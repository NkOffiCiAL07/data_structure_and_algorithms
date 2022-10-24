class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long l = *min_element(nums.begin(), nums.end());
        long long r = *max_element(nums.begin(), nums.end());
        
        long long ans = 1e18;
        while(r >= l){
            long long x1 = l + (r - l) / 3;
            long long x2 = r - (r - l) / 3;
            
            long long a1 = 0, a2 = 0;
            for(int i = 0; i<nums.size(); i++){
                a1 += abs(nums[i] - x1) * cost[i];
                a2 += abs(nums[i] - x2) * cost[i];
            }
            
            if(a1 < a2){
                ans = min(a1, ans);
                r = x2 - 1;
            } else {
                ans = min(a2, ans);
                l = x1 + 1;
            }
        }
        
        return ans;
    }
};