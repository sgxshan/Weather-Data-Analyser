#include "stdafx.h"
#include "CElement.h"
CElement::CElement()
{
}


CElement::~CElement()
{
}

//declare a function to store the interval of each component to the two dimensional vector container
void CElement::DataInterval(int height)
{

	DrawSet.clear();
	depthval.clear();
	vcarval.clear();
	vtpkval.clear();
	vcmxval.clear();
	wdir1val.clear();
	wspd1val.clear();
	gspd1val.clear();
	wdir2val.clear();
	wspd2val.clear();
	gspd2val.clear();
	atms1val.clear();
	atms2val.clear();
	drytval.clear();
	sstpval.clear();

	float TempInterval;				//declare a temp variable to store the interval of element
	for (int i = StartLine; i <= EndLine; i++)
	{
		//calculate and store the interval of each element in the one dimensional container
		TempInterval = height * (depth[i] - minDepth) / (maxDepth - minDepth);
		depthval.push_back(height - TempInterval);				
	
		TempInterval = height * (vcar[i] - minVcar) / (maxVcar - minVcar);
		vcarval.push_back(height - TempInterval);

		TempInterval = height * (vtpk[i] - minVtpk) / (maxVtpk - minVtpk);
		vtpkval.push_back(height - TempInterval);

		TempInterval = height * (vcmx[i] - minVcmx) / (maxVcmx - minVcmx);
		vcmxval.push_back(height - TempInterval);

		TempInterval = height * (wdir1[i] - minWdir1) / (maxWdir1 - minWdir1);
		wdir1val.push_back(height - TempInterval);

		TempInterval = height * (wspd1[i] - minWspd1) / (maxWspd1 - minWspd1);
		wspd1val.push_back(height - TempInterval);

		TempInterval = height * (gspd1[i] - minGspd1) / (maxGspd1 - minGspd1);
		gspd1val.push_back(height - TempInterval);

		TempInterval = height * (wdir2[i] - minWdir2) / (maxWdir2 - minWdir2);
		wdir2val.push_back(height - TempInterval);

		TempInterval = height * (wspd2[i] - minWspd2) / (maxWspd2 - minWspd2);
		wspd2val.push_back(height - TempInterval);

		TempInterval = height * (gspd2[i] - minGspd2) / (maxGspd2 - minGspd2);
		gspd2val.push_back(height - TempInterval);

		TempInterval = height * (atms1[i] - minAtms1) / (maxAtms1 - minAtms1);
		atms1val.push_back(height - TempInterval);

		TempInterval = height * (atms2[i] - minAtms2) / (maxAtms2 - minAtms2);
		atms2val.push_back(height - TempInterval);

		TempInterval = height * (dryt[i] - minDryt) / (maxDryt - minDryt);
		drytval.push_back(height - TempInterval);

		TempInterval = height * (sstp[i] - minSstp) / (maxSstp - minSstp);
		sstpval.push_back(height - TempInterval);
	}

	//store the interval of each element in the two dimensional container
	DrawSet.push_back(depthval);		
	DrawSet.push_back(vcarval);
	DrawSet.push_back(vtpkval);
	DrawSet.push_back(vcmxval);
	DrawSet.push_back(wdir1val);
	DrawSet.push_back(wspd1val);
	DrawSet.push_back(gspd1val);
	DrawSet.push_back(wdir2val);
	DrawSet.push_back(wspd2val);
	DrawSet.push_back(gspd2val);
	DrawSet.push_back(atms1val);
	DrawSet.push_back(atms2val);
	DrawSet.push_back(drytval);
	DrawSet.push_back(sstpval);
}