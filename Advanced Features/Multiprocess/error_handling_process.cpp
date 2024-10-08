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
        execlp("nonexistent_command", "nonexistent_command", nullptr); // Try to execute a non-existent command
        std::cerr << "exec failed!" << std::endl; // If exec fails
        return 1; // Exit the child process with an error code
    } else { // This block is executed by the parent process
        int status; // Variable to hold the status of the child process
        waitpid(pid, &status, 0); // Wait for the child process to finish

        // Check the exit status of the child process
        if (WIFEXITED(status)) {
            std::cout << "Child process exited with code: " << WEXITSTATUS(status) << std::endl; // Print the exit code
        } else {
            std::cout << "Child process did not exit normally." << std::endl; // If the process did not exit normally
        }
    }

    return 0; // End the program
}
