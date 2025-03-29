
#include <stdio.h>
#include <string.h>
int main() {
  int i,j,n;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int key;
  printf("key:");
scanf("%d",&key);
int ans=0;
for(i=0;i<n;i++){
        if(key<a[i]){
          ans=a[i];
        break;
    }
}
printf("%d",ans);
    return 0;
}

