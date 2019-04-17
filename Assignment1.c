
#include<stdio.h>
int main()
{
    int i,m;
    printf("\nEnter the Total number of processes: ");
    scanf("%d",&m);
    int arrival[m];
    int burst[m],burst1[m];
    int waiting[m];
    int tarrival[m];
    int tq1=3;
    int tq2=6;
    float avgT=0;
    float avgW=0;
    int time=0;
    int x=0;
    int ct[m];
    int ar[m];
    printf("\nEnter Arrival Time and the Burst Time of Processes:");
    for(i=0;i<m;i++)
    {  scanf("%d%d",&arrival[i],&burst[i]);
        burst1[i]=burst[i];    
    }
    
    printf("\nFirst Iterarrivalion(TQ=3)\n");               //first Iteration
    for(i=0;i<m;i++)
    {  
    if(arrival[i]<=time)
    {
        if(burst[i]>tq1){
        
        time=time+tq1;
        burst[i]=burst[i]-tq1;
        printf("\nP[%d] : %d",i+1,burst[i]);
        }
        else
        {
        time+=burst[i];
        ct[i]=time;
        tarrival[i]=ct[i]-arrival[i];
        ar[x]=i;
        x++;
        burst[i]-=tq1;
        printf("\nP[%d] : %d",i+1,burst[i]);
        }    
        }
    }
    printf("\n\nAFTER ITERarrivalION 2 (TQ=6)");             //Second Iteration
    for(i=0;i<m;i++)
    {
    if(arrival[i]<=time)
    {
        if(burst[i]>tq1){
        time+=tq2;
        burst[i]=burst[i]-tq2;
        
        printf("\nP[%d] : %d",i+1,burst[i]);
        }
        else
        {
        time+=burst[i];
        ct[i]=time;
        tarrival[i]=ct[i]-arrival[i];
        ar[x]=i;
        x++;
        burst[i]-=tq2;
        printf("\nP[%d] : %d",i+1,burst[i]);
        }
    }
    }
    printf("\n\n3RD ITERarrivalION");                        //Third Iteration
    int j,temp;
    //shorting for SRTF
    for(i=0;i<m;i++)
    {
        for(j=0;j<m-i-1;j++)
        {if(burst[j]>burst[j+1])
        {
        
            temp=burst[j];
            burst[j]=burst[j+1];
            burst[j+1]=temp;
            }
        }
    }
    int y=0;
    for(i=0;i<m;i++){
        for(j=0;j<x;j++){
            if(i==ar[j]);
             y=1;
        }
        if(y==1){
            continue;
        }
        else{
            time+=burst[i];
            ct[i]=time;
            tarrival[i]=ct[i]-arrival[i];
        }
    }
    for(i=0;i<m;i++)
    {
        tarrival[i]=ct[i]-arrival[i];
        waiting[i]=tarrival[i]-burst1[i];
        printf("\n\nProcess | Compilation Time | TurnAround Time | Waiting Time\n");
        printf("  P[%d] \t\t %d \t\t %d \t\t %d \n",i+1,ct[i],tarrival[i],waiting[i]);
        avgT=avgT+tarrival[i];
        avgW =avgW +waiting[i];
        
    }
    avgT =avgT*1.0/m;
    avgW =avgW*1.0 /m;
    printf("\n\nAverage turn arrounf time: %f",avgT);
    printf("\nAverage waiting time:%f",avgW);
    }
