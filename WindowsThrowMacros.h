#pragma once

#define PLSR_EXCEPT( hr ) Window::HrException( __LINE__,__FILE__,(hr) )
#define PLSR_LAST_EXCEPT() Window::HrException( __LINE__,__FILE__,GetLastError() )
#define PLSR_NOGFX_EXCEPT() Window::NoGfxException( __LINE__,__FILE__ )
