#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
int fd1,fd2;
char ch;
if(argc!=3)
{
printf("\nUsage: mycp<src 
file><dest file>");
return;
}
fd1=open(argv[1],O_RDONLY);
if(fd1<0)
{ 
perror(" ");
return; 
} 
fd2=open(argv[2],O_WRONLY|O_CREAT
,0777);
if(fd2<0)
{
perror(" ");
return;
}
while(read(fd1,&ch,1)==1)
write(fd2,&ch,1);
close(fd1);
close(fd2);
}