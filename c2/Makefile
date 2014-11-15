# Do not edit this makefile. It was generated automatically 
# with commands like
#
#     $ AUPSRC=/aup # (for example)
#     $ export AUPSRC
#     $ awk -f $AUPSRC/makebuild.awk $AUPSRC/c1/makebuild.spec >$AUPSRC/c1/Makefile
#
# It is incomplete in the sense that there are no header-file
# dependencies.
#
# Use the shell-procedure makebuild to run awk. Then compile
# with a shell-procedure like this one for Linux:
#
# 	AUPSRC=/aup # (for example)
# 	OS=LINUX
# 	LIBS="-lncurses -lutil"
# 	TLIBS=-pthread
# 	export OS LIBS TLIBS
# 	make $2 -f $AUPSRC/$1/Makefile $3
#

defaulttarget: all
# Following must be defined in the environment before you run make:
#
#	OS = SOLARIS or LINUX or FREEBSD
#	LIBS = regular (non-thread) libraries (eg, "-lncurses -lutil")
#	TLIBS = thread libraries (eg, "-llthread -llgcc_r")
#	PTHREADSTUB = stub for thread functions (eg, pthreadstub.o), if needed
#	INCLUDES = additional include directory (eg, "-I/usr/local/include/pthread/linuxthreads")
#	Don't forget:
#		export OS LIBS TLIBS PTHREADSTUB INCLUDES
#	Suggestions:
#		Solaris:
#			OS=SOLARIS
#			LIBS="-lrt -lcurses -lsocket -lnsl"
#			TLIBS="-lpthread"
#
#		FreeBSD:
#			OS=FREEBSD
#			LIBS="-lncurses -lutil"
#			TLIBS="-llthread -llgcc_r"
#			PTHREADSTUB=pthreadstub.o
#			INCLUDES="-I/usr/local/include/pthread/linuxthreads"
#
#		Linux:
#			OS=LINUX
#			LIBS="-lncurses -lutil"
#			TLIBS="-pthread"
CFLAGS = $(INCLUDES) -I$(AUPSRC)/include -I$(AUPSRC)/common -I$(AUPSRC)/c6 -g -Wimplicit -Wstrict-prototypes -Wall -D$(OS) -D_REENTRANT -D_THREAD_SAFE
CC = gcc
# Same objects are used all the time, sometimes linking in unnecessary files.
AUPOBJS = syserr.o time.o extio.o getblksize.o setblock.o ec.o logf.o options.o macrostr.o 

mms: mkmacrostr.o $(AUPOBJS) $(PTHREADSTUB)
	$(CC) -o mms mkmacrostr.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)
#############################################
# Utility to build macro-string program
#############################################
macrostr.o: $(AUPSRC)/common/macrostr.c $(AUPSRC)/common/macrostr.incl
	$(CC) $(CFLAGS) -c  -o $*.o $(AUPSRC)/common/macrostr.c

mkmacrostr.o: $(AUPSRC)/common/mkmacrostr.c
	$(CC) $(CFLAGS)  -c -o mkmacrostr.o $(AUPSRC)/common/mkmacrostr.c

options.o: $(AUPSRC)/common/options.c
	$(CC) $(CFLAGS)  -c -o options.o $(AUPSRC)/common/options.c

pthreadstub.o: $(AUPSRC)/common/pthreadstub.c
	$(CC) $(CFLAGS)  -c -o pthreadstub.o $(AUPSRC)/common/pthreadstub.c

ec.o: $(AUPSRC)/common/ec.c
	$(CC) $(CFLAGS)  -c -o ec.o $(AUPSRC)/common/ec.c

logf.o: $(AUPSRC)/common/logf.c
	$(CC) $(CFLAGS)  -c -o logf.o $(AUPSRC)/common/logf.c

setblock.o: $(AUPSRC)/c4/setblock.c
	$(CC) $(CFLAGS)  -c -o setblock.o $(AUPSRC)/c4/setblock.c

extio.o: $(AUPSRC)/c2/extio.c
	$(CC) $(CFLAGS)  -c -o extio.o $(AUPSRC)/c2/extio.c

syserr.o: $(AUPSRC)/c1/syserr.c
	$(CC) $(CFLAGS)  -c -o syserr.o $(AUPSRC)/c1/syserr.c

time.o: $(AUPSRC)/c1/time.c
	$(CC) $(CFLAGS)  -c -o time.o $(AUPSRC)/c1/time.c

getblksize.o: $(AUPSRC)/c2/getblksize.c
	$(CC) $(CFLAGS)  -c -o getblksize.o $(AUPSRC)/c2/getblksize.c

syncio: syncio.o $(AUPOBJS) $(PTHREADSTUB)
	$(CC) -o syncio syncio.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

trunc: trunc.o $(AUPOBJS) $(PTHREADSTUB)
	$(CC) -o trunc trunc.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

writev: writev.o $(AUPOBJS) $(PTHREADSTUB)
	$(CC) -o writev writev.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

x2: x2.o bufio.o $(AUPOBJS) $(PTHREADSTUB)
	$(CC) -o x2 x2.o bufio.o $(AUPOBJS) $(LIBS) $(PTHREADSTUB)

syncio.o: $(AUPSRC)/c2/syncio.c
	$(CC) $(CFLAGS)  -c -o syncio.o $(AUPSRC)/c2/syncio.c

x2.o: $(AUPSRC)/c2/x2.c
	$(CC) $(CFLAGS)  -c -o x2.o $(AUPSRC)/c2/x2.c

trunc.o: $(AUPSRC)/c2/trunc.c
	$(CC) $(CFLAGS)  -c -o trunc.o $(AUPSRC)/c2/trunc.c

bufio.o: $(AUPSRC)/c2/bufio.c
	$(CC) $(CFLAGS)  -c -o bufio.o $(AUPSRC)/c2/bufio.c

writev.o: $(AUPSRC)/c2/writev.c
	$(CC) $(CFLAGS)  -c -o writev.o $(AUPSRC)/c2/writev.c
testlock.o: $(AUPSRC)/c2/testlock.c
	$(CC) $(CFLAGS)  -c -o testlock.o $(AUPSRC)/c2/testlock.c
testlock: testlock.o
	$(CC) -o testlock testlock.o $(AUPOBJS) $(LIBS)

all:  x2 writev trunc syncio testlock
clean:
	rm  x2 writev trunc syncio *.o
