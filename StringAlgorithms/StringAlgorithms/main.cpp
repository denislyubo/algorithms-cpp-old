#include <string>
#include <algorithm>
#include <iostream> 
#include <cctype>
#include <time.h>

void GenerateString(size_t length, std::string &str)
{
  srand(time(0));
  
  auto randchar = []() -> char
  {
    const char charset[] =
      "0123456789"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "abcdefghijklmnopqrstuvwxyz";
    const size_t max_index = (sizeof(charset) - 1);
    return charset[rand() % max_index];
  };
  str.assign(length, 0);
  std::generate_n(str.begin(), length, randchar);
}

void SolveString(std::string &input, std::string &output)
{
  std::string::const_iterator begIndex = input.begin(), endIndex = input.end();
  bool isUpperLetterExist = false;
  int curLength = 0, length = 0;

  for (std::string::const_iterator curIt = input.begin(); curIt != input.end(); curIt++)
  {
    if (std::isdigit(*curIt))
      curIt++;

    if (std::isalpha(*curIt))
    {
      begIndex = curIt;
      curLength++;
      if (std::isupper(*curIt))
        isUpperLetterExist = true;
    }

    do
    {
      curIt++;
      endIndex = curIt;

      if (curIt != input.end())
      {
        if (std::isdigit(*curIt))
        {
          if (curLength > length && isUpperLetterExist)
          {
            output.resize(0);
            output.insert(output.begin(), begIndex, endIndex);
            length = curLength;
          }
          curLength = 0;
          break;
        }
        else if (!isUpperLetterExist)
        {
          if (std::isupper(*curIt))
            isUpperLetterExist = true;
        }

        curLength++;
      }
      else
      {
        if (curLength > length && isUpperLetterExist)
        {
          output.resize(0);
          output.insert(output.begin(), begIndex, endIndex);
          length = curLength;
        }
        curLength = 0;
        return;
      }
    } 
    while (true);
  }

}

void SolveStringOptimal(std::string &input, std::string &output)
{
  std::string::const_iterator begIndex = input.end(), endIndex = input.end();
  bool isUpperLetterExist = false, startWord = false;
  int curLength = 0, length = 0;

  std::string::const_iterator curIt = input.begin();

  while (curIt != input.end())
  {
    if (std::isdigit(*curIt))
    {
      if (startWord)
      {
        endIndex = curIt;
        if (curLength > length && isUpperLetterExist)
        {
          output.resize(0);
          output.insert(output.begin(), begIndex, endIndex);
          length = curLength;
        }
        curLength = 0;
        startWord = false;
      }
      curIt++;
      continue;
    }

    if (std::isalpha(*curIt))
    {
      if (!startWord)
      {
        begIndex = curIt;
        startWord = true;
      }

      curLength++;

      if (std::isupper(*curIt))
        isUpperLetterExist = true;

      curIt++;
    }
  }

  if (startWord)
  {
    endIndex = curIt;
    if (curLength > length && isUpperLetterExist)
    {
      output.resize(0);
      output.insert(output.begin(), begIndex, endIndex);
      length = curLength;
    }
    startWord = false;
  }
}

int SolveString(std::string &input)
{
  std::string::const_iterator curIt = input.begin();
  
  int maxLength = 0, currentLength = 0;
  bool isUpperLetterExist = false;

  do
  {
    if (curIt == input.end())
    {
      if (currentLength > maxLength && isUpperLetterExist)
        maxLength = currentLength;
      break;
    }

    if (std::isalpha(*curIt))
    {
      if (std::isupper(*curIt))
        isUpperLetterExist = true;
        
      currentLength++;
    }

    if (std::isdigit(*curIt))
    {
      if (currentLength > maxLength && isUpperLetterExist)
        maxLength = currentLength;

      currentLength = 0;
      isUpperLetterExist = false;
    }

    curIt++;
  } 
  while (true);

  return maxLength;
}

int main(int argc, char *argv[])
{
  int length = 200;
  std::string str, resStr;

  GenerateString(length, str);

  //SolveString(str, resStr);
  
  SolveStringOptimal(str, resStr);
  
  std::cout << "My array contains such substring: ";
  for (int i = 0, len = resStr.length(); i < len; ++i)
    std::cout << ' ' << resStr[i];
  std::cout << '\n';

  std::cout << SolveString(str) << '\n';

  int a;
  std::cin >> a;

  return 0;
}