
// CodingTestDlg.h: 헤더 파일
//
#include "DlgImage.h"

#pragma once


// CCodingTestDlg 대화 상자
class CCodingTestDlg : public CDialogEx
{
// 생성입니다.
public:
	CCodingTestDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CDlgImage* m_pDlgImage;
	int m_nSelFigure = 0;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CODINGTEST_DIALOG };
#endif

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
	CEdit IDD_INPUT_RADIUS;
	void SetDlgImage();

	void DrawFigure(int nRadius);
	void CheckInputStr();

	void SetBorderPoint(int nCenterX, int nCenterY, int nRadius, int nSelFigure, int nPitch);

	bool IsBorderPoint(int x, int y, int centerX, int centerY, int radius, int selFigure);
	bool isCircleBorder(int i, int j, int nCenterX, int nCenterY, int nRadius);
	bool isTriangleBorder(int i, int j, int nCenterX, int nCenterY, int nRadius);
	bool isSquareBorder(int i, int j, int nCenterX, int nCenterY, int nRadius);
	bool isStarBorder(int i, int j, int nCenterX, int nCenterY, int nRadius);

	bool isCrossLine(int i, int j, int nCenterX, int nCenterY, int nRadius);

	void GetData(int selFigure);
	CString IsFigure(int nSelFigure);

	double isMinDistance(double dCenterX, double dCenterY);
	double isMaxDistance(double dCenterX, double dCenterY);

	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnDrawCircle();
	afx_msg void OnBnClickedBtnDrawTriangle();
	afx_msg void OnBnClickedBtnDrawSquare();
	afx_msg void OnBnClickedBtnDrawStar();
};
