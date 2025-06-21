#include<bits/stdc++.h>
using namespace std;
int lic(int n,vector<int>&nums){
 if(n==0) return 0;
    vector<int>dp(n,1);
 for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
        if(nums[j]<nums[i]){
            dp[i]=max(dp[i],dp[j]+1);
        }
    }
 }





return *max_element(dp.begin(),dp.end());
}

int main(){
 int n;
 cout<<"size:";
 cin>>n;
 vector<int>num(n);
 for(int i=0;i<n;i++){
    cin>>num[i];
 }
int res=lic(n,num);
cout<<res<<endl;

}
