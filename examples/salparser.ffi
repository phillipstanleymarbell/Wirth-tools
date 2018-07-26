production P_BOOLCONST:			firstset = {T_TRUE, T_FALSE, T_MAYBE}

production P_BASETYPE:			firstset = {T_INTEGERS, T_REALS, T_STRINGS}

production P_CONSTSETEXPR:		firstset = {T_LBRACE}

production P_ORDERABLEINTCONSTDIM:	firstset = {T_LT, T_INTEGERS}

production P_UNORDERABLEINTCONSTDIM:	firstset = {T_LBRACE}

production P_ORDERABLEREALCONSTDIM:	firstset = {T_LT, T_REALS}

production P_UNORDERABLEREALCONSTDIM:	firstset = {T_LBRACE}

production P_ORDERABLESTRCONSTDIM:	firstset = {T_LT, T_STRINGS}

production P_UNORDERABLESTRCONSTDIM:	firstset = {T_LBRACE}

production P_CONSTDIMEXPR:		firstset = {T_LBRACE, T_LT, T_INTEGERS, T_REALS, T_STRINGS}

production P_HPRECBINBOOLOP:		firstset = {T_AND, T_CARET}

production P_LPRECBINBOOLOP:		firstset = {T_OR}

production P_UNARYBOOLOP:		firstset = {T_NOT}

production P_ARITH2BOOLOP:		firstset = {T_EQ, T_NE, T_GT, T_GE, T_LT, T_LE}

production P_HPRECARITH2ARITHOP:	firstset = {T_MUL, T_DIV, T_MOD, T_POW, T_LOG}

production P_LPRECARITH2ARITHOP:	firstset = {T_PLUS, T_SUB}

production P_AGGROP:			firstset = {T_MUL, T_DIV, T_MOD, T_POW, T_LOG, T_PLUS, T_SUB}

production P_HPRECBOOLSETOP:		firstset = {T_INTERSECT, T_CROSS}

production P_LPRECBOOLSETOP:		firstset = {T_PLUS, T_SUB, T_CARET}

production P_UNARYSETOP:		firstset = {T_POWERSET, T_SETCOMPLEMENT}

production P_QUANTIFIEROP:		firstset = {T_FORALL, T_EXISTS}

production P_SETCMPOP:			firstset = {T_WEAKDOMINATES, T_STRICTDOMINATES}

production P_UANDOP:			firstset = {T_UNIONOVER, T_ANDOVER}

production P_PROGRAM:			firstset = 	{	epsilon,
								T_PREG, T_IREG, T_WREG, T_RREG, T_SREG, T_UREG, T_PRINT,
								T_REGCLR, T_LPREGS, T_LSREGS, T_LUREGS, T_LIREGS, T_LRREGS,
								T_LWREGS, T_LOAD, T_EMALLOCDEBUG, T_PMALLOCDEBUG, T_MVERSEINFO,
								T_HELP, T_MAN, T_SHOWDOTPATH, T_SETDOTPATH, T_SETMAXENUMS, 
								T_SETCPULIMIT, T_SETMEMLIMIT, T_ECHO, T_VERBOSE, T_DUMPSTATE,
								T_QUIT, T_COMMENT, T_NEWLINE
							}

production P_PREDASSIGN:		firstset = {T_PREG}
			
production P_IREGASSIGN:		firstset = {T_IREG}

production P_WREGASSIGN:		firstset = {T_WREG}

production P_RREGASSIGN:		firstset = {T_RREG}

production P_SETINFERDEFN:		firstset = {T_SREG}

production P_UNVDEFN:			firstset = {T_UREG}

production P_UNVINFERDEFN:		firstset = {T_UREG}

production P_MISCOP:			firstset = 	{	
								T_PRINT, T_REGCLR, T_LPREGS, T_LSREGS, T_LUREGS,
								T_LIREGS, T_LRREGS, T_LWREGS, T_LOAD, T_EMALLOCDEBUG,
								T_PMALLOCDEBUG, T_MVERSEINFO, T_HELP, T_MAN, T_SHOWDOTPATH,
								T_SETDOTPATH, T_SETMAXENUMS, T_SETCPULIMIT, T_SETMEMLIMIT,
								T_ECHO, T_VERBOSE, T_DUMPSTATE, T_QUIT, T_COMMENT, T_NEWLINE
							}

production P_AGGREXPR:			firstset = {T_AGGR}

production P_ABSTREXPR:			firstset = {T_ABSTR}

production P_PROJEXPR:			firstset = {T_PROJ}

production P_UANDEXPR:			firstset = {T_LPAREN}

production P_OPTFILENAME:		firstset = {T_STRINGCONST}

production P_PRINTFMT:			firstset = {T_ENUM, T_RANDENUM, T_PREWALK, T_POSTWALK, T_DOT, T_INFO}

production P_TYPE:			firstset = {T_INTEGERS, T_REALS, T_STRINGS, T_UREG, T_LPAREN}

