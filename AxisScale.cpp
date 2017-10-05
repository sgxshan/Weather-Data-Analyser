#include "stdafx.h"
#include "AxisScale.h"


AxisScale::AxisScale()
{
}


AxisScale::~AxisScale()
{
}

//declare a function to store the interval of Y aixs in the array
void AxisScale::YInterval()
{
	float TempFloat;		//declare a temp variable
	for (int i = StartLine; i <= EndLine; i++)
	{
		TempFloat = depth[i];										//store the value of depth in to temp variable
		//get the value of minimum value of depth (if (min<temp), min=min, else min=temp) default value for min=9999
		minDepth = minDepth < TempFloat ? minDepth : TempFloat;		
		//get the value of maximum value of depth (if (max>temp), max=max, else max=temp) default value for max=0
		maxDepth = maxDepth > TempFloat ? maxDepth : TempFloat;		

		TempFloat = vcar[i];		
		minVcar = minVcar < TempFloat ? minVcar : TempFloat;
		maxVcar = maxVcar > TempFloat ? maxVcar : TempFloat;

		TempFloat = vtpk[i];
		minVtpk = minVtpk < TempFloat ? minVtpk : TempFloat;
		maxVtpk = maxVtpk > TempFloat ? maxVtpk : TempFloat;

		TempFloat = vcmx[i];		
		minVcmx = minVcmx < TempFloat ? minVcmx : TempFloat;
		maxVcmx = maxVcmx > TempFloat ? maxVcmx : TempFloat;

		TempFloat = wdir1[i];
		minWdir1 = minWdir1 < TempFloat ? minWdir1 : TempFloat;
		maxWdir1 = maxWdir1 > TempFloat ? maxWdir1 : TempFloat;

		TempFloat = wspd1[i];
		minWspd1 = minWspd1 < TempFloat ? minWspd1 : TempFloat;
		maxWspd1 = maxWspd1 > TempFloat ? maxWspd1 : TempFloat;

		TempFloat = gspd1[i];
		minGspd1 = minGspd1 < TempFloat ? minGspd1 : TempFloat;
		maxGspd1 = maxGspd1 > TempFloat ? maxGspd1 : TempFloat;

		TempFloat = wdir2[i];
		minWdir2 = minWdir2 < TempFloat ? minWdir2 : TempFloat;
		maxWdir2 = maxWdir2 > TempFloat ? maxWdir2 : TempFloat;

		TempFloat = wspd2[i];
		minWspd2 = minWspd2 < TempFloat ? minWspd2 : TempFloat;
		maxWspd2 = maxWspd2 > TempFloat ? maxWspd2 : TempFloat;

		TempFloat = gspd2[i];
		minGspd2 = minGspd2 < TempFloat ? minGspd2 : TempFloat;
		maxGspd2 = maxGspd2 > TempFloat ? maxGspd2 : TempFloat;

		TempFloat = atms1[i];
		minAtms1 = minAtms1 < TempFloat ? minAtms1 : TempFloat;
		maxAtms1 = maxAtms1 > TempFloat ? maxAtms1 : TempFloat;

		TempFloat = atms2[i];
		minAtms2 = minAtms2 < TempFloat ? minAtms2 : TempFloat;
		maxAtms2 = maxAtms2 > TempFloat ? maxAtms2 : TempFloat;

		TempFloat = dryt[i];
		minDryt = minDryt < TempFloat ? minDryt : TempFloat;
		maxDryt = maxDryt > TempFloat ? maxDryt : TempFloat;

		TempFloat = sstp[i];
		minSstp = minSstp < TempFloat ? minSstp : TempFloat;
		maxSstp = maxSstp > TempFloat ? maxSstp : TempFloat;
	}

	if (maxDepth == minDepth)
	{
		minDepth = 0;				
	}

	//Obtain and store the interval of Y scale in the array
	interval[0] = ((maxDepth - minDepth) / 5);
	interval[1] = ((maxVcar - minVcar) / 5);
	interval[2] = ((maxVtpk - minVtpk) / 5);
	interval[3] = ((maxVcmx - minVcmx) / 5);
	interval[4] = ((maxWdir1 - minWdir1) / 5);
	interval[5] = ((maxWspd1 - minWspd1) / 5);
	interval[6] = ((maxGspd1 - minGspd1) / 5);
	interval[7] = ((maxWdir2 - minWdir2) / 5);
	interval[8] = ((maxWspd2 - minWspd2) / 5);
	interval[9] = ((maxGspd2 - minGspd2) / 5);
	interval[10] = ((maxAtms1 - minAtms1) / 5);
	interval[11] = ((maxAtms2 - minAtms2) / 5);
	interval[12] = ((maxDryt - minDryt) / 5);
	interval[13] = ((maxSstp - minSstp) / 5);
}