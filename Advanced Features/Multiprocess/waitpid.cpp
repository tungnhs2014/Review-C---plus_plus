#include <iostream>
#include <unistd.h> // For using fork()
#include <sys/wait.h> // For using waitpid()

int main() {
    pid_t pid1 = fork(); // Create the first child process

    if (pid1 < 0) { // Check if the first process creation failed
        std::cerr << "Failed to create first process!" << std::endl;
        return 1; // Exit the program with an error code 1
    } else if (pid1 == 0) { // This block is executed by the first child process
        std::cout << "First child process. PID: " << getpid() << std::endl;
        sleep(2); // Simulate some work
        return 0; // Exit normally
    }

    pid_t pid2 = fork(); // Create the second child process

    if (pid2 < 0) { // Check if the second process creation failed
        std::cerr << "Failed to create second process!" << std::endl;
        return 1; // Exit the program with an error code 1
    } else if (pid2 == 0) { // This block is executed by the second child process
        std::cout << "Second child process. PID: " << getpid() << std::endl;
        sleep(4); // Simulate some work
        return 0; // Exit normally
    }

    // Wait for the first child process to finish
    int status1;
    waitpid(pid1, &status1, 0);
    std::cout << "First child exited with code: " << WEXITSTATUS(status1) << std::endl;

    // Wait for the second child process to finish
    int status2;
    waitpid(pid2, &status2, 0);
    std::cout << "Second child exited with code: " << WEXITSTATUS(status2) << std::endl;

    return 0; // End the program
}
