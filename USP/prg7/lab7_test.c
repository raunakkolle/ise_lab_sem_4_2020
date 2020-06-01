#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main(int argc, char const *argv[])
{
    FILE *fp = fopen ("/tmp/Log.txt", "a+");
    fprintf(fp, "Login called...\n");
    while(1){
    fprintf(fp, "TEST...\n");
        printf(".");
        fflush(fp);

    sleep(5);
    
    
    }
    return (0);


    
}
//https://www.informit.com/articles/article.aspx?p=397655&seqNum=6

//https://www.computerhope.com/unix/uumask.htm

//https://www.thegeekstuff.com/2012/02/c-daemon-process/

//https://www.cyberciti.biz/faq/how-do-i-find-all-the-files-owned-by-a-particular-user-or-group/
