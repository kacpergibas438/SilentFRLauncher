#include <Windows.h>

VOID startup(LPCTSTR lpApplicationName)
{
	// https://stackoverflow.com/questions/15435994/how-do-i-open-an-exe-from-another-c-exe/15440094

	// additional information
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	// set the size of the structures
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// start the program up
	CreateProcess(
		lpApplicationName, // the path
		NULL, // Command line
		NULL, // Process handle not inheritable
		NULL, // Thread handle not inheritable
		FALSE, // Set handle inheritance to FALSE
		0, // No creation flags
		NULL, // Use parent's environment block
		NULL, // Use parent's starting directory 
		&si, // Pointer to STARTUPINFO structure
		&pi // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
	);
	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

int main(int argc, char* argv[])
{
	startup(L"FreeRunning.exe");
	return 0;
}
