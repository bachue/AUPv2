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
CFLAGS = $(INCLUDES) -I$(AUPSRC)/include -I$(AUPSRC)/common -g -Wimplicit -Wstrict-prototypes -Wall -D$(OS) -D_REENTRANT -D_THREAD_SAFE
CC = gcc
# Same objects are used all the time, sometimes linking in unnecessary files.
AUPOBJS = $(AUPSRC)/common/ec.o $(AUPSRC)/common/logf.o $(AUPSRC)/common/macrostr.o $(AUPSRC)/c1/syserr.o
EXECS = hello testlock append_test aread setblock readany readany2 readany3 test_tc_keystroke test_tc_setraw fsort0 fsort msg_server msg_client
#############################################
# Utility to build macro-string program
#############################################
hello.o:
	$(CC) $(CFLAGS) -c  -o hello.o $(AUPSRC)/mytest/hello.c

testlock.o: $(AUPSRC)/mytest/testlock.c
	$(CC) $(CFLAGS) -c -o testlock.o $(AUPSRC)/mytest/testlock.c

append_test.o: $(AUPSRC)/mytest/append_test.c
	$(CC) $(CFLAGS) -c -o append_test.o $(AUPSRC)/mytest/append_test.c

setblock.o: $(AUPSRC)/mytest/setblock.c
	$(CC) $(CFLAGS) -c -o setblock.o $(AUPSRC)/mytest/setblock.c

libsetblock.o: $(AUPSRC)/c4/setblock.c
	$(CC) $(CFLAGS) -c -o libsetblock.o $(AUPSRC)/c4/setblock.c

readany.o: $(AUPSRC)/mytest/readany.c
	$(CC) $(CFLAGS) -c -o readany.o $(AUPSRC)/mytest/readany.c

readany2.o: $(AUPSRC)/mytest/readany2.c
	$(CC) $(CFLAGS) -c -o readany2.o $(AUPSRC)/mytest/readany2.c

readany3.o: $(AUPSRC)/mytest/readany3.c
	$(CC) $(CFLAGS)  -c -o readany3.o $(AUPSRC)/mytest/readany3.c

aread.o: $(AUPSRC)/mytest/aread.c
	$(CC) $(CFLAGS)  -c -o aread.o $(AUPSRC)/mytest/aread.c

fsort0.o: $(AUPSRC)/mytest/fsort0.c
	$(CC) $(CFLAGS)  -c -o fsort0.o $(AUPSRC)/mytest/fsort0.c

fsort.o: $(AUPSRC)/mytest/fsort.c
	$(CC) $(CFLAGS)  -c -o fsort.o $(AUPSRC)/mytest/fsort.c

test_tc_keystroke.o: $(AUPSRC)/mytest/test_tc_keystroke.c
	$(CC) $(CFLAGS)  -c -o test_tc_keystroke.o $(AUPSRC)/mytest/test_tc_keystroke.c

test_tc_setraw.o: $(AUPSRC)/mytest/test_tc_setraw.c
	$(CC) $(CFLAGS)  -c -o test_tc_setraw.o $(AUPSRC)/mytest/test_tc_setraw.c

msg_server.o: $(AUPSRC)/mytest/msg_server.c
	$(CC) $(CFLAGS)  -c -o msg_server.o $(AUPSRC)/mytest/msg_server.c

msg_client.o: $(AUPSRC)/mytest/msg_client.c
	$(CC) $(CFLAGS)  -c -o msg_client.o $(AUPSRC)/mytest/msg_client.c

hello: hello.o
	$(CC) $(CFLAGS) -o hello hello.o $(AUPOBJS) $(LIBS)

testlock: testlock.o
	$(CC) -o testlock testlock.o $(AUPOBJS) $(LIBS)

append_test: append_test.o
	$(CC) -o append_test append_test.o $(AUPOBJS) $(LIBS)

setblock: setblock.o libsetblock.o
	$(CC) -o setblock setblock.o libsetblock.o $(AUPOBJS) $(LIBS)

readany: readany.o libsetblock.o
	$(CC) -o readany readany.o libsetblock.o $(AUPOBJS) $(LIBS)

readany2: readany2.o
	$(CC) -o readany2 readany2.o $(AUPOBJS) $(LIBS)

readany3: readany3.o
	$(CC) -o readany3 readany3.o $(AUPOBJS) $(LIBS)

aread: aread.o
	$(CC) -o aread aread.o $(AUPOBJS) $(LIBS) -lrt

fsort0: fsort0.o
	$(CC) -o fsort0 fsort0.o $(AUPOBJS) $(LIBS)

fsort: fsort.o
	$(CC) -o fsort fsort.o $(AUPOBJS) $(LIBS)

test_tc_keystroke: test_tc_keystroke.o $(AUPSRC)/c4/tc_setraw.o
	$(CC) -o test_tc_keystroke $(AUPSRC)/c4/tc_setraw.o test_tc_keystroke.o $(AUPOBJS) $(LIBS) -lrt
test_tc_setraw: test_tc_setraw.o $(AUPSRC)/c4/tc_setraw.o
	$(CC) -o test_tc_setraw $(AUPSRC)/c4/tc_setraw.o test_tc_setraw.o $(AUPOBJS) $(LIBS) -lrt

msg_server: msg_server.o
	$(CC) -o msg_server msg_server.o $(AUPOBJS) $(LIBS)

msg_client: msg_client.o
	$(CC) -o msg_client msg_client.o $(AUPOBJS) $(LIBS)

all:  $(EXECS)
clean:
	rm -f *.o $(EXECS)
