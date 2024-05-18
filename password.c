#include <pwd.h>
#include <stdio.h>
#include <sys/types.h>
main()
{
struct passwd *ptr;
int uid, gid;
uid = getuid();
gid = getgid();
printf("\nUser ID and Group ID using 
getuid(),getgid()");
printf("\nUser ID = %d", uid);
printf("\nGroup ID = %d", gid);
printf("\nPassword information using 
getpwuid()");
ptr = getpwuid(uid);
printf("\nUsername = %s\nPassword = 
%s", ptr->pw_name, ptr->pw_passwd);
printf("\nUser ID = %d\nGroup ID 
= %d", ptr->pw_uid, ptr->pw_gid);
printf("\nHome Directory = %s\nShell = 
%s", ptr->pw_dir, ptr->pw_shell);
printf("\nPassword information using 
getpwnam()");
ptr = getpwnam("mca02-31");
printf("\nUsername = %s\nPassword = 
%s", ptr->pw_name, ptr->pw_passwd);
printf("\nUser ID = %d\nGroup ID 
= %d", ptr->pw_uid, ptr->pw_gid);
printf("\nHome Directory = %s\nShell = 
%s", ptr->pw_dir, ptr->pw_shell);
}