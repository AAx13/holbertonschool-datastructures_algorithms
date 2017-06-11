# Stacks, Queues - LIFO, FIFO Project

## Monty Bytecode Interpreter

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account.

Example of Monty Bytecode file:

```
Ubuntu:0x01-c_stacks_queues_lifo_fifo vagrant$ cat bytecodes/000.m
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

Create the executable: `make`.
To delete the executable and all unecessary files: `make clean`.

Usage: `./monty file`
Where `file` is the path to the Monty Bytecode file.