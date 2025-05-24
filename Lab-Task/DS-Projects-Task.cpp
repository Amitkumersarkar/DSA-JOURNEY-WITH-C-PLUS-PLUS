#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// Queue for print jobs
char queue[SIZE][50];
int front = -1, rear = -1;

// Stack to track the last added jobs
char stack[SIZE][50];
int top = -1;

// Function to add job
void addPrintJob(char job[])
{
    if (rear == SIZE - 1)
    {
        printf("Queue Full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    strcpy(queue[rear], job);

    top++;
    strcpy(stack[top], job);

    printf("Print job '%s' added.\n", job);
}

// Function to cancel the last job using stack
void cancelLastJob()
{
    if (top == -1)
    {
        printf("No job to cancel.\n");
        return;
    }

    char lastJob[50];
    strcpy(lastJob, stack[top]);
    top--;

    // Remove lastJob from queue
    int found = 0;
    for (int i = front; i <= rear; i++)
    {
        if (strcmp(queue[i], lastJob) == 0)
        {
            found = 1;
            // Shift elements
            for (int j = i; j < rear; j++)
            {
                strcpy(queue[j], queue[j + 1]);
            }
            rear--;
            break;
        }
    }

    if (found)
        printf("Canceled print job: %s\n", lastJob);
    else
        printf("Job not found in queue.\n");
}

// Function to process jobs
void processJobs()
{
    if (front == -1 || front > rear)
    {
        printf("No jobs to print.\n");
        return;
    }

    printf("\nProcessing remaining print jobs:\n");
    for (int i = front; i <= rear; i++)
    {
        printf("Printing: %s\n", queue[i]);
    }
}

int main()
{
    int choice;
    char job[50];

    while (1)
    {
        printf("\n1. Add Print Job\n2. Cancel Last Job\n3. Process Jobs\n4. Exit\nChoose: ");
        scanf("%d", &choice);
        getchar(); // To clear newline from buffer

        switch (choice)
        {
        case 1:
            printf("Enter job name: ");
            gets(job); // Use fgets in real code to avoid buffer overflow
            addPrintJob(job);
            break;
        case 2:
            cancelLastJob();
            break;
        case 3:
            processJobs();
            break;
        case 4:
            exit(0);
        }
    }

    return 0;
}
