
// WeatherDataAnalyserView.cpp : implementation of the CWeatherDataAnalyserView class
//
#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "WeatherDataAnalyser.h"
#endif

#include "WeatherDataAnalyserDoc.h"
#include "WeatherDataAnalyserView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeatherDataAnalyserView

IMPLEMENT_DYNCREATE(CWeatherDataAnalyserView, CScrollView)

BEGIN_MESSAGE_MAP(CWeatherDataAnalyserView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_TIME_TIMESPAN, &CWeatherDataAnalyserView::OnTimeTimespan)
	ON_COMMAND(ID_DATA_DEPTH, &CWeatherDataAnalyserView::OnDataDepth)
	ON_COMMAND(ID_DATA_VCAR, &CWeatherDataAnalyserView::OnDataVcar)
	ON_COMMAND(ID_DATA_VTPK, &CWeatherDataAnalyserView::OnDataVtpk)
	ON_COMMAND(ID_DATA_WSPD1, &CWeatherDataAnalyserView::OnDataWspd1)
	ON_COMMAND(ID_DATA_GSPD1, &CWeatherDataAnalyserView::OnDataGspd1)
	ON_COMMAND(ID_DATA_WDIR1, &CWeatherDataAnalyserView::OnDataWdir1)
	ON_COMMAND(ID_DATA_WDIR2, &CWeatherDataAnalyserView::OnDataWdir2)
	ON_COMMAND(ID_DATA_WSPD2, &CWeatherDataAnalyserView::OnDataWspd2)
	ON_COMMAND(ID_DATA_VCMX, &CWeatherDataAnalyserView::OnDataVcmx)
	ON_COMMAND(ID_DATA_GSPD2, &CWeatherDataAnalyserView::OnDataGspd2)
	ON_COMMAND(ID_DATA_ATMS1, &CWeatherDataAnalyserView::OnDataAtms1)
	ON_COMMAND(ID_DATA_ATMS2, &CWeatherDataAnalyserView::OnDataAtms2)
	ON_COMMAND(ID_DATA_DRYT, &CWeatherDataAnalyserView::OnDataDryt)
	ON_COMMAND(ID_DATA_SSTP, &CWeatherDataAnalyserView::OnDataSstp)
	ON_UPDATE_COMMAND_UI(ID_DATA_DEPTH, &CWeatherDataAnalyserView::OnUpdateDataDepth)
	ON_UPDATE_COMMAND_UI(ID_DATA_VCAR, &CWeatherDataAnalyserView::OnUpdateDataVcar)
	ON_UPDATE_COMMAND_UI(ID_DATA_WSPD1, &CWeatherDataAnalyserView::OnUpdateDataWspd1)
	ON_UPDATE_COMMAND_UI(ID_DATA_GSPD1, &CWeatherDataAnalyserView::OnUpdateDataGspd1)
	ON_UPDATE_COMMAND_UI(ID_DATA_WDIR2, &CWeatherDataAnalyserView::OnUpdateDataWdir2)
	ON_UPDATE_COMMAND_UI(ID_DATA_WSPD2, &CWeatherDataAnalyserView::OnUpdateDataWspd2)
	ON_UPDATE_COMMAND_UI(ID_DATA_GSPD2, &CWeatherDataAnalyserView::OnUpdateDataGspd2)
	ON_UPDATE_COMMAND_UI(ID_DATA_ATMS1, &CWeatherDataAnalyserView::OnUpdateDataAtms1)
	ON_UPDATE_COMMAND_UI(ID_DATA_ATMS2, &CWeatherDataAnalyserView::OnUpdateDataAtms2)
	ON_UPDATE_COMMAND_UI(ID_DATA_SSTP, &CWeatherDataAnalyserView::OnUpdateDataSstp)
	ON_UPDATE_COMMAND_UI(ID_DATA_VTPK, &CWeatherDataAnalyserView::OnUpdateDataVtpk)
	ON_UPDATE_COMMAND_UI(ID_DATA_DRYT, &CWeatherDataAnalyserView::OnUpdateDataDryt)
	ON_UPDATE_COMMAND_UI(ID_DATA_WDIR1, &CWeatherDataAnalyserView::OnUpdateDataWdir1)
	ON_UPDATE_COMMAND_UI(ID_DATA_VCMX, &CWeatherDataAnalyserView::OnUpdateDataVcmx)
	ON_COMMAND(ID_CLEAN_RESET, &CWeatherDataAnalyserView::OnCleanReset)
	ON_COMMAND(ID_FILE_SAVE, &CWeatherDataAnalyserView::OnFileSave)
