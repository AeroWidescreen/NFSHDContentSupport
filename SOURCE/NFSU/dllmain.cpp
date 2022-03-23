#include "stdafx.h"
#include "stdio.h"
#include <windows.h>
#include "..\includes\injector\injector.hpp"
#include <cstdint>
#include "..\includes\IniReader.h"
#include <d3d9.h>
#include "..\settings.h"

DWORD loc_40C0F4 = 0x40C0F4;
DWORD loc_40C0F0 = 0x40C0F0;

void __declspec(naked) FontScaleCodeCave1()
{
	_asm 
	{
	FontScaleCodeCave1Check1:
		cmp dword ptr ds : [ecx + 0x24], 0x5B9D88B9 // checks for "CONDUITMDITC_TT21I" // 256x256
		je FontScaleCodeCave1Scale256256
		cmp dword ptr ds : [ecx + 0x24], 0x5B9D84DB // checks for "CONDUITMDITC_TT14I" // 256x256
		je FontScaleCodeCave1Scale256256
		cmp dword ptr ds : [ecx + 0x24], 0xDCA5485A // checks for "CONDUITMDITC_TT14I_KOREAN" // 512x512
		je FontScaleCodeCave1Scale512512
		cmp dword ptr ds : [ecx + 0x24], 0x833A8678 // checks for "CONDUITMDITC_TT21I_KOREAN" // 512x1024
		je FontScaleCodeCave1Scale5121024
		cmp dword ptr ds : [ecx + 0x24], 0xA87927BE // checks for "FONT_ARIAL" // 256x256
		je FontScaleCodeCave1Scale256256
		cmp dword ptr ds : [ecx + 0x24], 0xAB6215C1 // checks for "FONT_ARIAL12" // 256x256
		je FontScaleCodeCave1Scale256256
		cmp dword ptr ds : [ecx + 0x24], 0x9583AA1A // checks for "FONT_CONDUITMDITCTT38BI" // 512x512
		je FontScaleCodeCave1Scale512512
		cmp dword ptr ds : [ecx + 0x24], 0x0920075C // checks for "FONT_IMPACT36" // 512x512
		je FontScaleCodeCave1Scale512512
		cmp dword ptr ds : [ecx + 0x24], 0xBBBA71C2 // checks for "LCD_LET48" // 128x128
		je FontScaleCodeCave1Scale128128
		jmp ExitCode

	FontScaleCodeCave1Scale128128:
		mov edx, 0x0080 // 128: LCD_LET48
		mov dword ptr ds : [esp + 0x0C] , edx
		mov eax, 0x0080 // 128: LCD_LET48
		jmp loc_40C0F4

	FontScaleCodeCave1Scale256256:
		mov edx, 0x0100 // 256: CONDUITMDITC_TT21I, CONDUITMDITC_TT14I_KOREAN, FONT_ARIAL, FONTARIAL12
		mov dword ptr ds : [esp + 0x0C], edx
		mov eax, 0x0100 // 256: CONDUITMDITC_TT21I, CONDUITMDITC_TT14I_KOREAN, FONT_ARIAL, FONTARIAL12
		jmp loc_40C0F4

	FontScaleCodeCave1Scale512512:
		mov edx, 0x0200 // 512: CONDUITMDITC_TT14I_KOREAN, FONT_CONDUITMDITCTT38BI, FONT_IMPACT36
		mov dword ptr ds : [esp + 0x0C] , edx
		mov eax, 0x0200 // 512: CONDUITMDITC_TT14I_KOREAN, FONT_CONDUITMDITCTT38BI, FONT_IMPACT36
		jmp loc_40C0F4

	FontScaleCodeCave1Scale5121024:
		mov edx, 0x0200 // 512: CONDUITMDITC_TT21I_KOREAN
		mov dword ptr ds : [esp + 0x0C] , edx
		mov eax, 0x0400 // 1024:  CONDUITMDITC_TT21I_KOREAN
		jmp loc_40C0F4

	ExitCode:
		movsx edx, word ptr ds : [ecx + 0x44]
		mov dword ptr ds : [esp + 0x0C], edx
		jmp loc_40C0F0
	}
}

DWORD loc_4F47AA = 0x4F47AA;
DWORD loc_4F47A3 = 0x4F47A3;

