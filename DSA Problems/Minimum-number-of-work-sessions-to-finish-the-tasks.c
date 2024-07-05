/* There are n tasks assigned to you. The task times are represented as an integer array tasks of length n, where the ith task takes tasks[i] hours to finish.
   A work session is when you work for at most sessionTime consecutive hours and then take a break.

   You should finish the given tasks in a way that satisfies the following conditions:

   If you start a task in a work session, you must complete it in the same work session.
   You can start a new task immediately after finishing the previous one.
   You may complete the tasks in any order.
*/

#include <stdio.h>

int count(int tasks[], int time, int taskNumber)
{
    int count = 0;
    int currentTime = 0;
    for (int i = 0; i < taskNumber; i++)
    {
        if (tasks[i] + currentTime <= time)
        {
            currentTime += tasks[i];
        }
        else
        {
            count++;
            currentTime = tasks[i];
        }
    }

    return count + (currentTime > 0 ? 1 : 0);
}

int main()
{
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    int tasks[n];
    printf("Enter the time for each task:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tasks[i]);
    }

    int sessionTime;
    printf("Enter the maximum time per work session: ");
    scanf("%d", &sessionTime);

    int sessionNumber = count(tasks, sessionTime, n);
    printf("Number of working sessions required: %d", sessionNumber);

    return 0;
}