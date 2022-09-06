# Qss及其类型
Html中样式表被称为CSS          
Qt中的样式表被称为QSS(Qt Style Sheet)。用于设置程序UI界面中控件的背景图片、大小、字体颜色、字体类型、按钮状态变化等属性，美化UI界面，实现界面和程序的分离。可以快速切换皮肤。          
Qt中一般使用 setStyleSheet 语句来设置对应控件的样式表          
QSS的基本语法为 ： 选择器{ 声明 }          
选择器：通常情况下为控件类名(如： QPushButton)。**可以对多个选择器使用同一语句，但选择器之间要使用逗号隔开**          
QSS中选择器区分大小写，但声明不区分大小写。          
`eg: btn->setStyleSheet("QPushButton, QLabel{color : red}");`          
选择器后可以使用 :: 跟上子控件，比如 spinbox 中的上下选择按钮就是子控件。          
`eg: ui->spinBox->setStyleSheet("QSpinBox::up-arrow{image:url(:/image.ico)}");`          
选择器及其子控件后也可以跟上 : 添加伪状态。比如鼠标悬停在按钮上就是一种伪状态。          
`eg: btn->setStyleSheet("QPushButton:hover{color:green}");`          

## 选择器的类型
| 用法 |  例子 | 详解 |
| :---: | :---: | :---: |
| 通配选择器 | *  | 匹配所有的控件 |
| 类选择器 | 如 QPushButton | 匹配所有的QPushButton及其子类 |
| .类选择器 | 如 .QPushButton | 匹配所有的QPushButton 但不匹配其子类 |
| id选择器(#) |  如 QPushButton#but1 | 匹配QPushButton的but1实例 |
| 属性选择器 |QPushButton[flat="false"]| 作用于 flat="false" 的QPushButton实例 |
| 后代选择器 | QDialog QPushButton | 只匹配 QObject 中的所有层级的 QPushButton 样式 |
| 子选择器 | QDialog > QPushButton | 只匹配QDialog中第一层级的QPushButton的样式 | 

# Qss中的基础属性
## 颜色
QSS中的颜色除了系统已经预设的各种颜色，如：red、blue、yellow等还可以使用自定义颜色的各种属性。Qt中有多种方式指定颜色。          
### 1. 使用系统调制好的，直接使用英文单词
`this->setStyleSheet("QPushButton{color : blue}");`          

### 2.使用 rgb或者rgba
- rgb为三原色          
- rgba中的a表示透明度          
- r、g、b、a四种属性值范围都是 0 - 255          
`this->setStyleSheet("QPusnButton{color:rgba(100, 56, 43, 30)}");`          

### 3.使用#加六位十六进制数指定颜色
六位十六进制数，每两位表示三原色种中的一种。依次为 r、g、b          
`this->setStyleSheet("QPusnButton{color:#FFFFF");`          

### 4.使用色相、饱和度和明度(HSL)或HSLA
HSL: hue、saturation、lightness          
A表示透明度，是一个0到255的值。          
色相，是色轮上从0到360的度数。0是红色，120是绿色，240是蓝色          
饱和度，是一个百分比的值。0%表示灰度阴影，100%是金色          
亮度，是一个百分比的值。0%是黑色，50%是既不透明也不暗，100%是白色          
`this->setStyleSheet("QPusnButton{color:hsl(162, 20%, 30%)");`          

## 背景
### 1.背景颜色 background-color
`eg: this->setStyleSheet("QWidget{background-color : #F0F0F0}");`          

### 2.设置背景图片background-image
background-image后边要跟一个url（图片的链接）          
`eg: this->setStyleSheet("QWidget{background-image:url(:/image/33.jpg)}");`          
为避免项目移植时，程序无法加载图片，建议将图片放在项目对应的文件夹下          

### 3.避免图片重复加载 background-repeat
- 一般不单独使用。多和background-image配合使用防止出现重复的情况。          
- repeat，背景图片向水平方向和垂直方向重复。(这是加载图片的默认值)          
- repeat-x，水平方向重复          
- repeat-y，垂直方向重复          
- no-repeat，不会重复          
- inhert，指定background-repeat属性设置应该从父元素继承。          

### 4.图片位置 background-position。
- 一般不单独使用。和background-image配合使用设置image的位置          
- 可供使用的属性值有： top left(左上)、top center(靠上居中)、top right(右上)、left center(靠左居中)、center center(正中)、right center(靠右居中)、bottom left(左下)、buttom center(靠下居中)、bottom right(右下)          

### 5.图片滚动 background-attachment
图片滚动只有两个值，默认值 scroll(滚动)和 fixed(固定)          

### 6.background格式简写 background: color image repeat position
background 设置背景，属性值可以缺省，但顺序最好不要变          
`eg: this->setStyleSheet("background: green url(:/image/1.jpg) no-repeat right bottom")`          


## 边框
边框可以是围绕元素内容和内边距的一条或多条线，对于这些线条，可以定义它们的样式、宽度以及颜色。          
**边框的所有属性可以设置一到四个值（用于上边框、右边框、下边框、左边框,如果未指定对应的值，左边框使用右边框的值，下边框和右边框使用上边框的值）**          
**可以通过 top、bottom、left、right设置指定边框的样式**          

### border-color设置边框颜色

### border-style指定要显示的边框类型
- dotted - 点线边框          
- dashed - 虚线边框          
- solid - 实线边框          
- double - 双边框          
- groove - 3D坡口边框，效果取决于 border-color的值          
- ridge - 定义3D脊线边框，效果取决于 border-color的值          
- insert - 定义3Dinsert边框，效果取决于 border-color的值          
- outside - 定义3Doutside边框，效果取决于 border-color的值          
- none - 定义无边框          
- hidden - 定义隐藏边框          


### border-width设置边框宽度
边框宽度既可以使用特定值，如px、pt等，也可以使用预定义的值：thin、medium、thick          

### 简写样式border
border对应的属性值分别为： border-width、border-style、border-color          
不同于其他属性可以缺省，border-style为必填项。          

### border-radius 设置圆角
border-radius设置圆角，取值可以是固定值，也可以是百分比的一个值。          

### 盒子模型
- 外边距 margin          
- 边框 border          
- 内边距 padding          
- 内容 content          


## 字体
通用字体族：
在CSS中，有五个通用字体族：
- 衬线字体(serif) -- 在每个字母的边缘都有一个小的笔触。它们营造出一种形式感和优雅感          
- 无衬线字体(sans-serif) -- 字体线条简洁，营造现代、简约的外观          
- 等宽字体(monospace) -- 所有的字母都有相同的固定宽度。营造机械式的外观          
- 草书字体(cursive) -- 模仿人类的笔迹          
- 幻想字体(fantasy) -- 装饰性/俏皮的字体          
所有不同的字体名称均属于这五个通用字体系列之一。          

### 字体属性
- font -- 简写属性，在每一条声明中设置所有字体属性          
font简写的字体属性，属性值分别对应：font-style、font-variant、font-weight、font-size、font-family。可以缺省，但顺序最好不要变。          
- font-family -- 字体系列(字体族)          
- font-size -- 字体大小          
可以使用绝对大小，如像素。和相对大小。          
- font-weight -- 字体的粗细          
font-weight的取值可以是normal、bold、light等值也可以是数字          
- font-style -- 字体样式          
font-style属性可以设置三个值。normal-文字正常显示。italic-斜体。oblique-倾斜(倾斜与斜体非常相似，所以一般都是使用斜体，对oblique支持的很少)          
- font-variant -- 是否以小型大写字母显示文本          

# Qss进阶
## 子控件
许多部件包含子元素，这些元素可以称为"子部件"。如QComboBox是由一个内容框和一个下箭头；QSpinBox由一个内容框和上下箭头组成。          
QSS中可以通过使用子部件来定义微观样式。          
**通过 控件类名::子控件名 可以指定子控件，进行子控件样式的修改**          
子控件也遵循盒子模型，可以对子控件进行内外边距，边框以及内容的样式设定。          
子控件的位置(position属性)是相对于父控件的，可以进行水平以及垂直方向的设置。水平方向取值有：top、center、right。垂直方向取值有：top、center、bottom。          


## 伪状态
用户在操作时，可以根据不同的交互状态展示不同的用户样式。          
伪状态通过 (:) 进行指定。          
伪状态可以使用 ! (非) 进行反向选择。          
多个伪状态之间可以使用逗号分隔，          
子控件也可以使用伪状态。          

