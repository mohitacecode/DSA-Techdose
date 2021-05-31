#include<bits/stdc++.h>
using namespace std;
    int maxSubArray(vector<int>& nums) {
        //Kadane's algorithm
        int mx = INT_MIN;
        int currsum = 0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            mx = max(mx,currsum);
            if(currsum<0){
                currsum = 0;
            }
        }
        return mx;
    }
int main(){
    vector<int> nums = {1,3,4,-1,-4,0,-5,1,4,8};
    cout<<maxSubArray(nums)<<endl;
    return 0;
}