#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

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



/**
 * struct instruction_s - opcode and its function
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

// Global Variable
typedef struct glob_var_s
{
	FILE *file;
	char *linebuf;
	char *sizbuf;
	int node_num;
} glob_var_t;

extern glob_var_t Var;

int main(int ac __attribute__((unused)), char **av);
// ------------------ General Functions --------------------------- */
char *readfile(char **av);
char* stacki(char *buffer);
char *func_parser(stack_t *head, unsigned int num);
int get_functions(char **stack, unsigned int line_number);
// -------------------- Errors Functions -------------------------
void int_Error(stack_t *head, unsigned int line_number);
// ------------------ Node Functions -----------------------------
void func_code_push(stack_t **stack, unsigned int line_number);
void func_code_pall(stack_t **stack, unsigned int line_number);

#endif