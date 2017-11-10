#include "Game.h"
#include "resource_manager.h"
#include "SpriteRenderer.h"

SpriteRenderer *Renderer;

Game::Game(GLuint width, GLuint height)
	:State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{
}


Game::~Game()
{

}

void Game::Init()
{
	// Load shaders
	ResourceManager::LoadShader("shaders/sprite.vs", "shaders/sprite.frag", nullptr, "sprite");
	// Configure shaders
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width),
		static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
	ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
	// Set render-specific controls
	Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
	// Load textures
	ResourceManager::LoadTexture("textures/awesomeface.png", GL_TRUE, "face");

}

void Game::ProcessInput(GLfloat dt)
{
}

void Game::Update(GLfloat dt)
{
}

void Game::Render()
{
	Renderer->DrawSprite(ResourceManager::GetTexture("face"),
		glm::vec2(200, 200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}
