#include "stdafx.h"
#include "stdio.h"
#include <windows.h>
#include "..\includes\injector\injector.hpp"
#include <cstdint>
#include "..\includes\IniReader.h"
#include <d3d9.h>
#include "..\settings.h"

DWORD FontScaleCodeCave1Exit = 0x585D7F;
DWORD FontScaleCodeCave1Part2Exit = 0x585D78;
DWORD FontScaleCodeCave2Exit = 0x6D1502;
DWORD FontScaleCodeCave2Part2Exit = 0x6D14FE;
DWORD CursorScaleCodeCave1Exit = 0x570462;
DWORD CursorScaleCodeCave2Exit = 0x570487;
DWORD CursorScaleCodeCave3Exit = 0x57049C;
DWORD CursorScaleCodeCave4Exit = 0x5704C5;
DWORD FMVScaleCodeCaveExit = 0x599F1E;

void __declspec(naked) FontScaleCodeCave1()
{
	__asm {
	FontScaleCodeCave1Check1:
		cmp dword ptr ds : [esi + 0x24], 0xA87927BE // checks for "FONT_ARIAL"
		je FontScaleCodeCave1Scale1
		cmp dword ptr ds : [esi + 0x24], 0xAB6215C1 // checks for "FONT_ARIAL12"
		je FontScaleCodeCave1Scale1
		cmp dword ptr ds : [esi + 0x24], 0x545570C6 // checks for "FONT_MW_BODY"
		je FontScaleCodeCave1Scale1
		cmp dword ptr ds : [esi + 0x24], 0xE0463AFA // checks for "FONT_MW_TITLE"
		je FontScaleCodeCave1Scale2
		cmp dword ptr ds : [esi + 0x24], 0xC7BD87CE // checks for "FONT_MW_CUSTOM_NUMBERS"
		je FontScaleCodeCave1Scale3
		cmp dword ptr ds : [esi + 0x24], 0x01424892 // checks for "TAC_NUMBERS"
		je FontScaleCodeCave1Scale3
		jmp FontScaleCodeCave1None

	FontScaleCodeCave1Scale1:
		mov edi, 0x0100 // 256 FONT_MW_BODY & FONT_ARIAL scale
		mov dword ptr ds : [esp + 0x24], edi
		lea edi, dword ptr ds : [eax - 0x01]
		mov esi, 0x0100 // 256 FONT_MW_BODY & FONT_ARIAL scale
		jmp FontScaleCodeCave1Exit

	FontScaleCodeCave1Scale2:
		mov edi, 0x0200 // 512 FONT_MW_TITLE scale
		mov dword ptr ds : [esp + 0x24] , edi
		lea edi, dword ptr ds : [eax - 0x01]
		mov esi, 0x0200 // 512 FONT_MW_TITLE scale
		jmp FontScaleCodeCave1Exit

	FontScaleCodeCave1Scale3:
		mov edi, 0x0080 // 128 FONT_MW_CUSTOM_NUMBERS & TAC_NUMBERS scale
		mov dword ptr ds : [esp + 0x24] , edi
		lea edi, dword ptr ds : [eax - 0x01]
		mov esi, 0x0040 // 64 FONT_MW_CUSTOM_NUMBERS & TAC_NUMBERS scale
		jmp FontScaleCodeCave1Exit

	FontScaleCodeCave1None:
		movsx edi, word ptr ds : [esi + 0x44]
		mov dword ptr ds : [esp + 0x24], edi
		jmp FontScaleCodeCave1Part2Exit
	}
}

