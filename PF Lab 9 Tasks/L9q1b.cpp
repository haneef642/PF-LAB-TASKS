#include <stdio.h>
int main() {
int n;
printf("Enter the Amount of Rows u want to print:");
scanf("%d",&n);
for(int i=0;i<=n;i++) {
for(int j=1;j<i;j++) {
printf("%d",j);
}
for(int k=i;k>0;k--) {
printf("%d",k);
}
printf("\n");
}
return 0;
}

