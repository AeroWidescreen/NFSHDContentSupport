#include "stdafx.h"
#include "stdio.h"
#include <windows.h>
#include "..\includes\injector\injector.hpp"
#include <cstdint>
#include "..\includes\IniReader.h"
#include <d3d9.h>
#include "..\settings.h"

DWORD FontScaleCodeCave1Exit = 0x700620;
DWORD FontScaleCodeCave1Exit2 = 0x70061C;
DWORD FontScaleCodeCave2Exit = 0x5A175F;
DWORD FontScaleCodeCave2Exit2 = 0x5A1738;
DWORD FontScaleCodeCave3Exit = 0x5A199F;
DWORD FontScaleCodeCave3Exit2 = 0x5A1988;
DWORD CursorScaleCodeCave1Exit = 0x5A0C2A;
DWORD CursorScaleCodeCave2Exit = 0x5A0C40;
DWORD CursorScaleCodeCave3Exit = 0x5A0C50;
DWORD CursorScaleCodeCave4Exit = 0x5A0C67;

void __declspec(naked) FontScaleCodeCave1()
{
	__asm {
	FontScaleCodeCave1Check1:
		cmp dword ptr ds : [esi + 0x0C], 0x94AF4029 // checks for "FONT_NFS_BODY"
		je FontScaleCodeCave1Scale1
		cmp dword ptr ds : [esi + 0x0C], 0x94B51F10 // checks for "FONT_NFS_MENU"
		je FontScaleCodeCave1Scale1
		cmp dword ptr ds : [esi + 0x0C], 0x2AB5F1C2 // checks for "FONT_NFS_DEBUG"
		je FontScaleCodeCave1Scale1
		cmp dword ptr ds : [esi + 0x0C], 0xEA23AE36 // checks for "FONT_NFS_TACH_NUMBERS"
		je FontScaleCodeCave1Scale2
		cmp dword ptr ds : [esi + 0x0C], 0x2BD9F6BD // checks for "FONT_NFS_TITLE"
		je FontScaleCodeCave1Scale3
		cmp dword ptr ds : [esi + 0x0C], 0xD51E0499 // checks for "FONT_NFS_FX"
		je FontScaleCodeCave1Scale4
		jmp FontScaleCodeCave1None

	FontScaleCodeCave1Scale1:
		mov edi, 0x0100 // 256 FONT_NFS_BODY, FONT_NFS_MENU, FONT_NFS_DEBUG
		mov dword ptr ds : [esp + 0x08], edi
		mov edi, 0x0100 // 256 FONT_NFS_BODY, FONT_NFS_MENU, FONT_NFS_DEBUG
		test edx, edx
		jmp FontScaleCodeCave1Exit

	FontScaleCodeCave1Scale2:
		mov edi, 0x0080 // 128 FONT_NFS_TACH_NUMBERS
		mov dword ptr ds : [esp + 0x08], edi
		mov edi, 0x0080 // 128 FONT_NFS_TACH_NUMBERS
		test edx, edx
		jmp FontScaleCodeCave1Exit

	FontScaleCodeCave1Scale3:
		mov edi, 0x0200 // 512 FONT_NFS_TITLE
		mov dword ptr ds : [esp + 0x08], edi
		mov edi, 0x0100 // 256 FONT_NFS_TITLE
		test edx, edx
		jmp FontScaleCodeCave1Exit

	FontScaleCodeCave1Scale4:
		mov edi, 0x0400 // 1024 FONT_NFS_FX
		mov dword ptr ds : [esp + 0x08], edi
		mov edi, 0x0200 // 512 FONT_NFS_FX
		test edx, edx
		jmp FontScaleCodeCave1Exit

	FontScaleCodeCave1None:
		movsx edi, word ptr ds : [esi + 0x28]
		mov dword ptr ds : [esp + 0x08], edi
		test edx, edx
		jmp FontScaleCodeCave1Exit2
	}
}

