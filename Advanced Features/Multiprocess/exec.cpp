#include <iostream>
#include <unistd.h> // For using fork() and exec()
#include <sys/wait.h> // For using wait()

int main() {
    // Create a new process
    pid_t pid = fork();

    if (pid < 0) { // Check if process creation failed
        std::cerr << "Failed to create process!" << std::endl;
        return 1; // Exit the program with an error code 1
    } else if (pid == 0) { // This block is executed by the child process
        // Replace the child process with the 'ls' command
        execlp("ls", "ls", nullptr); // List files in the current directory
        std::cerr << "exec failed!" << std::endl; // If exec fails
    } else { // This block is executed by the parent process
        std::cout << "This is the parent process. Child PID: " << pid << std::endl;
        wait(nullptr); // Wait for the child process to finish
    }

    return 0; // End the program
}
