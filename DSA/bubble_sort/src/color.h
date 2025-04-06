/**
 * @file color.h
 * @brief Defines all of the ANSI terminal escape codes that modify the color of text.
 */

#ifndef COLOR_H
#define COLOR_H

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define BACKGROUND_TEXT(bg_color, text) \
    "\033["TOSTRING(bg_color)"m"text"\033[0m"

#define BACKGROUND_TEXT_COLOR(bg, fg, fmt) \
    "\033[" TOSTRING(bg) "m\033[" TOSTRING(fg) "m" fmt "\033[0m"

#endif // COLOR_H
