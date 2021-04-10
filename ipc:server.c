int main()
{
  //获取ipc通讯指定ID
  key_t k = ftok(PATHNAME,PROJ_ID);
  printf("key: %p\n",k);
  //创建共享内存                                                       
  int shmid = shmget(k,SIZE,IPC_CREAT|0666);
  //创建失败则抛异常
  if(shmid<0)
  {
    perror("shmget error!\n");
    return 1;
  }
  //打印shmid
  printf("shmid:%d\n",shmid);
  //连接共享内存与进程的地址空间
  char *str=shmat(shmid,NULL,0);//sleep(5);
  //每隔一秒打印一次str
  while(1)
  {
    sleep(1);
    printf("%s\n",str);
  }
  //解除进程与共享内存区域的关联
  shmdt(str);
  //清空共享内存
  shmctl(shmid,IPC_RMID,NULL);//sleep(10);
  return 0;
}    
————————————————
版权声明：本文为CSDN博主「You are my ghost」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_43745617/article/details/115571079
