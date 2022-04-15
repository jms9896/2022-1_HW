#include	<pthread.h>
#include	<stdio.h>
#include	<stdlib.h>

void	*runner(void	*param);	/*	the	thread	*/
void	print_char(int	ch);
int	state	=	0;	/*	shared	by	threads	*/

int	main(void)
{
    pthread_t	tid1,	tid2;			/*	the	thread	identifier	*/
    pthread_attr_t	attr;				/*	set	of	attributes	for	the	thread	*/
    /*	get	the	default	attributes	*/
    pthread_attr_init(&attr);
    /*	create	two	threads	*/
    pthread_create(&tid1,&attr,runner,'O');
    pthread_create(&tid2,&attr,runner,'-');
    /*	now	wait	for	the	thread	to	exit	*/
    pthread_join(tid1,	NULL);
    pthread_join(tid2,	NULL);
    printf("\nstate	=	%d\n",state);
}

/*	thread	body	*/
void	*runner(void	*param)
{
    int	i;
    int	ch;
    ch	=	(int)param;
    print_char(ch);
    state++;
    pthread_exit(0);
}
void	print_char(int	ch)
{
    int	i,	j;
    for	(i=0;	i<100;	i++)	{
        putchar(ch);
        fflush(stdout);
        for	(j=0;	j<1000;	j++)		/*	delay	*/
            ;
    }
}