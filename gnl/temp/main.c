#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

// Compile-time configuration
#define MAX_PASSWORD_LENGTH 100
#define CHAR_SET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()"
#define PRINT_ATTEMPTS // Uncomment to enable attempt logging

// Compute character set size at compile time
#define CHAR_SET_SIZE (sizeof(CHAR_SET) - 1)

// Fast uint64 to string conversion
static inline int u64_to_str(uint64_t value, char *str) {
    char *ptr = str;
    
    // Handle zero explicitly
    if (value == 0) {
        *ptr++ = '0';
    } else {
        char temp[20];
        char *temp_ptr = temp;
        while (value > 0) {
            *temp_ptr++ = '0' + (value % 10);
            value /= 10;
        }
        // Reverse the temporary buffer into str
        while (temp_ptr > temp) {
            *ptr++ = *--temp_ptr;
        }
    }
    *ptr++ = ':';
    *ptr++ = ' ';
    return ptr - str;
}

// Optimized password guessing function
static inline bool guess_password(const char *target, char *attempt) {
    const int target_length = strlen(target);
    uint64_t indices[MAX_PASSWORD_LENGTH] = {0};
    memset(attempt, CHAR_SET[0], target_length);
    attempt[target_length] = '\0';

    char log_buffer[256];
    const int log_fd = STDOUT_FILENO;
    uint64_t attempt_count = 0;

    while (1) {
        #ifdef PRINT_ATTEMPTS
        if ((attempt_count & 0xFFFF) == 0) { // Log every 65536 attempts
            int len = u64_to_str(attempt_count, log_buffer);
            memcpy(log_buffer + len, attempt, target_length);
            log_buffer[len + target_length] = '\n';
            write(log_fd, log_buffer, len + target_length + 1);
        }
        attempt_count++;
        #endif

        if (memcmp(attempt, target, target_length) == 0) {
            return true;
        }

        // Generate the next combination
        int i = target_length - 1;
        while (i >= 0) {
            if (++indices[i] == CHAR_SET_SIZE) {
                indices[i] = 0;
                attempt[i] = CHAR_SET[0];
                --i;
            } else {
                attempt[i] = CHAR_SET[indices[i]];
                break;
            }
        }

        if (i < 0) break; // All combinations exhausted
    }
    return false;
}

int main() {
    const char *target_password = "aB*(@7";
    char attempt[MAX_PASSWORD_LENGTH + 1];

    write(STDOUT_FILENO, "Starting password guess...\n", 27);

    if (guess_password(target_password, attempt)) {
        char success_msg[256];
        int msg_len = snprintf(success_msg, sizeof(success_msg), "Password guessed: %s\n", attempt);
        write(STDOUT_FILENO, success_msg, msg_len);
    } else {
        write(STDOUT_FILENO, "Password not found.\n", 21);
    }

    return 0;
}
