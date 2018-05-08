#pragma once
#include "UnorderedMap.h"



template<typename Iterator, typename Content>
UnorderedMap<Iterator, Content>::UnorderedMap()
{
}

template<typename Iterator, typename Content>
void UnorderedMap<Iterator, Content>::push(Iterator iterator, Content content)
{
	this->objects.push_back(content);
	this->iteratorIndex.emplace(iterator, objects.size() - 1);
	this->priorityIndex.push_back(objects.size() - 1);
}

template<typename Iterator, typename Content>
unsigned int UnorderedMap<Iterator, Content>::size()
{
	return this->objects.size();
}

template<typename Iterator, typename Content>
void UnorderedMap<Iterator, Content>::clear()
{
		this->objects.clear();
		this->iteratorIndex.clear();
		this->priorityIndex.clear();
}

template<typename Iterator, typename Content>
void UnorderedMap<Iterator, Content>::remove(Iterator iterator)
{
		int index = this->iteratorIndex.at(iterator);
		this->objects.erase(this->objects.begin() + index);
		this->iteratorIndex.erase(iterator);

		for (unsigned int i = 0; i < this->priorityIndex.size(); i++)
		{
			if (this->priorityIndex.at(i) == index)
			{
				this->priorityIndex.erase(this->priorityIndex.begin() + i);
				break;
			}
		}
}

template<typename Iterator, typename Content>
void UnorderedMap<Iterator, Content>::remove(int index)
{
		this->objects.erase(this->objects.begin() + index);

		map<Iterator, int>::iterator it;
		it = this->iteratorIndex.begin();
		for (int i = 0; i < index; i++)
			it++;
		this->iteratorIndex.erase(it->first);

		for (unsigned int i = 0; i < this->priorityIndex.size(); i++)
		{
			if (this->priorityIndex.at(i) == index)
			{
				this->priorityIndex.erase(this->priorityIndex.begin() + i);
				break;
			}
		}
}

template<typename Iterator, typename Content>
int UnorderedMap<Iterator, Content>::getIndex(Iterator iterator)
{
		return this->iteratorIndex.at(iterator);
}

template<typename Iterator, typename Content>
void UnorderedMap<Iterator, Content>::set(int index, Content content)
{
		this->objects.at(index) = content;
}

template<typename Iterator, typename Content>
void UnorderedMap<Iterator, Content>::set(Iterator iterator, Content content)
{
		this->objects.at(this->iteratorIndex.at(iterator)) = content;
}

template<typename Iterator, typename Content>
Content UnorderedMap<Iterator, Content>::get(Iterator iterator)
{
		return this->objects.at(this->iteratorIndex.at(iterator));
}

template<typename Iterator, typename Content>
Content UnorderedMap<Iterator, Content>::get(int index)
{
		return this->objects.at(index);
}

template<typename Iterator, typename Content>
Iterator UnorderedMap<Iterator, Content>::getIterator(int index)
{
		map<Iterator, int>::iterator it;
		it = this->iteratorIndex.begin();
		for (int i = 0; i < index; i++)
			it++;
		return it->first;
}

template<typename Iterator, typename Content>
Iterator UnorderedMap<Iterator, Content>::getIterator(Content content)
{
		for (unsigned int i = 0; i < objects.size(); i++)
		{
			if (objects.at(i) == content)
			{
				map<Iterator, int>::iterator it;
				it = this->iteratorIndex.begin();
				for (int j = 0; j < i; j++)
					it++;
				return this->iteratorIndex.at(it->first);
			}
		}
		throw;
}

template<typename Iterator, typename Content>
bool UnorderedMap<Iterator, Content>::itemExists(Iterator iterator)
{
		try
		{
			this->iteratorIndex.at(iterator);
			return true;
		}
		catch (...)
		{
			return false;
		}
		return true;
}

template<typename Iterator, typename Content>
int UnorderedMap<Iterator, Content>::getPriority(Iterator iterator)
{
		int index = this->iteratorIndex.at(iterator);

		for (unsigned int i = 0; i < this->priorityIndex.size(); i++)
		{
			if (this->priorityIndex.at(i) == index)
			{
				return (int)i;
			}
		}
		throw;
}

template<typename Iterator, typename Content>
UnorderedMap<Iterator, Content>::getPriority(int index)
{
	for (unsigned int i = 0; i < this->priorityIndex.size(); i++)
	{
		if (this->priorityIndex.at(i) == index)
		{
			return i;
		}
	}
	throw;
}

template<typename Iterator, typename Content>
void UnorderedMap<Iterator, Content>::setPriority(Iterator iterator, int priority)
{
		int indexInVector = this->iteratorIndex.at(iterator);

		int currentPriorityIndex = 0;
		for (unsigned int i = 0; i < this->priorityIndex.size(); i++)
		{
			if (this->priorityIndex.at(i) == indexInVector)
			{
				currentPriorityIndex = i;
				break;
			}
		}

		this->priorityIndex.erase(this->priorityIndex.begin() + currentPriorityIndex);
		this->priorityIndex.insert(this->priorityIndex.begin() + priority, indexInVector);
}

template<typename Iterator, typename Content>
void UnorderedMap<Iterator, Content>::setPriority(int index, int priority)
{
	int currentPriorityIndex = 0;
	for (unsigned int i = 0; i < this->priorityIndex.size(); i++)
	{
		if (this->priorityIndex.at(i) == index)
		{
			currentPriorityIndex = i;
			break;
		}
	}

	this->priorityIndex.erase(this->priorityIndex.begin() + currentPriorityIndex);
	this->priorityIndex.insert(this->priorityIndex.begin() + priority, index);
}

template<typename Iterator, typename Content>
Content UnorderedMap<Iterator, Content>::getContentByPriority(int priority)
{
	return this->objects.at(this->priorityIndex.at(priority));
}

template<typename Iterator, typename Content>
int UnorderedMap<Iterator, Content>::getIndexByPriority(int priority)
{
	return this->priorityIndex.at(priority);
}
