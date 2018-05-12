#pragma once
#include <mutex>
#include <fstream>
#include <iostream>
#include <sstream>
#include <random>
#include <map>
#include <unordered_map>

using namespace std;

template<typename Iterator, typename Content>
class SortableMap
{
private:
	map<Iterator, Content> contents;
	vector<const Iterator*> priorityIterator;

public:

	// Basic operations
	void push(Iterator iterator, Content content);
	void insert(Iterator iterator, Content content, int index);
	void removeAt(Iterator iterator);
	void removeAtIndex(int index);
	void clear();
	size_t size();

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
};

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::push(Iterator iterator, Content content)
{
	this->contents.emplace(iterator, content);
	this->priorityIterator.push_back(&this->contents.find(iterator)->first);
}

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::insert(Iterator iterator, Content content, int index)
{
	this->contents.emplace(iterator, content);
	this->priorityIterator.insert(priorityIterator.begin() + index, &contents.find(iterator)->first);
}

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::removeAt(Iterator iterator)
{
	auto contentIterator = this->contents.find(iterator);

	if (contentIterator != contents.end())
	{
		const Iterator* iteratorPointer = &contentIterator->first;
		this->contents.erase(contentIterator);
		auto pIterator = std::find(priorityIterator.begin(), priorityIterator.end(), iteratorPointer);
		this->priorityIterator.erase(pIterator);
	}
}

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::removeAtIndex(int index)
{
	this->contents.erase(this->findByIndex(index));
	this->priorityIterator.erase(priorityIterator.begin() + index);
}

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::clear()
{
	this->contents.clear();
	this->priorityIterator.clear();
}

template<typename Iterator, typename Content>
inline size_t SortableMap<Iterator, Content>::size()
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
	return this->contents.at(findByIndex(index));
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

	this->updateIndex(iteratorIndex, index);
}

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::updateIndex(int index, int newIndex)
{
	typename std::vector<const Iterator *>::iterator first, middle, last;

	if (index < newIndex)
	{
		first = this->priorityIterator.begin() + index;
		middle = first + 1;
		last = this->priorityIterator.begin() + newIndex;
	}
	else
	{
		first = this->priorityIterator.begin() + newIndex;
		middle = this->priorityIterator.begin() + index;
		last = middle + 1;
	}
	rotate(first, middle, last);
}