class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int MAX = *max_element(nums.begin(), nums.end());

        // Step 1: Frequency of each value
        vector<long long> freq(MAX + 1, 0);
        for (int x : nums)
            freq[x]++;

        // Step 2: Count numbers divisible by each d
        vector<long long> cnt(MAX + 1, 0);
        for (int d = 1; d <= MAX; d++) {
            for (int multiple = d; multiple <= MAX; multiple += d) {
                cnt[d] += freq[multiple];
            }
        }

        // Step 3: Count pairs divisible by d
        vector<long long> exact(MAX + 1, 0);
        for (int d = 1; d <= MAX; d++) {
            exact[d] = cnt[d] * (cnt[d] - 1) / 2;
        }

        // Step 4: Inclusion-Exclusion
        for (int d = MAX; d >= 1; d--) {
            for (int multiple = 2 * d; multiple <= MAX; multiple += d) {
                exact[d] -= exact[multiple];
            }
        }

        // Step 5: Prefix sum of counts
        vector<long long> prefix(MAX + 1, 0);
        for (int d = 1; d <= MAX; d++) {
            prefix[d] = prefix[d - 1] + exact[d];
        }

        // Step 6: Answer queries
        vector<int> ans;
        for (long long q : queries) {
            // We need first prefix > q
            int g = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};