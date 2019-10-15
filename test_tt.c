/*
* Program: test_tt.c - C program to compile to run on NASCOM 2 simulator
*
*
* usage: sdcc -mz80 --code-loc0x1000 --no-std-crt0 test_tt.c
*	sdcc -V -mz80 --code-loc 0x1000  --no-std-crt0  test_tt.c
*	sdldz80 -u -nf test_tt.lk
*
*
* There is a JavaScript NASCOM 2 simulator version that run in Chrome / Firefox browser. ( 22/11/2014 )
* http://thorn.ws/jsnascom/jsnascom.html  
* load test_tt.ihx
*
*/



#include <stdio.h>
#include <string.h>
/* declarations */
void putchr( char x );
void putcharLF( void );
void putchar( char x );
void prs( void );
char rin( char x );
void retNAS_SYS( void );

float x;

  char   __at ( 0x0BCA ) scrchar;
  char   __at ( 0x0BCC ) scrptr[8];
  char   __at ( 0x0BD2 ) scrptr2[64];

/* code seems to start here, when I run E1000 */

main(){

 
  char ip;
  ip = '+';
  scrchar = ip;

    scrptr[0] = 'D';
    scrptr[1] = 'o';
    scrptr[2] = 'u';
    scrptr[3] = 'g';
    
  while( 1 ) {
    scrptr[0] = 'D';
    scrptr[1] = 'o';
    scrptr[2] = 'u';
    scrptr[3] = 'g';
    ip = rin( ip );
    strcpy(scrptr2,"hello doug how are you?");
    putchar( ip );
    scrchar = ip;
  }  


  
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

