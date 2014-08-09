#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>
#include "flextypes.h"
#include "flexerror.h"
#include "flex.h"
#include "errors.h"
#include "version.h"
#include "ffi2code.h"


char	*gASTnodeSTRINGS[ASTnode_MAX]	= {
						[P_LANGUAGE]		= "P_LANGUAGE",		/*	0	*/
						[P_FFSTMT]		= "P_FFSTMT",		/*	1	*/
						[P_FIRSTSETSTMT]	= "P_FIRSTSETSTMT",	/*	2	*/
						[P_FOLLOWSETSTMT]	= "P_FOLLOWSETSTMT",	/*	3	*/
						[P_FIRSTSETOP]		= "P_FIRSTSETOP",	/*	4	*/
						[P_FIRSTSET]		= "P_FIRSTSET",		/*	5	*/
						[P_FOLLOWSETOP]		= "P_FOLLOWSETOP",	/*	6	*/
						[P_FOLLOWSET]		= "P_FOLLOWSET",	/*	7	*/
						[T_IDENTIFIER]		= "T_IDENTIFIER",	/*	8	*/
						[T_TOKEN]		= "T_TOKEN",		/*	9	*/
						[T_PRODUCTION]		= "T_PRODUCTION",	/*	10	*/
						[T_FIRSTSET]		= "T_FIRSTSET",		/*	11	*/
						[T_FOLLOWSET]		= "T_FOLLOWSET",	/*	12	*/
						[ASTnode_TREERESIDENT]	= "ASTnode_TREERESIDENT",/*	13	*/
						[T_COLON]		= "T_COLON",		/*	14	*/
						[T_EQUALS]		= "T_EQUALS",		/*	15	*/
						[T_COMMA]		= "T_COMMA",		/*	16	*/
						[T_LBRACE]		= "T_LBRACE",		/*	17	*/
						[T_RBRACE]		= "T_RBRACE",		/*	18	*/
						[T_LPAREN]		= "T_LPAREN",		/*	19	*/
						[T_RPAREN]		= "T_RPAREN",		/*	20	*/
						[T_NEWLINE]		= "T_NEWLINE",		/*	21	*/
						[T_EPSILON]		= "T_EPSILON",		/*	22	*/
						[X_SEQ]			= "X_SEQ",		/*	23	*/
					};

char	*gASTnodeDESCRIPTIONS[ASTnode_MAX]	= {
						[P_LANGUAGE]		= "FFI language production",
						[P_FFSTMT]		= "statement production",
						[P_FIRSTSETSTMT]	= "firstset statement production",
						[P_FOLLOWSETSTMT]	= "followset statement production ",
						[P_FIRSTSETOP]		= "firstset() operator production",
						[P_FIRSTSET]		= "firstset production",
						[P_FOLLOWSETOP]		= "followset() operator production",
						[P_FOLLOWSET]		= "followset production",

						[T_IDENTIFIER]		= "identifier",
						[T_TOKEN]		= "\"token\"",
						[T_PRODUCTION]		= "\"production\"",
						[T_FIRSTSET]		= "\"firstset\"",
						[T_FOLLOWSET]		= "\"followset\"",
						[T_COLON]		= "\":\"",
						[T_EQUALS]		= "\"=\"",
						[T_COMMA]		= "\",\"",
						[T_LBRACE]		= "\"{\"",
						[T_RBRACE]		= "\"}\"",
						[T_LPAREN]		= "\"(\"",
						[T_RPAREN]		= "\")\""
					};

/*
 *	First and follow sets for grammar productions and tokens
 */
int	gFIRSTS[ASTnode_MAX]	= {
					[P_LANGUAGE]		= ((1 << T_TOKEN) | (1 << T_PRODUCTION)),
					[P_FFSTMT]		= ((1 << T_TOKEN) | (1 << T_PRODUCTION)),
					[P_FIRSTSETSTMT]	= ((1 << T_TOKEN) | (1 << T_PRODUCTION)),
					[P_FOLLOWSETSTMT]	= ((1 << T_TOKEN) | (1 << T_PRODUCTION)),
					[P_FIRSTSETOP]		= ( 1 << T_FIRSTSET),
					[P_FIRSTSET]		= ((1 << T_IDENTIFIER) | (1 << T_FIRSTSET)),
					[P_FOLLOWSETOP]		= ( 1 << T_FOLLOWSET),
					[P_FOLLOWSET]		= ((1 << T_IDENTIFIER) | (1 << T_FIRSTSET) | (1 << T_FOLLOWSET))
				};

