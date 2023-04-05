# JSON是什么
用于**网络传输(报文)**或**配置文件**的一种数据格式。
既然是一种数据格式那么必然牵扯到数据类型与数据格式(规则，语法)。

# JSON语法规则
1. JSON支持的的数据类型有：数值型、布尔型、字符串、数组、对象以及空类型
1. JSON中的数据以键值对的形式书写，且必须使用`"键名":值`的形式书写，不同的键值对使用`,`分隔。**最后一个值后面不加","**。
1. 键值具有唯一性，如果定义两个同名键值后一个对前一个进行覆盖。
1. 所有的JSON数据需要包裹在一个花括号中
1. 一个Json文件中只允许一个大的Json结构(数组或者对象)

# JSON中的数据介绍
- 数值：无特殊情况，浮点数可使用e或E进行指数表示
- 布尔：无特殊情况
- 字符串：无特殊情况，可使用转移字符
- 空：值为null
- 数组：JSON中数组由方括号(\[ \])和其中的若干值组成。数组的值可以是JSON中的任意数据类型，并支持多层嵌套。数组中的多个值之间使用逗号(,)分隔，最后一个值后边不加逗号
- 对象：JSON中对象是使用`{ }`包裹起来的无序键值对的集合。对象支持多层嵌套。
- **JSON中数据的主要呈现形式是数组和对象，两者之间可任意嵌套**

# 一个JSON实例
```json
//本实例来自JSON中国
{
    "glossary": {
        "title": "example glossary",
        "GlossDiv": {
            "title": "S",
            "GlossList": {
                "GlossEntry": {
                    "ID": "SGML",
                    "SortAs": "SGML",
                    "GlossTerm": "Standard Generalized Markup Language",
                    "Acronym": "SGML",
                    "Abbrev": "ISO 8879:1986",
                    "GlossDef": {
                        "para": "A meta-markup language, used to create markup languages such as DocBook.",
                        "GlossSeeAlso": [
                            "GML",
                            "XML"
                        ]
                    },
                    "GlossSee": "markup"
                }
            }
        }
    }
}
```

# JSON拓展
为改进JSON存在的一些问题，有了非官方的JSON5以及yaml的衍生。
此外JSON还存在着一种规范：Json Schema
## 1.JSON5
JSON5是非官方的JSON升级版，目的是兼容现有JSON格式的同时，减少JSON的某些限制
- 在对象或数组的末尾（即最后一个键/值对或值），可以添加逗号；
- 字符串可以使用单引号定义；
- 字符串中可以包含转义字符，并且可以跨越多行；
- 可以定义十六进制的数字；
- 数字可以包含前导或后导的小数点；
- 数字前可以添加一个加、减号来表示正负数；
- 可以使用//来定义单行注释，使用/* ... */来定义多行注释。

## 2.JSON与yaml
更轻量化的JSON

## 3.Json Schema(JSON模式)
校验JSON数据用的。书写JsonSchema时百度百度就好。