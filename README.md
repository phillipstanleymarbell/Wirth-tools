Wirth Tools
===========
Wirth is a set of tools to automate construction of a recursive-descent
parser in the Wirth style.

*	ffi2code takes the intermediate first and follow set definitions
	(.ffi file) and outputs header file definitions and array
	definitions for the **FIRST()** and **FOLLOW()** sets.

*	ffi2code depends on Libflex (https://github.com/phillipstanleymarbell/libflex)
	which is included as a submodule.

*	To build: `make OSTYPE=darwin MACHTYPE=x86_64` on macOS, or
	`make OSTYPE=linux MACHTYPE=x86_64` on linux.
