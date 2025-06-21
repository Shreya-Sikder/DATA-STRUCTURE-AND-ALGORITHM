#include<bits/stdc++.h>
using namespace std;

int knapsack(int n,int maxcap,vector<int>&weight,vector<int>&value)
{
    vector<vector<int>>dp(n+1,vector<int>(maxcap+1,0));

    for(int i=1; i<=n; i++)
    {
        for(int w=0; w<=maxcap; w++)
        {
            if(weight[i-1]<=w)
            {
                dp[i][w]=max(dp[i-1][w],value[i-1]+dp[i-1][w-weight[i-1]]);
            }
            else
            {
                dp[i][w]=dp[i-1][w];
            }
        }
    }


    return dp[n][maxcap];
}






int main()
{
    int n;//no of items
    cin>>n;
    int maxcap;// maximum capacity
    cin>>maxcap;

    vector<int>weight(n);
    vector<int>value(n);

    cout<<"weight:"<<endl;
    for(int i=0; i<n; i++)
    {

        cin>>weight[i];
    }
    cout<<"value:"<<endl;
    for(int i=0; i<n; i++)
    {

        cin>>value[i];
    }
    int res=knapsack(n,maxcap,weight,value);
    cout<<"Maximum Total Value is :"<<res<<endl;
}
