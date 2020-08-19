
// CrevisCamPracticeDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"

#define NORMAL_VID 0
#define BINARY_VID 1
#define ROI_VID 2
#define TOTAL_DISP 3

// CCrevisCamPracticeDlg 대화 상자
class CCrevisCamPracticeDlg : public CDialogEx
{
// 생성입니다.
public:
	CCrevisCamPracticeDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CREVISCAMPRACTICE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton1();
	afx_msg void OnBnClickedOpenbtn();
	afx_msg void OnBnClickedClosebtn();
	afx_msg void OnBnClickedNorplaybtn();
	afx_msg void OnBnClickedNorstopbtn();
	afx_msg void OnBnClickedRoiplaybtn();
	afx_msg void OnBnClickedRoistopbtn();
	afx_msg void OnBnClickedBinplaybtn();
	afx_msg void OnBnClickedBinstopbtn();
	afx_msg void OnDestroy();

public:
	void SetFeature();
	void ReceiveImage();
	void ConvertPalette(int vidType);
	void DrawImage(int vidType);
	void MemoryLeakCheck();

private:
	INT32		m_hDevice; // Device 핸들
	INT32		m_Width; 
	INT32		m_Height; // 영상 높이 폭
	INT32		m_BufferSize; // 이미지 버퍼사이즈
	INT32		m_deviceEnum; // Device enum id 저장용
	void*		m_pImage; // 이미지 버퍼 포인터
	BOOL		m_IsOpened; // 카메라 오픈여부 bool flag
	BOOL		m_IsPlay[TOTAL_DISP]; // 활성화된 스크린용 bool flag
	UINT32		m_Threshold; // 이진화 영상 threshold값
	INT32		m_roiX;
	INT32		m_roiY;
	INT32		m_roiWidth;
	INT32		m_roiHeight;
	// for videos

	CRect		m_rcDisp[TOTAL_DISP]; // 각 디스플레이용 Crect
	HDC			m_hDC[TOTAL_DISP]; // 각 디스플레이용 핸들
	Bitmap*		m_pBitmap; 
	Graphics*	m_pGraphics[TOTAL_DISP]; 
	// GDI+

	HANDLE		m_hThread;
	HANDLE		m_hTerminate;
	
public:
	// Getting user input to find devcie wtih IP address
	CIPAddressCtrl m_DeviceIPControl;
	// User input of Threshold value for binary video
	CEdit m_TBThreshold;
	// Roi video X coord
	CEdit m_TBRoiX;
	// Roi Y coord
	CEdit m_TBRoiY;
	// Roi Width
	CEdit m_TBWidth;
	// Roi Height
	CEdit m_TBRoiHeight;
	afx_msg void OnStnClickedNorDisp();
};
