#pragma once

#include"../../CSVec2/CSVec2.h"

//! @brief AABBクラス
class AABB
{
	/*==============================
	中心座標
	===============================*/
private:
	CSVec2 m_centerPos;
	CSVec2 m_centerPosOrigin;
public:
	//! @brief 中心座標の取得
	//! @return 中心座標
	const CSVec2& getCenterPosition()const;
	
	//! @brief 中心座標の設定
	//! @param centerPos 中心座標
	void setCenterPosition(const CSVec2& centerPos);

	//! @brief もともとの中心座標を取得する
	const CSVec2& getCenterPositionOrigin()const;

	/*==============================
	幅,高さ
	===============================*/
private:
	float m_width;
	float m_height;
public:
	//! @brief 幅の取得
	//! @return 幅
	float getWidth()const;

	//! @brief 高さの取得
	//! @return 高さ
	float getHeight()const;

	//! @brief 幅の設定
	//! @param width 幅
	void setWidth(float width);

	//! @brief 高さの設定
	//! @param height 高さ
	void setHeight(float height);

	/*==============================
	最小座標,最大座標
	===============================*/
private:
	CSVec2 m_upper;
	CSVec2 m_lower;
public:
	//! @brief 最大座標の取得
	//! @return 最大座標
	const CSVec2& getUpper()const;

	//! @brief 最小座標の取得
	//! @return 最小座標
	const CSVec2& getLower()const;

	/*==============================
	コンストラクタ,デストラクタ
	===============================*/
public:
	AABB() = default;

	//! @param centerPos 中心座標
	//! @param width 幅
	//! @param height 高さ
	AABB(const CSVec2& centerPos, float width, float height);

	//! @param lower 最小座標
	//! @param upper 最大座標
	AABB(const CSVec2& lower, const CSVec2& upper);

	~AABB() = default;

	/*==============================
	その他関数
	===============================*/
public:
	//! @brief AABBとAABBの接触判定
	//! @param aabb AABB
	bool isIntersect(const AABB& aabb)const;

	void dump()const;
};