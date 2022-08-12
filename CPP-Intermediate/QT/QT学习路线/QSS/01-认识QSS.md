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

