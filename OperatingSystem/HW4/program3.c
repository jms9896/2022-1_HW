#include	<stdio.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<string.h>
#define	BUFFER_SIZE	32
int	main(void)
{
    char	write_msg[BUFFER_SIZE]	=	"Hello	Pipe	Message";
    char	read_msg[BUFFER_SIZE];
    pid_t	pid;
    int	fd[2];						/*	0:	read	end,	1:	write	end	*/
   
    /*	create	the	pipe	*/
    if	(pipe(fd)	==	-1)	{
        fprintf(stderr,"Pipe	failed");
        return	1;
    }

    /*	now	fork	a	child	process	*/
    pid	=	fork();

    if	(pid	<	0)	{
        fprintf(stderr,	"Fork	failed");
        return	1;
    }	
    else if	(pid	>	0)	{		/*	parent	process	*/
        /*	close	the	unused	read	end	of	the	pipe	*/
        close(fd[0]);
        /*	write	to	the	pipe	*/
        write(fd[1],	write_msg,	strlen(write_msg)+1);
        /*	close	the	write	end	of	the	pipe	*/
        close(fd[1]);
    }	
    else{		/*	child	process	*/
        /*	close	the	unused	write	end	of	the	pipe	*/
        close(fd[1]);
        /*	read	from	the	pipe	*/
        read(fd[0],	read_msg,	BUFFER_SIZE);
        printf("child	read	message	=		%s\n",read_msg);
        /*	close	the	write	end	of	the	pipe	*/
        close(fd[0]);
    }
    
    return	0;
}