


## escalating to SIGTERM

运行ros节点执行ctrl+c后进程会转而执行rosspin()后面的程序，但是如果在一定时间内程序没有执行完毕，进程会强制退出，并抛出”escalating to SIGTERM“错误，为了解决此问题，可以修改ros配置文件

```
/opt/ros/melodic/lib/python2.7/dist-packages/roslaunch/nodeprocess.py
```

将该文件第48行的“_TIMEOUT_SIGINT = 15.0 #seconds”中的15秒改为您期望运行的最大时间
