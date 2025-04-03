#include<bits/stdc++.h>
using namespace std;
struct Pair
{
    int max;
    int min;
};

Pair maxmin(vector<int> &vec,int l,int h)
{
    Pair result,left,right;
    if(l==h)
    {
        result.max=vec[l];
        result.min=vec[l];
        return result;
    }
    int mid=(l+h)/2;
    left=maxmin(vec,l,mid);
    right=maxmin(vec,mid+1,h);

    result.max=(left.max>right.max)?left.max:right.max;
    result.min=(left.min<right.min)?left.min:right.min;
    return result;
}


int main()
{
    int n;
    cout<<"enter your array size:";
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
    {
        cin>>vec[i];
    }
    Pair result=maxmin(vec,0,n-1);

    cout<<"max value is: "<<result.max<<endl;


    cout<<"min value is: "<<result.min<<endl;

}
