CC=gcc
ICSOS_ROOT=../..
SDK=../../sdk
CFLAGS=-m32 -nostdlib -fno-builtin -static
LIBS=$(SDK)/tccsdk.c $(SDK)/libtcc1.c $(SDK)/crt1.c 
EXE=ttwist.exe

$(EXE): text-twist.c
	$(CC) $(CFLAGS) -o${EXE} text-twist.c $(LIBS)

install: $(EXE)
	cp $(EXE) $(ICSOS_ROOT)/apps

uninstall:
	rm $(ICSOS_ROOT)/apps/$(EXE)

clean:
	rm $(EXE)


