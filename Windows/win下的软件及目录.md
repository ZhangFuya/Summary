C: System ，都已经放到C盘了就不要再讲究什么目录结构了，直接默认安装多好            
|                   
|---SSD，我用的是256GB的固态，分给C盘100GB其余的给了D盘，也就将将够用             
|             
D: Devlop ， D盘我给到了生存，所以命名命名为 Dev              
             
E: Liveer ， E盘用于存放一些软件，部分软件缓存              
|                 
|- 三个盘符就够了。但是F盘设置一个也还好，因为这样可以使得用起来更顺手。                   
|                  
F: 存放各式各样的文件，名字就定为 storage                     
               
命名规则：             
1. 7-12个字符是我的最佳观感，长命名超过20个字符              
2. 未到最后一级不使用长命名(无子文件夹即为最后一级)             
3. 未到最后一级禁止使用中文命名                
4. 长命名最好是排列在一起，不要与规则命名交叉             


## C盘 -- System            

- utools        
通过 Alt + Space 或 鼠标中键 调出一个命令框，完成各种琐碎的日常操作。           
    - utools、quicker、liatary         
    我用过utools和quicker，因为quicker是收费的嘛，所以我改用了utools。               
    对于不爱折腾的人来说，listary(免费版)足够了。特别喜欢折腾的友友quicker会是不错的选择。        

- office           
    office与WPS之间，我是选了office。       

- Neatreader               
    阅读电子书的一款软件，免费版就已经很不错了。             

- Obsidian             
    我看中了它的知识图谱            

- Google Chrom                
    用Google访问国外的网站习惯了。尽管Edge很强大还是会装一个Google。            

- Edge             
    PC端最强浏览器                 

- VScode                       
    一个 VSCode，一个 Edge 可抵得上千军万马。                   

- WeMeet (选装)                          
    如果要安装腾讯会议，默认安装，使得其安装在C盘                            
    因为腾讯会议会赋予安装路径管理员权限，然后安装路径上的所有文件夹使用者就没有修改权限。那完了只能看不能改了               


## D盘 -- Devlop(develop,为保证字符的一致性使用了devlop)

#### DevEnv  - 开发环境
- Git           
    这应该是所有开发人员的必备软件了。         

- CMake             

- Sqlite         
    嵌入式开发中表现优异的数据库           

- MySQL          
    使用极为广泛的一款数据库             

- MinGW (选装)               
    使用VScode、Clion开发C语言程序安装，其他情况不安装MinGW              

- Boost (选装)              
    希望对C++有更丰富的认识安装             

- Android (选装)              
    使用Qt开发Android安装            

- JDK (开发Android必装)               

#### DevFiles - 所有的工程文件             
- Project - (Source -> Gitee/Github)           
使用Git管理的项目。如：              
    - WinInAll           
    - application-configution           

- ClionProject - (Source -> Clion)          

- QtProject - (Source -> Qt)                 
- QtProject2                  

- VSProject - (Source -> VS/VScode)                       

***如果项目过多需要放入到不同的文件夹，就可以使用数字加以区分，如 QtProject2 。***           

#### DevSoftware - 开发所需的软件            
- JetBrains          
    - Clion            
    - DataGrip            
    DataGrip是我安装JetBrains产品的主要动力了             

- QT              
    - Qt5.15            
    - Qt6.0           
    因其出色的类库以及在嵌入式方面优秀的表现，短期内仍会处于霸主地位           
    之所以安装两个版本是因为，两版本的类库存在差异。为省去迁移导致的问题不如安装两个版本。          

- VisualStudio           
    - VisualStudio2019        
    - VisualStudio2022        
    Windows下最佳 C/C++ IDE          
    如果有需要可以安装多个版本，这并不会产生冲突     

- Keil5.23         
    嵌入式开发软件           
    相对而言 5.23 较其他版本好用一些      

- Wireshark             
    网络检测工具，做嵌入式开发还是要准备一下的         

