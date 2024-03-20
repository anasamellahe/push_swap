#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "push_swap.h"


int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}
int ft_strcmp(char *s, char *s1)
{
    int i;

    i = 0;
    while (s && s1 && s[i] == s1[i] && s[i] && s1[i])
        i++;
    return (s[i] - s1[i]);
}
int is_number(char *s)
{
    int i;

    i = 0;
    i += s[i] == '-';
    while (s[i])
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return (-1);
        i++;
    }
    return (0);
}
int is_int(char *s)
{
    int len;
    int i;
    int sign;
    char *n;

    i = 0;
    sign = s[i] == '-';
    n = (char *)((long int)"2147483647" * !sign + (long int)"-2147483648" * sign);
    len = ft_strlen(s);
    if (len >= 10)
    {
        while (s[i])
        {
            if (len > (10 + sign) || n[i] < s[i])
                return (-1);
            i++;
        }
    } 
    return (0);
}
int is_dup(char **av, int ac)
{
    int i;
    int j;

    i = 0;
    while (i < ac - 1)
    {
        j = i + 1;
        while (j < ac -1)
        {
            if (!ft_strcmp(av[i + 1], av[j + 1]))
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}
int ft_atoi(char *s)
{
    int i;
    int sign;
    int n;

    i = 0;
    n = 0;
    sign = 1;
    while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
        i++;
    if (s[i] == '-')
        sign = -1;
    i += sign == -1;
    while (s[i] && (s[i] >= '0' && s[i] <= '9'))
    {
        n = (n * 10) + (s[i] - 48);
        i++;
    }
    return (n * sign);

}

int check_error(char **av, int ac)
{
    int i;

    i = 0;
    if (ac)
    while (i < ac - 1)
    {
        if (is_int(av[i + 1]) || is_number(av[i + 1]))
            return (-1);
        i++;
    }
    return (is_dup(av, ac));
    
}
// int main (int ac, char *av[])
// {
    // int *tab;
    // int i = 0;

    // tab = (int *)malloc(sizeof(int) * (ac - 1));
    // if (!tab)
    // {
    //     printf("malloc faile :(\n");
    //     return (0);
    // }
    // while (i < ac - 1)
    // {
    //     tab[i] = ft_atoi(av[i + 1]);
    //     i++;
    // }
    // if (check_error(av, ac) == -1)
    //     printf("ERROR\n");
    // else
    //     printf("OK");
    // return (0);

//     stack *head;
    
// }
stack *new_node (int data)
{
    stack *new;

    new = malloc(sizeof(stack));
    new->data = data;
    new->next = NULL;
}
void l_add_node(stack **head, stack *node_to_add)
{
    stack *tmp_head;

    tmp_head = (*head);
    if ((*head) != NULL)
    {
        while ((*head)->next)
            (*head) = (*head)->next;
        (*head)->next = node_to_add;
        (*head) = tmp_head;
    }
    else
        (*head) = node_to_add;
}

void f_add_node(stack **head, stack * node_to_add)
{   
    node_to_add->next = (*head);
    (*head) = node_to_add;
}
void print_node(stack *head)
{
    while (head)
    {
        printf("node = [%d]\n", head->data);
        head = head->next;
    }
}
int main(int ac, char  **av)
{
    int i = 0;
    stack *stack_a = NULL;
    if (check_error(av, ac) == -1)
    {
        printf("ERROR\n");
        return(0);
    }
    while (i < ac - 1)
    {
        l_add_node(&stack_a, new_node(ft_atoi(av[i+1])));
        i++;
    }
    print_node(stack_a);
    
}