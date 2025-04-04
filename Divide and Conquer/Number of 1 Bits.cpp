#include<bits/stdc++.h>
using namespace std;

    int hammingWeight(int n) {
      vector<int> binary;

    if (n == 0)
      return 0;

    while (n > 0) {
        binary.push_back(n % 2);
        n = n / 2;
    }
 int count=0;
    for (int i = binary.size() - 1; i >= 0; i--) {
  if(binary[i]==1){
    count++;
  }
    }
    return count;
    }



int main()
{

    int n;
    cout<<"Number in decimal: ";
    cin>>n;

    int result=hammingWeight(n);

    cout<<"total: "<<result<<endl;

}
