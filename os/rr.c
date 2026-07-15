#include <stdio.h>

int main()
{
    int n, tq;
    int at[10], bt[10], rem_bt[10];
    int ct[10], wt[10], tat[10];

    int queue[20], front = 0, rear = 0;
    int time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    /* Add first arrived process to queue */
    for (int i = 0; i < n; i++)
    {
        if (at[i] == 0)
            queue[rear++] = i;
    }

    while (completed < n)
    {
        int i = queue[front++];   // dequeue process

        if (rem_bt[i] > tq)
        {
            time += tq;
            rem_bt[i] -= tq;
        }
        else
        {
            time += rem_bt[i];
            rem_bt[i] = 0;
            ct[i] = time;
            completed++;
        }

        /* Add newly arrived processes */
        for (int j = 0; j < n; j++)
        {
            if (at[j] <= time && rem_bt[j] > 0)
            {
                int already_in_queue = 0;
                for (int k = front; k < rear; k++)
                {
                    if (queue[k] == j)
                        already_in_queue = 1;
                }
                if (!already_in_queue && j != i)
                    queue[rear++] = j;
            }
        }

        /* Re-add current process if not finished */
        if (rem_bt[i] > 0)
            queue[rear++] = i;
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
