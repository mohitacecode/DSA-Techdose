#include<bits/stdc++.h>
using namespace std;
void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//RADIX SORT
void counting(int arr[], int n, int d){
    vector<int> hash(10,0);
    int dvd = pow(10,d);
    for(int i=0;i<n;i++){
        hash[(arr[i]/dvd)%10]++;
    }
    for(int i=1;i<10;i++){
        hash[i] = hash[i] + hash[i-1];
    }
    vector<int> new_arr(n,0);
    for(int i=n-1;i>=0;i--){
        int temp = (arr[i]/dvd)%10;
        new_arr[hash[temp]-1] = arr[i];
        hash[temp]--;
    }
    for(int i=0;i<n;i++){
        arr[i] = new_arr[i];
    }
}

void radix_sort(int arr[], int n){
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        mx = max(mx,arr[i]);
    }

    int digits = log10(mx)+1;
    for(int i=0;i<digits;i++){
        counting(arr,n,i);
    }
}
//COUTING SORT
void counting_sort(int arr[], int n){
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        mx = max(mx, arr[i]);
    }

    int *hash = new int[mx+1];
    memset(hash,0,sizeof(int)*(mx+1));
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    for(int i=1;i<=mx;i++){
        hash[i] = hash[i] + hash[i-1];
    }

    int *new_arr = new int[n];
    for(int i=n-1;i>=0;i--){
        new_arr[hash[arr[i]]-1] = arr[i];
        hash[arr[i]]--;
    }

    for(int i=0;i<n;i++){
        arr[i] = new_arr[i];
    }
}

//QUICK SORT
int pivot(int arr[], int s, int e){
    int pvt = arr[e];
    int j=s-1;
    for(int i=s;i<e;i++){
        if(arr[i]<pvt){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j+1],arr[e]);
    return j+1;
}
void quick_sort(int arr[],int s, int e){
    if(s>=e){
        return;
    }
    int ind = pivot(arr,s,e);
    quick_sort(arr,s,ind-1);
    quick_sort(arr,ind+1,e);
}
//MERGE SORT
void merge(int arr[],int s, int m, int e){
    int i = s, j = m+1, k=0;
    int *new_arr = new int[e-s+1];
    while(i<=m && j<=e){
        if(arr[i]<arr[j]){
            new_arr[k++] = arr[i++];
        }
        else{
            new_arr[k++] = arr[j++];
        }
    }

    while(i<=m){
        new_arr[k++] = arr[i++];
    }
    while(j<=e){
        new_arr[k++] = arr[j++];
    }

    k = 0;
    for(int i=s;i<=e;i++){
        arr[i] = new_arr[k++];
    }
}
void merge_sort(int arr[], int s, int e){
    if(s>=e){
        return;
    }

    int m = s+(e-s)/2;
    merge_sort(arr,s,m);
    merge_sort(arr,m+1,e);
    merge(arr,s,m,e);
}

//INSERTION SORT
void insertion_sort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

//BUUBLE SORT
void bubble_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

//SELECTION SORT
void selection_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int ind = i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[ind]){
                ind = j;
            }
        }
        swap(arr[i],arr[ind]);
    }
}
int main(){
    int arr[] = {170,45,75,90,802,24,2,66};
    int n = sizeof(arr)/sizeof(arr[0]);
    // selection_sort(arr,n);
    // bubble_sort(arr,n);
    // insertion_sort(arr,n);
    // merge_sort(arr,0,n-1);
    // quick_sort(arr,0,n-1);
    // counting_sort(arr,n);
    radix_sort(arr,n);
    print(arr,n);
    return 0;
}