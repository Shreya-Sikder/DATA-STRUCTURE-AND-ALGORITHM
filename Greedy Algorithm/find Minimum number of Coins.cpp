#include<bits/stdc++.h>
using namespace std;

void mincoin(vector<int>&coin,int n,int value)
{
    sort(coin.begin(),coin.end(),greater<int>());
    vector<int>result;
    for(int i=0; i<n; i++)
    {
        while(value>=coin[i])
        {
            result.push_back(coin[i]);

            value-=coin[i];
        }
    }
    cout<<"minimum coin used: ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }

}

int main()
{
    int n;
    cout<<"type of coins: ";
    cin>>n;
    vector<int>coin(n);
    cout<<"input coins: ";
    for(int i=0; i<n; i++)
    {
        cin>>coin[i];
    }
    int value;
    cout<<"value: ";
    cin>>value;
    mincoin(coin,n,value);

}
