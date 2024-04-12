#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int bin(vector<int>& nums1,vector<int>& nums2,int k)
{
int n1 = nums1.size();
int n2 =nums2.size();
int left1 = 0,right1 =n1-1,mid1 = (n1-1)/2;
int left2 = 0,right2 =n2 -1,mid2 = (n2-1)/2;
int i =mid1,j=mid2;
while(i!=k && j!=k)
{
//i = i+mid1;
//j =j +mid2;
if(mid1>=n1)

if(nums1[mid1]>nums2[mid2])
{
    left2 = mid2+1 ;
    i+=j+1;
}
else if(nums1[mid1]==nums2[mid2])
{
    int temp =j;
    j = j+i; 
    i = i+temp+1;
}
else
{
    left1 = mid1+1 ;
    j+=i;
}
}
}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if((nums1.size()+nums2.size())%2)
        {
            int k = (nums1.size() +nums2.size())/2 +1;
             

        }
    }
};