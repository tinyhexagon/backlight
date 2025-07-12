#include <iostream>
#include <filesystem>
#include <fstream>

int main(int argc, char *argv[])
{
  if (argc > 1)
  {
    if (std::string(argv[1]) == "new")
    {
      std::filesystem::create_directory(std::string(argv[2]));
      std::ofstream mainFile(std::string(argv[2]) + "/main.pixel");
      mainFile << "fn main()\n{\n}";
      return EXIT_SUCCESS;
    }
    else
    {
      std::cerr << "Error: Unknown command.";
      return EXIT_FAILURE;
    }
  }
  else
  {
    std::cerr << "Error: No arguments provided.";
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}