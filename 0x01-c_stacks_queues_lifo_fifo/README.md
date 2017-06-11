# Stacks, Queues - LIFO, FIFO Project

### Tools
* Ubuntu 14.04LTS
* gcc 4.8.4

## Monty Bytecode Interpreter

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account.

Example of Monty Bytecode file:

```
 $ cat bytecodes/000.m
push 0
push 1
push 2
  push 3
          pall
push 4
     push 5
	push      6
pall
```

Is read as:

```
push 0
push 1
push 2
push 3
pall
push 4
push 5
push 6
pall
```

The Monty Bytecode Interpreter Program.

* Create the executable: `make`
* To delete the executable and all unecessary files: `make clean`

Usage: `./monty file`

* Where `file` is the path to the Monty Bytecode file.

```
 $ cat bytecodes/00.m
push 1
push 2
push 3
pall

 $ ./monty bytecodes/00.m
3
2
1
```


## Opcodes

`push` Pushes an element to the stack.
* Usage: `push <int>`
* where `<int>` is an integer.

##

`pall` Prints all the values on the stack, starting from the top of the stack.
* Usage: `pall`

##

`pint` Prints the value at the top of the stack, followed by a new line.
* Usage: `pint`

##

`pop` Removes the top element of the stack.
* Usage: `pop`

##

`swap` Swaps the top two elements of the stack.
* Usage: `swap`

##

`add` Adds the top two elements of the stack.
* Usage: `add`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end.
* The top element of the stack contains the result
* The stack is one element shorter.

##

`nop` Doesn't do anything.
* Usage: `nop`

##

`sub` Subtracts the top element of the stack from the second top element of the stack.
* Usage: `sub`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end.
* The top element of the stack contains the result
* The stack is one element shorter.

##

`div` Divides the second top element of the stack by the top element of the stack.
* Usage: `div`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end.
* The top element of the stack contains the result
* The stack is one element shorter.

##

`mul` Multiplies the second top element of the stack with the top element of the stack.
* Usage: `mul`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end.
* The top element of the stack contains the result
* The stack is one element shorter.

##

`mod` Computes the rest of the division of the second top element of the stack by the top element of the stack.
* Usage: `mod`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end.
* The top element of the stack contains the result
* The stack is one element shorter.

##

`#` Comment implementation. Everything on this line after the `#` is not processed.

##

`pchar` Prints the char at the top of the stack, followed by a new line.
* Usage: `pchar`
* The integer stored at the top of the stack is treated as the ascii value of the character to be printed.

##

`pstr` Prints the string starting at the top of the stack, followed by a new line.
* Usage: `pstr`
* The integer stored in each element of the stack is treated as the ascii value of the character to be printed.
* If the stack is empty, print only a new line.

##

`rotl` Rotates the stack to the top.
* Usage: `rotl`
* The top element of the stack becomes the last one, and the second top element of the stack becomes the first one.

##

`rotr` Rotates the stack to the bottom.
* Usage: `rotr`
* The last element of the stack becomes the top element of the stack.

##

`stack` Sets the format of the data to a stack (LIFO). This is the default behavior of the program.
* Usage: `stack`

`queue` Sets the format of the data to a queue (FIFO).
* Usage: `queue`

##### When switching mode (stack or queue):

* The top of the stack becomes the front of the queue.
* The front of the queue becomes the top of the stack.

##