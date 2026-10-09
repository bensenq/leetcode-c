class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 == 0 || n2 == 0 || k == 0) return res;
        // 小顶堆：比较器按 nums1[i]+nums2[j] 升序
        auto cmp = [&](const pair<int,int>& a, const pair<int,int>& b) {
            return nums1[a.first] + nums2[a.second] >
                   nums1[b.first] + nums2[b.second];  // > 得到小顶堆
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < min(k, n1); ++i) {
            pq.push({i, 0});
        }

        while (k-- > 0 && !pq.empty()) {
            auto [i, j] = pq.top(); pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if (j + 1 < n2) {
                pq.push({i, j + 1});
            }
        }
        return res;
    }
};
