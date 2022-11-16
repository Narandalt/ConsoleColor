//
// Created by Narandalt on 15.11.2022.
//

#ifndef TEXTCOLOR_TEXTCOLOR_H
#define TEXTCOLOR_TEXTCOLOR_H

#include <stdio.h>
#include <windows.h>
#include <string.h>

#define darkBlue 1
#define darkGreen 2
#define darkTurquoise 3
#define darkRed 4
#define darkPink 5
#define darkYellow 6
#define white 7
#define darkWhite 8
#define blue 9
#define green 10
#define turquoise 11
#define red 12
#define pink 13
#define yellow 14

/*
 * HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
 */

int clrPrint (const char *__format, int textColor, ...)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);

    int __retval;
    __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
    __retval = __mingw_vfprintf( stdout, __format, __local_argv );
    __builtin_va_end( __local_argv );

    SetConsoleTextAttribute(hConsole, white);

    return __retval;
}

#endif //TEXTCOLOR_TEXTCOLOR_H