int	gFOLLOWS[ASTnode_MAX]	= {
					[P_LANGUAGE]		= ( 1 << T_EPSILON),
					[P_FFSTMT]		= ((1 << T_TOKEN) | (1 << T_PRODUCTION)),
					[P_FIRSTSETSTMT]	= ((1 << T_TOKEN) | (1 << T_PRODUCTION)),
					[P_FOLLOWSETSTMT]	= ((1 << T_TOKEN) | (1 << T_PRODUCTION)),
					[P_FIRSTSETOP]		= ((1 << T_COMMA) | (1 << T_RBRACE)),
					[P_FIRSTSET]		= ( 1 << T_RBRACE),
					[P_FOLLOWSETOP]		= ((1 << T_COMMA) | (1 << T_RBRACE)),
					[P_FOLLOWSET]		= ( 1 << T_RBRACE),
					[T_IDENTIFIER]		= ((1 << T_COLON) | (1 << T_RPAREN) | (1 << T_COMMA) | (1 << T_RBRACE)),
					[T_TOKEN]		= ( 1 << T_IDENTIFIER),
					[T_PRODUCTION]		= ( 1 << T_IDENTIFIER),
					[T_FIRSTSET]		= ((1 << T_EQUALS) | (1 << T_LPAREN)),
					[T_FOLLOWSET]		= ((1 << T_EQUALS) | (1 << T_LPAREN)),
					[T_COLON]		= ((1 << T_FIRSTSET) | (1 << T_FOLLOWSET)),
					[T_EQUALS]		= ( 1 << T_LBRACE),
					[T_COMMA]		= ((1 << T_IDENTIFIER) | (1 << T_FIRSTSET) | (1 << T_FOLLOWSET)),
					[T_LBRACE]		= ((1 << T_IDENTIFIER) | (1 << T_FIRSTSET) | (1 << T_FOLLOWSET)),
					[T_RBRACE]		= ((1 << T_TOKEN) | (1 << T_PRODUCTION)),
					[T_LPAREN]		= ( 1 << T_IDENTIFIER),
					[T_RPAREN]		= ((1 << T_COMMA) | (1 << T_RBRACE)),
				};

Pair	gTOKENSTRS[ASTnode_MAX] = {
					[T_TOKEN]		= {T_TOKEN,		"token"},
					[T_PRODUCTION]		= {T_PRODUCTION,	"production"},
					[T_COLON]		= {T_COLON,		":"},
					[T_FIRSTSET]		= {T_FIRSTSET,		"firstset"},
					[T_EQUALS]		= {T_EQUALS,		"="},
					[T_LBRACE]		= {T_LBRACE,		"{"},
					[T_RBRACE]		= {T_RBRACE,		"}"},
					[T_FOLLOWSET]		= {T_FOLLOWSET,		"followset"},
					[T_LPAREN]		= {T_LPAREN,		"("},
					[T_RPAREN]		= {T_RPAREN,		")"},
					[T_COMMA]		= {T_COMMA,		","},
					[T_NEWLINE]		= {T_NEWLINE,		"\n"},
				};

/*							*/
/*	Separated, but kept (NOTE: 'x', '.' and 	*/
/*	'"' aren't sticky):				*/
/*							*/
const char	kFFI_STICKIES[]		= "-(){},:\n";

/*							*/
/*			Thrown away:			*/	
/*							*/
const char	kFFI_SEPCHARS[]		= " \t\r";


/*							*/
/*			Error strings.			*/
/*							*/
const char	Effi2codefatal[]	= "ffi2code---fatal error: ";
const char	Effi2codeerror[]	= "ffi2code---error: ";


ASTnode*	parse_language(FFIstate *F);
ASTnode*	parse_ffstmt(FFIstate *F);
ASTnode*	parse_xsetstmt(FFIstate *F, ASTnodeType x);
ASTnode*	parse_firstsetop(FFIstate *F);
ASTnode*	parse_firstset(FFIstate *F);
ASTnode*	parse_followsetop(FFIstate *F);
ASTnode*	parse_followset(FFIstate *F);

char*		ast_print(FFIstate *F, ASTnode *p);
int		ast_treesz(FFIstate *F, ASTnode *p);
int		ast_printwalk(FFIstate *F, ASTnode *p, char *buf, int buflen);
void		ast_colortree(FFIstate *F, ASTnode *p, int color);
int		dotfmt(FFIstate *F, char *buf, int buflen, ASTnode *p);

void		replace_followsets(ASTnode *root, ASTnode *node, FFIstate *F);

void		fatal(FFIstate *F, const char *msg);
void		error(FFIstate *F, const char *msg);
void		usage(FFIstate *F);


