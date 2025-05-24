#include <iostream>
#include <queue> // For std::queue (FIFO)
#include <stack> // For std::stack (LIFO)
#include <string>
#include <unordered_set> // For efficient lookup of cancelled job IDs

// Structure to represent a print job
struct PrintJob
{
    int id;
    std::string name;

    // Constructor for convenience
    PrintJob(int job_id, const std::string &job_name) : id(job_id), name(job_name) {}
};

class PrinterQueueSystem
{
private:
    std::queue<PrintJob> printQueue;       // Main queue for processing (FIFO)
    std::stack<int> cancellationStack;     // Stack to track job IDs for LIFO cancellation
    std::unordered_set<int> cancelledJobs; // Set to store IDs of cancelled jobs

public:
    // 1. Adds print jobs to the queue.
    void addPrintJob(int job_id, const std::string &job_name)
    {
        PrintJob newJob(job_id, job_name);
        printQueue.push(newJob);
        cancellationStack.push(job_id); // Add job ID to stack for potential cancellation
        std::cout << "Added job: '" << newJob.name << "' (ID: " << newJob.id << ") to the queue." << std::endl;
    }

    // 2. Allows a user to cancel the last added print job using the stack.
    void cancelLastAddedPrintJob()
    {
        if (cancellationStack.empty())
        {
            std::cout << "No jobs to cancel." << std::endl;
            return;
        }

        int jobIdToCancel = cancellationStack.top(); // Get the ID from the top of the stack
        cancellationStack.pop();                     // Remove it from the stack
        cancelledJobs.insert(jobIdToCancel);         // Mark this job ID as cancelled
        std::cout << "Attempting to cancel job with ID: " << jobIdToCancel << " (most recent)." << std::endl;
    }

    // 3. Processes the remaining print jobs in the queue.
    void processRemainingPrintJobs()
    {
        std::cout << "\n--- Processing Print Jobs ---" << std::endl;
        if (printQueue.empty())
        {
            std::cout << "No jobs in the queue to process." << std::endl;
            return;
        }

        int processedCount = 0;
        while (!printQueue.empty())
        {
            PrintJob currentJob = printQueue.front(); // Get the job at the front (FIFO)
            printQueue.pop();                         // Remove it from the queue

            // Check if this job has been marked as cancelled
            if (cancelledJobs.count(currentJob.id))
            { // .count() returns 1 if found, 0 otherwise
                std::cout << "Skipping cancelled job: '" << currentJob.name << "' (ID: " << currentJob.id << ")." << std::endl;
                cancelledJobs.erase(currentJob.id); // Remove from the set as it's now "processed" (skipped)
            }
            else
            {
                std::cout << "Printing job: '" << currentJob.name << "' (ID: " << currentJob.id << ")." << std::endl;
                processedCount++;
            }
        }
        std::cout << "--- Finished processing " << processedCount << " jobs. ---" << std::endl;
    }
};

// --- Simple Program Example ---
int main()
{
    PrinterQueueSystem printerSystem;

    // Add some print jobs
    printerSystem.addPrintJob(101, "Document A");
    printerSystem.addPrintJob(102, "Image B");
    printerSystem.addPrintJob(103, "Report C");
    printerSystem.addPrintJob(104, "Spreadsheet D");

    // Simulate a user cancelling the last added job
    std::cout << "\nSimulating a cancellation:" << std::endl;
    printerSystem.cancelLastAddedPrintJob(); // Should cancel Spreadsheet D

    // Add another job after cancellation
    printerSystem.addPrintJob(105, "Presentation E");

    // Simulate another cancellation
    std::cout << "\nSimulating another cancellation:" << std::endl;
    printerSystem.cancelLastAddedPrintJob(); // Should cancel Presentation E

    // Process the remaining jobs
    printerSystem.processRemainingPrintJobs();

    std::cout << "\n--- Another scenario ---" << std::endl;
    PrinterQueueSystem newPrinterSystem;
    newPrinterSystem.addPrintJob(201, "Invoice 1");
    newPrinterSystem.addPrintJob(202, "Invoice 2");
    newPrinterSystem.cancelLastAddedPrintJob(); // Cancels Invoice 2
    newPrinterSystem.addPrintJob(203, "Invoice 3");
    newPrinterSystem.processRemainingPrintJobs();

    return 0;
}