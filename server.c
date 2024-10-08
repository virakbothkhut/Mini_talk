#include "minitalk.h"

void sig_toc(int sig, siginfo_t *siginfo, void *contxt)
{
    static int c_bit;
    static int c_word;

    (void)contxt;
    if (sig  == SIGUSR1)
        c_word += 1 << c_bit;
    c_bit++;
    if(c_bit == 8)
    {
            ft_putchar_fd(c_word,1);
            if(c_word == '\0')
            {
                ft_putstr_fd(END_SER,1);
            }
            c_word = 0;
            c_bit = 0;
    }
}

int main(int ac, char **av)
{
    int pid;
    struct sigaction ser_act;

    (void)av;
    if(ac != 1)
    {
        printfI("ERROR , No arguments needed \n");
        return (1);
    }
    pid = getpid();
    ft_printf("%d\n", pid);
    ser_act.sigaction = sig_toc;
    ser_act.flags = 0;
    while( ac == 1)
    {
            sigaction(SIGUSR1, &ser_act, NULL);
            sigaction(SIGUSR2, &ser_act, NULL);
    }
    return (0);
}
