# Basic Shell.
 - Linux Shell if Case sensitive.
 - printing something on terminal using `echo` 
 - usage: `echo hello world` ; the word `hello world` will be printed on the shell.
 - changing directory using `cd`
 - moving file using `mv` (also used for renaming);
 - copying file using `cp`
 - deleting file using `rm`
 - getting calender using `cal`
    - supplying arguments to cal; `cal 2020` ; this will print calender for year 2020.
    - using `cal 12 2020` ; show 12th month of the 2020 calender.
    - alternative: `cal -m December 2020`
 - getting current date using `date`
 - cleaning our shell using `clear`.
 - getting history of commandu using `history`.
    - running previous command from history using `!`
    - usage: `!20` ; to run command number 20.
    - clear history using `history -c`
- getting help using `man` to show manual page.
    - usage: `man` followed by program name. 
    - example: `man echo`; this show manual page for echo.

    ### Quick note:
    - not all command receive arguments.
    - use `man` command to learn more about the command we want to use.

# Enviroment Variables.
 - we can see enviroment variable using `echo $VARIABLENAME`.
 - examples
    - `echo $PATH`; show env for our default path to for binary execution.
    - `echo $SHELL`; show env for default shell eg:(bash, ksh, sh);

    ### Quick note:
    - `$PATH`; show path for folder containing executable binary.
    - example: 
    ```
        usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
    ``` 
    - let say we have a shell or program called `test.sh` and `test2.sh` inside folder `/home/jun/bin/`.
    - if we want to execute `test.sh` from other places such as from `~/Download` we need to specify the relative path of the file. or we first need to `cd` into the folder containing the file. 
    - if we want to make it executable by simply typing the name `test.sh` instead of the full path `/home/jun/bin/test.sh` from everywhere we can include the folder path into our `$PATH` variable.
    - to include the path we use the command `export`
    - usage: `export $PATH=$PATH:/home/jun/bin`; this will append `/home/jun/bin` to the end of our $PATH variable. so next time we execute something in shell, it will find the executable in the path starting from the leftmost to the end.

    - finding location of the executable file using `which` command.
    - usage : `which echo` ; show the path of the executable.


    ### redirecting using >>/> or <</<
    ### STD INPUT(0), STD OUTPUT(1), STD ERROR (2).
    - usage: `cat something.txt 1>> else.txt 2>> error.txt`; 
    - cat will diplay the content of `something.txt` into std output (1), and from std output we redirect the data to `else.txt`; in case if there is an error, the error will be stream to std error (2), from std error we redirect it to `error.txt`

    - example2: `echo $(0< input.txt)`.
    - this example take input.txt as source into our std input (0), and from std input. then our std input become the argument for echo to print the output to terminal.

    ### Cutting strings into column using `cut`
    - content of `input.txt` is `Hello-world`.
    - example `cut < input.txt -d "-" -f 1 -s`;
    - this example take input.txt as source into our std input, then we cut the string.
    - `-d` stands for delimeter, means where we want to cut. this example is using `-d "-"` followed by dash means we want to cut the words whenever we found dash. 
    - `-f` is for field, means telling which field we want. in this case the first field.
    - so the result will cut `Hello-world` into `Hello` and `world`. then using `-f 1` we only want `Hello`.
    - `-s` is for strict, do not print lines not containing delimiters.


    # T pipes.
    - T pipes or `tee`, is a command that take stream from std input---> write to file ---> std output. 
    - what is does is it acts like a T junction, where one end to write a file, and another end to the std output.
    - example : `cat input.txt | tee middlecopy.txt | cut --d "-" -f 1 -s`


    # xargs. 
    - takes stream from std input, and build it as arguments for another command.
    - example:
        - `address.txt` contains address `www.google.com`
        - to pipe the content of address.txt to `ping` command we can use `xargs`.
        - usage: `cat address.txt | xargs ping`.
        - what it does it that, it run `cat` on `address.txt`, take the result from std input and make it into arguments for `ping`

    - example2:
        - `list.txt` contains arguments (`-al`) for `ls` command.
        - usage: `cat list.txt | xargs ls`.
        - this will convert content of `list.txt` which is `-al` into an arguments and run `ls -al`.

    - example3:
        - `name-addr.txt` contains name:address pair eg: (google:www.google.com).
        - we can use `cut` and pipe it to `ping` commands using xagrs to build the address into argument.
        - usage: `cut < name-addr.txt -d ":" -f 2 -s | xargs ping`.
        - this will run `ping www.google.com`

    ## alias, to make shorter version of shell command.
    - let say writing  `cut < name-addr.txt -d ":" -f 2 -s | xargs ping`, can be a little bit of hassel.
    - we can create name for it by using `alias`. it's like assigning a variable name to it, and just use the name to refer to that command.
    - usage: `alias ourshortname='our command string'`.
    - example:
        - open a terminal and write
        - `alias pingaddr='cut < name-addr.txt -d ":" -f 2 -s | xargs ping'`.
        - then we can run the same command by just typing `pingaddr`.
        - this will only work in current session. after we close our session it no longer available.

    - example2:
        - alternatively we can create a `.bash_aliases` file in our home directory to make it permanent.
        - create `.bash_aliases` using `touch ~/.bash_aliases`.
        - then add our alias command inside it (we can add multiple alias).
        - content will look like this.
        ```txt
        alias pingaddr='cut < name-addr.txt -d ":" -f 2 -s | xargs ping';
        alias ll='ls -al';
        ```
        - make sure there is not spaces at `=`

# Braces expansion. {}
- it is used to generate strings.
- it is will expand value in braces to the outside.
- let say we have `{x,y,z}{a,b,c}`:
    - it will generate set of `xa,xb,xc,ya,yb,yc,za,zb,zc`
- whenever we write braces in shell, it will be interpreted as braces expansion.
- example: `echo {01,02,03,04,05,06,07,08,09}.videos`
- example2: `echo 192.168.1.{0,1,2,3,4,5}`
- example3: `touch testfile_{01,02,03,04,05}.txt`
- example4: `mkdir -p ./years/{jan,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec}_{2019,2020,2021}`
- example5: `mkdir -p ./months/{1..12}_2021`
- we can use it like a range loop in python.
    ```bash
    for x in {1..13}
    do
        echo x
    done
    ```
- we can also use it to generate letters A..Z
    ```bash
    for x in {A..Z}
    do 
        echo $x
    done
    ```