#include <chrono> 
#include <iostream> 
#include <windows.h>
#include <iomanip>
#include <string.h>

using namespace std; 
using namespace std::chrono; 

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

    system(command);

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n\n[Finished in " << fixed << setprecision(2) << duration.count() / 1e+6 << "s]";
 
    return 0; 
} 
