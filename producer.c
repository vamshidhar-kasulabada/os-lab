#include<stdio.h>
#include<stdlib.h>
int full = 0, empty, n, buffer[20],
item;
int in = 0, out = 0, mutex = 1;
void wait(int s){
while (s<0)
{
printf("\nCannot add
item\n");
exit(0);
11) }
12) s--;
13) }
14) void signal(int s){
15) s++;
16) }
17) void producer(){
18) do
19) {
20) wait(empty);
21) wait(mutex);
22) printf("\nEnter an item: ");
23) scanf("%d"
,&item);
24) buffer[in] = item;
25) in = in + 1;
26) signal(mutex);
27) signal(full);
28) } while (in<n);
29) }
30) void consumer(){
31) do
32) {
33) wait(full);
34) wait(mutex);
35) item = buffer[out];
36) printf("\nItem consumed:
%d"
,item);
37) out = out + 1;
38) signal(mutex);
39) signal(empty);
40) } while (out<n);
41) }
42) void main(){
43) printf("Enter the value of n:
");
44) scanf("%d"
,&n);
45) empty = n;
46) while (in<n)
47) {
48) producer();
49) }
50) while (out!=n)
51) {
52) consumer();
53) }
54) }
