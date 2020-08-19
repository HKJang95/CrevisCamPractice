
// CrevisCamPracticeDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "CrevisCamPractice.h"
#include "CrevisCamPracticeDlg.h"
#include "afxdialogex.h"
#include "VirtualFG40.h"

// #ifdef _DEBUG
// #define new DEBUG_NEW
// #endif

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

void ThreadProc(CCrevisCamPracticeDlg* pPrivate)
{
	pPrivate->ReceiveImage();
}
// ThreadProcesses : used for createthread

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCrevisCamPracticeDlg 대화 상자



CCrevisCamPracticeDlg::CCrevisCamPracticeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCrevisCamPracticeDlg::IDD, pParent)
	, m_hDevice(0)
	, m_Width(0)
	, m_Height(0)
	, m_BufferSize(0)
	, m_pImage(NULL)
	, m_IsOpened(FALSE)
	, m_pBitmap(NULL)
	, m_deviceEnum(-1)
	, m_roiX(0)
	, m_roiY(0)
	, m_roiWidth(0)
	, m_roiHeight(0)
	, m_hThread(NULL)

{
	for (int i = 0; i < TOTAL_DISP; i++)
	{
		m_pGraphics[i] = NULL;
		m_hDC[i] = NULL;
		m_rcDisp[i] = NULL;
		m_IsPlay[i] = FALSE;
	}

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_hTerminate = CreateEvent(NULL, true, false, NULL);
}

void CCrevisCamPracticeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DEVICEIP, m_DeviceIPControl);
	DDX_Control(pDX, IDC_TBTHRESHOLD, m_TBThreshold);
	DDX_Control(pDX, IDC_ROIXTB, m_TBRoiX);
	DDX_Control(pDX, IDC_ROIYTB, m_TBRoiY);
	DDX_Control(pDX, IDC_ROIWITB, m_TBWidth);
	DDX_Control(pDX, IDC_ROIHETB, m_TBRoiHeight);
}

BEGIN_MESSAGE_MAP(CCrevisCamPracticeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPENBTN, &CCrevisCamPracticeDlg::OnBnClickedOpenbtn)
	ON_BN_CLICKED(IDC_CLOSEBTN, &CCrevisCamPracticeDlg::OnBnClickedClosebtn)
	ON_BN_CLICKED(IDC_NORPLAYBTN, &CCrevisCamPracticeDlg::OnBnClickedNorplaybtn)
	ON_BN_CLICKED(IDC_NORSTOPBTN, &CCrevisCamPracticeDlg::OnBnClickedNorstopbtn)
	ON_BN_CLICKED(IDC_ROIPLAYBTN, &CCrevisCamPracticeDlg::OnBnClickedRoiplaybtn)
	ON_BN_CLICKED(IDC_ROISTOPBTN, &CCrevisCamPracticeDlg::OnBnClickedRoistopbtn)
	ON_BN_CLICKED(IDC_BINPLAYBTN, &CCrevisCamPracticeDlg::OnBnClickedBinplaybtn)
	ON_BN_CLICKED(IDC_BINSTOPBTN, &CCrevisCamPracticeDlg::OnBnClickedBinstopbtn)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CCrevisCamPracticeDlg 메시지 처리기

BOOL CCrevisCamPracticeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	if (ST_InitSystem() != MCAM_ERR_SUCCESS)
	{
		AfxMessageBox(_T("System Initializing Failed!"), MB_OK|MB_ICONSTOP);
	}

	m_DeviceIPControl.SetWindowTextW(_T("192.168.20.2"));
	m_TBRoiX.SetWindowTextW(_T("20"));
	m_TBRoiY.SetWindowTextW(_T("20"));
	m_TBWidth.SetWindowTextW(_T("200"));
	m_TBRoiHeight.SetWindowTextW(_T("200"));
	m_TBThreshold.SetWindowTextW(_T("125"));

	static CClientDC norDc(GetDlgItem(IDC_NOR_DISP));
	static CClientDC binDc(GetDlgItem(IDC_BIN_DISP));
	static CClientDC roiDc(GetDlgItem(IDC_ROI_DISP));
	static CClientDC rectDc(GetDlgItem(IDC_NOR_DISP));
	// dc init

	m_hDC[NORMAL_VID] = norDc.GetSafeHdc();
	m_hDC[BINARY_VID] = binDc.GetSafeHdc();
	m_hDC[ROI_VID] = roiDc.GetSafeHdc();
	// handle init

	GetDlgItem(IDC_NOR_DISP)->GetWindowRect(m_rcDisp[NORMAL_VID]);
	GetDlgItem(IDC_ROI_DISP)->GetWindowRect(m_rcDisp[ROI_VID]);
	GetDlgItem(IDC_BIN_DISP)->GetWindowRect(m_rcDisp[BINARY_VID]);
	// rect info init

	m_pGraphics[NORMAL_VID] = Graphics::FromHDC(m_hDC[NORMAL_VID]);
	m_pGraphics[ROI_VID] = Graphics::FromHDC(m_hDC[ROI_VID]);
	m_pGraphics[BINARY_VID] = Graphics::FromHDC(m_hDC[BINARY_VID]);
	// get gdiplus handle

	GetDlgItem(IDC_OPENBTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_NORPLAYBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_ROIPLAYBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_BINPLAYBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_NORSTOPBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_ROISTOPBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_BINSTOPBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_CLOSEBTN)->EnableWindow(FALSE);

