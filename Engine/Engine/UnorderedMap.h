#pragma once
#include "ExternalInclude.h"

template<typename Iterator, typename Content>
class UnorderedMap
{
private:
	vector<Content> objects;
	map<Iterator, int> iteratorIndex;
	vector<int> priorityIndex;

public:
	extern UnorderedMap<Iterator, Content>();

	extern void push(Iterator iterator, Content content);

	extern unsigned int size();

	extern void clear();

	extern void remove(Iterator iterator);

	extern void remove(int index);

	extern int getIndex(Iterator iterator);

	extern void set(int index, Content content);

	extern void set(Iterator iterator, Content content);

	extern Content get(Iterator iterator);

	extern  Content get(int index);

	extern Iterator getIterator(int index);

	extern Iterator getIterator(Content content);

	extern bool itemExists(Iterator iterator);

	extern int getPriority(Iterator iterator);

	extern  getPriority(int index);

	extern void setPriority(Iterator iterator, int priority);

	extern void setPriority(int index, int priority);

	extern Content getContentByPriority(int priority);

	extern int getIndexByPriority(int priority);
};


