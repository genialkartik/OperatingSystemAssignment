#include<stdio.h>

int main()
{

  int i,j,n,time,remain,flag=0,q;
  int wt=0,tt=0,at[10],bt[10],rbt[10];
  printf("Enter Total Process:\t ");
  scanf("%d",&n);
  remain=n;
  for(i=0;i<n;i++)
  {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",i+1);
    scanf("%d",&at[i]);
    scanf("%d",&bt[i]);
    rbt[i]=bt[i];
  }
  printf("Enter Time Quantum:\t");
  scanf("%d",&q);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  
  f
  
  
  
  
  
  
  
  
  
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);

  return 0;
}
