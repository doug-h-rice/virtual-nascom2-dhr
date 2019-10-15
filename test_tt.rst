                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.5.0 #9253 (Mar 19 2016) (Linux)
                              4 ; This file was generated Tue Oct 15 21:58:45 2019
                              5 ;--------------------------------------------------------
                              6 	.module test_tt
                              7 	.optsdcc -mz80
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _rin0
                             13 	.globl _main
                             14 	.globl _scrptr2
                             15 	.globl _scrptr
                             16 	.globl _scrchar
                             17 	.globl _x
                             18 	.globl _putchr
                             19 	.globl _putcharLF
                             20 	.globl _putchar
                             21 	.globl _rin
                             22 	.globl _prs
                             23 	.globl _retNAS_SYS
                             24 ;--------------------------------------------------------
                             25 ; special function registers
                             26 ;--------------------------------------------------------
                             27 ;--------------------------------------------------------
                             28 ; ram data
                             29 ;--------------------------------------------------------
                             30 	.area _DATA
   8000                      31 _x::
   8000                      32 	.ds 4
                     0BCA    33 _scrchar	=	0x0bca
                     0BCC    34 _scrptr	=	0x0bcc
                     0BD2    35 _scrptr2	=	0x0bd2
                             36 ;--------------------------------------------------------
                             37 ; ram data
                             38 ;--------------------------------------------------------
                             39 	.area _INITIALIZED
                             40 ;--------------------------------------------------------
                             41 ; absolute external ram data
                             42 ;--------------------------------------------------------
                             43 	.area _DABS (ABS)
                             44 ;--------------------------------------------------------
                             45 ; global & static initialisations
                             46 ;--------------------------------------------------------
                             47 	.area _HOME
                             48 	.area _GSINIT
                             49 	.area _GSFINAL
                             50 	.area _GSINIT
                             51 ;--------------------------------------------------------
                             52 ; Home
                             53 ;--------------------------------------------------------
                             54 	.area _HOME
                             55 	.area _HOME
                             56 ;--------------------------------------------------------
                             57 ; code
                             58 ;--------------------------------------------------------
                             59 	.area _CODE
                             60 ;test_tt.c:36: main(){
                             61 ;	---------------------------------
                             62 ; Function main
                             63 ; ---------------------------------
   1000                      64 _main::
                             65 ;test_tt.c:40: ip = '+';
   1000 16 2B         [ 7]   66 	ld	d,#0x2B
                             67 ;test_tt.c:41: scrchar = ip;
   1002 21 CA 0B      [10]   68 	ld	hl,#_scrchar + 0
   1005 36 2B         [10]   69 	ld	(hl), #0x2B
                             70 ;test_tt.c:43: scrptr[0] = 'D';
   1007 21 CC 0B      [10]   71 	ld	hl,#_scrptr+0
   100A 36 44         [10]   72 	ld	(hl),#0x44
                             73 ;test_tt.c:44: scrptr[1] = 'o';
   100C 21 CD 0B      [10]   74 	ld	hl,#_scrptr+1
   100F 36 6F         [10]   75 	ld	(hl),#0x6F
                             76 ;test_tt.c:45: scrptr[2] = 'u';
   1011 21 CE 0B      [10]   77 	ld	hl,#_scrptr+2
   1014 36 75         [10]   78 	ld	(hl),#0x75
                             79 ;test_tt.c:46: scrptr[3] = 'g';
   1016 21 CF 0B      [10]   80 	ld	hl,#_scrptr+3
   1019 36 67         [10]   81 	ld	(hl),#0x67
                             82 ;test_tt.c:48: while( 1 ) {
   101B                      83 00102$:
                             84 ;test_tt.c:49: scrptr[0] = 'D';
   101B 21 CC 0B      [10]   85 	ld	hl,#_scrptr+0
   101E 36 44         [10]   86 	ld	(hl),#0x44
                             87 ;test_tt.c:50: scrptr[1] = 'o';
   1020 21 CD 0B      [10]   88 	ld	hl,#_scrptr+1
   1023 36 6F         [10]   89 	ld	(hl),#0x6F
                             90 ;test_tt.c:51: scrptr[2] = 'u';
   1025 21 CE 0B      [10]   91 	ld	hl,#_scrptr+2
   1028 36 75         [10]   92 	ld	(hl),#0x75
                             93 ;test_tt.c:52: scrptr[3] = 'g';
   102A 21 CF 0B      [10]   94 	ld	hl,#_scrptr+3
   102D 36 67         [10]   95 	ld	(hl),#0x67
                             96 ;test_tt.c:53: ip = rin( ip );
   102F D5            [11]   97 	push	de
   1030 33            [ 6]   98 	inc	sp
   1031 CD 97 10      [17]   99 	call	_rin
   1034 33            [ 6]  100 	inc	sp
   1035 55            [ 4]  101 	ld	d,l
                            102 ;test_tt.c:54: strcpy(scrptr2,"hello doug how are you?");
   1036 21 52 10      [10]  103 	ld	hl,#___str_0
   1039 D5            [11]  104 	push	de
   103A 11 D2 0B      [10]  105 	ld	de,#_scrptr2
   103D AF            [ 4]  106 	xor	a, a
   103E                     107 00110$:
   103E BE            [ 7]  108 	cp	a, (hl)
   103F ED A0         [16]  109 	ldi
   1041 20 FB         [12]  110 	jr	NZ, 00110$
   1043 D1            [10]  111 	pop	de
                            112 ;test_tt.c:55: putchar( ip );
   1044 D5            [11]  113 	push	de
   1045 D5            [11]  114 	push	de
   1046 33            [ 6]  115 	inc	sp
   1047 CD 6F 10      [17]  116 	call	_putchar
   104A 33            [ 6]  117 	inc	sp
   104B D1            [10]  118 	pop	de
                            119 ;test_tt.c:56: scrchar = ip;
   104C 21 CA 0B      [10]  120 	ld	hl,#_scrchar + 0
   104F 72            [ 7]  121 	ld	(hl), d
                            122 ;test_tt.c:62: ;retNAS_SYS();
   1050 18 C9         [12]  123 	jr	00102$
   1052                     124 ___str_0:
   1052 68 65 6C 6C 6F 20   125 	.ascii "hello doug how are you?"
        64 6F 75 67 20 68
        6F 77 20 61 72 65
        20 79 6F 75 3F
   1069 00                  126 	.db 0x00
                            127 ;test_tt.c:65: void putchr( char x ){
                            128 ;	---------------------------------
                            129 ; Function putchr
                            130 ; ---------------------------------
   106A                     131 _putchr::
                            132 ;test_tt.c:69: __endasm;
   106A F7            [11]  133 	RST 0x30;
   106B C9            [10]  134 	ret
                            135 ;test_tt.c:72: void putcharLF( void ){
                            136 ;	---------------------------------
                            137 ; Function putcharLF
                            138 ; ---------------------------------
   106C                     139 _putcharLF::
                            140 ;test_tt.c:78: __endasm;
                            141 ; CRLF
   106C DF                  142 	.db 0xDF
   106D 6A                  143 	.db 0x6A
   106E C9            [10]  144 	ret
                            145 ;test_tt.c:81: void putchar( char x ){
                            146 ;	---------------------------------
                            147 ; Function putchar
                            148 ; ---------------------------------
   106F                     149 _putchar::
                            150 ;test_tt.c:83: if ( x == '\n' ){
   106F 21 02 00      [10]  151 	ld	hl, #2+0
   1072 39            [11]  152 	add	hl, sp
   1073 7E            [ 7]  153 	ld	a, (hl)
   1074 D6 0A         [ 7]  154 	sub	a, #0x0A
                            155 ;test_tt.c:84: putcharLF();
   1076 CA 6C 10      [10]  156 	jp	Z,_putcharLF
                            157 ;test_tt.c:86: putchr(x);
   1079 21 02 00      [10]  158 	ld	hl, #2+0
   107C 39            [11]  159 	add	hl, sp
   107D 7E            [ 7]  160 	ld	a, (hl)
   107E F5            [11]  161 	push	af
   107F 33            [ 6]  162 	inc	sp
   1080 CD 6A 10      [17]  163 	call	_putchr
   1083 33            [ 6]  164 	inc	sp
   1084 C9            [10]  165 	ret
                            166 ;test_tt.c:95: char rin0( char x ){
                            167 ;	---------------------------------
                            168 ; Function rin0
                            169 ; ---------------------------------
   1085                     170 _rin0::
                            171 ;test_tt.c:96: x = x + 10;
   1085 21 02 00      [10]  172 	ld	hl,#2
   1088 39            [11]  173 	add	hl,sp
   1089 7E            [ 7]  174 	ld	a,(hl)
   108A C6 0A         [ 7]  175 	add	a, #0x0A
   108C 77            [ 7]  176 	ld	(hl),a
                            177 ;test_tt.c:97: return x ;
   108D FD 21 02 00   [14]  178 	ld	iy,#2
   1091 FD 39         [15]  179 	add	iy,sp
   1093 FD 6E 00      [19]  180 	ld	l,0 (iy)
   1096 C9            [10]  181 	ret
                            182 ;test_tt.c:100: char rin( char x ){
                            183 ;	---------------------------------
                            184 ; Function rin
                            185 ; ---------------------------------
   1097                     186 _rin::
                            187 ;test_tt.c:110: __endasm;
                            188 ; CRLF
   1097 CF            [11]  189 	rst 8
                            190 ; set up return value.
   1098 6F            [ 4]  191 	LD L,a
                            192 ;LD H,0x00
   1099 C9            [10]  193 	ret
   109A DD 77 04      [19]  194 	ld 4 (ix),a
                            195 ;test_tt.c:111: return x ;
   109D FD 21 02 00   [14]  196 	ld	iy,#2
   10A1 FD 39         [15]  197 	add	iy,sp
   10A3 FD 6E 00      [19]  198 	ld	l,0 (iy)
   10A6 C9            [10]  199 	ret
                            200 ;test_tt.c:114: void prs( void ){
                            201 ;	---------------------------------
                            202 ; Function prs
                            203 ; ---------------------------------
   10A7                     204 _prs::
                            205 ;test_tt.c:120: __endasm;
   10A7 EF                  206 	.db 0xEF
   10A8 68 65 6C 6C 6F 20   207 	.ascii 'hello doug how are you?, NASCOM PRS '
        64 6F 75 67 20 68
        6F 77 20 61 72 65
        20 79 6F 75 3F 2C
        20 4E 41 53 43 4F
        4D 20 50 52 53 20
   10CC 00                  208 	.db 0x00
   10CD C9            [10]  209 	ret
                            210 ;test_tt.c:123: void retNAS_SYS( void ){
                            211 ;	---------------------------------
                            212 ; Function retNAS_SYS
                            213 ; ---------------------------------
   10CE                     214 _retNAS_SYS::
                            215 ;test_tt.c:129: __endasm;
                            216 ; CRLF
   10CE DF                  217 	.db 0xDF
   10CF 5B                  218 	.db 0x5B
   10D0 C9            [10]  219 	ret
                            220 	.area _CODE
                            221 	.area _INITIALIZER
                            222 	.area _CABS (ABS)
