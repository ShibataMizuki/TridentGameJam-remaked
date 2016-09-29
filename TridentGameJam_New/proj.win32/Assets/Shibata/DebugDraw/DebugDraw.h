#pragma once

#include<cocos2d.h>
#include"../CollisionSystem/CSworld/CSWorld.h"
#include"../CollisionSystem/CSShape/AABB/AABB.h"

class DebugDraw
{
	/*==============================
	シングルトン
	===============================*/
private:
	static DebugDraw* m_pInstance;

	//! コンストラクタ制限
	DebugDraw() = default;
	~DebugDraw() = default;
	DebugDraw(DebugDraw&) = delete;
	DebugDraw(DebugDraw&&) = delete;
	DebugDraw& operator+(const DebugDraw&) = delete;

public:
	//! @brief インスタンスを取得
	//! @return インスタンス
	static DebugDraw* getInstance();

	//! @brief インスタンスを解放
	void release();

private:
	//! 描画対象のノード
	cocos2d::Node* m_pTargetNode;
	//! 描画ノード
	cocos2d::DrawNode* m_drawNode;

public:
	//! @brief ノードを初期化
	void initialize(cocos2d::Node* pTargetNode);

	//! @brief 描画ノード取得
	cocos2d::DrawNode* getDrawNode()const;

};
