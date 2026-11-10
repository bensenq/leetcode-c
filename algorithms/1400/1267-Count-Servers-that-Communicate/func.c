class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> freq_col(250,0), freq_row(250,0);
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    freq_col[j]++;
                    freq_row[i]++;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && (freq_col[j] > 1 || freq_row[i] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
