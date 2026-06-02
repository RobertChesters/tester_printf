# tester_printf
Created to test the functionality of the [ft_printf](https://github.com/RobertChesters/printf_42Berlin.git) function (part of the core curriculum at 42).

## Description ##
I have created two testers to share with peers at 42.
These testers should be used at your own discretion, I cannot guarantee that they catch everything that is required to pass evaluations at 42 and you should also apply your own tests to your ft_printf function.
The testers are quite rudimentary in their asthetics.

-  test_specifiers:  compares the printed output and return values of the libc printf function to the ft_printf fucntion
-  test_write_fail:  tests that the ft_printf function returns the same value (-1) upon interruption of the write function.

The test_write_fail function allowed me to correct my ft_printf function upon 42 first submission failure. It may or may not be required to test failure of the write function in order for your ft_printf to pass moulinette.

## Instructions ##
1.  Clone the repository in to the parent directory of your printf directory
    i.e.  parent_dir/
            printf
            tester_printf
    ```
    git clone https://github.com/RobertChesters/tester_printf.git tester_printf
    ```
3.  Compile with ```make```
4.  Execute with ```./test_specifier``` and/or ```./test_write_fail```

## Feedback ##
I welcome any feedback regarding the functionality and/or aesthetics of these testers and any suggested improvements.
