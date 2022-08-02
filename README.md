# get_next_line

<br>

**About The Project**
<br>
The function reads from the file descriptor and returns one line at a time per function call.
The bonus part is doing basically the same, but in addition it allows to read from several file descriptors simultaneously and to return the current read line from a particular file descriptor with every function call.

<br>

**Getting Started**

compile following .c files to use the mandatory version and include the get_next_line.h header:

`gcc get_next_line.c get_next_line_utils.c
`

compile following .c files to run the bonus version and include get_next_line_bonus.h:

`gcc get_next_line_bonus.c get_next_line_utils_bonus.c
`

<br>

**Prerequisites**

Installed C-Compiler like gcc, cc or clang.

<br>

**Usage**

`get_next_line(FILE_DESCRIPTOR);
`

<br>


**Acknowledgments**

Great tester to validate the project:

https://github.com/Tripouille/gnlTester
