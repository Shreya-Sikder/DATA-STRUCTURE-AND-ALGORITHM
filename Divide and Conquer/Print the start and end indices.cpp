#include<bits/stdc++.h>
using namespace std;

struct subarray{
int left;
int sum;
int right;
};



subarray cross( vector<int>&vec,int l,int mid,int h )
{
    int sum=0;
    int left=INT_MIN;
    int left_index=mid;

    for(int i=mid;i>=l;i--){
        sum+=vec[i];
        if(left<sum){
            left=sum;
            left_index=i;
        }
    }
  sum=0;
    int right=INT_MIN;
       int right_index=mid+1;
    for(int i=mid+1;i<=h;i++){
        sum+=vec[i];
        if(right<sum){
           right=sum;
           right_index=i;
        }
    }
subarray result;
result.sum=left+right;
result.left=left_index;
result.right=right_index;
return result;

}
subarray indexprint(vector<int>&vec,int l,int h)
{
    if(l==h) return {vec[l],l,h};
    int mid=(l+h)/2;
subarray left=indexprint(vec,l,mid);
  subarray right=indexprint(vec,mid+1,h);
    subarray crosssum=cross(vec,l,mid,h);
    if(left.sum>=right.sum && left.sum>=crosssum.sum)return left;
    else if (right.sum>=left.sum && right.sum>=crosssum.sum)return right;
    else return crosssum;
}


int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0; i<n; i++)
    {
        cin>>vec[i];
    }
subarray result= indexprint(vec,0,n-1);
cout<<"sum: "<<result.sum<<endl;
cout<<"left index: "<<result.left<<endl;
cout<<"right index: "<<result.right<<endl;


}
