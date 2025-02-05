#include <stdio.h>
#include <stdlib.h>

int main() {
    char ipAddress[100];
    int pingResult;

    // Get IP address from user
    printf("Enter the IP address to ping: ");
    scanf("%s", ipAddress);

    // Build the ping command
    char command[150];
    snprintf(command, sizeof(command), "ping -c 4 %s > /dev/null 2>&1", ipAddress);

    // Execute the ping command
    pingResult = system(command);

    // Check the result
    if (pingResult == 0) {
        printf("Ping to %s is active.\n", ipAddress);
    } else {
        printf("Ping to %s failed.\n", ipAddress);
    }

    return 0;
}
