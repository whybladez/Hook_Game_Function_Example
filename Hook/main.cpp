#define _CRT_SECURE_NO_WARNINGS

#include "hook/hook.h"
#include <Windows.h>
#include <process.h>
#include <string>
#include <iostream>

DWORD pSAMP = NULL;

struct CEntity;
struct CColPoint;

class CVector {
public:
	float x, y, z;
};

struct CWeapon;

class CTaskSimpleUseGun {};
using func_t = void(__thiscall*)(CWeapon*, CEntity *, CVector *, CVector *, CEntity *, CVector *, CVector *);
func_t func = reinterpret_cast<func_t>(0x742300);

void hooked(CWeapon*& pWeapon, CEntity*& pFiringEntity, CVector*& pvecOrigin, CVector*& pvecTarget, CEntity*& pTargetEntity, CVector*& pvec_1, CVector*& pvec_2)
{

}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (hModule)
	{
		if (dwReason == DLL_PROCESS_ATTACH)
		{
			while (!pSAMP)
				pSAMP = (DWORD)GetModuleHandle("samp.dll");

			AllocConsole();
			freopen("CONOUT$", "w", stdout);

			static hook test(func, hooked);
		}
	}

	return true;
}