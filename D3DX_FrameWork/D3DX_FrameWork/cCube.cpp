#include "stdafx.h"
#include "cCube.h"


cCube::cCube()
	: m_fRotY(0.0f)
	, m_vPosition(0, 0, 0)
	, m_vDirection(0, 0, 1)
{
	D3DXMatrixIdentity(&matScale);
}


cCube::~cCube()
{
}

void cCube::Init()
{
	ST_PC_VERTEXT	v;

	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
}
void cCube::Update()
{
	if (GetKeyState('A') & 0x8000)
	{
		m_fRotY -= 0.1f;
	}
	if (GetKeyState('D') & 0x8000)
	{
		m_fRotY += 0.1f;
	}

	if (GetKeyState('W') & 0x8000)
	{
		m_vPosition = m_vPosition + (m_vDirection * 0.1f);
	}
	if (GetKeyState('S') & 0x8000)
	{
		m_vPosition = m_vPosition - (m_vDirection * 0.1f);
	}

	D3DXMatrixIdentity(&m_matWorld);

	D3DXMATRIX	matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);
	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);

	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);

	m_matWorld = matR * matT;
}
void cCube::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEXT::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEXT));
}