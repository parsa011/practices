#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool is_match(char *s, char *p)
{
	char last_matched = 0;
	while (*p) {
		int star = *(p + 1) == '*';
		char expect;

		do {
			expect = *p == '.' ? *s : *p;

			if (*s != expect && last_matched == *s) {
				p++;
				continue;
			}

			if (*s++ != expect) {
				if (!star)
					return false;
				else {
					s--;
					break;
				}
			} else {
				last_matched = expect;
			}
		} while (star && *s);
		p += 1 + star;
	}
	return *p == 0 && *s == 0;
}

int main()
{
	printf("%d\n", is_match("aaa", "a*a"));
	return 0;
}
