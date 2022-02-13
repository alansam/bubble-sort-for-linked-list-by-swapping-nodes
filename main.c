
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node Node;
struct Node {
  Node * next;
  int val;
};

Node ** sort(Node ** head, size_t count);
void print_node(Node const * np);
void print(Node * node);

int main(void) {
  printf("RecursiveLustrousWorkspaces\n");

  Node * head;

  Node test[] = {
    { NULL, 3, },
    { NULL, 1, },
    { NULL, 2, },
    { NULL, 0, },
  };
  size_t test_l = sizeof(test) / sizeof(*test);

  head = &test[0];
  test[0].next = &test[1];
  test[1].next = &test[2];
  test[2].next = &test[3];

  print(head);
  sort(&head, test_l);
  print(head);

  return 0;
}

//  @see https://www.geeksforgeeks.org/bubble-sort-for-linked-list-by-swapping-nodes/

Node * swap(Node* ptr1, Node * ptr2) {
  Node * tmp = ptr2->next;
  ptr2->next = ptr1;
  ptr1->next = tmp;

  return ptr2;
}

Node ** sort(Node ** head, size_t count) {
  printf("In function %s()\n", __func__);
  struct Node ** head_ptr;
  bool swapped;

  for (size_t ix = 0; ix <= count; ix++) {
    head_ptr = head;
    swapped = false;

    for (size_t jx = 0; jx < count - ix - 1; jx++) {
      Node * p1 = *head_ptr;
      Node* p2 = p1->next;

      if (p1->val > p2->val) {
        // update the link after swapping
        *head_ptr = swap(p1, p2);
        swapped = true;
      }

      head_ptr = &(*head_ptr)->next;
    }

    // break if the loop ended without any swaps
    if (!swapped) {
      break;
    }
  }
  return head;
}

void print_node(Node const * np) {
  printf("%18p - next: %18p, val: %3d\n",
         np, np->next, np->val);
}

void print(Node * node) {
  printf("In function %s()\n", __func__);

  while (true) {
    print_node(node);
    if (node->next == NULL) { break; }
    node = node->next;
  }
}