END_MESSAGE_MAP()

// CWeatherDataAnalyserView construction/destruction

CWeatherDataAnalyserView::CWeatherDataAnalyserView()
{
	// TODO: add construction code here

	method = new CString[14];
	method[0] = CString("depth");
	method[1] = CString("vcar");
	method[2] = CString("vtpk");
	method[3] = CString("vcmx");
	method[4] = CString("wdir1");
	method[5] = CString("wspd1");
	method[6] = CString("gspd1");
	method[7] = CString("wdir2");
	method[8] = CString("wspd2");
	method[9] = CString("gspd2");
	method[10] = CString("atms1");
	method[11] = CString("atms2");
	method[12] = CString("dryt");
	method[13] = CString("sstp");


	pens = new CPen[15];
	pens[0].CreatePen(PS_SOLID, 1, RGB(64, 0, 0));
	pens[13].CreatePen(PS_SOLID, 1, RGB(128, 0, 0));
	pens[2].CreatePen(PS_SOLID, 1, RGB(192, 0, 0));
	pens[7].CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	pens[4].CreatePen(PS_SOLID, 1, RGB(0, 64, 0));
	pens[9].CreatePen(PS_SOLID, 1, RGB(0, 128, 0));
	pens[11].CreatePen(PS_SOLID, 1, RGB(0, 192, 0));
	pens[3].CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	pens[8].CreatePen(PS_SOLID, 1, RGB(0, 0, 64));
	pens[5].CreatePen(PS_SOLID, 1, RGB(0, 0, 128));
	pens[10].CreatePen(PS_SOLID, 1, RGB(0, 0, 192));
	pens[6].CreatePen(PS_SOLID, 1, RGB(128, 0, 255));
	pens[12].CreatePen(PS_SOLID, 1, RGB(128, 128, 128));
	pens[1].CreatePen(PS_SOLID, 1, RGB(128, 255, 128));
	pens[14].CreatePen(PS_SOLID, 8, RGB(0, 255, 255));		//used for hightlight if flag!=1


}

CWeatherDataAnalyserView::~CWeatherDataAnalyserView()
{
}

BOOL CWeatherDataAnalyserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// method to draw the curve of each element and the axis 
void CWeatherDataAnalyserView::OnDraw(CDC* pDC)
{
	CWeatherDataAnalyserDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: add draw code for native data here
	int startx = 200;		//start coordinate value of X axis for plotting curve
	int starty = 50;		//start coordinate value of Y axis for plotting curve
	int ind = 0;			//declare a variable used to draw the label of weather data
	if (set.size() > 0)
	{
		pDC->MoveTo(150, 600);		// original point 150,600

		//draw X axis
		pDC->LineTo(startx + 2*pDoc->weather.TimeSpan::length(), 600);
		pDC->LineTo(startx + 2 * pDoc->weather.TimeSpan::length() - 10, 600 - 5);
		
		pDC->MoveTo(150, 600);		// move to original point 150,600

		//draw Y yaxis
		pDC->LineTo(150, 600 - 560);
		pDC->LineTo(150 - 5, 600 - 560 + 10);

		//label the X axis as "time"
		CString labelx;
		labelx="time";
		pDC->TextOut(startx + 2 * pDoc->weather.TimeSpan::length(), 610, labelx);

		std::set<int>::iterator it = set.begin();		//refer to the first element in the set container.
		for (; it != set.end(); it++)
		{
			YAxisScale(pDC,it);			//invoke the function to draw the scale of Y axis
			int index = *it;			
			if (pDoc->weather.DrawSet.size() <= 0)
				break;
			if (pDoc->weather.DrawSet[index].size() <= 0)
				break;

			pDC->MoveTo(0, starty+starty*ind);
			ind++;
			pDC->SelectObject(&pens[index]);
			pDC->LineTo(starty, starty + starty*ind);				//draw the line for label
			pDC->TextOut(starty, starty * ind, method[index]);		//draw the label for component

			//draw the curve of element for weather data
			pDC->MoveTo(startx, starty + pDoc->weather.DrawSet[index][0]);
			for (int i = 1; i < pDoc->weather.DrawSet[index].size(); i++)
			{
				if (pDoc->weather.flag[i] == 1)													//the data with good quality
					pDC->LineTo(startx + i * 2, starty + pDoc->weather.DrawSet[index][i]);		//draw the curve for data
				else
				{																				//data with poor quality
					pDC->LineTo(startx + i * 2, starty + pDoc->weather.DrawSet[index][i]);
					pDC->SelectObject(&pens[14]);												// highlight pen
					pDC->LineTo(startx + i * 2, starty + pDoc->weather.DrawSet[index][i]);
					pDC->SelectObject(&pens[index]);											// recovery
				}
			}
		}
	}
}

