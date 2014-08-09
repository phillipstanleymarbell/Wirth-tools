LIBFLEXPATH     = ../libflex
CONFIGPATH	= ../libflex
include		$(CONFIGPATH)/config.$(OSTYPE)-$(MACHTYPE).clang
include		config.$(OSTYPE)-$(MACHTYPE).clang


CCFLAGS		= $(PLATFORM_CFLAGS) $(PLATFORM_DFLAGS) $(PLATFORM_OPTFLAGS) $(PLATFORM_DBGFLAGS)
LDFLAGS 	= -lm $(PLATFORM_LFLAGS)

FFI2CODE_L10N	= EN
CCFLAGS         += -DFFI2CODE_L10N="\"$(FFI2CODE_L10N)\"" -DFFI2CODE_L10N_EN

TARGET		= ffi2code-$(OSTYPE)-$(FFI2CODE_L10N)


WFLAGS		= -Wall #-Werror
INCDIRS		= -I. -I$(LIBFLEXPATH)


OBJS		=\
		ffi2code.o\

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
%.o: %.c $(HEADERS) Makefile
#	$(SPLINT) $(FLEXFLAGS) $(INCDIRS) $<
#	$(LCLINT) $(FLEXFLAGS) $(INCDIRS) $<
	$(CC) $(FLEXFLAGS) $(INCDIRS) $(CCFLAGS) $(WFLAGS) $(OPTFLAGS) -c $<


version.h: Makefile
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
