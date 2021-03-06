/*
ゲームオブジェクトの定義
*/

#pragma once

#include<cocos2d.h>
#include"../CollisionSystem/CollisionSystem.h"

enum class ObjectGroup
{
	AllyCharacter,
	EnemyCharacter,
	AllyBullet,
	EnemyBullet,
	DropItem,
};

//! @brief ゲームに出現するオブジェクトの基底
class GameObject :public cocos2d::Node
{
	/*==============================
	cocos2d-x
	===============================*/
public:
	//! @brief 初期化処理
	virtual bool init();

	/*==============================
	当たり判定用
	===============================*/
protected:
	//! ボディ
	std::shared_ptr<CSBody> m_pBody;
public:
	//! @brief ボディを設定
	void setBody(const std::shared_ptr<CSBody>& pBody);
	//! @brief ボディを取得
	const std::shared_ptr<CSBody>& getBody()const;
	//! @brief ボディを追従させる
	void syncBody();

	/*==============================
	スプライトアニメーションの管理
	===============================*/
protected:
	//! スプライト
	cocos2d::Sprite* m_pSprite;
public:
	//! @brief スプライトを取得
	cocos2d::Sprite* getSprite()const;

	//! @brief アニメーションを実行
	//! @param 実行するアニメーション
	void runAnimation(cocos2d::Animation* pAnimation);
	

	/*==============================
	コンストラクタ/デストラクタ
	===============================*/
public:
	virtual ~GameObject() = default;
};