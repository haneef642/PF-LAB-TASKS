#include<stdio.h>
int main(){
	
 
  int factorial=1;	
  int n;
  printf("Enter a number");
  scanf("%d",&n);
  
  if(n<0){
  	printf("The Should be greater than 0");
  	
  }else{
  	
  	for(int i=1;i<=n;i++)
  	factorial=factorial*i;
  	
  	printf("The factorial of  %d = %d",n,factorial);
  }
  return 0;
  
}
