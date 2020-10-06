#include <bits/stdc++.h> 
#include <climits>
#include <cmath>
#include <cfloat>
using namespace std; 
struct Point  
{  
    int x, y;  
};
Point p1,p2;
Point L[10001]; //+1 to account for sentinel value
Point R[10001]; //+1 to account for sentinel value
void Merge(Point *M, int p, int q, int r, int compareOption)
{
    int n1 = q - p; //Last index of left array
    int n2 = r - q - 1; //Last index of right array
    for (int i = 0; i <= n1; i++)
        L[i] = M[p + i];
    for (int j = 0; j <= n2; j++)
        R[j] = M[q + j + 1];
    if (compareOption == 1)
    {
        L[n1 + 1].x = RAND_MAX + RAND_MAX; //The sentinel value
        R[n2 + 1].x = RAND_MAX + RAND_MAX; //The sentinel value

        int i = 0;
        int j = 0;
        for (int k = p; k <= r; k++)
        {
            if (L[i].x <= R[j].x)
            {
                M[k] = L[i];
                i++;
            }
            else
            {
                M[k] = R[j];
                j++;
            }
        }
    }
    else 
    { 
        L[n1 + 1].y = RAND_MAX + RAND_MAX; //The sentinel value
        R[n2 + 1].y = RAND_MAX + RAND_MAX; //The sentinel value
        int i = 0;
        int j = 0;
        for (int k = p; k <= r; k++)
        {
            if (L[i].y <= R[j].y)
            {
                M[k] = L[i];
                i++;
            }
            else
            {
                M[k] = R[j];
                j++;
            }
        }
    }
}
void MergeSort(Point *M, int p, int r, int compareOption)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        MergeSort(M, p, q, compareOption);
        MergeSort(M, q + 1, r, compareOption);
        Merge(M, p, q, r, compareOption);
    }
}
float DistanceOf2Points(Point p1, Point p2)  
{  
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y));  
}  
float ClosestDistanceOf3(Point P[], int n)  
{  
         float min = 1000000;  
           for (int i = 0;i < n;i++)  
             for (int j = i+1;j < n;j++)  
                if (DistanceOf2Points(P[i], P[j]) < min)  
                {
                    min = DistanceOf2Points(P[i], P[j]);  
                    p1=P[i];
                    p2=P[j];
                }
                 return min;  
}  
float MinimumOf2(float x, float y)  
{  
   if(x<y)
   return x;
   else
   return y;
}  
float FormationOfStrip(Point strip[], int n, float d)  
{  
    float min = d; // Initialize the minimum distance as d  
    Point Py[n];
    for (int i = 0; i < n; i++)
    {
        Py[i] = strip[i];
    }
    MergeSort(Py, 0,n - 1, 2); //1 for compare x
    for (int i = 0; i < n; ++i)  
    {
        for (int j = i+1; j < n && (strip[j].y - strip[i].y) < min; ++j)  
        {
            if (DistanceOf2Points(strip[i],strip[j]) < min)
            {
                min = DistanceOf2Points(strip[i], strip[j]);  
                p1=strip[i];
                p2=strip[j];
            }
        }
    }
       return min;  
}  
float CompareDistance(Point P[], int n)  
{  
        if (n <= 3)  
        return ClosestDistanceOf3(P, n);  
        int middleindex = n/2;  
        Point middlePoint = P[middleindex];  
        float dleft = CompareDistance(P, middleindex);  
        float dright = CompareDistance(P + middleindex, n - middleindex);  
        float dmin = MinimumOf2(dleft, dright);  
    Point yaxisstrip[n];  
    int j = 0;  
    for (int i = 0; i < n; i++)  
    {
        if (abs(P[i].x - middlePoint.x) < dmin) 
        {
            yaxisstrip[j] = P[i];
            j++;  
        }
    }
    return MinimumOf2(dmin,FormationOfStrip(yaxisstrip, j, dmin));  
}  
float NearestPoint(Point P[], int n)  
{  
    Point Px[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
    }
    MergeSort(Px, 0, n - 1, 1); //1 for compare x
    return CompareDistance(P, n);  
}  
int main()  
{  
    Point P[] ={{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int size = sizeof(P) / sizeof(P[0]);  
    cout << "The distance between closest pair of points is: " << NearestPoint(P, size)<<endl; 
    cout <<"Points are : ("<<p1.x<<","<<p1.y<<") and ("<<p2.x<<","<<p2.y<<")";
    return 0;  
}  