int
main(int argc, char *argv[])
{
	FFIstate	*F;
	ASTnode		*astroot;
	char		*buf, *filename;
	int		fd, curline = 1, curcol = 1;


	F = (FFIstate *)calloc(1, sizeof(FFIstate));
	if (F == NULL)
	{
		fatal(NULL, Emalloc);
	}

	F->Fe = (FlexErrState *)calloc(1, sizeof(FlexErrState));
	if (F->Fe == NULL)
	{
		fatal(NULL, Emalloc);
	}

	F->Fm = (FlexMstate *)calloc(1, sizeof(FlexMstate));
	if (F->Fm == NULL)
	{
		fatal(NULL, Emalloc);
	}
	F->Fm->debug = 0;

	F->Fi = (FlexIstream *)calloc(1, sizeof(FlexIstream));
	if (F->Fi == NULL)
	{
		fatal(NULL, Emalloc);
		return -1;
	}


	/*
	 *	We choose not to allocate error/info buffers for libflex.
	 */
	F->Fperr = NULL;
	F->Fpinfo = NULL;


	if (argc != 2)
	{
		usage(F);
		exit(EXIT_FAILURE);
	}
	//TODO: use getopt
	filename = argv[1];
	
	//TODO: use getopt to determine verbosity
	F->verbose = 0;



	buf = (char *) flexcalloc(F->Fe, F->Fm, F->Fperr, kFFI_MAXBUFLEN+1, sizeof(char), "ffi2code.c:main/buf");
	if (buf == NULL)
	{
		fatal(F, Emalloc);
		return -1;
	}

	fd = flexopen(F->Fe, F->Fm, F->Fperr, filename, FLEX_OREAD);
	if (fd < 0)
	{
		flexprint(F->Fe, F->Fm, F->Fperr, "%s \"%s\"...\n\n", Eopen, filename);
		return -1;
	}

	flexstreamclear(F->Fe, F->Fm, F->Fperr, F->Fi);
	while (flexfgets(F->Fe, F->Fm, F->Fperr, buf, kFFI_MAXBUFLEN, fd) != NULL)
	{
		flexstreammunch(F->Fe, F->Fm, F->Fperr, F->Fi, kFFI_SEPCHARS, kFFI_STICKIES, buf, &curline, &curcol);
	}

	//flexstreamchk(F->Fe, F->Fm, F->Fperr, F->Fi, kFFI_MAXERRORTOKS, kFFI_STREAMCHKWIDTH);
	flexstreamscan(F->Fe, F->Fm, F->Fperr, F->Fi);
	//flexstreamchk(F->Fe, F->Fm, F->Fperr, F->Fi, 0, 0);
	

	astroot = parse_language(F);
replace_followsets(astroot, astroot, F);

	fprintf(stdout, "%s\n", ast_print(F, astroot));




	exit(EXIT_SUCCESS);
}

/*
language	::= {ffstmt} .

ffstmt		::= firstsetstmt | followsetstmt .
firstsetstmt	::= ("token" | "production") identifier ':' "firstset" '=' '{' firstset '}' .
followsetstmt	::= ("token" | "production") identifier ':' "followset" '=' '{' followset '}' .

firstsetop	::= "firstset" '(' identifier ')' .
firstset	::= (identifier | firstsetop) {',' (identifier | firstsetop)} .

followsetop	::= "followset" '(' identifier ')' .
followset	::= (identifier | firstsetop | followsetop) {',' (identifier | firstsetop | followsetop)} .
*/


void
removetoken(FFIstate *F)
{
	Input	*I = &F->Fi->istream;
	Datum	*tmphd = I->head;



	I->head = I->head->prev;
	
	/*										*/
	/*	NOTE: If there is only one item on stream, and we remove head, then	*/
	/*	the masthead and tail will still be pointing to it, even though head	*/
	/*	will now be NULL. That is OK, since masthead and tail are kept around	*/
	/*	for future runs through the list (e.g., when scanning), and head is	*/
	/*	used in essence as a temporary per-run.					*/
	/*										*/
	
	/*	If the last token on, head will now be null	*/
	if (I->head != NULL)
	{
		I->head->next = NULL;
	}

	flexfree(F->Fe, F->Fm, F->Fperr, tmphd->data, "ffi2code.c:removetoken/tmphd->data");
	flexfree(F->Fe, F->Fm, F->Fperr, tmphd, "ffi2code.c:removetoken/tmphd");


	return;
}


Pair*
nexttoken(FFIstate *F)
{
	Pair	*ret;
	Input	*I = &F->Fi->istream;
	Datum	*current = I->head;



//TODO: dealloc at all call sites
	/*	Caller is responsible for dealloc'ing both struct and embedded string	*/
	ret = (Pair*)calloc(1, sizeof(Pair));
	if (ret == NULL)
	{
		fatal(F, Emalloc);
	}


	if (current == NULL)
	{
		ret->type = T_EPSILON;

		return ret;
	}

	if (current->data == NULL)
	{
		fatal(F, Esanity);
		exit(EXIT_FAILURE);
	}


	/*	Skip over comments. TODO: this could also have been integrated into the parse flow, instead of here, which is essentially lexing	*/
	if (	!strcmp(I->head->data, "-") 			&&
		I->head->prev != NULL				&&
		((Datum*)I->head->prev)->data != NULL		&&
		!strcmp(((Datum*)I->head->prev)->data, "-")
	)
	{
		while (I->head != NULL && strncmp(I->head->data, "\n", 1))
		{
			fprintf(stderr, "[%s] is in comment\n", I->head->data);
			removetoken(F);

			//TODO: Are we not advancing head?...
		}


		/*	Remove the newline terminating the comment	*/
		while (I->head != NULL && !strncmp(I->head->data, "\n", 1))
		{
			removetoken(F);
		}

		/*	recurse		*/
		return nexttoken(F);
	}


	for (int i = 0; i < ASTnode_MAX; i++)
	{
		if (gTOKENSTRS[i].string != NULL && !strcmp(current->data, gTOKENSTRS[i].string))
		{
			return &gTOKENSTRS[i];
		}
	}

	ret->type = T_IDENTIFIER;
	ret->string = current->data;


	return ret;
}

bool
infirsts(ASTnodeType production, ASTnodeType token)
{
	return (gFIRSTS[production] & (1 << token));
}

