#ifndef MONTY
#define MONTY

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* external declaration of the stack to pass between functions */
extern stack_t *stack;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* isnum - checks if string is a number */
int isnum(char *str);

/* parse - checks line from file for a single command and argument. */
void parse(char *line, char **tokens);

/* free_stack - frees the stack. */
void free_stack(stack_t **stack);

/* manage_stack - manage the passing of opcode to their respective functions */
int manage_stack(stack_t **stack, char **tokens, unsigned int line_number);

/* push_check - checks for push, queue, and stack opcode commands */
int push_check(stack_t **stack, char **token, unsigned int ln, int sentinel);

/* op_push - push an element onto the stack or queue. */
void op_push(stack_t **stack, char **tokens, unsigned int ln, int sentinel);

/* op_pall - print the stack. */
void op_pall(stack_t **stack, unsigned int line_number);

/* op_pint - prints the value at the top of the stack. */
void op_pint(stack_t **stack, unsigned int line_number);

/* op_pop - removes the top elemnt of the stack. */
void op_pop(stack_t **stack, unsigned int line_number);

/* op_swap - swaps the top two elements of the stack. */
void op_swap(stack_t **stack, unsigned int line_number);

/* op_add - adds the top two elements of the stack. */
void op_add(stack_t **stack, unsigned int line_number);

/* op_nop - doesn't do anything */
void op_nop(stack_t **stack, unsigned int line_number);

/* op_sub - subtracts the top element of the stack from the second top. */
void op_sub(stack_t **stack, unsigned int line_number);

/* op_div - divides the second top element of the stack by the top element. */
void op_div(stack_t **stack, unsigned int line_number);

/* op_mul - multiplies the second top element of the stack with the top. */
void op_mul(stack_t **stack, unsigned int line_number);

/*
 * op_mod - computes the remainder of the division of
 * the second top element and the stack by the top element.
 */
void op_mod(stack_t **stack, unsigned int line_number);

/* op_pchar - prints the char at the top of the stack. */
void op_pchar(stack_t **stack, unsigned int line_number);

/* op_pstr - prints the string starting at the top of the stack. */
void op_pstr(stack_t **stack, unsigned int line_number);

/* op_rotl - rotates the stack to the top. */
void op_rotl(stack_t **stack, unsigned int line_number);

/* op_rotr - rotates the stack to the bottom. */
void op_rotr(stack_t **stack, unsigned int line_number);

/* op_queue - pushes to a queue. */
void op_queue(stack_t **stack, stack_t *new_node);

/* op_stack - pushes to a stack. */
void op_stack(stack_t **stack, stack_t *new_node);

#endif /* MONTY */