// CWeatherDataAnalyserView drawing
//method to draw the Y scale of weather data
void CWeatherDataAnalyserView::YAxisScale(CDC* pDC, std::set<int>::iterator it)
{
	CWeatherDataAnalyserDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//draw five point on Y aixs
	for (int i = 0; i <= 5; i++)
	{
		pDC->MoveTo(150, 50 + i * 100);
		pDC->LineTo(160, 50 + i * 100);
	}

	CString YScale;
	switch (*it)
	{
	//Scale of Y axis for depth
	case 0:
		for (int i = 0; i <= 5; i++)
		{
			YScale.Format(_T("%0.1f"), pDoc->weather.maxDepth - i * pDoc->weather.interval[0]);
			pDC->TextOut(100, 45 + i * 100, YScale);
		};
		break;

	//Scale of Y axis for vcar
	case 1:
		for (int i = 0; i <= 5; i++)
		{
			YScale.Format(_T("%0.1f"), pDoc->weather.maxVcar - i * pDoc->weather.interval[1]);
			pDC->TextOut(100, 45 + i * 100, YScale);
		}
		break;

	//Scale of Y axis for vtpk
	case 2:
		for (int i = 0; i <= 5; i++)
		{
			YScale.Format(_T("%0.1f"), pDoc->weather.maxVtpk - i * pDoc->weather.interval[2]);
			pDC->TextOut(100, 45 + i * 100, YScale);
		}
		break;

	//Scale of Y axis for vcmx
	case 3:
		for (int i = 0; i <= 5; i++)
		{
			YScale.Format(_T("%0.1f"), pDoc->weather.maxVcmx - i * pDoc->weather.interval[3]);
			pDC->TextOut(100, 45 + i * 100, YScale);
		}
		break;

	//Scale of Y axis for wdir1
	case 4:
		for (int i = 0; i <= 5; i++)
		{
			YScale.Format(_T("%0.1f"), pDoc->weather.maxWdir1 - i * pDoc->weather.interval[4]);
			pDC->TextOut(100, 45 + i * 100, YScale);
		}
		break;

	//Scale of Y axis for wspd1
	case 5:
		for (int i = 0; i <= 5; i++)
		{
			YScale.Format(_T("%0.1f"), pDoc->weather.maxWspd1 - i * pDoc->weather.interval[5]);
			pDC->TextOut(100, 45 + i * 100, YScale);
		}
		break;

	//Scale of Y axis for gspd1
	case 6:
		for (int i = 0; i <= 5; i++)
		{
			YScale.Format(_T("%0.1f"), pDoc->weather.maxGspd1 - i * pDoc->weather.interval[6]);
			pDC->TextOut(100, 45 + i * 100, YScale);
		}
		break;

	//Scale of Y axis for wdir2
	case 7:
		for (int i = 0; i <= 5; i++)
		{
			YScale.Format(_T("%0.1f"), pDoc->weather.maxWdir2 - i * pDoc->weather.interval[7]);
			pDC->TextOut(100, 45 + i * 100, YScale);
		}
		break;

	//Scale of Y axis for wspd2
	case 8:
		for (int i = 0; i <= 5; i++)
		{
			YScale.Format(_T("%0.1f"), pDoc->weather.maxWspd2 - i * pDoc->weather.interval[8]);
			pDC->TextOut(100, 45 + i * 100, YScale);
		}
		break;

	//Scale of Y axis for gspd2
	case 9:
		for (int i = 0; i <= 5; i++)
		{
			YScale.Format(_T("%0.1f"), pDoc->weather.maxGspd2 - i * pDoc->weather.interval[9]);
			pDC->TextOut(100, 45 + i * 100, YScale);
		}
		break;

	//Scale of Y axis for atms1
	case 10:
		for (int i = 0; i <= 5; i++)
		{
			YScale.Format(_T("%0.1f"), pDoc->weather.maxAtms1 - i * pDoc->weather.interval[10]);
			pDC->TextOut(100, 45 + i * 100, YScale);
		}
		break;

	//Scale of Y axis for atms2
	case 11:
		for (int i = 0; i <= 5; i++)
		{
			YScale.Format(_T("%0.1f"), pDoc->weather.maxAtms2 - i * pDoc->weather.interval[11]);
			pDC->TextOut(100, 45 + i * 100, YScale);
		}
		break;

	//Scale of Y axis for dryt
	case 12:
		for (int i = 0; i <= 5; i++)
		{
			YScale.Format(_T("%0.1f"), pDoc->weather.maxDryt - i * pDoc->weather.interval[12]);
			pDC->TextOut(100, 45 + i * 100, YScale);
		}
		break;

	//Scale of Y axis for sstp
	case 13:
		for (int i = 0; i <= 5; i++)
		{
			YScale.Format(_T("%0.1f"), pDoc->weather.maxSstp - i * pDoc->weather.interval[13]);
			pDC->TextOut(100, 45 + i * 100, YScale);
		}
		break;
	}
}

