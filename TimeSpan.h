#pragma once
#include <vector>
#include"CData.h"
class TimeSpan:public CData
{
public:
	TimeSpan();
	~TimeSpan();

	int StartLine;			//declare variable to store the start line for a start time
	int EndLine;			//declare variable to store the end line for a end time
	vector<time_t> time;	//declare time variable to store the time for a selected time span

	void TimeLength(time_t start, time_t end);	//declare a function to obtain the start line and end line of a selected time span
	int length();								//declare a function to get the line length of a selected time span
};

