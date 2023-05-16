#include<stdio.h>
#include<math.h>

int multiply(double n1,double n2){
	int n=0;
	int max=(n1<n2)?n2:n1;
	while(max!=0){
		max/=10;
		n++;
	}

	if(n==1){
		return n1*n2;
	}
	
	// if ((int) n%2==1){
	// 	n++;
	// }
	int m=floor(n/2);
	
	int a,b,c,d;
	a=(int) n1/(int)pow(10,m);
	b=(int) n1%(int)pow(10,m);
	c=(int) n2/(int)pow(10,m);
	d=(int) n2%(int)pow(10,m);
	// printf("%d %d %d %d",a,b,c,d);
	int ac=multiply(a,c);
	int bd=multiply(b,d);
	
	// int ac= a*c;
	// int bd=b*d;
	
	int t=multiply(a+b,c+d)-ac-bd;
	// int t=(a+b)*(c+d)-ac-bd;
	
	int ans=(ac*pow(10,2*m))+(t*pow(10,m))+bd;
	
	return ans;
	
}


void main(){
	int n=0,n1,n2,max;
	printf("Enter 2 numbers:\n");
	scanf("%d%d", &n1, &n2);
	
	
	int ans=multiply(n1,n2);
	printf("\nANS= %d",ans);
	
	
}