void
syntaxerror(FFIstate *F, ASTnodeType production, ASTnodeType prodtoken)
{
	int	seen = 0;

	
	/*
	 *	If prodtoken is ASTnode_MAX, check syntax of next token relative to FIRST() set. Otherwise, check syntax relative to prodtoken
	 */
	flexprint(F->Fe, F->Fm, F->Fperr, "\n\tSyntax error while parsing %s---expected", gASTnodeDESCRIPTIONS[production]);
	if (prodtoken == ASTnode_MAX)
	{
		flexprint(F->Fe, F->Fm, F->Fperr, " one of:\n\n\t\t");
		for (int i = 0; i < ASTnode_MAX; i++)
		{
			if (infirsts(production, i))
			{
				if (seen > 0)
				{
					flexprint(F->Fe, F->Fm, F->Fperr, ", ");
				}

				flexprint(F->Fe, F->Fm, F->Fperr, "%s", gASTnodeDESCRIPTIONS[i]);
				seen++;
			}
		}
	}
	else
	{
		flexprint(F->Fe, F->Fm, F->Fperr, ":\n\n\t\t");
		flexprint(F->Fe, F->Fm, F->Fperr, "%s", gASTnodeDESCRIPTIONS[prodtoken]);
	}


	flexprint(F->Fe, F->Fm, F->Fperr, ".\n\n\tInstead, saw:\n\n\t\t\"%s\".\n\n", nexttoken(F)->string);

	while (nexttoken(F)->type == T_NEWLINE)
	{
		removetoken(F);
	}
}

ASTnode*
parse_language(FFIstate *F)
{
	ASTnode	*stmt, *root, *p;


	if (!infirsts(P_LANGUAGE, nexttoken(F)->type))
	{
		/*
		 *	Print syntax error message based on FIRST() set.
		 *	For initial version, we don't attempt any sort of
		 *	error recovery.
		 */
		syntaxerror(F, P_LANGUAGE, ASTnode_MAX);
		flexprint(F->Fe, F->Fm, F->Fperr, "\tffi2code: exiting...\n\n");

		exit(EXIT_FAILURE);
	}


	root = (ASTnode*)calloc(1, sizeof(ASTnode));
	if (root == NULL)
	{
		fatal(F, Emalloc);
		exit(EXIT_FAILURE);
	}
	root->type = P_LANGUAGE;
	p = root;

	while ((stmt = parse_ffstmt(F)) != NULL)
	{
		p->l = (ASTnode*)calloc(1, sizeof(ASTnode));
		if (p->l == NULL)
		{
			fatal(F, Emalloc);
			exit(EXIT_FAILURE);
		}
		p->l->type = X_SEQ;

		p = p->l;
		p->r = stmt;
	}

	return root;
}


bool
lookahead4(Input *I, const char *string)
{
	if (	(I->head 			!= NULL) &&
		(I->head->prev			!= NULL) &&
		(((Datum *)I->head->prev)->prev		!= NULL) &&
		(((Datum*)((Datum *)I->head->prev)->prev)->prev	!= NULL) &&
		!strcmp(((Datum*)((Datum*)((Datum *)I->head->prev)->prev)->prev)->data, string)
	)
	{
		return true;
	}

	return false;
}

ASTnode*
parse_ffstmt(FFIstate *F)
{
	Input		*I = &F->Fi->istream;


	if (I->head == NULL)
	{
		return NULL;
	}


	/*
		ffstmt		::= firstsetstmt | followsetstmt .
		firstsetstmt	::= ("token" | "production") identifier ':' "firstset" '=' '{' firstset '}'   .
		followsetstmt	::= ("token" | "production") identifier ':' "followset" '=' '{' followset '}' .
	*/

	if (lookahead4(I, "firstset"))
	{
		return parse_xsetstmt(F, P_FIRSTSETSTMT);
	}

	if (lookahead4(I, "followset"))
	{
		return parse_xsetstmt(F, P_FOLLOWSETSTMT);
	}

	flexprint(F->Fe, F->Fm, F->Fperr, "\n\tSyntax error while parsing %s. Current input steam is:\n\n", gASTnodeDESCRIPTIONS[P_FFSTMT]);
	flexstreamchk(F->Fe, F->Fm, F->Fperr, F->Fi, kFFI_MAXERRORTOKS, kFFI_STREAMCHKWIDTH);
	
	exit(EXIT_FAILURE);
}


