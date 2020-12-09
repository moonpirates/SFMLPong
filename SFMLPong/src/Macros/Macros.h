#pragma once

#include <iostream>
#include <iomanip>

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

// Colors references: https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
#define __ANSI_COLOR_DEFAULT__ "\033[0m"
#define __ANSI_COLOR_TIME__ "\033[90m"
#define __ANSI_COLOR_LOG__ "\033[91m"
#define __ANSI_COLOR_FILE__ "\033[90m"

#define LOG(x) std::cout << std::left \
	<< __ANSI_COLOR_TIME__ << "[" << __TIME__ << "] "  \
	<< __ANSI_COLOR_FILE__ << __FILENAME__ << "(" << __LINE__ << ")" << " " \
	<< __ANSI_COLOR_LOG__ << x << " " \
	<< __ANSI_COLOR_DEFAULT__ << std::endl;