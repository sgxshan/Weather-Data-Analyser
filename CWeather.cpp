#include "stdafx.h"
#include "CWeather.h"
#include <cstdlib>

using namespace std;

//default constructor
CWeather::CWeather()
{
}

CWeather::~CWeather()
{

}

//declare a function to split the separator ¡¯,¡¯ and put the value into vector container. 
vector<CString> CWeather::split(CString cstr)
{
	vector<CString> result;		//declare a vector container to store the string
	CString temp;				//declare a temp string
	int nTokenPos = 0;			//declare a variable to find position for the token
	int position = 0;			//declare a variable to record position for the token

	while (nTokenPos < cstr.GetLength())
	{
		if (cstr.GetAt(nTokenPos) == ',')		//position for the token
		{
			temp = cstr.Mid(position, nTokenPos - position);			//store the string between the two position
			result.push_back(temp);
			position = nTokenPos + 1;			//record the position of token
		}
		nTokenPos++;					//find next postion of token
	}
	temp = cstr.Mid(position, nTokenPos - position);
	result.push_back(temp);				//store the seperated string in vector
	return result;
}


//declare a function to read the file and store the data of each component into vector container.
void CWeather::LoadDate(CString filename)
{
	CStdioFile MyFile;
	MyFile.Open(filename, CFile::modeRead);
	CString str;
	vector<CString> result;					//declare a vector container to store the string
	int year, month, day, hour, min;		//declare variable for the date
	int TempInteger;						//declare a temp variable to store integer
	float TempFloat;						//declare a temp variable to store float data
	MyFile.ReadString(str);					//pass the first line
	while (MyFile.ReadString(str))
	{
		result = split(str);							//store and split the string 
		year = month = day = hour = min = 0;			//default value

		int position, LastPos;
		position = result[0].Find(_T("/"));
		month = _ttoi(result[0].Mid(0, position));		//store the value for month
		result[0].Delete(0, position + 1);				//delete the value for month

		position = result[0].Find(_T("/"));
		day = _ttoi(result[0].Mid(0, position));		//store the value for day
		result[0].Delete(0, position + 1);				//delete the value for day

		position = result[0].Find(_T(" "));
		year = _ttoi(result[0].Mid(0, position));		//store the value for year
		result[0].Delete(0, position + 1);				//delete the value for year

		position = result[0].Find(_T(":"));
		hour = _ttoi(result[0].Mid(0, position));		//store the value for hour
		result[0].Delete(0, position);					//delete the value for hour

		LastPos = result[0].GetLength();
		min = _ttoi(result[0].Mid(0, LastPos));			//store the value for minute

		if (year < 70)
			year = 2000 + year;				
		else
			year = 1900 + year;

		CTime TempTime(year, month, day, hour, min, 0);
		time.push_back(TempTime.GetTime());				//store the value for time

		TempInteger = _ttoi(result[1]);					//store the value for flag
		flag.push_back(TempInteger);

		TempFloat = _ttof(result[2]);					//store the value for depth
		depth.push_back(TempFloat);

		TempFloat = _ttof(result[3]);					//store the value for vcar
		vcar.push_back(TempFloat);

		TempFloat = _ttof(result[4]);					//store the value for vtpk
		vtpk.push_back(TempFloat);

		TempFloat = _ttof(result[5]);					//store the value for vcmx
		vcmx.push_back(TempFloat);

		TempFloat = _ttof(result[6]);
		wdir1.push_back(TempFloat);						//store the value for wdir1

		TempFloat = _ttof(result[7]);
		wspd1.push_back(TempFloat);						//store the value for wspd1

		TempFloat = _ttof(result[8]);
		gspd1.push_back(TempFloat);						//store the value for gspd1

		TempFloat = _ttof(result[9]);
		wdir2.push_back(TempFloat);						//store the value for wdir2
	
		TempFloat = _ttof(result[10]);
		wspd2.push_back(TempFloat);						//store the value for wspd2

		TempFloat = _ttof(result[11]);
		gspd2.push_back(TempFloat);						//store the value for gspd2

		TempFloat = _ttof(result[12]);
		atms1.push_back(TempFloat);						//store the value for atms1

		TempFloat = _ttof(result[13]);
		atms2.push_back(TempFloat);						//store the value for atms2

		TempFloat = _ttof(result[14]);	
		dryt.push_back(TempFloat);						//store the value for dryt

		TempFloat = _ttof(result[15]);
		sstp.push_back(TempFloat);						//store the value for sstp
	}
}




