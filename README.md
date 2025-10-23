# `francinette`

An easy-to-use testing framework for 42 projects.

Use `francinette` inside a project folder to run it.

Currently has tests for: `libft`, `ft_printf`, `get_next_line`, `minitalk`, and `pipex`.

## :exclamation: Important :exclamation:

If you have little to no experience programming, I highly recommend that you write your own tests first.
For example, for `ft_split`, try to write a main that tests that your code works in most cases.
It is also useful to think about corner cases, like what it should return if the string is `""`, `"   "`, or `"word"`.

**Do NOT rely on `francinette` or other testers.**

### :warning: Write your own tests. It's an essential part of programming. :warning:

## Table of Contents

1. [Purpose](#Purpose)
2. [Install](#Install)
3. [Usage](#Usage)
4. [Update](#Update)
5. [Uninstall](#Uninstall)
6. [FAQ](#FAQ)
7. [Credits](#Credits)

## Purpose

This is designed to function as a kind of `moulinette` that you can execute locally.
That means that by executing `francinette`, it will check `norminette`, your `Makefile`, compile the code, and execute the tests.
You can use it as a local test battery to test your code.

## Install

`francinette` has an automatic installer.

Copy the line below to your console and execute it.
It will automatically download the repo, create the necessary folders and alias, and install a Python virtual environment dedicated to running this tool.

On Linux, it will also download and install the necessary packages for it to run.
It needs admin permission to do that.

```sh
bash -c "$(curl -fsSL https://raw.github.com/Desoroxxx/francinette/main/bin/install.sh)"
```

The `francinette` folder will be in your `$HOME`.

## Usage

If you are at the root of a project, `francinette` should be able to tell which project it is and execute the corresponding tests.

To see all the available options, execute `francinette -h`.

```sh
/libft $> francinette                # Execute the tests for libft

~ $> francinette -h                  # Shows the help message

libft $> francinette memset isalpha memcpy  # Executes only the specified tests
```

The name of the folder is not important.
What is important is that you have a `Makefile` that contains the name of the project (for example, `libft`), or the expected delivery files.
If there is no `Makefile` or delivery files are not present, `francinette` will not know which project to execute.

```sh
~ $> francinette git@repo42.com/intra-uuid-234
```

This command clones the git repository present at `git@repo42.com/intra-uuid-234` into the current folder and executes the corresponding tests.

All the files are copied to the folder `~/francinette/temp/<project>`.
This is where the `norminette` is checked, the code compiled, and the tests executed.
Normally you do not need to access this directory for anything.
But if you run into unexpected problems, this is where the magic happens.

Logs can be found in: `~/francinette/logs`

## Update

Normally,
`francinette` will prompt you when there is a new version, and then you can update it.

You can also force it from `francinette` itself:

```sh
~ $> francinette -u              # Forces francinette to update
```

If the above does not work, you can also execute the command below:

```sh
bash -c "$(curl -fsSL https://raw.github.com/Desoroxxx/francinette/main/bin/update.sh)"
```

## Uninstall

To uninstall `francinette`, delete the `francinette` folder.
It should be located in your `$HOME` directory.

You also need to remove the automatically created aliases. To do that, open your `~/.zshrc` file and delete the lines:

```sh
alias francinette="$HOME"/francinette/tester.sh
```

## FAQ

If you have any questions, you can create an issue or contact me directly.

#### This test that you put up is incorrect!

Please create a new GitHub issue indicating for which exercise the test fails and include a description of what you think is wrong.
You can also try to fix it and create a pull request for that change!

#### What is NULL_CHECK in strict?

This is a way to test if you are protecting your `malloc` calls.
This means that it will make every call to `malloc` fail and return `NULL` instead of a newly allocated pointer.
You need to take this into account when programming so that you don't get segmentation faults.

#### The tester for get_next_line is giving me Timeout errors

This is very common.
My tester will get slower for every `malloc` that you do, so if you do a lot of `malloc`s, it will probably time out.

If it times out while in strict mode,
don't worry; this one is very inefficient.
Don't worry if it gives a Timeout.

## Troubleshooting

#### I've installed `francinette`, but when I try to execute it I get the message: `command not found: francinette`

The install script tries to set an alias for `francinette`.
If for some reason it does not work, you can try to set the aliases yourself by adding:

```sh
alias francinette="$HOME"/francinette/tester.sh
alias ="$HOME"/francinette/tester.sh
```

Now it should work. 
If it does not, don't be afraid to contact me.

## Credits

- [xicodomingues](https://github.com/xicodomingues) for the [francinette](https://github.com/xicodomingues/francinette)
- [Tripouille](https://github.com/Tripouille) for the [libftTester](https://github.com/Tripouille/libftTester), [printfTester](https://github.com/Tripouille/printfTester), and [gnlTester](https://github.com/Tripouille/gnlTester)
- [alelievr](https://github.com/alelievr) for the [libft-unit-test](https://github.com/alelievr/libft-unit-test) and [printf-unit-test](https://github.com/alelievr/printf-unit-test)
- [jtoty](https://github.com/jtoty) for the [Libftest](https://github.com/jtoty/Libftest)
- [0x050f](https://github.com/0x050f) for the [libft-war-machine](https://github.com/jtoty/Libftest)
- [cacharle](https://github.com/cacharle) for the [ft_printf_test](https://github.com/cacharle/ft_printf_test)
- [vfurmane](https://github.com/vfurmane) for the [pipex-tester](https://github.com/vfurmane/pipex-tester)
- [gmarcha](https://github.com/gmarcha) for the [pipexMedic](https://github.com/gmarcha/pipexMedic)
