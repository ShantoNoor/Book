#include <iostream>
#include <memory>

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
	int value = 0;
	{
		Timer timer;
		for(int i = 0; i < 1000000; i++)
		{
			value += 2;
		}
	}
	std::cout << value << std::endl;

	return 0;
}