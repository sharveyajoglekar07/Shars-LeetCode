class Solution {
public:
    int gcd(int a, int b){
        while (b!=0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd;
        int mx = nums[0];
        for(int i=0;i<n;i++){
            mx=max(mx, nums[i]);
            prefixGcd.push_back(gcd(nums[i], mx));
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long ans=0;
        int left =0, right=n-1;
        while (left<right){
            ans+=gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        return ans;
    }
};