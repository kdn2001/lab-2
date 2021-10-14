#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>

#define   MAX_COUNT  200
#define   BUF_SIZE   100

void  childProcess(int);                /* child process prototype  */
void  Parentprocess(void);   
long int random(void);

void  main(void){
  pid_t  pid;
  int number;
  
  // for loop to create more than one child processes
   for (number = 0; number < 2; number++){
     //function to create processes
     pid = fork();
     if (pid == 0)
           childProcess(number);
     else if (pid < 0)
         printf("error in the fork\n");
  }
  Parentprocess();
  
}

void  childProcess(int myid){
  int i;
  int random_n;
  int random_m;
  
  random_m = rand()%2 +1;
  for(i = 0; i < random_m; i++ ){
    printf("Child Pid: %d is going to sleep now!\n",getpid());
  
    srand(getpid());
  
    random_n = rand()%10;

    sleep(random_n +1);
      printf("Child Pid: is awake now!\n Where is my parent: %d\n",getppid());
    
  }
   exit(0);

  
}

void  Parentprocess(void){
 int number;
 int pid;
 int status;
 for(number = 0; number <2; number++){
   pid = wait(&status);
   printf("Childp Pid: %d has completed\n",pid);
 }
     
}