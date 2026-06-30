#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> modCount;
        modCount[0] = 1; // Initialize with 0 mod count
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            int mod = ((sum % k) + k) % k; // Handle negative mods

            if (modCount.find(mod) != modCount.end()) {
                count += modCount[mod]; // Add the count of previous subarrays with the same mod
            }

            modCount[mod]++; // Increment the count for this mod
        }

        return count;
    }
};