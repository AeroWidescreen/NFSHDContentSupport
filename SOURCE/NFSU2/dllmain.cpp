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
		cmp dword ptr ds : [esi + 0x24], 0x5B9D88B9 // checks for "CONDUITMDITC_TT21I"
		je FontScaleCodeCave1Scale1
		cmp dword ptr ds : [esi + 0x24], 0x4815619D // checks for "CONDUITMDITC_TT21I_THAILAND"
		je FontScaleCodeCave1Scale1
		cmp dword ptr ds : [esi + 0x24], 0x15192F5F // checks for "CONDUITMDITC_TT21I_JAPANESE"
		je FontScaleCodeCave1Scale1
		cmp dword ptr ds : [esi + 0x24], 0x833A8678 // checks for "CONDUITMDITC_TT21I_KOREAN"
		je FontScaleCodeCave1Scale2
		cmp dword ptr ds : [esi + 0x24], 0x71C777D7 // checks for "CONDUITMDITC_TT21I_CHINESE"
		je FontScaleCodeCave1Scale3
		cmp dword ptr ds : [esi + 0x24], 0x5B9D84DB // checks for "CONDUITMDITC_TT14I"
		je FontScaleCodeCave1Scale4
		cmp dword ptr ds : [esi + 0x24], 0xA73823FF // checks for "CONDUITMDITC_TT14I_THAILAND"
		je FontScaleCodeCave1Scale4
		cmp dword ptr ds : [esi + 0x24], 0x743BF1C1 // checks for "CONDUITMDITC_TT14I_JAPANESE"
		je FontScaleCodeCave1Scale2
		cmp dword ptr ds : [esi + 0x24], 0xDCA5485A // checks for "CONDUITMDITC_TT14I_KOREAN"
		je FontScaleCodeCave1Scale2
		cmp dword ptr ds : [esi + 0x24], 0xF88A75F9 // checks for "CONDUITMDITC_TT14I_CHINESE"
		je FontScaleCodeCave1Scale2
		cmp dword ptr ds : [esi + 0x24], 0xA87927BE // checks for "FONT_ARIAL"
		je FontScaleCodeCave1Scale3
		cmp dword ptr ds : [esi + 0x24], 0x9583AA1A // checks for "FONT_CONDUITMDITCTT38BI"
		je FontScaleCodeCave1Scale5
		cmp dword ptr ds : [esi + 0x24], 0x0920075C // checks for "FONT_IMPACT36"
		je FontScaleCodeCave1Scale6
		cmp dword ptr ds : [esi + 0x24], 0xBBBA71C2 // checks for "LCD_LET48"
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
		cmp dword ptr ds : [ecx + 0x24], 0x5B9D88B9 // checks for "CONDUITMDITC_TT21I"
		je FontScaleCodeCave2Scale1
		cmp dword ptr ds : [ecx + 0x24], 0x4815619D // checks for "CONDUITMDITC_TT21I_THAILAND"
		je FontScaleCodeCave2Scale1
		cmp dword ptr ds : [ecx + 0x24], 0x15192F5F // checks for "CONDUITMDITC_TT21I_JAPANESE"
		je FontScaleCodeCave2Scale2
		cmp dword ptr ds : [ecx + 0x24], 0x833A8678 // checks for "CONDUITMDITC_TT21I_KOREAN"
		je FontScaleCodeCave2Scale2
		cmp dword ptr ds : [ecx + 0x24], 0x71C777D7 // checks for "CONDUITMDITC_TT21I_CHINESE"
		je FontScaleCodeCave2Scale3
		cmp dword ptr ds : [ecx + 0x24], 0x5B9D84DB // checks for "CONDUITMDITC_TT14I"
		je FontScaleCodeCave2Scale4
		cmp dword ptr ds : [ecx + 0x24], 0xA73823FF // checks for "CONDUITMDITC_TT14I_THAILAND"
		je FontScaleCodeCave2Scale4
		cmp dword ptr ds : [ecx + 0x24], 0x743BF1C1 // checks for "CONDUITMDITC_TT14I_JAPANESE"
		je FontScaleCodeCave2Scale2
		cmp dword ptr ds : [ecx + 0x24], 0xDCA5485A // checks for "CONDUITMDITC_TT14I_KOREAN"
		je FontScaleCodeCave2Scale2
		cmp dword ptr ds : [ecx + 0x24], 0xF88A75F9 // checks for "CONDUITMDITC_TT14I_CHINESE"
		je FontScaleCodeCave2Scale2
		cmp dword ptr ds : [ecx + 0x24], 0xA87927BE // checks for "FONT_ARIAL"
		je FontScaleCodeCave2Scale3
		cmp dword ptr ds : [ecx + 0x24], 0x9583AA1A // checks for "FONT_CONDUITMDITCTT38BI"
		je FontScaleCodeCave2Scale5
		cmp dword ptr ds : [ecx + 0x24], 0x0920075C // checks for "FONT_IMPACT36"
		je FontScaleCodeCave2Scale6
		cmp dword ptr ds : [ecx + 0x24], 0xBBBA71C2 // checks for "LCD_LET48"
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
		cmp dword ptr ds : [esi + 0x24], 0x6B6A294F // checks for "PC_CURSOR"
		jne CursorScaleCodeCaveNone

	CursorScaleCodeCaveScale:
		mov dword ptr ds : [esi + 0x44], 0x00200020 // 32 (0x0020) 32 (0x0020)

	CursorScaleCodeCaveNone:
		movsx edx, word ptr ds : [esi + 0x44]
		add edx, eax
		jmp CursorScaleCodeCaveExit
	}
}

