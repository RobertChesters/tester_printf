#include <stdio.h>
#include <unistd.h>

int ft_printf(const char *format, ...);

// Helpers to close and restore stdout
static int close_stdout_for_test(void)
{
    int backup;
    fflush(stdout);
    backup = dup(STDOUT_FILENO);
    close(STDOUT_FILENO);
    return backup;
}

static void restore_stdout_after_test(int backup)
{
    dup2(backup, STDOUT_FILENO);
    close(backup);
    clearerr(stdout);
}

static void print_result(int libc, int ft_)
{
	if (libc == ft_)
        printf("\033[32m[PASS]\033[0m Both functions correctly return -1 on failure.\n");
    else
        printf("\033[31m[FAIL]\033[0m Functions return different values. libc expected -1 (got %d), ft_ expected -1 (got %d).\n",
               libc, ft_);
}

// Tests
void test_write_failure_c(void)
{
    printf("\ntesting c\n");

    int stdout_backup = close_stdout_for_test();

    int libc = printf("%c\n", 'c');
    int ft_ = ft_printf("%c\n", 'c');

    restore_stdout_after_test(stdout_backup);

    printf("libc returns: %d\n", libc);
    printf("ft_  returns: %d\t", ft_);

    print_result(libc, ft_);
}

void test_write_failure_s(void)
{
    printf("\ntesting s\n");

    int stdout_backup = close_stdout_for_test();

    int libc = printf("%s\n", "string");
    int ft_ = ft_printf("%s\n", "string");

    restore_stdout_after_test(stdout_backup);

    printf("libc returns: %d\n", libc);
    printf("ft_  returns: %d\t", ft_);

    print_result(libc, ft_);
}

void test_write_failure_p(void)
{
    printf("\ntesting p\n");

    int stdout_backup = close_stdout_for_test();

    int libc = printf("%p\n", (void *)"pointer");
    int ft_ = ft_printf("%p\n", (void *)"pointer");

    restore_stdout_after_test(stdout_backup);

    printf("libc returns: %d\n", libc);
    printf("ft_  returns: %d\t", ft_);

    print_result(libc, ft_);
}

void test_write_failure_d(void)
{
    printf("\ntesting d\n");

    int stdout_backup = close_stdout_for_test();

    int libc = printf("%d\n", 42);
    int ft_ = ft_printf("%d\n", 42);

    restore_stdout_after_test(stdout_backup);

    printf("libc returns: %d\n", libc);
    printf("ft_  returns: %d\t", ft_);

    print_result(libc, ft_);
}

void test_write_failure_i(void)
{
    printf("\ntesting i\n");

    int stdout_backup = close_stdout_for_test();

    int libc = printf("%i\n", 42);
    int ft_ = ft_printf("%i\n", 42);

    restore_stdout_after_test(stdout_backup);

    printf("libc returns: %d\n", libc);
    printf("ft_  returns: %d\t", ft_);

    print_result(libc, ft_);
}

void test_write_failure_u(void)
{
    printf("\ntesting u\n");

    int stdout_backup = close_stdout_for_test();

    int libc = printf("%u\n", 42);
    int ft_ = ft_printf("%u\n", 42);

    restore_stdout_after_test(stdout_backup);

    printf("libc returns: %d\n", libc);
    printf("ft_  returns: %d\t", ft_);

    print_result(libc, ft_);
}

void test_write_failure_x(void)
{
    printf("\ntesting x\n");

    int stdout_backup = close_stdout_for_test();

    int libc = printf("%x\n", 42);
    int ft_ = ft_printf("%x\n", 42);

    restore_stdout_after_test(stdout_backup);

    printf("libc returns: %d\n", libc);
    printf("ft_  returns: %d\t", ft_);

    print_result(libc, ft_);
}

void test_write_failure_X(void)
{
    printf("\ntesting X\n");

    int stdout_backup = close_stdout_for_test();

    int libc = printf("%X\n", 42);
    int ft_ = ft_printf("%X\n", 42);

    restore_stdout_after_test(stdout_backup);

    printf("libc returns: %d\n", libc);
    printf("ft_  returns: %d\t", ft_);

    print_result(libc, ft_);
}

void test_write_failure_percent(void)
{
    printf("\ntesting percent\n");

    int stdout_backup = close_stdout_for_test();

    int libc = printf("%%\n");
    int ft_ = ft_printf("%%\n");

    restore_stdout_after_test(stdout_backup);

    printf("libc returns: %d\n", libc);
    printf("ft_  returns: %d\t", ft_);

    print_result(libc, ft_);
}

void test_write_failure_multi(void)
{
    printf("\ntesting percent\n");

    printf("libc output before write fail:	%c\n", 'c');
    ft_printf("ft_ output before write fail:	%c\n", 'c');

	int stdout_backup = close_stdout_for_test();


	int libc = printf("%%\n");
    int ft_ = ft_printf("%%\n");

    restore_stdout_after_test(stdout_backup);

    printf("libc returns: %d\n", libc);
    printf("ft_  returns: %d\t", ft_);

    print_result(libc, ft_);
}

int main(void)
{
	printf("Testing libc printf (libc) output versus ft_printf (ft_) output after write function failure.\n");
	printf("Write function failure caused by temporarily closing the file descriptor (fd) preventing writing of data.\n");
    test_write_failure_c();
    test_write_failure_s();
    test_write_failure_p();
    test_write_failure_d();
    test_write_failure_i();
    test_write_failure_u();
    test_write_failure_x();
    test_write_failure_X();
    test_write_failure_percent();
	test_write_failure_multi();
    return 0;
}