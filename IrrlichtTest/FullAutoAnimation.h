#pragma once

#include "Animation.h"

class FullAutoAnimation : public Animation
{
public:

	FullAutoAnimation(irr::u32 time) : Animation()
	{
		shotTime = time;
	}

	virtual void animateNode(irr::scene::ISceneNode * node, irr::u32 timeMs)
	{
		if (firstUpdate)
		{
			firstUpdate = false;
			node->setRotation(irr::core::vector3df(0.0f, 0.0f, 0.0f));
		}

		if (!startTime)
			startTime = timeMs;

		node->setPosition(irr::core::vector3df(-0.2f - 0.2f * (irr::f32)sin(M_PI * (double)(timeMs - startTime) / (double)shotTime), 0.4f, -0.4f));
	}

	virtual ISceneNodeAnimator * createClone(irr::scene::ISceneNode *node, irr::scene::ISceneManager *newManager = 0)
	{
		return new FullAutoAnimation(shotTime);
	}

private:

	irr::u32 shotTime;
};