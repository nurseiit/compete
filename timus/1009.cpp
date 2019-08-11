#include <cstdio>
#include <vector>
using namespace std;

typedef long long int ll;

vector<vector<ll>> dp;

ll solve(int n, int k, int pos = 0, int last = 0) {
   if (pos == n) return 1;
   ll &res = dp[pos][last];
   if (res != -1) return res;
   res = 0;
   for (int next = (last == 0); next < k; next++)
     res += solve(n, k, pos + 1, next);
   return res;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  dp = vector<vector<ll>>(n + 1, vector<ll> (k + 1, -1));

  printf("%lld\n", solve(n, k));
  return 0;
}
