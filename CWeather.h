#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
#include "CElement.h"
// to compile weather data

class CWeather : public CElement
{
public:
	CWeather();
	~CWeather();
	vector<CString> split(CString cstr);		//declare a function to split the separator ¡¯,¡¯ and put the value into vector container. 
	void LoadDate(CString filename);			//declare a function to read the file and store the data of each component into vector container. 

private:

};
