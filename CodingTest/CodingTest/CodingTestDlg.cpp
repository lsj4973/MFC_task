
// CodingTestDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "CodingTest.h"
#include "CodingTestDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

using namespace std;
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCodingTestDlg 대화 상자



CCodingTestDlg::CCodingTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CODINGTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCodingTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INPUT_RADIUS, IDD_INPUT_RADIUS);
}

BEGIN_MESSAGE_MAP(CCodingTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_DRAW_CIRCLE, &CCodingTestDlg::OnBnClickedBtnDrawCircle)
	ON_BN_CLICKED(IDC_BTN_DRAW_TRIANGLE, &CCodingTestDlg::OnBnClickedBtnDrawTriangle)
	ON_BN_CLICKED(IDC_BTN_DRAW_SQUARE, &CCodingTestDlg::OnBnClickedBtnDrawSquare)
	ON_BN_CLICKED(IDC_BTN_DRAW_STAR, &CCodingTestDlg::OnBnClickedBtnDrawStar)
END_MESSAGE_MAP()


// CCodingTestDlg 메시지 처리기

BOOL CCodingTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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
	inItImage();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CCodingTestDlg::inItImage()
{
	// DeskTop
	MoveWindow(0, 0, 655, 600);
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_DlgImage, this);
	m_pDlgImage->ShowWindow(SW_SHOW);
	m_pDlgImage->MoveWindow(0, 50, 640, 480);

	// LapTop
	//MoveWindow(0, 0, 700, 800);
	//m_pDlgImage = new CDlgImage;
	//m_pDlgImage->Create(IDD_DlgImage, this);
	//m_pDlgImage->ShowWindow(SW_SHOW);
	//m_pDlgImage->MoveWindow(20, 50, 640, 480);
}

void CCodingTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCodingTestDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCodingTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCodingTestDlg::OnBnClickedBtnDrawCircle()
{
	m_nSelFigure = 0;

	CheckInputStr();
}

void CCodingTestDlg::OnBnClickedBtnDrawTriangle()
{
	m_nSelFigure = 1;

	CheckInputStr();
}


void CCodingTestDlg::OnBnClickedBtnDrawSquare()
{
	m_nSelFigure = 2;

	CheckInputStr();
}

void CCodingTestDlg::OnBnClickedBtnDrawStar()
{
	m_nSelFigure = 3;

	CheckInputStr();
}

void CCodingTestDlg::CheckInputStr()
{
	int nHeight = m_pDlgImage->m_image.GetHeight();
	CString str;
	IDD_INPUT_RADIUS.GetWindowTextW(str);
	int nRadius = _ttoi(str);
	if (nRadius != 0 || str.Compare(_T("0")) == 0) {
		nRadius = nRadius;
		if (nRadius > nHeight / 2 - 10 || nRadius <= 0) {
			AfxMessageBox(_T("Number Out Of Range!!"));
			IDD_INPUT_RADIUS.SetWindowTextW(_T(""));
		}
		else {
			DrawFigure(nRadius);
			GetData();
		}
	}
	else {
		AfxMessageBox(_T("Please Input Number"));
		IDD_INPUT_RADIUS.SetWindowTextW(_T(""));
	}
}

void CCodingTestDlg::DrawFigure(int nRadius)
{
	m_pDlgImage->pointArray.RemoveAll();	// 배열 초기화
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	memset(fm, BACK_COLOR, nWidth * nHeight);

	int nCenterX = rand() % (nWidth - nRadius * 2) + nRadius;
	int nCenterY = rand() % (nHeight - nRadius * 2) + nRadius;

	m_pDlgImage->m_nSelColor = m_nSelFigure;

	// 원 테두리 좌표 배열에 저장
	SetBorderPoint(nCenterX, nCenterY, nRadius, nPitch);

	int nGray = 100;
	// 십자선 그리기
	for (int j = nCenterY - nRadius; j <= nCenterY + nRadius; j++) {
		for (int i = nCenterX - nRadius; i <= nCenterX + nRadius; i++) {
			if (isCrossLine(i, j, nCenterX, nCenterY, nRadius)) {
				fm[nPitch * j + i] = nGray;
			}
		}
	}

	m_pDlgImage->Invalidate();
}

