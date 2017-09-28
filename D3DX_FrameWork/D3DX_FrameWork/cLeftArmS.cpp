#include "stdafx.h"
#include "cLeftArmS.h"


cLeftArmS::cLeftArmS()
{
}


cLeftArmS::~cLeftArmS()
{
}

void cLeftArmS::Init()
{
	cCubeMake::Init();
	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.4f, 0.6f, 0.4f);
	D3DXMatrixTranslation(&matT, -1.2f, -0.6f, 0.0f);

	matWorld = matS * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
}
