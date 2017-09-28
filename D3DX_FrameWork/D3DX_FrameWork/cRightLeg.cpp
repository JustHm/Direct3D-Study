#include "stdafx.h"
#include "cRightLeg.h"


cRightLeg::cRightLeg()
	: angleY(0.0f)
	, angleMax(0.3f)
	, angleMin(-0.3f)
	, angleRe(true)
{
}


cRightLeg::~cRightLeg()
{
}


void cRightLeg::Init()
{
	cCubeMake::Init();

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.4f, 0.6f, 0.4f);
	D3DXMatrixTranslation(&matT, 0.4f, -1.8f, 0.0f);
	D3DXMatrixIdentity(&matWorld);
	matWorld = matS * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
}

void cRightLeg::MoveMotion()
{
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matMoveT);

	if (angleY >= angleMax)
	{
		angleRe = false;
	}
	else if (angleY <= angleMin)
	{
		angleRe = true;
	}

	if (angleRe) angleY += 0.02f;
	else angleY -= 0.02f;
	D3DXMatrixTranslation(&matMoveT, 0, -0.6, 0);
	D3DXMatrixTranslation(&matOriginT, 0, 0.6, 0);
	D3DXMatrixRotationX(&matR, angleY);
}
