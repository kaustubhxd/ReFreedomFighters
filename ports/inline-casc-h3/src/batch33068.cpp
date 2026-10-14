// batch33068.cpp - h3 () batch 33068: tier C wrappers
#include "ff.h"

extern "C" void THISCALL ext_43f8c0(u8 *self, u32 a);               // ret 4 (tail to slot 0x48)
extern "C" void THISCALL ext_45f070(u8 *self, u32 a);               // ret 4 (tail)
extern "C" void THISCALL ext_5626c0(u8 *self);                      // tail
extern "C" void THISCALL ext_563510(u8 *self, u32 a);               // ret 4
extern "C" void THISCALL ext_563610(u8 *self, u32 a);               // ret 4
extern "C" u32 THISCALL ext_566f10(u8 *self);
extern "C" void THISCALL ext_5672c0(u8 *self, u32 a);               // ret 4
extern "C" void __attribute__((cdecl)) ext_634d34(void *obj, u32 info);   // throw helper (never returns)

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
typedef u32 (*hook_t)();
typedef u32 (__attribute__((cdecl)) *log3_t)(u8 *, u32, u32);

// 0x654e50: thiscall(a,b,c) ret 0xc: slot 0x230(a,b,c); clear key bits in sysobj bytes [0xa1f],[0x1406]; if [this+0x137]: import 0x6761f0(), flag [this+0x1153], slot 0xc8() (vtable read after the import)
typedef void (STDCALL *imp0_t)();
static void THISCALL fn654e50(u8 *self, u32 a, u32 b, u32 c) {
  vcall<u32>(self, 0x230, a, b, c);
  SYS[0xa1f] &= 0x7f;
  SYS[0xa1f] &= 0xdf;
  SYS[0x1406] &= 0x7f;
  SYS[0x1406] &= 0xdf;
  if (*(u32 *)(self + 0x137) != 0) {
    (*(imp0_t *)0x6761f0)();
    u8 *vt = *(u8 **)self;
    *(u32 *)(self + 0x1153) |= 0x2000000;
    self[0x1185] = 0;
    ((u32(THISCALL *)(u8 *)) * (u32 *)(vt + 0xc8))(self);
    *(u32 *)(self + 0x1153) &= 0xfdffffffu;
  }
  self[0x1184] = 0;
}
PCREG(654e50, fn654e50);

// 0x45c0e0: thiscall(i) ret 4: arr=[this+0x40]; arr[i]==0 -> assert hook; sysobj[0x190f]->slot 0x20()->slot 0x40(arr[i]); arr[i]=0 (arr re-read)
static void THISCALL fn45c0e0(u8 *self, u32 i) {
  if (*(u32 *)(*(u8 **)(self + 0x40) + i * 4) == 0) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u8 *g = *(u8 **)(SYS + 0x190f);
  u8 *r = vcall<u8 *>(g, 0x20);
  u32 v = *(u32 *)(*(u8 **)(self + 0x40) + i * 4);
  vcall<u32>(r, 0x40, v);
  *(u32 *)(*(u8 **)(self + 0x40) + i * 4) = 0;
}
PCREG(45c0e0, fn45c0e0);

// 0x46caa0: thiscall(a) ret 4: 0x43f8c0(this,a); if (u8)a->slot 0x1e0(0x1007d3) copy dwords 0x5c,0x60,0x64,0x68,0x6c,0x78 from a
static void THISCALL fn46caa0(u8 *self, u8 *a) {
  ext_43f8c0(self, (u32)a);
  if ((u8)vcall<u32>(a, 0x1e0, 0x1007d3u)) {
    *(u32 *)(self + 0x5c) = *(u32 *)(a + 0x5c);
    *(u32 *)(self + 0x60) = *(u32 *)(a + 0x60);
    *(u32 *)(self + 0x64) = *(u32 *)(a + 0x64);
    *(u32 *)(self + 0x68) = *(u32 *)(a + 0x68);
    *(u32 *)(self + 0x6c) = *(u32 *)(a + 0x6c);
    *(u32 *)(self + 0x78) = *(u32 *)(a + 0x78);
  }
}
PCREG(46caa0, fn46caa0);

