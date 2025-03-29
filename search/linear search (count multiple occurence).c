
#include <stdio.h>
#include <string.h>

int main() {
  int i,n;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int key;
  printf("key:");
scanf("%d",&key);
for(i=0;i<n;i++){
    if(key==a[i]){
        printf(" %d ",i);
    }
}  return 0;
}
