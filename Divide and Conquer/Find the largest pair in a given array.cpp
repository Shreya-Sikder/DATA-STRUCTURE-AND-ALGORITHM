#include<bits/stdc++.h>
using namespace std;

pair<int,int>largestpair(vector<int> &vec,int l,int h)
{
   if(l==h) return {vec[l],INT_MIN};

    int mid=(l+h)/2;
    pair<int,int>leftpair=largestpair(vec,l,mid);
     pair<int,int>rightpair=largestpair(vec,mid+1,h);
    int first_large=max(leftpair.first,rightpair.first);
    int second_large=max(min(leftpair.first,rightpair.first),max(leftpair.second,rightpair.second));
    return {first_large,second_large};

}


int main(){
int n;
cin>>n;
vector<int>vec(n);
for(int i=0;i<n;i++){
    cin>>vec[i];
}

pair <int,int>result= largestpair(vec,0,n-1);
int sum=result.first+result.second;
cout<<"First largest number: "<<result.first<<endl;
cout<<"second  largest number: "<<result.second<<endl;

cout <<"pair: ("<<result.second<<","<<result.first<<") and their sum is: "<<sum<<endl;
 }
