class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());

        long long ans = 0;
        int prev = -1;

        for (int i = 0; i < n; i++) {
            int curr = a[i].second;

            if (i == 0) {
                ans += n;
            } else {
                if (curr < prev) {
                    ans += n - i;
                }
            }

            prev = curr;
        }

        return ans;
    }
};