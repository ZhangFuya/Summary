## WSL常用指令
### 重启WSL子系统
```shell
#停止LxssManager服务
net stop LxssManager  
 
#启动LxssManager服务
net start LxssManager  
```

## WSL更改软件源
使用WSL可能会出现一些常见的软件都无法安装的情况。     
这时就需要对WSL的软件源进行更改
1. 备份配置文件
`sudo cp /etc/apt/sources.list /etc/apt/sources.list.bak`
2. 修改配置文件
将 /etc/apt/sources.list 内容修改为：   
```
deb http://mirrors.aliyun.com/ubuntu/ focal main restricted
deb http://mirrors.aliyun.com/ubuntu/ focal-updates main restricted
deb http://mirrors.aliyun.com/ubuntu/ focal universe
deb http://mirrors.aliyun.com/ubuntu/ focal-updates universe
deb http://mirrors.aliyun.com/ubuntu/ focal multiverse
deb http://mirrors.aliyun.com/ubuntu/ focal-updates multiverse
deb http://mirrors.aliyun.com/ubuntu/ focal-backports main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ focal-security main restricted
deb http://mirrors.aliyun.com/ubuntu/ focal-security universe
deb http://mirrors.aliyun.com/ubuntu/ focal-security multiverse
```
3. 更新软件源
```
sudo apt update
sudo apt upgrade
```

本文摘抄自:> [乐天笔记——WSL配置](https://www.letianbiji.com/windows/wsl-ubuntu-software-source.html)    