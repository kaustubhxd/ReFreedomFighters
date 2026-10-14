// batch37012.cpp - cascade s6 batch 37012: 0x61c3d0.
#include "ff.h"

extern "C" void ext_620670(u8 *p);              // cdecl, 1 arg
extern "C" void ext_61f0d0(u8 *p, u8 *ctx);     // cdecl, 2 args
typedef void(*free_t)(void *);
typedef void(*fn1_t)(u32);

#define W(o) (*(u32 *)(ctx + (o)))
#define FREE(p) ((*(free_t *)(ctx + 0x14))((void *)(p)))

// 0x61c3d0, cdecl(ctx): tears down a context. Pops every node of the list at +0x204 (refilling it from +0x208), freeing the node's data (+0x18), its sublist
// (+0x20, elements {.., next +4, data +0x10}) and the node, then frees the lists at +0x210 and +0x20c, runs 0x620670 on two sub-objects, swaps the 0x2a-dword
// block at +0x158 with the one in the object at +0x270, runs 0x61f0d0 on it, frees the owned buffers and finally the context itself. ctx+0x14 is the free function.
static void fn61c3d0(u8 *ctx) {
  for (;;) {
    if (W(0x204) == 0) {
      u32 n = W(0x208);
      if (!n) break;
      W(0x204) = n;
      W(0x208) = 0;
    }
    u8 *node = (u8 *)W(0x204);
    W(0x204) = *(u32 *)node;
    FREE(*(u32 *)(node + 0x18));
    u8 *sub = (u8 *)*(u32 *)(node + 0x20);
    while (sub) {
      u8 *nx = (u8 *)*(u32 *)(sub + 4);
      FREE(*(u32 *)(sub + 0x10));
      FREE(sub);
      sub = nx;
    }
    FREE(node);
  }
  u8 *l = (u8 *)W(0x210);
  while (l) {
    u8 *nx = (u8 *)*(u32 *)(l + 4);
    FREE(*(u32 *)(l + 0x10));
    FREE(l);
    l = nx;
  }
  l = (u8 *)W(0x20c);
  while (l) {
    u8 *nx = (u8 *)*(u32 *)(l + 4);
    FREE(*(u32 *)(l + 0x10));
    FREE(l);
    l = nx;
  }
  ext_620670(ctx + 0x22c);
  ext_620670(ctx + 0x244);
  u8 *o = (u8 *)W(0x270);
  if (o) {
    if (W(0x264)) W(0x1c0) = 0;
    u32 tmp[0x2a];
    for (int i = 0; i < 0x2a; i++) tmp[i] = *(u32 *)(ctx + 0x158 + 4 * i);
    for (int i = 0; i < 0x2a; i++) *(u32 *)(ctx + 0x158 + 4 * i) = *(u32 *)(o + 0x158 + 4 * i);
    for (int i = 0; i < 0x2a; i++) *(u32 *)(o + 0x158 + 4 * i) = tmp[i];
  }
  ext_61f0d0(ctx + 0x158, ctx);
  FREE(W(0x220));
  if (W(0x25c)) FREE(W(0x25c));
  if (W(8)) FREE(W(8));
  FREE(W(0x2c));
  if (W(0xf0)) FREE(W(0xf0));
  if (W(0xfc)) ((fn1_t)W(0xfc))(W(0xf4));
  FREE(ctx);
}
PCREG(61c3d0, fn61c3d0);
