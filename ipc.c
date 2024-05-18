#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
int childid, fd[2], uid;
char string[40];
char buffer[40];
pipe(fd);
if((childid=fork())<0){
printf("Error");
exit(0);
}
if (childid==0)
{
close(fd[0]);
printf("\nEnter string: ");
gets(string);
printf("\nChild process sends the 
string %s", string);
write(fd[1], string, 
strlen(string)+1);
}
else{
close(fd[1]);
printf("\nParent Process");
uid = read(fd[0], buffer, 
sizeof(buffer));
printf("\nParent process receives 
the string %s", buffer);
}
}