#include <iostream>
#include <chrono>
using namespace std;

class Timer
{
public:
    Timer()
    {
        m_StartTimePoint = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        Stop();
    }

    void Stop()
    {
        std::chrono::time_point<std::chrono::high_resolution_clock> endTimePoint = std::chrono::high_resolution_clock::now();

        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

        long long duration = end - start;
        double microsecond = duration * 0.001;
        double second = duration * 0.000001;

        std::cout << duration << "us" << std::endl;
        std::cout << microsecond << "ms" << std::endl;
        std::cout << second << "s" << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
};

int main()
{
    int n, i, j, c;
    cin >> n;
{
    Timer t;
    for(i = 0; i < n; i++)
    {
        c = 1;
        for(j = 0; j < n-i-1; j++)
        {
            cout << ".";
        }
        for(j = 0; j < i*2+1; j++)
        {
            if(c > 9)
                c = 1;
            cout << c;
            c++;
            if(c > i+1)
            {
                c = 1;
            }
        }
        for(j = 0; j < n-i-1; j++)
        {
            cout << ".";
        }
        cout << endl;
    }

    for(i = 1; i < n; i++)
    {
        c = 1;
        for(j = 0; j < i; j++)
        {
            cout << ".";
        }
        for(j = i; j < n*2-1-i; j++)
        {
            if(c > 9)
                c = 1;
            cout << c;
            c++;
            if(c > n-i)
            {
                c = 1;
            }
        }
        for(j = 0; j < i; j++)
        {
            cout << ".";
        }
        cout << endl;
    }
}
    return 0;
}