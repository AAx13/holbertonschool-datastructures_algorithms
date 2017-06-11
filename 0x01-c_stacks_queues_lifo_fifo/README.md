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

`pall` Prints all the values on the stack, starting from the top of the stack.
* Usage: `pall`

