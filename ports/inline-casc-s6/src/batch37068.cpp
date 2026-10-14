// batch37068.cpp - cascade s6 batch 37068: 0x5ff140.
#include "ff.h"

extern "C" void THISCALL ext_5ff0a0(u8 *vec);                  // grows a u16 vector (plain ret)
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 bytes);  // allocate
extern "C" void __attribute__((cdecl)) ext_41e2c0(void *p);     // free

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5ff140, stdcall(vecA, vecB, ctx, targetA, targetB, startB, startA) ret 0x1c, returns bool. ctx: +0xe0 table of u32 keys, +0xf8 table of u16 "next" links (0xffff ends a chain).
// Vectors are {u16 *data, capacity, size}. Walks the chain from startA: stops with 1 when a node's key equals targetA, otherwise appends the node to vecA. Then walks the chain from
// startB: stops with 1 (and clears vecA) when a key equals targetB; a node already in vecA truncates vecA to that node's index and returns 1; otherwise the node is appended to vecB
// (doubling its storage when full). Returns 0 when both chains end without a hit.
static u8 STDCALL fn5ff140(u8 *va, u8 *vb, u8 *ctx, u32 targetA, u32 targetB, u16 startB, u16 startA) {
  u32 n = startA;
  while ((u16)n != 0xffff) {
    if (((u32 *)D32(ctx, 0xe0))[n & 0xffff] == targetA) return 1;
    if (D32(va, 8) >= D32(va, 4)) ext_5ff0a0(va);
    ((u16 *)D32(va, 0))[D32(va, 8)] = (u16)n;
    D32(va, 8)++;
    n = ((u16 *)D32(ctx, 0xf8))[n & 0xffff];
  }
  u32 m = startB;
  while ((u16)m != 0xffff) {
    u32 mi = m & 0xffff;
    if (((u32 *)D32(ctx, 0xe0))[mi] == targetB) {
      D32(va, 8) = 0;
      return 1;
    }
    u32 size = D32(va, 8);
    u32 idx = 0;
    bool found = false;
    if (size) {
      u16 *d = (u16 *)D32(va, 0);
      for (idx = 0; idx < size; idx++) {
        if (d[idx] == (u16)m) { found = true; break; }
      }
    }
    if (found) {
      if (size - idx != 0) D32(va, 8) = size - (size - idx);
      return 1;
    }
    if (D32(vb, 8) >= D32(vb, 4)) {
      u32 newcap = D32(vb, 4) * 2;
      u16 *old = (u16 *)D32(vb, 0);
      u64 bytes = (u64)newcap * 2;
      D32(vb, 0) = (u32)ext_41e290((bytes >> 32) ? 0xffffffffu : (u32)bytes);
      for (u32 i = 0; i < D32(vb, 4); i++) ((u16 *)D32(vb, 0))[i] = old[i];
      ext_41e2c0(old);
      D32(vb, 4) = newcap;
    }
    ((u16 *)D32(vb, 0))[D32(vb, 8)] = (u16)m;
    D32(vb, 8)++;
    m = ((u16 *)D32(ctx, 0xf8))[mi];
  }
  return 0;
}
PCREG(5ff140, fn5ff140);
