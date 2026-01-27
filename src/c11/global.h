//
// Created by redredmaple on 2026/1/23.
//

#ifndef C11_GLOBAL_H
#define C11_GLOBAL_H

// globals.h
#pragma once
#include <mutex>

extern int g_constructCount;
extern int g_copyConstructCount;
extern int g_destructCount;
extern std::once_flag flag;



#endif //C11_GLOBAL_H
