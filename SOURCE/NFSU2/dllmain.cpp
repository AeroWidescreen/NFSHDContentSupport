#include "stdafx.h"
#include "stdio.h"
#include <windows.h>
#include "..\includes\injector\injector.hpp"
#include <cstdint>
#include "..\includes\IniReader.h"
#include <d3d9.h>
#include "..\settings.h"

DWORD FontScaleCodeCave1Exit = 0x51BFDF;
DWORD FontScaleCodeCave1Exit2 = 0x51BFD8;
DWORD FontScaleCodeCave2Exit = 0x5C5294;
DWORD FontScaleCodeCave2Exit2 = 0x5C5290;
DWORD CursorScaleCodeCaveExit = 0x50B6AA;

void __declspec(naked) FontScaleCodeCave1()
{
	__asm {
	FontScaleCodeCave1Check1:
		cmp dword ptr ds : [esi + 0x0C], 0x444E4F43 // checks for "COND"
		jne FontScaleCodeCave1Check2
		cmp dword ptr ds : [esi + 0x1C] , 0x00004931 // checks for "1I" (CONDUITMDITC_TT21I)
		je FontScaleCodeCave1Scale1
		cmp dword ptr ds : [esi + 0x1C], 0x00004931 // checks for "1I" (CONDUITMDITC_TT21I)
		je FontScaleCodeCave1Scale1
		cmp dword ptr ds : [esi + 0x1C], 0x545F4931 // checks for "1I_T" (CONDUITMDITC_TT21I_THAI)
		je FontScaleCodeCave1Scale1
		cmp dword ptr ds : [esi + 0x1C], 0x4A5F4931 // checks for "1I_J" (CONDUITMDITC_TT21I_JAPA)
		je FontScaleCodeCave1Scale2
		cmp dword ptr ds : [esi + 0x1C], 0x4B5F4931 // checks for "1I_K" (CONDUITMDITC_TT21I_KORE)
		je FontScaleCodeCave1Scale2
		cmp dword ptr ds : [esi + 0x1C], 0x435F4931 // checks for "1I_C" (CONDUITMDITC_TT21I_CHIN)
		je FontScaleCodeCave1Scale3
		cmp dword ptr ds : [esi + 0x1C], 0x00004934 // checks for "4I" (CONDUITMDITC_TT14I)
		je FontScaleCodeCave1Scale4
		cmp dword ptr ds : [esi + 0x1C], 0x545F4934 // checks for "4I_T" (CONDUITMDITC_TT14I_THAI)
		je FontScaleCodeCave1Scale4
		cmp dword ptr ds : [esi + 0x1C], 0x4A5F4934 // checks for "4I_J" (CONDUITMDITC_TT14I_JAPA)
		je FontScaleCodeCave1Scale2
		cmp dword ptr ds : [esi + 0x1C], 0x4B5F4934 // checks for "4I_K" (CONDUITMDITC_TT14I_KORE)
		je FontScaleCodeCave1Scale2
		cmp dword ptr ds : [esi + 0x1C], 0x435F4934 // checks for "4I_C" (CONDUITMDITC_TT14I_CHIN)
		je FontScaleCodeCave1Scale2
		jmp FontScaleCodeCave1None

	FontScaleCodeCave1Check2:
		cmp dword ptr ds : [esi + 0x0C], 0x544E4F46 // checks for "FONT"
		jne FontScaleCodeCave1Check3
		cmp dword ptr ds : [esi + 0x10], 0x4952415F // checks for "_ARI" (FONT_ARIAL)
		je FontScaleCodeCave1Scale3
		cmp dword ptr ds : [esi + 0x10], 0x4E4F435F // checks for "_CON" (FONT_CONDUITMDITCTT38BI)
		je FontScaleCodeCave1Scale5
		cmp dword ptr ds : [esi + 0x10], 0x504D495F // checks for "_IMP" (FONT_IMPACT36)
		je FontScaleCodeCave1Scale6
		jmp FontScaleCodeCave1None

	FontScaleCodeCave1Check3:
		cmp dword ptr ds : [esi + 0x0C], 0x5F44434C // checks for "LCD_"
		jne FontScaleCodeCave1None
		cmp dword ptr ds : [esi + 0x10], 0x3454454C // checks for "LET4" (LCD_LET4)
		je FontScaleCodeCave1Scale7
		jmp FontScaleCodeCave1None


	FontScaleCodeCave1Scale1:
		mov edi, 0x0100 // 256: CONDUITMDITC_TT21I, CONDUITMDITC_TT21I_THAI, FONT_ARIAL
		mov dword ptr ds : [esp + 0x28], edi
		lea edi, dword ptr ds : [eax - 0x01]
		mov esi, 0x0100 // 256: CONDUITMDITC_TT21I, CONDUITMDITC_TT21I_THAI, FONT_ARIAL
		jmp FontScaleCodeCave1Exit

	FontScaleCodeCave1Scale2:
		mov edi, 0x0400 // 1024: CONDUITMDITC_TT21I_JAPA, CONDUITMDITC_TT21I_KORE, CONDUITMDITC_TT14I_JAPA, CONDUITMDITC_TT14I_KORE, CONDUITMDITC_TT14I_CHIN
		mov dword ptr ds : [esp + 0x28] , edi
		lea edi, dword ptr ds : [eax - 0x01]
		mov esi, 0x0200 // 512: CONDUITMDITC_TT21I_JAPA, CONDUITMDITC_TT21I_KORE, CONDUITMDITC_TT14I_JAPA, CONDUITMDITC_TT14I_KORE, CONDUITMDITC_TT14I_CHIN
		jmp FontScaleCodeCave1Exit

	FontScaleCodeCave1Scale3:
		mov edi, 0x0400 // 1024: CONDUITMDITC_TT21I_CHIN
		mov dword ptr ds : [esp + 0x28] , edi
		lea edi, dword ptr ds : [eax - 0x01]
		mov esi, 0x0400 // 1024: CONDUITMDITC_TT21I_CHIN
		jmp FontScaleCodeCave1Exit

	FontScaleCodeCave1Scale4:
		mov edi, 0x0100 // 256: CONDUITMDITC_TT14I, CONDUITMDITC_TT14I_THAI
		mov dword ptr ds : [esp + 0x28] , edi
		lea edi, dword ptr ds : [eax - 0x01]
		mov esi, 0x0080 // 128: CONDUITMDITC_TT14I, CONDUITMDITC_TT14I_THAI
		jmp FontScaleCodeCave1Exit

	FontScaleCodeCave1Scale5:
		mov edi, 0x0200 // 512: FONT_CONDUITMDITCTT38BI
		mov dword ptr ds : [esp + 0x28] , edi
		lea edi, dword ptr ds : [eax - 0x01]
		mov esi, 0x0100 // 256: FONT_CONDUITMDITCTT38BI
		jmp FontScaleCodeCave1Exit

	FontScaleCodeCave1Scale6:
		mov edi, 0x0200 // 512: FONT_IMPACT36
		mov dword ptr ds : [esp + 0x28] , edi
		lea edi, dword ptr ds : [eax - 0x01]
		mov esi, 0x0200 // 512: FONT_IMPACT36
		jmp FontScaleCodeCave1Exit

	FontScaleCodeCave1Scale7:
		mov edi, 0x0080 // 128: LCD_LET4
		mov dword ptr ds : [esp + 0x28] , edi
		lea edi, dword ptr ds : [eax - 0x01]
		mov esi, 0x0040 // 64: LCD_LET4
		jmp FontScaleCodeCave1Exit

	FontScaleCodeCave1None:
		movsx edi, word ptr ds : [esi + 0x44]
		mov dword ptr ds : [esp + 0x28], edi
		jmp FontScaleCodeCave1Exit2
	}
}

