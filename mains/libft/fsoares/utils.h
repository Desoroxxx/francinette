/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoares- <fsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:40:02 by fsoares-          #+#    #+#             */
/*   Updated: 2022/01/19 03:03:12 by fsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <signal.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <stdbool.h>

#include "libft.h"
#include "color.h"

#define MEM_SIZE 0x100
#define REPETITIONS 1000

char function[1000];
char signature[1000];
int g_offset;
char escaped[1000];

#define create_test_ctype(fn)                                                \
	int test_##fn(void)                                                      \
	{                                                                        \
		int c;                                                               \
		int res = 1;                                                         \
		for (c = 0; c <= 0xff && res; c++)                                   \
		{                                                                    \
			if (!fn(c) != !ft_##fn(c))                                       \
			{                                                                \
				printf(CYN "fn_" #fn "(%i: %s)" NC ": std: %i, yours: %i\n", \
					   c, escape_chr(c), fn(c), ft_##fn(c));                 \
				res = 0;                                                     \
			}                                                                \
		}                                                                    \
		if (!fn(EOF) != !ft_##fn(EOF))                                       \
		{                                                                    \
			printf(CYN "fn_" #fn "(EOF)" NC ": std: %i, yours: %i\n",        \
				   fn(EOF), ft_##fn(EOF));                                   \
			res = 0;                                                         \
		}                                                                    \
		return res;                                                          \
	}

#define create_test_val(fn)                                                  \
	int test_##fn(void)                                                      \
	{                                                                        \
		int c;                                                               \
		int res = 1;                                                         \
		for (c = 0; c <= 0xff && res; c++)                                   \
		{                                                                    \
			if (fn(c) != ft_##fn(c))                                         \
			{                                                                \
				printf(CYN "ft_" #fn "(%i: %s)" NC ": std: %i, yours: %i\n", \
					   c, escape_chr(c), fn(c), ft_##fn(c));                 \
				res = 0;                                                     \
			}                                                                \
		}                                                                    \
		if (fn(EOF) != ft_##fn(EOF))                                         \
		{                                                                    \
			printf(CYN "ft_" #fn "(EOF)" NC ": std: %i, yours: %i\n",        \
				   fn(EOF), ft_##fn(EOF));                                   \
			res = 0;                                                         \
		}                                                                    \
		return res;                                                          \
	}

#define test(fn)                                        \
	strcpy(function, #fn);                              \
	if (!test_##fn())                                   \
		printf("%-16s: " LRED "KO" NC "\n", "ft_" #fn); \
	else                                                \
		printf("%-16s: " LGRN "OK" NC "\n", "ft_" #fn);

#define no_test(fn) \
	printf("ft_%-13s: " YEL "No test yet\n" NC, #fn)

#ifdef STRICT_MEM
#define null_check(fn_call, result)                                         \
	reset_malloc_mock();                                                    \
	fn_call;                                                                \
	int malloc_calls = reset_malloc_mock();                                 \
	for (int i = 0; i < malloc_calls; i++)                                  \
	{                                                                       \
		sprintf(signature + g_offset, NC " NULL check for %ith malloc", i); \
		malloc_set_null(i);                                                 \
		char *res = fn_call;                                                \
		result = check_leaks(res) && result;                                \
		if (res != NULL)                                                    \
			result = error("Should return NULL\n");                         \
	}
#else
#define null_check(fn_call, result)
#endif

void handle_signals();

void print_mem(void *ptr, int size);
void print_mem_full(void *ptr, int size);

char *rand_bytes(char *dest, int len);
char *escape_str(char *src);
char *escape_chr(char ch);
void reset(void *m1, void *m2, int size);
void reset_with(void *m1, void *m2, char *content, int size);

int set_sign(const char *format, ...);
int error(const char *format, ...);

int same_ptr(void *res, void *res_std);
int same_mem(void *expected, void *result, int size);
int same_value(int res, int res_std);
int same_sign(int res, int res_std);
int same_offset(void *start, void *start_std, void *res, void *res_std);
int same_return(void *res, void *dest);
int same_size(void *ptr, void *ptr_std);
int same_string(char *expected, char *actual);
int check_mem_size(void *ptr, size_t expected_size);

int reset_malloc_mock();
size_t get_malloc_size(void *ptr);
void malloc_set_result(void *res);
void malloc_set_null(int nth);
int check_leaks(void *ptr);

#ifndef HAVE_STRLCAT
size_t strlcat(char *dst, const char *src, size_t size);
#endif
#ifndef HAVE_STRLCPY
size_t strlcpy(char *dst, const char *src, size_t size);
#endif
#ifndef HAVE_STRNSTR
char *strnstr(const char *haystack, const char *needle, size_t len);
#endif

#endif
