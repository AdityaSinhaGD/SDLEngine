#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(unsigned int index, unsigned int numberOfFrames, unsigned int animationSpeed)
{
	this->index = index;
	this->numberOfFrames = numberOfFrames;
	this->animationSpeed = animationSpeed;
}
