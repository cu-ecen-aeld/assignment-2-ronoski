#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    openlog("writer", LOG_PID, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments. Expected 2, got %d", argc - 1);
        fprintf(stderr, "Usage: %s <file_path> <string_to_write>\n", argv[0]);
        closelog();
        return EXIT_FAILURE;
    }

    const char *file_path     = argv[1];
    const char *text_to_write = argv[2];

    syslog(LOG_DEBUG, "Writing %s to %s", text_to_write, file_path);

    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Failed to open %s for writing: %s ", file_path, strerror(errno));
        fprintf(stderr, "Error: could not open %s for writing: %s\n", file_path, strerror(errno));
        closelog();
        return EXIT_FAILURE;
    }

    if (fputs(text_to_write, file) == EOF) {
        syslog(LOG_ERR, "Failed to write to %s: %s", file_path, strerror(errno));
        fprintf(stderr, "Error: failed to write to %s\n", file_path);
        fclose(file);
        closelog();
        return EXIT_FAILURE;
    }

    if (fclose(file) != 0) {
        syslog(LOG_ERR, "Failed to close %s: %s", file_path, strerror(errno));
        fprintf(stderr, "Error: failed to close %s\n", file_path);
        closelog();
        return EXIT_FAILURE;
    }

    closelog();
    return EXIT_SUCCESS;
}
