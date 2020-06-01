// C Program for Message Queue (Writer Process) 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <string.h> 
#include <stdlib.h> 

// structure for message queue 
struct mesg_buffer { 
	long mesg_type; 
	char mesg_text[100]; 
} message; 

int main() 
{ 
	key_t key; 
	int msgid; 

	// ftok to generate unique key 
	key = ftok("progfile", 65); 

	// msgget creates a message queue 
	// and returns identifier 
	msgid = msgget(key, 0666 | IPC_CREAT); 
	message.mesg_type = 1; 


                while(1){
                long read_write, msg_type;
                printf("1. read, 2. write 3.destroy: ");
                scanf("%ld",&read_write);
                if(read_write == 1){
                       // Read
                       printf("msg_type:");
                       scanf("%ld",&msg_type);
                       msgrcv(msgid, &message, sizeof(message), msg_type, 0);
                       printf("Data Received is : %s \n",message.mesg_text);  
                }
                else if (read_write == 2){
                        // Write
                       printf("msg_type:");
                       scanf("%ld",&message.mesg_type);
                       printf("msg_content:");
                       scanf("%s",message.mesg_text);
                       //gets(message.mesg_text);
                       msgsnd(msgid, &message, sizeof(message), 0); 
                       printf("Data send is : %s \n", message.mesg_text); 
                        
                }
                else {
                        msgctl(msgid, IPC_RMID, NULL); 
                        exit(0);
                }
        
        
        
        }



	return 0; 
} 

