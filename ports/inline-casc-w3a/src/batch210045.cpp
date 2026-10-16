// batch210045.cpp - Sonnet-w3a: small BLOCKED rows (chunked list cursor walks with a stack cursor advanced by slots)
#include "ff.h"

struct Cur { u32 *p; u32 idx; u8 *chunk; };  // cursor words in memory order: element slot pointer, index, chunk

static u32 THISCALL fn6404d0(u8 *self) {
  u32 cur[3];
  vcall<u32, u32 *>(self + 0x1f0, 0xc, cur);  // @6404d0_a
  u32 edx = cur[0];
  if (!edx) return 0;
  do {
    u8 *elem = *(u8 **)edx;
    if (*(u32 *)(elem + 0x38) == 0 || !(elem[5] & 1)) {  // @6404d0_b
      vcall<u32, u32 *>(self + 0x1f0, 0x10, cur);  // @6404d0_c
    } else {
      u32 idx = cur[1] + 1;
      cur[1] = idx;
      u8 *chunk = (u8 *)cur[2];
      if (idx != *(u32 *)chunk) {  // @6404d0_d
        cur[0] = edx + 4;  // @6404d0_e
      } else {
        u8 *next = *(u8 **)(chunk + 8);
        cur[2] = (u32)next;
        if (!next) cur[0] = 0;  // @6404d0_f
        else {
          cur[1] = 0;
          cur[0] = (u32)(next + 0x10);  // @6404d0_g
        }
      }
      vcall<u32, u8 *>(self, 0x80, elem);  // @6404d0_h
    }
    edx = cur[0];
  } while (edx);
  return 0;
}
PCREG(6404d0, fn6404d0);

static u32 THISCALL fn640450(u8 *self) {
  u32 cur[3];
  vcall<u32, u32 *>(self + 0x1dc, 0xc, cur);  // @640450_a
  u32 ecx = cur[0];
  if (!ecx) return 0;
  u32 edx = cur[2], esi = cur[1];
  for (;;) {
    u8 *elem = *(u8 **)ecx;
    if (elem[5] & 1) {  // @640450_b
      esi++;
      cur[1] = esi;
      if (esi != *(u32 *)edx) {  // @640450_c
        ecx += 4;  // @640450_d
      } else {
        edx = *(u32 *)(edx + 8);
        cur[2] = edx;
        if (!edx) return 0;  // @640450_e
        esi = 0;
        ecx = edx + 0x10;  // @640450_f
        cur[1] = 0;
      }
      cur[0] = ecx;
    } else {
      vcall<u32, u32 *>(self + 0x1dc, 0x10, cur);  // @640450_g
      edx = cur[2];
      esi = cur[1];
      ecx = cur[0];
    }
    if (!ecx) return 0;
  }
}
PCREG(640450, fn640450);
