#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
  int hh;
  hh = stoi(s.substr(0, 2));

  if (hh < 12 && s[8] == 'P')
    hh += 12;
  if (hh == 12 && s[8] == 'A')
    hh = 0;

  char buffer[8];
  snprintf(buffer, 8, "%02d", hh);
  string hh_str(buffer);

  string result = hh_str + ":" + s.substr(3, 5);
  cout << result << endl;

  return result;
}

int main()
{
  // ofstream fout(getenv("OUTPUT_PATH"));

  // string s;
  // getline(cin, s);
  string s = "02:05:45PM";

  string result = timeConversion(s);

  // fout << result << "\n";

  // fout.close();

  return 0;
}