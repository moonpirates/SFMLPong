#pragma once

#include <iostream>

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

// Colors based on https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
#define __ANSI_COLOR_DEFAULT__ "henk";
#define __ANSI_COLOR_GREY__ "henk";

#define LOG(x) std::cout << __ANSI_COLOR_GREY__ << "[" << __TIME__ << "] " << __ANSI_COLOR_DEFAULT__ << x << \
	__ANSI_COLOR_GREY__ << __FILENAME__ << "(" << __LINE__ << ")" << __ANSI_COLOR_DEFAULT__ << std::endl;