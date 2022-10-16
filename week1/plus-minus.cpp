#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr)
{
  float len_pos_val = 0, len_neg_val = 0, len_zero_val = 0;
  float length = arr.size();

  for (int i = 0; i < length; i++)
  {
    int val = arr[i];
    len_zero_val += (val == 0);
    len_pos_val += (val > 0);
    len_neg_val += (val < 0);
  }

  float total_length = len_neg_val + len_pos_val + len_zero_val;
  printf("%0.06lf\n%0.06lf\n%0.06lf\n", len_pos_val / length, len_neg_val / length, len_zero_val / length);
}

int main()
{
  string n_temp;
  // getline(cin, n_temp);

  // int n = stoi(ltrim(rtrim(n_temp)));

  // string arr_temp_temp;
  // getline(cin, arr_temp_temp);

  // vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<string> arr_temp{"1", "1", "0", "-1", "-1"};
  int n = 5;

  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  plusMinus(arr);

  return 0;
}

string ltrim(const string &str)
{
  string s(str);

  s.erase(
      s.begin(),
      find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str)
{
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}

vector<string> split(const string &str)
{
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos)
  {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
