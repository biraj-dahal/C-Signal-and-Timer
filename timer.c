/*timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

bool return_to_main = false;
int begin;

void handler(int signum) //signal handler
{ 
  printf("Hello World!\n");
  return_to_main = true;
}

void sig_int_handler(int signum){
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("The total execution of time is: %f seconds.\n", time_spent);
  exit(0);
}

int main(int argc, char * argv[])
{
  begin = clock();
  signal(SIGINT, sig_int_handler);
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1);

  
  while(1){ //loop indefinitely to print
  if(return_to_main){ 
    printf("Turing was right!\n");
    return_to_main=false;
    alarm(1);
  }
  };

  return 0; 
}
