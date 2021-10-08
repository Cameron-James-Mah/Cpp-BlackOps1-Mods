#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>

//local player addresses
DWORD Base1 = 0x1A53770;


//Player offsets
DWORD primaryMag = 0x3C0;
DWORD secondaryMag = 0x3D0;
DWORD grenade = 0x3D8;
DWORD attachment = 0x3C8; //Grenade launcher in first campaign mission, not sure if it works for other things yet
DWORD Points = 0x1B88;


//Local player coordinate offsets
DWORD localXCor = 0x24;
DWORD localYCor = 0x28;
DWORD localZCor = 0x2C;

//Addresses
DWORD HP = 0x1A7987C;
DWORD Speed = 0x268EE18;


//2nd Player addresses
DWORD Points2 = 0x1C0C3F0;
DWORD ammo2 = 0x1C0AC40;
DWORD Grenades2 = 0x1C0AC30;


int main() {

	HWND hwnd = FindWindowA(0, ("Call of Duty®: BlackOps"));
	if (hwnd == 0) {
		std::cout << "Can't find window" << std::endl;
	}
	else {
		DWORD pid;
		GetWindowThreadProcessId(hwnd, &pid);
		HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
		DWORD dynamicPlayer;
		ReadProcessMemory(pHandle, LPCVOID(Base1), &dynamicPlayer, sizeof(dynamicPlayer), 0);

		int modPrimaryMag = 30;
		int modSecondaryMag;
		int modGrenade = 4;
		int modAttachment = 5;
		int modHp = 1000;
		int modPoints = 9999;
		int modSpd = 500;
		
		

		while (true) {
			WriteProcessMemory(pHandle, LPVOID(dynamicPlayer + primaryMag), &modPrimaryMag, sizeof(modPrimaryMag), 0);
			WriteProcessMemory(pHandle, LPVOID(dynamicPlayer + grenade), &modGrenade, sizeof(modGrenade), 0);
			WriteProcessMemory(pHandle, LPVOID(dynamicPlayer + secondaryMag), &modPrimaryMag, sizeof(modSecondaryMag), 0);
			WriteProcessMemory(pHandle, LPVOID(dynamicPlayer + attachment), &modAttachment, sizeof(modAttachment), 0);
			WriteProcessMemory(pHandle, LPVOID(HP), &modHp, sizeof(modHp), 0);
			WriteProcessMemory(pHandle, LPVOID(dynamicPlayer + Points), &modPoints, sizeof(modPoints), 0);
			WriteProcessMemory(pHandle, LPVOID(Speed), &modSpd, sizeof(modSpd), 0);

			//2P
			WriteProcessMemory(pHandle, LPVOID(Points2), &modPoints, sizeof(modPoints), 0);
			WriteProcessMemory(pHandle, LPVOID(ammo2), &modPrimaryMag, sizeof(modPrimaryMag), 0);
			WriteProcessMemory(pHandle, LPVOID(Grenades2), &modGrenade, sizeof(modGrenade), 0);

			
			
		}
	}



}