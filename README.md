# yake lang
[Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) lang but shittier (ongoing proj.)

```zsh
$ make yake
$ ./yake "++.<<."
2
8
```

**Storing**

```zsh
./yake "++.@@.<.@+@.&-&.&+&."
```

*visual output*

```zsh
&v : 2 | 0x6000005c9260 -> 0
&v : 2 | 0x6000005c9260 -> 2 
&v : 4 | 0x6000005c9260 -> 2
&v : 4 | 0x6000005c9264 -> 4
&v : 2 | 0x6000005c9260 -> 2
```

**Arithmetic (Boolean) operations**
```zsh
./yake"+@@.<<.@+@.&-.%+."
```

*visual output*
```
&v : 1 | 0x6000032cd260 -> 1 | m = 0
&v : 4 | 0x6000032cd260 -> 1 | m = 0
&v : 4 | 0x6000032cd264 -> 4 | m = 0
&v : 4 | 0x6000032cd260 -> 1 | m = 1
&v : 5 | 0x6000032cd260 -> 1 | m = 0
```


**Operations**

Starting value : `0`

|sym|opr description|
|---|---|
|<kbd>+</kbd>|Increment|
|<kbd>-</kbd>|Decrement|
|<kbd><</kbd>|Left Shift|
|<kbd>></kbd>|Right Shift|

**Methods**

|sym|meothod description|
|---|---|
|<kbd>.</kbd>|Display current value (equ. fxn is printf)|
|<kbd>&</kbd>|Move pointer and get value|
|<kbd>@</kbd>|Move pointer and store value|
|<kbd>%</kbd>|% followed by <kbd>+</kbd> or <kbd>-</kbd> adds the current pointer address value to `v`|


