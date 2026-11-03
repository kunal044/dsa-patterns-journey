class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int max_diff = INT_MAX;
        int n = nums.size();
        int res_sum;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++){
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }

            int left=i+1;
            int right=n-1;

            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];

                
                if(sum==target){
                    left++;
                    right--;
                    while(left<n and nums[left]==nums[left-1]){
                        left++;
                    }
                    while(right>=0 and nums[right]==right+1){
                        right--;
                    }
                }
                else if(sum<target){
                    left++;
                }
                else{
                    right--;
                }
                
                int diff = abs(sum-target);
                if(diff<max_diff){
                    max_diff=diff;
                    res_sum=sum;
                }
            }
        }
    return res_sum;
    }
};