/////////////////////////////////////////////
	MemoryLeakCheck();
return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}



void CCrevisCamPracticeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCrevisCamPracticeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		for (int i = 0; i < TOTAL_DISP; i++)
		{
			if (m_IsPlay[i] && m_pBitmap)
			{
				DrawImage(i);
			}
		} // 디스플레이 flag 확인 후 TRUE인 디스플레이에 영상 시현

		CDialogEx::OnPaint();
	}
	MemoryLeakCheck();
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCrevisCamPracticeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
} 

void CCrevisCamPracticeDlg::MemoryLeakCheck() {	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); } 
// if memory leaks, it shows on the debug output window.

void CCrevisCamPracticeDlg::OnBnClickedOpenbtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	INT32 status = MCAM_ERR_SUCCESS;
	UINT32 bufsize = 40;
	UINT32 camNum = 0;
	CString availableIPstr;
	CString inputIP;
	CString deviceIPCstr;
	CString strErr;
	char * deviceIp = new char[bufsize];

	m_deviceEnum = -1;
	m_DeviceIPControl.GetWindowTextW(inputIP);
	// 유저 입력 IP를 받는 부분

	status = ST_UpdateDevice();
	if (status != MCAM_ERR_SUCCESS)
	{
		strErr.Format(_T("Device Update Fail! : %d"), status);
		AfxMessageBox(strErr, MB_OK | MB_ICONSTOP);
		delete[] deviceIp;
		deviceIp = NULL;
		return;
	} // Device Update : updates list of devices.
	
	ST_GetAvailableCameraNum(&camNum);
	if (camNum <= 0)
	{
		strErr.Format(_T("No Camera Available! Check connection."));
		AfxMessageBox(strErr, MB_OK | MB_ICONSTOP);
		delete[] deviceIp;
		deviceIp = NULL;
		return;
	} // get numbers of connected cams and check if at least 1 is connected


	for (unsigned int i = 0; i < camNum; i++)
	{
		status = ST_GetEnumDeviceInfo(i, MCAM_DEVICEINFO_IP_ADDRESS, deviceIp, &bufsize);
		if (status != MCAM_ERR_SUCCESS)
		{
			strErr.Format(_T("IP Address retrieving fail : Check network configuration! || code: %d"), status);
			AfxMessageBox(strErr, MB_OK | MB_ICONSTOP);
			delete[] deviceIp;
			deviceIp = NULL;
			return;
		}
		// getting IP addresses of all connected devices.
		else
		{
			deviceIPCstr = deviceIp;
			if (deviceIPCstr == inputIP)
			{
				m_deviceEnum = i;
			}
		}
		// compares with user input, and if matches sets enum to get handle of the device.
	}

	if (m_deviceEnum < 0)
	{
		strErr = (_T("Device not found with your input IP.\nAvailable IP list is : \n"));
		for (int i = 0; i < camNum; i++)
		{
			status = ST_GetEnumDeviceInfo(i, MCAM_DEVICEINFO_IP_ADDRESS, deviceIp, &bufsize);
			if (status != MCAM_ERR_SUCCESS)
			{
				strErr.Format(_T("IP Address retrieving fail : Check network configuration! || code: %d"), status);
				AfxMessageBox(strErr, MB_OK | MB_ICONSTOP);
				delete[] deviceIp;
				deviceIp = NULL;
				return;
			}
			availableIPstr = deviceIp;
			availableIPstr += _T("\n");
			strErr += availableIPstr;
		}
		AfxMessageBox(strErr);
		delete[] deviceIp;
		deviceIp = NULL;
		return;
	} // if no device found that matches with user IP input
	// Checks with user input IP address if a device has same IP address setting with user input
	
	status = ST_OpenDevice(m_deviceEnum, &m_hDevice);
	if (status != MCAM_ERR_SUCCESS)
	{
		strErr.Format(_T("Device Open Fail! : %d"), status);
		AfxMessageBox(strErr, MB_OK | MB_ICONSTOP);
		return;
	}

	SetFeature();

	//Get Width
	status = ST_GetIntReg(m_hDevice, MCAM_WIDTH, &m_Width);
	if (status != MCAM_ERR_SUCCESS)
	{
		strErr.Format(_T("Read Register failed : %d"), status);
		AfxMessageBox(strErr, MB_OK | MB_ICONSTOP);
		return;
	}

	//Get Height
	status = ST_GetIntReg(m_hDevice, MCAM_HEIGHT, &m_Height);
	if (status != MCAM_ERR_SUCCESS)
	{
		strErr.Format(_T("Read Register failed : %d"), status);
		AfxMessageBox(strErr, MB_OK | MB_ICONSTOP);
		return;
	}

	// Image Buffer Allocatation
	m_pBitmap = new Bitmap(m_Width, m_Height, PixelFormat8bppIndexed);
	
	m_BufferSize = m_Width * m_Height;
	m_pImage = malloc(m_BufferSize);
	memset((void*)m_pImage, 0, m_BufferSize);
	m_pGraphics[NORMAL_VID]->DrawImage(m_pBitmap, 0, 0, m_Width, m_Height);
	m_pGraphics[BINARY_VID]->DrawImage(m_pBitmap, 0, 0, m_Width, m_Height);
	m_pGraphics[ROI_VID]->DrawImage(m_pBitmap, 0, 0, m_Width, m_Height);

	m_IsOpened = TRUE;

	status = ST_AcqStart(m_hDevice);
	if (status != MCAM_ERR_SUCCESS)
	{
		strErr.Format(_T("Acquisition start failed : %d"), status);
		AfxMessageBox(strErr, MB_OK | MB_ICONSTOP);
		return;
	}
	// Camera acquitision starts when camera is been opened.


	ResetEvent(m_hTerminate); // terminate thread for normal video streaming signal off
	m_hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc, this, 0, NULL);

	AfxMessageBox(TEXT("Camera open complete! Acquisition started."));

	GetDlgItem(IDC_OPENBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_CLOSEBTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_BINPLAYBTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_NORPLAYBTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_ROIPLAYBTN)->EnableWindow(TRUE);

	delete[] deviceIp;
	deviceIp = NULL;

	MemoryLeakCheck();
} // When "Open" button click

