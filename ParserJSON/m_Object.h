#pragma once
#include "Headers.h"

class m_Object
{
public:

	void Insert(string key, string value);
	void Insert(string key, m_Object* object);

private:

	map<string, string> m_strParameters;
	map<string, m_Object*> m_objArray;

};

