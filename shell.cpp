#include <iostream>
#include <string>
#include <sys/wait.h>

int main() {
    std::string userInput;

    while (true) {
        std::cout << "cmd> " << std::flush;

        if (!std::getline(std::cin, userInput)) {
            break;
        }

        if (userInput == "exit") {
            break;
        }

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(-1);
        }

        if (pid == 0) {
            execlp(userInput.c_str(), userInput.c_str(), (char*)NULL);
            perror("execlp");
            _exit(-1);
        } else {
            if (wait(NULL) == -1) {
                perror("wait");
                exit(-1);
            }
        }
    }

    return 0;
}
