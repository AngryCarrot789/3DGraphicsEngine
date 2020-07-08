#pragma once
#include "GameHeader.h"
#include "Camera.h"
#include "Input.h"
#include "GameObject.h"
#include "Player.h"
#include "Sky.h"
#include <GL/glew.h>
#include <windows.h>
#include <memory>
#include <vector>
#include "Timer.h"
#include "Scene.h"

class Engine {
public:
	Engine();
	~Engine();

	int Run();
	void Update();
	void Render(const Camera& cam, GLuint curFBO);
	void LoadScene(int sceneNumber);

	LRESULT WindowProc(HWND hCurWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	const Player& GetPlayer() const { return *player; }

private:
	void CreateGLWindow();
	void InitGLObjects();
	void DestroyGLObjects();
	void SetupInputs();
	void ConfineCursor();
	void ToggleFullscreen();

	HDC   hDC;           // Device context
	HGLRC hRC;		     // OpenGL context
	HWND  hWnd;		     // Window handle
	HINSTANCE hInstance; // Application/Process ID

	LONG iWidth;         // Window Width
	LONG iHeight;        // Window Height
	bool isFullscreen;   // Fullscreen state

	//Main camera
	Camera main_cam;
	//Inputs for keyboard/mouse (and others...)
	Input input;
	//A timer mainly used for updating physics for realism
	Timer timer;

	// A collection of GameObjects
	std::vector<std::shared_ptr<GameObject>> vObjects;
	// The sky
	std::shared_ptr<Sky> sky;
	// You... the player
	std::shared_ptr<Player> player;

	// A collection of playable scenes
	std::vector<std::shared_ptr<Scene>> vScenes;
	// The scene you're currently in.
	std::shared_ptr<Scene> curScene;

	// an opengl thingy
	GLint occlusionCullingSupported;
};