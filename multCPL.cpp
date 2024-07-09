#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#define ARRAY_SIZE 32
typedef struct {
    unsigned int data[ARRAY_SIZE];
} BigInt;

void initializeBigInt(BigInt* num) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        num->data[i] = 0;
    }
}
void addLongLongToBigInt(long long int value, BigInt* result) {
    int carry = 0;

    for (int i =31; i >=0|| carry > 0; i--) {
        unsigned long long int sum = (unsigned long long int)result->data[i] +(i == 0 ? value : 0) + carry;
        result->data[i] = (unsigned int)sum;
        carry = (int)(sum >> 32);
    }
}

void printNum(const BigInt* a){
    for(int j=0;j<=31;j++){
		    	printf("%09u",a->data[j]);
	    	}
	    	printf("\n");
    	}

void inputNum(const BigInt* a,int n){
	int g;
	if(n%9==0)
		{
			g=n/9;
		}
		else
		{
			g=(n/9)+1;
		}
		int i=31-g+1;
		if(n%9!=0 ){
		    printf("Enter first %d digits: ",(n%9));
		    scanf("%d",&a->data[i]);
		}
		else {
		    printf("Enter first %d digits:",9);
		    scanf("%d",&a->data[i]);
		}
		i++;
		while(i<=31)
		{
			printf("Enter next 9 digits:");
			scanf("%d",&a->data[i]);
			i++;
		}
		printf("\n");
		printNum(a);
	}	
	
void multiplyBigInt(const BigInt* a, const BigInt b, BigInt* result) {
    BigInt temp;
    initializeBigInt(result);
    initializeBigInt(&temp);
	int p=31,q,k=0,r=31;
	printf("\nresult=");
for ( int i = 31; i >= 0; i--)
 {
 	q=b.data[i];
 	int x=(q%10);
  	while(x>0)
  	{
  		unsigned long long int product =0;
	  	x=q%10;
	  	q=q/10;
        for (int j = 31; j >= 0; j--) {
        product = (unsigned long long int)a->data[j] * x * pow(10,k)  ;
        if(product!=0)
        {
        printf("%lld+",product);
     	}
        temp.data[p] = (unsigned int)product;

		 addLongLongToBigInt(product, result);
        }
        k++;
        p--;

    }
}
}

int main() {
    BigInt a, b, result;
    int n1,n2;
    initializeBigInt(&a);
    initializeBigInt(&b);
    initializeBigInt(&result);
    printf("enter the size of a you are about to insert:");
    scanf("%d",&n1);
    printf("enter the size of b you are about to insert:");
	scanf("%d",&n2);//do not enter 10,100,1000,10000........
	
	inputNum(&a,n1);
	inputNum(&b,n2);

   multiplyBigInt(&a, b, &result);
   printf("0\n");
	return 0;
}
