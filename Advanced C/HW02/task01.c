#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

void *findMaxBlock(list *head);

int main(void)
{
    return 0;
}

void *findMaxBlock(list *head)
{
    int max_size = 0;
    while (head != NULL)
    {
        list *ptmp = head;
        max_size < head->size ? head->size : max_size;
        head = ptmp->next;
        free(ptmp);
    }
    printf("Max size: %d", max_size);
}