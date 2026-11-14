#ifndef ASCII_TEXT_ANALYZER_INPUT_READER_H
#define ASCII_TEXT_ANALYZER_INPUT_READER_H

#include <stdio.h>

// Reads all characters from 'stream' until EOF into a heap-allocated string.
[[nodiscard]] char *read_stream(FILE *stream);

#endif //ASCII_TEXT_ANALYZER_INPUT_READER_H
