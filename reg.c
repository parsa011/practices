#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

//bool isMatch(char *s, char *p)
//{
//    while (*p) {
//        int star = *(p + 1) == '*';
//        char expect;
//        if (star)
//            printf("==star found==\n");
//        do {
//            if (*p == '.') {
//                expect = *s;
//            } else
//                expect = *p;
// 			printf("expect : %c\t s : %c\t *p : %c\n", expect, *s, *p);
//            if (*s++ != expect)
//                if (!star)			/* this line means it should have this char */
//                    return false;
//                else {			/* if this was star but not repeated */ 
//                    s--;
//                    break;
//                }
//            else
//                if (star)
//                    return isMatch(s, p + 2);
//        } while (star && *s);
//        p += 1 + star;
//    }
//    return *p == 0 && *s == 0;
//}

bool isMatch(char *s, char *p)
{
}

void main()
{
	printf("%d\n", isMatch("aaaaaaab", "ab*a*c*a*b"));
}
