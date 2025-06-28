class Solution {
public:
    // All power sets of the input array
    vector<vector<int>> findSubset(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> set(n + 1);

		for (int j = 0; j < (1 << n); ++j) {
			int size = 0, subsetSum = 0, temp = j, k = 0;
			while (temp != 0) {
				if ((temp & 1) == 1) {
					size++;
					subsetSum += nums[k];
				}
				k++;
				temp >>= 1;
			}
			set[size].push_back(subsetSum);
		}

		return set;
	}
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
		if (n == 1) return false;
		if (n == 2) return nums[0] == nums[1];

		int halflen = n / 2;
		int total = accumulate(nums.begin(), nums.end(), 0);

		vector<int> firstHalf(nums.begin(), nums.begin() + halflen + 1);
		vector<int> secondHalf(nums.begin() + halflen + 1, nums.end());

		vector<vector<int>> set1 = findSubset(firstHalf);
		vector<vector<int>> set2 = findSubset(secondHalf);


		for (auto& s : set2) {
			sort(s.begin(), s.end());
		}

		for (int i = 0; i < set1.size(); ++i) {
			for (int x : set1[i]) {
				for (int j = 0; j < set2.size(); ++j) {
					if (i + j == 0 or i + j == nums.size()) continue;
					// (x + y) / (i + j) == (total - (x + y)) / (nums.size() - (i + j))
					double y = ((1.0 * total * (i + j)) / nums.size()) - x;
					if (ceil(y) != y) continue;
					if (binary_search(set2[j].begin(), set2[j].end(), static_cast<int>(y))) {
						return true;
					}
				}
			}
		}
		return false;
    }
};