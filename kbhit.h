

#ifndef KBHIT_H
#define KBHIT_H

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// Function to detect if a key has been pressed (similar to kbhit)
int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    // Get the terminal settings for stdin
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    // Disable canonical mode and echoing
    newt.c_lflag &= ~(ICANON | ECHO);
    // Set the new terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    // Set the file descriptor to non-blocking mode
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    // Restore the old terminal settings and blocking mode
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

// Function to get a single character input from the user (similar to getch)
int getch() {
    struct termios oldt, newt;
    int ch;

    // Get the terminal settings for stdin
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    // Disable canonical mode and echoing
    newt.c_lflag &= ~(ICANON | ECHO);
    // Set the new terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    // Restore the old terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

#endif /* KBHIT_H */