void CCodingTestDlg::SetBorderPoint(int nCenterX, int nCenterY, int nRadius, int nPitch)
{
	int nBlack = 0;
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	for (int j = nCenterY - nRadius; j <= nCenterY + nRadius; j++) {
		for (int i = nCenterX - nRadius; i <= nCenterX + nRadius; i++) {
			if (IsBorderPoint(i, j, nCenterX, nCenterY, nRadius)) {
				fm[nPitch * j + i] = nBlack;
				m_pDlgImage->pointArray.Add(CPoint(i, j));
			}
		}
	}
}

bool CCodingTestDlg::IsBorderPoint(int x, int y, int centerX, int centerY, int radius)
{
	switch (m_nSelFigure) {
	case 0:
		return isCircleBorder(x, y, centerX, centerY, radius);
	case 1:
		return isTriangleBorder(x, y, centerX, centerY, radius);
	case 2:
		return isSquareBorder(x, y, centerX, centerY, radius);
	case 3:
		return isStarBorder(x, y, centerX, centerY, radius);
	default:
		return false;
	}
}



bool CCodingTestDlg::isCircleBorder(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;
	// 원 테두리 두께 설정
	int nThick = 2;

	if (dDist <= nRadius * nRadius && dDist >= (nRadius - nThick) * (nRadius - nThick)) {
		bRet = true;
	}

	return bRet;
}

bool CCodingTestDlg::isTriangleBorder(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false; 

	// 삼각형 테두리 두께 설정
	int nThick = 1;

	if (4 * (nCenterX - i) * (nCenterX - i) <= 3 * nRadius * nRadius && nCenterY == j - (nRadius/2)) {
		bRet = true;
	}
	else if (4 * (nCenterX - i) * (nCenterX - i) <= 3 * (nRadius - nThick) * (nRadius - nThick) && nCenterY == j - ((nRadius - nThick)/2)) {
		bRet = true;
	}
	else if (4 * (nCenterX - i) * (nCenterX - i) <= 3 * nRadius * nRadius && (nCenterY - j - nRadius) * (nCenterY - j - nRadius) >= 3 * (nCenterX - i) * (nCenterX - i)) {
		if (4 * (nCenterX - i) * (nCenterX - i) <= 3 * (nRadius - nThick) * (nRadius - nThick) && (nCenterY - j - (nRadius - nThick)) * (nCenterY - j - (nRadius - nThick)) <= 3 * (nCenterX - i) * (nCenterX - i)) {
			bRet = true;
		}
	}
	return bRet;
}

bool CCodingTestDlg::isSquareBorder(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;

	// 사각형 테두리 두께 설정
	int nThick = 1;

	if((nCenterX - i) >= -nRadius && (nCenterX - i) <= -(nRadius-nThick))
		bRet = true;
	else if((nCenterX - i) <= nRadius && (nCenterX - i) >= (nRadius - nThick))
		bRet = true;
	else if((nCenterY - j) >= -nRadius && (nCenterY - j) <= -(nRadius - nThick))
		bRet = true;
	else if ((nCenterY - j) <= nRadius && (nCenterY - j) >= (nRadius - nThick))
		bRet = true;

	return bRet;
}

bool CCodingTestDlg::isStarBorder(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;

	// 별 테두리 두께 설정
	int nThick = 1;

	if (4 * (nCenterX - i) * (nCenterX - i) <= 3 * nRadius * nRadius && nCenterY == j - (nRadius / 2)) {
		bRet = true;
	}
	else if (4 * (nCenterX - i) * (nCenterX - i) <= 3 * (nRadius - nThick) * (nRadius - nThick) && nCenterY == j - ((nRadius - nThick) / 2)) {
		bRet = true;
	}
	else if (4 * (nCenterX - i) * (nCenterX - i) <= 3 * nRadius * nRadius && (nCenterY - j - nRadius) * (nCenterY - j - nRadius) >= 3 * (nCenterX - i) * (nCenterX - i)) {
		if (4 * (nCenterX - i) * (nCenterX - i) <= 3 * (nRadius - nThick) * (nRadius - nThick) && (nCenterY - j - (nRadius - nThick)) * (nCenterY - j - (nRadius - nThick)) <= 3 * (nCenterX - i) * (nCenterX - i)) {
			bRet = true;
		}
	}
	if (4 * (i - nCenterX) * (i - nCenterX) <= 3 * nRadius * nRadius && j == nCenterY - (nRadius / 2)) {
		bRet = true;
	}
	else if (4 * (i - nCenterX) * (i - nCenterX) <= 3 * (nRadius - nThick) * (nRadius - nThick) && j == nCenterY - ((nRadius - nThick) / 2)) {
		bRet = true;
	}
	else if (4 * (i - nCenterX) * (i - nCenterX) <= 3 * nRadius * nRadius && (j - nCenterY - nRadius) * (j - nCenterY - nRadius) >= 3 * (i - nCenterX) * (i - nCenterX)) {
		if (4 * (i - nCenterX) * (i - nCenterX) <= 3 * (nRadius - nThick) * (nRadius - nThick) && (j - nCenterY - (nRadius - nThick)) * (j - nCenterY - (nRadius - nThick)) <= 3 * (i - nCenterX) * (i - nCenterX)) {
			bRet = true;
		}
	}
	return bRet;
}

