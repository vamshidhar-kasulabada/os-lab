#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#define max 256
void main()
{ 
int p1[2],p2[2],pid,n,i;
char msg[max];
pipe(p1);
pipe(p2);
pid=fork();
if(pid==0)
{
close(p2[0]);
close(p1[1]);
for(i=1;i<=5;++i)
{ 
printf("\nEnter any msg: ");
fflush(stdout); 
scanf("%s",msg);
write(p2[1],&msg,sizeof(msg));
n=read(p1[0],&msg,max);
printf("Server echoed back: 
%s\n",msg);
}
}
else
{
close(p1[0]);
close(p2[1]);
for(i=1;i<=5;++i)
{
n=read(p2[0],&msg,max
);
printf("\nServer received from 
client is: %s\n",msg);
write(p1[1],&msg,n);
}
}
}