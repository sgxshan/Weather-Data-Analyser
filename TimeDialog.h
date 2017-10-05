#pragma once
#include "afxdtctl.h"

// TimeDialog dialog

class TimeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TimeDialog)

public:
	TimeDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~TimeDialog();

// Dialog Data
	enum { IDD = IDD_TIMEDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CTime start, to;		//declare two time variable to store the start time and end time for a selected time span

	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);		//Function of message handler for the data time picker to obtain and store the start time in time variable
	afx_msg void OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult);		//Function of message handler for the data time picker to obtain and store the end time in time variable
	CDateTimeCtrl timeFrom;		//Time picker control for end time
	CDateTimeCtrl timeTo;		//Time picker control for end time
};