//method to provide the scale of input data to mapping mode 
void CWeatherDataAnalyserView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	//	CSize sizeTotal;
	// TODO: calculate the total size of this view

	CSize DocSize{ 167000 * 2, 800 };			//X Axis:totale data element 16700 * interval 2, Y axis: total height: 800
	CSize PagesScroll{ 500, 500 };			
	CSize LineScroll{ 20, 20 };
	SetScrollSizes(MM_TEXT, DocSize, PagesScroll, LineScroll);

	//	sizeTotal.cx = sizeTotal.cy = 100;
	//	SetScrollSizes(MM_TEXT, sizeTotal);
}

// CWeatherDataAnalyserView printing
BOOL CWeatherDataAnalyserView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWeatherDataAnalyserView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWeatherDataAnalyserView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CWeatherDataAnalyserView diagnostics

#ifdef _DEBUG
void CWeatherDataAnalyserView::AssertValid() const
{
	CView::AssertValid();
}

void CWeatherDataAnalyserView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeatherDataAnalyserDoc* CWeatherDataAnalyserView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeatherDataAnalyserDoc)));
	return (CWeatherDataAnalyserDoc*)m_pDocument;
}
#endif //_DEBUG


// CWeatherDataAnalyserView message handlers


//Function of message handler for menu time span to get the start time and end time within a selected time span. 
void CWeatherDataAnalyserView::OnTimeTimespan()
{
	TimeDialog TimeDialog;
	time_t StartTime, EndTime;
	time_t from;
	time_t to;
	CWeatherDataAnalyserDoc* pDoc = GetDocument();
	if (TimeDialog.DoModal() == IDOK)
	{
		StartTime = TimeDialog.start.GetTime();
		EndTime = TimeDialog.to.GetTime();
		pDoc->weather.TimeLength(StartTime, EndTime);
		pDoc->weather.AxisScale::YInterval();			//invoke the funtion to get the maximum and minmum value for component
		pDoc->weather.CElement::DataInterval(500);		//invoke the funtion to get the interval of each element for plot
	}
	Invalidate(true);
}

