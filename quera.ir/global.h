#ifndef _GLOBAL_H
# define _GLOBAL_H

#ifdef CPP
	#include <iostream>
	using namespace std;
#else
	#include <stdlib.h>
#endif

#include <math.h>


#ifdef CPP
static void get_array(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        cin >> arr[i];
}
#endif


static char *read_line(int *len)
{
	int bufsize = 32;
	char *buffer = (char *)malloc(sizeof(char) * bufsize);
	int buflen = 0; 
	char c;
	while (1) {
		c = getchar();
		if (c == '\n' || c == '\0')
			break;
		if (buflen == bufsize) {
			bufsize *= 2;
			buffer = (char *)realloc(buffer, sizeof(char) * bufsize);
		}
		buffer[buflen++] = c;
	}
	buffer = (char *)realloc(buffer, sizeof(char) * buflen);
	buffer[buflen] = '\0';
	*len = buflen;
	return buffer;
}

#endif
