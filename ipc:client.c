#include<stdio.h>                                                      
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include"comm.h"
#include<unistd.h>
int main()
{
  key_t k = ftok(PATHNAME,PROJ_ID);
  printf("key: %p\n",k);
  //共享内存创建/使用，已在server端创建完毕，直接使用即可
  int shmid = shmget(k,SIZE,0);
  //若创建失败，则抛异常
  if(shmid<0)
  {
    perror("shmget error!\n");
    return 1;
  }
  //打印shmid
  printf("shmid:%d\n",shmid);
  //shmctl(shmid,IPC_RMID,NULL);sleep(10);
  char *str=shmat(shmid,NULL,0);sleep(1);
  char c='a';
  for(;c<='z';c++)
  {
    str[c-'a']=c;
    sleep(1);
  }
  shmdt(str);sleep(2);
  //shmctl(shmid,IPC_RMID,NULL);sleep(2);
  return 0;
}
————————————————
版权声明：本文为CSDN博主「You are my ghost」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_43745617/article/details/115571079
