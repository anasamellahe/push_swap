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

void print_stack(stack *stack_a)
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
    int i = 0;
    stack *stack_a = NULL;
    stack * stack_b = NULL;

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

    
    
    
    alogo_1(&stack_a, &stack_b, 5);
    //print_stack(stack_a);
	
	

   



    // print_stack(stack_a, stack_b);


    // rr(&stack_a, &stack_b);
    // printf("----RR----\n");
    // print_stack(stack_a, stack_b);

    // rrr(&stack_a, &stack_b);
    // printf("----RRR----\n");
    // print_stack(stack_a, stack_b);

    // ss(stack_a, stack_b);
    // printf("----SS----\n");
    // print_stack(stack_a, stack_b);

    // ss(stack_a, stack_b);
    // printf("----SS----\n");
    // print_stack(stack_a, stack_b);

    // pa(&stack_a, &stack_b);
    // printf("----PA----\n");
    // print_stack(stack_a, stack_b);

    // pb(&stack_a, &stack_b);
    // printf("----PB----\n");
    // print_stack(stack_a, stack_b);




    // printf("|----A----|\n");
    // print_node(stack_a);
    // printf("|----B----|\n");
    // print_node(stack_b);
    // rra(&stack_a);
    // printf("----RRA----\n");
    // printf("|----A----|\n");
    // print_node(stack_a);
    // ra(&stack_a);
    // printf("----RRA----\n");
    // printf("|----A----|\n");
    // print_node(stack_a);
    // rb(&stack_b);
    // printf("----Rb----\n");
    // printf("|----b----|\n");
    // print_node(stack_b);
    

    
    // pa(&stack_a, &stack_b);
    // printf("----PA----\n");

    // printf("|----A----|\n");
    // print_node(stack_a);
    // printf("|----B----|\n");
    // print_node(stack_b);

    // pb(&stack_a, &stack_b);
    // pb(&stack_a, &stack_b);
    // printf("----PB----\n");

    // printf("|----A----|\n");
    // print_node(stack_a);
    // printf("|----B----|\n");
    // print_node(stack_b);


    //----------------//
    //free_node(stack_a);
    //free_node(stack_b);
    return (0);

}