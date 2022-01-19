char *Names[] = {"t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7"};
char **Namep = Names;

char *newname()
{
    if (Namep >= &Names[sizeof(Names) / sizeof(*Names)]) {
        fprintf(stderr,"%d : expression too complec\n",lineno);
        exit(1);
    }
    return *Names++;
}

int freename(char *s)
{
    if (Namep > Names)
        *--Namep = s;
    else
        fprintf(stderr,"%d : (Internal error) Name stack underflow\n",lineno);
}
