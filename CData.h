#pragma once
#include <vector>
using namespace std;
class CData
{
public:
	CData();		
	~CData();

	//declares 15 vector containers to store each element
	vector<int> flag;
	vector<float> depth;
	vector<float> vcar;
	vector<float> vtpk;
	vector<float> vcmx;
	vector<float> wdir1;
	vector<float> wspd1;
	vector<float> gspd1;
	vector<float> wdir2;
	vector<float> wspd2;
	vector<float> gspd2;
	vector<float> atms1;
	vector<float> atms2;
	vector<float> dryt;
	vector<float> sstp;
};

