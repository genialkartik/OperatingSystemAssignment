// the structure for round robin scheduling algorithm with gantt chart.
 
typedef struct struct-rra
{
int process_id, burst_time, burst_time_bal;
int total_average_time, waiting_time;
} PCB;
int main()    {
  struct-rra process[10];
  int i,j,k,n,tq;
  int sum_burst_time=0,sum_total_average_time=0,sum_waiting_time=0,tq_used=0;
  int gantt[2][50];
  printf("Enter number of process required : ");
  scanf("%d",&amp;n);
  for(i=0;i&lt;n;i++) 
  {
    printf("Burst-time of process %d: ",i+1);
    process[i].process_id = i+1;
    scanf("%d",&amp;process[i].burst_time);
    process[i].burst_time_bal = process[i].burst_time;
  }
  printf("enter time quantums of the process : ");
  scanf("%d",&amp;tq);
  for( i=0;i&lt;n;i++)
    sum_burst_time += process[i].burst_time;
  printf("\nsum of burst time = %d\n",sum_burst_time);
  k=0;
  do
  {
    for( i=0;i&lt;n;i++) {
      if( process[i].burst_time_bal &gt; 0 &amp;&amp; process[i].burst_time_bal &lt;= tq )
      {
        tq_used += process[i].burst_time_bal;
        process[i].total_average_time = tq_used;
        process[i].waiting_time = process[i].total_average_time - process[i].burst_time;
        process[i].burst_time_bal = 0;
        gantt[0][k] = process[i].process_id;
        gantt[1][k] = tq_used;
        k++;
      }
      else if( process[i].burst_time_bal &gt;0 )
      {
        tq_used += tq;
        process[i].burst_time_bal -= tq;
        gantt[0][k] = process[i].process_id;
        gantt[1][k] = tq_used;
        k++;
      }
      else if( process[i].burst_time_bal &lt; 0 )
      {
        printf("\nError: burst time Negative \n");
        exit(1);
      }
  } while( tq_used != sum_burst_time);
printf("\n <strong>round robin scheduling program in c with gantt chart</strong> \n\n");
printf("process_id: ");
for( i=0; i&lt;n;i++)
printf("%4d",gantt[0][i]);
printf("\n\nTime: ");
for( i=0; i&lt;n;i++)
printf("%4d",gantt[1][i]);
for( i=0;i&lt;n;i++)
sum_waiting_time += process[i].waiting_time;
for( i=0;i&lt;n;i++)
sum_total_average_time += process[i].total_average_time;
printf("\n\nprocess_id: ");
for( i=0;i&lt;n;i++)
printf("%4d",i+1);
printf("\nburst_timeime:");
for( i=0;i&lt;n;i++)
printf("%4d",process[i].burst_time);
printf("\n Total <span style="text-decoration: underline;">round robin scheduling program in c with arrival time</span> : ");
for( i=0;i&lt;n;i++)
printf("%4d",process[i].total_average_time);
printf("\nwaiting_timeime:");
for( i=0;i&lt;n;i++)
printf("%4d",process[i].waiting_time);
printf("\n\nTotal waiting time = %d\n",sum_waiting_time);
printf("Average waiting time = %.2f\n",(float)sum_waiting_time/n);
printf("\nTotal turn around time = %d\n",sum_total_average_time);
printf("Average turn around time = %.2f\n\n",(float)sum_total_average_time/n);
return 0;
}
