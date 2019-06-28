// 28 June 2019
//
// Problem: "PK and interesting language"
// Origin: HackerEarth
// Link: https://www.hackerearth.com/problem/algorithm/pk-and-interesting-language/description/
//
#include <iostream>
#include <vector>

using namespace std;

const int mod = (int)1e9 + 7;
const int alpha = 26;

vector<vector<int>> matmul(const vector<vector<int>> &a, const vector<vector<int>> &b) {
  vector<vector<int>> c(alpha, vector<int> (alpha, 0));

  int n = a.size();
  int p = b.size();
  int m = b[0].size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < p; k++) {
        int now = (a[i][k] * 1ll * b[k][j]) % mod;
        c[i][j] = (c[i][j] + now) % mod;
      }
    }
  }
  return c;
}

vector<vector<int>> matone(int len) {
  vector<vector<int>> one (len, vector<int> (len, 0));

  for (int i = 0; i < len; i++) {
    one[i][i] = 1;
  }
  return one;
}

vector<vector<int>> matpow(vector<vector<int>> a, int n) {
  vector<vector<int>> res = matone(alpha);
  while (n > 0) {
    if (n % 2 == 1)
      res = matmul(res, a);
    a = matmul(a, a);
    n /= 2;
  }
  return res;
}

int solve(vector<vector<int>> can, char ch, int len) {
  vector<vector<int>> result = matpow(can, len - 1);
  int ch_num = ch - 'a';
  int sum = 0;
  for (int i = 0; i < alpha; i++) {
    sum = (sum + result[i][ch_num]) % mod;
  }
  return sum;
}

int slow(vector<vector<int>> can, char ch, int len) {
  vector<vector<int>> dp (alpha, vector<int> (len + 1, 0));
  for (int i = 0; i < alpha; i++)
    dp[i][1] = 1;
  for (int curLen = 2; curLen <= len; curLen++) {
    for (int i = 0; i < alpha; i++) {
      for (int j = 0; j < alpha; j++) {
        // dp[j][curLen] += dp[i][curLen - 1] * can[i][j];
        if (can[i][j] == true) {
          dp[j][curLen] += dp[i][curLen - 1];
          dp[j][curLen] %= mod;
        }
      }
    }
  }
  return dp[ch - 'a'][len];
}

int main () {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  vector<vector<int> > can (alpha, vector<int> (alpha));

  for (int i = 0; i < alpha; i++) {
    for (int j = 0; j < alpha; j++) {
      cin >> can[i][j];
    }
  }

  int tests;
  cin >> tests;
  while (tests--) {
    char ch;
    int len;
    cin >> ch >> len;
    cout << solve(can, ch, len) << "\n";
  }
  return 0;
}
