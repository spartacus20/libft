#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

void assert_int(int result_ft, int result_std) {
    if (result_ft == result_std) {
        printf("\033[32mPASSED\033[0m\n");
    } else {
		printf("\033[31mFAILED\033[0m\n");
        printf("Expected: %d\n", result_std);
        printf("Actual: %d\n", result_ft);
	}
}

void assert_string(char *str1, char *str2) {
    if (strcmp(str1, str2) == 0) {
        printf("\033[32mPASSED\033[0m\n"); // Verde si pasa
    } else {
		printf("\033[31mFAILED\033[0m\n"); // Rojo si falla
        printf("Expected: %s\n", str1);
        printf("Actual: %s\n", str2);
	}
}

void assert_ptr(const void *actual, const void *expected) {
    if (actual == expected) {
        printf("\033[32mPASSED\033[0m\n"); // Verde si pasa
    } else {
        printf("\033[31mFAILED\033[0m\n"); // Rojo si falla
        printf("Expected: %p\n", expected);
        printf("Actual: %p\n", actual);
    }
}

void assert_stringN(char *str1, char *str2, size_t n) {
      if (strncmp(str1, str2, n) == 0) {
        printf("\033[32mPASSED\033[0m\n"); // Verde si pasa
    } else {
		printf("\033[31mFAILED\033[0m\n"); // Rojo si falla
        printf("Expected: %s\n", str1);
        printf("Actual: %s\n", str2);
	}
}

void assert_memory(const void *ptr1, const void *ptr2, size_t size) {
    int result = memcmp(ptr1, ptr2, size);
    if (result == 0) {
        printf("\033[32mPASSED\033[0m\n");
    } else {
        printf("\033[31mFAILED\033[0m\n");
        printf("Memory comparison failed.\n");
        printf("Expected memory: ");
        for (size_t i = 0; i < size; i++) {
            printf("%02X ", ((unsigned char *)ptr1)[i]);
        }
        printf("\nActual memory:   ");
        for (size_t i = 0; i < size; i++) {
            printf("%02X ", ((unsigned char *)ptr2)[i]);
        }
        printf("\n");
    }
}

