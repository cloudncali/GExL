#include <iostream>
#include <GExL/utils/StringUtil.hpp>

int main(int argc, char* argv[])
{
  std::string anString;
  std::cout << "Input String:";
  std::cin >> anString;

  std::cout << "Lowercase String:" << GExL::StringToLowercase(anString) << std::endl;
  std::cout << "Uppercase String:" << GExL::StringToUppercase(anString) << std::endl;
  
  std::system("PAUSE");
  return 0;
}