#include <stdio.h>

typedef unsigned char byte;

struct MyStruct {
    byte A;
    byte B;
    unsigned short C;
};

enum Action {
    ACTION_NEXT = 'n',
    ACTION_LAST = 'l',
    ACTION_QUIT = 'q'
};

void print_byte(byte b) {
    char bin_str[9] = {0};
    for (int idx = 7; idx >= 0; --idx) {
        bin_str[idx] = (b % 2) + '0';
        b /= 2;
    }
    puts(bin_str);
}

int main(void) {
    struct MyStruct obj = { .A = 1, .B = 0xff, .C = 0xff00 };
    byte *ptr = (byte *) &obj;

    while (1) {
        printf("$ ");
        enum Action action = getchar();
        getchar(); // consume newline
        switch (action) {
            case ACTION_QUIT: goto loop_break;
            case ACTION_NEXT: print_byte(*ptr++); break;
        }
    }

loop_break:
    return 0;
}