size_t strlcat(char *dst, const char *src, size_t dsize)
{
	const char *odst = dst;
	const char *osrc = src;
	size_t n = dsize;
	size_t dlen;

	/* Find the end of dst and adjust bytes left but don't go past end. */
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	n = dsize - dlen;
    printf("%zu\n", n);

	if (n-- == 0)
		return(dlen + strlen(src));
	while (*src != '\0') {
		if (n != 0) {
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';

	return(dlen + (src - osrc));	/* count does not include NUL */
}

size_t strlcpy(char *dst, const char *src, size_t dsize)
{
	const char *osrc = src;
	size_t nleft = dsize;

	/* Copy as many bytes as will fit. */
	if (nleft != 0) {
		while (--nleft != 0) {
			if ((*dst++ = *src++) == '\0')
				break;
		}
	}

	/* Not enough room in dst, add NUL and traverse rest of src. */
	if (nleft == 0) {
		if (dsize != 0)
			*dst = '\0';		/* NUL-terminate dst */
		while (*src++)
			;
	}

	return(src - osrc - 1);	/* count does not include NUL */
}

char *strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}


void test_isalpha() {
    printf("\n==================FT_ISALPHA=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
    int result_ft1 = ft_isalpha('a');
    int result_std1 = isalpha('a');
    assert_int(result_ft1, result_std1);
    printf("\n");

    // TEST 2
    printf("TEST 2\n\n");
    int result_ft2 = ft_isalpha('1');
    int result_std2 = isalpha('1');
    assert_int(result_ft2, result_std2);
    printf("\n");
}

void test_isdigit() {
    printf("\n==================FT_ISDIGIT=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
    int result_ft1 = ft_isdigit('a');
    int result_std1 = isdigit('a');
    assert_int(result_ft1, result_std1);
    printf("\n");

    // TEST 2
    printf("TEST 2\n\n");
    int result_ft2 = ft_isdigit('1');
    int result_std2 = isdigit('1');
    assert_int(result_ft2, result_std2);
    printf("\n");

    printf("TEST 3\n\n");
    result_ft2 = ft_isdigit('5');
    result_std2 = isdigit('5');
    assert_int(result_ft2, result_std2);
    printf("\n");

    printf("TEST 3\n\n");
    result_ft2 = ft_isdigit('A');
    result_std2 = isdigit('A');
    assert_int(result_ft2, result_std2);
    printf("\n");

}


void test_isalnum() {
    printf("\n==================FT_ISALNUM=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
    int result_ft1 = ft_isalnum('A');
    int result_std1 = isalnum('A');
    assert_int(result_ft1, result_std1);
    printf("\n");

    // TEST 2
    printf("TEST 2\n\n");
    int result_ft2 = ft_isalnum('e');
    int result_std2 = isalnum('e');
    assert_int(result_ft2, result_std2);
    printf("\n");

    // TEST 3
    printf("TEST 3\n\n");
    int result_ft3 = ft_isalnum('$');
    int result_std3 = isalnum('$');
    assert_int(result_ft3, result_std3);
    printf("\n");

    // TEST 4
    printf("TEST 4\n\n");
    int result_ft4 = ft_isalnum('7');
    int result_std4 = isalnum('7');
    assert_int(result_ft4, result_std4);
    printf("\n");

    // TEST 5
    printf("TEST 5\n\n");
    int result_ft5 = ft_isalnum(' ');
    int result_std5 = isalnum(' ');
    assert_int(result_ft5, result_std5);
    printf("\n");

    // TEST 6
    printf("TEST 6\n\n");
    int result_ft6 = ft_isalnum('0');
    int result_std6 = isalnum('0');
    assert_int(result_ft6, result_std6);
    printf("\n");
}


void test_isascii() {
    printf("\n==================FT_ISASCII=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
    int result_ft1 = ft_isascii('a');
    int result_std1 = isascii('a');
    assert_int(result_ft1, result_std1);
    printf("\n");

    // TEST 2
    printf("TEST 2\n\n");
    int result_ft2 = ft_isascii(128); // Carácter no ASCII
    int result_std2 = isascii(128);
    assert_int(result_ft2, result_std2);
    printf("\n");
}

void test_isprint() {
    printf("\n==================FT_ISPRINT=======================\n\n");

    int var1 = 'k';
    int var2 = '8';
    int var3 = '\t';
    int var4 = ' ';

        // TEST 1
    printf("TEST 1\n\n");
    int result_ft1 = ft_isprint(var1);
    int result_std1 = isprint(var1);
    assert_int(result_ft1, result_std1);
    printf("\n");

    // TEST 2
    printf("TEST 2\n\n");
    int result_ft2 = ft_isprint(var2);
    int result_std2 = isprint(var2);
    assert_int(result_ft2, result_std2);
    printf("\n");

    // TEST 3
    printf("TEST 3\n\n");
    int result_ft3 = ft_isprint(var3);
    int result_std3 = isprint(var3);
    assert_int(result_ft3, result_std3);
    printf("\n");

    // TEST 4
    printf("TEST 4\n\n");
    int result_ft4 = ft_isprint(var4);
    int result_std4 = isprint(var4);
    assert_int(result_ft4, result_std4);
    printf("\n");


}

void test_strlen() {
    printf("\n===================FT_STRLEN=======================\n\n");

    // TEST 1: Cadena vacía
    printf("TEST 1\n\n");
    char empty_str[] = "";
    int result_ft1 = ft_strlen(empty_str);
    int result_std1 = strlen(empty_str);
    assert_int(result_ft1, result_std1);
    printf("\n");

    // TEST 2: Cadena con caracteres alfabéticos y numéricos
    printf("TEST 2\n\n");
    char alpha_num_str[] = "Hello123";
    int result_ft2 = ft_strlen(alpha_num_str);
    int result_std2 = strlen(alpha_num_str);
    assert_int(result_ft2, result_std2);
    printf("\n");

    // TEST 3: Cadena con caracteres especiales
    printf("TEST 3\n\n");
    char special_str[] = "!@#$%^";
    int result_ft3 = ft_strlen(special_str);
    int result_std3 = strlen(special_str);
    assert_int(result_ft3, result_std3);
    printf("\n");
}

void test_memset() {
    printf("\n===================FT_MEMSET=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
    char buffer1[10];
    char buffer2[10];
    ft_memset(buffer1, 'A', 10);
    memset(buffer2, 'A', 10);
    int result_ft1 = memcmp(buffer1, buffer2, 10);
    int result_std1 = 0; // Se espera que ambos sean iguales
    assert_int(result_ft1, result_std1);
    printf("\n");

    // TEST 2
    printf("TEST 2\n\n");
    char buffer3[10];
    char buffer4[10];
    ft_memset(buffer3, 0, 10);
    memset(buffer4, 0, 10);
    int result_ft2 = memcmp(buffer3, buffer4, 10);
    int result_std2 = 0; // Se espera que ambos sean iguales
    assert_int(result_ft2, result_std2);
    printf("\n");
}

//TO DO: MODIFY THIS TEST

void test_bzero() {
    printf("\n===================FT_BZERO=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
    char data1[] = "Hello, World!";
    char data1_copy[] = "Hello, World!";
    size_t size1 = sizeof(data1);
    ft_bzero(data1, size1);
    bzero(data1_copy, size1);
    assert_memory(data1, data1_copy, size1);
    printf("\n");

    // TEST 2
    printf("TEST 2\n\n");
    int data2[] = {1, 2, 3, 4, 5};
    int data2_copy[] = {1, 2, 3, 4, 5};
    size_t size2 = sizeof(data2);
    ft_bzero(data2, size2);
    bzero(data2_copy, size2);
    assert_memory(data2, data2_copy, size2);
    printf("\n");

}

void test_memcpy() {
    printf("\n===================FT_MEMCPY=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
    char src1[10] = "123456789";
    char dest1[10];
    char src2[10] = "123456789";
    char dest2[10];
    ft_memcpy(dest1, src1, 10);
    memcpy(dest2, src2, 10);
    int result_ft1 = memcmp(dest1, dest2, 10);
    int result_std1 = 0; // Se espera que ambos sean iguales
    assert_int(result_ft1, result_std1);
    printf("\n");
}

void test_memmove() {
    printf("\n===================FT_MEMMOVE=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
    char data1[] = "Hello, World!";
    char data1_copy[] = "Hello, World!";
    size_t size1 = sizeof(data1);
    ft_memmove(data1 + 7, data1, 7);
    memmove(data1_copy + 7, data1_copy, 7);
    assert_memory(data1, data1_copy, size1);
    assert_stringN(data1, data1_copy, size1);
    printf("\n");

    // TEST 2
    printf("TEST 2\n\n");
    int data2[] = {1, 2, 3, 4, 5};
    int data2_copy[] = {1, 2, 3, 4, 5};
    size_t size2 = sizeof(data2);
    ft_memmove(data2 + 2, data2, 3 * sizeof(int));
    memmove(data2_copy + 2, data2_copy, 3 * sizeof(int));
    assert_memory(data2, data2_copy, size2);
    printf("\n");

    // TEST 3
    printf("TEST 3\n\n");
    char data3[] = "Hello, World!";
    char data3_copy[] = "Hello, World!";
    size_t size3 = sizeof(data3);
    ft_memmove(data3, data3 + 7, 7);
    memmove(data3_copy, data3_copy + 7, 7);
    assert_memory(data3, data3_copy, size3);
    printf("\n");

    // // TEST 4
    printf("TEST 4\n\n");
    int data4[] = {1, 2, 3, 4, 5};
    int data4_copy[] = {1, 2, 3, 4, 5};
    size_t size4 = sizeof(data4);
    ft_memmove(data4, data4 + 2, 3 * sizeof(int));
    memmove(data4_copy, data4_copy + 2, 3 * sizeof(int));
    assert_memory(data4, data4_copy, size4);
    printf("\n");
}

void test_strlcpy() {
    printf("\n===================FT_STRLCPY=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
    char src1[] = "Hello, ";
    char dest1[20];
    size_t result_ft1 = ft_strlcpy(dest1, src1, sizeof(dest1));
    size_t result_std1 = strlcpy(dest1, src1, sizeof(dest1));
    assert_int(result_ft1, result_std1);
    printf("\n");

    // TEST 2
    printf("TEST 2\n\n");
    char src2[] = "world!";
    char dest2[20];
    size_t result_ft2 = ft_strlcpy(dest2, src2, sizeof(dest2));
    size_t result_std2 = strlcpy(dest2, src2, sizeof(dest2));
    assert_int(result_ft2, result_std2);
    printf("\n");
}

void test_strlcat() {
    printf("\n==================FT_STRLCAT=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
    char dest1[15] = "Hello, ";
    const char *src1 = "World!";
    size_t size1 = sizeof(dest1);
    size_t result_ft1 = ft_strlcat(dest1, src1, size1);
    size_t result_std1 = 13;
    assert_int(result_ft1, result_std1);

    printf("Concatenated string: %s\n", dest1);
    printf("\n");

    // TEST 2
    printf("TEST 2\n\n");
    char dest2[10] = "Hello";
    const char *src2 = "World!";
    size_t size2 = sizeof(dest2);
    size_t result_ft2 = ft_strlcat(dest2, src2, size2);
    size_t result_std2 = 11;
    assert_int(result_ft2, result_std2);
    printf("Concatenated string: %s\n", dest2);
    printf("\n");

    // TEST 3
    printf("TEST 3\n\n");
    char dest3[5] = "Hello";
    const char *src3 = "World!";
    size_t size3 = sizeof(dest3);
    size_t result_ft3 = ft_strlcat(dest3, src3, size3);
    size_t result_std3 = strlcat(dest3, src3, size3);
    assert_int(result_ft3, result_std3);
    printf("Concatenated string: %s\n", dest3);
    printf("\n");
}

void test_strchr(){


    printf("\n===================FT_STRCHR=======================\n\n");
    // TEST 1
    printf("TEST 1\n\n");
    const char str1[] = "42 london 123";
    const char ch1 = ' ';
    char *ret1;
    char *ret2;

    ret1 = strchr(str1, ch1);
    ret2 = ft_strchr(str1, ch1);
    assert_string(ret1, ret2);


    printf("\nTEST 2\n\n");
    const char str2[] = "42 london 123";
    const char ch2 = '\0';

    ret1 = strchr(str2, ch2);
    ret2 = ft_strchr(str2, ch2);
    assert_string(ret1, ret2);



    printf("\nTEST 3\n\n");
    const char str3[] = "42\nlondon\n123";
    const char ch3 = '\n';


    ret1 = strchr(str3, ch3);
    ret2 = ft_strchr(str3, ch3);
    assert_string(ret1, ret2);


}

void test_strncmp(){
     printf("\n===================FT_STRNCMP=======================\n\n");
    // TEST 1
    printf("TEST 1\n\n");
    char *str = "42 London";
    char *str2 = "42 London";
    int n = 10;
    assert_int(ft_strncmp(str, str2, n), strncmp(str, str2, n));

    printf("\nTEST 2\n\n");
    str = "42";
    str2 = "42 London";
    n = 10;
    assert_int(ft_strncmp(str, str2, n), strncmp(str, str2, n));


    printf("\nTEST 3\n\n");
    str = "42 London";
    str2 = "42";
    n = 10;
    assert_int(ft_strncmp(str, str2, n), strncmp(str, str2, n));



    printf("\nTEST 4\n\n");
    str = "43";
    str2 = "42";
    n = 10;
    assert_int(ft_strncmp(str, str2, n), strncmp(str, str2, 2));

    printf("\nTEST 5\n\n");
    str = "42";
    str2 = "43";
    n = 10;
    assert_int(ft_strncmp(str, str2, n), strncmp(str, str2, 2));


}


void test_memchr(){


    printf("\n===================FT_MEMCHR=======================\n\n");
    // TEST 1
    printf("TEST 1\n\n");
    const char str1[] = "42 london 123";
    const char ch1 = ' ';
    char *ret1;
    char *ret2;

    ret1 = strchr(str1, ch1);
    ret2 = ft_strchr(str1, ch1);
    assert_string(ret1, ret2);


    printf("\nTEST 2\n\n");
    const char str2[] = "42 london 123";
    const char ch2 = '\0';

    ret1 = strchr(str2, ch2);
    ret2 = ft_strchr(str2, ch2);
    assert_string(ret1, ret2);



    printf("\nTEST 3\n\n");
    const char str3[] = "42\nlondon\n123";
    const char ch3 = '\n';


    ret1 = strchr(str3, ch3);
    ret2 = ft_strchr(str3, ch3);
    assert_string(ret1, ret2);


}



void test_memcmp(){
     printf("\n===================FT_MEMCMP=======================\n\n");
    // TEST 1
    printf("TEST 1\n\n");
    char *str = "42 London";
    char *str2 = "42 London";
    int n = 10;
    assert_int(ft_memcmp(str, str2, n), memcmp(str, str2, n));

    printf("\nTEST 2\n\n");
    str = "42";
    str2 = "42 London";
    n = 10;
    assert_int(ft_memcmp(str, str2, n), memcmp(str, str2, n));


    printf("\nTEST 3\n\n");
    str = "42 London";
    str2 = "42";
    n = 10;
    assert_int(ft_memcmp(str, str2, n), memcmp(str, str2, n));


    printf("\nTEST 4\n\n");
    str = "43";
    str2 = "42";
    n = 10;
    assert_int(ft_memcmp(str, str2, n), memcmp(str, str2, 2));

    printf("\nTEST 5\n\n");
    str = "42";
    str2 = "43";
    n = 10;
    assert_int(ft_memcmp(str, str2, n), memcmp(str, str2, 2));


}


void test_strnstr() {
    printf("\n===================FT_STRNSTR=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
    char *haystack = "Esta es una cadena de ejemplo";
    char *needle = "cadena";
    size_t len = 20;
    assert_ptr(ft_strnstr(haystack, needle, len), strnstr(haystack, needle, len));

    // TEST 2
    printf("\nTEST 2\n\n");
    haystack = "Esta es otra cadena de prueba";
    needle = "otra";
    len = 25;
    assert_ptr(ft_strnstr(haystack, needle, len), strnstr(haystack, needle, len));

    // Agrega más pruebas aquí si es necesario

}


void test_atoi() {
    printf("\n===================FT_ATOI=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
    const char *str1 = "123";
    assert_int(ft_atoi(str1), 123);

    // TEST 2
    printf("\nTEST 2\n\n");
    const char *str2 = "-456";
    assert_int(ft_atoi(str2), -456);

    // TEST 3
    printf("\nTEST 3\n\n");
    const char *str3 = "0";
    assert_int(ft_atoi(str3), 0);

    // TEST 4
    printf("\nTEST 4\n\n");
    const char *str4 = "  789";
    assert_int(ft_atoi(str4), 789);

    // TEST 5
    printf("\nTEST 5\n\n");
    const char *str5 = "abc123";
    assert_int(ft_atoi(str5), 0);
}

void test_strdup() {
    printf("\n===================FT_STRDUP=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
     char *str1 = "Hello, World!";
    char *result1 = ft_strdup(str1);
     char *expected1 = "Hello, World!";
    assert_string(result1, expected1);

    // TEST 2
    printf("\nTEST 2\n\n");
     char *str2 = "";
    char *result2 = ft_strdup(str2);
     char *expected2 = "";
    assert_string(result2, expected2);

    // TEST 3
    printf("\nTEST 3\n\n");
     char *str3 = "12345";
    char *result3 = ft_strdup(str3);
     char *expected3 = "12345";
    assert_string(result3, expected3);


    // Free the allocated memory
    free(result1);
    free(result2);
    free(result3);
}

void test_substr() {
    printf("\n===================FT_SUBSTR=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
    const char *str1 = "Hello, World!";
    char *result1 = ft_substr(str1, 0, 5);
    char *expected1 = "Hello";
    assert_string(result1, expected1);
    free(result1);

    // TEST 2
    printf("\nTEST 2\n\n");
    const char *str2 = "Substring test";
    char *result2 = ft_substr(str2, 10, 4);
    char *expected2 = "test";
    assert_string(result2, expected2);
    free(result2);

    // TEST 3
    printf("\nTEST 3\n\n");
    const char *str3 = "12345";
    char *result3 = ft_substr(str3, 1, 3);
    char *expected3 = "234";
    assert_string(result3, expected3);
    free(result3);

    // TEST 4
    printf("\nTEST 4\n\n");
    const char *str4 = "Sub";
    char *result4 = ft_substr(str4, 0, 10);
    char *expected4 = "Sub";
    assert_string(result4, expected4);
    free(result4);

    // TEST 5
    printf("\nTEST 5\n\n");
    const char *str5 = 0;
    char *result5 = ft_substr(str5, 0, 5);
    // char *expected5 = NULL;
    printf("%s", str5);
    free(result5);
}

void test_strjoin() {
    printf("\n===================FT_STRJOIN=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
    char *s1 = "Hello, ";
    char *s2 = "World!";
    char *result1 = ft_strjoin(s1, s2);
    char *expected1 = "Hello, World!";
    assert_string(result1, expected1);
    free(result1);

    // TEST 2
    printf("\nTEST 2\n\n");
    char *s3 = "Concatenation ";
    char *s4 = "Test";
    char *result2 = ft_strjoin(s3, s4);
    char *expected2 = "Concatenation Test";
    assert_string(result2, expected2);
    free(result2);

    // TEST 3
    printf("\nTEST 3\n\n");
    char *s5 = "";
    char *s6 = "Non-Empty";
    char *result3 = ft_strjoin(s5, s6);
    char *expected3 = "Non-Empty";
    assert_string(result3, expected3);
    free(result3);

    // TEST 4
    printf("\nTEST 4\n\n");
    char *s7 = "Empty";
    char *s8 = "";
    char *result4 = ft_strjoin(s7, s8);
    char *expected4 = "Empty";
    assert_string(result4, expected4);
    free(result4);
}

void test_strtrim() {
    printf("\n===================FT_STRTRIM=======================\n\n");

    // TEST 1
    printf("TEST 1\n\n");
    char *s1 = "   Hello, World!   ";
    char *set1 = " ";
    char *result1 = ft_strtrim(s1, set1);
    char *expected1 = "Hello,World!";
    assert_string(result1, expected1);
    free(result1);

    // TEST 2
    printf("\nTEST 2\n\n");
    char *s2 = "ABCDEF";
    char *set2 = "XYZ";
    char *result2 = ft_strtrim(s2, set2);
    char *expected2 = "ABCDEF";
    assert_string(result2, expected2);
    free(result2);

    // TEST 3
    printf("\nTEST 3\n\n");
    char *s3 = "123!@#";
    char *set3 = "123!@#";
    char *result3 = ft_strtrim(s3, set3);
    char *expected3 = "";
    assert_string(result3, expected3);
    free(result3);

    // TEST 4
    printf("\nTEST 4\n\n");
    char *s4 = "  Testing   ";
    char *set4 = " ";
    char *result4 = ft_strtrim(s4, set4);
    char *expected4 = "Testing";
    assert_string(result4, expected4);
    free(result4);
}



int main() {

	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
    test_strlcpy();
    test_strlcat();
    test_strchr();
    test_strncmp();
    test_memchr();
    test_memcmp();
    test_strnstr();
    test_atoi();
    test_strdup();
    test_substr();
    test_strjoin();
    test_strtrim();

    return 0;
}
