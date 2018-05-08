#pragma once
#include "ExternalInclude.h"
#include "UnorderedMap.h"

class ConfigHandler
{
	public:
		ConfigHandler(string toReadFrom, char pSectionBegin = '[', char pSectionEnd = '#');
		~ConfigHandler();

		// Öffentliche Helferfunktionen
		void readComplete();
		string get(string container, string variableName);
		void write(string container, string variableName, string variableValue);



	private:
		// Filename
		string textFileName;

		// Config wird hier abgespeichert
		UnorderedMap<string, UnorderedMap<string, string>*> cfgTable;

		// Helferfunkion zu rausfiltern der Chars
		string RemoveChars(const string& source, const string& chars);

		// Chars zum abgrenzen der Sektionen
		char sectionBegin;
		char sectionEnd;
};

