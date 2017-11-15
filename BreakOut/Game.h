#ifndef GAME_H
#define GAME_H

#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <vector>
#include "game_level.h"
#include "ball_object.h"
#include <tuple>
#include "powerup.h"
#include <algorithm>
#include <sstream>


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

// Initial size of the player paddle
const glm::vec2 PLAYER_SIZE(100, 20);
// Initial velocity of the player paddle
const GLfloat PLAYER_VELOCITY(500.0f);
// Initial velocity of the Ball
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
// Radius of the ball object
const GLfloat BALL_RADIUS = 12.5f;

class Game
{
public:
	//Game state
	GameState				State;
	GLboolean				Keys[1024];
	GLboolean				KeysProcessed[1024];
	GLuint					Width, Height;
	std::vector<GameLevel>  Levels;
	GLuint                  Level;
	GLuint					Lives;
	std::vector<PowerUp>	PowerUps;
	// Constructor/Destructor
	Game(GLuint width, GLuint height);
	~Game();
	// Initialize game state (load all shaders/textures/levels)
	void Init();
	// GameLoop
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();
	void DoCollisions();
	//Reset
	void ResetPlayer();
	void ResetLevel();
	//powerup fc
	void SpawnPowerUps(GameObject &block);
	void UpdatePowerUps(GLfloat dt);
};

#endif