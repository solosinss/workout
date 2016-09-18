#include <iostream>
using namespace std;
class Computer
{
public:
  virtual void Run() = 0;
  virtual void Stop() = 0;

  virtual ~Computer() {};
};

class Laptop: public Computer
{
public:
void Run() override {cout << "laptop is running\n"; mHibernating = false;};
  void Stop() override {cout << "laptop is stopped\n"; mHibernating = true;};

  virtual ~Laptop(){};
private:
  bool mHibernating;
};

class Desktop: public Computer
{
public:
  void Run() override {cout << "desktop is running\n"; mOn = false;};
  void Stop() override {cout << "desktop is stopped\n"; mOn = true;};

  virtual ~Desktop(){};
private:
  bool mOn;
};

class ComputerFactory
{
public:
  static Computer * NewComputer(const std::string &description)
  {
    if (description == "laptop")
      return new Laptop;
    if (description == "desktop")
      return new Desktop;
    return nullptr;
  }
};
int main()
{
  Computer * pc1;
  Computer * pc2;

  pc1 = ComputerFactory::NewComputer("laptop");
  pc2 = ComputerFactory::NewComputer("desktop");

  pc1->Run();
  pc1->Stop();

  pc2->Run();
  pc2->Stop();

  return 0;  
}
