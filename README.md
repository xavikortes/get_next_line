*This project has been created as part of 42 curriculum by jcortes.*

# get\_next\_line

## Description

**get_next_line** is a project focused on implementing a function that reads and returns a line from a file descriptor, one call at a time. The implementation must correctly handle different buffer sizes, multiple file descriptors, and input of varying lengths while managing dynamically allocated memory without leaks.

## Instructions

### Compiling

To compile the source files include the `*.c` files in your compilation scripts:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c your_main.c
```

## Usage

In order to use the compiled library in your project:

* Compile it following the steps above.
* Include the `get_next_line.h` file.
	```
	#include "get_next_line.h"
	```
* Call the get\_next\_line(int fd) function:
	```c
	int fd = open("path_to_some_text_file", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s\n", line);
	```

## Resources

- [man read](https://man7.org/linux/man-pages/man2/read.2.html)

This project only use AI tools to check the exhaustiveness of the tests and received some guidance to write this `README.md`.
