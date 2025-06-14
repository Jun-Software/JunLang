# 2. 使用输出系统输出字符串
> ## Use output system to output string

## 输出单行文本
> ### Output single line text

Code:
```junlang
output "Hello_world!"
```
保存为后缀是.jun的文件，编码为ANSI，并使用`JunLang.exe <文件名>`运行，
> Save as a file with the suffix .jun, encode it as ANSI, and run it using `JunLang.exe <file name>`,
<br/>
<br/>
<br/>

输入：`无输入`

> Input: `No input`

输出：`Hello world!`

> Output: `Hello_world!`
<br/>
<br/>
<br/>
<br/>

**注意：**

> **Warning:**

**`Hello`和`world!`之间不是空格，是`_`，**

> **There is a `_` between `Hello` and `world!`**

## 输出多行文本
> ### Output multi lines text

Code:
```junlang
output "Hello_world!"
wrap
output "Hello_world!"
```
保存编码为ANSI并运行，
> Save as a file, encode it as ANSI, and run it.
<br/>
<br/>
<br/>
输入：`无输入`

> Input: `No input`

输出：
> Output:
```
Hello world!
Hello world!
```

<br/>
<br/>
<br/>
<br/>

**注意：要用`wrap`换行标识符进行换行**
> **Warning: Use `wrap` to end line.**
