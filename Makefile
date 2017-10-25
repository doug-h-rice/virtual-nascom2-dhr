# Makefile for Virtual Nascom

# CC must be an C99 compiler
CC=gcc -std=c99

# full speed or debugging to taste
OPTIMIZE=-O2
#OPTIMIZE=-g
#WARN=-Wmost -Werror
WARN=-Wall -Wno-parentheses
CFLAGS=$(OPTIMIZE) $(WARN) $(shell sdl-config --cflags)

# SDL 2
srcdir  = .
CC      = gcc
#CC		=gcc -std=c99
EXE	= 
#CFLAGS  = -g -O2 -D_REENTRANT -I/usr/local/include/SDL2  -I/opt/vc/include -I/opt/vc/include/interface/vcos/pthreads -I/opt/vc/include/interface/vmcs_host/linux -DHAVE_OPENGLES -DHAVE_OPENGLES2 -DHAVE_OPENGL -g
CFLAGS  = -g -O2 -D_REENTRANT -I/usr/local/include/SDL2 -I/usr/include/SDL2 -I/opt/vc/include -I/opt/vc/include/interface/vcos/pthreads -I/opt/vc/include/interface/vmcs_host/linux -DHAVE_OPENGLES -DHAVE_OPENGLES2 -DHAVE_OPENGL -g
LIBS	=  -lSDL2_test -L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL2

virtual-nascom-sdl2: virtual-nascom-sdl2.o font.o simz80.o ihex.o
	$(CC) $(CWARN)  $^ -o $@ -lSDL2
	

clean:
	rm -f *.o *~ core
