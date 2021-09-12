#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Component.h"
#include "Entity.h"
#include "EntityManager.h"

class AssetManager;

class Game
{
private:
	bool isRunning;
	SDL_Window* window;
public:
	Game();
	~Game();
	static SDL_Renderer* renderer;
	static AssetManager* assetManager;
	static SDL_Event event;
	static SDL_Rect camera;
	int ticksLastFrame;
	bool IsRunning() const;
	void Initialize(int width, int height);
	void ProcessInput();
	void Update();
	void Render();
	void Destroy();
	void LoadLevel(int levelNumber);
	void ProcessCameraMovement();
	void ProcessCollisions();
	static bool isDebugMode;
	void CheckAllCollisions();
	void LoadNextLevel();
	void ProcessGameOver();
};
#endif // !GAME.H

