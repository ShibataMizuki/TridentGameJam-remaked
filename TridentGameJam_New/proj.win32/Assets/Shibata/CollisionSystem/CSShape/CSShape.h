#pragma once

#include"../CSVec2/CSVec2.h"
#include"AABB/AABB.h"

class CSShape
{
protected:
	//! 座標
	CSVec2 m_position;
	//! AABB
	AABB m_aabb;

public:
	/*==============================
	コンストラクタ・デストラクタ
	===============================*/
	CSShape() = default;
	CSShape(const CSVec2& pos);
	virtual ~CSShape() = default;

	/*==============================
	座標の管理
	===============================*/
	//! 座標を設定
	void setPosition(const CSVec2& pos);
	//! 座標を取得
	const CSVec2& getPosition()const;

	//! @brief 図形を内包するAABBを取得
	//! @return AABB
	const AABB& getAABB()const;
};