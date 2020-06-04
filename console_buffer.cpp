

#include<windows.h>
#include<stdio.h>

int nScreenWidth = 120;         // Console Screen Size X (columns)
int nScreenHeight = 40; 


int main()
{
	// Create Screen Buffer
	char *screen = new char[nScreenWidth*nScreenHeight];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	

	while(1)
	{

		// Display Frame
		screen[nScreenWidth * nScreenHeight - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);	
	}

	return 0;
}