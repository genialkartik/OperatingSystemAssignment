#include<stdio.h>
int main(){
int n, time=0,i=0,j,total_bt=0,temp1,temp2,temp3,temp4 ;
int q1=3,q2=6;
int front=-1;
int rear=-1;
int at[i],bt[i],rbt[i],wt[i],ctime[i],tat[i],p[i];
int flag=0;
int ar[i];
int queue_1[total_bt];
int totalwt,totaltat;
printf("\nEnter the no of process: ");
scanf("%d",&n);                    //total no of process
for(i=0;i<=n-1;i++){                //entering at and bt
    printf("\nEnter Arrival Time and Burst Time for process P[%d]: ",i);
    scanf("%d%d",&at[i],&bt[i]);
    rbt[i]=bt[i];
    
    total_bt=total_bt+bt[i];
    p[i]=i;
    }
printf("\n\tProcess\t|\tArival Time\t|\tBurst Time\t|\tcompilation\t|\tturn around\t|\twaiting time\n");
//sorting process in accending ordre wrt at
for(i=0;i<=n-1;i++){
    for(j=0;j<n-i-1;j++){
        if(at[j]>at[j+1]){
            temp1=at[j];
            temp2=rbt[j];
            temp3=bt[j];
            at[j]=at[j+1];
            rbt[j]=rbt[j+1];
            bt[j]=bt[j+1];
            at[j+1]=temp1;
            rbt[j+1]=temp2;
            bt[j+1]=temp3;
            temp4=p[j];
            p[j]=p[j+1];
            p[j+1]=temp4;
            }
        }
}


i=0;
//adding first process to queue1
if(rear==total_bt-1){
    printf("\nOverflow");
    }
else{
    if (front == - 1)
        front = 0;
    rear=rear+1;
    queue_1[rear]=rbt[0];
    
    }
//process scheduling initiated
int sum=0;
i=0;
p[i]=0;
int count=0;
int x=0;

do{
    flag=queue_1[front];
    for(j=0;j<n;j++){
        if(rbt[j]==flag){
            ar[x]=j;
        }
    }
    x++;
    rbt[i]=flag;
    front=front+1;
    for(j=0;j<x;j++){
         if(rbt[ar[j]]==rbt[i]){
            count++;
       }   
    }
    if(count==1){
        
        //if process traversed first time
        if(rbt[i]>q1){
            time=time+q1;
            rbt[i]=rbt[i]-q1;
            
            for(j=i+1;j<n;j++){
                if(at[j]<=time){
                rear=rear+1;
                queue_1[rear]=rbt[j];
                
                }
            }
            rear=rear+1;
            queue_1[rear]=rbt[i];
            
        }
        //if process traversed second time
        else{
            
            time=time+rbt[i];
            
            for(j=i+1;j<n;j++){
                if(at[j]<=time){
                rear=rear+1;
                queue_1[rear]=rbt[j];
                }
                
            }
            
            ctime[i]=time;
            tat[i]=ctime[i]-at[i];
            wt[i]=tat[i]-bt[i];
            totalwt+=ctime[i];
                totaltat+=rbt[i];
        }
        
        
        printf("\n\t%d\t\t%d\t\t%d\t\t%d\t\t%d",i,at[i],bt[i],ctime[i],tat[i],wt[i]);

    }

    else if(count==2){
        //if process traversed first time
        
        if(rbt[i]>q2){
            time=time+q2;
            rbt[i]=rbt[i]-q2;
            
            for(j=i+1;j<n;j++){
                if(at[j]<=time){
                rear=rear+1;
                queue_1[rear]=rbt[j];
                }
            }
            
            rear=rear+1;
            queue_1[rear]=rbt[i];
            

        }
        //if process traversed second time
        else{
            time=time+rbt[i];            
            for(j=i+1;j<n;j++){
                if(at[j]<=time){
                rear=rear+1;
                queue_1[rear]=rbt[j];
                }
            }
            
            ctime[i]=time;
            tat[i]=ctime[i]-at[i];
            wt[i]=tat[i]-bt[i];
            totalwt+=ctime[i];
                totaltat+=rbt[i];
            printf("\n\t%d\t\t%d\t\t%d\t\t%d\t\t%d",i,at[i],bt[i],ctime[i],tat[i],wt[i]);
        
        }
     }
    else if(count>2){
        
            
                time=time+rbt[i];
                for(j=i+1;j<n;j++){
                    if(at[j]<=time){
                    rear=rear+1;
                    queue_1[rear]=rbt[j];
                    }
                }
                ctime[i]=time;
                tat[i]=ctime[i]-at[i];
                wt[i]=tat[i]-bt[i];
                totalwt+=ctime[i];
                totaltat+=rbt[i];
                printf("\n\t%d\t\t%d\t\t%d\t\t%d\t\t%d",i,at[i],bt[i],ctime[i],tat[i],wt[i]);
            
        }
    
    i++;
    sum+=time;
    count=0;

}while(sum!=total_bt);
float avgwt=totalwt*1.0/n;
float avgtat=totaltat*1.0/n;
printf("\nAverage waiting time: %f",avgwt);
printf("\nAverage TurnAround Time: %f",avgtat);

}
