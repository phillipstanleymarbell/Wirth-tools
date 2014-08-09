--
--	language	::= {ffstmt} .
--	ffstmt		::= firstsetstmt | followsetstmt .
--	firstsetstmt	::= ("token" | "production") identifier ':' "firstset" '=' '{' firstset '}' .
--	followsetstmt	::= ("token" | "production") identifier ':' "followset" '=' '{' followset '}' .
--	firstsetop	::= "firstset" '(' identifier ')' .
--	firstset	::= (identifier | firstsetop) {',' (identifier | firstsetop)} .
--	followsetop	::= "followset" '(' identifier ')' .
--	followset	::= (identifier | firstsetop | followsetop) {',' (identifier | firstsetop | followsetop)} .
--

production	P_LANGUAGE:			firstset = {firstset(P_FFSTMT)}
production	P_FFSTMT:			firstset = {firstset(P_FIRSTSETSTMT), firstset(P_FOLLOWSETSTMT)}
production	P_FIRSTSETSTMT:			firstset = {T_TOKEN, T_PRODUCTION}
production	P_FOLLOWSETSTMT:		firstset = {T_TOKEN, T_PRODUCTION}
production	P_FIRSTSETOP:			firstset = {T_FIRSTSET}
production	P_FIRSTSET:			firstset = {T_IDENTIFIER, firstset(P_FIRSTSETOP)}
production	P_FOLLOWSETOP:			firstset = {T_FOLLOWSET}
production	P_FOLLOWSET:			firstset = {T_IDENTIFIER, firstset(P_FIRSTSETOP), firstset(P_FOLLOWSETOP)}

production	P_LANGUAGE:			followset = {T_EOF}
production	P_FFSTMT:			followset = {followset(P_LANGUAGE)}
production	P_FIRSTSETSTMT:			followset = {followset(P_FFSTMT)}
production	P_FOLLOWSETSTMT:		followset = {followset(P_FFSTMT)}
production	P_FIRSTSETOP:			followset = {T_COMMA, followset(P_FIRSTSET), followset(P_FOLLOWSET)}
production	P_FIRSTSET:			followset = {T_RBRACE}
production	P_FOLLOWSETOP:			followset = {T_COMMA, followset(P_FOLLOWSET)}
production	P_FOLLOWSET:			followset = {T_RBRACE}

token		T_TOKEN:			followset = {T_IDENTIFIER}
token		T_PRODUCTION:			followset = {T_IDENTIFIER}
token		T_IDENTIFIER:			followset = {T_COLON, T_RPAREN, T_COMMA, followset(P_FIRSTSET), followset(P_FOLLOWSET)}
token		T_COLON:			followset = {T_FIRSTSET, T_FOLLOWSET}
token		T_FIRSTSET:			followset = {T_EQUALS, T_LPAREN}
token		T_FOLLOWSET:			followset = {T_EQUALS, T_LPAREN}
token		T_EQUAL:			followset = {T_LBRACE}
token		T_LBRACE:			followset = {firstset(P_FIRSTSET), firstset(P_FOLLOWSET)}
token		T_RBRACE:			followset = {followset(P_FIRSTSETSTMT), followset(P_FOLLOWSETSTMT)}
token		T_LPAREN:			followset = {T_IDENTIFIER}
token		T_RPAREN:			followset = {followset(P_FIRSTSETOP), followset(P_FOLLOWSETOP)}
token		T_COMMA:			followset = {T_IDENTIFIER, firstset(P_FIRSTSETOP), firstset(P_FOLLOWSETOP)}