void __declspec(naked) FontScaleCodeCave2()
{
	__asm {
	FontScaleCodeCave2Check1:
		cmp dword ptr ds : [edx + 0x0C], 0x94AF4029 // checks for "FONT_NFS_BODY"
		je FontScaleCodeCave2Scale1
		cmp dword ptr ds : [edx + 0x0C], 0x94B51F10 // checks for "FONT_NFS_MENU"
		je FontScaleCodeCave2Scale1
		cmp dword ptr ds : [edx + 0x0C], 0x2AB5F1C2 // checks for "FONT_NFS_DEBUG"
		je FontScaleCodeCave2Scale1
		cmp dword ptr ds : [edx + 0x0C], 0xEA23AE36 // checks for "FONT_NFS_TACH_NUMBERS"
		je FontScaleCodeCave2Scale2
		cmp dword ptr ds : [edx + 0x0C], 0x2BD9F6BD // checks for "FONT_NFS_TITLE"
		je FontScaleCodeCave2Scale3
		cmp dword ptr ds : [edx + 0x0C], 0xD51E0499 // checks for "FONT_NFS_FX"
		je FontScaleCodeCave2Scale4
		jmp FontScaleCodeCave2None

	FontScaleCodeCave2Scale1:
		mov edi, 0x0100 // 256 FONT_NFS_BODY, FONT_NFS_MENU, FONT_NFS_DEBUG
		mov dword ptr ds : [esp + 0x24], edi
		mov dword ptr ds : [esp + 0x14], esi
		add esi, 0xFFFFFFFF
		fild dword ptr ds : [esp + 0x24]
		mov dword ptr ds : [esp + 0x24], esi
		movzx edi, byte ptr[eax + 02]
		fstp dword ptr ds : [esp + 0x18]
		fild dword ptr ds : [esp + 0x24]
		mov dword ptr ds : [esp + 0x24], edi
		fld dword ptr ds : [esp + 0x18]
		mov edx, 0x0100 // 256 FONT_NFS_BODY, FONT_NFS_MENU, FONT_NFS_DEBUG
		jmp FontScaleCodeCave2Exit

	FontScaleCodeCave2Scale2:
		mov edi, 0x0080 // 128 FONT_NFS_TACH_NUMBERS
		mov dword ptr ds : [esp + 0x24] , edi
		mov dword ptr ds : [esp + 0x14] , esi
		add esi, 0xFFFFFFFF
		fild dword ptr ds : [esp + 0x24]
		mov dword ptr ds : [esp + 0x24] , esi
		movzx edi, byte ptr[eax + 02]
		fstp dword ptr ds : [esp + 0x18]
		fild dword ptr ds : [esp + 0x24]
		mov dword ptr ds : [esp + 0x24] , edi
		fld dword ptr ds : [esp + 0x18]
		mov edx, 0x0080 // 128 FONT_NFS_TACH_NUMBERS
		jmp FontScaleCodeCave2Exit

	FontScaleCodeCave2Scale3:
		mov edi, 0x0200 // 512 FONT_NFS_TITLE
		mov dword ptr ds : [esp + 0x24] , edi
		mov dword ptr ds : [esp + 0x14] , esi
		add esi, 0xFFFFFFFF
		fild dword ptr ds : [esp + 0x24]
		mov dword ptr ds : [esp + 0x24] , esi
		movzx edi, byte ptr[eax + 02]
		fstp dword ptr ds : [esp + 0x18]
		fild dword ptr ds : [esp + 0x24]
		mov dword ptr ds : [esp + 0x24] , edi
		fld dword ptr ds : [esp + 0x18]
		mov edx, 0x0100 // 256 FONT_NFS_TITLE
		jmp FontScaleCodeCave2Exit

	FontScaleCodeCave2Scale4:
		mov edi, 0x0400 // 1024 FONT_NFS_FX
		mov dword ptr ds : [esp + 0x24] , edi
		mov dword ptr ds : [esp + 0x14], esi
		add esi, 0xFFFFFFFF
		fild dword ptr ds : [esp + 0x24]
		mov dword ptr ds : [esp + 0x24], esi
		movzx edi, byte ptr[eax + 02]
		fstp dword ptr ds : [esp + 0x18]
		fild dword ptr ds : [esp + 0x24]
		mov dword ptr ds : [esp + 0x24], edi
		fld dword ptr ds : [esp + 0x18]
		mov edx, 0x0200 // 512 FONT_NFS_FX
		jmp FontScaleCodeCave2Exit

	FontScaleCodeCave2None:
		movsx edi, word ptr ds : [edx + 0x28]
		mov dword ptr ds : [esp + 0x24], edi
		jmp FontScaleCodeCave2Exit2
	}
}

