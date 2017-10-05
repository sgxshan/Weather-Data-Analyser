
// WeatherDataAnalyserDoc.h : interface of the CWeatherDataAnalyserDoc class
//


#pragma once
#include "CWeather.h"


class CWeatherDataAnalyserDoc : public CDocument
{
protected: // create from serialization only
	CWeatherDataAnalyserDoc();
	DECLARE_DYNCREATE(CWeatherDataAnalyserDoc)

// Attributes
public:
	CWeather weather;		//invoke the class 
// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CWeatherDataAnalyserDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnFileOpen();  //Function of message handler of menu Open to get the file path name and load data.
};
