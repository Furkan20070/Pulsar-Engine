#include "App.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	try
	{
		return App{}.Go();
	}
	catch(const PulsarException& e)
	{
		const char* msg = e.what();
		const char* type = e.GetType();
		MessageBox(nullptr, Window::CharToWide(msg).c_str(), Window::CharToWide(type).c_str(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		const char* msg = e.what();
		MessageBox(nullptr, Window::CharToWide(e.what()).c_str(), L"Standart Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, L"No details available", L"Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}