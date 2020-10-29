/* Kadane's Algorithm Logic:
Simple idea of the Kadane’s algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this). And keep track of maximum sum contiguous segment among all positive segments (max_so_far is used for this). Each time we get a positive sum compare it with max_so_far and update max_so_far if it is greater than max_so_far */

#include <bits/stdc++.h>
using namespace std;

int maximumSubarraySum(vector<int> &arr, int n)
{

    int sumtillnow = 0, maxSumtillnow = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sumtillnow += arr[i];
        if (maxSumtillnow < sumtillnow)//update maxSumtillnow with greater value
            maxSumtillnow = sumtillnow;
        if (sumtillnow < 0)//if sum becomes negative, sumtillnow updated to 0
            sumtillnow = 0;
    }
    return maxSumtillnow;
}

int main()
{
    int size;
    cin >> size;
    vector<int> arr(size);
    for (auto &x : arr)
        cin >> x;
    int maxSubarraySum = maximumSubarraySum(arr, size);//function call
    cout<<maxSubarraySum; 
    return 0;
}