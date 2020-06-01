#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void login(FILE *fp){
    printf("LOGIN CALLED\n");
    //FILE *fp = NULL;
    //fp = fopen ("/tmp/Log.txt", "a+");
    fprintf(fp, "Login called...\n");

    fflush(fp);
    
}

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;
    pid_t process_id = fork();
    pid_t sid;
    if (process_id < 0)
    {
        printf("fork failed!\n");
        // Return failure in exit status
        exit(1);
    }
    // PARENT PROCESS. Need to kill it.
    if (process_id > 0)
    {
        printf("process_id of child process %d \n", process_id);
        // return success in exit status
        exit(0);
    }


    sid = setsid();
    if(sid < 0)
{
    // Return failure
    exit(1);
}

    chdir("/");
    // Close stdin. stdout and stderr
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    fp = fopen ("/tmp/Log.txt", "w+");
    int count = 0;
    while (1)
{
    //Dont block context switches, let the process sleep for some time
    sleep(2);
    
    fprintf(fp, "%d Logging info...\n", count++);
    fflush(fp);
    if (count == 5)
    {
        login(fp);
    }

    // Implement and call some function that does core work for this daemon.
    }
    fclose(fp);
    return (0);


    
}
//https://www.informit.com/articles/article.aspx?p=397655&seqNum=6

//https://www.computerhope.com/unix/uumask.htm

//https://www.thegeekstuff.com/2012/02/c-daemon-process/

//https://www.cyberciti.biz/faq/how-do-i-find-all-the-files-owned-by-a-particular-user-or-group/