void __declspec(naked) FontScaleCodeCave2()
{
	_asm
	{
		cmp dword ptr ds : [edx + 0x24] , 0x5B9D88B9 // checks for "CONDUITMDITC_TT21I" // 256x256
		je FontScaleCodeCave2Scale256256
		cmp dword ptr ds : [edx + 0x24] , 0x5B9D84DB // checks for "CONDUITMDITC_TT14I" // 256x256
		je FontScaleCodeCave2Scale256256
		cmp dword ptr ds : [edx + 0x24] , 0xDCA5485A // checks for "CONDUITMDITC_TT14I_KOREAN" // 512x512
		je FontScaleCodeCave2Scale512512
		cmp dword ptr ds : [edx + 0x24] , 0x833A8678 // checks for "CONDUITMDITC_TT21I_KOREAN" // 512x1024
		je FontScaleCodeCave2Scale5121024
		cmp dword ptr ds : [edx + 0x24] , 0xA87927BE // checks for "FONT_ARIAL" // 256x256
		je FontScaleCodeCave2Scale256256
		cmp dword ptr ds : [edx + 0x24] , 0xAB6215C1 // checks for "FONT_ARIAL12" // 256x256
		je FontScaleCodeCave2Scale256256
		cmp dword ptr ds : [edx + 0x24] , 0x9583AA1A // checks for "FONT_CONDUITMDITCTT38BI" // 512x512
		je FontScaleCodeCave2Scale512512
		cmp dword ptr ds : [edx + 0x24] , 0x0920075C // checks for "FONT_IMPACT36" // 512x512
		je FontScaleCodeCave2Scale512512
		cmp dword ptr ds : [edx + 0x24] , 0xBBBA71C2 // checks for "LCD_LET48" // 128x128
		je FontScaleCodeCave2Scale128128
		jmp ExitCode

	FontScaleCodeCave2Scale128128:
		mov esi, 0x0080 // 128: LCD_LET48
		mov dword ptr ds : [esp + 0x04], esi
		lea esi, dword ptr ds : [eax - 0x01]
		mov edx, 0x0080 // 128: LCD_LET48
		jmp loc_4F47AA

	FontScaleCodeCave2Scale256256 :
		mov esi, 0x0100 // 256: CONDUITMDITC_TT21I, CONDUITMDITC_TT14I_KOREAN, FONT_ARIAL, FONTARIAL12
		mov dword ptr ds : [esp + 0x04], esi
		lea esi, dword ptr ds : [eax - 0x01]
		mov edx, 0x0100 // 256: CONDUITMDITC_TT21I, CONDUITMDITC_TT14I_KOREAN, FONT_ARIAL, FONTARIAL12
		jmp loc_4F47AA

	FontScaleCodeCave2Scale512512 :
		mov esi, 0x0200 // 512: CONDUITMDITC_TT14I_KOREAN, FONT_CONDUITMDITCTT38BI, FONT_IMPACT36
		mov dword ptr ds : [esp + 0x04], esi
		lea esi, dword ptr ds : [eax - 0x01]
		mov edx, 0x0200 // 512: CONDUITMDITC_TT14I_KOREAN, FONT_CONDUITMDITCTT38BI, FONT_IMPACT36
		jmp loc_4F47AA

	FontScaleCodeCave2Scale5121024 :
		mov esi, 0x0200 // 512: CONDUITMDITC_TT21I_KOREAN
		mov dword ptr ds : [esp + 0x04], esi
		lea esi, dword ptr ds : [eax - 0x01]
		mov edx, 0x0400 // 1024:  CONDUITMDITC_TT21I_KOREAN
		jmp loc_4F47AA

	ExitCode:
		movsx esi, word ptr ds : [edx + 0x44]
		mov dword ptr ds : [esp + 0x04], esi
		jmp loc_4F47A3
	}
}

DWORD loc_4F36BE = 0x4F36BE;

void __declspec(naked) CursorScaleCodeCave()
{
	_asm 
	{
		cmp dword ptr ds : [edi + 0x24], 0x6B6A294F // checks for "PC_CURSOR"
		jne ExitCode

	CursorScaleCodeCaveScale:
		mov dword ptr ds : [edi + 0x44], 0x00100010 // 32 (0x0020) 32 (0x0020)

	ExitCode:
		movsx ecx, word ptr ds : [edi + 0x44]
		mov edx, dword ptr ds : [esp + 0x18]
		jmp loc_4F36BE
	}
}

void Init()
{
	// Read values from .ini
	CIniReader iniReader("NFSUHDContentSupport.ini");

	// General
	HDFontSupport = iniReader.ReadInteger("GENERAL", "HDFontSupport", 1);
	HDCursorSupport = iniReader.ReadInteger("GENERAL", "HDCursorSupport", 1);
	GlobalNeon = iniReader.ReadInteger("GENERAL", "(GlobalNeon", 0);
	GlobalShadowIG = iniReader.ReadInteger("GENERAL", "GlobalShadowIG", 0);
	GlobalShadowFE = iniReader.ReadInteger("GENERAL", "GlobalShadowFE", 0);

	if (HDFontSupport)
	{
		injector::MakeJMP(0x40C0E8, FontScaleCodeCave1, true);
		injector::MakeNOP(0x40C0ED, 3, true);
		injector::MakeJMP(0x4F479B, FontScaleCodeCave2, true);
		injector::MakeNOP(0x4F47A0, 3, true);
	}
	
	if (HDCursorSupport)
	{
		injector::MakeJMP(0x4F36B6, CursorScaleCodeCave, true);
	}

	if (GlobalNeon)
	{
		injector::WriteMemory(0x6BBD0C, &"HD_NEON", true);
	}

	if (GlobalShadowIG)
	{
		injector::WriteMemory(0x6BBD14, &"HD_SHADOWIG", true);
	}

	if (GlobalShadowFE)
	{
		injector::WriteMemory(0x6BBD20, &"HD_SHADOWFE", true);
	}
}

BOOL APIENTRY DllMain(HMODULE /*hModule*/, DWORD reason, LPVOID /*lpReserved*/)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		uintptr_t base = (uintptr_t)GetModuleHandleA(NULL);
		IMAGE_DOS_HEADER* dos = (IMAGE_DOS_HEADER*)(base);
		IMAGE_NT_HEADERS* nt = (IMAGE_NT_HEADERS*)(base + dos->e_lfanew);

		if ((base + nt->OptionalHeader.AddressOfEntryPoint + (0x400000 - base)) == 0x670CB5) // Check if .exe file is compatible - Thanks to thelink2012 and MWisBest
			Init();

		else
		{
			MessageBoxA(NULL, "This .exe is not supported.\nPlease use v1.4 English speed.exe (3.03 MB (3.178.496 bytes)).", "NFSU HD Content Support by Aero_", MB_ICONERROR);
			return FALSE;
		}
	}
	return TRUE;

}