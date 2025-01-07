/*
Time Complexity: 
Sorting: O(nlogn)
DP: O(n^2) 
Total: O(n^2 )
Space Complexity: O(n) for the dp array.
*/
/*
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        //if there are no envelopes simply return 0
        if(n == 0) {
            return 0;
        }
        // envelopes are sorted based on their width and height 
        sort(envelopes.begin(), envelopes.end());

        //dp[i] represents the maximum number of envelopes that can be nested up to the i-th envelope (inclusive).
        vector<int>dp(n+1, 1);
        int max =  1;

        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                
                    // envelopes[i][0] > envelopes[j][0] → Width of i is larger than j.
                    // envelopes[i][1] > envelopes[j][1] → Height of i is larger than j.
                    // dp[j] + 1 → Add envelope i to the nesting sequence ending at j.
                
                if(envelopes[i][0] > envelopes[j][0]  && 
                    envelopes[i][1] > envelopes[j][1] &&
                        1 + dp[j] > dp[i]) {
                            dp[i] = 1 + dp[j];
                        }
                        
                        if(max < dp[i]) {
                            max = dp[i];
                        }
            }
        }
        return max;
    }
};
*/
// Time Complexity: O(NLogN)
class Solution {
public:
    int Binary_Search(const vector<int>& dp, int target) {
        int low = 0, high = dp.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (dp[mid] < target) {
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
        return low;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) {
            return 0;
        }

        // Sort envelopes: width ascending, height descending (for same width)
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; // If widths are the same, sort by height descending
            }
            return a[0] < b[0]; // Otherwise, sort by width ascending
        });

        // Extract the heights of the sorted envelopes
        vector<int> heights;
        for (const auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }

        vector<int> dp;
        for (int height : heights) {
            int position = Binary_Search(dp, height);
            if (position == dp.size()) {
                dp.push_back(height); // Add new height
            } else {
                dp[position] = height; // Replace height at the found position
            }
        }
        return dp.size();
    }
};
