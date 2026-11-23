#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 100

typedef struct linked_list {
  struct linked_list * next_ptr;
  int data;
} l_list;

typedef struct {
  l_list * list;
} stack;

stack * stack_init(stack * st) {
  if (st) {
    st->list = malloc(sizeof(l_list));

    if (!st->list) {
      *st = (stack){0};
      printf("Malloc failed to allocate enough memory for linked list\n");
    } else {
      st->list->next_ptr = NULL;
      st->list->data = -1;
    }
  } else {
    printf("Incorrect input for stack_init()\n");
  }

  return st;
}

char is_empty(stack * st) {
  char result = -1;

  if (st && st->list) {
    result = st->list->next_ptr == NULL;
  } else {
    printf("Attempt to call is_empty() on non-existent or not initialized stack\n");
  }

  return result;
}

void push(stack * st, int value) {
  if (st && st->list) {
    l_list * new_item = malloc(sizeof(l_list));
    if (new_item) {
      new_item->data = -1;
      st->list->data = value;
      new_item->next_ptr = st->list;
      st->list = new_item;
    } else {
      printf("Malloc failed to allocate enough memory for a new list item\n");
    }
  } else {
    printf("Attempt to call push() on non-existent or not initialized stack\n");
  }
}

int pop(stack * st) {
  int result = -1;

  if (st && st->list && !is_empty(st)) {
    l_list * ptr_to_del = st->list->next_ptr;
    l_list * n_ptr = ptr_to_del->next_ptr;
    result = ptr_to_del->data;
    free(ptr_to_del);
    if (n_ptr) {
      st->list->next_ptr = n_ptr;
    } else {
      st->list->next_ptr = NULL;
    }
  } else {
    printf("Attempt to call pop() on empty or non-existent or not initialized stack\n");
  }

  return result;
}

int peek(stack * st) {
  int result = -1;

  if (st && st->list && !is_empty(st)) {
    result = st->list->next_ptr->data;
  } else {
    printf("Attempt to call peek() on empty or non-existent or not initialized stack\n");
  }

  return result;
}

void destroy(stack * st) {
  if (st && st->list) {
    while (st->list->next_ptr != NULL) {
      pop(st);
    }
    free(st->list);
    *st = (stack){0};
  } else {
    printf("Attempt to call destroy() on empty or non-existent or not initialized stack\n");
  }
}

int main()
{
  stack st;
  char str[BUF_SIZE], error_found = 0;
  int i = 0;

  stack_init(&st);

  if (st.list != NULL) {
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

    destroy(&st);
  } else {
      printf("Stack wasn't properly initialized\n");
  }

  return 0;
}
