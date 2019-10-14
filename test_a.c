/*
* Program: test_a.c - C program to compile to run on NASCOM 2 simulator
*
*
* usage: sdcc -mz80 --code-loc0x1000 --no-std-crt0 test_a.c
* usage: sdcc -V -mz80 --code-loc0x1000 --no-std-crt0 test_a.c
* gcc -Wall -c "%f"
*
* on hp:- 
* ../bin/sdcc -mz80 --code-loc0x1000 --no-std-crt0 test_a.c
*
* There is a JavaScript NASCOM 2 simulator version that run in Chrome / Firefox browser. ( 22/11/2014 )
* http://thorn.ws/jsnascom/jsnascom.html  
* load test_a.ihx
*
*
*> sdcc -V -mz80 --code-loc0x1000 --no-std-crt0 test_a.c
*
*C:\Users\doug\Desktop\dev>sdcc -V -mz80 --code-loc0x1000 --no-std-crt0 test_a.c 
*+ C:\PROGRA~2\SDCC\bin\sdcpp.exe -nostdinc -Wall -obj-ext=.rel -D__SDCC_STACK_AUTO -DSDCC_STACK_AUTO -D__SDCC_INT_LONG_REENT -DSDCC_INT_LONG_REENT -D__SDCC_FLOAT_REENT -DSDCC_FLOAT_REENT -D__SDCC=3_2_0 -DSDCC=320 -D__SDCC_REVISION=8008 -DSDCC_REVISION=8008 -D__SDCC_z80 -DSDCC_z80 -D__z80 -D__STDC_NO_COMPLEX__ -D__STDC_NO_THREADS__ -D__STDC_NO_ATOMICS__ -D__STDC_NO_VLA__ -isystem "C:\Program Files (x86)\SDCC\bin\..\include\z80" -isystem "C:\Program Files (x86)\SDCC\bin\..\include"  "test_a.c" 
*+ C:\PROGRA~2\SDCC\bin\sdasz80.exe -plosgffw "test_a.rel" "test_a.asm"
*+ C:\PROGRA~2\SDCC\bin\sdldz80.exe -nf "test_a.lk"
*test_a.c:67: warning 126: unreachable code
*test_a.c:68: warning 126: unreachable code
*test_a.c:75: warning 85: in function putchr unreferenced function argument : 'x'*
*/
#include <stdio.h>

/* declarations */
void putchr( char x );
void putcharLF( void );
void putchar( char x );
void prs( void );
char rin( char x );
void retNAS_SYS( void );

float x;

/* code seems to start here, when I run E1000 */

main(){
  char ip;
  ip = '+';

    prs();
    printf("\n\nPress A,B,C,D...\n"); 

  while( 1 ) {
/* 
    printf("\nHello\nprintf!\n%c\n",ip); 
    printf("\nHello\nprintf!\n%d\n",100); 
    printf("\nHello\nprintf!\n%f\n",22.0/7.0); 

    prs();
*/
    putcharLF();
    ip = rin( ip );
    printf("\nHello\nprintf!\n%c\n",ip); 
    switch( ip ){
      case 'A' : { printf("Pressed away  \n",100);       break; }
      case 'B' : { printf("Pressed bug   \n",100);       break; }
      case 'C' : { printf("Pressed cat \n",100);       break; }
      case 'D' : { printf("Pressed doug \n",100);       break; }
      default  :  { printf("Pressed key %c \n",ip);       break; }
    }  
  }
// we never get here
  
  return 1 ;
  ;retNAS_SYS();
}

void putchr( char x ){
/* call nascom software interupt */  
	__asm
   	  RST	0x30;  		
	__endasm;
}

void putcharLF( void ){
/* call nascom software interupt */  
	__asm
    ; CRLF
    .db 0xDF 		
    .db 0x6A
	__endasm;
}

void putchar( char x ){
  /* call nascom software interupt */  
    if ( x == '\n' ){
      putcharLF();
    } else {
      putchr(x);
    }
}

/* 
 * have a simple function that adds one to x 
 * to see what assember is produced.
 */
 
char rin0( char x ){
	x = x + 10;
    return x ;
}
#ifdef comment
/*
 * the NASCOM functions leave the value in A.
 * make sure the compiler returns the value correctly.
 * 
 * The example below add  10 to X, which is on the stack.
 * x is put in A and 0x10 is added. it is then put back on the stack
 * 
 * the SDCC documentation says that the return value should be in L.
 * 
 * This seems to be different on different versions of SDCC
 * so check the .lst file for the generated code.
 * 
doug@doug-laptop:~/Downloads/sdcc$ ./bin/sdcc --version
SDCC : mcs51/gbz80/z80/z180/r2k/r3ka/ds390/pic16/pic14/TININative/ds400/hc08/s08 3.2.0 #8008 (Jul  6 2012) (Linux)
 * 
test_a.lst has:
                            269 ;	---------------------------------
                            270 ; Function rin0
                            271 ; ---------------------------------
   013D                     272 _rin0_start::
   013D                     273 _rin0:
                            274 ;test_a.c:104: x = x + 10;
   013D 21 02 00            275 	ld	hl,#2
   0140 39                  276 	add	hl,sp
   0141 7E                  277 	ld	a,(hl)
   0142 C6 0A               278 	add	a, #0x0A
   0144 77                  279 	ld	(hl),a
                            280 ;test_a.c:105: return x ;
   0145 FD 21 02 00         281 	ld	iy,#2
   0149 FD 39               282 	add	iy,sp
   014B FD 6E 00            283 	ld	l,0 (iy)
   014E C9                  284 	ret
   014F                     285 _rin0_end::
*/
#endif 

char rin( char x ){
/* call nascom software interupt */  
	__asm
    ; CRLF
    rst 8
    ; set up return value.
    LD  L,a
    ;LD  H,0x00
    ret
    ld 4 (ix),a
	__endasm;
    return x ;
}
char rin2( char x ){
/* call nascom software interupt */  
	__asm
    ; CRLF
    ;rst 8

    ; repeat keyboard.
    ;.db 0xDF 		
    ;.db 0x7d

    ; repeat keyboard.
    .db 0xDF 		
    .db 0x61

    ld 4 (ix),a
    
    ; set up return value.
    LD  L,a
    ;LD  H,0x00
    ret
	__endasm;
    return x ;
}

void prs( void ){
/* call nascom software interupt */  
	__asm
    .db 0xEF
    .ascii 'hello doug how are you?, NASCOM PRS '	
    .db 0x00
	__endasm;
}

void retNAS_SYS( void ){
/* call nascom software interupt */  
	__asm
    ; CRLF
    .db 0xDF 		
    .db 0x5B
	__endasm;
}

