
#include <stdio.h>
#include <string.h>
int main()
{
    int i,j, n;
    scanf("%d",&n);
    int a[n];
for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

int key=0,first=0,last=0;
printf("key:");
  scanf("%d",&key);

    for(i=0;i<n;i++){
      if(a[i]==key) {
        if(first==0){
            first=a[i-1];
        }
      }
    }



    if(first==0){
        printf("nai bhai");
    }
else {
    printf("%d",first);
}
}
