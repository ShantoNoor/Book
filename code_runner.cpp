#include <chrono> 
#include <iostream> 
#include <windows.h>
#include <iomanip>
#include <string.h>
#include <sstream>

void printDashLine(std::string str)
{
	int dasNumber = 38 - str.size();
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

bool hasSpaces(const char* str)
{
    char last = 0;
    while (str && *str)
    {
        if ((*str == ' ' || *str == '\t') && last != '\\')
            return true;
        last = *str++;
    }
    return false;
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

int main(int argc, char** argv) 
{
    if (argc < 2)
    {
        printf("Usage: cpp_runner \"filename.cpp\" <args ...>\n");
        return 1;
    }

    // count size of arguments
    size_t fullsize = 0;
    for (int i = 1; i < argc; ++i)
    {
        fullsize += strlen(argv[i]);
    }
    // add some slack for spaces between args plus quotes around executable
    fullsize += argc + 32;

    char* cmdline = new char[fullsize];
    memset(cmdline, 0, fullsize);

    // 1st arg (executable) enclosed in quotes to support filenames with spaces
    bool sp = hasSpaces(argv[1]);
    if (sp)
        strcat(cmdline, "\"");
    strcat(cmdline, argv[1]);
    if (sp)
        strcat(cmdline, "\"");
    strcat(cmdline, " ");

    for (int i = 2; i < argc; ++i)
    {
        sp = hasSpaces(argv[i]);
        if (sp)
            strcat(cmdline, "\"");
        strcat(cmdline, argv[i]);
        if (sp)
            strcat(cmdline, "\"");
        strcat(cmdline, " ");
    }
    
    
    // formatiing output
	std::stringstream ss;
    std::string s;
    ss << "Start << " << cmdline << ">>" << std::endl;
    while(getline(ss, s))
    {
    	printDashLine(s.c_str());
    	printf("\n");
    }
    ss.clear();

    // start timer
    std::chrono::time_point<std::chrono::high_resolution_clock> startTimePoint = std::chrono::high_resolution_clock::now();

    // running the process
    int ret = execute_command(cmdline);

    // end timer
    std::chrono::time_point<std::chrono::high_resolution_clock> endTimePoint = std::chrono::high_resolution_clock::now();

	long long start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimePoint).time_since_epoch().count();
	long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

	long long nanosecond = end - start;
	//double microsecond = nanosecond * 0.001;
	double second = nanosecond * 0.000001;

    
    ss << cmdline << ">> return " << ret << std::endl;
    ss << "Finished in " << std::fixed << std::setprecision(2) << second << "s" << std::endl;

    while(getline(ss, s))
    {
    	printDashLine(s.c_str());
    	printf("\n");
    }
 
    delete[] cmdline;
    return ret;
} 
