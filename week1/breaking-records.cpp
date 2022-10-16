#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'breakingRecords' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY scores as parameter.
 */

vector<int> breakingRecords(vector<int> scores)
{
  int break_max_count = 0, break_min_count = 0;
  int length = scores.size();
  int max_score = scores[0], min_score = scores[0];
  for (auto score : scores)
  {
    if (score > max_score)
    {
      break_max_count++;
      max_score = score;
    }

    if (score < min_score)
    {
      break_min_count++;
      min_score = score;
    }
  }

  return vector<int>{break_max_count, break_min_count};
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string scores_temp_temp;
  getline(cin, scores_temp_temp);

  vector<string> scores_temp = split(rtrim(scores_temp_temp));

  vector<int> scores(n);

  for (int i = 0; i < n; i++)
  {
    int scores_item = stoi(scores_temp[i]);

    scores[i] = scores_item;
  }

  vector<int> result = breakingRecords(scores);

  for (size_t i = 0; i < result.size(); i++)
  {
    fout << result[i];

    if (i != result.size() - 1)
    {
      fout << " ";
    }
  }

  fout << "\n";

  fout.close();

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