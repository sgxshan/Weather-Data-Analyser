// TimeDialog.cpp : implementation file
//

#include "stdafx.h"
#include "WeatherDataAnalyser.h"
#include "TimeDialog.h"
#include "afxdialogex.h"


// TimeDialog dialog

IMPLEMENT_DYNAMIC(TimeDialog, CDialogEx)

TimeDialog::TimeDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(TimeDialog::IDD, pParent)
{

}

TimeDialog::~TimeDialog()
{
}

void TimeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, timeFrom);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, timeTo);
}


BEGIN_MESSAGE_MAP(TimeDialog, CDialogEx)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &TimeDialog::OnDtnDatetimechangeDatetimepicker1)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER2, &TimeDialog::OnDtnDatetimechangeDatetimepicker2)
END_MESSAGE_MAP()


// TimeDialog message handlers

//Function of message handler for the data time picker to obtain and store the start time in time variable
void TimeDialog::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	timeFrom.GetTime(start);
}

//Function of message handler for the data time picker to obtain and store the end time in time variable
void TimeDialog::OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	timeTo.GetTime(to);
}
