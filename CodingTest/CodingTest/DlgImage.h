#pragma once
#include "afxdialogex.h"
#include <afx.h>

// CDlgImage 대화 상자

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgImage();
	CImage m_image;
	CArray<CPoint, CPoint&> pointArray;
	int m_nSelColor = 0;
	CPoint CenterPoint;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DlgImage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	void InitImage();
	void drawData(CDC* pDC);
	void drawCenter(CDC* pDC);
	COLORREF IsBorderColor(int m_nSelColor);
};
