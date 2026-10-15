// batch67539.cpp - cascade s6 batch 67539: 0x646fb0.
#include "ff.h"

extern "C" u8 *THISCALL ext_63ea50(u8 *mgr, u8 *owner);                       // ret 4
extern "C" void FASTCALL ext_4dfd10(u32 *dst, u8 *src);                       // 3x3 transposed copy, plain ret
extern "C" void FASTCALL ext_4de480(u32 *dst, u8 *src);                       // dst *= src, plain ret
extern "C" void THISCALL ext_646f30(u8 *self, u8 *r, u8 *tab, u32 idx, u8 *out, u8 *outv);   // ret 0x14

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define SYS (*(u8 **)0x70039c)

// 0x646fb0, thiscall(outMat, outVec, idx, obj) ret 0x10, returns al: false when idx is above this[0x11]. Otherwise it fetches the object's matrix table (sys[0x1aa3][0x18] slot 0xc0 for obj[8][0x6c])
// and the object's pose block (0x63ea50 on sys[0x190f] slot 0x20). With a pose block it copies the idx-th 0x30-byte entry's vector (+0x24) to outVec and writes (transposed pose entry * table[idx]) to
// outMat (0x4dfd10 / 0x4de480 / 0x4dfd10); without one it builds the entry through the object itself (slot 0x280 into a local buffer when this[0x295], else the manager's slot 0xbc) and hands off to 0x646f30.
static u32 THISCALL fn646fb0(u8 *self, u8 *outMat, u8 *outVec, u32 idx, u8 *obj) {
  u8 buf[0x1228];
  if (idx > D32(self, 0x11)) return 0;
  u8 *mgr = *(u8 **)(SYS + 0x1aa3);
  u8 *tab = vcall<u8 *>(*(u8 **)(mgr + 0x18), 0xc0, D32(*(u8 **)(obj + 8), 0x6c));
  u8 *x = vcall<u8 *>(*(u8 **)(SYS + 0x190f), 0x20);
  u8 *t = ext_63ea50(x, *(u8 **)(obj + 8));
  if (t) {
    u8 *p = t + idx * 0x30;
    D32(outVec, 0) = D32(p, 0x24);
    D32(outVec, 4) = D32(p, 0x28);
    D32(outVec, 8) = D32(p, 0x2c);
    u32 m[9];
    ext_4dfd10(m, p);
    ext_4de480(m, tab + idx * 36);
    ext_4dfd10((u32 *)outMat, (u8 *)m);
  } else {
    u8 *r;
    if (self[0x295]) {
      vcall<void>(obj, 0x280, (u32)buf);
      r = buf;
    } else {
      r = vcall<u8 *>(*(u8 **)(*(u8 **)(SYS + 0x1aa3) + 0x18), 0xbc, D32(*(u8 **)(obj + 8), 0x6c));
    }
    ext_646f30(self, r, tab, idx, outMat, outVec);
  }
  return 1;
}
PCREG(646fb0, fn646fb0);
