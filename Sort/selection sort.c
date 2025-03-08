#include <stdio.h>
#include <stdlib.h>
int main()
{  int n,i,j;
int temp=0;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++){
    scanf("%d",&a[i]);
}
for(i=0;i<n-1;i++){
     int s=i;
    for(j=i+1;j<n;j++){
            if(a[j]<a[s])
      {
          s=j;
      }
    temp=a[s];
    a[s]=a[i];
    a[i]=temp;

}}
for(i=0;i<n;i++){
   printf(" %d \n",a[i]);
}
  return 0;}