//Function of message handler for menu depth to store the order value of depth into set container. 
void CWeatherDataAnalyserView::OnDataDepth()
{
	// TODO: Add your command handler code here
	std::set<int>::iterator it = set.begin();
	for (; it != set.end(); it++)
	{
		if (*it == 0)		//no group
		{
			continue;
		}
		else
		{
			set.clear();	//clear
			break;
		}
	}

	// if exist then remove
	if (set.count(0))		//Searches the container for elements equivalent to value and returns the number of matches (1 or 0)
		set.erase(0);		//erase the element
	else
		set.insert(0);		//insert the element
	Invalidate(true);		
}

//Function of message handler for menu vcar to store the order value of vcar into set container. 
void CWeatherDataAnalyserView::OnDataVcar()
{
	// TODO: Add your command handler code here
	std::set<int>::iterator it = set.begin();
	for (; it != set.end(); it++)
	{
		if (*it == 1 || *it == 2 || *it == 3)		//group with vcar, vtpk and vcmx
		{
			continue;
		}
		else
		{
			set.clear();
			break;
		}
	}

	if (set.count(1))		// if exist then remove
		set.erase(1);
	else
		set.insert(1);
	Invalidate(true);
}

//Function of message handler for menu vtpk to store the order value of vtpk into set container. 
void CWeatherDataAnalyserView::OnDataVtpk()
{
	// TODO: Add your command handler code here
	std::set<int>::iterator it = set.begin();
	for (; it != set.end(); it++)
	{
		if (*it == 1 || *it == 2 || *it == 3)		//group with vcar, vtpk and vcmx
		{
			continue;
		}
		else
		{
			set.clear();
			break;
		}
	}
	// if exist then remove
	if (set.count(2))
		set.erase(2);
	else
		set.insert(2);
	Invalidate(true);
}

//Function of message handler for menu vcmx to store the order value of vcmx into set container. 
void CWeatherDataAnalyserView::OnDataVcmx()
{
	// TODO: Add your command handler code here
	std::set<int>::iterator it = set.begin();
	for (; it != set.end(); it++)
	{
		if (*it == 1 || *it == 2 || *it == 3)		//group with vcar, vtpk and vcmx
		{
			continue;
		}
		else
		{
			set.clear();
			break;
		}
	}

	// if exist then remove
	if (set.count(3))
		set.erase(3);
	else
		set.insert(3);
	Invalidate(true);
}

//Function of message handler for menu wdir1 to store the order value of wdir1 into set container.
void CWeatherDataAnalyserView::OnDataWdir1()
{
	// TODO: Add your command handler code here
	std::set<int>::iterator it = set.begin();
	for (; it != set.end(); it++)
	{
		if (*it == 4 || *it == 7)	//group with wdir1 and wdir2
		{
			continue;
		}
		else
		{
			set.clear();
			break;
		}
	}

	// if exist then remove
	if (set.count(4))
		set.erase(4);
	else
		set.insert(4);
	Invalidate(true);
}

//Function of message handler for menu wspd1 to store the order value of wspd1 into set container.
void CWeatherDataAnalyserView::OnDataWspd1()
{
	// TODO: Add your command handler code here
	std::set<int>::iterator it = set.begin();
	for (; it != set.end(); it++)
	{
		if (*it == 5 || *it == 6 || *it == 8 || *it == 9)		//group with wspd1, wspd2, gspd1 and gspd2
		{
			continue;
		}
		else
		{
			set.clear();
			break;
		}
	}

	// if exist then remove
	if (set.count(5))
		set.erase(5);
	else
		set.insert(5);
	Invalidate(true);
}

//Function of message handler for menu gspd1 to store the order value of gspd1 into set container. 
void CWeatherDataAnalyserView::OnDataGspd1()
{
	// TODO: Add your command handler code here
	std::set<int>::iterator it = set.begin();
	for (; it != set.end(); it++)
	{
		if (*it == 5 || *it == 6 || *it == 8 || *it == 9)		//group with wspd1, wspd2, gspd1 and gspd2
		{
			continue;
		}
		else
		{
			set.clear();
			break;
		}
	}

	// if exist then remove
	if (set.count(6))
		set.erase(6);
	else
		set.insert(6);
	Invalidate(true);
}

