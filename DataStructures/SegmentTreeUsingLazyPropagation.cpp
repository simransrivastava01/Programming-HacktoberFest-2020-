/* C++ Program to impelment Segment tree
        using Lazy Propagation*/

#include <bits/stdc++.h>
using namespace std;

/* Function to answer range minimum queries*/

int rangeMinQueries(int *segTree,int *lazy,int qlow,int qhigh,int low,int high,int pos)
{
    if(lazy[pos]!=0)
    {
        segTree[pos]+=lazy[pos];
        if(low!=high)//not a leaf
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(qlow>high||qhigh<low)//no overlap
    {
        return INT_MAX;
    }
    if(low>=qlow&&high<=qhigh)//total overlap
    {
        return segTree[pos];
    }
    int mid=(low+high)/2;
    return min(rangeMinQueries(segTree,lazy,qlow,qhigh,low,mid,2*pos+1),rangeMinQueries(segTree,lazy,qlow,qhigh,mid+1,high,2*pos+2));
}

/* Function to update the segment
            and lazy trees*/

void updateTree(int *segTree,int *lazy,int qlow,int qhigh,int delta,int low,int high,int pos)
{
    if(low>high)
        return;
    if(lazy[pos]!=0)
    {
        segTree[pos]+=lazy[pos];
        if(low!=high)//not a leaf
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(qlow>high||qhigh<low)//no overlap
    {
        return;
    }
    if(low>=qlow&&high<=qhigh)//total overlap
    {
        segTree[pos]+=delta;
        if(low!=high)//not a leaf
        {
            lazy[2*pos+1]+=delta;
            lazy[2*pos+2]+=delta;
        }
    }
    else
    {
        int mid=(low+high)/2;
        updateTree(segTree,lazy,qlow,qhigh,delta,low,mid,2*pos+1);
        updateTree(segTree,lazy,qlow,qhigh,delta,mid+1,high,2*pos+2);
        segTree[pos]=min(segTree[2*pos+1],segTree[2*pos+2]);
    }
}

/* Recursive function to create
            the initial segment tree*/

void createTree(int *a,int *segTree,int low,int high,int pos)
{
    if(low==high)//leaf
    {
        segTree[pos]=a[low];
        return;
    }
    int mid=(low+high)/2;
    createTree(a,segTree,low,mid,2*pos+1);
    createTree(a,segTree,mid+1,high,2*pos+2);
    segTree[pos]=min(segTree[2*pos+1],segTree[2*pos+2]);
    return;
}

/* Main Function */

int main()
{
    int n;
    cout<<"Enter no. of elements"<<endl;
    cin>>n;
    int *a=new int[n];
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int temp;
    if(ceil(log2(n))==floor(log2(n)))
        temp=n;
    else
        temp=pow(2,ceil(log2(n)));
    int *segTree=new int[2*temp-1];
    int *lazy=new int[2*temp-1];
    createTree(a,segTree,0,n-1,0);
    for(int i=0;i<2*temp-1;i++)
        cout<<segTree[i]<<" ";
    cout<<endl;
    cout<<"Segment tree Formed"<<endl;
    updateTree(segTree,lazy,0,3,3,0,n-1,0);
    cout<<"Updated 1"<<endl;
    for(int i=0;i<2*temp-1;i++)
        cout<<segTree[i]<<" ";
    cout<<endl;
    updateTree(segTree,lazy,0,3,1,0,n-1,0);
    cout<<"Updated 2"<<endl;
    for(int i=0;i<2*temp-1;i++)
        cout<<segTree[i]<<" ";
    cout<<endl;
    updateTree(segTree,lazy,0,0,2,0,n-1,0);
    cout<<"Updated 3"<<endl;
    for(int i=0;i<2*temp-1;i++)
        cout<<segTree[i]<<" ";
    cout<<endl;
    cout<<rangeMinQueries(segTree,lazy,3,5,0,n-1,0)<<endl;
    for(int i=0;i<2*temp-1;i++)
        cout<<segTree[i]<<" ";
    cout<<endl;
    delete[] a;
    delete[] segTree;
    delete[] lazy;
    return 0;
}

/* Sample Input Array to check the program-
        -1 2 4 1 7 1 3 2
                */
