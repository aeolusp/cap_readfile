#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int main (int argc, char* argv[])
{
  std::ifstream file(argv[1]);
  if (!file.good())
    std::cout << "Error: " << strerror(errno) << std::endl;

  std::string str;
  while (std::getline(file, str)) {
    std::cout << str << "\n";
  }

  return 0;
}
