#include <chrono> 
#include <iostream> 
#include <windows.h>
#include <iomanip>
#include <string.h>

using namespace std; 
using namespace std::chrono; 

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

int main(int argc, char* argv[]) 
{
    char* command = argv[1];
    for(int i = 2; i < argc; i++)
    {
        strcat(command, " ");
        strcat(command, argv[i]);
    }
    cout << command << endl;
    auto start = high_resolution_clock::now(); 

    int ret = execute_command(command);

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n\n[Finished in " << fixed << setprecision(2) << duration.count() / 1e+6 << "s]" << endl;
    cout << "[Returned " << ret << "]" << endl;
 
    return 0; 
} 
