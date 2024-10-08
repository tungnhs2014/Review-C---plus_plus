#include <iostream>
#include <unistd.h> // For using pipe()
#include <string.h> // For using strlen()

int main() {
    int fd[2]; // Array to hold the two ends of the pipe
    pid_t pid;

    // Create a pipe
    if (pipe(fd) == -1) {
        std::cerr << "Failed to create pipe!" << std::endl;
        return 1; // Exit the program with an error code 1
    }

    pid = fork(); // Create a new process

    if (pid < 0) { // Check if process creation failed
        std::cerr << "Failed to create process!" << std::endl;
        return 1; // Exit the program with an error code 1
    } else if (pid == 0) { // This block is executed by the child process
        close(fd[1]); // Close the write end of the pipe
        char buffer[100]; // Buffer to store the message
        read(fd[0], buffer, sizeof(buffer)); // Read data from the pipe
        std::cout << "Child process received: " << buffer << std::endl; // Print the received message
        close(fd[0]); // Close the read end of the pipe
    } else { // This block is executed by the parent process
        close(fd[0]); // Close the read end of the pipe
        const char* msg = "Hello from the parent process!"; // Message to send
        write(fd[1], msg, strlen(msg) + 1); // Write data to the pipe
        close(fd[1]); // Close the write end of the pipe
        wait(nullptr); // Wait for the child process to finish
    }

    return 0; // End the program
}
