// batch33041.cpp - h3 (Sonnet) batch 33041: tier B ctors, small call wrappers, vector push_back, free-fields
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *self);
extern "C" void THISCALL ext_43de40(u8 *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" void THISCALL ext_4cc630(u8 *self, u32 s);                  // ret 4
extern "C" void THISCALL ext_4301c0(u8 *self, u32 *pos, u32 *val);     // ret 8
extern "C" void THISCALL ext_59dae0(u8 *self, u32 a, u32 b, u32 c, u32 one, u32 d);   // ret 0x14
extern "C" void THISCALL ext_42b390(u32 *dest, u32 a, u8 *p);          // ret 8, fills 3 dwords at ecx
extern "C" u32 THISCALL ext_602750(u8 *self, u32 s0, u32 s1, u32 s2, u32 b, u32 c, u32 d, u32 e);   // ret 0x1c
extern "C" void __attribute__((cdecl)) ext_634d52(void *p);
extern "C" u32 THISCALL ext_4d6520(u8 *self, u32 a, u8 *buf, u32 z);   // ret 0xc

// 0x5c4530: ctor: base, [4]|=0x20, [0x44]=0, vtable 0x6b4088, six fields cleared
static u8 *THISCALL fn5c4530(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b4088;
  *(u32 *)(self + 0x5c) = 0;
  *(u32 *)(self + 0x58) = 0;
  *(u32 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x60) = 0;
  *(u32 *)(self + 0x54) = 0;
  return self;
}
PCREG(5c4530, fn5c4530);

// 0x47fce0: ctor(a,b,c) ret 0xc: base 0x43de40, vtable 0x68b364, float fields, [0x8c]=0, [0x18]=8
static u8 *THISCALL fn47fce0(u8 *self, u32 a, u32 b, u32 c) {
  ext_43de40(self, a, b, c);
  *(u32 *)self = 0x68b364;
  *(u32 *)(self + 0x1c) = 0x42c80000;
  *(u32 *)(self + 0x24) = 0x3f000000;
  *(u32 *)(self + 0x20) = 0x3f800000;
  *(u32 *)(self + 0x8c) = 0;
  *(u32 *)(self + 0x18) = 8;
  return self;
}
PCREG(47fce0, fn47fce0);

// 0x4cbe50: thiscall(a) ret 4: 0x4cc630(this, *a ? *a : "" (0x677b5a)); return this
static u8 *THISCALL fn4cbe50(u8 *self, u32 *a) {
  u32 s = *a;
  ext_4cc630(self, s ? s : 0x677b5a);
  return self;
}
PCREG(4cbe50, fn4cbe50);

// 0x5f1590: thiscall(a) ret 4: vector at [[this+0xc]+0xac]: if end==cap call 0x4301c0(v, end, &a) else store and bump
static void THISCALL fn5f1590(u8 *self, u32 a) {
  u8 *v = *(u8 **)(self + 0xc) + 0xac;
  u32 *cur = *(u32 **)(v + 4);
  if (cur == *(u32 **)(v + 8)) {
    ext_4301c0(v, cur, &a);
    return;
  }
  if (cur) *cur = a;
  *(u32 *)(v + 4) += 4;
}
PCREG(5f1590, fn5f1590);

// 0x59db50: thiscall(a,b,c,d) ret 0x10: if n=[0x7ce] && !([this+n*16+0x7c2] < a) return 0; 0x59dae0(a,b,c,1,d); return 1
static u32 THISCALL fn59db50(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  u32 n = *(u32 *)(self + 0x7ce);
  if (n) {
    if (!(*(u32 *)(self + n * 16 + 0x7c2) < a)) return 0;
  }
  ext_59dae0(self, a, b, c, 1, d);
  return 1;
}
PCREG(59db50, fn59db50);

// 0x5f15d0: thiscall(a,b,c,d,e) ret 0x14: build 12-byte temp via 0x42b390(a, &arg), call 0x602750 on [[this+0xc]+4]->[0]
static u32 THISCALL fn5f15d0(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e) {
  u32 t[3];
  ext_42b390(t, a, (u8 *)&a + 0x13);
  u8 *o = **(u8 ***)(*(u8 **)(self + 0xc) + 4);
  return ext_602750(o, t[0], t[1], t[2], b, c, d, e);
}
PCREG(5f15d0, fn5f15d0);

// 0x40fa40: cdecl(p): if p: free [p+4] and [p+8] when non-null; zero p[0..2]
static void fn40fa40(u32 *p) {
  if (!p) return;
  if (p[1]) ext_634d52((void *)p[1]);
  if (p[2]) ext_634d52((void *)p[2]);
  p[0] = 0;
  p[1] = 0;
  p[2] = 0;
}
PCREG(40fa40, fn40fa40);

// 0x4d5e40: thiscall(a) ret 4: buf[0x20]; ok = 0x4d6520(a, buf, 0); return ok ? *(u32*)(buf+0x12) : -1
static u32 THISCALL fn4d5e40(u8 *self, u32 a) {
  u8 buf[0x20];
  u8 ok = (u8)ext_4d6520(self, a, buf, 0);
  return ok ? *(u32 *)(buf + 0x12) : 0xffffffffu;
}
PCREG(4d5e40, fn4d5e40);
