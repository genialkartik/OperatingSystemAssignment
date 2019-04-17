#include<stdio.h>
void firstFit(int B[],int m,int P[],int n) 
{
    
    int tempar[n]; 
    
    int i,j;
    for(i=0;i<n;i++){
        tempar[i]=-1;
    }
    for(i=0;i<n;i++) 
    { 
        for(j=0;j<m;j++) 
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
    for(i=0;i<n;i++) 
    { 
        printf(" %d\t\t%d\t\t",i+1,P[i]); 
        if (tempar[i]!=-1) 
            printf("%d\n",tempar[i]+1); 
        else
            printf( "Not Allocated\n"); 
    }
    
}
 void bestFit(int B[], int m, int P[], int n) 
{
    int i,j;
    int tempar[n]; 
    for(i=0;i<n;i++){
        tempar[i]=-1;
    }
    for (i=0; i<n; i++) 
    { 
        int temp = -1; 
        for (j=0; j<m; j++) 
        { 
            if (B[j] >= P[i]) 
            { 
                if (temp == -1) 
                    temp = j; 
                else if (B[temp] > B[j]) 
                    temp = j; 
            } 
        } 
        if (temp != -1) 
        { 
            tempar[i] = temp; 
            B[temp] -= P[i]; 
        } 
    } 
  
    printf( "\nProcess No.\tProcess Size\tBlock no.\n"); 
    for (i = 0; i < n; i++) 
    { 
        printf(" %d\t\t%d\t\t",i+1, P[i]); 
        if (tempar[i] != -1) 
            printf("%d\n", tempar[i] + 1); 
        else
            printf("Not Allocated\n"); 
    }
} 

void worstFit(int B[], int m, int P[],  int n) 
{
    int i,j;
    int tempar[n]; 
    for(i=0;i<n;i++){
        tempar[i]=-1;
    } 
    for (i=0; i<n; i++) 
    { 
        int t = -1; 
        for (j=0; j<m; j++) 
        { 
            if (B[j] >= P[i]) 
            { 
                if (t == -1) 
                    t = j; 
                else if (B[t] < B[j]) 
                    t = j; 
            } 
        } 
        if (t != -1) 
        { 
            tempar[i] = t; 
            B[t] -= P[i]; 
        } 
    }
    printf( "\nProcess No.\tProcess Size\tBlock no.\n"); 
    for (i = 0; i < n; i++) 
    { 
        printf(" %d\t\t%d\t\t",i+1, P[i]); 
        if (tempar[i] != -1) 
            printf("%d\n", tempar[i] + 1); 
        else
            printf("Not Allocated\n"); 
    }

} 



int main() 
{ 
    int m,n; int i,j;
    int Block[m],Process[n];
    printf("\nEnter Total No of Blocks: ");
    scanf("%d",&m);
    for(i=0;i<m;i++){
        printf("\nEnter block Size of Block B[%d]: ",i+1);
        scanf("%d",&Block[i]);
    }
    printf("\nEnter Total No of Process: ");
    scanf("%d",&n);
    for(j=0;j<n;j++){
        printf("\nEnter Process Size of Process P[%d]: ",j+1);
        scanf("%d",&Process[j]);
    }
    
    int b1[99],b2[99],b3[99];
    int p1[99],p2[99],p3[99];
    for (i = 0; i <m; i++) {
      b1[i]=Block[i];
      b2[i]=Block[i];
      b3[i]=Block[i];
   }
   for (j=0;j<n;j++) {
      p1[j]=Process[j];
      p2[j]=Process[j];
      p3[j]=Process[j];
   }
   firstFit(b1, m, p1, n); 
   
   bestFit(b2, m, p2, n);
   
   worstFit(b3, m, p3, n); 
   
    return 0 ; 
} 

