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

/* parse - checks line from file for a single command and argument. */
char **parse(char *line);

/* free_stack - frees the stack. */
void free_stack(stack_t **stack);

/* manage_stack - manages the passing of opcode to their respective functions. */
int manage_stack(stack_t **stack, char **tokens, unsigned int line_number);

/* push - push an element onto the stack. */
void push(stack_t **stack, char **tokens, unsigned int line_number);

/* pall - print the stack. */
void pall(stack_t **stack, unsigned int line_number);

#endif /* MONTY */
