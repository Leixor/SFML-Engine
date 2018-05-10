#include "ConfigHandler.h"


ConfigHandler::ConfigHandler(string toReadFrom, char pSectionBegin, char pSectionEnd) : textFileName(toReadFrom), sectionBegin(pSectionBegin), sectionEnd(pSectionEnd)
{
	this->readComplete();
}

void ConfigHandler::readComplete()
{
	// Clear die Tabelle
	cfgTable.clear();

	bool endSign = false;;

	int i = 0;

	// String zum durchiterieren bereitstellen
	string str;

	// File öffnen
	ifstream file(textFileName);

	// Die ganze config lesen
	while (std::getline(file, str))
	{
		if (str.at(0) == sectionBegin) {
			string sectionName = this->RemoveChars(str, string(1, sectionBegin));
			cfgTable.push(sectionName, new SortableMap<string, string>());
			while (!endSign)
			{
				getline(file, str);
				if (str.at(0) == sectionEnd)
				{
					endSign = true;
					break;
				}
				stringstream ss(str);
				getline(ss, str, ':');
				string varName = str;
				getline(ss, str);
				string varValue = str;
				cfgTable.atIndex(i)->push(varName, varValue);
			}
			i++;
		}
		endSign = false;
	}
}


string ConfigHandler::get(string container, string variableName)
{
	return this->cfgTable.at(container)->at(variableName);
}

void ConfigHandler::write(string container, string variableName, string variableValue)
{
	bool writeSuccess = false;

	// Erstmal checken ob der Container exestiert
	for (unsigned int i = 0; i < this->cfgTable.size(); i++)
	{
		// Falls er da reinkommt exestiert der Container schonmal
		if (this->cfgTable.findByIndex(i) == container)
		{
			// Checken ob die Variable schon exestiert
			for (unsigned int j = 0; j < this->cfgTable.atIndex(i)->size(); j++)
			{
				// Falls er da reinkommt exestiert die Variable schon
				if (this->cfgTable.atIndex(i)->findByIndex(j) == variableName)
				{
					// Variable überschreiben
					this->cfgTable.atIndex(i)->atIndex(j) = variableValue;
					writeSuccess = true;
					break;
				}
			}
			// Variable erstellen falls nicht vorhanden und füllen
			if (!writeSuccess)
			{
				this->cfgTable.atIndex(i)->push(variableName, variableValue);
				writeSuccess = true;
				break;
			}

		}
	}
	// Wenn der Container nicht exestiert auch einen neuen Container samt Variable erstellen
	if (!writeSuccess)
	{
		this->cfgTable.push(container, new SortableMap<string, string>);
		this->cfgTable.atIndex(cfgTable.size() - 1)->push(variableName, variableValue);
	}

	ofstream myfile(this->textFileName);

	for (unsigned int i = 0; i < this->cfgTable.size(); i++)
	{
		myfile << sectionBegin;
		// Erstmal Containersektion reinschreiben
		myfile << this->cfgTable.findByIndex(i) << "\n";

		for (unsigned int j = 0; j < this->cfgTable.atIndex(i)->size(); j++)
		{
			// Container füllen
			myfile << this->cfgTable.atIndex(i)->findByIndex(j) << ":" << this->cfgTable.atIndex(i)->atIndex(j) << "\n";
		}
		myfile << sectionEnd << "\n";
	}
	myfile.close();
}

std::string ConfigHandler::RemoveChars(const std::string& source, const std::string& chars)
{
	std::string result = "";
	for (unsigned int i = 0; i<source.length(); i++) {
		bool foundany = false;
		for (unsigned int j = 0; j<chars.length() && !foundany; j++) {
			foundany = (source[i] == chars[j]);
		}
		if (!foundany) {
			result += source[i];
		}
	}
	return result;
}


ConfigHandler::~ConfigHandler()
{

}

