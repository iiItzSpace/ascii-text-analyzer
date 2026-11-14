#include "input_reader.h"

#include <stdint.h>
#include <stdlib.h>

static constexpr size_t INITIAL_CAPACITY = 64;

char *read_stream(FILE *stream) {
    if (stream == nullptr) {
        return nullptr;
    }

    size_t capacity = INITIAL_CAPACITY;
    size_t length = 0;
    char *buffer = malloc(capacity);

    if (buffer == nullptr) {
        return nullptr;
    }

    int ch;
    while ((ch = fgetc(stream)) != EOF) {
        if (length + 1 >= capacity) {
            if (capacity > SIZE_MAX / 2) {
                free(buffer);
                return nullptr;
            }

            size_t new_capacity = capacity * 2;
            char *temp = realloc(buffer, new_capacity);
            if (temp == nullptr) {
                free(buffer);
                return nullptr;
            }

            buffer = temp;
            capacity = new_capacity;
        }

        buffer[length++] = (char)ch;
    }

    if (ferror(stream)) {
        free(buffer);
        return nullptr;
    }

    buffer[length] = '\0';
    return buffer;
}