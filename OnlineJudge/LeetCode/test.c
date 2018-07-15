#include <stdio.h>

int main() {
	printf("%d\n", EOF);
	char c;
	c = getchar();
	printf("%d\n", c);
	if (c == -1)
		printf("true\n");
	else
		printf("false\n");
	
	return 0;
}
