#pragma once
#include <DuiLib/UIlib.h>
#include <vector>

class CNotificationNetworkStatus;

#define  BT_SearchLog		(_T("search"))
#define		BT_OnStartTime		(_T("DataTime1"))
#define	 BT_OnStopTime		(_T("DataTime2"))

typedef struct 
{
	STDSTRING	Time;
	STDSTRING	Handle;
	STDSTRING	Description;
}Log_Search;

typedef struct 
{
	STDSTRING	Time;
	STDSTRING	Address;
	STDSTRING	Collect_people;
	STDSTRING	CaseName;
	STDSTRING	Case_description;
	STDSTRING	EquipmentIP;
	STDSTRING	Remark;
}Case_Search;

class CLogUI :
	public WindowImplBase
{
public:
	CLogUI();
	~CLogUI();
	virtual void InitWindow();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();
	void OnBeginSearch(TNotifyUI& msg);

	void OnSearchLog();
	void OnSearchCaseLog();

	void CreateLogList();
	void CreateCaseList();

	void InsertLogInfoToList();
	void InsertCaseInfoToList();

	void OnSelectStartTime(TNotifyUI& msg);
	void OnSelectStopTime(TNotifyUI& msg);
	void exportLog();
	void InitTime();

	void SetBtDataImage(STDSTRING& BT_Name, STDSTRING& day);

	void HandleNotificationNetworkStatus(CNotificationNetworkStatus* pNf);
	void SetNetWorkState(NOTIFICATION_TYPE& eNotify);

protected:
	std::vector<Log_Search>		m_LogInfo;
	std::vector<Case_Search>		m_CaseInfo;
	BOOL					m_bInit;
	SYSTEMTIME		 m_sysTime;
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};
