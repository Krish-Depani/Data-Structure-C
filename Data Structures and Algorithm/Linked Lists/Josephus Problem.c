#include <stdio.h>
#include <stdlib.h>

struct node
{
    int player_id;
    struct node *next;
};
struct node *head, *ptr, *new_node;

int main()
{
    int n, k, i, count;
    printf("\n Enter the number of players : ");
    scanf("%d", &n);
    printf("\n Enter the value of k (every kth player gets eliminated): ");
    scanf("%d", &k);

    head = malloc(sizeof(struct node));
    head->player_id = 1;
    ptr = head;
    for (i = 2; i <= n; i++) {
        new_node = malloc(sizeof(struct node));
        ptr->next = new_node;
        new_node->player_id = i;
        new_node->next = head;
        ptr = new_node;
    }
    for (count = n; count > 1; count--)
    {
        for (i = 0; i < k - 1;++i)
            ptr = ptr->next;
        ptr->next = ptr->next->next;
    }
    printf("\n The Winner is Player %d", ptr->player_id);
    return 0;
}