#ifndef GAME_H
#define GAME_H

#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <vector>
#include "game_level.h"
#include "ball_object.h"
#include <tuple>


// Represents the current state of the game
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};
// Direction
enum Direction {
	UP,
	RIGHT,
	DOWN,
	LEFT
};

typedef std::tuple<GLboolean, Direction, glm::vec2> Collision;

class Game
{
public:
	//Game state
	GameState	State;
	GLboolean	Keys[1024];
	GLuint		Width, Height;
	std::vector<GameLevel> Levels;
	GLuint                 Level;
	// Constructor/Destructor
	Game(GLuint width, GLuint height);
	~Game();
	// Initialize game state (load all shaders/textures/levels)
	void Init();
	// GameLoop
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();
	//collision detection
	void DoCollisions();
	Collision CheckCollision(GameObject &one, GameObject &two);
	Collision CheckCollision(BallObject &one, GameObject &two);
	Direction VectorDirection(glm::vec2 target);
	//
	void ResetPlayer();
	void ResetLevel();
};

#endif