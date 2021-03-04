#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1,2,4,5,6,8,13,24,49,49,3};
    // vector<int> nums = {1,2,3,4,4,5,6};
    sort(nums.begin(), nums.end());

    int ret = 0;
    int l = 0;
    int r = nums.size()-1;

    while(l <= r){
        int mid = l + (r - l)/2;

        if(nums[mid] != mid + 1){
            if(mid > 0 && nums[mid] == nums[mid-1]){
                ret = mid;
                break;
            }
                
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout<<nums[ret];
}