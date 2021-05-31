#include<bits/stdc++.h>
using namespace std;
void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr1[], int arr2[], int m, int n){
    for(int i=n-1;i>=0;i--){
        int last = arr1[m-1];
        int j;
        for(j = m-2;j>=0 && arr1[j] > arr2[i];j--){
            arr1[j+1] = arr1[j];
        }

        if(j!=m-2 || last > arr2[i]){
            arr1[j+1] = arr2[i];
            arr2[i] = last;
        }
    }
}
int main(){
    int arr1[] = {1,2,7,9,10,20};
    int arr2[] = {1,3,5,7,9};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    print(arr1,m);
    print(arr2,n);
    merge(arr1,arr2,m,n);
    print(arr1,m);
    print(arr2,n);
    return 0;
}