/*
* 便利アクション
*/

#include <Harada/MyAction.h>

USING_NS_CC;

void MyAction::SetParticle(Vec2 pos)
{
	CCParticleSystemQuad* particle = CCParticleSystemQuad::create("Effects/ontouch.plist");
	particle->resetSystem();
	particle->setPosition(Vec2(pos));

	this->addChild(particle, 2);
}
