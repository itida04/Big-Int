#include <stdio.h>
#include<stdlib.h>
#include <limits.h>
#define ARRAY_SIZE 32

typedef struct {
    unsigned int data[ARRAY_SIZE];
} BigInt;

void initializeBigInt(BigInt* num) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        num->data[i] = 0;
    }
}

void printNum(const BigInt* a){
    for(int j=0;j<=31;j++){
		    	printf("%09u",a->data[j]);
	    	}
	    	printf("\n");
    	}

void subtractBigInt(const BigInt* A, const BigInt* B, BigInt* result) {
    unsigned long long int borrow = 0;

    // Iterate over digits
    for (int i = 31; i>=0; i--) {
        // Ensure subtraction doesn't result in negative values
        unsigned long long int diff;
        if (A->data[i] >= B->data[i] + borrow)
		{
            diff = A->data[i] - B->data[i] - borrow;
            result->data[i]=diff;
            borrow = 0;
        } else
		{
			//convert A into 2s complement
			//	A->data[i]= (9999999999-(A->data[i]));
			long long int x= (999999999-(A->data[i]));
			diff=x+B->data[i];
			if(diff/1000000000==1)
			{
				diff=999999999-(diff%1000000000);
				result->data[i]=diff;
			}
			borrow = 1;
    	}
	}
	printNum(result);
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
void compare(const BigInt* a,const BigInt* b,int n ,BigInt* result){
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
	int flag=0;
	while(i<=31 && flag==0)
		{
				if(a->data[i]>b->data[i])
				{
					printf("Subtracting b from a: ");
					subtractBigInt(a,b,result);
					flag=1;
				}
				else if (a->data[i]<b->data[i]){
					printf("Subtracting a from b: ");
					subtractBigInt(b,a,result);
					flag=1;
				}
				else{
					i++;
					
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
	scanf("%d",&n2);
	inputNum(&a,n1);
	inputNum(&b,n2);
	if(n1>n2)
	{
		printf("subtracting b from a:");
		subtractBigInt( &a,&b,&result);
	}
	else if(n2>n1)
	{
		printf("subtracting a from b:");
		subtractBigInt( &b,&a,&result);
	}
	else
	{
		compare(&a,&b,n1,&result);
	}
	return 0;
}

