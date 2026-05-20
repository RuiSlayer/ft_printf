# ft_printf

> A re-implementation of the C standard `printf` function — part of the 42 School curriculum.

## Overview

`ft_printf` replicates the behaviour of the standard `printf` by parsing a format string and handling a variable number of arguments via **variadic functions** (`va_list`, `va_start`, `va_arg`, `va_end`). The function writes formatted output to **stdout** and returns the total number of characters printed, matching the real `printf` return value.

***

## Supported Conversions

| Specifier | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string (prints `(null)` if pointer is NULL) |
| `%p` | Prints a pointer address in hexadecimal (`0x...`) |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed integer (same as `%d`) |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned integer in lowercase hexadecimal |
| `%X` | Prints an unsigned integer in uppercase hexadecimal |
| `%%` | Prints a literal `%` character |

***

## Function Prototype

```c
int ft_printf(const char *format, ...);
```

Returns the total number of characters written to stdout, or `-1` on error.

***

## File Structure

| File | Description |
|---|---|
| `ft_printf.c` | Entry point — format string parser, `va_list` management, specifier dispatch |
| `put_vars.c` | Handlers for all conversion specifiers (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`) |
| `ft_printf.h` | Header — function prototypes and includes |
| `Makefile` | Build rules |

***

## Compilation

```bash
make        # Build libftprintf.a
make clean  # Remove object files
make fclean # Remove object files and libftprintf.a
make re     # Rebuild from scratch
```

***

## Usage

Include the header and link the library when compiling:

```c
#include "ft_printf.h"
```

```bash
gcc main.c -L. -lftprintf -o my_program
```

**Example:**

```c
ft_printf("Hello, %s! You are %d years old.\n", "Rui", 21);
ft_printf("Hex: %x | Pointer: %p\n", 255, &some_var);
```

***

## Key Concepts

- **Variadic functions** — `va_list` and the `stdarg.h` macros (`va_start`, `va_arg`, `va_end`) allow the function to accept a variable number of arguments
- **Format parsing** — the format string is scanned character by character; a `%` triggers specifier detection and dispatches to the appropriate handler in `put_vars.c`
- **Return value** — every handler returns the number of characters it wrote; the total is accumulated and returned by `ft_printf`
- **Write wrapper** — all output goes through `write(1, ...)` directly, without using any standard I/O functions

***

## Notes

- Undefined behaviour (e.g. `%d` with no matching argument) is not handled — matching the subject requirements.
- The library can be combined with `libft` by linking both `.a` files at compile time.
- No use of the real `printf` or any buffered I/O functions (`puts`, `putchar`, etc.) internally.

***

*Made with ❤️ at 42 School.*
