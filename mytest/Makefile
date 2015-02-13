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
CFLAGS = $(INCLUDES) -I$(AUPSRC)/include -I$(AUPSRC)/common -g3 -Wimplicit -Wstrict-prototypes -Wall -D$(OS) -D_REENTRANT -D_THREAD_SAFE
CC = gcc
# Same objects are used all the time, sometimes linking in unnecessary files.
AUPOBJS = $(AUPSRC)/common/ec.o $(AUPSRC)/common/logf.o $(AUPSRC)/common/macrostr.o $(AUPSRC)/c1/syserr.o
EXECS = hello testlock append_test aread setblock readany readany2 readany3 test_tc_keystroke test_tc_setraw fsort0 fsort msg_server msg_client mq_server mq_client sysv_sem_producer sysv_sem_consumer posix_sem_producer posix_sem_consumer test_shared_mem simple_socket_test order_test http_client getaddrinfo udp_test sig_on_subprocess rtsig_test1 rtsig_test2 alarm itimer time
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

mq_server.o: $(AUPSRC)/mytest/mq_server.c
	$(CC) $(CFLAGS)  -c -o mq_server.o $(AUPSRC)/mytest/mq_server.c -lrt

mq_client.o: $(AUPSRC)/mytest/mq_client.c
	$(CC) $(CFLAGS)  -c -o mq_client.o $(AUPSRC)/mytest/mq_client.c -lrt

sysv_sem_producer.o: $(AUPSRC)/mytest/sysv_sem_producer.c
	$(CC) $(CFLAGS)  -c -o sysv_sem_producer.o $(AUPSRC)/mytest/sysv_sem_producer.c

sysv_sem_consumer.o: $(AUPSRC)/mytest/sysv_sem_consumer.c
	$(CC) $(CFLAGS)  -c -o sysv_sem_consumer.o $(AUPSRC)/mytest/sysv_sem_consumer.c

posix_sem_producer.o: $(AUPSRC)/mytest/posix_sem_producer.c
	$(CC) $(CFLAGS)  -c -o posix_sem_producer.o $(AUPSRC)/mytest/posix_sem_producer.c -lrt

posix_sem_consumer.o: $(AUPSRC)/mytest/posix_sem_consumer.c
	$(CC) $(CFLAGS)  -c -o posix_sem_consumer.o $(AUPSRC)/mytest/posix_sem_consumer.c -lrt

test_shared_mem.o: $(AUPSRC)/mytest/test_shared_mem.c
	$(CC) $(CFLAGS)  -c -o test_shared_mem.o $(AUPSRC)/mytest/test_shared_mem.c

simple_socket_test.o: $(AUPSRC)/mytest/simple_socket_test.c
	$(CC) $(CFLAGS)  -c -o simple_socket_test.o $(AUPSRC)/mytest/simple_socket_test.c

order_test.o: $(AUPSRC)/mytest/order_test.c
	$(CC) $(CFLAGS)  -c -o order_test.o $(AUPSRC)/mytest/order_test.c

http_client.o: $(AUPSRC)/mytest/http_client.c
	$(CC) $(CFLAGS)  -c -o http_client.o $(AUPSRC)/mytest/http_client.c

getaddrinfo.o: $(AUPSRC)/mytest/getaddrinfo.c
	$(CC) $(CFLAGS)  -c -o getaddrinfo.o $(AUPSRC)/mytest/getaddrinfo.c

udp_test.o: $(AUPSRC)/mytest/udp_test.c
	$(CC) $(CFLAGS)  -c -o udp_test.o $(AUPSRC)/mytest/udp_test.c

sig_on_subprocess.o: $(AUPSRC)/mytest/sig_on_subprocess.c
	$(CC) $(CFLAGS)  -c -o sig_on_subprocess.o $(AUPSRC)/mytest/sig_on_subprocess.c

rtsig_test1.o: $(AUPSRC)/mytest/rtsig_test1.c
	$(CC) $(CFLAGS)  -c -o rtsig_test1.o $(AUPSRC)/mytest/rtsig_test1.c

rtsig_test2.o: $(AUPSRC)/mytest/rtsig_test2.c
	$(CC) $(CFLAGS)  -c -o rtsig_test2.o $(AUPSRC)/mytest/rtsig_test2.c

alarm.o: $(AUPSRC)/mytest/alarm.c
	$(CC) $(CFLAGS)  -c -o alarm.o $(AUPSRC)/mytest/alarm.c

itimer.o: $(AUPSRC)/mytest/itimer.c
	$(CC) $(CFLAGS)  -c -o itimer.o $(AUPSRC)/mytest/itimer.c

time.o: $(AUPSRC)/mytest/time.c
	$(CC) $(CFLAGS)  -c -o time.o $(AUPSRC)/mytest/time.c

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

mq_server: mq_server.o
	$(CC) -o mq_server mq_server.o $(AUPOBJS) $(LIBS) -lrt

mq_client: mq_client.o
	$(CC) -o mq_client mq_client.o $(AUPOBJS) $(LIBS) -lrt

sysv_sem_producer: sysv_sem_producer.o
	$(CC) -o sysv_sem_producer sysv_sem_producer.o $(AUPOBJS) $(LIBS)

sysv_sem_consumer: sysv_sem_consumer.o
	$(CC) -o sysv_sem_consumer sysv_sem_consumer.o $(AUPOBJS) $(LIBS)

posix_sem_producer: posix_sem_producer.o
	$(CC) -o posix_sem_producer posix_sem_producer.o $(AUPOBJS) $(LIBS) $(TLIBS) -lrt

posix_sem_consumer: posix_sem_consumer.o
	$(CC) -o posix_sem_consumer posix_sem_consumer.o $(AUPOBJS) $(LIBS) $(TLIBS) -lrt

test_shared_mem: test_shared_mem.o
	$(CC) -o test_shared_mem test_shared_mem.o $(AUPOBJS) $(LIBS)

simple_socket_test: simple_socket_test.o
	$(CC) -o simple_socket_test simple_socket_test.o $(AUPOBJS) $(LIBS)

order_test: order_test.o
	$(CC) -o order_test order_test.o $(AUPOBJS) $(LIBS)

http_client: http_client.o
	$(CC) -o http_client http_client.o $(AUPOBJS) $(LIBS)

getaddrinfo: getaddrinfo.o
	$(CC) -o getaddrinfo getaddrinfo.o $(AUPOBJS) $(LIBS)

udp_test: udp_test.o
	$(CC) -o udp_test udp_test.o $(AUPOBJS) $(LIBS)

sig_on_subprocess: sig_on_subprocess.o
	$(CC) -o sig_on_subprocess sig_on_subprocess.o $(AUPOBJS) $(LIBS)

rtsig_test1: rtsig_test1.o
	$(CC) -o rtsig_test1 rtsig_test1.o $(AUPOBJS) $(LIBS)

rtsig_test2: rtsig_test2.o
	$(CC) -o rtsig_test2 rtsig_test2.o $(AUPOBJS) $(LIBS) -pthread

alarm: alarm.o
	$(CC) -o alarm alarm.o $(AUPOBJS) $(LIBS)

itimer: itimer.o
	$(CC) -o itimer itimer.o $(AUPOBJS) $(LIBS)

time: time.o
	$(CC) -o time time.o $(AUPOBJS) $(LIBS)

all:  $(EXECS)
clean:
	rm -f *.o $(EXECS)
