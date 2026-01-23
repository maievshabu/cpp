//
// Created by redredmaple on 2026/1/23.
//
#include "global.h"

int g_constructCount = 0;
int g_copyConstructCount = 0;
int g_destructCount = 0;
std::once_flag flag;
