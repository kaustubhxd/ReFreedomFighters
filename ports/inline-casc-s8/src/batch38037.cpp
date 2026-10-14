// batch38037.cpp - cascade s8 batch 38037: 0x619c20 (draw one batch entry: set transform, render state and buffers).
#include "ff.h"

extern "C" void THISCALL ext_441730(u8 *g);                                   // plain ret
extern "C" void THISCALL ext_440530(u8 *g);                                   // plain ret
extern "C" void FASTCALL ext_4de440(void *out, u8 *p, u8 *q);                 // ret 4
extern "C" void FASTCALL ext_441970(void *out, u8 *p, u8 *q);                 // ret 4
extern "C" void FASTCALL ext_441940(void *out, u8 *p);                        // plain ret
extern "C" void THISCALL ext_610070(u8 *y, u32 f);                            // ret 4 (float arg 0.0)
extern "C" void THISCALL ext_6107e0(u8 *y, u32 a);                            // ret 4
extern "C" void FASTCALL ext_61a6b0(u8 *a, u8 *b);                            // plain ret
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(STDCALL *d3_t)(void *, u32, u32);
typedef u32(STDCALL *d4_t)(void *, u32, u32, u32);
typedef u32(STDCALL *d2_t)(void *, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define GV(a) G(u32, a)
#define DEV G(u8 *, 0x724a00)

// 0x619c20, thiscall(item, target) ret 8. Draws one entry of a batch (this[0xc] entries, this[4]+0xc the current record): begins the timer scope (0x441730 / 0x440530 on the object at 0x6bde8c),
// sends the record's three fields to target slot 0x29c, picks the item's transform source S (item[0xc] over item[0x14][0xc] over item[0x14][8]+8) and either builds the two matrices through
// the 0x4de440 / 0x441970 / 0x441940 helpers (when neither item nor its owner has flag bit 4 in byte +5) or uses S directly, sets the scale with 0x610070(0.0), draws through target slot 0x28c
// (matrix, matrix, 0), applies 0x6107e0 and then updates cached device state (render state 0x89 cleared when target flag +0x115f bit 1, state 0x152, stage 0x24, buffers) only when it differs.
static void THISCALL fn619c20(u8 *self, u8 *item, u8 *y) {
  if (*(u32 *)(self + 0xc) == 0) return;
  u8 *p = *(u8 **)(self + 4) + 0xc;
  if (*(u32 *)(p + 8) == 0) return;
  ext_441730((u8 *)0x6bde8c);
  u8 *rec = *(u8 **)(*(u8 **)(*(u8 **)(self + 4) + 4) + 8);
  SLOT(y, 0x29c, v3_t)(y, *(u32 *)(rec + 0x20), *(u32 *)(rec + 0x38), *(u32 *)(rec + 0x44));
  u8 *d = *(u8 **)(item + 0x14);
  u32 w = *(u32 *)(item + 0x28);
  u32 r20 = *(u32 *)(d + 0x20);
  u8 *s = *(u8 **)(d + 8) + 8;
  if (*(u32 *)(d + 0xc)) s = *(u8 **)(d + 0xc);
  if (*(u32 *)(item + 0xc)) s = *(u8 **)(item + 0xc);
  if (!(item[5] & 4) && !(d[5] & 4)) {
    u8 l34[0x24], l10[0xc];
    u8 *e = (u8 *)(r20 + 0x10);
    ext_4de440(l34, s, e);
    ext_441970(l10, s + 0x24, e);
    ext_441940(l10, (u8 *)(r20 + 0x34));
    ext_610070(y, 0);
    SLOT(y, 0x28c, v3_t)(y, (u32)l34, (u32)l10, 0);
  } else {
    ext_610070(y, 0);
    SLOT(y, 0x28c, v3_t)(y, (u32)s, (u32)(s + 0x24), 0);
  }
  ext_6107e0(y, w);
  if ((y[0x115f] & 2) && GV(0x724948) != 0) {
    u8 *dev = DEV;
    GV(0x724948) = 0;
    SLOT(dev, 0xc8, d3_t)(dev, 0x89, 0);
  }
  u8 *esi = *(u8 **)(y + 0x13fa);
  u8 *edi = *(u8 **)(y + 0x140a);
  if (GV(0x7249f8) != 0x152) {
    u8 *dev = DEV;
    GV(0x7249f8) = 0x152;
    SLOT(dev, 0x130, d2_t)(dev, 0x152);
  }
  if (*(u32 *)(esi + 0x30)) {
    SLOT(esi, 8, v0_t)(esi);
    *(u32 *)(esi + 0x30) = 0;
  }
  u32 edx = *(u32 *)(esi + 0x2c);
  if (GV(0x724970) != edx || GV(0x7249b0) != 0x24) {
    u8 *dev = DEV;
    GV(0x724970) = edx;
    GV(0x7249b0) = 0x24;
    SLOT(dev, 0x14c, d4_t)(dev, 0, edx, 0x24);
  }
  u32 cnt = *(u32 *)(self + 0xc);
  if (*(u32 *)(edi + 0x18)) {
    SLOT(edi, 8, v0_t)(edi);
    *(u32 *)(edi + 0x18) = 0;
  }
  u32 e14 = *(u32 *)(edi + 0x14);
  if (GV(0x7249f0) != e14 || GV(0x7249f4) != cnt) {
    u8 *dev = DEV;
    GV(0x7249f0) = e14;
    GV(0x7249f4) = cnt;
    SLOT(dev, 0x154, d3_t)(dev, e14, cnt);
  }
  ext_61a6b0(*(u8 **)(self + 8), p);
  ext_440530((u8 *)0x6bde8c);
}
PCREG(619c20, fn619c20);
