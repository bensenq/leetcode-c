class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> count;
        int i;
        for(i = 0; i < nums.size();i ++) {
            count[nums[i]]++;
            if (count[nums[i]] > (nums.size() / 2)) 
                break;
        }
        return nums[i];
    }
};