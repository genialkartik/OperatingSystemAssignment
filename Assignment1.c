#include<stdio.h>
#include<conio.h>
int k=0;
void check_at(){
	for(j=front+1;j<n;j++){
		if(at[j]<=time){
			rear=rear+1;
			queue_1[rear]=rbt[j];
		}
	}
}
void sent_to_queue2(int t[]){
	temp[k]=t[];
}
int main(){
int n, time=0,i,j,k,total_bt=0,temp1,temp2,temp3;
int q1=3,q2=6;
int front=-1;
int rear=-1;
int at[i],bt[i],rbt[i],ct[i],wt[i],ctime[i],tat[i];
int flag[i]=0,temp[i];
printf("\nEnter the no of process: ");
scanf("%d",&n);					//total no of process
for(i=0;i<=n-1;i++){				//entering at and bt
	printf("\nEnter Arrival Time and Burst Time for process P[%d]: ",i);
	scanf("%d%d",at[i],bt[i]);
	rbt[i]=bt[i];
	total_bt=total_bt+bt[i];
	}
int queue_1[total_bt];		//first queue

//sorting process in accending ordre wrt at
for(i=1;i<=n-1;i++{
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
			}
		}
}
//adding first process to queue1
if(rear==total_bt)}
	printf("\nOverflow");
	}
else{
	if(front==-1){
		front=0;
	}
	rear=rear+1;
	queue_1[rear]=rbt[0];
	
	}
//process scheduling initiated
i=0;
do{
if(front==-1||front>rear){
	printf("\nunderflow");
	return ;
	}
else{
	rbt[i]=queue_1[front];
	if(flag[i]==0){
		//if process traversed first time
		if(rbt[i]>q1){
			time=time+q1;
			rbt[i]=rbt[i]-q1;
			check_at();
			rear=rear+1;
			queue_1[rear]=rbt[i];
			flag[i]++;
		}
		//if process traversed second time
		else{
			time=time+q1;
			check_at();
			ctime[i]=time;
			tat[i]=ctime-at[i];
			wt[i]=tat[i]-bt[i];
		}
	}
	
	else if(flag[i]==1){
		//if process traversed first time
		if(rbt[i]>q2){
			time=time+q2;
			rbt[i]=rbt[i]-q2;
			check_at();
			rear=rear+1;
			queue_1[rear]=rbt[i];
			flag[i]++;
		}
		//if process traversed second time
		else{
			time=time+q2;
			check_at();
			ctime[i]=time;
			tat[i]=ctime-at[i];
			wt[i]=tat[i]-bt[i];
		}
	}
	else if(flag[i]>1){
		send_to_queue2(rbt[i]);
	}
		
	}
