#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

// ◦ write
// ◦ ft_printf or any equivalent YOU coded
// ◦ signal
// ◦ sigemptyset
// ◦ sigaddset
// ◦ sigaction
// ◦ kill
// ◦ getpid
// ◦ malloc
// ◦ free
// ◦ pause
// ◦ sleep
// ◦ usleep
// ◦ exit

// struct sigaction {
//    void     (*sa_handler)(int);
//    void     (*sa_sigaction)(int, siginfo_t *, void *);
//    sigset_t   sa_mask;
//    int        sa_flags;
//    void     (*sa_restorer)(void);
// };

// decoding bytes
	// unsigned char c = 0b00110000;
	// unsigned char res = 0;

	// for (int i = 0; i < 8; ++i)
	// {
	// 	res <<= 1; // make room for next bit

	// 	if (c & 0b10000000)
	// 	{
	// 		printf("1\n");
	// 		res |= 1; // insert bit
	// 	}
	// 	else
	// 	{
	// 		printf("0\n");
	// 	}

	// 	c <<= 1;
	// }

int main(int argc, char **argv)
{
	size_t i;
	int k;

	i = 0;
	k = 0;
	if (argc != 3)
		return ft_printf("Error: bad number of arguments\n");
	ft_printf("value: %d\n", argv[2][0]);
	while (i < ft_strlen(argv[2]))
	{
		k = 0;
		while (k < 8)
		{
			usleep(100);
			if (argv[2][i] & 0b10000000)
			{
				kill(ft_atoi(argv[1]), SIGUSR1);
			}
			else
			{
				kill(ft_atoi(argv[1]), SIGUSR2);
			}
			argv[2][i] <<= 1;
			++k;
		}
		++i;
	}
	
	printf("message sennt\n");
}