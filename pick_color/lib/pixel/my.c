/*
** PERSONNAL PROJECT, 2018
** 
** File description:
** 
*/

int my_sqrt(int nb)
{
    int i = 1;
    int result = 0;

    while (result <= nb) {
        result = i * i;
        if (result == nb)
            return (i);
        else i += 1;
    }
    return (0);
}

int my_pow(int nb, int p)
{
    int tmp = nb;
    int result = 0;

    if (p == 0)
	return (1);
    else if (p < 0)
	return (0);
    if (p >= 1)
	result = my_pow(nb, p - 1) * tmp;
    if (result > 2147483647)
	return (0);
    return (result);
}