void CCrevisCamPracticeDlg::OnBnClickedClosebtn()
{
	INT32 status = MCAM_ERR_SUCCESS;
	CString strErr;

	if (m_hThread != NULL)
	{
		SetEvent(m_hTerminate);
		WaitForSingleObject(m_hThread, INFINITE);
		CloseHandle(m_hThread);
		m_hThread = NULL;
	}// stops and frees threads.

	for (int i = 0; i < TOTAL_DISP; i++)
	{
		m_IsPlay[i] = FALSE;
	} // turning off all displays

	status = ST_AcqStop(m_hDevice);
	if (status != MCAM_ERR_SUCCESS)
	{
		strErr.Format(_T("Acquisition stop failed : %d"), status);
		AfxMessageBox(strErr, MB_OK | MB_ICONSTOP);
		return;
	}
	// Camera acquisition stops

	if (m_pImage != NULL)
	{
		free(m_pImage);
		m_pImage = NULL;
	}
	// image buffer free and nullification
	ST_CloseDevice(m_hDevice);
	m_IsOpened = FALSE;

	GetDlgItem(IDC_OPENBTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_NORPLAYBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_ROIPLAYBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_BINPLAYBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_NORSTOPBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_ROISTOPBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_BINSTOPBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_CLOSEBTN)->EnableWindow(FALSE);
	MemoryLeakCheck();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
} // when "Close" button click


void CCrevisCamPracticeDlg::OnBnClickedNorplaybtn()
{
	m_IsPlay[NORMAL_VID] = TRUE;
	GetDlgItem(IDC_NORPLAYBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_NORSTOPBTN)->EnableWindow(TRUE);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MemoryLeakCheck();
}// when normal "play" button click


void CCrevisCamPracticeDlg::OnBnClickedNorstopbtn()
{
	m_IsPlay[NORMAL_VID] = FALSE;
	GetDlgItem(IDC_NORPLAYBTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_NORSTOPBTN)->EnableWindow(FALSE);
	MemoryLeakCheck();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
} // when normal "stop" button click


