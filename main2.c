#include  <stdio.h>
#include  <sys/types.h>

#define   MAX_COUNT  200

void  childProcess(void);                /* child process prototype  */
void  Parentprocess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;

     pid = fork();
     if (pid == 0) 
          childProcess();
     else 
          Parentprocess();
}

void  childProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("   This line is from child, value = %d\n", i);
     printf("   *** Child process is done ***\n");
}

void  Parentprocess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("This line is from parent, value = %d\n", i);
     printf("*** Parent is done ***\n");
}