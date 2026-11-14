#include "input_reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK(cond)                                                                                                    \
    do                                                                                                                 \
    {                                                                                                                  \
        if (!(cond))                                                                                                   \
        {                                                                                                              \
            fprintf(stderr, "FAIL %s (%s:%d)\n", #cond, __FILE__, __LINE__);                                           \
            exit(EXIT_FAILURE);                                                                                        \
        }                                                                                                              \
    } while (0)

static FILE *make_stream(const char *content)
{
    FILE *stream = tmpfile();
    CHECK(stream != nullptr);

    size_t len = strlen(content);
    if (len > 0)
    {
        CHECK(fwrite(content, 1, len, stream) == len);
    }
    rewind(stream);
    return stream;
}

static void test_read_stream_null()
{
    CHECK(read_stream(nullptr) == nullptr);
}

static void test_read_stream_empty()
{
    FILE *stream = make_stream("");
    char *result = read_stream(stream);

    CHECK(result != nullptr);
    CHECK(strcmp(result, "") == 0);

    free(result);
    fclose(stream);
}

static void test_read_stream_short_multiline()
{
    const char *input = "Hello \nASCII world!\n123";
    FILE *stream = make_stream(input);
    char *result = read_stream(stream);

    CHECK(result != nullptr);
    CHECK(strcmp(result, input) == 0);

    free(result);
    fclose(stream);
}

static void test_read_stream_exact_buffer_boundaries()
{
    static constexpr size_t lengths[] = {63, 64};

    for (size_t k = 0; k < 2; k++)
    {
        size_t len = lengths[k];
        char expected[65];
        memset(expected, 'a', len);
        expected[len] = '\0';

        FILE *stream = make_stream(expected);
        char *result = read_stream(stream);

        CHECK(result != nullptr);
        CHECK(strlen(result) == len);
        CHECK(strcmp(result, expected) == 0);

        free(result);
        fclose(stream);
    }
}

static void test_read_stream_long_reallocation()
{
    char expected[301];
    for (size_t i = 0; i < 300; i++)
    {
        expected[i] = (char)('A' + (i % 26));
    }
    expected[300] = '\0';

    FILE *stream = make_stream(expected);
    char *result = read_stream(stream);

    CHECK(result != nullptr);
    CHECK(strlen(result) == 300);
    CHECK(strcmp(result, expected) == 0);

    free(result);
    fclose(stream);
}

static void test_read_stream_preserves_utf8_bytes()
{
    const char *input = "Hello 👋 🖖";
    FILE *stream = make_stream(input);
    char *result = read_stream(stream);

    CHECK(result != nullptr);
    CHECK(strcmp(result, input) == 0);

    free(result);
    fclose(stream);
}

int main()
{
    test_read_stream_null();
    test_read_stream_empty();
    test_read_stream_short_multiline();
    test_read_stream_exact_buffer_boundaries();
    test_read_stream_long_reallocation();
    test_read_stream_preserves_utf8_bytes();

    printf("All input_reader tests passed!\n");
    return EXIT_SUCCESS;
}
