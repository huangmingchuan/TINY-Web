# TINY-Web
TINY-Web 是《深入理解计算机系统》书中的一个 HTTP Web 服务器，虽然缺乏一个实际服务器所具备的功能性、健壮性和安全性，但是用来学习已经足够了。

系统环境：Ubuntu 12.04 

编译器：gcc 4.6.3

启动方式：
```
gcc tiny.c csapp.c -o tiny -lpthread
cd cgi-bin
gcc -O1 adder.c -o adder -I../
cd ..
./tiny 8888

```

然后用浏览器访问
```
http://localhost:2000/cgi-bin/adder?xxxx&yyyy
```