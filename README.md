# TINY-Web
TINY-Web 是《深入理解计算机系统》书中的一个 HTTP Web 服务器，虽然缺乏一个实际服务器所具备的功能性、健壮性和安全性，但是用来学习已经足够了。

系统环境：Ubuntu 12.04 

编译器：gcc 4.6.3

启动方式：
```
gcc tiny.c csapp.c -o tiny 
cd cgi-bin
gcc adder.c -o adder -I../
cd ..
./tiny 8888
```

然后用浏览器访问
```
http://localhost:8888/cgi-bin/adder?xxxx&yyyy
```

结果如图

![screen](https://github.com/huangmingchuan/TINY-Web/raw/master/screen.png)

### 内容分析
TINY-Web 只实现了 GET 请求，并且一次只能连接一个客户端。在获得 GET 请求后，会忽略掉所有请求头。然后判断 uri 是不是静态文件，返回对应的静态内容或动态内容。

如果要返回动态内容，则 Fork 一个子进程调用 CGI 程序，并且父进程阻塞直到子进程终止。

从功能上来看，这个程序只能算做是个理论上的东西。在几百行代码里，涉及到了 Unix IO、Socket、进程控制、HTTP协议，就好像将之前的知识点连成线，然后织成网这种感觉。

所以从学习的角度而言，这个项目的作用是很大的。