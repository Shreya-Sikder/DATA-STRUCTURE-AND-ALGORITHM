#include <bits/stdc++.h>
using namespace std;
int buySell(vector<int>&a)
{ int n=a.size();
if(n==0) return 0;
vector<int>dp(n,0);
 int minPrice=a[0];
 for(int i=1;i<n;i++){
    dp[i]=max(dp[i-1],a[i]-minPrice);
    minPrice=min(minPrice,a[i]);
 }

 return dp[n-1];
}
int main()
{
int n;
cin>>n;
vector<int>a(n);
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
int maxProfit= buySell(a);

cout<<maxProfit<<endl;

}

