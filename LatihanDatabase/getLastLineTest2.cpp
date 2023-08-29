#include <fstream>
#include <iostream>

int main()
{
  const std::string filename = "test.txt";
  std::ifstream fs;
  fs.open(filename.c_str(), std::fstream::in);
  if(fs.is_open())
  {
    //Got to the last character before EOF
    fs.seekg(-1, std::ios_base::end);
    if(fs.peek() == '\n')
    {
      //Start searching for \n occurrences
      fs.seekg(-1, std::ios_base::cur);
      int i = fs.tellg();
      for(i;i > 0; i--)
      {
        if(fs.peek() == '\n')
        {
          //Found
          fs.get();
          break;
        }
        //Move one character back
        fs.seekg(i, std::ios_base::beg);
      }
    }
    std::string lastline;
    getline(fs, lastline);
    std::cout << lastline << std::endl;
  }
  else
  {
    std::cout << "Could not find end line character" << std::endl;
  }
  return 0;
}