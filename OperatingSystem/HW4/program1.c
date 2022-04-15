/* Simple program demonstrating shared memory in POSIX systems. */ 
#include <stdio.h> 
#include <sys/shm.h> 
#include <sys/stat.h>
#include <wait.h>

int main(void)
{
	int pid;		/* the identifier for the shared memory segment */ 
	int segment_id;	/* a pointer to the shared memory segment */ 
	char* shared_memory; /* the size of the shared memory segment (byte) */ 
	const int segment_size = 4096;	
	
	/** allocate a shared memory segment */ 
	segment_id = shmget(IPC_PRIVATE, segment_size, S_IRUSR | S_IWUSR); 
	printf("create shared memory : segment_id = %d\n", segment_id);
	
	/** attach the shared memory segment */ 
	shared_memory = (char *) shmat(segment_id, NULL, 0);
	
	pid = fork(); 
	if (pid < 0)
		return -1; 
	else if (pid == 0) { /* child */
		/** write a message to the shared memory segment */
		sprintf(shared_memory, "Hello Parent"); 
		/** now detach the shared memory segment */ 
		if ( shmdt (shared_memory) == -1) {
			fprintf(stderr, "Unable to detach\n");
		}			
		else { /* parent */
			wait(NULL); 
			/** now print out the string from shared memory */ 
			printf("*%s*\n", shared_memory); 
			/** now detach the shared memory segment */ 
			if ( shmdt (shared_memory) == -1) {
				fprintf(stderr, "Unable to detach\n");
			}
			
			/** now remove the shared memory segment */ 
			shmctl(segment_id, IPC_RMID, NULL);
		}
	return 0;
}