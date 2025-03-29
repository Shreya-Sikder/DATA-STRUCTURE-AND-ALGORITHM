
#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,n,temp=0;
    scanf("%d",&n);
    int a[n];
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
 int key;
    printf("key:");
    scanf("%d",&key);
int low=0,count=0;
int high=n-1;
while(low<=high){
        int mid=(low+high)/2;
    if(key==a[mid]){
      printf("at index: %d",mid);
      count++;
        break;
    }
    else if(key>a[mid]){

         high=mid-1;
    }
    else if(key<a[mid]){

         low=mid+1;
    }
}
if(count==0){
    printf("-1");
}

    return 0;
}
