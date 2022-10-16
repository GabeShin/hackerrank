#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

string parse(vector<string> args);
vector<string> split(string input, char delimiter);
vector<string> splitCamelCase(string input);
string joinStringVector(vector<string> input, string delimiter, bool is_uppercase);
string trim(string s);

int main()
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  string line;
  while (getline(std::cin, line))
  {
    line.erase(remove(line.begin(), line.end(), '\r'), line.end());
    line.erase(remove(line.begin(), line.end(), '\t'), line.end());
    line.erase(remove(line.begin(), line.end(), '\n'), line.end());

    vector<string> args = split(line, ';');
    string result = parse(args);
    result = trim(result);
    std::cout << result << endl;
  }

  return 0;
}

string parse(vector<string> args)
{
  string result_str;
  if (args[0] == "S")
  {
    string output = args[2];
    // split
    if (args[1] == "M")
    {
      // methods. remove ()
      output = output.substr(0, output.size() - 2);
    }
    else if (args[1] == "C")
    {
      // class. lower class the first letter
      output[0] = tolower(output[0]);
    }

    // splitCamelCase
    auto result = splitCamelCase(output);
    result_str = joinStringVector(result, " ", false);
  }
  else if (args[0] == "C")
  {
    // combine
    auto temp = split(args[2], ' ');
    auto output = joinStringVector(temp, "", true);

    if (args[1] == "M")
    {
      // methods. add () at the end
      output += "()";
    }

    if (args[1] != "C")
    {
      // not class. lower class the first letter
      output[0] = tolower(output[0]);
    }

    result_str = output;
  }

  return result_str;
}

vector<string> split(string input, char delimiter)
{
  vector<string> answer;
  stringstream ss(input);
  string temp;

  while (getline(ss, temp, delimiter))
  {
    answer.push_back(temp);
  }
  return answer;
}

vector<string> splitCamelCase(string input)
{
  vector<string> answer;
  int last_index = 0;

  for (int i = 0; i < input.size(); i++)
  {
    if (isupper(input[i]))
    {
      auto temp = input.substr(last_index, i - last_index);
      temp[0] = tolower(temp[0]);
      answer.push_back(temp);
      last_index = i;
    }
  }
  auto temp = input.substr(last_index, input.size() - last_index);
  temp[0] = tolower(temp[0]);
  answer.push_back(temp);

  return answer;
}

string joinStringVector(vector<string> input, string delimiter, bool is_uppercase = false)
{
  string output = "";

  for (int i = 0; i < input.size(); i++)
  {
    string temp = input[i];
    if (i != 0)
      output += delimiter;
    if (is_uppercase)
    {
      temp[0] = toupper(temp[0]);
    }
    output += temp;
  }
  return output;
}

std::string ltrim(const std::string &s)

{
  const std::string WHITESPACE = " \n\r\t\f\v";
  size_t start = s.find_first_not_of(WHITESPACE);
  return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s)
{
  const std::string WHITESPACE = " \n\r\t\f\v";
  size_t end = s.find_last_not_of(WHITESPACE);
  return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(string s)
{
  return rtrim(ltrim(s));
}