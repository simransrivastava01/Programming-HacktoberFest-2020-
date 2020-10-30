//Ques link: https://www.hackerrank.com/contests/pep-interviewprep-9june/challenges/pep-javaip-1arrays-3equilibrium-point
/*
sum of values at lower indices should be equal to the sum of
values at higher indices. Return the value of the index, otherwise return -1.
Taget time complexity : O(n)
Input Format

Integer A-size of array
A Integers -elements of array A
Constraints

1 ≤ A ≤ 10^5
-10^9 ≤ Ai ≤ 10^9 for each valid i
Output Format

Index of the equilibrium point.
Sample Input 0

7
-7  1  5  2 -4  3  0
Sample Output 0

3
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    vector<int> sumtillnow;//stores sum till current index
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        sumtillnow.push_back(sum);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (sumtillnow[i - 1] == sumtillnow[n - 1] - sumtillnow[i])//sum till previous (i-1)th index == total sum - sum till ith index
        {
            cout << i;//return equilibrium index
            return 0;
        }
    }
    cout << -1;//when no equilibrium exisits, return -1
    return 0;
}
