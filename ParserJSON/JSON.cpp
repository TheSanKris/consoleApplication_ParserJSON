#include "JSON.h"

void JSON::Init(string data)
{
	m_strJsonData = data;
	AddToStory("START", &RESULT);
}

void JSON::Parse()
{
	for (int i = 1; i < m_strJsonData.length(); i++)
	{
		simbol = m_strJsonData[i];
		last_flag = flag;
		flag = CheckType();
		last_simbol = simbol;

		//Добавление пары
		if ((flag != last_flag) && (last_flag == VALUE))
		{
			m_Object* tmp = m_vStoryObjects.back().second;
			tmp->Insert(m_strKey, m_strValue);
			m_strKey = "";
			m_strValue = "";
		}

		switch (flag)
		{
		case KEY:
			if ((simbol != ':') && (simbol != ' '))
				m_strKey += simbol;
			break;

		case VALUE:
			if ((simbol != ',') && (simbol != ' ') && (simbol != '"'))
				m_strValue += simbol;
			break;

		case START_OBJECT:
			da = CreateObject();
			InsertObjectToObject(m_strKey, da);
			AddToStory(m_strKey, da);
			
			break;

		case END_OBJECT:
			DeleteLastToStory();

			break;

		case START_ARRAY:
			da = CreateObject();
			InsertObjectToObject(m_strKey, da);
			AddToStory(m_strKey, da);

			break;

		case END_ARRAY:
			DeleteLastToStory();

			break;

		default:
			break;
		}
	}

}

Flags JSON::CheckType()
{
	//Это база
	if (simbol == '{')
		return START_OBJECT;
	if (simbol == '}')
		return END_OBJECT;
	if (simbol == '[')
		return START_ARRAY;
	if (simbol == ']')
		return END_ARRAY;
	//Теперь для параметров
	if ((last_simbol == ',') || (last_simbol == '{'))
		return KEY;
	if (last_simbol == ':')
		return VALUE;
	return flag;
}

m_Object* JSON::CreateObject()
{
	m_Object* da = new m_Object;
	return da;
}

void JSON::AddToStory(string key, m_Object* object)
{
	pair<string, m_Object*> tmp;
	tmp.first = key;
	tmp.second = object;
	m_vStoryObjects.push_back(tmp);
	m_vListObjectsJSON.push_back(tmp);
	m_strKey = "";
	
}

void JSON::InsertObjectToObject(string key, m_Object* object)
{
	m_Object* tmp = m_vStoryObjects.back().second;
	tmp->Insert(m_strKey, object);

}

void JSON::DeleteLastToStory()
{
	m_vStoryObjects.pop_back();
}
