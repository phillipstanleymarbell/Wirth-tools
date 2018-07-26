LIBFLEXPATH     = ../libflex-github-clone
CONFIGPATH	= ../libflex-github-clone
include		$(CONFIGPATH)/config.$(OSTYPE)-$(MACHTYPE).clang
include		config.$(OSTYPE)-$(MACHTYPE).clang


CCFLAGS		= $(PLATFORM_DBGFLAGS) $(PLATFORM_CFLAGS) $(PLATFORM_DFLAGS) $(PLATFORM_OPTFLAGS)

#
#	We pass in linker flags to explicitly request a large stack since for grammars with high nesting depth
#	we can run out of stack space.
#
LDFLAGS		= $(PLATFORM_DBGFLAGS) -lm $(PLATFORM_LFLAGS) -Wl,-stack_size -Wl,0xF000000

FFI2CODE_L10N	= EN

CCFLAGS		+= -DFFI2CODE_L10N="\"$(FFI2CODE_L10N)\"" -DFFI2CODE_L10N_EN

TARGET		= ffi2code-$(OSTYPE)-$(FFI2CODE_L10N)


WFLAGS		= -Wall #-Werror
INCDIRS		= -I. -I$(LIBFLEXPATH)


OBJS		=\
		ffi2code.$(OBJECTEXTENSION)\

HEADERS		=\
		version.h\



#
#			Executables
#
all: $(OBJS)
	$(LD) -L. -L$(LIBFLEXPATH) $(LDFLAGS) $(OBJS) -lflex-$(OSTYPE) -o $(TARGET)

#
#			Objects
#
%.$(OBJECTEXTENSION): %.c $(HEADERS) Makefile
#	$(SPLINT) $(FLEXFLAGS) $(INCDIRS) $<
#	$(LCLINT) $(FLEXFLAGS) $(INCDIRS) $<
	$(CC) $(FLEXFLAGS) $(INCDIRS) $(CCFLAGS) $(WFLAGS) $(OPTFLAGS) -c --analyze $<
	$(CC) $(FLEXFLAGS) $(INCDIRS) $(CCFLAGS) $(WFLAGS) $(OPTFLAGS) -c $<


version.h: Makefile ffi2code.c
	echo 'char kFFI2CODE_VERSION[] = "0.0-alpha (build '`date '+%m-%d-%Y-%H:%M'`-`whoami`@`hostname -s`-`uname -s`-`uname -r`-`uname -m`\)\"\; > version.h


#
#			Debug and Documentation
#
#	Need --dsymutil=yes flag to valgrind to get line numbers in error messages
debug:	all
	valgrind --dsymutil=yes --leak-check=yes ./$(TARGET) EXAMPLES/test.ffi >& debug.valgrind.log; sam debug.valgrind.log &

scan:	clean
	scan-build --use-cc=$(CC) -k -V make -j4

README.sloccount: clean
	sloccount *.c *.h *.y > README.sloccount





clean:
	rm -f $(OBJS) $(TARGET) version.h
