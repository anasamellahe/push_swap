#include "push_swap.h"


int ft_strlen(const char *s)
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

char **new_str(char **av)
{
    int i;
    char *new;
    char **new_sp;

    i = 1;
    new = 0;
    while (av[i] != NULL)
    {
        new = ft_strjoin(new, av[i]);
        if (av[i + 1] != NULL)
            new = ft_strjoin(new, " ");
        i++;
    }
    new_sp = ft_split(new, ' ');
    free(new);
    return (new_sp);
}

void print_stack(t_stack *stack_a)
{
    printf("<--print stack-->\n");

    while (stack_a != NULL)
    {
        printf("%d\n",stack_a->data);
            stack_a = stack_a->next;
    }

}

int main(int ac, char  **av)
{
    char    **str;
    t_stack *stack_a = NULL;
    t_stack * stack_b = NULL;

    str =  new_str(av);
    if (check_error == -1)
    {
        write(2, "Error\n", 6);
        return (0);
    }
    // while (i < ac - 1)
    // {
    //     l_add_node(&stack_a, new_node(ft_atoi(av[i+1])));
    //     i++;
    // }

 
    //algo(&stack_a, &stack_b);
    return (0);

}