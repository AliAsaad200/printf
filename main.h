#ifndef Main
#define Main
int _putchar(char c);
void print_correct_string(const char *sttring_task);
int _printf(const char *format, ...);
int format_arguments_output(const char *format, va_list argument_format);
int print_correct_int(va_list no);
int format_arguments_output(const char *format, va_list argument_format);
void process_string_argument(va_list argument_format, int *counting_down);
void process_unknown_specifier(const char *format, int *counting_down);

#endif
