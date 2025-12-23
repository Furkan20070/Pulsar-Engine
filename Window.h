#pragma once
#include "NoClutterWin.h"
#include "PulsarException.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include <optional>
#include <memory>

class Window
{
public:
	class Exception : public PulsarException
	{
		using PulsarException::PulsarException;
	public:
		static std::wstring TranslateErrorCode(HRESULT hr) noexcept;
	};
	class HrException : public Exception
	{
	public:
		HrException(int line, const char* file, HRESULT hr) noexcept;
		const char* what() const noexcept override;
		const char* GetType() const noexcept override;
		HRESULT GetErrorCode() const noexcept;
		std::string GetErrorDescription() const noexcept;
	private:
		HRESULT hr;
	};
	class NoGfxException : public Exception
	{
	public:
		using Exception::Exception;
		const char* GetType() const noexcept override;
	};
private:
	class WindowClass
	{
	public:
		static const wchar_t* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;
		static constexpr const wchar_t* wndClassName = L"DirectX 3D Window";
		static WindowClass wndClass;
		HINSTANCE hInst;
	};
public:
	Window(int width, int height, const wchar_t* name);
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	static std::wstring CharToWide(const char* text);
	static std::string WideToUtf8(const std::wstring& w);
	void SetTitle(const std::string& title) noexcept;
	static std::optional<int> ProcessMessages() noexcept;
	Graphics& GFX();
private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	static LRESULT CALLBACK HandleMsgThunk(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	LRESULT HandleMsg(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
public:
	Keyboard kbd;
	Mouse mouse;
private:
	int width;
	int height;
	HWND hwnd;
	std::unique_ptr<Graphics> pGfx;
};

// error execution helper macro
#define PLSR_EXCEPT( hr ) Window::HrException( __LINE__,__FILE__,(hr) )
#define PLSR_LAST_EXCEPT() Window::HrException( __LINE__,__FILE__,GetLastError() )
#define PLSR_NOGFX_EXCEPT() Window::NoGfxException( __LINE__,__FILE__ )

