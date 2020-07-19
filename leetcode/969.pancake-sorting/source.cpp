#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> ans;
    vector<int> pancakeSort(vector<int> &A)
    {
        sort(A, A.size());
        return ans;
    }
    void sort(vector<int> &A, int n)
    {
        if(n==1||n==0)
        return;
        int max=0,maxIndex=0;
        for(int i=0;i<n;++i)
        {
            if(A[i]>max){
                max=A[i];
                maxIndex=i;
            }
        }
        reverse(A,0,maxIndex);
        ans.push_back(maxIndex+1);
        reverse(A,0,n-1);
        ans.push_back(n);
        sort(A,n-1);
    }
    void reverse(vector<int> &nums, int i, int j)
    {
        while (i < j)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;--j;
        }
    }
};