production P_UNVFACTOR:			firstset = {T_INTEGERS, T_REALS, T_STRINGS, T_UREG, T_LPAREN}

production P_UNVTERM:			firstset = {T_INTEGERS, T_REALS, T_STRINGS, T_UREG, T_LPAREN, T_POWERSET, T_SETCOMPLEMENT}

production P_UNVEXPR:			firstset = {T_INTEGERS, T_REALS, T_STRINGS, T_UREG, T_LPAREN, T_POWERSET, T_SETCOMPLEMENT}

production P_IDENTORVALUE:		firstset = {arithexpr (fill in after we've done arithexpr's FIRSTs), T_QUOTEDSTRING, T_WREG}

production P_IDENTORVALUELIST:		firstset = {arithexpr (fill in after we've done arithexpr's FIRSTs), T_QUOTEDSTRING, T_WREG}

production P_IDENTIFIER:		firstset = {T_STRING}

production P_VARINTRO:			firstset = {T_STRING}

production P_VARTUPLE:			firstset = {arithexpr (fill in after we've done arithexpr's FIRSTs), T_QUOTEDSTRING, T_WREG, T_LPAREN}

production P_ARITHCONST:		firstset = {T_IMEM, T_RMEM, T_IREG, T_UIMM, T_SUB, T_PLUS, T_RREG, T_DIMM}

production P_ARITHFACTOR:		firstset = 	{
								T_IMEM, T_RMEM, T_IREG, T_UIMM, T_SUB, T_PLUS, T_RREG, T_DIMM,
								T_LPAREN, T_STRING, T_OR
							}

production P_ARITHTERM:			firstset =	{
								T_IMEM, T_RMEM, T_IREG, T_UIMM, T_SUB, T_PLUS, T_RREG, T_DIMM, 
								T_LPAREN, T_STRING, T_OR
							}

production P_ARITHOVEROP:		firstset = {T_SUM, T_PRODUCT}

production P_ARITHOVER:			firstset = {T_SUM, T_PRODUCT}

production P_ARITHEXPR:			firstset =	{
								T_IMEM, T_RMEM, T_IREG, T_UIMM, T_SUB, T_PLUS, T_RREG, T_DIMM, 
								T_LPAREN, T_STRING, T_OR, T_SUM, T_PRODUCT
							}

production P_QUANTBOOLTERM:		firstset = {T_FORALL, T_EXISTS}

production P_CONDEXPR:			firstset = {T_LPAREN}

production P_REGFULLTERM:		firstset = {T_REGFULL}








production P_SETCMPTERM:		firstset = {firstset(P_SETEXPR)}

production P_PREDFACTOR:		firstset = {firstset(P_BOOLCONST), T_RANDPTREE , T_READPTREE, T_PREG, T_LPAREN}

production P_OPTDEVTOLSPEC:		firstset = {epsilon, T_AT}

production P_PREDTERM:			firstset = 	{
								firstset(predfactor), firstset(arithexpr) firstset(quantboolterm),
								firstset(regfullterm), firstset(setcmpterm), firstset(vartuple),
								firstset(unaryboolop)
							}
						
production P_PREDEXPR:			firstset = {firstset(P_PREDTERM)}

production P_MINEXPR:			firstset = {T_MIN}

production P_SETFACTOR:			firstset = {firstset(P_CONSTSETEXPR), T_LBRACE, T_OMEGA, T_SREG, T_LPAREN}

production P_SETTERM:			firstset =	{
								firstset(setfactor), firstset(unarysetop), firstset(minexpr),
								firstset(aggrexpr), firstset(abstrexpr), firstset(projexpr),
								firstset(uandexpr)
							}

production P_SETEXPR:			firstset = {firstset(P_SETTERM)}

production P_STRINGCONST:		firstset = {T_STRING, T_QUOTEDSTRING}

production P_INTCONST:			firstset = {T_UIMM, T_SUB, T_PLUS}

production P_INTPARAMORCONST:		firstset = {firstset(P_INTCONST), T_IREG}

production P_IREGIDX:			firstset = {T_IMEM}

production P_REALCONST:			firstset = {T_DIMM, T_SUB, T_PLUS}

production P_REALPARAMORCONST:		firstset = {firstset(P_REALCONST), T_RREG}
			
production P_RREGIDX:			firstset = {T_RMEM}
			
production P_REALRANGELIST:		firstset = {firstset(P_REALPARAMORCONST)}
			
production P_REALLISTBODY:		firstset = 	{
								firstset(P_REALRANGELIST), firstset(P_REALPARAMORCONST),
								firstset(P_REALLISTBODY), firstset(P_REALLISTBODY)
							}
			
production P_INTRANGELIST:		firstset = {firstset(P_INTPARAMORCONST), firstset(P_INTPARAMORCONST)}
			
