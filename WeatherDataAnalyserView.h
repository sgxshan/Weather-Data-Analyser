
// WeatherDataAnalyserView.h : interface of the CWeatherDataAnalyserView class
//

#pragma once
#define WIDTH 800
#define HEIGHT 500
#include <set>
#include "TimeDialog.h"
using namespace std;
class CWeatherDataAnalyserView : public CScrollView
{
protected: // create from serialization only
	CWeatherDataAnalyserView();
	DECLARE_DYNCREATE(CWeatherDataAnalyserView)

	CString *method;	//declare pointer variable to store the name of each element of weather data
// Attributes
public:
	CWeatherDataAnalyserDoc* GetDocument() const;
	CPen *pens;			//delcare pen objects with different colour, and thickness for different elements
	set<int> set;		//declare a container set that store unique elements following a specific order

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);		// method to draw the curve of each element 
	virtual	void YAxisScale(CDC* pDC, std::set<int>::iterator it);		//method to draw the Y scale of weather data
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate();		//method to provide the scale of input data to mapping mode 
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CWeatherDataAnalyserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnTimeTimespan();		//Function of message handler for menu time span to get the start time and end time within a selected time span. 
	afx_msg void OnDataDepth();			//Function of message handler for menu depth to store the order value of depth into set container. 
	afx_msg void OnDataVcar();			//Function of message handler for menu vcar to store the order value of vcar into set container. 
	afx_msg void OnDataVtpk();			//Function of message handler for menu vtpk to store the order value of vtpk into set container. 
	afx_msg void OnDataVcmx();			//Function of message handler for menu vcmx to store the order value of vcmx into set container. 
	afx_msg void OnDataWdir1();			//Function of message handler for menu wdir1 to store the order value of wdir1 into set container. 
	afx_msg void OnDataWspd1();			//Function of message handler for menu wspd1 to store the order value of wspd1 into set container. 
	afx_msg void OnDataGspd1();			//Function of message handler for menu gspd1 to store the order value of gspd1 into set container. 
	afx_msg void OnDataWdir2();			//Function of message handler for menu wdir2 to store the order value of wdir2 into set container. 
	afx_msg void OnDataWspd2();			//Function of message handler for menu wspd2 to store the order value of wspd2 into set container. 
	afx_msg void OnDataGspd2();			//Function of message handler for menu gspd2 to store the order value of gspd2 into set container. 
	afx_msg void OnDataAtms1();			//Function of message handler for menu atms1 to store the order value of atms1 into set container. 
	afx_msg void OnDataAtms2();			//Function of message handler for menu atms2 to store the order value of atms2 into set container. 
	afx_msg void OnDataDryt();			//Function of message handler for menu dryt to store the order value of dryt into set container. 
	afx_msg void OnDataSstp();			//Function of message handler for menu sstp to store the order value of sstp into set container. 
	afx_msg void OnUpdateDataDepth(CCmdUI *pCmdUI);		//Function of message handler for menu depth to check the item to indicate the selected element of depth.
	afx_msg void OnUpdateDataVcar(CCmdUI *pCmdUI);		//Function of message handler for menu vcar to check the item to indicate the selected element of vcar.
	afx_msg void OnUpdateDataVtpk(CCmdUI *pCmdUI);		//Function of message handler for menu vtpk to check the item to indicate the selected element of vtpk.
	afx_msg void OnUpdateDataWspd1(CCmdUI *pCmdUI);		//Function of message handler for menu wspd1 to check the item to indicate the selected element of wspd1.
	afx_msg void OnUpdateDataGspd1(CCmdUI *pCmdUI);		//Function of message handler for menu gspd1 to check the item to indicate the selected element of gspd1.
	afx_msg void OnUpdateDataWdir2(CCmdUI *pCmdUI);		//Function of message handler for menu wdir2 to check the item to indicate the selected element of wdir2.
	afx_msg void OnUpdateDataWspd2(CCmdUI *pCmdUI);		//Function of message handler for menu wspd2 to check the item to indicate the selected element of wspd2.
	afx_msg void OnUpdateDataGspd2(CCmdUI *pCmdUI);		//Function of message handler for menu gspd2 to check the item to indicate the selected element of gspd2.
	afx_msg void OnUpdateDataAtms1(CCmdUI *pCmdUI);		//Function of message handler for menu atms1 to check the item to indicate the selected element of atms1.
	afx_msg void OnUpdateDataAtms2(CCmdUI *pCmdUI);		//Function of message handler for menu atms2 to check the item to indicate the selected element of atms2.
	afx_msg void OnUpdateDataSstp(CCmdUI *pCmdUI);		//Function of message handler for menu sstp to check the item to indicate the selected element of sstp.
	afx_msg void OnUpdateDataDryt(CCmdUI *pCmdUI);		//Function of message handler for menu dryt to check the item to indicate the selected element of dryt.
	afx_msg void OnUpdateDataWdir1(CCmdUI *pCmdUI);		//Function of message handler for menu wdir1 to check the item to indicate the selected element of wdir1.
	afx_msg void OnUpdateDataVcmx(CCmdUI *pCmdUI);		//Function of message handler for menu vcmx to check the item to indicate the selected element of vcmx.
	afx_msg void OnCleanReset();		//Function of message handler for the menu reset.
	afx_msg void OnFileSave();			//Function of message handler for the menu save.
};

#ifndef _DEBUG  // debug version in WeatherDataAnalyserView.cpp
inline CWeatherDataAnalyserDoc* CWeatherDataAnalyserView::GetDocument() const
   { return reinterpret_cast<CWeatherDataAnalyserDoc*>(m_pDocument); }
#endif

