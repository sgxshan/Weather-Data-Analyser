
// WeatherDataAnalyserDoc.cpp : implementation of the CWeatherDataAnalyserDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "WeatherDataAnalyser.h"
#endif

#include "WeatherDataAnalyserDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CWeatherDataAnalyserDoc

IMPLEMENT_DYNCREATE(CWeatherDataAnalyserDoc, CDocument)

BEGIN_MESSAGE_MAP(CWeatherDataAnalyserDoc, CDocument)
	ON_COMMAND(ID_FILE_OPEN, &CWeatherDataAnalyserDoc::OnFileOpen)
END_MESSAGE_MAP()


// CWeatherDataAnalyserDoc construction/destruction

CWeatherDataAnalyserDoc::CWeatherDataAnalyserDoc()
{
	// TODO: add one-time construction code here

}

CWeatherDataAnalyserDoc::~CWeatherDataAnalyserDoc()
{
}

BOOL CWeatherDataAnalyserDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CWeatherDataAnalyserDoc serialization

void CWeatherDataAnalyserDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}

}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CWeatherDataAnalyserDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CWeatherDataAnalyserDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CWeatherDataAnalyserDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CWeatherDataAnalyserDoc diagnostics

#ifdef _DEBUG
void CWeatherDataAnalyserDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWeatherDataAnalyserDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CWeatherDataAnalyserDoc commands

//Function of message handler of menu Open to get the file path name and load data.
void CWeatherDataAnalyserDoc::OnFileOpen()
{
	// szFilters - name filters:
	TCHAR szFilters[] = _T("MyType Files (*.csv)| *.csv | All Files(*.*) | *.* || ");
		
	// Create an Open dialog;
	CFileDialog fileDlg(TRUE, _T("csv"), _T("*.csv"),OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,szFilters);
	
	// Display the file dialog
	if (fileDlg.DoModal() == IDOK)
	{
		CString	PathName = fileDlg.GetPathName();
		weather.LoadDate(PathName);			//Invoke the function to load data 
	}
}
