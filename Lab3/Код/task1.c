#include <stdlib.h>
#include <stdio.h>

#define ST_SIZE 5

typedef struct {
  int *data;
  int stack_pointer; // шоб не забути: вказує на ПЕРШУ ПУСТУ КОМІРКУ [0, довжина стека]
  size_t stack_size;
} stack;

stack * stack_init(stack * st, const size_t st_size) {
  if (st && st_size) {
    st->data = malloc(st_size * sizeof(int));
    st->stack_pointer = 0;
    st->stack_size = st_size;

    if (!st->data) {
      *st = (stack){0};
      printf("Malloc failed to allocate enough memory for stack array\n");
    }

  } else {
    printf("Incorrect input for stack_init()\n");
  }

  return st;
}

char is_full(stack * st) {
  char result = -1;

  if (st && st->data) {
    result = st->stack_pointer >= st->stack_size;
  } else {
    printf("Attempt to call is_full() on non-existent stack\n");
  }

  return result;
}

char is_empty(stack * st) {
  char result = -1;

  if (st && st->data) {
    result = st->stack_pointer <= 0;
  } else {
    printf("Attempt to call is_empty() on non-existent stack\n");
  }

  return result;
}

void push(stack * st, int value) {
  if (st && st->data && !is_full(st)) {
    st->data[st->stack_pointer++] = value;
  } else {
    printf("Attempt to call push() on full or non-existent stack\n");
  }
}

int pop(stack * st) {
  int result = -1;

  if (st && st->data && !is_empty(st)) {
    result = st->data[--st->stack_pointer];
  } else {
    printf("Attempt to call pop() on empty or non-existent stack\n");
  }

  return result;
}

int peek(stack * st) {
  int result = -1;

  if (st && st->data && !is_empty(st)) {
    result = st->data[st->stack_pointer - 1];
  } else {
    printf("Attempt to call peek() on empty or non-existent stack\n");
  }

  return result;
}

void destroy(stack * st) {
  if (st && st->data) {
    free(st->data);
    *st = (stack){0};
  } else {
    printf("Attempt to call destroy() on empty or non-existent stack\n");
  }
}

int main()
{
  stack st;
  char str[ST_SIZE], error_found = 0;
  int i = 0;

  stack_init(&st, ST_SIZE);

  if (st.data != NULL) {
    // ! Для першого тесту:
    if (fgets(str, sizeof(str), stdin) != NULL) {
      while ((str[i] != '\0') && (error_found != 1)) {
        if (str[i] == '(') {
          push(&st, i);
        } else if (str[i] == ')') {
          if (is_empty(&st)) {
            error_found = 1;
            printf("Error found. Closing not yet opened brackets at index %d\n", i);
          } else {
            pop(&st);
          }
        }
        i++;
      }

      if (!is_empty(&st)) {
        do {
          i = pop(&st);
        } while (!is_empty(&st));
        printf("Error found. Not closed brackets at index %d\n", i);
      } else if (!error_found) {
        printf("Errors not found, alr boy\n");
      }
    } else {
      printf("Error during entering the input encountered\n");
    }
    // Кінець першого тесту

    // ! Для другого тесту:
    // printf("%d", pop(&st));
    // Кінець другого тесту

    // ! Для третього тесту:
    // push(&st, 23);
    // push(&st, 1);
    // push(&st, 6);
    // push(&st, 2);
    // push(&st, 1000);
    // push(&st, 23);
    // printf("%d", peek(&st));
    // Кінець третього тесту

    destroy(&st);
  } else {
      printf("Stack wasn't properly initialized\n");
  }

  return 0;
}
