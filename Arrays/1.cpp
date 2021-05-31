    #include<bits/stdc++.h>
    using namespace std;
    int  pivot(vector<int> &nums, int s, int e){
        int pvt = nums[e];
        int j = s-1;
        for(int i=s;i<e;i++){
            if(nums[i]<pvt){
                j++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[j+1],nums[e]);
        return j+1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int s=0, e=nums.size()-1, n = nums.size();
        k = n-k+1;
        while(s<e){//until only one elements is remain to be in possible elements when this happen that is the answer
            int ind = pivot(nums,s,e);
            if(ind==k-1){
                return nums[ind];
            }
            else if(ind<k-1){
                s = ind+1;
            }
            else{
                e = ind-1;
            }
        }
        return nums[s];
    }
    int main(){
        vector<int> arr = {1,3,5,1,5,7,9,3};
        int n = 4;
        cout<<findKthLargest(arr,n)<<endl;
    }