void __declspec(naked) FontScaleCodeCave2()
{
	__asm {
	FontScaleCodeCave2Check1:
		cmp dword ptr ds : [ecx + 0x0C], 0x444E4F43 // checks for "COND"
		jne FontScaleCodeCave2Check2
		cmp dword ptr ds : [ecx + 0x1C], 0x00004931 // checks for "1I" (CONDUITMDITC_TT21I)
		je FontScaleCodeCave2Scale1
		cmp dword ptr ds : [ecx + 0x1C], 0x00004931 // checks for "1I" (CONDUITMDITC_TT21I)
		je FontScaleCodeCave2Scale1
		cmp dword ptr ds : [ecx + 0x1C], 0x545F4931 // checks for "1I_T" (CONDUITMDITC_TT21I_THAI)
		je FontScaleCodeCave2Scale1
		cmp dword ptr ds : [ecx + 0x1C], 0x4A5F4931 // checks for "1I_J" (CONDUITMDITC_TT21I_JAPA)
		je FontScaleCodeCave2Scale2
		cmp dword ptr ds : [ecx + 0x1C], 0x4B5F4931 // checks for "1I_K" (CONDUITMDITC_TT21I_KORE)
		je FontScaleCodeCave2Scale2
		cmp dword ptr ds : [ecx + 0x1C], 0x435F4931 // checks for "1I_C" (CONDUITMDITC_TT21I_CHIN)
		je FontScaleCodeCave2Scale3
		cmp dword ptr ds : [ecx + 0x1C], 0x00004934 // checks for "4I" (CONDUITMDITC_TT14I)
		je FontScaleCodeCave2Scale4
		cmp dword ptr ds : [ecx + 0x1C], 0x545F4934 // checks for "4I_T" (CONDUITMDITC_TT14I_THAI)
		je FontScaleCodeCave2Scale4
		cmp dword ptr ds : [ecx + 0x1C], 0x4A5F4934 // checks for "4I_J" (CONDUITMDITC_TT14I_JAPA)
		je FontScaleCodeCave2Scale2
		cmp dword ptr ds : [ecx + 0x1C], 0x4B5F4934 // checks for "4I_K" (CONDUITMDITC_TT14I_KORE)
		je FontScaleCodeCave2Scale2
		cmp dword ptr ds : [ecx + 0x1C], 0x435F4934 // checks for "4I_C" (CONDUITMDITC_TT14I_CHIN)
		je FontScaleCodeCave2Scale2
		jmp FontScaleCodeCave2None

	FontScaleCodeCave2Check2:
		cmp dword ptr ds : [ecx + 0x0C], 0x544E4F46 // checks for "FONT"
		jne FontScaleCodeCave2Check3
		cmp dword ptr ds : [ecx + 0x10], 0x4952415F // checks for "_ARI" (FONT_ARIAL)
		je FontScaleCodeCave2Scale3
		cmp dword ptr ds : [ecx + 0x10], 0x4E4F435F // checks for "_CON" (FONT_CONDUITMDITCTT38BI)
		je FontScaleCodeCave2Scale5
		cmp dword ptr ds : [ecx + 0x10], 0x504D495F // checks for "_IMP" (FONT_IMPACT36)
		je FontScaleCodeCave2Scale6
		jmp FontScaleCodeCave2None

	FontScaleCodeCave2Check3:
		cmp dword ptr ds : [ecx + 0x0C], 0x5F44434C // checks for "LCD_"
		jne FontScaleCodeCave2None
		cmp dword ptr ds : [ecx + 0x10], 0x3454454C // checks for "LET4" (LCD_LET4)
		je FontScaleCodeCave2Scale7
		jmp FontScaleCodeCave2None


	FontScaleCodeCave2Scale1:
		mov edx, 0x0100 // 256: CONDUITMDITC_TT21I, CONDUITMDITC_TT21I_THAI, FONT_ARIAL
		mov dword ptr ds : [esp + 0x1C], edx
		mov eax, 0x0100 // 256: CONDUITMDITC_TT21I, CONDUITMDITC_TT21I_THAI, FONT_ARIAL
		jmp FontScaleCodeCave2Exit

	FontScaleCodeCave2Scale2:
		mov edx, 0x0400 // 1024: CONDUITMDITC_TT21I_JAPA, CONDUITMDITC_TT21I_KORE, CONDUITMDITC_TT14I_JAPA, CONDUITMDITC_TT14I_KORE, CONDUITMDITC_TT14I_CHIN
		mov dword ptr ds : [esp + 0x1C], edx
		mov eax, 0x0200 // 512: CONDUITMDITC_TT21I_JAPA, CONDUITMDITC_TT21I_KORE, CONDUITMDITC_TT14I_JAPA, CONDUITMDITC_TT14I_KORE, CONDUITMDITC_TT14I_CHIN
		jmp FontScaleCodeCave2Exit

	FontScaleCodeCave2Scale3:
		mov edx, 0x0400 // 1024: CONDUITMDITC_TT21I_CHIN
		mov dword ptr ds : [esp + 0x1C], edx
		mov eax, 0x0400 // 1024: CONDUITMDITC_TT21I_CHIN
		jmp FontScaleCodeCave2Exit

	FontScaleCodeCave2Scale4:
		mov edx, 0x0100 // 256: CONDUITMDITC_TT14I, CONDUITMDITC_TT14I_THAI
		mov dword ptr ds : [esp + 0x1C], edx
		mov eax, 0x0080 // 128: CONDUITMDITC_TT14I, CONDUITMDITC_TT14I_THAI
		jmp FontScaleCodeCave2Exit

	FontScaleCodeCave2Scale5:
		mov edx, 0x0200 // 512: FONT_CONDUITMDITCTT38BI
		mov dword ptr ds : [esp + 0x1C], edx
		mov eax, 0x0100 // 256: FONT_CONDUITMDITCTT38BI
		jmp FontScaleCodeCave2Exit

	FontScaleCodeCave2Scale6:
		mov edx, 0x0200 // 512: FONT_IMPACT36
		mov dword ptr ds : [esp + 0x1C], edx
		mov eax, 0x0200 // 512: FONT_IMPACT36
		jmp FontScaleCodeCave2Exit

	FontScaleCodeCave2Scale7:
		mov edx, 0x0080 // 128: LCD_LET4
		mov dword ptr ds : [esp + 0x1C], edx
		mov eax, 0x0040 // 64: LCD_LET4
		jmp FontScaleCodeCave2Exit

	FontScaleCodeCave2None:
		movsx edx, word ptr ds : [ecx + 0x44]
		mov dword ptr ds : [esp + 0x1C], edx
		jmp FontScaleCodeCave2Exit2
	}
}

