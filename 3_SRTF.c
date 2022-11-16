#include <stdio.h>
int main()
{
int AT[10], BT[10], temp[10];
int i, smallest, count = 0, time, n;
double WT = 0, TAT = 0, exitime;
float average_waiting_time, average_TAT;
printf("\nEnter the Total Number of Processes:\t");
scanf("%d", &n);
printf("\nEnter Details of %d Processesn", n);
for(i = 0; i < n; i++)
{
printf("\nEnter Arrival Time:\t");
scanf("%d", &AT[i]);
printf("Enter Burst Time:\t");
scanf("%d", &BT[i]);
temp[i] = BT[i];
}
BT[9] = 9999; //infinity value

for(time = 0; count != n; time++)
{
smallest = 9;
for(i = 0; i < n; i++)
{
if(AT[i] <= time && BT[i] < BT[smallest] && BT[i] > 0)
{
smallest = i;
}
}
BT[smallest]--;
if(BT[smallest] == 0)
{
count++;
exitime = time + 1;
WT = WT + exitime - AT[smallest] - temp[smallest];
TAT = TAT + exitime - AT[smallest];
}
}

average_waiting_time = WT / n;
average_TAT = TAT / n;
printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
printf("Average Turnaround Time:\t%lf\n", average_TAT);
return 0;
}
