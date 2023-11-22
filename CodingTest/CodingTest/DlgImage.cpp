﻿// DlgImage.cpp: 구현 파일
//

#include "pch.h"
#include "CodingTest.h"
#include "afxdialogex.h"
#include "DlgImage.h"
#include "CodingTestDlg.h"
#include <iostream>

// CDlgImage 대화 상자

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DlgImage, pParent)
{
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	InitImage();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	if (m_image)
		m_image.Draw(dc, 0, 0);

	drawData(&dc);
}

void CDlgImage::InitImage()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);

	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbBlue = rgb[i].rgbGreen = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, BACK_COLOR, nWidth * nHeight);
}

void CDlgImage::drawData(CDC* pDC)
{
	int size = pointArray.GetSize();
	CRect rect;

	for (int i = 0; i < size; i++) {
		CPoint point = pointArray.GetAt(i);
		rect.SetRect(point, point);
		rect.InflateRect(1, 1);

		pDC->FillRect(rect, &CBrush(IsBorderColor(m_nSelColor)));
	}
}

// 도형에 따라 색 지정
COLORREF CDlgImage::IsBorderColor(int m_nSelColor)
{
	switch (m_nSelColor) {
	case 0:
		return COLOR_YELLOW;	// Circle
	case 1:
		return COLOR_RED;		// Triangle
	case 2:
		return COLOR_GREEN;		// Square
	default:
		return COLOR_BLUE;		// Star
	}
}