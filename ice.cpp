/* ice => Intelligent C++ Executor */
/* This program is created by Shanto Noor */

#include <chrono> 
#include <iostream> 
#include <windows.h>
#include <iomanip>
#include <sstream>
// #include <string.h>
// #include <conio.h>
// #include <algorithm>

// std::string gppCommand = "g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -O2 -Wno-unused-result";

int findLastPosition(std::string str, char x)
{
    int pos = 0;
    for(unsigned int i = 0; i < str.size(); i++)
    {
        if(str[i] == x)
            pos = i;
    }
    return pos;
}

void copyStr(std::string str, char arr[])
{
    unsigned int i;
    for(i = 0; i < str.size(); i++)
        arr[i] = str[i];
    arr[i] = '\0';
}

void printDashLine(std::string str)
{
	int dasNumber = 72 - str.size();
	if(dasNumber & 1)
	{
		dasNumber = dasNumber/2;
		for(int i = 0; i < dasNumber; i++)
			printf("-");
		printf("[");
		printf(str.c_str());
		printf("]");
		for(int i = 0; i < dasNumber+1; i++)
			printf("-");
	}
	else
	{
		dasNumber = dasNumber/2;
		for(int i = 0; i < dasNumber; i++)
			printf("-");
		printf("[");
		printf(str.c_str());
		printf("]");
		for(int i = 0; i < dasNumber; i++)
			printf("-");
	}
}

int execute_command(char *cmdline)
{
    SetConsoleTitle(cmdline);

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    // Start the child process.
    CreateProcess( NULL, TEXT(cmdline), NULL, NULL, FALSE, 0,
                   NULL, NULL, &si, &pi );

    // Wait until child process exits.
    WaitForSingleObject( pi.hProcess, INFINITE );

    // Get the return value of the child process
    DWORD ret;
    GetExitCodeProcess( pi.hProcess, &ret );

    // Close process and thread handles.
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );

    return ret;
}

std::string tolower(std::string str)
{
	for(unsigned int i = 0; i < str.size(); i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] |= 32; 
	}
	return str;
}


int compile(std::string str)
{
	str = "\"g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -O2 -Wno-unused-result \"" + str + ".cpp\" -o \"" + str + ".exe\"\"";
	// str = "\"" + gppCommand + " " + "\"" + str + ".cpp" + "\"" + " -o " + "\"" + str + ".exe" + "\"" + "\"";

	printDashLine("Compiling!"); printf("\n"); printf("\n");
	if(system(str.c_str()) == 0)
		return 1;
	else
	{
		printDashLine("End!"); printf("\n");
    	printDashLine("Compile Time ERROR"); printf("\n"); printf("\n");
    	system("pause");
		return 0;
	}
}

int main(int argc, char** argv) 
{
	printDashLine("Intelligent C++ Executor (ice) by"); printf("\n");
	printDashLine("Shanto Noor"); printf("\n"); printf("\n");

    if (argc < 2)
    {
        printf("example: ice \"filename.cpp\" or \"filename.exe\" <args ...>\n");
        return 1;
    }
    
    std::string strcmd = argv[1];
    for(int i = 2; i < argc; i++)
    {
        strcmd += " ";
        strcmd += argv[i];
    }
    
    int lastPos = findLastPosition(strcmd, '\\');
    if(lastPos)
    {
        strcmd.erase(0, lastPos+1);
        strcmd.shrink_to_fit();
    }

    // filetype checking
    lastPos = findLastPosition(strcmd, '.');
    std::string filetype = tolower(strcmd.substr(lastPos+1, 3));
    std::string filename = strcmd.substr(0, lastPos);
    // filename = "\"" + filename + "\"";

    std::string das = " ";
    lastPos = findLastPosition(strcmd, '-');
    if(lastPos)
    	das = strcmd.substr(lastPos, strcmd.size()-lastPos);

    if(filetype == "cpp")
    {
    	if(compile(filename) && das == " ")
    		strcmd = filename + ".exe";
    	else if(compile(filename) && das == "d")
    		strcmd = filename + ".exe" + " && del " + filename + ".exe";
	    else
	    	return 1;
    }

	char cmdline[strcmd.size()+1];
    copyStr(strcmd, cmdline);

    // formatiing output
    std::string s = "Start << " + strcmd;
    printDashLine(s); printf("\n");
    printf("\n");
    printf("\n");

    // start timer
    std::chrono::time_point<std::chrono::high_resolution_clock> startTimePoint = std::chrono::high_resolution_clock::now();

    // running the process
    int ret = execute_command(cmdline);

    // end timer
    std::chrono::time_point<std::chrono::high_resolution_clock> endTimePoint = std::chrono::high_resolution_clock::now();

	long long start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimePoint).time_since_epoch().count();
	long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

	long long nanosecond = end - start;
	double microsecond = nanosecond * 0.001;
	double second = nanosecond * 0.000001;

	std::stringstream ss;
    ss << strcmd << " >> return " << ret << " (0x" << std::hex << ret << std::dec << ")" << '\n';
    ss << "Finished in " << std::fixed << std::setprecision(2) << second << "s | " << std::fixed << std::setprecision(2) << microsecond << "us" << std::endl;


    printf("\n");
    printf("\n");
    while(getline(ss, s))
    {
    	printDashLine(s); printf("\n");
    }

    printf("\n");
    // printf("Press any key to continue . . .");
    // getch();       /*   include <conio.h>   
    system("pause");

    return ret;
} 