/*   VirtualNascom, a Nascom II emulator.
 
   Copyright (C) 2000  Tommy Thorn
   Copyright (C) 1995,1998  Frank D. Cringle.

NasEmu is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your
option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.



   A Nascom consists of:

    - a Z80 CPU,
    - an UART,
    - a bitmapped keyboard,
    - memory:
        0000 - 07ff  2 KB ROM monitor,
        0800 - 0bff  1 KB screen memory,
        0c00 - 0fff  1 KB workspace
        1000 - dfff       memory
        e000 - ffff  8 KB of MS Basic

  With the Z80 emulator in place the first thing to get working is the
  screen memory.  The "correct" way to simulate screen memory is to
  trap upon writes, but that would be slow.  We do it any just to get
  started.


  */

#include <stdio.h>

#include "simz80.h"
#include "xvirtualnascom.h"

#define INSCREEN(x) (((x) >> 10) == 2)

unsigned char keym[9] = 
{
  0,  /* ? ? ? Shift ? ? ? ? */
  0,  /* ?!TXF5BH  ! = Up*/
  0,  /* ?!YZD6NJ  ! = Left*/
  0,  /* ?!USE7MK  ! = Down */
  0,  /* ?!IAW8,L  ! = Right */
  0,  /* ??OQ39.; */
  0,  /* ?[P120/: */
  0,  /* ?]R C4VG */
  0   /* ? ? CR - Newline BS */
};

unsigned char keyp = 0;
unsigned char port0;

void out(unsigned int port, unsigned char value)
{
  unsigned int down_trans;

  if (0) fprintf(stdout, "[%02x] <- %02x\n", port, value);

  switch (port) {
  case 0:
    /* KBD */
    down_trans = port0 & ~value;
    port0 = value;

    if ((1 & down_trans) && keyp < 9) keyp++;
    if (2 & down_trans) keyp = 0;
    break;

  default: ;
  }
}

int in(unsigned int port)
{
  if (0) fprintf(stdout, "<- [%02x]\n", port);

  switch (port) {
  case 0:
    /* KBD */
    /* printf("[%d]", keyp); */
    return ~keym[keyp];
  case 2:
    /* Status port on the UART */
    return 0;
  default:
    return 0;
  }
}

void slow_write(unsigned int a, unsigned char v)
{
  if (INSCREEN(a)) 
    {
      unsigned int y = (a-0x800) / 64;
      unsigned int x = (a-0x800) % 64;
      /* fprintf(stdout, "putbyte %04x %02x '%c'\n", a, v, v); */
      if (10 <= x && x < 58 && ' ' <= v) {
	if (y == 15)
	  y = 0;
	else
	  ++y;

	xputch(x-10, y, v);
      }
    }
  if (0x800 <= a && a <= 0xE000)
    RAM(a) = v;
}
