#include "m_Object.h"

void m_Object::Insert(string key, string value)
{
	m_strParameters[key] = value;
}

void m_Object::Insert(string key, m_Object* object)
{
	m_objArray[key] = object;
}
