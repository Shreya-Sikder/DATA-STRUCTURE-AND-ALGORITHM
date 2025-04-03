#include<bits/stdc++.h>
using namespace std;

int Even(vector<int>&vec,int l,int h){

    if(l==h){
        return (vec[l]%2==0?1:0 );
    }
 int mid=(l+h)/2;
 int leftcount=Even(vec,l,mid);
 int rightcount=Even(vec,mid+1,h);
return leftcount+rightcount;
}

int main(){
int n;
cout<<"size:";
cin>>n;
vector<int>vec(n);
for(int i=0;i<n;i++){
    cin>>vec[i];
}
 int l=0;
    int h=vec.size()-1;
cout<<"total even number"<<Even(vec,l,h)<<endl;
}
