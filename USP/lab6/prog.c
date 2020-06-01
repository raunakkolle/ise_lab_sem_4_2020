#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void handle_sigint(int sig)
{
    printf("Caught signal Interrupt %d\n", sig);
}
void handle_sigfpe(int sig)
{
    printf("Caught signal FPE %d\n", sig);
    exit(0);
   
   
}
void handle_sigsegv(int sig)
{
    printf("Caught signal SEGV %d\n", sig);
     exit(0);
}
void handle_sigchld(int sig)
{
    printf("Caught signal CHLD %d\n", sig);
}
void handle_sigill(int sig)
{
    printf("Caught signal ILL %d\n", sig);
}

 
int main()
{
    signal(SIGINT, handle_sigint);
    signal(SIGFPE, handle_sigfpe);
    signal(SIGSEGV, handle_sigsegv);
    signal(SIGCHLD, handle_sigchld);
    signal(SIGILL, handle_sigill);
   
     printf("1. press ctrl C for SIGINT\n");
   
    printf("2. SIGFPE \n");
   
    printf("3. SIGSEGV \n");
   
    printf("4. SIGCHLD \n");
   
    printf("5. SIGILL \n");
   
    int k ;
    scanf("%d",&k);
    int* z;
    switch(k){
    case 1: while(1);
    case 2: printf("%d : ", 2%0); break;

    case 3:
            *(z+1000000) = 0; break;
           
    case 4: fork(); wait(); break;
   
    case 5: z =  raise(SIGILL); break;
   
    }    
   
   
   
   
    return 0;
} 
