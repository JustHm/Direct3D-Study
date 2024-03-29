#include "stdafx.h"
#include "cCamera.h"


cCamera::cCamera()
	: m_vEye(0, 15, -20)
	, m_vLookAt(0, 0, 0)
	, m_vUp(0, 1, 0)
	, m_fCameraDistance(0,0,0)
	, m_isLButtonDown(false)
	, m_vCamRotAngle(0, 0, 0)
{
	m_ptPrevMouse.x = 0;
	m_ptPrevMouse.y = 0;
	Init();
}


cCamera::~cCamera()
{
}

void cCamera::Init()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIX matProj;
	D3DXMatrixPerspectiveFovLH(&matProj,
		D3DX_PI / 4.0f,
		rc.right / (float)rc.bottom,
		1.0f,
		1000.0f);
	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}
void cCamera::Update()
{
	D3DXMATRIX matR, matRX, matRY;
	D3DXMATRIX matT, matTT;

	D3DXMatrixTranslation(&matT, m_fCameraDistance.x, m_fCameraDistance.y, m_fCameraDistance.z);
	D3DXMatrixRotationX(&matRX, m_vCamRotAngle.x);
	D3DXMatrixRotationY(&matRY, m_vCamRotAngle.y);
	matR = matRX*matRY * matT;

	m_vLookAt = D3DXVECTOR3(m_fCameraDistance.x, m_fCameraDistance.y, m_fCameraDistance.z);
	m_vEye = D3DXVECTOR3(0, 8,-15);
	D3DXVec3TransformCoord(&m_vEye, &m_vEye, &matR);

	D3DXMATRIX matView;
	D3DXMatrixLookAtLH(&matView, &m_vEye, &m_vLookAt, &m_vUp);
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);
}

void cCamera::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_RBUTTONDOWN:
		m_isLButtonDown = false;	
		break;
	case WM_LBUTTONDOWN:
		m_ptPrevMouse.x = LOWORD(lParam);
		m_ptPrevMouse.y = HIWORD(lParam);
		m_isLButtonDown = true;
		break;
	case WM_MOUSEMOVE:
		if (m_isLButtonDown)
		{
			POINT ptCurrMouse;
			ptCurrMouse.x = LOWORD(lParam);
			ptCurrMouse.y = HIWORD(lParam);
			float fDeltaX = (float)ptCurrMouse.x - m_ptPrevMouse.x;
			float fDeltaY = (float)ptCurrMouse.y - m_ptPrevMouse.y;
			m_vCamRotAngle.y += (fDeltaX / 100.f);
			m_vCamRotAngle.x += (fDeltaY / 100.f);
			if (m_vCamRotAngle.x < -D3DX_PI / 2.0f + 0.001f)
				m_vCamRotAngle.x = -D3DX_PI / 2.0f + 0.001f;
			if (m_vCamRotAngle.x > D3DX_PI / 2.0f - 0.001f)
				m_vCamRotAngle.x = D3DX_PI / 2.0f - 0.001f;
			m_ptPrevMouse = ptCurrMouse;
		}
		break;

	case WM_MOUSEWHEEL:
	/*	m_fCameraDistance -= (GET_WHEEL_DELTA_WPARAM(wParam) / 30.f);
		if (m_fCameraDistance < 0.0001f)
			m_fCameraDistance = 0.0001f;*/
		break;
	}
}

void cCamera::Release()
{
}
