#pragma once

#include <iostream>
#include <iomanip>
#include <string>

// Filename macro
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

// Log colors, grabbed from https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
#define __ANSI_COLOR_DEFAULT__ "\033[97m"
#define __ANSI_COLOR_WARNING__ "\033[33m"
#define __ANSI_COLOR_ERROR__ "\033[31m"
#define __ANSI_COLOR_DIMMED__ "\033[90m"
#define __ANSI_COLOR_FILE__ "\033[90m"

// Column width constants
#define __FILE_COLUMN_WIDTH__ 25
#define __LINE_NUMBER_COLUMN_WIDTH__ 5
#define __LOG_LEVEL_COLUMN_WIDTH__ 4

//#define _STRINGIFY(x) #x
//#define STRINGIFY(x) _STRINGIFY(x)
//#define CONCAT(x,y) x##y

// Log levels
#define LOG_LEVEL_DEFAULT 0
#define LOG_LEVEL_WARNING 1
#define LOG_LEVEL_ERROR 2
#define LOG_LEVEL_FRIENDLY_DEFAULT ""
#define LOG_LEVEL_FRIENDLY_WARNING "WARN"
#define LOG_LEVEL_FRIENDLY_ERROR "ERR"

// Log methods
#define LOG(message) LOG_INTERNAL(message, LOG_LEVEL_DEFAULT)
#define LOG_WARN(message) LOG_INTERNAL(message, LOG_LEVEL_WARNING)
#define LOG_ERROR(message) LOG_INTERNAL(message, LOG_LEVEL_ERROR)

// Global log methods
#define LOG_INTERNAL(message, level) std::cout << std::left \
	<< GET_DIMMED_COLOR(level) << "[" << __DATE__ << " " << __TIME__ << "] " \
	<< GET_DIMMED_COLOR(level) << std::right << std::setw(__FILE_COLUMN_WIDTH__) << std::string(__FILENAME__) \
	<< GET_DIMMED_COLOR(level) << std::left << std::setw(__LINE_NUMBER_COLUMN_WIDTH__) << ":" + std::to_string(__LINE__) << " | "\
	<< GET_LOG_COLOR(level) << std::right << std::setw(__LOG_LEVEL_COLUMN_WIDTH__) << GET_FRIENDLY_LOG_LEVEL(level) \
	<< GET_DIMMED_COLOR(level) << " | " \
	<< GET_LOG_COLOR(level) << message \
	<< __ANSI_COLOR_DEFAULT__ \
	<< std::endl;

// Log level specific functions
#define GET_LOG_COLOR(level) ((level) == LOG_LEVEL_ERROR ? __ANSI_COLOR_ERROR__ : (level) == LOG_LEVEL_WARNING ? __ANSI_COLOR_WARNING__ \
	: __ANSI_COLOR_DEFAULT__)
#define GET_DIMMED_COLOR(level) (level == LOG_LEVEL_DEFAULT ? __ANSI_COLOR_DIMMED__ : GET_LOG_COLOR(level))
#define GET_FRIENDLY_LOG_LEVEL(level) ((level) == LOG_LEVEL_ERROR ? LOG_LEVEL_FRIENDLY_ERROR : (level) == LOG_LEVEL_WARNING ? \
	LOG_LEVEL_FRIENDLY_WARNING : LOG_LEVEL_FRIENDLY_DEFAULT)