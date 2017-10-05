#include "stdafx.h"
#include "TimeSpan.h"

TimeSpan::TimeSpan()
{
}

TimeSpan::~TimeSpan()
{
}

//declare a function to obtain the start line and end line of a selected time span
void TimeSpan::TimeLength(time_t start, time_t end)
{
	//default value
	StartLine = 0;
	EndLine = time.size() - 1;
	if (start < time[0])
	{
		start = time[0];
		StartLine = 0;
	}
	else
	{
		//Obtain the start line
		int index = 0;				//declare a variable to get the line
		while (index < time.size())
		{
			if (start <= time[index])
			{
				StartLine = index;	//store the start Line
				break;
			}
			index++;
		}
	}

	time_t temp = time[time.size() - 1];	//declare a temp time variable 
	if (end > temp)
	{
		end = temp;
		EndLine = time.size() - 1;
	}
	else
	{
		//Obtain the end line
		int index = time.size() - 1;
		while (index > 0)
		{
			if (end >= time[index])
			{
				EndLine = index;		//store the end line
				break;
			}
			index--;
		}
	}
}

//declare a function to get the line length of a selected time span
int TimeSpan::length()
{
	return (EndLine - StartLine);		
}