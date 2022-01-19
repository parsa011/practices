
#define EOI			0
#define SEMI		1
#define	PLUS		2
#define	TIMES		3
#define	LP			4
#define RP			5
#define	NUM_OR_ID	6
#define WHITESPACE	7

extern char buf[];

int next();
int match();
void advance();

extern char *text;
extern int lineno;
extern int length;

void get_line();
void write_prompt();

void statements();
void expression();
void expr_prime();
void term();
void term_prime();
void factor();
void type_decl();
void get_type();
void get_name();
