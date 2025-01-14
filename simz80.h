/* Header file for the instruction set simulator.
   Copyright (C) 1995  Frank D. Cringle.

This file is part of yaze - yet another Z80 emulator.

Yaze is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your
option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */

#include <limits.h>
#include <stdint.h>
#include <string.h>

#if UCHAR_MAX == 255
typedef uint8_t BYTE;
#else
#error Need to find an 8-bit type for BYTE
#endif

#if USHRT_MAX == 65535
typedef uint16_t WORD;
#else
#error Need to find an 16-bit type for WORD
#endif

/* FASTREG needs to be at least 16 bits wide and efficient for the
   host architecture */
#if UINT_MAX >= 65535
typedef unsigned int	FASTREG;
#else
typedef unsigned long	FASTREG;
#endif

/* FASTWORK needs to be wider than 16 bits and efficient for the host
   architecture */
#if UINT_MAX > 65535
typedef unsigned int	FASTWORK;
#else
typedef unsigned long	FASTWORK;
#endif

/* two sets of accumulator / flags */
extern WORD af[2];
extern int af_sel;

/* two sets of 16-bit registers */
extern struct ddregs {
	WORD bc;
	WORD de;
	WORD hl;
} regs[2];
extern int regs_sel;

extern WORD ir;
extern WORD ix;
extern WORD iy;
extern WORD sp;
extern WORD pc;
extern WORD IFF;

#ifndef MEMSIZE
#define MEMSIZE 64
#endif

//NOTE: ram[0x10000] = ram[0]; // Make GetWord[0xFFFF) work correctly
extern BYTE ram[MEMSIZE*1024+2];  // The +1 location is for the wraparound GetWord
#ifdef MMU
extern BYTE *pagetable[MEMSIZE/4];
#endif

#ifdef DEBUG
extern volatile int stopsim;
#endif

extern FASTWORK simz80(FASTREG PC, int, int (*)());

#define FLAG_C	1
#define FLAG_N	2
#define FLAG_P	4
#define FLAG_H	16
#define FLAG_Z	64
#define FLAG_S	128

#define SETFLAG(f,c)	AF = (c) ? AF | FLAG_ ## f : AF & ~FLAG_ ## f
#define TSTFLAG(f)	((AF & FLAG_ ## f) != 0)

#define ldig(x)		((x) & 0xf)
#define hdig(x)		(((x)>>4)&0xf)
#define lreg(x)		((x)&0xff)
#define hreg(x)		(((x)>>8)&0xff)

#define Setlreg(x, v)	x = (((x)&0xff00) | ((v)&0xff))
#define Sethreg(x, v)	x = (((x)&0xff) | (((v)&0xff) << 8))

#ifdef MMU
#define RAM(a)		*(pagetable[((a)&0xffff)>>12]+((a)&0x0fff))
#else
#define RAM(a)		ram[(a)&0xffff]
#endif

static inline unsigned char
GetBYTE(uint16_t a)
{
    return ram[a];
}

/* Fast write inside [3K; 64K-8K]

   NOTICE: This is dependent on the assumption that the 8KB Basic ROM
   is present
*/

void slow_write(unsigned int a, unsigned char v);
static inline void
PutBYTE(uint16_t a, uint16_t v)
{
    if (0x800 <= a && a < 0xE000)
        ram[a] = v;
}

/*#define PutBYTE(a, v)	RAM(a) = v*/

// Note, works even for 0xFFFF because we maintain ram[0] === ram[0x10000]
// Note: http://blog.regehr.org/archives/959
static inline uint16_t GetWORD(uint16_t a)
{
    uint16_t res;
    memcpy(&res, ram+a, 2);
    return res;
}

static inline void PutWORD(unsigned a, uint16_t v)
{
    if (0x800 <= a && a < 0xE000 - 1)
        memcpy(ram+a, &v, 2);
}

#ifndef BIOS
extern int in(unsigned int);
extern void out(unsigned int, unsigned char);
#define Input(port) in(port)
#define Output(port, value) out(port,value)
#else
/* Define these as macros or functions if you really want to simulate I/O */
#define Input(port)	0
#define Output(port, value)
#endif