//Function of message handler for menu wdir2 to store the order value of wdir2 into set container. 
void CWeatherDataAnalyserView::OnDataWdir2()
{
	// TODO: Add your command handler code here
	std::set<int>::iterator it = set.begin();
	for (; it != set.end(); it++)
	{
		if (*it == 4 || *it == 7)		//group with wdir2
		{
			continue;
		}
		else
		{
			set.clear();
			break;
		}
	}

	// if exist then remove
	if (set.count(7))
		set.erase(7);
	else
		set.insert(7);
	Invalidate(true);
}

//Function of message handler for menu wspd2 to store the order value of wspd2 into set container. 
void CWeatherDataAnalyserView::OnDataWspd2()
{
	// TODO: Add your command handler code here
	std::set<int>::iterator it = set.begin();
	for (; it != set.end(); it++)
	{
		if (*it == 5 || *it == 6 || *it == 8 || *it == 9)	//group with wspd1, wspd2, gspd1 and gspd2
		{
			continue;
		}
		else
		{
			set.clear();
			break;
		}
	}

	// if exist then remove
	if (set.count(8))
		set.erase(8);
	else
		set.insert(8);
	Invalidate(true);
}

//Function of message handler for menu gspd2 to store the order value of gspd2 into set container. 
void CWeatherDataAnalyserView::OnDataGspd2()
{
	// TODO: Add your command handler code here
	std::set<int>::iterator it = set.begin();
	for (; it != set.end(); it++)
	{
		if (*it == 5 || *it == 6 || *it == 8 || *it == 9)		//group with wspd1, wspd2, gspd1 and gspd2
		{
			continue;
		}
		else
		{
			set.clear();
			break;
		}
	}
	// if exist then remove
	if (set.count(9))
		set.erase(9);
	else
		set.insert(9);
	Invalidate(true);
}

//Function of message handler for menu atms1 to store the order value of atms1 into set container.
void CWeatherDataAnalyserView::OnDataAtms1()
{
	// TODO: Add your command handler code here
	std::set<int>::iterator it = set.begin();
	for (; it != set.end(); it++)
	{
		if (*it == 10 || *it == 11)			//group with atms1 and atms2
		{
			continue;
		}
		else
		{
			set.clear();
			break;
		}
	}

	// if exist then remove
	if (set.count(10))
		set.erase(10);
	else
		set.insert(10);
	Invalidate(true);
}

//Function of message handler for menu atms2 to store the order value of atms2 into set container. 
void CWeatherDataAnalyserView::OnDataAtms2()
{
	// TODO: Add your command handler code here
	std::set<int>::iterator it = set.begin();
	for (; it != set.end(); it++)
	{
		if (*it == 10 || *it == 11)		//group with atms1 and atms2
		{
			continue;
		}
		else
		{
			set.clear();
			break;
		}
	}

	// if exist then remove
	if (set.count(11))
		set.erase(11);
	else
		set.insert(11);
	Invalidate(true);
}

//Function of message handler for menu dryt to store the order value of dryt into set container. 
void CWeatherDataAnalyserView::OnDataDryt()
{
	// TODO: Add your command handler code here
	std::set<int>::iterator it = set.begin();
	for (; it != set.end(); it++)
	{
		if (*it == 12 || *it == 13)			//group with dryt and sstp
		{
			continue;
		}
		else
		{
			set.clear();
			break;
		}
	}

	// if exist then remove
	if (set.count(12))
		set.erase(12);
	else
		set.insert(12);
	Invalidate(true);
}

//Function of message handler for menu sstp to store the order value of sstp into set container. 
void CWeatherDataAnalyserView::OnDataSstp()
{
	// TODO: Add your command handler code here
	std::set<int>::iterator it = set.begin();
	for (; it != set.end(); it++)
	{
		if (*it == 12 || *it == 13)			//group with dryt and sstp
		{
			continue;
		}
		else
		{
			set.clear();
			break;
		}
	}

	// if exist then remove
	if (set.count(13))
		set.erase(13);
	else
		set.insert(13);
	Invalidate(true);
}

