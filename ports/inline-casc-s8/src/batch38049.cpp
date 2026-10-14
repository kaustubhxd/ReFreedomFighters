// batch38049.cpp - cascade s8 batch 38049: 0x620180 (refill a chunked output buffer from a reader).
#include "ff.h"

extern "C" u32 ext_6206e0(u8 *s);                         // cdecl: initial setup of the buffer
extern "C" void ext_634d22(void *dst, const void *src, u32 n);   // memcpy, cdecl
typedef void (*read_t)(void *src, u32 *got, u32 want, u32 *off, u32 end);   // cdecl, 5 args
typedef u8 *(*alloc_t)(u32 size);                          // cdecl
typedef u8 *(*realloc_t)(u8 *p, u32 size);                 // cdecl
#define F(off) (*(u32 *)(S + (off)))

// 0x620180, cdecl(S, src, got, want). S is a chunked output buffer: +0 current chunk, +4 free chunk list, +8 end of the usable area, +0xc running offset, +0x10 cursor, +0x14 -> {alloc, realloc}
// callbacks; a chunk is {next, size, data...}. Starts the reader (function pointer at src+0x3c) with the free space and, while it has not delivered `want`, makes room: reuses a free chunk (copying the unread tail
// into it when the current one is too small), grows the current chunk in place with realloc, or allocates a new chunk of max(0x400, 2 * remaining) bytes, then calls the reader again with the new end.
// Returns the cursor (0 when an allocation fails).
static u32 fn620180(u8 *S, u8 *src, u32 got, u32 want) {
  if (F(0xc) == 0) {
    if (!ext_6206e0(S)) return 0;
  }
  read_t rd = *(read_t *)(src + 0x3c);
  rd(src, &got, want, (u32 *)(S + 0xc), F(8));
  if (got == want) return F(0x10);
  for (;;) {
    u32 edx = F(4);
    u32 end;
    bool made = false;
    if (edx) {
      u32 ecx = F(0x10);
      if (ecx == 0) {
        F(0) = edx;
        F(4) = *(u32 *)edx;
        *(u32 *)edx = 0;
        ecx = F(0) + 8;
        F(0x10) = ecx;
        end = *(u32 *)(F(0) + 4) + ecx;
        F(0xc) = ecx;
        made = true;
      } else if ((s32)(F(8) - ecx) < (s32) * (u32 *)(edx + 4)) {
        u32 nxt = *(u32 *)edx;
        *(u32 *)edx = F(0);
        F(0) = F(4);
        F(4) = nxt;
        ext_634d22((void *)(F(0) + 8), (const void *)F(0x10), F(8) - F(0x10));
        u32 e2 = F(0);
        F(0xc) += e2 - F(0x10) + 8;
        F(0x10) = e2 + 8;
        end = *(u32 *)(e2 + 4) + e2 + 8;
        made = true;
      }
    }
    if (!made) {
      u32 e0 = F(0);
      if (e0 && F(0x10) == e0 + 8) {
        u32 sz = (F(8) - F(0x10)) * 2;
        u8 *cb = *(u8 **)(S + 0x14);
        u8 *np = (*(realloc_t *)(cb + 4))((u8 *)e0, sz + 8);
        F(0) = (u32)np;
        if (!np) return 0;
        *(u32 *)(np + 4) = sz;
        u32 c0 = F(0);
        F(0xc) += c0 - F(0x10) + 8;
        F(0x10) = c0 + 8;
        end = c0 + 8 + sz;
      } else {
        u32 sz = F(8) - F(0x10);
        sz = (s32)sz < 0x400 ? 0x400 : sz * 2;
        u8 *cb = *(u8 **)(S + 0x14);
        u8 *np = (*(alloc_t *)cb)(sz + 8);
        if (!np) return 0;
        *(u32 *)(np + 4) = sz;
        *(u32 *)np = F(0);
        u32 off = F(0xc), cur = F(0x10);
        F(0) = (u32)np;
        if (off != cur) ext_634d22(np + 8, (const void *)cur, off - cur);
        F(0xc) += (u32)np - F(0x10) + 8;
        F(0x10) = (u32)np + 8;
        end = sz + 8 + (u32)np;
      }
    }
    F(8) = end;
    rd(src, &got, want, (u32 *)(S + 0xc), end);
    if (got == want) break;
  }
  return F(0x10);
}
PCREG(620180, fn620180);