// 0x4fa120: thiscall(a) ret 4: (u8)a ? (slot 0x2c4() && slot 0x2c4()->slot 0x2f4(this,1); 0x45f070(this,1); [this+0x6c]&=~1) : (0x45f070(this,0); [this+0x6c]|=1)
static void THISCALL fn4fa120(u8 *self, u32 a) {
  if ((u8)a) {
    if (vcall<u32>(self, 0x2c4) != 0) {
      u8 *r = vcall<u8 *>(self, 0x2c4);
      vcall<u32>(r, 0x2f4, (u32)self, 1u);
    }
    ext_45f070(self, 1);
    *(u32 *)(self + 0x6c) &= 0xfffffffeu;
    return;
  }
  ext_45f070(self, 0);
  *(u32 *)(self + 0x6c) |= 1;
}
PCREG(4fa120, fn4fa120);

// 0x5670a0: thiscall: init sequence; [this+0x194]=table->slot 0x58([this+0x190]); 0x5672c0(this, 0x566f10(this)); s=[this+0x94] read before the table->slot 0x4c([this+0x44]) call; dword [s+0x132b3]=result
static void THISCALL fn5670a0(u8 *self) {
  ext_5626c0(self);
  ext_563510(self, 0x6a6f98);
  ext_563610(self, 0x6a6fa0);
  u32 r = vcall<u32>(SYS_TABLE, 0x58, *(u32 *)(self + 0x190));
  *(u32 *)(self + 0x194) = r;
  u32 y = ext_566f10(self);
  ext_5672c0(self, y);
  u8 *s = *(u8 **)(self + 0x94);
  u32 z = vcall<u32>(SYS_TABLE, 0x4c, *(u32 *)(self + 0x44));
  *(u32 *)(s + 0x132b3) = z;
}
PCREG(5670a0, fn5670a0);

// 0x5c94a0: stdcall(a) ret 4 bool: o=table->slot 0x58(a); o && (u8)o->slot 0x1e0(0x200006) && c=[o+0x54] && [c+4]==0
static u32 STDCALL fn5c94a0(u32 a) {
  u8 *o = vcall<u8 *>(SYS_TABLE, 0x58, a);
  if (!o) return 0;
  if (!(u8)vcall<u32>(o, 0x1e0, 0x200006u)) return 0;
  u8 *c = *(u8 **)(o + 0x54);
  if (!c) return 0;
  return *(u32 *)(c + 4) == 0;
}
PCREG(5c94a0, fn5c94a0);

// 0x602cd0: thiscall(a) ret 4: kind byte [this+4] in {0,2}: [this]=*a, kind=2, returns *a; else log + assert hook
static u32 THISCALL fn602cd0(u8 *self, u32 *a) {
  u8 k = self[4];
  if (k == 0 || k == 2) {
    u32 v = *a;
    *(u32 *)self = v;
    self[4] = 2;
    return v;
  }
  u8 *g = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(g, 0x20, 0x69c8e0u, 0xd5u);
  (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x69c6b0, 0x69c938);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(602cd0, fn602cd0);

// 0x652840: stdcall(a) ret 4 (stack cookie): h=import[0x67603c](a); import[0x676030](a,h,0x28,buf); buf flags dword at +4: bit 0x80 -> throw (0x634d34, never returns)
typedef u32 (STDCALL *imp1_t)(u32);
typedef u32 (STDCALL *imp4_t)(u32, u32, u32, u32 *);
static void STDCALL fn652840(u32 a) {
  u32 buf[10];
  u32 h = (*(imp1_t *)0x67603c)(a);
  (*(imp4_t *)0x676030)(a, h, 0x28, buf);
  if (buf[1] & 0x80) {
    u32 obj[2] = {0x6c3b54, 0x6c3b1c};
    ext_634d34(obj, 0x6dd21c);
  }
}
PCREG(652840, fn652840);
