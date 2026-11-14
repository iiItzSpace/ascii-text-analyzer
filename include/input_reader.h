#ifndef ASCII_TEXT_ANALYZER_INPUT_READER_H
#define ASCII_TEXT_ANALYZER_INPUT_READER_H

#include <stdio.h>

/// @brief Reads all characters from a stream until EOF into a heap-allocated string.
/// @param stream Input stream to read from (must not be nullptr).
/// @return Null-terminated string allocated on the heap (caller must free),
///     or nullptr on invalid input, I/O error, or allocation failure.
[[nodiscard]] char *read_stream(FILE *stream);

#endif // ASCII_TEXT_ANALYZER_INPUT_READER_H
