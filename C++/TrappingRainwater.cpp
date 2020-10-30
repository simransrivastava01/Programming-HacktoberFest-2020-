//Ques link : https: //www.hackerrank.com/contests/pep-interviewprep-9june/challenges/pep-javaip-1arrays-9trappingrainwater

/*You are give an array of non-negative integers. The elements in array represent elevation of bars. Each bar is of width 1. Compute the amount of water, the
structure can trap on raining.
Input Format

N - Size of Array
N spaced integers
Constraints

0<= N <= 10^9
0<= Ai (ith integer of the array) <= 10^9
Output Format

Maximum amount of rainwater - Integer
Sample Input 0

12
0 1 0 2 1 0 1 3 2 1 2 1
Sample Output 0

6*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int TrapRainWater(vector<int> &b, int n)
{
   
    int i = 1;
    int trap_water = 0;
    int z = 0, zz = 0;
    while (i < n - 1)
    {

        int curr = b[i];//height of current bar
        z = curr, zz = curr;
        for (int j = 0; j < i; j++)
        {

            z = max(z, b[j]);//find heighest bar on left
        }
        for (int j = i + 1; j < n; j++)
        {

            zz = max(zz, b[j]);//find heighest bar on right
        }
        trap_water += min(z, zz) - curr;//the minimum of heights of bar on left and right traps water
        i++;
    }
    return trap_water;

}

int main()
{
    int n;
    cin >> n;
    vector<int> barElevation(n);
    for (auto &x : barElevation)
        cin >> x;

    int waterTrapped;
    waterTrapped = TrapRainWater(barElevation, n);//function call
    cout<<waterTrapped;
    return 0;
}