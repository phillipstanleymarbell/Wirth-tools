production	P_ROOT:				firstset = {firstset(T_LEAF1), firstset(T_LEAF2)}
production	P_ROOT:				followset = {followset(T_LEAF1), followset(T_LEAF2)}

token		T_LEAF1:			followset = {T_EOF}
token		T_LEAF2:			followset = {T_EOF}