void CCrevisCamPracticeDlg::OnBnClickedRoiplaybtn()
{
	CString CroiX, CroiY, CroiHeight, CroiWidth;
	CString strErr;
	m_TBRoiX.GetWindowTextW(CroiX);
	m_roiX = _ttoi(CroiX);
	m_TBRoiY.GetWindowTextW(CroiY);
	m_roiY = _ttoi(CroiY);
	m_TBRoiHeight.GetWindowTextW(CroiHeight);
	m_roiHeight = _ttoi(CroiHeight);
	m_TBWidth.GetWindowTextW(CroiWidth);
	m_roiWidth = _ttoi(CroiWidth);
	// Getting & setting coord and height, width info to designate ROI info

	if (m_roiX < 0 || m_roiY < 0 || m_roiHeight <= 0 || m_roiWidth <= 0)
	{
		AfxMessageBox(_T("Plase check ROI input : no value allowed under 0"));
		return;
	}

	if (m_roiX >= m_rcDisp[NORMAL_VID].Width() || 
		m_roiY >= m_rcDisp[NORMAL_VID].Height())
	{
		strErr.Format(_T("Coordinate out of bound || X MAX : %d / Y MAX : %d"), 
			m_rcDisp[NORMAL_VID].Width(), m_rcDisp[NORMAL_VID].Height());
		AfxMessageBox(strErr);
		return;
	}

	if ((m_roiWidth + m_roiX) > m_rcDisp[NORMAL_VID].Width()
		|| (m_roiHeight + m_roiY) > m_rcDisp[NORMAL_VID].Height())
	{
		strErr.Format(_T("Length out of bound || Width MAX : %d / Height MAX : %d"),
			m_rcDisp[NORMAL_VID].Width() - m_roiX, m_rcDisp[NORMAL_VID].Height() - m_roiY);
		AfxMessageBox(strErr);
		return;
	}


	m_IsPlay[ROI_VID] = TRUE;

	GetDlgItem(IDC_ROIPLAYBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_ROISTOPBTN)->EnableWindow(TRUE);
	MemoryLeakCheck();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
} // when roi "play" button click



void CCrevisCamPracticeDlg::OnBnClickedRoistopbtn()
{
	m_IsPlay[ROI_VID] = FALSE;
	GetDlgItem(IDC_ROIPLAYBTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_ROISTOPBTN)->EnableWindow(FALSE);
	MemoryLeakCheck();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}// when roi "stop" button click


void CCrevisCamPracticeDlg::OnBnClickedBinplaybtn()
{
	CString CThreshold;

	m_TBThreshold.GetWindowTextW(CThreshold);
	m_Threshold = _ttoi(CThreshold);
	// Getting threshold value
	if (m_Threshold < 0 || m_Threshold > 255)
	{
		AfxMessageBox(TEXT("Please input a number between 0~255"));
		return;
	} // Threashold error value check

	m_IsPlay[BINARY_VID] = TRUE;

	GetDlgItem(IDC_BINPLAYBTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_BINSTOPBTN)->EnableWindow(TRUE);
	MemoryLeakCheck();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}// when binary "play" button click


void CCrevisCamPracticeDlg::OnBnClickedBinstopbtn()
{
	m_IsPlay[BINARY_VID] = FALSE;
	GetDlgItem(IDC_BINPLAYBTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_BINSTOPBTN)->EnableWindow(FALSE);
	MemoryLeakCheck();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}// when binary "play" button click


void CCrevisCamPracticeDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	INT32 status = MCAM_ERR_SUCCESS;
	CString strErr;
	
	if (m_hThread != NULL)
	{
		SetEvent(m_hTerminate);
		WaitForSingleObject(m_hTerminate, INFINITE);
		CloseHandle(m_hThread);
		m_hThread = NULL;
	}
	
	// cycles on m_hThreadArr and checks if any thread is being used, and terminates
	// sets interrupt, wait for thread to be halted then close handle & frees pointer.
	if (m_IsOpened == TRUE)
	{
		status = ST_AcqStop(m_hDevice);
		if (status != MCAM_ERR_SUCCESS)
		{
			strErr.Format(_T("Acquisition stop fail. code :%d"), status);
			AfxMessageBox(strErr, MB_OK | MB_ICONSTOP);
			return;
		}

		if (m_pImage != NULL)
		{
			free(m_pImage);
			m_pImage = NULL;
		}
		// image grab buffer free & nullification

		ST_CloseDevice(m_hDevice);
	}
	// camera close procedure

	ST_FreeSystem();
	MemoryLeakCheck();
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
} 

