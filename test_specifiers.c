#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include "printf/ft_printf.h"

void    test_result(int compare)
{
    if (compare == 0)
        printf("\033[32m[PASS]\033[0m \n\n");
    else
    printf("\033[31m[FAIL]\033[0m return values differ.\n\n");
}

void	test_empty(void)
{
    int libc;
    int ft_;
	int compare;

    libc = printf("");
	printf("		libc returns	%d\n", libc);
    ft_ = ft_printf("");
	printf("		ft_  returns	%d\t", ft_);
    compare = libc - ft_;
    test_result (compare);
}

void	test_null(void)
{
    int libc;
    int ft_;
	int compare;

    libc = printf(NULL);
	printf("		libc returns	%d\n", libc);
    ft_ = ft_printf(NULL);
	printf("		ft_  returns	%d\t", ft_);
    compare = libc - ft_;
    test_result (compare);
}

void	test_just_str(void)
{
    int libc;
    int ft_;
	int compare;

    libc = printf("Hello 42\t");
	printf("libc returns	%d\n", libc);
    ft_ = ft_printf("Hello 42\t");
	printf("ft_  returns	%d\t", ft_);
    compare = libc - ft_;
    test_result (compare);
}

void	test_char(char c)
{
    int libc;
    int ft_;
	int compare;

    libc = printf("%c\t\t", c);
	printf("libc returns	%d\n", libc);
    ft_ = ft_printf("%c\t\t", c);
	printf("ft_  returns	%d\t", ft_);
    compare = libc - ft_;
    test_result(compare);
}

void	test_str(char *c)
{
    int libc;
    int ft_;
	int compare;

    libc = printf("%s\t\t", c);
	printf("libc returns	%d\n", libc);
    ft_ = ft_printf("%s\t\t", c);
	printf("ft_  returns	%d\t", ft_);
    compare = libc - ft_;
    test_result(compare);
}

void	test_ptr(void *c)
{
    int libc;
    int ft_;
	int compare;

    libc = printf("%p\t", c);
	printf("libc returns	%d\n", libc);
    ft_ = ft_printf("%p\t", c);
	printf("ft_  returns	%d\t", ft_);
    compare = libc - ft_;
    test_result(compare);
}

void	test_d(int c)
{
    int libc;
    int ft_;
	int compare;

    libc = printf("%d\t\t", c);
	printf("libc returns	%d\n", libc);
    ft_ = ft_printf("%d\t\t", c);
	printf("ft_  returns	%d\t", ft_);
    compare = libc - ft_;
    test_result(compare);
}

void	test_i(int c)
{
    int libc;
    int ft_;
	int compare;

    libc = printf("%i\t\t", c);
	printf("libc returns	%d\n", libc);
    ft_ = ft_printf("%i\t\t", c);
	printf("ft_  returns	%d\t", ft_);
    compare = libc - ft_;
    test_result(compare);
}

void	test_u(unsigned int c)
{
    int libc;
    int ft_;
	int compare;

    libc = printf("%u\t\t", c);
	printf("libc returns	%d\n", libc);
    ft_ = ft_printf("%u\t\t", c);
	printf("ft_  returns	%d\t", ft_);
    compare = libc - ft_;
    test_result(compare);
}

void	test_x(unsigned int c)
{
    int libc;
    int ft_;
	int compare;

    libc = printf("%x\t\t", c);
	printf("libc returns	%d\n", libc);
    ft_ = ft_printf("%x\t\t", c);
	printf("ft_  returns	%d\t", ft_);
    compare = libc - ft_;
    test_result(compare);
}

void	test_X(unsigned int c)
{
    int libc;
    int ft_;
	int compare;

    libc = printf("%X\t\t", c);
	printf("libc returns	%d\n", libc);
    ft_ = ft_printf("%X\t\t", c);
	printf("ft_  returns	%d\t", ft_);
    compare = libc - ft_;
    test_result(compare);
}

void	test_percent(void)
{
    int libc;
    int ft_;
	int compare;

    libc = printf("%%%%");
	printf("libc returns	%d\n", libc);
    ft_ = ft_printf("%%%%");
	printf("ft_  returns	%d\t", ft_);
    compare = libc - ft_;
    test_result(compare);
}

void	test_mix(void)
{
    int libc;
    int ft_;
	int compare;

    libc = printf("%c\n%s\n%p\n%d\n%i\n%x\n%X\n%%\n\t", 'c', "string", (void *)"pointer", 42, 42, 42, 42);
	printf("libc returns	%d\n\n", libc);
	ft_ = libc = printf("%c\n%s\n%p\n%d\n%i\n%x\n%X\n%%\n\t", 'c', "string", (void *)"pointer", 42, 42, 42, 42);
    printf("ft_ returns	%d\t", ft_);
    compare = libc - ft_;
    test_result(compare);
}

int main(void)
{
	system("clear");
	printf("Testing each specifier works by comparing libc printf output and return values against ft_printf output and return values.\n\n");
	printf("First column = printed output.	Second column = return values.	Third column = test result.\n\n");
   	printf("OUTPUT			RETURN VALUES\n\n");
	printf("\033[33;1mTesting empty ...]\033[0m\n\n");
	test_empty();

	printf("\033[33;1mTesting null ...]\033[0m\n\n");
	test_null();

	printf("\033[33;1mTesting just a const str ...]\033[0m\n\n");
	test_just_str();

	printf("\033[33;1mTesting %%c ...]\033[0m\n\n");
    test_char('a');
    test_char(0);
	test_char(70);
	test_char(-35);

	printf("\033[33;1mTesting %%s ...]\033[0m\n\n");
    test_str(NULL);
    test_str("marvin");
    test_str("");

	printf("\033[33;1mTesting %%p ...]\033[0m\n\n");
    test_ptr(NULL);
    test_ptr("c");
    test_ptr("");
    test_ptr("hello");
	test_ptr((void *)50);
	test_ptr((void *)-50);
	test_ptr((void *)16);
	test_ptr((void *)123456789);
	test_ptr((void *)-123456789);


	printf("\033[33;1mTesting %%d ...]\033[0m\n\n");
    test_d(42);
	test_d(0);
	test_d(-42);
	test_d(INT32_MAX);
	test_d(INT32_MIN);
	test_d('a');
	test_d('t');

	printf("\033[33;1mTesting %%i ...]\033[0m\n\n");
    test_i(42);
	test_i(0);
	test_i(-42);
	test_i(INT32_MAX);
	test_i(INT32_MIN);
	test_i('a');
	test_i('t');

	printf("\033[33;1mTesting %%u ...]\033[0m\n\n");
    test_u(42);
	test_u(0);
	test_u(-42);
	test_u(UINT32_MAX);
	test_u(INT32_MIN);
	test_u('a');
	test_u('t');

	printf("\033[33;1mTesting %%x ...]\033[0m\n\n");
	test_x(42);
	test_x(0);
	test_x(-42);
	test_x(INT32_MAX);
	test_x(INT32_MIN);
	test_x(UINT32_MAX);
	test_x('a');
	test_x('t');

	printf("\033[33;1mTesting %%X ...]\033[0m\n\n");
    test_X(42);
	test_X(0);
	test_X(-42);
	test_X(INT32_MAX);
	test_X(INT32_MIN);
	test_X(UINT32_MAX);
	test_X('a');
	test_X('t');

	printf("\033[33;1mTesting %% ...]\033[0m\n\n");
    test_percent();

	printf("\033[33;1mTesting mix ...]\033[0m\n\n");
	test_mix();

    return (0);
}