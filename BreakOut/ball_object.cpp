#include "ball_object.h"



BallObject::BallObject()
	: GameObject(), Radius(12.5f), Stuck(true) { }


BallObject::BallObject(glm::vec2 pos, GLfloat radius, glm::vec2 velocity, Texture2D sprite)
	: GameObject(pos, glm::vec2(radius * 2, radius * 2), sprite, glm::vec3(1.0f), velocity), Radius(radius), Stuck(true) { }

