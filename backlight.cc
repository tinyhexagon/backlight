#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[])
{
  if (argc > 1)
  {

    std::string command = std::string(argv[1]);
    std::string arg2;
    std::string mainProjectDirectoryName;
    if (argc > 2)
    {
      arg2 = std::string(argv[2]);
    }

    if (command == "new")
    {
      mainProjectDirectoryName = arg2;
      std::filesystem::create_directory(mainProjectDirectoryName);
      std::filesystem::create_directory(mainProjectDirectoryName + "/imports");
      std::filesystem::create_directory(mainProjectDirectoryName + "/src");
      std::ofstream mainFile(mainProjectDirectoryName + "/src/main.pixel");
      mainFile << "fn main()\n{\n}";
      return EXIT_SUCCESS;
    }
    else if (command == "build")
    {
      if (std::filesystem::exists(mainProjectDirectoryName + "src/main.pixel"))
      {
        std::string compileCommand = "pixelc" + mainProjectDirectoryName + "src/main.pixel";
        system(compileCommand.c_str());
      }
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