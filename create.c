#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
main()
{
int fd,n,m;
char buf1[100],buf2[100];
fd=open("v.txt",O_WRONLY|O_CREAT,0600); 
printf("enter a string:");
fflush(stdin);
scanf("%s",buf1);
n=write(fd,buf1,strlen(buf1));
printf("\n no of bytes written: %d",n);
close(fd);
fd=open("v.txt",O_RDONLY); 
m=read(fd,buf2,n);
printf("\n no of bytes read:%d",m);
buf2[n]='\0';
printf("\n readed string :%s\n",buf2);
close(fd);
}