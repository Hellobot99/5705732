#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {

	char c;

	while (scanf("%c", &c) != EOF) {
		printf("%c", c);
	}

	return 0;
}