bool CCodingTestDlg::isCrossLine(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nCrossLength = nRadius / 10;	// 십자선 길이 설정
	// 좌표가 전체 영역 범위를 넘어갔을 때 false
	if (i < 0 || i >= nWidth) {
		bRet = false;
	}
	else if (j < 0 || j>= nHeight) {
		bRet = false;
	}
	// 십자선 영역에 있을 때 true
	else if (i == nCenterX && j <= nCenterY + nCrossLength && j >= nCenterY - nCrossLength) {
		bRet = true;
	}
	else if (j == nCenterY && i <= nCenterX + nCrossLength && i >= nCenterX - nCrossLength) {
		bRet = true;
	}

	return bRet;
}

void CCodingTestDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (m_pDlgImage)	delete m_pDlgImage;
}

// 무게 중심 구하기
void CCodingTestDlg::GetData()
{
	CString Figure = IsFigure();;
	static int nTimes = 1;
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();

	CRect rect(0, 0, nWidth, nHeight);
	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;
	int nGray = 100;
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j * nPitch + i] != BACK_COLOR && fm[j * nPitch + i] != nGray) {
				nSumX += i;
				nSumY += j;
				nCount++;
			}
		}
	}

	double dCenterX = (double)nSumX / nCount;
	double dCenterY = (double)nSumY / nCount;

	double dMinDistance = isMinDistance(dCenterX, dCenterY);
	double dMaxDistance = isMaxDistance(dCenterX, dCenterY);

	cout << "#" << nTimes << "  ";
	wprintf(L"%s\n\n", (LPCTSTR)Figure);
	cout << "무게중심 : (" << dCenterX << ", " << dCenterY << ")" << endl;
	cout << "최소거리 : " << dMinDistance << endl;
	cout << "최대거리 : " << dMaxDistance << endl;
	cout << "======================================================" << endl;
	nTimes++;
}

CString CCodingTestDlg::IsFigure()
{
	CString str;
	switch (m_nSelFigure) {
	case 0:
		str = "Circle";
		break;
	case 1:
		str = "Triangle";
		break;
	case 2:
		str = "Square";
		break;
	case 3:
		str = "Star";
		break;
	default:
		str = "Error";
		break;
	}
	return str;
}

double CCodingTestDlg::isMinDistance(double dCenterX, double dCenterY)
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();

	CRect rect(0, 0, nWidth, nHeight);
	int nGray = 100;
	double dMinDis = (double)nWidth;
	double dTempDis;
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j * nPitch + i] != BACK_COLOR && fm[j * nPitch + i] != nGray) {
				dTempDis = sqrt((i - dCenterX) * (i - dCenterX) + (j - dCenterY) * (j - dCenterY));
				if (dTempDis <= dMinDis) {
					dMinDis = dTempDis;
				}
			}
		}
	}
	return dMinDis;
}

double CCodingTestDlg::isMaxDistance(double dCenterX, double dCenterY)
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();

	CRect rect(0, 0, nWidth, nHeight);
	int nGray = 100;
	double dMaxDis = 0.0;
	double dTempDis;
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j * nPitch + i] != BACK_COLOR && fm[j * nPitch + i] != nGray) {
				dTempDis = sqrt((i - dCenterX) * (i - dCenterX) + (j - dCenterY) * (j - dCenterY));
				if (dTempDis >= dMaxDis) {
					dMaxDis = dTempDis;
				}
			}
		}
	}
	return dMaxDis;
}