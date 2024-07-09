#include <stdio.h>
#define ARRAY_SIZE 32

typedef struct {
    unsigned int data[ARRAY_SIZE];
} BigInt;

void initializeBigInt(BigInt* num) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        num->data[i] = 0;
    }
}

void addBigInt(const BigInt* a, const BigInt* b, BigInt* result) {
    unsigned int carry = 0;
    for (int i = 31; i >=0; i--) {
        unsigned long long sum = (unsigned long long)a->data[i] + b->data[i] + carry;
        result->data[i] = (unsigned int)sum;
        carry = (unsigned int)(sum >> 32);
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

  	addBigInt(&a, &b, &result);
   
    printf("result:");
    printNum(&result);

    return 0;
}