ASTnode*
parse_xsetstmt(FFIstate *F, ASTnodeType x)
{
	/*
		ffstmt		::= firstsetstmt | followsetstmt .
		firstsetstmt	::= ("token" | "production") identifier ':' "firstset" '=' '{' firstset '}'   .
		followsetstmt	::= ("token" | "production") identifier ':' "followset" '=' '{' followset '}' .
	*/

	ASTnode		*root, *l, *r = NULL;
	Input		*I = &F->Fi->istream;
	Pair		*next;


	if (F->verbose & kFFI_VERBOSE_CALLTRACE)
	{
		flexprint(F->Fe, F->Fm, F->Fperr, "parse_xsetstmt()\n");
	}


	if (I->head == NULL)
	{
		return NULL;
	}

	root = (ASTnode*)calloc(1, sizeof(ASTnode));
	if (root == NULL)
	{
		fatal(F, Emalloc);
		exit(EXIT_FAILURE);
	}
	root->type = x;


	
	/*
	 *	Build the subtree:	root->l:	token/prod
	 *				root->l->l:	identifier
	 *				root->l->r:	NULL
	 *				root->r:	firstset
	 */
	next = nexttoken(F);
	removetoken(F);
	l = (ASTnode*)calloc(1, sizeof(ASTnode));
	if (l == NULL)
	{
		fatal(F, Emalloc);
		exit(EXIT_FAILURE);
	}
	l->type = next->type;
	

	next = nexttoken(F);
	l->l = (ASTnode*)calloc(1, sizeof(ASTnode));
	if (l->l == NULL)
	{
		fatal(F, Emalloc);
		exit(EXIT_FAILURE);
	}
	l->l->type = next->type;
	
	/*	Make a copy, because removetoken() will dealloc it 	*/
	l->l->tokenstring = (char*)calloc(1, strlen(next->string)+1);
	if (l->l->tokenstring == NULL)
	{
		fatal(F, Emalloc);
		exit(EXIT_FAILURE);
	
	}
	strcpy(l->l->tokenstring, next->string);
	removetoken(F);


	/*	Gobble up the ':' 'firstset/followset' '='	*/
	removetoken(F);
	removetoken(F);
	removetoken(F);

	if (x == P_FIRSTSETSTMT)
	{
		r = parse_firstset(F);
	}
	else if (x == P_FOLLOWSETSTMT)
	{
		r = parse_followset(F);
	}
	else
	{
		fatal(F, Esanity);
	}


	root->l = l;
	root->r = r;


	return root;
}



ASTnode*
parse_firstsetop(FFIstate *F)
{
	if (F->verbose & kFFI_VERBOSE_CALLTRACE)
	{
		flexprint(F->Fe, F->Fm, F->Fperr, "parse_firstsetop()\n");
	}

	return NULL;
}


ASTnode*
parse_xset(FFIstate *F, ASTnodeType x)
{
	ASTnode		**tmproot, *root;
	Input		*I = &F->Fi->istream;
	Pair		*next;


	if (F->verbose & kFFI_VERBOSE_CALLTRACE)
	{
		flexprint(F->Fe, F->Fm, F->Fperr, "parse_xset()\n");
	}

	if (I->head == NULL)
	{
		return NULL;
	}

	root = (ASTnode*)calloc(1, sizeof(ASTnode));
	if (root == NULL)
	{
		fatal(F, Emalloc);
		exit(EXIT_FAILURE);
	}
	root->type = x;



	/*	Gobble up the '{'	*/
	removetoken(F);

	
	/*
	 *	Build the subtree:	root->l:	X_SEQ
	 *				root->r:	NULL
	 *				root->l->r:	token/prod
	 *				root->l->l:	(future subtree)
	 */
	tmproot = &(root->l);
	while ((next = nexttoken(F))->type != T_RBRACE)
	{
		if (	nexttoken(F)->type == T_COMMA 	||
			nexttoken(F)->type == T_NEWLINE ||
			nexttoken(F)->type == T_LPAREN 	||
			nexttoken(F)->type == T_RPAREN	)
		{
			removetoken(F);
			continue;
		}

		*tmproot = (ASTnode*)calloc(1, sizeof(ASTnode));
		if (*tmproot == NULL)
		{
			fatal(F, Emalloc);
			exit(EXIT_FAILURE);
		}
		(*tmproot)->type = X_SEQ;


		(*tmproot)->r = (ASTnode*)calloc(1, sizeof(ASTnode));
		if ((*tmproot)->r == NULL)
		{
			fatal(F, Emalloc);
			exit(EXIT_FAILURE);
		}
		(*tmproot)->r->type = next->type;

		/*	Make a copy, because removetoken() will dealloc it 	*/
		(*tmproot)->r->tokenstring = (char*)calloc(1, strlen(next->string)+1);
		if ((*tmproot)->r->tokenstring == NULL)
		{
			fatal(F, Emalloc);
			exit(EXIT_FAILURE);
		}
		strcpy((*tmproot)->r->tokenstring, next->string);

		/*
		 *	For items such as "firstset(x)/followset(x)", build the subtree:
		 *
		 *			(*tmproot)->r->type	= T_FIRSTSET
		 *			(*tmproot)->r->l->type	= T_IDENTIFIER
		 */
		if (	next->type == T_FIRSTSET ||
			((x == P_FOLLOWSET) && (next->type == T_FOLLOWSET)))
		{
			if (F->verbose & kFFI_VERBOSE_ACTIONTRACE)
			{
				fprintf(stderr, "Building subtree for [%s]: ", next->string);
			}

			/*	Gobble up the 'firstset/followset' '('	*/
			removetoken(F);
			removetoken(F);

			/*	Get the production identifier whose firstset/followset is of interest	*/
			next = nexttoken(F);

			if (F->verbose & kFFI_VERBOSE_ACTIONTRACE)
			{
				fprintf(stderr, "[%s]\n", next->string);
			}

			(*tmproot)->r->l = (ASTnode*)calloc(1, sizeof(ASTnode));
			if ((*tmproot)->r->l == NULL)
			{
				fatal(F, Emalloc);
				exit(EXIT_FAILURE);
			}
			(*tmproot)->r->l->type = next->type;

			/*	Make a copy, because removetoken() will dealloc it 	*/
			(*tmproot)->r->l->tokenstring = (char*)calloc(1, strlen(next->string)+1);
			if ((*tmproot)->r->l->tokenstring == NULL)
			{
				fatal(F, Emalloc);
				exit(EXIT_FAILURE);
			}
			strcpy((*tmproot)->r->l->tokenstring, next->string);


			/*	Gobble up the ')'	*/
			removetoken(F);
		}
		else if (F->verbose & kFFI_VERBOSE_ACTIONTRACE)
		{
			fprintf(stderr, "[%s]\n", next->string);
		}

		tmproot = &((*tmproot)->l);
		removetoken(F);
	}


	/*	Gobble up the '}'	*/
	removetoken(F);

	while (nexttoken(F)->type == T_NEWLINE)
	{
		removetoken(F);
	}

	if (F->verbose & kFFI_VERBOSE_ACTIONTRACE)
	{
		fprintf(stderr, "\n");
	}


	return root;
}


