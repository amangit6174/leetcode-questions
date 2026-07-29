class Solution {
public:
    static const int LIMIT = 10e6;
    long long comb(int n, int r) {
        if (r < 0 or r > n)
            return 0;

        r = min(r, n - r);
        long long res = 1;

        for (int i = 1; i <= r; i++) {
            res = (res * (n - r + i)) / i;

            if (res >= LIMIT)
                return LIMIT;
        }

        return res;
    }

    long long countWays(vector<int>& cnt) {
        int l = accumulate(begin(cnt), end(cnt), 0);
        long long ways = 1;

        for (int x : cnt) {
            if (!x)
                continue;

            ways = min((long long)LIMIT, ways * comb(l, x));
            l -= x;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26), half(26);
        char mid = 0;
        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;

            if (freq[i] & 1) {
                mid = 'a' + i;
            }
        }

        long long totalWays = countWays(half);

        if (totalWays < k) {
            return "";
        }

        string left;
        int sz = s.length() / 2;

        while (left.size() < sz) {
            for (int i = 0; i < 26; i++) {
                if (!half[i]) {
                    continue;
                }

                half[i]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left += char('a' + i);
                    break;
                }

                k -= ways;
                half[i]++;
            }
        }

        string right = left;
        reverse(begin(right), end(right));
        return left + (mid ? string(1, mid) : "") + right;
    }
};