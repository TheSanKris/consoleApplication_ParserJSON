#pragma once
#include "Headers.h"
#include "m_Object.h"

enum Flags
{
	KEY,
	VALUE,
	START_OBJECT,
	END_OBJECT,
	START_ARRAY,
	END_ARRAY

};

class JSON
{
public:

	void Init(string data);
	void Parse();
	void Delete();

	void GetData(string query);
	void GetStruct();

private:

	Flags CheckType();
	m_Object* CreateObject();
	void AddToStory(string key, m_Object* object);
	void InsertObjectToObject(string key, m_Object* object);
	void DeleteLastToStory();

private:

	string m_strJsonData;
	m_Object RESULT;
	vector<pair<string, m_Object*>> m_vStoryObjects;
	vector<pair<string, m_Object*>> m_vListObjectsJSON;

	m_Object* da;

	string m_strKey;
	string m_strValue;
	Flags flag;
	Flags last_flag;
	char simbol;
	char last_simbol;

};

