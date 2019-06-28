#include <iostream>
#include <vector>

using namespace std;

class Solution {
  private:
    vector<int> nums;
  public:
    Solution(vector<int> nums) : nums(nums) {}

    void rebuild() {}
    void update(int l, int r, int x, int y) {}
    vector<int> finish() {
      return vector<int>();
    }
};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int len;
  cin >> len;
  vector<int> nums(len);
  for (int i = 0; i < len; i++) {
    cin >> nums[i];
  }

  const int magic = 450;
  Solution easy = Solution(nums);

  int queries;
  cin >> queries;
  for (int query = 0; query < queries; query++) {
    if (query % magic == 0)
      easy.rebuild();
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    easy.update(l, r, x, y);
  }

  vector<int> result = easy.finish();
  for (int num : result) {
    cout << num << " ";
  }
  cout << "\n";
  return 0;
}
