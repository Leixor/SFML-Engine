#pragma once
#include "ExternalInclude.h"

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
};

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::push(Iterator iterator, Content content)
{
		this->contents.emplace(iterator, content);
		this->priorityIterator.push_back(&this->contents.end()->first);
}

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::insert(Iterator iterator, Content content, int index)
{
	this->contents.emplace(iterator, content);
	this->priorityIterator.insert(priorityIterator.begin() + index, &this->contents.end()->first);
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
	this->priorityIterator.erase(priorityIterator.begin() + index);
	this->contents.erase(this->getIterator(index));
}

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::clear()
{
	this->contents.clear();
	this->priorityIterator.clear();
}

template<typename Iterator, typename Content>
inline unsigned int SortableMap<Iterator, Content>::size()
{
	return this->contents.size();
}

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::set(int index, Content content)
{
	this->contents.at(getIterator(index)) = content;
}

template<typename Iterator, typename Content>
inline void SortableMap<Iterator, Content>::set(Iterator iterator, Content content)
{
	this->contents.at(iterator) = content;
}

template<typename Iterator, typename Content>
inline Content SortableMap<Iterator, Content>::at(Iterator iterator)
{
	return this->contents.at(iterator);
}

template<typename Iterator, typename Content>
inline Content SortableMap<Iterator, Content>::atIndex(int index)
{
	return this->contents.at(getIterator(index));
}

template<typename Iterator, typename Content>
inline int SortableMap<Iterator, Content>::getIndex(Iterator iterator)
{
	auto contentIterator = this->contents.find(iterator);
	return distance(priorityIndex.begin(), find(priorityIndex.begin(), priorityIndex.end(), &contentIterator->first));
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
		last = this->priorityIterator + newIndex;
	}
	else
	{
		first = this->priorityIterator + newIndex;
		middle = this->priorityIterator + index;
		last = middle + 1;
	}
	rotate(first, middle, last);
}




