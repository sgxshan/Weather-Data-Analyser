#pragma once
#include "AxisScale.h"

class CElement :public AxisScale
{
public:
	CElement();
	~CElement();

	//declare vector containers to store the interval of each element for plot
	vector<int> depthval;
	vector<int> vcarval;
	vector<int> vtpkval;
	vector<int> vcmxval;
	vector<int> wdir1val;
	vector<int> wspd1val;
	vector<int> gspd1val;
	vector<int> wdir2val;
	vector<int> wspd2val;
	vector<int> gspd2val;
	vector<int> atms1val;
	vector<int> atms2val;
	vector<int> drytval;
	vector<int> sstpval;
	vector<vector<int> > DrawSet;	//declare a wwo dimensional vector container to store the interval of each element
	void DataInterval(int height);	//declare a function to store the interval of each component to the two dimensional vector container
};