- Enigma Virtual Box (选装)               
    打包程序，生成可在任意位置运行的 可执行程序             
- Setup Factory （选装）             
    配合Enigma Virtual Box生成软件安装包             

- VMware (选装)             
    VMware是极好的一款产品，但我感觉完全没必要。          
    产品收费，你需要找激活码。            
    再有它提供了十分便捷的快照，使得虚拟机具有很强的容灾性能。这很好，              
    但对于一名软件工程师来说把自己本应该具有的灾难处理能力交给了别人，这不好。           

    不需要使用linxu桌面，但又需要使用Linux可以安装WSL          
    需要用到linux桌面环境，可以考虑双系统 或者 使用U盘做系统磁盘，实现Linux桌面环境的即插即用            
    建议不愿意折腾 或者 需要一边在windows下工作，一边在linux下工作的友友安装           

- Android Studio (选装)           
    开发Android所需。            
    注意一点：使用Qt开发Android程序，             
    在安装Android Studio时一定要将Android Stdio安装的SDK库和Qt安装的SDK库放到同一个目录下                 
    如果Qt仍无法正常启动Android Studio创建的虚拟机，就要将Android Studio安装到和Android SDK同级的目录中          


## E盘 -- Liveer(软件)            

#### Application - 应用软件           
- Adobe             
    - AcrobatDC     
    PDF阅读器             
    - PhotoShop     
    最强图片编辑器              

- Multimedia            
    - Potplayer       
    最良心视频播放器                 
    - HoneyView            
    看图软件           
    - Blibli            
    BilBli客户端             
    - Obs-studio     
    最良心录屏软件      
    - Billfish          
    素材管理库               
    - Collagelt         
    将多个图片拼成一个         
    - ImageMatting             
    很强大的抠图软件                    

- Netease           
    - NeteEmail     
    网易邮箱       
    - Youdao           
    有道词典                     

- Tencent            
    - WeChat    
    微信                      
    - TencQQ     
    QQ               

#### GlightWare - 轻量级的软件          
- BettWin             
windows增强            
    - 7Zip       
    压缩软件       
    - Everything    
    搜索系统文件         
    - Seer           
    文件预览         
    - Snipaste
    截图软件             
    - TranslucentTB       
    任务栏透明    

- Depression          
解压缩就能用的         
    - geek     
    简洁版卸载软件        
    - HappyCrawler           
    B站视频下载      
    - GifCam  
    最小巧gif录制
    - HibiUnistall            
    很强大的一款软件，集卸载、垃圾清理、文件粉碎等于一身             
    - SpaceSniffer              
    扫面磁盘文件            

- Tools                   
    - Fast Copy          
    大文件快速拷贝            
    - Meazure               
    屏幕尺             

#### NetWork - 网络传输软件                  
- IDM    
最强下载器                   

- qBittorrent      
种子下载             

- Thunder       
破解版很好用         

- aDrive         
阿里云              

- BaiDiNetdisk               
百度网盘          

- Sunlogin          
向日葵远程控制            
- ToDesk(荐)    
远程控制，个人感觉优于向日葵          

#### OuterNet - 连外网           
- Stream++    

- Clash for Windows                  


## F盘 -- Strage(storage，为保证字符的一致性使用strage)    

#### Download            
所有软件的下载文件夹，此文件夹里的内容应按照文件类型分类              

#### Installpkg              
- Develop             

- Liver             
    我没分类，因为这些基本也用不上。之所以备一份是为了以防万一。            

#### Machine - 虚拟机存放位置           
- Ubuntu22            

#### Summary            
- Document          
 
- Ebooks         
    - 时光的歌 - 存放文学书籍           
    - 学习的海         

- ISOFile            
    - ubuntu22.04          

- Picture            
    - ICOFile             
    - SnipCache             
    - TimeAxis              
    - Wallpaper            

- Video            
    - Films           
    - MP3          
    - Others             

- 方向         