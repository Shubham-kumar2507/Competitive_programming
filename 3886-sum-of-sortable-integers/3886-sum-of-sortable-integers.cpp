class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> fac;
        for (int d = 1; d * d <= n; ++d){
            if (n % d == 0) {
                fac.push_back(d);
                if (n / d != d) {
                    fac.push_back(n / d);
                }
            }
        }
        vector<int> target = nums;
        ranges::sort(target);
        auto kmp = [](const vector<int>& text,
                      const vector<int>& pattern) {
            int n = text.size();
            int m = pattern.size();
            vector<int> pi(m, 0);
            int j = 0;

            for (int i = 1; i < m; ++i) {
                while (j > 0 && pattern[i] != pattern[j]) {
                    j = pi[j - 1];
                }

                if (pattern[i] == pattern[j]) {
                    ++j;
                }

                pi[i] = j;
            }
            j = 0;

            for (int i = 0; i < n; ++i) {
                while (j > 0 && text[i] != pattern[j]) {
                    j = pi[j - 1];
                }

                if (text[i] == pattern[j]) {
                    ++j;
                }

                if (j == m) {
                    return true;
                }
            }

            return false;
        };
        auto check = [&](const vector<int>& nums1,
                         const vector<int>& nums2) {
            vector<int> doubled = nums1;

            doubled.insert(
                doubled.end(),
                nums1.begin(),
                nums1.end()
            );

            return kmp(doubled, nums2);
        };

        int ans = 0;
        for (int d : fac) {
            bool allGood = true;

            for (int left = 0; left < n; left += d) {
                int right = left + d - 1;

                vector<int> sub1(
                    nums.begin() + left,
                    nums.begin() + right + 1
                );

                vector<int> sub2(
                    target.begin() + left,
                    target.begin() + right + 1
                );

                if (!check(sub1, sub2)) {
                    allGood = false;
                    break;
                }
            }

            //Add valid divisors to the answer
            if (allGood) {
                ans += d;
            }
        }

        return ans;
    }
};