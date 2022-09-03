## The Seven rules of a great Git commit message
```c
1.Separate subject from body with a blank line
2.Limit the subject line to 50 characters
3.Capitalize the subject line
4.Do not end the subject line with a period
5.Use the imperative mood in the subject line
6.Wrap the body at 72 characters
7.Use the body to explain what and why vs. how
```
- 用空行将主题与正文分开
- 将主题行限制为 50 个字符
- 将主题行大写
- 不要以句点结束主题行
- 在主题行中使用命令式语气
- 将正文包装为 72 个字符
- 使用正文来解释做了什么，为什么而不是如何做

下面是一个极好的Git commit message
```c
commit eb0b56b19017ab5c16c745e6da39c53126924ed6
Author: Pieter Wuille <pieter.wuille@gmail.com>
Date:   Fri Aug 1 22:57:55 2014 +0200

   Simplify serialize.h's exception handling

   Remove the 'state' and 'exceptmask' from serialize.h's stream
   implementations, as well as related methods.

   As exceptmask always included 'failbit', and setstate was always
   called with bits = failbit, all it did was immediately raise an
   exception. Get rid of those variables, and replace the setstate
   with direct exception throwing (which also removes some dead
   code).

   As a result, good() is never reached after a failure (there are
   only 2 calls, one of which is in tests), and can just be replaced
   by !eof().

   fail(), clear(n) and exceptions() are just never called. Delete
   them.
```

引原网站的一句话：
未来的维护者，感谢你的可能是你自己
The future maintainer that thanks you may be yourself!


本文摘抄自：https://cbea.ms/git-commit/#separate