#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int left=low;
    int right=high;
    
    while(left<right){
        //1st element greater than pivot from left
        while(arr[left]<=pivot && left<high){
            left++;
        }
        //1st element smaller than pivot from right
         while(arr[right]>pivot && right>low){
            right--;
        }
        
        if(left<right)swap(arr[left],arr[right]);
    }
    
    //pivot with the smallest element right at after outer loop  ends 
    swap(arr[low],arr[right]);
    return right;
}

void quickSort(vector<int> &arr,int low,int high){
    if(low<high){
    int pIndex=partition(arr,low,high);
     quickSort(arr,low,pIndex-1);
     quickSort(arr,pIndex+1,high);
    }
}

int main() {
   vector<int> arr={10,20,5,10,11,45,28};
   cout<<"Before Sorting : [ ";
   for(auto it:arr)cout<<it<<" ";
   cout<<"]\n";
   
   int n=arr.size();
   quickSort(arr,0,n-1);
   
   cout<<"After Sorting : [ ";
   for(auto it:arr)cout<<it<<" ";
   cout<<"]\n";

    return 0;
}