void __declspec(naked) TextureScaleCodeCave1()
{
	__asm {
		cmp dword ptr ds : [eax + 0x24], 0x37BD6804 // checks for "DRAG_HEAT_FILL"
		je TextureScaleCodeCave1Scale1
		cmp dword ptr ds : [eax + 0x24], 0x435AEE12 // checks for "DRAG_NOS_FILL"
		je TextureScaleCodeCave1Scale1
		movsx ecx, word ptr ds : [eax + 0x46]
		mov dword ptr ds : [esp + 0x34], ecx
		ret


	TextureScaleCodeCave1Scale1:
		mov ecx, 0x0100 // 256: DRAG_HEAT_FILL
		mov dword ptr ds : [esp + 0x34], ecx
		ret
	}
}

void __declspec(naked) WidescreenSplashCodeCave()
{
	__asm {
		cmp dword ptr ds : [esi + 0x38], 0x44200000 // 640
		jne ExitCode
		cmp dword ptr ds : [esi + 0x3C], 0x43F00000 // 480
		jne ExitCode
		cmp dword ptr ds : [esi + 0x40] , 0x00000000 // 0
		jne ExitCode
		cmp dword ptr ds : [esi + 0x44] , 0x00000000 // 0
		jne ExitCode
		mov dword ptr ds : [esi + 0x38], 0x44555555 // 853 (16:9)

	ExitCode:
		mov ecx, 0x3F800000
		ret
	}
}

void Init()
{
	// Read values from .ini
	CIniReader iniReader("NFSU2HDContentSupport.ini");

	// General
	HDFontSupport = iniReader.ReadInteger("GENERAL", "HDFontSupport", 1);
	HDCursorSupport = iniReader.ReadInteger("GENERAL", "HDCursorSupport", 1);
	HDTextureSupport = iniReader.ReadInteger("GENERAL", "HDTextureSupport", 1);
	GlobalNeon = iniReader.ReadInteger("GENERAL", "GlobalNeon", 0);
	GlobalShadowIG = iniReader.ReadInteger("GENERAL", "GlobalShadowIG", 0);
	GlobalShadowFE = iniReader.ReadInteger("GENERAL", "GlobalShadowFE", 0);
	WidescreenSplash = iniReader.ReadInteger("GENERAL", "WidescreenSplash", 0);

	if (HDFontSupport)
	{
		injector::MakeJMP(0x51BFD0, FontScaleCodeCave1, true);
		injector::MakeJMP(0x5C5288, FontScaleCodeCave2, true);
	}
	
	if (HDCursorSupport)
	{
		injector::MakeJMP(0x50B6A4, CursorScaleCodeCave, true);
	}

	if (HDTextureSupport)
	{
		injector::MakeCALL(0x4C6709, TextureScaleCodeCave1, true);
		injector::MakeNOP(0x4C670E, 3, true);
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

	if (WidescreenSplash)
	{
		injector::MakeCALL(0x51B10A, WidescreenSplashCodeCave, true);
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