void __declspec(naked) CursorScaleCodeCave()
{
	__asm {
	CursorScaleCodeCaveCheck:
		cmp dword ptr ds : [esi + 0x0C], 0x435F4350 // checks for "PC_C"
		jne CursorScaleCodeCaveNone
		cmp dword ptr ds : [esi + 0x10], 0x4F535255 // checks for "URSO" (PC_CURSOR)
		jne CursorScaleCodeCaveNone

	CursorScaleCodeCaveScale:
		mov dword ptr ds : [esi + 0x44], 0x00200020 // 32 (0x0020) 32 (0x0020)

	CursorScaleCodeCaveNone:
		movsx edx, word ptr ds : [esi + 0x44]
		add edx, eax
		jmp CursorScaleCodeCaveExit
	}
}

void Init()
{
	// Read values from .ini
	CIniReader iniReader("NFSU2HDContentSupport.ini");

	// General
	HDFontSupport = iniReader.ReadInteger("GENERAL", "HDFontSupport", 1);
	HDCursorSupport = iniReader.ReadInteger("GENERAL", "HDCursorSupport", 1);
	GlobalNeon = iniReader.ReadInteger("GENERAL", "GlobalNeon", 0);
	GlobalShadowIG = iniReader.ReadInteger("GENERAL", "GlobalShadowIG", 0);
	GlobalShadowFE = iniReader.ReadInteger("GENERAL", "GlobalShadowFE", 0);

	if (HDFontSupport)
	{
		injector::MakeJMP(0x51BFD0, FontScaleCodeCave1, true);
		injector::MakeJMP(0x5C5288, FontScaleCodeCave2, true);
	}
	
	if (HDCursorSupport)
	{
		injector::MakeJMP(0x50B6A4, CursorScaleCodeCave, true);
	}

	if (GlobalNeon)
	{
		injector::WriteMemory(0x6329B1, &"HD_NEON", true);
		injector::WriteMemory(0x63883E, &"HD_NEON", true);
	}

	if (GlobalShadowIG)
	{
		injector::WriteMemory(0x6387EC, &"HD_SHADOWIG", true);
	}

	if (GlobalShadowFE)
	{
		injector::WriteMemory(0x63880D, &"HD_SHADOWFE", true);
	}
}

BOOL APIENTRY DllMain(HMODULE /*hModule*/, DWORD reason, LPVOID /*lpReserved*/)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		uintptr_t base = (uintptr_t)GetModuleHandleA(NULL);
		IMAGE_DOS_HEADER* dos = (IMAGE_DOS_HEADER*)(base);
		IMAGE_NT_HEADERS* nt = (IMAGE_NT_HEADERS*)(base + dos->e_lfanew);

		if ((base + nt->OptionalHeader.AddressOfEntryPoint + (0x400000 - base)) == 0x75BCC7) // Check if .exe file is compatible - Thanks to thelink2012 and MWisBest
			Init();

		else
		{
			MessageBoxA(NULL, "This .exe is not supported.\nPlease use v1.2 NTSC speed2.exe (4,57 MB (4.800.512 bytes)).", "NFSU2 HD Content Support by Aero_", MB_ICONERROR);
			return FALSE;
		}
	}
	return TRUE;

}