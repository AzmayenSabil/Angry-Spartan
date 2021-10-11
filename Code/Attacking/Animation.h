#pragma once

#include <iostream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <math.h>

#include <SFML/system.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

using namespace std;
using namespace sf;

class Animation
{
public:
	Animation(float totalTime, float switchTime,
		IntRect currentFrameIdle, IntRect currentFrameWalking, IntRect currentFrameJumping, IntRect currentFrameAttacking,
		float walkingFrameStart, float walkingFrameEnd, float jumpingFrameStart, float jumpingFrameEnd,
		float attackingFrameStart, float attackingFrameEnd,
		Vector2f frameWidthAndHeight, Vector2f scale);

	~Animation();


	IntRect currentFrameWalking;
	IntRect currentFrameJumping;
	IntRect currentFrameIdle;
	IntRect currentFrameAttacking;
	IntRect currentLightAttackingFrame;
	IntRect currentHeavyAttackingFrame;
	IntRect currentFrameBlocking;


	float walkingFrameStart;
	float walkingFrameEnd;
	float jumpingFrameStart;
	float jumpingFrameEnd;
	float attackingFrameStart;
	float attackingFrameEnd;
	float lightAttackingFrameStart;
	float lightAttackingFrameEnd;
	float heavyAttackingFrameStart;
	float heavyAttackingFrameEnd;
	float blockingFrameStart;
	float blockingFrameEnd;

	Vector2f frameWidthAndHeight;
	Vector2f scale;

	void setLightAttackFrame(IntRect currentLightAttackingFrame, float lightAttackingFrameStart, float lightAttackingFrameEnd);
	void setHeavyAttackFrame(IntRect currentHeavyAttackingFrame, float heavyAttackingFrameStart, float heavyAttackingFrameEnd);
	void setBlockingFrame(IntRect currentBlockingFrame, float blockingFrameStart, float blockingFrameEnd);

	void idle(Sprite *sprite, bool isFacingLeft, float deltaTime);
	void walk(Sprite *sprite, bool isFacingLeft, float deltaTime);
	void attack(Sprite *sprite, bool isFacingLeft, float deltaTime);
	void heavyAttack(Sprite *sprite, bool isFacingLeft, float deltaTime);
	void lightAttack(Sprite *sprite, bool isFacingLeft, float deltaTime);
	void block(Sprite *sprite, bool isFacingLeft, float deltaTime);
	void jump(Sprite *sprite, bool isFacingLeft, float deltaTime);
	void die(Sprite *sprite, bool isFacingLeft, float deltaTime);

private:

	float totalTime;
	float switchTime;
};