void CCrevisCamPracticeDlg::SetFeature()
{
	INT32 status = MCAM_ERR_SUCCESS;
	CString strErr;

	status = ST_SetEnumReg(m_hDevice, MCAM_TRIGGER_MODE, TRIGGER_MODE_OFF);
	if (status != MCAM_ERR_SUCCESS)
	{
		strErr.Format(_T("Write Register failed : %d"), status);
		AfxMessageBox(strErr, MB_OK | MB_ICONSTOP);
	}
	// Trigger mode off!
	MemoryLeakCheck();
}


void CCrevisCamPracticeDlg::ReceiveImage()
{
	INT32 status = MCAM_ERR_SUCCESS;
	
	while (WaitForSingleObject(m_hTerminate, 0) != WAIT_OBJECT_0)
	{
		status = ST_GrabImage(m_hDevice, m_pImage, m_BufferSize);
		// grabbing image from camera
		if (status == MCAM_ERR_SUCCESS)
		{
			for (int i = 0; i < TOTAL_DISP; i++)
			{
				if (m_IsPlay[i]){
					InvalidateRect(m_rcDisp[i], FALSE);
				}
			}
		}
		MemoryLeakCheck();
	}
	// grab image by and sends to display which has vidType id.

	
}
void CCrevisCamPracticeDlg::DrawImage(int vidType)
{
	if (!m_IsOpened)
	{
		return;
	}

	BitmapData bitmapdata;
	Rect rc(0, 0, m_Width, m_Height);
	Rect roirc(m_roiX, m_roiY, m_roiWidth, m_roiHeight); // rectangular for ROI section square on normal video
	Rect dispRc(0, 0, m_rcDisp[vidType].Width(), m_rcDisp[vidType].Height()); // 
	Pen pen(Color(255, 0, 255), 5);
	Graphics mDC(m_pBitmap);
	// if video is not ROI just change color of the video and streams

	m_pBitmap->LockBits(&rc, 0, PixelFormat8bppIndexed, &bitmapdata);
	memcpy(bitmapdata.Scan0, m_pImage, m_BufferSize);
	m_pBitmap->UnlockBits(&bitmapdata);
	ConvertPalette(vidType);
	switch (vidType)
	{
	case NORMAL_VID:
		if (m_IsPlay[ROI_VID])
		{
			mDC.DrawRectangle(&pen, roirc);
			// to prevent double buffering issue
			// draws on the bitmap that has video
		}
		m_pGraphics[vidType]->DrawImage(m_pBitmap, dispRc, 0, 0, dispRc.Width, dispRc.Height, UnitPixel);
		break;

	case ROI_VID:
		m_pGraphics[vidType]->DrawImage(m_pBitmap, dispRc, m_roiX, m_roiY, m_roiWidth, m_roiHeight, UnitPixel);
		break;

	case BINARY_VID:
		m_pGraphics[vidType]->DrawImage(m_pBitmap, dispRc, 0, 0, dispRc.Width, dispRc.Height, UnitPixel);
		break;
	}
	MemoryLeakCheck();
}

void CCrevisCamPracticeDlg::ConvertPalette(int vidType)
{
	int paletteSize = m_pBitmap->GetPaletteSize();
	ColorPalette* pPalette = new ColorPalette[paletteSize];
	m_pBitmap->GetPalette(pPalette, paletteSize);
	// gets palette info of bitmap image to set color info of the bitmap
	switch (vidType)
	{
	case NORMAL_VID:
	case ROI_VID:
		for (unsigned int i = 0; i < pPalette->Count; i++)
		{
			pPalette->Entries[i] = Color::MakeARGB(255, i, i, i);
		}
		m_pBitmap->SetPalette(pPalette);
		break;
	// Normal video || ROI video color set
	case BINARY_VID:
		for (unsigned int i = 0; i < pPalette->Count; i++)
		{
			if (i <= m_Threshold)
			{
				pPalette->Entries[i] = Color::MakeARGB(255, 0, 0, 0);
			}
			else
			{
				pPalette->Entries[i] = Color::MakeARGB(255, 255, 255, 255);
			}
		}
		m_pBitmap->SetPalette(pPalette);
		break;
		// Binary video color set
		// if color value is lower than threshold -> 0
		// if higher -> 255
	default:
		AfxMessageBox(TEXT("vidtype error : on converting palette!"));
		delete[] pPalette;
		return;
		break;
	}
	delete[] pPalette;
	MemoryLeakCheck();
}