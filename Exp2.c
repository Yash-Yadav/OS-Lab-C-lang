#include <stdio.h>
#include <conio.h>
void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}
void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}
void findingTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt);
    findTurnaroundTime(processes, n, bt, wt, tat);
    printf("Processes \tBurst Time \tWaiting \tTurn Around Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("  %d   \t\t%d   \t\t%d   \t\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time: %f", (float)total_wt / (float)n);
    printf("Average Turn Around Time: %f", (float)total_tat / (float)n);
}
int main()
{
    int processes[3] = { 1, 2, 3 }, n = 3, burst_time[3] = { 10, 5, 8 };
    findingTime(processes, n, burst_time);
    getch();
}
