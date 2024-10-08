#include "minitalk.h"

void cto_sig(int ser_pid, char c)
{
    int c_bit;
    c_bit = 0;
    while(c_bit < 8)
    {
        if(c & (1 << c_bit))
            kill(ser_pid, SIGUSR1);
        else
            kill(ser_pid, SIGUSR2);
        usleep(100);
        c_bit++;
    }
}

int main(int ac, char **av)
{
    int i;
    i = 0;
    int ser_pid;
    

    if(ac == 3)
    {
        ser_pid = ft_atoi(av[1]);
        if(ac == 3 && ser_pid > 1)
        {
            while(av[2][i])
            {
                cto_sig(ser_pid, av[2][i])
                i++;
            }
            cto_sig(ser_pid, '\n');
            cto_sig(ser_pid, '\0');
        }
        else
        {
            ft_putendl_fc("ERROR ", 1);
            return (1);
        }
        return 0;
    }
    
}