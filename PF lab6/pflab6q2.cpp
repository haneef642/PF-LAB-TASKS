#include<stdio.h>
int main(){
	
	int i=2;
	int n;
	printf("Enter a number");
	scanf("%d",&n);
	
	if(n>=1){
		
		while(i<=n){
			printf(" %d ",i);
			i+=2;
			
		}
	}else{
		printf("The number should be greater than 0");
	}
	return 0;
}