ASTnode*
parse_firstset(FFIstate *F)
{
	if (F->verbose & kFFI_VERBOSE_CALLTRACE)
	{
		flexprint(F->Fe, F->Fm, F->Fperr, "parse_firstset()\n");
	}

	return parse_xset(F, P_FIRSTSET);
}


ASTnode*
parse_followsetop(FFIstate *F)
{
	if (F->verbose & kFFI_VERBOSE_CALLTRACE)
	{
		flexprint(F->Fe, F->Fm, F->Fperr, "parse_followsetop()\n");
	}

	return NULL;
}


ASTnode*
parse_followset(FFIstate *F)
{
	if (F->verbose & kFFI_VERBOSE_CALLTRACE)
	{
		flexprint(F->Fe, F->Fm, F->Fperr, "parse_followset()\n");
	}

	return parse_xset(F, P_FOLLOWSET);
}


ASTnode *
find_subtree(ASTnode *node, ASTnodeType type, char *identifier, FFIstate *F)
{
	ASTnode	*found;


	if (node == NULL)
	{
		return NULL;
	}

	if ((found = find_subtree(node->l, type, identifier, F)) != NULL)
	{
		return found;
	}
	
	if ((found = find_subtree(node->r, type, identifier,  F)) != NULL)
	{
		return found;
	}

	/*								*/
	/*	For P_FIRSTSETSTMT and P_FOLLOWSETSTMT, node->l->l	*/
	/*	has the relevant identifier we want to compare to.	*/
	/*								*/
//if (node->type == type) fprintf(stderr, "type=[%d], identifier = [%s], node->l->l->tokenstring = [%s]\n", type, identifier, node->l->l->tokenstring);
	if (	((type == P_FIRSTSETSTMT) || (type == P_FOLLOWSETSTMT)) &&
		(node->type == type) && !strcmp(identifier, node->l->l->tokenstring))
	{
		return node;
	}


	return NULL;
}


ASTnode*
copy_subtree(ASTnode *subtree, FFIstate *F)
{
return subtree;
}

void
delete_subtree(ASTnode *subtree, FFIstate *F)
{
return;
	if (subtree == NULL)
	{
		return;
	}

	delete_subtree(subtree->l, F);
	delete_subtree(subtree->r, F);

	if (subtree->tokenstring != NULL)
	{
		free(subtree->tokenstring);
	}

	free(subtree);
}


void
replace_followsets(ASTnode *root, ASTnode *node, FFIstate *F)
{
	if (node == NULL)
	{
		return;
	}

	replace_followsets(root, node->l, F);
	replace_followsets(root, node->r, F);


	/*								*/
	/*	Replace X_SEQ nodes whose node->r are either		*/
	/*	T_FIRSTSET or T_FOLLOWSET, with a sequence of		*/
	/*	X_SEQs each of whose node->r is the expanded		*/
	/*	FIRSTSET() or FOLLOWSET().				*/
	/*								*/
	if ((node->type == X_SEQ) && (node->r->type == T_FIRSTSET))
	{
		/*	The subtree we seek is a P_FIRSTSETSTMT, not T_FIRSTSET	*/
		ASTnode		*subtree = find_subtree(root, P_FIRSTSETSTMT, node->r->l->tokenstring, F);
		
//if (subtree != NULL) fprintf(stderr, "Found subtree for [%s]:\n", node->r->l->tokenstring);
//if (subtree != NULL) fprintf(stdout, "%s\n", ast_print(F, subtree));

		/*							*/
		/*	subtree->r->l is the replacement XSEQ chain	*/
		/*	we are interested in. Add a copy of it to	*/
		/*	replace node, by setting node's l and r to	*/
		/*	copies of its l and r.				*/
		/*							*/
//fprintf(stderr, "Replacing subtree:\n%s:\n", ast_print(F, node));
		delete_subtree(node->l, F);
		node->l = copy_subtree(subtree->r->l->l, F);

		delete_subtree(node->r, F);
		node->r = copy_subtree(subtree->r->l->r, F);

//fprintf(stderr, "New subtree:\n%s:\n", ast_print(F, node));
	}

	if ((node->type == X_SEQ) && (node->r->type == T_FOLLOWSET))
	{
		/*	The subtree we seek is a P_FOLLOWSETSTMT, not T_FOLLOWSET	*/
		ASTnode		*subtree = find_subtree(root, P_FOLLOWSETSTMT, node->r->l->tokenstring, F);

//if (subtree != NULL) fprintf(stderr, "Found subtree for [%s]:\n", node->r->l->tokenstring);
//if (subtree != NULL) fprintf(stdout, "%s\n", ast_print(F, subtree));
	}

	return;
}


