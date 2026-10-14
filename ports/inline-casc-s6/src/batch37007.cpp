// batch37007.cpp - cascade s6 batch 37003: 0x620320.
#include "ff.h"

extern "C" void ext_634d22(u8 *dst, u8 *src, u32 n);   // memmove-style import thunk, cdecl
typedef u8 *(*alloc_t)(u32);
typedef u8 *(*realloc_t)(u8 *, u32);

// 0x620320, cdecl(self, str), returns the string start ([self+0x10], not advanced) or 0 when an allocation fails: appends the NUL-terminated
// string (terminator NOT copied; nothing happens for an empty string) to a chunked string buffer. self: +0 current chunk, +4 spare chunk, +8 end of room, +0xc write pointer,
// +0x10 start of the string being built, +0x14 allocator (slot 0 alloc(size), slot 4 realloc(ptr, size)). A chunk is {next, capacity, data...}.
static u8 *fn620320(u32 *self, u8 *str) {
  while (*str) {
    if (self[3] == self[2]) {
      u32 *spare = (u32 *)self[1];
      u32 end;
      bool grown = false;
      if (spare) {
        u32 start = self[4];
        if (!start) {
          self[0] = (u32)spare;
          self[1] = spare[0];
          spare[0] = 0;
          start = self[0] + 8;
          self[4] = start;
          self[3] = start;
          end = ((u32 *)self[0])[1] + start;
          grown = true;
        } else if ((s32)(self[2] - start) < (s32)spare[1]) {
          u32 nx = spare[0];
          spare[0] = self[0];
          self[0] = self[1];
          self[1] = nx;
          ext_634d22((u8 *)(self[0] + 8), (u8 *)self[4], self[2] - self[4]);
          u32 c = self[0];
          self[3] += (c - self[4]) + 8;
          self[4] = c + 8;
          end = ((u32 *)c)[1] + self[4];
          grown = true;
        }
      }
      if (!grown) {
        u32 cur0 = self[0];
        if (cur0 && self[4] == cur0 + 8) {
          u32 dbl = (self[2] - self[4]) * 2;
          u8 *p = ((realloc_t *)self[5])[1]((u8 *)cur0, dbl + 8);
          self[0] = (u32)p;
          if (!p) return 0;
          ((u32 *)p)[1] = dbl;
          self[3] += ((u32)p - self[4]) + 8;
          self[4] = (u32)p + 8;
          end = self[4] + dbl;
        } else {
          s32 n = (s32)(self[2] - self[4]);
          s32 sz = 0x400;
          if (n >= 0x400) sz = n + n;
          u8 *p = ((alloc_t *)self[5])[0]((u32)sz + 8);
          if (!p) return 0;
          ((u32 *)p)[1] = (u32)sz;
          ((u32 *)p)[0] = self[0];
          u32 cur = self[3], st = self[4];
          self[0] = (u32)p;
          if (cur != st) ext_634d22(p + 8, (u8 *)st, cur - st);
          self[3] += ((u32)p - self[4]) + 8;
          self[4] = (u32)p + 8;
          end = (u32)p + 8 + (u32)sz;
        }
      }
      self[2] = end;
    }
    *(u8 *)self[3] = *str;
    self[3]++;
    str++;
  }
  return (u8 *)self[4];
}
PCREG(620320, fn620320);
