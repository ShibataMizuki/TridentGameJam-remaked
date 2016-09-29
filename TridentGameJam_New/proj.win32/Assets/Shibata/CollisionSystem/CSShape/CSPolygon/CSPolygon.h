#pragma once

#include"../CSShape.h"
#include<vector>

class CSPolygon :public CSShape
{
protected:
	//! ���_���X�g
	std::vector<CSVec2> m_vertexes;

public:
	/*==============================
	�R���X�g���N�^
	===============================*/
	CSPolygon();
	CSPolygon(const std::vector<CSVec2>& vertexes);
};