void __declspec(naked) FontScaleCodeCave2()
{
	__asm {
	FontScaleCodeCave2Check1:
		cmp dword ptr ds : [ecx + 0x24], 0xA87927BE // checks for "FONT_ARIAL"
		je FontScaleCodeCave2Scale1
		cmp dword ptr ds : [ecx + 0x24], 0xAB6215C1 // checks for "FONT_ARIAL12"
		je FontScaleCodeCave2Scale1
		cmp dword ptr ds : [ecx + 0x24], 0x545570C6 // checks for "FONT_MW_BODY"
		je FontScaleCodeCave2Scale1
		cmp dword ptr ds : [ecx + 0x24], 0xE0463AFA // checks for "FONT_MW_TITLE"
		je FontScaleCodeCave2Scale2
		cmp dword ptr ds : [ecx + 0x24], 0xC7BD87CE // checks for "FONT_MW_CUSTOM_NUMBERS"
		je FontScaleCodeCave2Scale3
		cmp dword ptr ds : [ecx + 0x24], 0x01424892 // checks for "TAC_NUMBERS"
		je FontScaleCodeCave2Scale3
		jmp FontScaleCodeCave2None

	FontScaleCodeCave2Scale1:
		mov edx, 0x0100 // 256 FONT_MW_BODY & FONT_ARIAL scale
		mov dword ptr ds : [esp + 0x18], edx
		mov eax, 0x0100 // 256 FONT_MW_BODY & FONT_ARIAL scale
		jmp FontScaleCodeCave2Exit
			
	FontScaleCodeCave2Scale2:
		mov edx, 0x0200 // 512 FONT_MW_TITLE scale
		mov dword ptr ds : [esp + 0x18], edx
		mov eax, 0x0200 // 512 FONT_MW_TITLE scale
		jmp FontScaleCodeCave2Exit

	FontScaleCodeCave2Scale3:
		mov edx, 0x0080 // 128 FONT_MW_CUSTOM_NUMBERS & TAC_NUMBERS scale
		mov dword ptr ds : [esp + 0x18], edx
		mov eax, 0x0040 // 64 FONT_MW_CUSTOM_NUMBERS & TAC_NUMBERS scale
		jmp FontScaleCodeCave2Exit

	FontScaleCodeCave2None:
		movsx edx, word ptr ds : [ecx + 0x44]
		mov dword ptr ds : [esp + 0x18], edx
		jmp FontScaleCodeCave2Part2Exit
	}
}

void __declspec(naked) CursorScaleCodeCave1()
{
	__asm
	{
		mov ecx, 0x0010 // 16 Cursor Scale X
		add ecx, edi
		jmp CursorScaleCodeCave1Exit
	}
}

void __declspec(naked) CursorScaleCodeCave2()
{
	__asm
	{
		mov eax, 0x0010 // 16 Cursor Scale X
		add eax, edi
		jmp CursorScaleCodeCave2Exit
	}
}

void __declspec(naked) CursorScaleCodeCave3()
{
	__asm
	{
		mov ecx, 0x0010 // 16 Cursor Scale Y
		add ecx, ebx
		jmp CursorScaleCodeCave3Exit
	}
}

void __declspec(naked) CursorScaleCodeCave4()
{
	__asm
	{
		mov eax, 0x0010 // 16 Cursor Scale Y
		add eax, ebx
		jmp CursorScaleCodeCave4Exit
	}
}

void __declspec(naked) FMVScaleCodeCave()
{
	__asm 
	{
		mov eax, 0x00000400 // 1024 FMV Scale X
		mov edx, 0x00000200 // 512 FMV Scale Y
		mov dword ptr ds : [esp + 0x0C], eax
		mov dword ptr ds : [esp + 0x20], ecx
		jmp FMVScaleCodeCaveExit
	}
}

void Init()
{
	// Read values from .ini
	CIniReader iniReader("NFSMWHDContentSupport.ini");

	// General
	HDFontSupport = iniReader.ReadInteger("GENERAL", "HDFontSupport", 1);
	HDCursorSupport = iniReader.ReadInteger("GENERAL", "HDCursorSupport", 1);
	HDFMVSupport = iniReader.ReadInteger("GENERAL", "HDFMVSupport", 1);

	if (HDFontSupport)
	{
		injector::MakeJMP(0x585D70, FontScaleCodeCave1, true);
		injector::MakeJMP(0x6D14F6, FontScaleCodeCave2, true);
	}

	if (HDCursorSupport)
	{
		injector::MakeJMP(0x57045C, CursorScaleCodeCave1, true);
		injector::MakeJMP(0x570481, CursorScaleCodeCave2, true);
		injector::MakeJMP(0x570496, CursorScaleCodeCave3, true);
		injector::MakeJMP(0x5704BF, CursorScaleCodeCave4, true);
	}

	if (HDFMVSupport)
	{
		injector::MakeJMP(0x599F16, FMVScaleCodeCave, true);
	}
}
	

BOOL APIENTRY DllMain(HMODULE /*hModule*/, DWORD reason, LPVOID /*lpReserved*/)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		uintptr_t base = (uintptr_t)GetModuleHandleA(NULL);
		IMAGE_DOS_HEADER* dos = (IMAGE_DOS_HEADER*)(base);
		IMAGE_NT_HEADERS* nt = (IMAGE_NT_HEADERS*)(base + dos->e_lfanew);

		if ((base + nt->OptionalHeader.AddressOfEntryPoint + (0x400000 - base)) == 0x7C4040) // Check if .exe file is compatible - Thanks to thelink2012 and MWisBest
			Init();

		else
		{
			MessageBoxA(NULL, "This .exe is not supported.\nPlease use v1.3 English speed.exe (5,75 MB (6.029.312 bytes)).", "NFSMW HD Content Support by Aero_", MB_ICONERROR);
			return FALSE;
		}
	}
	return TRUE;	
}