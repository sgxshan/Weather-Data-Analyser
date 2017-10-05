#pragma once
#include "TimeSpan.h"
class AxisScale
	:public TimeSpan
{
public:

	AxisScale();				//default constructor 
	~AxisScale();				//default destructor 

	float interval[13];			//declare array to store the interval of each component for plotting the scale of Y axis
	void YInterval();			//declare a function to store the interval of Y aixs in the array

	//declare variables to store the maximum value of each component
	//decalare the default value for maximum and minimum value
	float minDepth = 999999999, maxDepth = 0;
	float minVcar = 999999999, maxVcar = 0;
	float minVtpk = 999999999, maxVtpk = 0;
	float minVcmx = 999999999, maxVcmx = 0;
	float minWdir1 = 999999999, maxWdir1 = 0;
	float minWspd1 = 999999999, maxWspd1 = 0;
	float minGspd1 = 999999999, maxGspd1 = 0;
	float minWdir2 = 999999999, maxWdir2 = 0;
	float minWspd2 = 999999999, maxWspd2 = 0;
	float minGspd2 = 999999999, maxGspd2 = 0;
	float minAtms1 = 999999999, maxAtms1 = 0;
	float minAtms2 = 999999999, maxAtms2 = 0;
	float minDryt = 999999999, maxDryt = 0;
	float minSstp = 999999999, maxSstp = 0;
};

