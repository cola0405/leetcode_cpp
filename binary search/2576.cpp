#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool fit(int k, vector<int>& nums, int n){
        for (int i = 0; i < k; ++i) {
            if (nums[i] * 2 > nums[n - k + i]) {
                return false;
            }
        }
        return true;
    };

    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = n / 2;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (fit(mid, nums, n)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low * 2;
    }
};