production P_INTLISTBODY:		firstset = {firstset(P_INTRANGELIST), firstset(P_INTPARAMORCONST), firstset(P_INTLISTBODY)}

production P_STRPARAMORCONST:		firstset = {T_QUOTEDSTRING, T_WREG}

production P_WREGIDX:			firstset = {T_WMEM}

production P_STRINGLISTBODYSINGLE:	firstset = {firstset(P_STRPARAMORCONST)}

production P_STRINGLISTBODY:		firstset = {firstset(P_STRINGLISTBODYSINGLE), firstset(P_STRINGLISTBODY)}
			
production P_TUPLEELEM:			firstset = {firstset(P_INTPARAMORCONST), firstset(P_REALPARAMORCONST), firstset(P_STRPARAMORCONST)}

production P_TUPLEBODY:			firstset = {firstset(P_TUPLEELEM), firstset(P_TUPLEBODY)}
			
production P_TUPLE:			firstset = {T_LPAREN, firstset(P_TUPLEELEM)}

production P_TUPLELISTBODY:		firstset = {firstset(P_TUPLE), firstset(P_TUPLELISTBODY)}
						
			
			
			
			


production	P_PREDASSIGN:			followset = {followset(P_STMT)}
production	P_ABSTREXPR:			followset = {followset(P_SETTERM)}
production	P_AGGREXPR:			followset = {followset(P_SETTERM)}
production	P_AGGROP:			followset = {T_UIMM}
production	P_ARITH2BOOLOP:			followset = {firstset(P_OPTDEVTOLSPEC)}
production	P_ARITHCONST:			followset = {followset(P_ARITHFACTOR)}
production	P_ARITHEXPR:			followset = {T_OF}
production	P_ARITHEXPR:			followset = {T_RBRAC}
production	P_ARITHEXPR:			followset = {T_RPAREN}
production	P_ARITHEXPR:			followset = {T_STEP}
production	P_ARITHEXPR:			followset = {T_TO}
production	P_ARITHEXPR:			followset = {firstset(P_ARITH2BOOLOP)}
production	P_ARITHEXPR:			followset = {firstset(P_LPRECARITH2ARITHOP)}
production	P_ARITHEXPR:			followset = {firstset(P_OPTFILENAME)}
production	P_ARITHEXPR:			followset = {followset(P_ARITHOVER)}
production	P_ARITHEXPR:			followset = {followset(P_IDENTORVALUE)}
production	P_ARITHEXPR:			followset = {followset(P_INTRANGELIST)}
production	P_ARITHEXPR:			followset = {followset(P_IREGASSIGN)}
production	P_ARITHEXPR:			followset = {followset(P_PREDTERM)}
production	P_ARITHEXPR:			followset = {followset(P_REALRANGELIST)}
production	P_ARITHEXPR:			followset = {followset(P_RREGASSIGN)}
production	P_ARITHFACTOR:			followset = {followset(P_ARITHTERM)}
production	P_ARITHOVER:			followset = {followset(P_ARITHEXPR)}
production	P_ARITHOVEROP:			followset = {firstset(P_VARINTRO)}
production	P_ARITHTERM:			followset = {firstset(P_HPRECARITH2ARITHOP)}
production	P_ARITHTERM:			followset = {followset(P_ARITHEXPR)}
production	P_BASETYPE:			followset = {followset(P_TYPE)}			
production	P_BOOLCONST:			followset = {followset(P_PREDFACTOR)}
production	P_CONDEXPR:			followset = {followset(P_ARITHFACTOR)}
production	P_CONSTDIMEXPR:			followset = {followset(P_UNVDEFN)}
production	P_CONSTSETEXPR:			followset = {followset(P_SETFACTOR)}
production	P_HPRECARITH2ARITHOP:		followset = {firstset(P_ARITHFACTOR)}
production	P_HPRECARITH2ARITHOP:		followset = {followset(P_AGGROP)}
production	P_HPRECBINBOOLOP:		followset = {firstset(P_PREDFACTOR)}
production	P_HPRECBOOLSETOP:		followset = {firstset(P_SETFACTOR)}
production	P_HPRECBOOLSETOP:		followset = {firstset(P_UNVFACTOR)}
production	P_IDENTIFIER:			followset = {followset(P_ARITHFACTOR)}
production	P_IDENTORVALUE:			followset = {T_COMMA}
production	P_IDENTORVALUE:			followset = {followset(P_IDENTORVALUELIST)}
production	P_IDENTORVALUE:			followset = {followset(P_VARTUPLE)}
production	P_IDENTORVALUELIST:		followset = {T_RPAREN}
production	P_INTCONST:			followset = {followset(P_INTPARAMORCONST)}
production	P_INTLISTBODY:			followset = {T_BRACE}
production	P_INTLISTBODY:			followset = {T_COMMA}
production	P_INTLISTBODY:			followset = {T_GT}
production	P_INTPARAMORCONST:		followset = {T_DELTA}
production	P_INTPARAMORCONST:		followset = {T_ELLIPSIS}
production	P_INTPARAMORCONST:		followset = {followset(P_ARITHCONST)}
production	P_INTPARAMORCONST:		followset = {followset(P_INTLISTBODY)}
production	P_INTPARAMORCONST:		followset = {followset(P_INTRANGELIST)}
production	P_INTPARAMORCONST:		followset = {followset(P_OPTDEVTOLSPEC)}
production	P_INTPARAMORCONST:		followset = {followset(P_TUPLEELEM)}
production	P_INTRANGELIST:			followset = {followset(P_INTLISTBODY)}
production	P_IREGASSIGN:			followset = {followset(P_STMT)}
production	P_IREGIDX:			followset = {followset(P_ARITHCONST)}
production	P_LPRECARITH2ARITHOP:		followset = {firstset(P_ARITHTERM)}
production	P_LPRECARITH2ARITHOP:		followset = {followset(P_AGGROP)}
production	P_LPRECBINBOOLOP:		followset = {firstset(P_PREDTERM)}
production	P_LPRECBOOLSETOP:		followset = {firstset(P_SETTERM)}
production	P_LPRECBOOLSETOP:		followset = {firstset(P_UNVTERM)}
production	P_MINEXPR:			followset = {followset(P_SETTERM)}
production	P_MISCOP:			followset = {followset(P_STMT)}
production	P_OPTDEVTOLSPEC:		followset = {firstset(P_ARITHEXPR)}
production	P_OPTDEVTOLSPEC:		followset = {firstset(P_SETTERM)}
production	P_OPTFILENAME:			followset = {followset(P_MISCOP)}
production	P_ORDERABLEINTCONSTDIM:		followset = {followset(P_CONSTDIMEXPR)}
production	P_ORDERABLEREALCONSTDIM:	followset = {followset(P_CONSTDIMEXPR)}
production	P_ORDERABLESTRCONSTDIM:		followset = {followset(P_CONSTDIMEXPR)}
production	P_PREDEXPR:			followset = {T_COLON}
production	P_PREDEXPR:			followset = {T_RPAREN}
production	P_PREDEXPR:			followset = {firstset(P_LPRECBINBOOLOP)}
production	P_PREDEXPR:			followset = {firstset(P_SETEXPR)}
production	P_PREDEXPR:			followset = {followset(P_PREDASSIGN)}
production	P_PREDEXPR:			followset = {followset(P_QUANTBOOLTERM)}
production	P_PREDFACTOR:			followset = {followset(P_PREDTERM)}
production	P_PREDFACTOR:			followset = {followset(P_PREDTERM)}			
production	P_PREDTERM:			followset = {firstset(P_HPRECBINBOOLOP)}
production	P_PREDTERM:			followset = {followset(P_PREDEXPR)}
production	P_PRINTFMT:			followset = {T_PREG}
production	P_PRINTFMT:			followset = {T_SREG}
production	P_PROGRAM:			followset = {T_EOF}
production	P_PROGRAM:			followset = {firstset(P_STMT)}
production	P_PROJEXPR:			followset = {followset(P_SETTERM)}
production	P_QUANTBOOLTERM:		followset = {followset(P_PREDTERM)}
production	P_QUANTIFIEROP:			followset = {firstset(P_VARINTRO)}
production	P_REALCONST:			followset = {followset(P_REALPARAMORCONST)}
production	P_REALLISTBODY:			followset = {T_COMMA}
production	P_REALLISTBODY:			followset = {T_GT}
production	P_REALLISTBODY:			followset = {T_RBRACE}
production	P_REALPARAMORCONST:		followset = {T_DELTA}
production	P_REALPARAMORCONST:		followset = {followset(P_ARITHCONST)}
production	P_REALPARAMORCONST:		followset = {followset(P_OPTDEVTOLSPEC)}
production	P_REALPARAMORCONST:		followset = {followset(P_REALLISTBODY)}
production	P_REALPARAMORCONST:		followset = {followset(P_TUPLEELEM)}
production	P_REALRANGELIST:		followset = {followset(P_REALLISTBODY)}
production	P_REGFULLTERM:			followset = {followset(P_PREDTERM)}
production	P_RREGASSIGN:			followset = {followset(P_STMT)}
production	P_RREGIDX:			followset = {followset(P_ARITHCONST)}
production	P_SETCMPOP:			followset = {firstset(P_SETEXPR)}
production	P_SETCMPTERM:			followset = {followset(P_PREDTERM)}
production	P_SETEXPR:			followset = {T_RPAREN}
production	P_SETEXPR:			followset = {firstset(P_LPRECBOOLSETOP)}
production	P_SETEXPR:			followset = {firstset(P_SETCMPOP)}
production	P_SETEXPR:			followset = {followset(P_SETCMPTERM)}
production	P_SETEXPR:			followset = {followset(P_SETINFERDEFN)}
production	P_SETFACTOR:			followset = {followset(P_SETTERM)}
production	P_SETINFERDEFN:			followset = {followset(P_STMT)}
production	P_SETTERM:			followset = {firstset(P_HPRECBOOLSETOP)}
production	P_SETTERM:			followset = {followset(P_PREDTERM)}
production	P_SETTERM:			followset = {followset(P_SETEXPR)}
production	P_STRINGCONST:			followset = {followset(P_MISCOP)}
production	P_STRINGCONST:			followset = {followset(P_OPTFILENAME)}
production	P_STRINGCONST:			followset = {followset(P_PREDFACTOR)}
production	P_STRINGLISTBODY:		followset = {T_COMMA}
production	P_STRINGLISTBODY:		followset = {T_GT}
production	P_STRINGLISTBODY:		followset = {T_RBRACE}
production	P_STRINGLISTBODYSINGLE:		followset = {followset(P_STRINGLISTBODY)}
production	P_STRPARAMORCONST:		followset = {followset(P_IDENTORVALUE)}
production	P_STRPARAMORCONST:		followset = {followset(P_STRINGLISTBODY)}
production	P_STRPARAMORCONST:		followset = {followset(P_STRINGLISTBODYSINGLE)}
production	P_STRPARAMORCONST:		followset = {followset(P_TUPLEELEM)}
production	P_TUPLE:			followset = {followset(P_TUPLELISTBODY)}
production	P_TUPLEBODY:			followset = {T_COMMA}
production	P_TUPLEBODY:			followset = {T_RPAREN}
production	P_TUPLEELEM:			followset = {followset(P_TUPLE)}
production	P_TUPLEELEM:			followset = {followset(P_TUPLEBODY)}
production	P_TUPLELISTBODY:		followset = {T_COMMA}
production	P_TUPLELISTBODY:		followset = {T_RBRACE}
production	P_TYPE:				followset = {followset(P_UNVFACTOR)}
production	P_UANDEXPR:			followset = {followset(P_SETTERM)}
production	P_UNARYBOOLOP:			followset = {firstset(P_PREDFACTOR)}
production	P_UNARYSETOP:			followset = {firstset(P_SETFACTOR)}
production	P_UNARYSETOP:			followset = {firstset(P_UNVFACTOR)}
production	P_UNORDERABLEINTCONSTDIM:	followset = {followset(P_CONSTDIMEXPR)}
production	P_UNORDERABLEREALCONSTDIM:	followset = {followset(P_CONSTDIMEXPR)}
production	P_UNORDERABLESTRCONSTDIM:	followset = {followset(P_CONSTDIMEXPR)}
production	P_UNVDEFN:			followset = {followset(P_STMT)}
production	P_UNVEXPR:			followset = {T_ASSIGN}
production	P_UNVEXPR:			followset = {T_RPAREN}
production	P_UNVEXPR:			followset = {firstset(P_LPRECBOOLSETOP)}
production	P_UNVEXPR:			followset = {followset(P_CONSTSETEXPR)}
production	P_UNVEXPR:			followset = {followset(P_UNVINFERDEFN)}
production	P_UNVFACTOR:			followset = {followset(P_UNVTERM)}
production	P_UNVINFERDEFN:			followset = {followset(P_STMT)}
production	P_UNVTERM:			followset = {firstset(P_HPRECBOOLSETOP)}
production	P_UNVTERM:			followset = {followset(P_UNVEXPR)}
production	P_VARINTRO:			followset = {T_FROM}
production	P_VARINTRO:			followset = {T_SUCHTHAT}
production	P_VARINTRO:			followset = {firstset(P_PREDEXPR)}
production	P_VARINTRO:			followset = {followset(P_ARITHFACTOR)}
production	P_VARTUPLE:			followset = {T_IN}
production	P_WREGASSIGN:			followset = {followset(P_STMT)}
production	P_identifier:			followset = {T_COLON}
production	P_realparamorconst:		followset = {T_ELLIPSIS}
producton	P_UANDOP:			followset = {firstset(P_VARINTRO)}
token		P_SETEXPR:			followset = {T_RPAREN}
token		T_ABSTR:			followset = {T_SREG}
token		T_AGGR:				followset = {T_SREG}
token		T_AND:				followset = {followset(P_HPRECBINBOOLOP)}
token		T_ANDOVER:			followset = {followset(P_UANDOP)}
token		T_ASSIGN:			followset = {T_QUOTEDSTRING}
token		T_ASSIGN:			followset = {firstset(P_ARITHEXPR)}
token		T_ASSIGN:			followset = {firstset(P_CONSTDIMEXPR)}
token		T_ASSIGN:			followset = {firstset(P_PREDEXPR)}
token		T_ASSIGN:			followset = {firstset(P_SETEXPR)}
token		T_ASSIGN:			followset = {firstset(P_UNVEXPR)}
token		T_AT:				followset = {firstset(P_INTPARAMORCONST)}
token		T_AT:				followset = {firstset(P_REALPARAMORCONST)}
token		T_CARET:			followset = {followset(P_HPRECBINBOOLOP)}
token		T_CARET:			followset = {followset(P_LPRECBOOLSETOP)}
token		T_COLON:			followset = {T_UREG}
token		T_COLON:			followset = {firstset(P_UNVEXPR)}
token		T_COMMA:			followset = {P_IDENTORVALUELIST}
token		T_COMMA:			followset = {firstset(P_IDENTORVALUELIST)}
token		T_COMMA:			followset = {firstset(P_INTPARAMORCONST)}
token		T_COMMA:			followset = {firstset(P_INTRANGELIST)}
token		T_COMMA:			followset = {firstset(P_REALPARAMORCONST)}
token		T_COMMA:			followset = {firstset(P_REALRANGELIST)}
token		T_COMMA:			followset = {firstset(P_STRPARAMORCONST)}
token		T_COMMA:			followset = {firstset(P_TUPLE)}
token		T_COMMA:			followset = {firstset(P_TUPLEELEM)}
token		T_COMMENT:			followset = {followset(P_MISCOP)}
token		T_CROSS:			followset = {followset(P_HPRECBOOLSETOP)}
token		T_DELTA:			followset = {firstset(P_ARITHEXPR)}
token		T_DIMM:				followset = {followset(P_REALCONST)}
token		T_DIV:				followset = {followset(P_HPRECARITH2ARITHOP)}
token		T_DOT:				followset = {followset(P_PRINTFMT)}
token		T_DUMPSTATE:			followset = {firstset(P_STRINGCONST)}
token		T_ECHO:				followset = {firstset(P_STRINGCONST)}
token		T_ELLIPSIS:			followset = {firstset(P_INTPARAMORCONST)}
token		T_ELLIPSIS:			followset = {firstset(P_REALPARAMORCONST)}
token		T_EMALLOCDEBUG:			followset = {T_UIMM}
token		T_ENUM:				followset = {followset(P_PRINTFMT)}
token		T_EQ:				followset = {followset(P_ARITH2BOOLOP)}
token		T_EXISTS:			followset = {followset(P_QUANTIFIEROP)}
token		T_FALSE:			followset = {followset(T_TRUE), followset(T_MAYBE), followset(P_BOOLCONST)}
token		T_FORALL:			followset = {followset(P_QUANTIFIEROP)}
token		T_FROM:				followset = {firstset(P_ARITHEXPR)}
token		T_GE:				followset = {followset(P_ARITH2BOOLOP)}
token		T_GT:				followset = {followset(P_ARITH2BOOLOP)}
token		T_GT:				followset = {followset(P_ORDERABLEINTCONSTDIM)}
token		T_GT:				followset = {followset(P_ORDERABLEREALCONSTDIM)}
token		T_GT:				followset = {followset(P_ORDERABLESTRCONSTDIM)}
token		T_HELP:				followset = {followset(P_MISCOP)}
token		T_IMEM:				followset = {T_LBRAC}
token		T_IN:				followset = {firstset(P_OPTDEVTOLSPEC)}
token		T_INFO:				followset = {followset(P_PRINTFMT)}
token		T_INTEGERS:			followset = {followset(T_REALS), followset(T_STRINGS), followset(P_BASETYPE)}
token		T_INTEGERS:			followset = {followset(P_ORDERABLEINTCONSTDIM)}
token		T_INTERSECT:			followset = {followset(P_HPRECBOOLSETOP)}
token		T_IREG:				followset = {T_ASSIGN}
token		T_IREG:				followset = {followset(P_INTPARAMORCONST)}				
token		T_IREG:				followset = {followset(P_REGFULLTERM)}
token		T_LBRAC:			followset = {firstset(P_ARITHEXPR)}
token		T_LBRACE:			followset = {T_RBRACE}
token		T_LBRACE:			followset = {firstset(P_INTLISTBODY)}
token		T_LBRACE:			followset = {firstset(P_REALLISTBODY)}
token		T_LBRACE:			followset = {firstset(P_STRINGLISTBODY)}
token		T_LBRACE:			followset = {firstset(P_TUPLELISTBODY)}
token		T_LE:				followset = {followset(P_ARITH2BOOLOP)}
token		T_LIREGS:			followset = {followset(P_MISCOP)}
token		T_LLVM:				followset = {firstset(P_ARITHEXPR)}
token		T_LOAD:				followset = {firstset(P_STRINGCONST)}
token		T_LOG:				followset = {followset(P_HPRECARITH2ARITHOP)}
token		T_LPAREN:			followset = {T_SET2TYPE}
token		T_LPAREN:			followset = {firstset(P_ARITHEXPR)}
token		T_LPAREN:			followset = {firstset(P_IDENTORVALUE)}
token		T_LPAREN:			followset = {firstset(P_PREDEXPR)}
token		T_LPAREN:			followset = {firstset(P_SETEXPR)}
token		T_LPAREN:			followset = {firstset(P_TUPLEBODY)}
token		T_LPAREN:			followset = {firstset(P_UANDOP)}
token		T_LPAREN:			followset = {firstset(P_UNVEXPR)}
token		T_LPAREN:			followset = {firstset(P_VARINTRO)}
token		T_LPREGS:			followset = {followset(P_MISCOP)}
token		T_LRREGS:			followset = {followset(P_MISCOP)}
token		T_LSREGS:			followset = {followset(P_MISCOP)}
token		T_LT:				followset = {firstset(P_INTLISTBODY)}
token		T_LT:				followset = {firstset(P_REALLISTBODY)}
token		T_LT:				followset = {firstset(P_STRINGLISTBODY)}
token		T_LT:				followset = {followset(P_ARITH2BOOLOP)}
token		T_LUREGS:			followset = {followset(P_MISCOP)}
token		T_LWREGS:			followset = {followset(P_MISCOP)}
token		T_MAN:				followset = {followset(P_MISCOP)}
token		T_MAYBE:			followset = {followset(T_TRUE), followset(T_FALSE), followset(P_BOOLCONST)}
token		T_MIN:				followset = {T_SREG}
token		T_MOD:				followset = {followset(P_HPRECARITH2ARITHOP)}
token		T_MUL:				followset = {followset(P_HPRECARITH2ARITHOP)}
token		T_MVERSEINFO:			followset = {followset(P_MISCOP)}
token		T_NE:				followset = {followset(P_ARITH2BOOLOP)}
token		T_NOT:				followset = {followset(P_UNARYBOOLOP)}
token		T_OF:				followset = {firstset(P_ARITHEXPR)}
token		T_OMEGA:			followset = {followset(P_SETFACTOR)}
token		T_OR:				followset = {T_SREG}
token		T_OR:				followset = {followset(P_ARITHFACTOR)}
token		T_OR:				followset = {followset(P_LPRECBINBOOLOP)}
token		T_PLUS:				followset = {T_DIMM}
token		T_PLUS:				followset = {T_UIMM}
token		T_PLUS:				followset = {followset(P_LPRECARITH2ARITHOP)}
token		T_PLUS:				followset = {followset(P_LPRECBOOLSETOP)}
token		T_PMALLOCDEBUG:			followset = {followset(P_MISCOP)}
token		T_POSTWALK:			followset = {followset(P_PRINTFMT)}
token		T_POW:				followset = {followset(P_HPRECARITH2ARITHOP)}
token		T_POWERSET:			followset = {followset(P_UNARYSETOP)}
token		T_PREG:				followset = {T_ASSIGN}
token		T_PREG:				followset = {firstset(P_OPTFILENAME)}
token		T_PREG:				followset = {followset(P_MISCOP)}
token		T_PREG:				followset = {followset(P_PREDFACTOR)}
token		T_PREWALK:			followset = {followset(P_PRINTFMT)}
token		T_PRINT:			followset = {T_LLVM}
token		T_PRINT:			followset = {T_UREG}
token		T_PRINT:			followset = {firstset(P_PRINTFMT)}
token		T_PRODUCT:			followset = {followset(P_ARITHOVEROP)}
token		T_PROJ:				followset = {T_SREG}
token		T_QUIT:				followset = {followset(P_MISCOP)}
token		T_QUOTEDSTRING:			followset = {followset(P_STRINGCONST)}
token		T_QUOTEDSTRING:			followset = {followset(P_STRPARAMORCONST)}
token		T_QUOTEDSTRING:			followset = {followset(P_WREGASSIGN)}
token		T_RANDENUM:			followset = {followset(P_PRINTFMT)}
token		T_RANDPTREE:			followset = {T_UIMM}
token		T_RBRAC:			followset = {followset(P_IREGIDX)}
token		T_RBRAC:			followset = {followset(P_RREGIDX)}
token		T_RBRAC:			followset = {followset(P_VARINTRO)}
token		T_RBRAC:			followset = {followset(P_WREGIDX)}
token		T_RBRACE:			followset = {T_COLON}
token		T_RBRACE:			followset = {followset(P_SETFACTOR)}
token		T_RBRACE:			followset = {followset(P_UNORDERABLEINTCONSTDIM)}
token		T_RBRACE:			followset = {followset(P_UNORDERABLEREALCONSTDIM)}
token		T_RBRACE:			followset = {followset(P_UNORDERABLESTRCONSTDIM)}
token		T_READPTREE:			followset = {firstset(P_STRINGCONST)}
token		T_REALS:			followset = {followset(T_INTEGERS), followset(T_STRINGS), followset(P_BASETYPE)}
token		T_REALS:			followset = {followset(P_ORDERABLEREALCONSTDIM)}
token		T_REGCLR:			followset = {T_PREG}
token		T_REGCLR:			followset = {T_SREG}
token		T_REGCLR:			followset = {T_UREG}
token		T_REGFULL:			followset = {T_IREG}
token		T_REGFULL:			followset = {T_RREG}
token		T_REGFULL:			followset = {T_WREG}
token		T_RMEM:				followset = {T_LBRAC}
token		T_RPAREN:			followset = {followset(P_ARITHFACTOR)}
token		T_RPAREN:			followset = {followset(P_CONDEXPR)}
token		T_RPAREN:			followset = {followset(P_PREDFACTOR)}
token		T_RPAREN:			followset = {followset(P_SETFACTOR)}
token		T_RPAREN:			followset = {followset(P_TUPLE)}
token		T_RPAREN:			followset = {followset(P_TYPE)}
token		T_RPAREN:			followset = {followset(P_UANDEXPR)}
token		T_RPAREN:			followset = {followset(P_UNVFACTOR)}
token		T_RPAREN:			followset = {followset(P_VARTUPLE)}
token		T_RREG:				followset = {T_ASSIGN}
token		T_RREG:				followset = {followset(P_REALPARAMORCONST)}
token		T_RREG:				followset = {followset(P_REGFULLTERM)}
token		T_SET2TYPE:			followset = {firstset(P_SETEXPR)}
token		T_SETCOMPLEMENT:		followset = {followset(P_UNARYSETOP)}
token		T_SETCPULIMIT:			followset = {T_UIMM}
token		T_SETDOTPATH:			followset = {firstset(P_STRINGCONST)}
token		T_SETMAXENUMS:			followset = {T_UIMM}
token		T_SETMEMLIMIT:			followset = {T_UIMM}
token		T_SHOWDOTPATH:			followset = {followset(P_MISCOP)}
token		T_SREG:				followset = {T_ASSIGN}
token		T_SREG:				followset = {T_OR}
token		T_SREG:				followset = {T_UIMM}
token		T_SREG:				followset = {firstset(P_AGGROP)}
token		T_SREG:				followset = {firstset(P_OPTFILENAME)}
token		T_SREG:				followset = {followset(P_MINEXPR)}
token		T_SREG:				followset = {followset(P_MISCOP)}
token		T_SREG:				followset = {followset(P_SETFACTOR)}
token		T_STEP:				followset = {firstset(P_ARITHEXPR)}
token		T_STRICTDOMINATES:		followset = {followset(P_SETCMPOP)}
token		T_STRING:			followset = {followset(P_IDENTIFIER)}
token		T_STRING:			followset = {followset(P_STRINGCONST)}
token		T_STRINGS:			followset = {followset(T_INTEGERS), followset(T_REALS), followset(P_BASETYPE)}
token		T_STRINGS:			followset = {followset(P_ORDERABLESTRCONSTDIM)}
token		T_SUB:				followset = {T_DIMM}
token		T_SUB:				followset = {T_UIMM}
token		T_SUB:				followset = {followset(P_LPRECARITH2ARITHOP)}
token		T_SUB:				followset = {followset(P_LPRECBOOLSETOP)}
token		T_SUCHTHAT:			followset = {firstset(P_PREDEXPR)}
token		T_SUM:				followset = {followset(P_ARITHOVEROP)}
token		T_TO:				followset = {firstset(P_ARITHEXPR)}
token		T_TRUE:				followset = {followset(T_FALSE), followset(T_MAYBE), followset(P_BOOLCONST)}
token		T_UIMM:				followset = {T_UIMM}
token		T_UIMM:				followset = {followset(P_ABSTREXPR)}
token		T_UIMM:				followset = {followset(P_AGGREXPR)}
token		T_UIMM:				followset = {followset(P_INTCONST)}
token		T_UIMM:				followset = {followset(P_MISCOP)}
token		T_UIMM:				followset = {followset(P_PREDFACTOR)}
token		T_UIMM:				followset = {followset(P_PROJEXPR)}
token		T_UNIONOVER:			followset = {followset(P_UANDOP)}
token		T_UREG:				followset = {T_ASSIGN}
token		T_UREG:				followset = {T_COLON}
token		T_UREG:				followset = {T_LBRAC}
token		T_UREG:				followset = {firstset(P_OPTFILENAME)}
token		T_UREG:				followset = {followset(P_MISCOP)}
token		T_UREG:				followset = {followset(P_TYPE)}	
token		T_VERBOSE:			followset = {T_UIMM}
token		T_WEAKDOMINATES:		followset = {followset(P_SETCMPOP)}
token		T_WMEM:				followset = {T_LBRAC}
token		T_WREG:				followset = {T_ASSIGN}
token		T_WREG:				followset = {followset(P_REGFULLTERM)}
token		T_WREG:				followset = {followset(P_STRPARAMORCONST)}





