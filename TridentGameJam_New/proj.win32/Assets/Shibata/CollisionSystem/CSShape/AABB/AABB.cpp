#include "AABB.h"
#include<iostream>
using namespace std;

const CSVec2 & AABB::getCenterPosition() const
{
	return m_centerPos;	
}

void AABB::setCenterPosition(const CSVec2 & centerPos)
{
	m_centerPos = centerPos;
	m_lower.x = centerPos.x - m_width / 2.f;
	m_lower.y = centerPos.y - m_height / 2.f;
	m_upper.x = centerPos.x + m_width / 2.f;
	m_upper.y = centerPos.y + m_height / 2.f;
}

const CSVec2 & AABB::getCenterPositionOrigin() const
{
	return m_centerPosOrigin;
}

float AABB::getWidth() const
{
	return m_width;
}

float AABB::getHeight() const
{
	return m_height;
}

void AABB::setWidth(float width)
{
	m_width = width;
}

void AABB::setHeight(float height)
{
	m_height = height;
}

const CSVec2 & AABB::getUpper() const
{
	return m_upper;
}

const CSVec2 & AABB::getLower() const
{
	return m_lower;
}


AABB::AABB(const CSVec2 & centerPos, float width, float height) :
	m_centerPos(centerPos),m_centerPosOrigin(centerPos),
	m_width(width), m_height(height)
{
	m_upper.x = centerPos.x + width / 2.f;
	m_upper.y = centerPos.y + height / 2.f;
	m_lower.x = centerPos.x - width / 2.f;
	m_lower.y = centerPos.y - height / 2.f;
}

AABB::AABB(const CSVec2 & lower, const CSVec2 & upper) :
	m_lower(lower), m_upper(upper)
{
	m_centerPos = (lower + upper) / 2.f;
	m_centerPosOrigin = m_centerPos;
	m_width = upper.x - lower.x;
	m_height = upper.y - lower.y;
}

bool AABB::isIntersect(const AABB & aabb) const
{
	return this->m_upper.x > aabb.m_lower.x&&
		this->m_lower.x<aabb.m_upper.x&&
		this->m_upper.y>aabb.m_lower.y&&
		this->m_lower.y < aabb.m_upper.y;
}

void AABB::dump() const
{
	cout << "[Center]" << m_centerPos.dump() << endl;
	cout << "[Upper]" << m_upper.dump() << endl;
	cout << "[Lower]" << m_lower.dump() << endl;
}
