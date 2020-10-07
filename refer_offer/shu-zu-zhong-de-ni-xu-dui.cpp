#include<iostream>
#include<vector>
using namespace std;

int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
    if (l >= r) {
        return 0;
    }

    int mid = (l + r) / 2;
    int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
    int i = l, j = mid + 1, pos = l;
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {
            tmp[pos] = nums[i];
            ++i;
            inv_count += (j - (mid + 1));
        }
        else {
            tmp[pos] = nums[j];
            ++j;
        }
        ++pos;
    }
    cout << l << " " << r << " " << pos << endl;
    for (int k = i; k <= mid; ++k) {
        tmp[pos++] = nums[k];
        inv_count += (j - (mid + 1));
    } // 连着 while i 提前退出的情况 
    cout << pos << endl;
    for (int k = j; k <= r; ++k) {
        tmp[pos++] = nums[k];
    } // 连着 while i 提前退出的情况 
    copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
    return inv_count;
}

int main() {
	int a[5] = {7,5,6,4};
	vector<int>nums(a, a+4);
    int n = nums.size();
    vector<int> tmp(n);
    cout << mergeSort(nums, tmp, 0, n - 1);
    return 0;
}

class Solution {
public:
    int merge(vector<int>& nums, vector<int>& temp, int l, int r){
        if (l >= r){
            return 0;
        }
        int mid = (l + r) / 2;
        int count = merge(nums, temp, l, mid) + merge(nums, temp, mid+1, r);
        int i = l, j = mid+1, pos = l;
        while (i <= mid && j <= r){
            if (nums[i] <= nums[j]){
                temp[pos] = nums[i];
                count += (j - (mid + 1));
                i++;
            }
            else{
                temp[pos] = nums[j];
                j++;
            }
            pos++;
        }
        for (int k = i; k <= mid; k++){
            temp[pos++] = nums[k];
            count += (j - (mid+1));
        }
        for (int k = j; k <= r; k++){
            temp[pos++] = nums[k];
        }
        copy(temp.begin()+l, temp.begin()+r+1, nums.begin()+l);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        vector<int>temp(nums.size());
        return merge(nums, temp, 0, nums.size()-1);
    }
};
