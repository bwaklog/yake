# yake lang
[Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) language but shittier (ongoing project).

- The program uses a pointer to an address in the heap, along with temporary storage for one variable only called `v` starting at the value 0. This is done with basic arithmetics and shifting operations ('+', '-', '<', '>'). 
- With the help of `&` to fetch the value stored in v where the main program pointer is at.
- `@` is used to store the current value of `v` where the pointer is pointing at. This is mode also lets us modify the position of the pointer. The first `@` starts the pointer mode of the program, so all `+` and `-` modify the pointers value, and calling `@` again would switch out of the pointer mode. All following operations would affect the temporary value.
- `&` is also used for switching to the pointer mode, but the difference is that, when we close the operations within another `&`, it stores the current value at the heap pointed by the pointer is stored in the temporary value `v`.

```text
&<pointer arithmetic operations>& -> stores value at addr location to v
@<pointer arithmetic operations>@ -> writes value of v to addr location
```

- `.` is used to print(debug) the current state of the program, showing the current value of the temporary variable `v` and the pointer location.

The motive of this project is to have a simple esoteric language, for fun

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

**Explanation**

<img width="600" alt="Screenshot 2024-01-06 at 10 09 19 PM" src="https://github.com/bwaklog/yake/assets/91192289/4384f71d-1a19-45c3-9cc4-b6e8e6f13d83">


**Wanna print a string, well time to learn your asciis**

```zsh
$ ./yake "+<<<<<<++++++++@@+@+@>---@+@&--&>>>>-:"
HI!
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
|<kbd>:</kbd>|Print out letters for range `v`...yeah the same `v` you have been using upto now|


