#include <stdio.h>

void ft_sa(int *a)
{
    if (sizeof(a)/sizeof(a[0] <= 1))
        return ;
    int first = a[0];
    a[0] = a[1];
    a[1] = first;
}

int main(void)
{
    int a[] = {2, 5, 1, 6};
    int i = 0;
    ft_sa(a);
    int length = sizeof(a)/sizeof(a[0]);
    while (i < length)
    {
        printf("%i\n", a[i]);
        i++;
    }
}