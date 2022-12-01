extern int old_var __attribute__ ((deprecated));
extern int old_var;
int new_fn () { return old_var; }

int main()
{
	return 0;
}
