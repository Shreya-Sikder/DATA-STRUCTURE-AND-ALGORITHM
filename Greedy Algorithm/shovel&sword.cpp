/*Polycarp plays a well-known computer game (we won't mention its name). In this game,
he can craft tools of two types — shovels and swords.
To craft a shovel, Polycarp spends two sticks and one diamond;
to craft a sword, Polycarp spends two diamonds and one stick.
Each tool can be sold for exactly one dollar. How many dollars can Polycarp earn, if he
has a sticks and b diamonds? */

#include<bits/stdc++.h>
using namespace std;

int main()
{ int shovel=0,sword=0;
    int diamond,stick;
    cout<<"enter diamond: ";
    cin>>diamond;
       cout<<"enter stick: ";
    cin>>stick;
 while(diamond>0&&stick>0){

    if(diamond>=2&&stick>=1){
        diamond-=2;
        stick-=1;
        sword++;
    }

  else if(stick>=2&&stick>diamond>=1){
    stick-=2;
    diamond-=1;
     shovel++;

  }
else{break;}
 }
cout<<"total sword price: "<<sword<<endl;
cout<<"total shovel price : "<<shovel<<endl;


}
