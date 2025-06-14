# 5. 使用逻辑运算功能
> ## 5. Use boolean caculation

## 逻辑运算

> ### Boolean calculation

Code:
```junlang
new a
input a
new b
equal a 2 b
output b
```

此段代码判断a是否等于2，将结果赋值到变量b，并输出。
> This code determines whether variable `a` is equal to 2, assigns the result to variable `b`, and outputs it.

<br/>
<br/>
<br/>

输入：`2`
> Input: `2`

输出：`1`
> Output: `1`

<br/>
<br/>

输入：`3`
> Input: `3`

输出：`0`
> Output: `0`

<br/>
<br/>
<br/>
<br/>

以此类推：
> And so on:

判断是否等于另一个变量就将2改为变量名，
> To determine if it is equal to another variable, change `2` to the variable name,

判断是否大于，就将`equal`改为`greater`，
> To determine if it is greater than, change `equal` to `greater`,

判断是否小于，就将`equal`改为`less`，
> To determine if it is less than, change `equal` to `less`,

判断是否大于等于，就将`equal`改为`equal-or-greater`，
> To determine if it is greater than or equal to, change `equal` to `equal-or-greater`,

判断是否小于等于，就将`equal`改为`equal-or-less`，
> To determine if it is less than or equal to, change `equal` to `equal-or-less`,

还有非运算：将`equal`改为`not`，并将2省略。
> There are also non operations: change `equal` to `not` and omit 2.

## if判断
> if judgment
Code:
```junlang
new a
input a
new b
input b
new c
equal a b c
if c
output "1"
end-if
```

这段代码判断输入的a和b是否相等，如相等输出1。
> This code determines whether input `a` and `b` are equal, such as output 1.

<br/>
<br/>
<br/>

输入：`1 1`
> Input: `1 1`

输出：`1`
> Output: `1`

<br/>
<br/>

输入：`1 2`
> Input: `1 2`

输出：`无输出`
> Output: `No output`

<br/>
<br/>
<br/>
<br/>

## loop循环
> loop

Code:
```junlang
new a
set a 0
new b
set b 1
loop b
output a
wrap
addition a 1
less a 10 b
end-loop
```

这段代码判断如果a小于10，就不断输出并增加a的值。
> This code determines that if a is less than 10, it will continuously output and increase the value of `a`.

<br/>
<br/>
<br/>

输入：`无输入`
> Input: `No input`

输出：
> Output: 
```
0
1
2
3
4
5
6
7
8
9
```
<br/>
<br/>
<br/>
<br/>