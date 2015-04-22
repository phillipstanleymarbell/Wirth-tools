typedef enum
{
	P_LANGUAGE		= 0,
	P_FFSTMT		= 1,
	P_FIRSTSETSTMT		= 2,
	P_FOLLOWSETSTMT		= 3,
	P_FIRSTSETOP		= 4,
	P_FIRSTSET		= 5,
	P_FOLLOWSETOP		= 6,
	P_FOLLOWSET		= 7,
	T_IDENTIFIER		= 8,
	T_TOKEN			= 9,
	T_PRODUCTION		= 10,
	T_FIRSTSET		= 11,
	T_FOLLOWSET		= 12,

	ASTnode_TREERESIDENT	= 13,

	/*							*/
	/*	The following tokens are seen in parsing, but	*/
	/*	don't go into the AST.				*/
	/*							*/
	T_COLON			= 14,
	T_EQUALS		= 15,
	T_COMMA			= 16,
	T_LBRACE		= 17,
	T_RBRACE		= 18,
	T_LPAREN		= 19,
	T_RPAREN		= 20,
	T_NEWLINE		= 21,

	T_EPSILON		= 22,

	/*							*/					
	/*	Used for chaining items in the AST		*/
	/*							*/
	X_SEQ			= 23,

	/*							*/
	/*	Code depends on this bringing up the rear	*/
	/*							*/
	ASTnode_MAX		= 24,
} ASTnodeType;

typedef struct
{
	/*								*/
	/*	Used to get error status from FlexLib routines		*/
	/*								*/
	FlexErrState	*Fe;

	/*								*/
        /*			Parsed input stream			*/
	/*								*/
	FlexIstream	*Fi;


	/*								*/
	/*	State for the portable/monitoring allocator (FlexM)	*/
	/*								*/
	FlexMstate	*Fm;

	/*								*/
	/*	State for portable/buffering print routines (FlexP)	*/
	/*	We have one buffer for informational messages, and	*/
	/*	another for errors and warnings.			*/
	/*								*/
	FlexPrintBuf	*Fperr;
	FlexPrintBuf	*Fpinfo;

	uint64_t	mode;
	uint64_t	verbose;
} FFIstate;


typedef struct ASTnode ASTnode;
struct ASTnode
{
	ASTnodeType	type;
	char		*tokenstring;
	ASTnode		*l;
	ASTnode		*r;

	int		color;
};

typedef enum
{
	kFFI_MAXBUFLEN				= 1024,
	kFFI_MAXERRORTOKS			= 32,
	kFFI_STREAMCHKWIDTH			= 32,
	kFFI_MODEVERBOSE			= (1 << 0),
	kFFI_MAXPRINTBUF			= 8192,
	kFFI_CHUNK_PREDPRINTBUF_MULTIPLIER	= 8192,
	kFFI_VERBOSE_CALLTRACE			= (1 << 0),
	kFFI_VERBOSE_ACTIONTRACE		= (1 << 1),
	kFFI_MAX_TOKEN_CHARS                    = 32        
} FFIconstants;

typedef struct
{
	ASTnodeType	type;
	char		*string;
} Pair;
