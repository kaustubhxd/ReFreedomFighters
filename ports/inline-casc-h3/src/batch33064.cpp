// batch33064.cpp - h3 (Sonnet) batch 33064: tier C wrappers with stack-struct args
#include "ff.h"

extern "C" u32 THISCALL ext_463030(u8 *self, u32 a, u32 b);          // ret 8
extern "C" void THISCALL ext_466eb0(u8 *self, u32 a, u32 b);         // ret 8
extern "C" void THISCALL ext_44b610(u8 *self);
extern "C" void __attribute__((cdecl)) ext_44b740(u8 *p);
extern "C" void THISCALL ext_4e6330(u8 *self, u8 *p);                // ret 4
extern "C" u32 THISCALL ext_4e5e60(u8 *self);
extern "C" u32 THISCALL ext_45f3c0(u8 *self, u32 a);                 // ret 4
extern "C" void THISCALL ext_52b430(u8 *self, u32 a);                // ret 4
extern "C" void THISCALL ext_563110(u8 *self, u32 a, u32 b);         // ret 8
extern "C" void THISCALL ext_57f750(u8 *self);

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
typedef u32 (*hook_t)();

// 0x462a20: thiscall(a,b,c,d) ret 0x10 bool: r=0x463030(d,'NAME',0); w=(u16)table->slot 0x114(r,0,str,0x67b); this->slot 0x128(w,0,0); returns al=0
static u32 THISCALL fn462a20(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  u32 r = ext_463030((u8 *)d, 0x4e414d45, 0);
  u32 x = vcall<u32>(SYS_TABLE, 0x114, r, 0u, 0x685834u, 0x67bu);
  u32 e = vcall<u32>(self, 0x128, (u32)(u16)x, 0u, 0u);
  (void)e;
  return 0;
}
PCREG(462a20, fn462a20);

// 0x474730: thiscall(a,b) ret 8 bool: 0x466eb0(this+4, a, b); a->slot 0x18(this+0x51,5); a->slot 0x18(this+0x5a,0xc); return 1
static u32 THISCALL fn474730(u8 *self, u8 *a, u32 b) {
  ext_466eb0(self + 4, (u32)a, b);
  vcall<u32>(a, 0x18, (u32)(self + 0x51), 5u);
  vcall<u32>(a, 0x18, (u32)(self + 0x5a), 0xcu);
  return 1;
}
PCREG(474730, fn474730);

// 0x4b05d0: thiscall(a,b) ret 8: if (u16)a == word [this+0xdc]: o=table->slot 0x60([this+0xde]); o && (0x44b610(o); cdecl 0x44b740(o)); return 0
static u32 THISCALL fn4b05d0(u8 *self, u32 a, u32 b) {
  if ((u16)a == *(u16 *)(self + 0xdc)) {
    u8 *o = vcall<u8 *>(SYS_TABLE, 0x60, *(u32 *)(self + 0xde));
    if (o) {
      ext_44b610(o);
      ext_44b740(o);
    }
  }
  return 0;
}
PCREG(4b05d0, fn4b05d0);

// 0x4f6860: thiscall(a,b) ret 8: 0x4e6330(b, this+0x48); [this+0xf4]=0x4e5e60(b); byte [0xf8]=(0x4e5e60(b)!=0); byte [0xf9]=(0x4e5e60(b)!=0)
static void THISCALL fn4f6860(u8 *self, u32 a, u8 *b) {
  ext_4e6330(b, self + 0x48);
  *(u32 *)(self + 0xf4) = ext_4e5e60(b);
  self[0xf8] = ext_4e5e60(b) != 0;
  self[0xf9] = ext_4e5e60(b) != 0;
}
PCREG(4f6860, fn4f6860);

// 0x52b4a0: thiscall(a) ret 4 bool: !(u8)0x45f3c0(this,a) -> return; a->slot 0x48(this+0x75); 0x52b430([this+0x79], a); return 1
static u32 THISCALL fn52b4a0(u8 *self, u8 *a) {
  u32 ok = ext_45f3c0(self, (u32)a);
  if (!(u8)ok) return ok;
  vcall<u32>(a, 0x48, (u32)(self + 0x75));
  ext_52b430(*(u8 **)(self + 0x79), (u32)a);
  return 1;
}
PCREG(52b4a0, fn52b4a0);

// 0x57f660: thiscall(a,b) ret 8 bool: 0x563110(a,b); 0x57f750(); p=slot 0x84(); p->slot 0x34c(0x10000, 0, [this+0x44], 10.0f, 0) (the zero is a pushed copy of ecx overwritten by the mov [ecx],0); return 0
static u32 THISCALL fn57f660(u8 *self, u32 a, u32 b) {
  ext_563110(self, a, b);
  ext_57f750(self);
  u8 *p = vcall<u8 *>(self, 0x84);
  vcall<u32>(p, 0x34c, 0x10000u, 0u, *(u32 *)(self + 0x44), 0x41200000u, 0u);
  return 0;
}
PCREG(57f660, fn57f660);

// 0x5b9730: thiscall: r = slot 0x84([[this+0x54]+0x18], [this+0x5c]); [this+0x5c]=r; r: [this+0x44]->slot 0x128((u16)[this+0x62], &{0x6ad2f4, r}, 0)
struct Pair { u32 a, b; };
static void THISCALL fn5b9730(u8 *self) {
  u32 r = vcall<u32>(self, 0x84, *(u32 *)(*(u8 **)(self + 0x54) + 0x18), *(u32 *)(self + 0x5c));
  *(u32 *)(self + 0x5c) = r;
  if (!r) return;
  Pair loc = {0x6ad2f4, r};
  vcall<u32>(*(u8 **)(self + 0x44), 0x128, (u32) * (u16 *)(self + 0x62), (u32)&loc, 0u);
}
PCREG(5b9730, fn5b9730);

// 0x5f3160: thiscall(a) ret 4: if [this+8]+4 > [this+0xc] assert hook (int3 when null); dword [[this+8]] = (u8)a; [this+8] += 4
static void THISCALL fn5f3160(u8 *self, u32 a) {
  if (*(u32 *)(self + 8) + 4 > *(u32 *)(self + 0xc)) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  **(u32 **)(self + 8) = (u8)a;
  *(u32 *)(self + 8) += 4;
}
PCREG(5f3160, fn5f3160);
