#include "App.h"

App::App() : window(800, 600, L"Pulsar Window")
{

}

int App::Go()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	window.GFX().ClearBuffer(c, c, 1.0f);
	window.GFX().DrawTestTriangle(timer.Peek());
	window.GFX().EndFrame();
}
