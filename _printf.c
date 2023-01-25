#include "main.h"
#include <stdarg.h>
#include <stdio.h>

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...) {
    int count = 0;
    va_list args;
    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            switch (format[i]) {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    printf("%s", va_arg(args, char*));
                    count += strlen(va_arg(args, char*));
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar(format[i]);
                    count++;
                    break;
            }
        } else {
            putchar(format[i]);
            count++;
        }
    }

    va_end(args);
    return count;
}
