#pragma once
#include "ExternalInclude.h"


template<typename Iterator, typename Content>
class SortableMap
{
private:
	map<Iterator, Content> contents;
	vector<const Iterator*> priorityIterator;
	vector<Content*> priorityContent;

public:

	// Basic operations
	void push(Iterator iterator, Content content);
	void insert(Iterator iterator, Content content, int index);
	void removeAt(Iterator iterator);
	void removeAtIndex(int index);
	void clear();
	unsigned int size();

	// Setters and getters
	Content at(Iterator iterator);
	Content atIndex(int index);
	int getIndex(Iterator iterator);
	Iterator findByIndex(int index);
	Iterator find(Content content);

	// Itemcheck
	bool itemExists(Iterator iterator);

	// Priority
	void setIndex(Iterator iterator, int index);
	void updateIndex(int index, int newIndex);
private:
	template <typename vectorClass>
	void moveIndex(vector<vectorClass>& vector, int index, int newIndex);
};

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::push(Iterator iterator, Content content)
{
	this->contents.emplace(iterator, content);
	auto mapContent = this->contents.find(iterator);
	this->priorityIterator.push_back(&mapContent->first);
	this->priorityContent.push_back(&mapContent->second);
}

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::insert(Iterator iterator, Content content, int index)
{
	this->contents.emplace(iterator, content);
	auto mapContent = contents.find(iterator);
	this->priorityIterator.insert(priorityIterator.begin() + index, &mapContent->first);
	this->priorityContent.insert(priorityContent.begin() + index, &mapContent->second);
}

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::removeAt(Iterator iterator)
{
	auto contentIterator = this->contents.find(iterator);

	if (contentIterator != contents.end())
	{
		auto index = this->getIndex(iterator);
		this->priorityIterator.erase(priorityIterator.begin() + index);
		this->priorityContent.erase(priorityContent.begin() + index);
		this->contents.erase(contentIterator);
	}
}

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::removeAtIndex(int index)
{
	this->contents.erase(this->findByIndex(index));
	this->priorityIterator.erase(priorityIterator.begin() + index);
	this->priorityContent.erase(priorityContent.begin() + index);
}

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::clear()
{
	this->contents.clear();
	this->priorityIterator.clear();
	this->priorityContent.clear();
}

template<typename Iterator, typename Content>
inline unsigned int SortableMap<Iterator, Content>::size()
{
	return this->contents.size();
}


template<typename Iterator, typename Content>
inline Content SortableMap<Iterator, Content>::at(Iterator iterator)
{
	return this->contents.at(iterator);
}

template<typename Iterator, typename Content>
inline Content SortableMap<Iterator, Content>::atIndex(int index)
{
	return *this->priorityContent.at(index);
}

template<typename Iterator, typename Content>
inline int SortableMap<Iterator, Content>::getIndex(Iterator iterator)
{
	auto contentIterator = this->contents.find(iterator);
	return distance(priorityIterator.begin(), std::find(priorityIterator.begin(), priorityIterator.end(), &contentIterator->first));
}

template<typename Iterator, typename Content>
inline Iterator SortableMap<Iterator, Content>::findByIndex(int index)
{
	return *this->priorityIterator.at(index);
}

template<typename Iterator, typename Content>
inline Iterator SortableMap<Iterator, Content>::find(Content content)
{
	return this->contents.find(content)->first;
}

template<typename Iterator, typename Content>
inline bool SortableMap<Iterator, Content>::itemExists(Iterator iterator)
{
	return this->contents.end() != this->contents.find(iterator);
}



template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::setIndex(Iterator iterator, int index)
{
	int iteratorIndex = getIndex(iterator);

	this->moveIndex(this->priorityIterator, iteratorIndex, index);
	this->moveIndex(this->priorityContent, iteratorIndex, index);

}

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::updateIndex(int index, int newIndex)
{
	this->moveIndex(this->priorityIterator, index, newIndex);
	this->moveIndex(this->priorityContent, index, newIndex);
}

template<typename Iterator, typename Content>
template<typename vectorClass>
inline void SortableMap<Iterator, Content>::moveIndex(vector<vectorClass>& vector, int index, int newIndex)
{
	typename std::vector<vectorClass>::iterator first, middle, last;

	if (index < newIndex)
	{
		first = vector.begin() + index;
		middle = first + 1;
		last = vector.begin() + newIndex;
	}
	else
	{
		first = vector.begin() + newIndex;
		middle = vector.begin() + index;
		last = middle + 1;
	}
	rotate(first, middle, last);
}
