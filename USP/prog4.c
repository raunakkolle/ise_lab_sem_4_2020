#include<stdio.h>
#include<setjmp.h>

void usd1(jmp_buf buf)
{
   printf("Inside the user defined function 1\n");
   longjmp(buf,1);
   printf("user defined function 1\n");
}

void usd2(jmp_buf buf)
{
   printf("Inside the user defined function 2\n");
   longjmp(buf,2);
   printf("User defined function 2\n");
}

int main()
{
  printf("Entered the Main Function\n");
  jmp_buf buffer;
  printf("Setting jumper\n");
  
  int res =setjmp(buffer);
  
  if(res==1)
  {
     printf("Calling to USD 2 from the main function\n");
     usd2(buffer);
     printf("Back to main 2\n");
  }
  else if(res==2)
  {
    printf("Now res is == 2 \n");
  }
  else
  {
    printf("Calling to USD 1 from main function\n");
    usd1(buffer);
    printf("Back to main 1 \n");
  }
  return 0;
}    
         
      
