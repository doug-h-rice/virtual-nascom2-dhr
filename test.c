/*
* Program: test.c - C program to compile to run on NASCOM 2 simulator
* usage: sdcc -mz80 --code-loc0x1000 --no-std-crt0 test.c
* gcc -Wall -c "%f"
*
* on hp:- 
* ../bin/sdcc -mz80 --code-loc0x1000 --no-std-crt0 test.c
*/
#include <stdio.h>

/* declarations */
void putchr( char x );
void putcharLF( void );
void putchar( char x );
void prs( void );
char rin( char x );

float x;

/* code seems to start here, when I run E1000 */

main(){
  char ip;
  ip = '+';
  while( 1 ) { 
    printf("\nHello\nprintf!\n%c\n",ip); 
    printf("\nHello\nprintf!\n%d\n",100); 
    printf("\nHello\nprintf!\n%f\n",22.0/7.0); 

    prs();
    putcharLF();
    ip = rin( ip );
  }
  return 1 ;
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

char rin( char x ){
/* call nascom software interupt */  
	__asm
    ; CRLF
    rst 8
    ; set up return value.
    LD  L,a
    ;LD  H,0x00
    ret
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

