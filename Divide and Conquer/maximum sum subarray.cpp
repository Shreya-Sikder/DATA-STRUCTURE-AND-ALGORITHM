#include<bits/stdc++.h>
using namespace std;
int cross(vector<int>&vec,int l,int m,int h)
{
    int sum=0;
    int leftsum=INT_MIN;
    for(int i=m; i>=l; i--)
    {
        sum+=vec[i];
        if(leftsum<sum)
        {
            leftsum=sum;
        }
    }
    sum=0;
    int rightsum=INT_MIN;
    for(int i=m+1; i<=h; i++)
    {
        sum+=vec[i];
        if(rightsum<sum)
        {
            rightsum=sum;
        }
    }
    return leftsum+rightsum;
}


int maxsum(vector<int>&vec,int l,int h)
{

    if(l==h) return vec[l];

    int mid=(l+h)/2;
    int leftsum=maxsum(vec,l,mid);
    int rightsum=maxsum(vec,mid+1,h);
    int crossSum=cross(vec,l,mid,h);

    if(leftsum>=rightsum && leftsum>=crossSum)
    {
        return leftsum;
    }
    else if (rightsum>=leftsum && rightsum>=crossSum)
    {
        return rightsum;
    }
    else
    {
       return crossSum;
    }

}
int maxsub(vector<int>&vec,int n)
{
    return maxsum(vec,0,n-1);

}

int main()
{
    int n;
    cout<<"enter your array size:";
    cin>>n;
    cout<<"enter your inputs:";
    vector <int> vec(n);

    for(int i=0; i<n; i++)
    {
        cin>>vec[i];
    }
    cout<<maxsub(vec,n);



    return 0;
}