//Function of message handler for menu depth to check the item to indicate the selected element of depth.
void CWeatherDataAnalyserView::OnUpdateDataDepth(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	int count = set.count(0);
	if (count)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

//Function of message handler for menu vcar to check the item to indicate the selected element of vcar.
void CWeatherDataAnalyserView::OnUpdateDataVcar(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	int count = set.count(1);
	if (count)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

//Function of message handler for menu vtpk to check the item to indicate the selected element of vtpk.
void CWeatherDataAnalyserView::OnUpdateDataVtpk(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	int count = set.count(2);
	if (count)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

//Function of message handler for menu vcmx to check the item to indicate the selected element of vcmx.
void CWeatherDataAnalyserView::OnUpdateDataVcmx(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	int count = set.count(3);
	if (count)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

//Function of message handler for menu wdir1 to check the item to indicate the selected element of wdir1.
void CWeatherDataAnalyserView::OnUpdateDataWdir1(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	int count = set.count(4);
	if (count)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

//Function of message handler for menu wspd1 to check the item to indicate the selected element of wspd1.
void CWeatherDataAnalyserView::OnUpdateDataWspd1(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	int count = set.count(5);
	if (count)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

//Function of message handler for menu gspd1 to check the item to indicate the selected element of gspd1.
void CWeatherDataAnalyserView::OnUpdateDataGspd1(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	int count = set.count(6);
	if (count)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

//Function of message handler for menu wdir2 to check the item to indicate the selected element of wdir2.
void CWeatherDataAnalyserView::OnUpdateDataWdir2(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	int count = set.count(7);
	if (count)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

//Function of message handler for menu wspd2 to check the item to indicate the selected element of wspd2.
void CWeatherDataAnalyserView::OnUpdateDataWspd2(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	int count = set.count(8);
	if (count)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

//Function of message handler for menu gspd2 to check the item to indicate the selected element of gspd2.
void CWeatherDataAnalyserView::OnUpdateDataGspd2(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	int count = set.count(9);
	if (count)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

//Function of message handler for menu atms1 to check the item to indicate the selected element of atms1.
void CWeatherDataAnalyserView::OnUpdateDataAtms1(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	int count = set.count(10);
	if (count)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

//Function of message handler for menu atms2 to check the item to indicate the selected element of atms2.
void CWeatherDataAnalyserView::OnUpdateDataAtms2(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	int count = set.count(11);
	if (count)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

//Function of message handler for menu sstp to check the item to indicate the selected element of dryt
void CWeatherDataAnalyserView::OnUpdateDataDryt(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	int count = set.count(12);
	if (count)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

//Function of message handler for menu sstp to check the item to indicate the selected element of sstp.
void CWeatherDataAnalyserView::OnUpdateDataSstp(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	int count = set.count(13);
	if (count)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

//Function of message handler for the menu reset.
void CWeatherDataAnalyserView::OnCleanReset()
{
	// TODO: Add your command handler code here
	set.clear();
	Invalidate(true);
}

//Function of message handler for the menu save.
void CWeatherDataAnalyserView::OnFileSave()
{
	// TODO: Add your command handler code here
	CString defaultDir = L"";		//Default file path 
	CString fileName = L"";         //Default file name
	CString filter = L"file (*.bmp)|*.bmp||";		//Type of filter file
	CString	FilePathName;
	CFileDialog dlg(FALSE, defaultDir, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);

	if (dlg.DoModal() == IDOK)
	{
		FilePathName = dlg.GetPathName();
		CClientDC dc(this);
		CRect rect;
		GetClientRect(&rect);
		HBITMAP hbitmap = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
		HDC hdc = CreateCompatibleDC(dc);
		HBITMAP hOldMap = (HBITMAP)SelectObject(hdc, hbitmap);
		BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, dc, 0, 0, SRCCOPY);
		CImage image;
		image.Attach(hbitmap);
		HRESULT hResult = image.Save(FilePathName);
		image.Detach();
		SelectObject(hdc, hOldMap);
	}
}
