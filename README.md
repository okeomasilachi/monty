# 0x19. C - Stacks, Queues - LIFO, FIFO

## The monty program

The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
Usage: monty file


### The opcode push pushes an element to the stack.

Usage: push <int>
where <int> is an integer
if <int> is not an integer or if there is no argument given to push, prints the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
where "L" is the line number in the file

### The opcode pall prints all the values on the stack, starting from the top of the stack.

Usage pall

### The opcode pint prints the value at the top of the stack, followed by a new line.

Usage: pint
If the stack is empty, prints the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

### The opcode pop removes the top element of the stack.

Usage: pop
If the stack is empty, prints the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE

### The opcode swap swaps the top two elements of the stack.

Usage: swap
If the stack contains less than two elements, prints the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

### The opcode add adds the top two elements of the stack.

Usage: add
If the stack contains less than two elements, prints the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so, at the end:
The top element of the stack contains the result
NOTE: The stack is one element shorter

### The opcode nop doesn’t do anything.

Usage: nop

### The opcode sub subtracts the top element of the stack from the second top element of the stack.

Usage: sub
If the stack contains less than two elements, prints the error message L<line_number>: can't sub, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so, at the end:
The top element of the stack contains the result
NOTE: The stack is one element shorter

### The opcode div divides the second top element of the stack by the top element of the stack.

Usage: div
If the stack contains less than two elements, prints the error message L<line_number>: can't div, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so, at the end:
The top element of the stack contains the result
NOTE: The stack is one element shorter
If the top element of the stack is 0, it prints the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

### The opcode mul multiplies the second top element of the stack with the top element of the stack.

Usage: mul
If the stack contains less than two elements, prints the error message L<line_number>: can't mul, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so, at the end:
The top element of the stack contains the result
NOTE: The stack is one element shorter

### The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.

Usage: mod
If the stack contains less than two elements, prints the error message L<line_number>: can't mod, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so, at the end:
The top element of the stack contains the result
NOTE: The stack is one element shorter
If the top element of the stack is 0, it prints the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

### The opcode pchar prints the char at the top of the stack, followed by a new line.

Usage: pchar
The integer stored at the top of the stack is treated as the ascii value of the character to be printed
If the value is not in the ascii table (man ascii) prints the error message L<line_number>: can't pchar, value out of range, followed by a new line, and exit with the status EXIT_FAILURE
If the stack is empty, prints the error message L<line_number>: can't pchar, stack empty, followed by a new line, and exit with the status

### The opcode pstr prints the string starting at the top of the stack, followed by a new line.

Usage: pstr
The integer stored in each element of the stack is treated as the ascii value of the character to be printed
The string stops when either:
* the stack is over
* the value of the element is 0
* the value of the element is not in the ascii table

NOTE: If the stack is empty, prints only a new line

### The opcode rotl rotates the stack to the top.

Usage: rotl
The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
rotl never fails

###The opcode rotr rotates the stack to the bottom.

Usage: rotr
The last element of the stack becomes the top element of the stack
rotr never fails

### The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.

Usage: stack

### The opcode queue sets the format of the data to a queue (FIFO).

Usage: queue
When switching mode:

NOTE: 
* The top of the stack becomes the front of the queue
* The front of the queue becomes the top of the stack
