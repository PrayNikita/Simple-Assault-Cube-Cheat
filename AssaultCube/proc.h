#pragma once

#include "includes.h"
#include <Windows.h>

DWORD GetProcessID(const wchar_t* modName);

DWORD GetModuleBaseAddress(DWORD procID, const wchar_t* modName);