#include <cstdio>
#include <cctype>
#include <cstring>
const int INPUT_BUFFER_SIZE = 1 << 20;
const int OUTPUT_BUFFER_SIZE = 1 << 20;

char input_buffer[INPUT_BUFFER_SIZE];
int input_pos = 0, input_len = 0;

char output_buffer[OUTPUT_BUFFER_SIZE];
int output_pos = 0;

inline char next_char() {
    if (input_pos == input_len) {
        input_len = fread(input_buffer, 1, INPUT_BUFFER_SIZE, stdin);
        input_pos = 0;
        if (input_len == 0) return EOF;
    }
    return input_buffer[input_pos++];
}

inline int fast_read_int() {
    int x = 0, neg = 0;
    char c = next_char();
    while (!isdigit(c) && c != '-' && c != EOF) c = next_char();
    if (c == '-') {
        neg = 1;
        c = next_char();
    }
    while (isdigit(c)) {
        x = x * 10 + (c - '0');
        c = next_char();
    }
    return neg ? -x : x;
}

inline void flush_output() {
    fwrite(output_buffer, 1, output_pos, stdout);
    output_pos = 0;
}

inline void fast_write_char(char c) {
    if (output_pos == OUTPUT_BUFFER_SIZE) flush_output();
    output_buffer[output_pos++] = c;
}

inline void fast_write_int(int x) {
    if (x < 0) {
        fast_write_char('-');
        x = -x;
    }
    char tmp[10];
    int len = 0;
    if (x == 0) tmp[len++] = '0';
    while (x > 0) {
        tmp[len++] = (x % 10) + '0';
        x /= 10;
    }
    while (len--) fast_write_char(tmp[len]);
    fast_write_char('\n');
}

inline void fast_read_string(char* s) {
    char c = next_char();
    while (isspace(c)) c = next_char();
    while (!isspace(c) && c != EOF) {
        *s++ = c;
        c = next_char();
    }
    *s = '\0';
}

inline void fast_write_string(const char* s) {
    while (*s) {
        fast_write_char(*s++);
    }
}