void __declspec(naked) FontScaleCodeCave3()
{
	__asm {
	FontScaleCodeCave3Check1:
		cmp dword ptr ds : [edx + 0x0C], 0x94AF4029 // checks for "FONT_NFS_BODY"
		je FontScaleCodeCave3Scale1
		cmp dword ptr ds : [edx + 0x0C], 0x94B51F10 // checks for "FONT_NFS_MENU"
		je FontScaleCodeCave3Scale1
		cmp dword ptr ds : [edx + 0x0C], 0x2AB5F1C2 // checks for "FONT_NFS_DEBUG"
		je FontScaleCodeCave3Scale1
		cmp dword ptr ds : [edx + 0x0C], 0xEA23AE36 // checks for "FONT_NFS_TACH_NUMBERS"
		je FontScaleCodeCave3Scale2
		cmp dword ptr ds : [edx + 0x0C], 0x2BD9F6BD // checks for "FONT_NFS_TITLE"
		je FontScaleCodeCave3Scale3
		cmp dword ptr ds : [edx + 0x0C], 0xD51E0499 // checks for "FONT_NFS_FX"
		je FontScaleCodeCave3Scale4
		jmp FontScaleCodeCave3None

	FontScaleCodeCave3Scale1 :
		mov edi, 0x0100 // 256 FONT_NFS_BODY, FONT_NFS_MENU, FONT_NFS_DEBUG
		mov dword ptr ds : [esp + 0x18], esi
		mov dword ptr ds : [esp + 0x24], edi
		add esi, 0xFFFFFFFF
		movzx edi, byte ptr ds : [eax + 0x02]
		fild dword ptr ds : [esp + 0x24]
		mov dword ptr ds : [esp + 0x24], esi
		mov edx, 0x0100 // 256 FONT_NFS_BODY, FONT_NFS_MENU, FONT_NFS_DEBUG
		jmp FontScaleCodeCave3Exit

	FontScaleCodeCave3Scale2 :
		mov edi, 0x0080 // 128 FONT_NFS_TACH_NUMBERS
		mov dword ptr ds : [esp + 0x18] , esi
		mov dword ptr ds : [esp + 0x24] , edi
		add esi, 0xFFFFFFFF
		movzx edi, byte ptr ds : [eax + 0x02]
		fild dword ptr ds : [esp + 0x24]
		mov dword ptr ds : [esp + 0x24] , esi
		mov edx, 0x0080 // 128 FONT_NFS_TACH_NUMBERS
		jmp FontScaleCodeCave3Exit

	FontScaleCodeCave3Scale3:
		mov edi, 0x0200 // 512 FONT_NFS_TITLE
		mov dword ptr ds : [esp + 0x18] , esi
		mov dword ptr ds : [esp + 0x24] , edi
		add esi, 0xFFFFFFFF
		movzx edi, byte ptr ds : [eax + 0x02]
		fild dword ptr ds : [esp + 0x24]
		mov dword ptr ds : [esp + 0x24] , esi
		mov edx, 0x0100 // 256 FONT_NFS_TITLE
		jmp FontScaleCodeCave3Exit

	FontScaleCodeCave3Scale4 :
		mov edi, 0x0400 // 1024 FONT_NFS_FX
		mov dword ptr ds : [esp + 0x18] , esi
		mov dword ptr ds : [esp + 0x24] , edi
		add esi, 0xFFFFFFFF
		movzx edi, byte ptr ds : [eax + 0x02]
		fild dword ptr ds : [esp + 0x24]
		mov dword ptr ds : [esp + 0x24] , esi
		mov edx, 0x0200 // 512 FONT_NFS_FX
		jmp FontScaleCodeCave3Exit

	FontScaleCodeCave3None :
		movsx edi, word ptr ds : [edx + 0x28]
		mov dword ptr ds : [esp + 0x18], esi
		jmp FontScaleCodeCave2Exit2
	}
}


void __declspec(naked) CursorScaleCodeCave1()
{
	__asm
	{
		mov edx, 0x0010 // 16 Cursor Scale X
		add edx, edi
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
		mov edx, 0x0010 // 16 Cursor Scale Y
		xorps xmm1, xmm1
		jmp CursorScaleCodeCave4Exit
	}
}

void Init()
{
	// Read values from .ini
	CIniReader iniReader("NFSPSHDContentSupport.ini");

	// General
	HDFontSupport = iniReader.ReadInteger("GENERAL", "HDFontSupport", 1);
	HDCursorSupport = iniReader.ReadInteger("GENERAL", "HDCursorSupport", 1);

	if (HDFontSupport)
	{
		injector::MakeJMP(0x700614, FontScaleCodeCave1, true);
		injector::MakeJMP(0x5A1730, FontScaleCodeCave2, true);
		injector::MakeJMP(0x5A1980, FontScaleCodeCave3, true);
	}

	if (HDCursorSupport)
	{
		injector::MakeJMP(0x5A0C24, CursorScaleCodeCave1, true);
		injector::MakeJMP(0x5A0C3A, CursorScaleCodeCave2, true);
		injector::MakeJMP(0x5A0C4A, CursorScaleCodeCave3, true);
		injector::MakeJMP(0x5A0C60, CursorScaleCodeCave4, true);
	}
}
	

BOOL APIENTRY DllMain(HMODULE /*hModule*/, DWORD reason, LPVOID /*lpReserved*/)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		uintptr_t base = (uintptr_t)GetModuleHandleA(NULL);

		if (strstr((const char*)(base + (0xA49742 - base)), "ProStreet08Release.exe"))
			Init();

		else
		{
			MessageBoxA(NULL, "This .exe is not supported.\nPlease use a NOCD v1.1 NFS.exe.", "NFSPS HD Content Support by Aero_", MB_ICONERROR);
			return FALSE;
		}
	}
	return TRUE;

}