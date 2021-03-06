#pragma once

#include"../CSShape.h"
#include<memory>

class CSCircle :public CSShape
{
protected:
	//! ~Ì¼a
	float m_radius;

public:
	/*==============================
	RXgN^
	===============================*/
	CSCircle();
	CSCircle(float radius);
	CSCircle(const CSVec2& pos, float radius);

	/*==============================
	~Ì¼aÌÇ
	===============================*/
	void setRadius(float radius);
	float getRadius()const;

	/*==============================
	shared_ptr¶¬
	===============================*/
	static std::shared_ptr<CSCircle> createShared();
	static std::shared_ptr<CSCircle> createShared(float radius);
	static std::shared_ptr<CSCircle> createShared(const CSVec2& pos, float radius);
};