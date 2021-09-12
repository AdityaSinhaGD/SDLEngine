#pragma once
class Animation
{
public:
	unsigned int index;
	unsigned int numberOfFrames;
	unsigned int animationSpeed;
	Animation();
	Animation(unsigned int index, unsigned int numberOfFrames, unsigned int animationSpeed);
};