void
ast_colortree(FFIstate *F, ASTnode *p, int color)
{
	if (p == NULL)
	{
		return;
	}

	if (p->l == p || p->r == p)
	{
		error(F, "Immediate cycle in AST, seen ast_colortree()!!\n");
		return;
	}

	p->color = color;
	ast_colortree(F, p->l, color);
	ast_colortree(F, p->r, color);

	return;
}

int
ast_treesz(FFIstate *F, ASTnode *p)
{
	if (p == NULL)
	{
		return 0;
	}

	if (p->l == p || p->r == p)
	{
		error(F, "Immediate cycle in predtree, seen in ast_treesz()!!\n");
		return 0;
	}

	return (1 + ast_treesz(F, p->l) + ast_treesz(F, p->r));
}

int
ast_printwalk(FFIstate *F, ASTnode *p, char *buf, int buflen)
{
	int	n0 = 0, n1 = 0, n2 = 0, n = 0;


	//
	//	TODO: if we run out of space in print buffer, we should
	//	print a "..." rather than just ending like we do now.
	//

	if (p == NULL)
	{
		return 0;
	}

	if (p->l == p || p->r == p)
	{
		fprintf(stderr, "Immediate cycle in AST, seen in ast_printwalk()!!\n");

		return 0;
	}

	/*									*/
	/*	For DOT, we walk tree in postorder, though it doesn't matter	*/
	/*	either way.							*/
	/*									*/
	n0 = ast_printwalk(F, p->l, &buf[0], buflen);
	n1 = ast_printwalk(F, p->r, &buf[n0], buflen-n0);

	/*	Only process Pred nodes once	*/
	if (p->color == -1)
	{
		n2 = dotfmt(F, &buf[n0+n1], buflen-(n0+n1), p);
		p->color = 0;
	}

	n = n0+n1+n2;

	
	return n;
}


int
dotfmt(FFIstate *F, char *buf, int buflen, ASTnode *p)
{
	int	n = 0;
	char	*nilfmt, *nodeprops, *nodeborder, *src, *l, *r;
	char	*identstring = "";


//fprintf(stderr, "p->tokenstring=[%s]\n", p->tokenstring);
	if (p->tokenstring != NULL)
	{
		identstring = p->tokenstring;
	}
			

	/*										*/
	/*	We use the pointer address of the ASTnode *p to give a unique		*/
	/*	string for each node in the graph. NOTE: dot renders _much_ faster	*/
	/*	if we don't supply a fontname (which it often cannot find anyway),	*/
	/*										*/
	nilfmt 	   = "style=filled,color=\"#003333\",fontcolor=white,fontsize=8,width=0.3,height=0.16,fixedsize=true,label=\"nil\", shape=record";
	nodeprops  = "";
	nodeborder = "M";


	/*	For identifiers, different graph node properties	*/
	if (p->type == T_IDENTIFIER)
	{
		nodeprops = "style=filled,color=\"#ccff66\",fixedsize=true,";
		nodeborder = "";
	}

	/*	For X_SEQ, different graph node properties		*/
	if (p->type == X_SEQ)
	{
		nodeprops = "style=filled,color=\"#999999\",fixedsize=true,";
		nodeborder = "M";
	}

	
	src = (char *)calloc(kFFI_MAXPRINTBUF, sizeof(char));
	if (src == NULL)
	{
		fatal(F, Emalloc);
	}

	src[0] = '\0';

	n += snprintf(&buf[n], buflen,
		"\tP" FLEX_PTRFMTH " [%sfontsize=8,height=0.8,"
		"label=\"{P" FLEX_PTRFMTH "\\ntype=%s\\n%s%s\\n%s| {<left> | <right> }}\",shape=%srecord];\n",
		(FlexAddr)p, nodeprops, (FlexAddr)p, gASTnodeSTRINGS[p->type], 
		((identstring == NULL || strlen(identstring) == 0) ? "" : " identifier="), identstring, 
		src, nodeborder);

	buflen -= n;

	if (p->l == NULL)
	{
		n += snprintf(&buf[n], buflen, "\tP" FLEX_PTRFMTH "_leftnil [%s];\n",
			(FlexAddr)p, nilfmt); buflen -= n;
	}
	if (p->r == NULL)
	{
		n += snprintf(&buf[n], buflen, "\tP" FLEX_PTRFMTH "_rightnil [%s];\n",
			(FlexAddr)p, nilfmt); buflen -= n;
	}

	
	l = (char *)calloc(kFFI_MAXPRINTBUF, sizeof(char));
	if (l == NULL)
	{
		fatal(F, Emalloc);
	}

	r = (char *)calloc(kFFI_MAXPRINTBUF, sizeof(char));
	if (r == NULL)
	{
		fatal(F, Emalloc);
	}

	if (p->l == NULL)
	{
		snprintf(l, kFFI_MAXPRINTBUF, "P" FLEX_PTRFMTH "_leftnil", (FlexAddr)p);
	}
	else
	{
		snprintf(l, kFFI_MAXPRINTBUF, "P" FLEX_PTRFMTH "", (FlexAddr)p->l);
	}

	if (p->r == NULL)
	{
		snprintf(r, kFFI_MAXPRINTBUF, "P" FLEX_PTRFMTH "_rightnil", (FlexAddr)p);
	}
	else
	{
		snprintf(r, kFFI_MAXPRINTBUF, "P" FLEX_PTRFMTH, (FlexAddr)p->r);
	}

	n += snprintf(&buf[n], buflen, "\tP" FLEX_PTRFMTH ":left -> %s;\n", (FlexAddr)p, l);
	buflen -= n;
	n += snprintf(&buf[n], buflen, "\tP" FLEX_PTRFMTH ":right -> %s;\n", (FlexAddr)p, r);
	buflen -= n;

	free(src);
	free(l);
	free(r);


	return n;
}

