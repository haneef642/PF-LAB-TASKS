#include<stdio.h>

int main(){
	
  int bolts,nuts,washers,total_cost;
  printf("Enter bolts \n Enter nuts\n Enter Washers ");
  scanf("%d%d%d",&bolts,&nuts,&washers);
  
  if(bolts==nuts && 2*bolts==washers){
  
  printf("Ok");
  
  }else if(bolts!=nuts && bolts>nuts && 2*bolts==washers){
  	
  	printf(" Check the order     :   Two few nuts");
  }else if(bolts!=nuts && nuts>bolts   && 2*bolts==washers){
  	
  	printf("check the order    :  Two few bolts");
  }else{
  	
  	printf(" Check the order :  Too few Washers");
  }
  
  

  total_cost=5*bolts+3*nuts+1*washers;
  
  printf("\nTotal Cost is %d ",total_cost);
}
