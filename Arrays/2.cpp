#include<bits/stdc++.h>
using namespace std;
    void sortColors(vector<int>& nums) {
        int l = -1, r = nums.size();
        int i=0;
        while(i<r){
            if(nums[i]==0){
                l++;
                swap(nums[l],nums[i]);
                i++;
            }
            else if(nums[i]==1){
                i++;
            }
            else{
                r--;
                swap(nums[i],nums[r]);
            }
        }
    }
int main(){
    vector<int> nums = {2,1,1,0,0,2,1,0};
    sortColors(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}