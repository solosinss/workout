#include <iostream>
#include <thread>

static const int num_threads = 100;

void call_from_thread(int tid) 
{
	std::cout << "Thread " << tid <<" running" << std::endl;
}

int main()
{
	std::thread t[num_threads];

  for (int i = 0; i<num_threads; i++)
  {
    t[i] = std::thread(call_from_thread, i);
  }

  for (int i = 0; i<num_threads; i++)
    t[i].join();  

	std::cout << "Main thread ending " << std::endl;

	return 0;
}
