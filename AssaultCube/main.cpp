#include "includes.h"
#include "proc.h"

using namespace std;

int main()
{
	int health = 9999;
	int armor = 9999;
	int ammo = 9999;
	int fireRate = 0;
	DWORD pID, baseModule, localPlayerPtr, WeaponPtr;

	pID = GetProcessID(L"ac_client.exe");

	baseModule = GetModuleBaseAddress(pID, L"ac_client.exe");


	std::cout << pID << std::endl;
	std::cout << std::hex << baseModule << std::endl;

	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, NULL, pID);

	ReadProcessMemory(handle, (LPCVOID)(baseModule + 0x17E0A8), &localPlayerPtr, sizeof(localPlayerPtr), nullptr);
	ReadProcessMemory(handle, (LPCVOID)(baseModule + 0x0017E0A8), &WeaponPtr, sizeof(WeaponPtr), nullptr);

	while (true)
	{
		//unlimited health
		WriteProcessMemory(handle, (LPVOID)(localPlayerPtr + 0xEC), &health, sizeof(health), nullptr);
		//unlimited armor
		WriteProcessMemory(handle, (LPVOID)(localPlayerPtr + 0xF0), &armor, sizeof(armor), nullptr);

		//unlimited ammo
		//HuntingRifle
		WriteProcessMemory(handle, (LPVOID)(WeaponPtr + 0x130), &ammo, sizeof(ammo), nullptr);
		//Pistole
		WriteProcessMemory(handle, (LPVOID)(WeaponPtr + 0x12C), &ammo, sizeof(ammo), nullptr);
		//AssaultRifle
		WriteProcessMemory(handle, (LPVOID)(WeaponPtr + 0x140), &ammo, sizeof(ammo), nullptr);

		//RapidFire
		WriteProcessMemory(handle, (LPVOID)(WeaponPtr + 0x164), &fireRate, sizeof(fireRate), nullptr);
	}


}