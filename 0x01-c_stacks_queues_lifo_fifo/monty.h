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
char **parse(char *line);

/* free_stack - frees the stack. */
void free_stack(stack_t **stack);

/* manage_stack - manage the passing of opcode to their respective functions */
int manage_stack(stack_t **stack, char **tokens, unsigned int line_number);

/* op_push - push an element onto the stack. */
void op_push(stack_t **stack, char **tokens, unsigned int line_number);

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

/* op_sub - subtracts the top element of the stack from the second top element. */
void op_sub(stack_t **stack, unsigned int line_number);

/* op_div - divides the second top element of the stack by the top element. */
void op_div(stack_t **stack, unsigned int line_number);

/* * op_mul - multiplies the second top element of the stack with the top element. */
void op_mul(stack_t **stack, unsigned int line_number);

#endif /* MONTY */
