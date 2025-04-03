#include<bits/stdc++.h>
using namespace std;

int countvowel(string s,int l, int h)
{
    if(l==h)
    {  char ch=tolower(s[l]);
        return (s[l]=='a'||s[l]=='e'||s[l]=='i'||s[l]=='o'||
                 s[l]=='u'||s[l]=='A'||s[l]=='E'||s[l]=='O'||s[l]=='I'||s[l]=='U')? 1:0;
    }

    int mid=(l+h)/2;
    int leftcount=countvowel(s,l,mid);
int rightcount=countvowel(s,mid+1,h);

    return (leftcount+rightcount);
}
int main()
{

    string s;
    getline(cin,s);
    int h= s.length()-1;

    cout<<"Total number of vowels :"<<countvowel(s,0,h)<<endl;


}
