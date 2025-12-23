#pragma once
#include "Window.h"
#include "PulsarTimer.h"

class App
{
public:
	App();
	// master frame / message loop
	int Go();
private:
	void DoFrame();
private:
	Window window;
	PulsarTimer timer;
};

