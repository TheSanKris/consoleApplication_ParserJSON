#include <iostream>

#include "JSON.h"

using namespace std;

int main()
{   
    string m_strJSON = R"({name: "gay", count: 2, position:[{ nazvanie: "first", number: true}]})";
    JSON* json = new JSON;
    json->Init(m_strJSON);
    json->Parse();
}
