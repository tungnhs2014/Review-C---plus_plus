#include <iostream>
#include <unistd.h> // For using fork()

int main() {
    // Create a new process
    pid_t pid = fork();

    if (pid < 0) { // Check if process creation failed
        std::cerr << "Failed to create process!" << std::endl;
        return 1; // Exit the program with an error code 1
    } else if (pid == 0) { // This block is executed by the child process
        std::cout << "This is the child process. PID: " << getpid() << std::endl;
    } else { // This block is executed by the parent process
        std::cout << "This is the parent process. PID: " << getpid() << ", Child PID: " << pid << std::endl;
    }

    return 0; // End the program
}
