//Using simple for loops
//T.C : O(m*n)
//S.C : O(m*n)
/*
class Solution {
public:
    vector<vector<int>> directions {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 0}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for(auto &it : directions) {
                    // If the indices form valid neighbor
                    int i_ = i + it[0];
                    int j_ = j + it[1];
                
                    if (0 <= i_ && i_ < m && 0 <= j_ && j_ < n) {
                        sum += img[i_][j_];
                        count += 1;
                    }
                }
                result[i][j] = sum / count;
            }
        }
        return result;
    }
};
*/


// Using Optimized Space
//T.C : O(m*n)
//S.C : O(n)
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        //prevRow array of size n.
        vector<int> prevRow(n);
        int prevCorner = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                int sum = 0;
                int count = 0;

                // Bottom neighbors
                if (i + 1 < m) {
                    if (j - 1 >= 0) {
                        sum += img[i + 1][j - 1];
                        count++;
                    }
                    sum += img[i + 1][j];
                    count += 1;
                    if (j + 1 < n) {
                        sum += img[i + 1][j + 1];
                        count++;
                    }
                }

                // Next neighbor
                if (j + 1 < n) {
                    sum += img[i][j + 1];
                    count++;
                }
                
                // This cell
                sum += img[i][j];
                count++;

                // Previous neighbor
                if (j - 1 >= 0) {
                    sum += prevRow[j - 1];
                    count++;
                }

                // Top neighbors
                if (i - 1 >= 0) {
                    // Left-top corner-sharing neighbor.
                    if (j - 1 >=  0) {
                        sum += prevCorner;
                        count++;
                    }
                    
                    // Top edge-sharing neighbor.
                    sum += prevRow[j];
                    count++;

                    // Right-top corner-sharing neighbor.
                    if (j + 1 < n) {
                        sum += prevRow[j + 1];
                        count++;
                    }
                }

                // store corner value
                if (i - 1 >= 0) {
                    prevCorner = prevRow[j];
                }

                // Store current value
                prevRow[j] = img[i][j];

                // Overwrite with smoothed value.
                img[i][j] = sum / count;
            }
        }
        // Return the smooth image.
        return img;
    }
};