char *
ast_print(FFIstate *F, ASTnode *p)
{
	int			buflen, treesz, n = 0;
	char			*buf = NULL;
	struct timeval		t;
	extern char		FFI2CODE_VERSION[];
	char			datestring[26];			/*	Length is required to be 26 chars by ctime_r.		*/


	/*	Heuristic	*/
	treesz = ast_treesz(F, p);
	buflen = treesz*kFFI_CHUNK_PREDPRINTBUF_MULTIPLIER;

	/*							*/
	/*	 This buffer is deallocated by our caller	*/
	/*							*/
	buf = calloc(buflen, sizeof(char));
	if (buf == NULL)
	{
		fatal(F, Emalloc);
	}

	gettimeofday(&t, NULL);
	ctime_r(&t.tv_sec, datestring);

	/*	Ctime string always ends in '\n\0'; elide the '\n'	*/
	datestring[24] = '.';

	n += snprintf(&buf[n], buflen, "digraph PREDTREE\n{\n");
//TODO: here and elsewhere, should be taking buflen = max(buflen - n, 0)
//n = max(MAX_PRINT_BUF - strlen(buf), 0); like we do for universe_print

	buflen -= n;

	/*	When rendering bitmapped, don't restrict size, and leave dpi reasonable (~150)	*/
	n += snprintf(&buf[n], buflen, "\tdpi=150;\n");
	buflen -= n;
	n += snprintf(&buf[n], buflen, "\tfontcolor=\"#C0C0C0\";\n");
	buflen -= n;
	n += snprintf(&buf[n], buflen, "\tfontsize=18;\n");
	buflen -= n;

//TODO: take the whole of this following string as one of the arguments, called, e.g., "dotplotlabel",
//so we are not calling gettimeofday() from here, and don't need to have the VM_VERSION symbol here either.
	n += snprintf(&buf[n], buflen, "\tlabel = \"\\nAuto-generated by ffi2code version %s, on %s\";\n",
			kFFI2CODE_VERSION, datestring);
	buflen -= n;
	n += snprintf(&buf[n], buflen, "\tsplines = true;\n");
	buflen -= n;

	/*	Don't restrict size when rendering bitmapped		*/
	//n += snprintf(&buf[n], buflen, "\tsize = \"5,9\";\n");
	//buflen -= n;

	n += snprintf(&buf[n], buflen, "\tmargin = 0.1;\n");
	buflen -= n;
	//linux n += snprintf(&buf[n], buflen, "\t\" \" [penwidth=0, color=white, margin=0, shapefile=\"salsvm-logo-small.png\"];\n");
	//linux buflen -= n;

	/*							*/
	/*	Temporarily color the graph, so we can know	*/
	/*	which nodes have been visited, in case when	*/
	/*	the graph is not a tree.			*/
	/*							*/
	ast_colortree(F, p, -1);


	n += ast_printwalk(F, p, &buf[n], buflen);
	buflen -= n;
//fprintf(stderr, "buflen = %d\n", buflen);
	/*		In case of DOT, need prologue and epilogue		*/
	n += snprintf(&buf[n], buflen, "}\n");
	buflen -= n;
//fprintf(stderr, "n = %d\n", n);

	/*	Revert predicate graph color to neutral (0).	*/
	ast_colortree(F, p, 0);


	return buf;
}

void
usage(FFIstate *F)
{
	flexprint(F->Fe, F->Fm, F->Fperr, "Usage: ffi2code <filename>\n");
}

void
fatal(FFIstate *F, const char *msg)
{
	fflush(stdout);
	fflush(stderr);

	/*										*/
	/*	Fatal message should always go to stderr / console, and not to GUI	*/
	/*	NOTE: F is NULL when fatal is evoked early in initialization.		*/
	/*										*/
	if (F == NULL)
	{
		fprintf(stderr, "\n%s: %s\n\n", Effi2codefatal, msg);
	}
	else
	{
		flexprint(F->Fe, F->Fm, F->Fperr, "\n%s: %s\n\n", Effi2codefatal, msg);
	}

	exit(EXIT_FAILURE);
}


void
error(FFIstate *F, const char *msg)
{
	if (F == NULL)
	{
		fatal(F, Esanity);
	}

	if (!(F->mode & kFFI_MODEVERBOSE))
	{
		return;
	}

	flexprint(F->Fe, F->Fm, F->Fperr, "\n%s: %s\n", Effi2codeerror, msg);


	if (F != NULL && F->Fe != NULL && F->Fe->errstr != NULL)
	{
		snprintf(F->Fe->errstr, F->Fe->errlen, "%s: %s", Effi2codeerror, msg);
	}

	return;
}
