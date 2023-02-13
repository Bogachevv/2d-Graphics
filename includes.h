#pragma once

#ifdef _WIN32

#include <windows.h>
#include "win/win_screen.h"

#elif defined(unix)

#include <unistd.h>
#include "linux/linux_screen.h"


#else
#error Incorrect operating system
#endif
