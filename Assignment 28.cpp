#include<stdio.h>
#include<string.h>
void firstFit(int B[],int m,int P[],int n) 
{
    int i,j;
    int tempar[n]; 
    memset(tempar, -1, sizeof(tempar));
    for(int i=0;i<n;i++) 
    { 
        for(int j=0;j<m;j++) 
        { 
            if(B[j]>=P[i]) 
            {
                tempar[i] = j; 
                B[j] -= P[i]; 
                break;
            } 
        } 
    } 
    printf("\nProcess No.\tProcess Size\tBlock no.\n"); 
    for(int i=0;i<n;i++) 
    { 
        printf(" %d\t\t%d\t\t",i+1,P[i]); 
        if (tempar[i]!=-1) 
            printf("%d\n",tempar[i]+1); 
        else
            printf( "Not Allocated\n"); 
         
    } 
    for(int j=0;j<m;j++){
    	printf("Block[%d]: %d\n",j,B[j]);
	}
} 
  
// Driver code 
int main() 
{ 
    int m,n; int i,j;
    int B[m],P[n];
	printf("\nEnter Total No of Blocks: ");
	scanf("%d",&m);
	for(i=0;i<m;i++){
		printf("\nEnter block Size of Block B[%d]: ",i+1);
		scanf("%d",&B[i]);
	}
	printf("\nEnter Total No of Process: ");
	scanf("%d",&n);
	for(j=0;j<n;j++){
		printf("\nEnter Process Size of Process P[%d]: ",j+1);
		scanf("%d",&P[j]);
	}
	
	
    firstFit(B, m, P, n); 
    return 0 ; 
} 

