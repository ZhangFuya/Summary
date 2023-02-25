    安装VMTools
    sudo apt install open-vm-tools-desktop
    
    安装一些必要软件，见文档结尾    

    静态网络配置
    1.查看网卡、ip、子网掩码、网关
    ifconfig
    route -n
    修改配置文件：
    sudo vim /etc/network/interfaces
    修改内容为：
    auto ens33 // 使用的网络接口，之前查询接口是为了这里
    iface ens33 inet static // ens33这个接口，使用静态ip设置
    address 192.168.20.124 	// 设置ip地址
    netmask 255.255.250.0 	// 设置子网掩码
    gateway 192.168.20.1 	// 设置网关
    dns-nameservers 114.114.114.114	//设置dns服务器地址
    设置网络为自定义类型
    sudo vim /etc/NetworkManager/NetworkManager.conf
    重启服务：
    sudo ip addr flush ens33
    sudo systemctl restart networking.service
    sudo service network-manager restart
    重启电脑
    注意事项：同一局域网下，相同的静态ip会相互抢占网络
    参考链接：https://www.jianshu.com/p/d69a95aa1ed7

    ssh服务的搭建
    1.确认是否安装ssh服务
    sudo apt policy ssh
    安装ssh服务
    sudo apt install openssh-client openssh-server
    2.启动ssh服务
    
    sudo systemctl restart sshd.service
    可以通过 ps -e | grep sshd 查看ssh服务是否启动
    
    ssh服务的免密登录：
    window和linux下同时输入 ssh-keygen -t rsa
    想办法将windows下 C:/Users/Username/.ssh/id_rsa.pub中的内容写入到linux的 ~/.ssh/authorized_keys中
    这里提供两种方法：
    a.在提供ssh连接的软件中使用 vim ~/.ssh/authorized_keys 然后将windows下的公钥复制。
    b.将公钥文件拷贝到linux中，然后 cat id_rsa.pub >> ~/.ssh/authorized_keys,记得删除id_rsa.pub

    设置root的免密登录
    Ubuntu中root默认没密码，所以要为root设置一个密码
    sudo su root
    passwd
    打开允许root免密登录的设置 vim /etc/ssh/sshd_config
    打开如下几项的开关(取消注释)并按照如下的值修改：
    LoginGraceTime  120
    PermitRootLogin  yes
    StrictModes  yes
    重启ssh服务
    sudo systemctl restart sshd.service
    设置root的免密登录
    root下输入ssh-keygen -t rsa
    然后将windows下的公钥写入到root下的~/.ssh/authorized_keys中

    Ubuntu下Git的创建与提交
    git clone git@gitee.com:ZhangFuya/my-application-configuration.git
    如果是私有仓库会报错，这时你需要将ssh生成的公钥添加到git仓库中去
    提交代码之前要将自己git的用户名和邮箱配置好
    git config --global user.name "XXX"
    git config --global user.email "XXXX"
    之后添加内容验证提交
    git add .
    git commit -m "XXXX"
    git push origin master
    
    你也可以先在本地创建一个git仓库，之后进行gitee的提交
    git init
    git remote add origin git@gitee.com:ZhangFuya/my-application-configuration.git
    git pull origin master
    极危险操作：使用git push origin master -f强制推送到gitee，以保证在gitee上有内容时无法提交

    vim
    net-tools
    openssh-client  openssh-server
    git 
    tree
    gcc g++ gdb make
    cmatrix
    sqlite3 libsqlit3-dev

    sudo apt install vim net-tools openssh-client \
    openssh-server  git  tree  gcc g++ gdb cmake \
    sqlite3  libsqlit3-dev cmatrix  