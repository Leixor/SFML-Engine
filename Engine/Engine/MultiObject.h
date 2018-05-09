#pragma once
#include "ExternalInclude.h"

template<class Object>
class MultiObject
{
public:
	virtual void addChild(Object object) = 0;
	virtual void updateChild() = 0;

protected:
	vector<Object> child;
};

