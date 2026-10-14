// batch33071.cpp - h3 () batch 33071: tier C wrappers with imports
#include "ff.h"

extern "C" void THISCALL ext_43ea20(u8 *self);
extern "C" u32 THISCALL ext_600810(u8 *self);
extern "C" void __attribute__((cdecl)) ext_45c510(u8 *p);
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *p, u32 n);
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);
extern "C" void __attribute__((cdecl)) ext_4102f0(u8 *p);
extern "C" void __attribute__((cdecl)) ext_401900(u8 *p);
extern "C" void __attribute__((cdecl)) ext_401c90(u8 *p);
extern "C" void __attribute__((cdecl)) ext_401020(u8 *p);
extern "C" void __attribute__((cdecl)) ext_4010c0(u8 *p);
extern "C" void __attribute__((cdecl)) ext_410490(u8 *p);

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
typedef u32 (*hook_t)();

// 0x4d4590: thiscall(c, n16) ret 8: n (or 1 if 0) times: if import[0x676424]((s8)c) (cdecl): append byte c at [this+0x1007+[this+0x10cf]], index++, terminate with 0
typedef u32 (__attribute__((cdecl)) *imp1c_t)(s32);
static void THISCALL fn4d4590(u8 *self, u32 c, u32 n16) {
  u32 n = (u16)n16;
  u32 edi = n ? n : n + 1;
  u8 bl = (u8)c;
  s32 ch = (s8)bl;
  do {
    edi--;
    u32 r = (*(imp1c_t *)0x676424)(ch);
    if (r) {
      u32 idx = *(u32 *)(self + 0x10cf);
      self[idx + 0x1007] = bl;
      (*(u32 *)(self + 0x10cf))++;
      idx = *(u32 *)(self + 0x10cf);
      self[idx + 0x1007] = 0;
    }
  } while (edi != 0);
}
PCREG(4d4590, fn4d4590);

// 0x4f6bb0: thiscall(a) ret 4: c=[this+0x93]; vtable 0x69aaf0; c && c->slot 0x210(1); [this+0x93]=0; 0x43ea20(this); a&1: (a&4 ? cdecl 0x4690b0(this,0xa8) : cdecl 0x45c510(this)); returns this
static u8 *THISCALL fn4f6bb0(u8 *self, u32 a) {
  u8 *c = *(u8 **)(self + 0x93);
  *(u32 *)self = 0x69aaf0;
  if (c) vcall<u32>(c, 0x210, 1u);
  *(u32 *)(self + 0x93) = 0;
  ext_43ea20(self);
  if (a & 1) {
    if (!(a & 4)) {
      ext_45c510(self);
      return self;
    }
    ext_4690b0(self, 0xa8);
  }
  return self;
}
PCREG(4f6bb0, fn4f6bb0);

// 0x54a040: thiscall: if byte [this+0x2315]: six cdecl cleanup calls on sub-objects, delete [this+0xd] (size 1), clear [this+0xd] and the flag
static void THISCALL fn54a040(u8 *self) {
  if (self[0x2315] == 0) return;
  ext_4102f0(self + 0x2061);
  ext_401900(self + 0x2299);
  ext_401c90(self + 0x2229);
  ext_401020(self + 0x2219);
  ext_4010c0(self + 0x21f9);
  ext_410490(self + 0x2045);
  u8 *p = *(u8 **)(self + 0xd);
  if (p) ext_634273(p, 1);
  *(u32 *)(self + 0xd) = 0;
  self[0x2315] = 0;
}
PCREG(54a040, fn54a040);

// 0x5eec70: thiscall(a) ret 4: three children [this+4/8/0xc]: slot 0(1) when set; vtable 0x6b8190 then 0x6b01dc; a&1 -> delete(this,0x21); returns this
static u8 *THISCALL fn5eec70(u8 *self, u32 a) {
  u8 *c1 = *(u8 **)(self + 4);
  *(u32 *)self = 0x6b8190;
  if (c1) vcall<u32>(c1, 0, 1u);
  u8 *c2 = *(u8 **)(self + 8);
  if (c2) vcall<u32>(c2, 0, 1u);
  u8 *c3 = *(u8 **)(self + 0xc);
  if (c3) vcall<u32>(c3, 0, 1u);
  *(u32 *)self = 0x6b01dc;
  if (a & 1) ext_634273(self, 0x21);
  return self;
}
PCREG(5eec70, fn5eec70);

// 0x5f0ff0: thiscall(a) bool: flag=1; r=table->slot 0x58(a); r's vtable read first; w=(u16)table->slot 0x114(str,0,str,0x22,&flag); r->vtable[0x130](r,w); return flag
static u32 THISCALL fn5f0ff0(u8 *self) {
  u8 flag = 1;
  u8 *r = vcall<u8 *>(SYS_TABLE, 0x58, (u32)self);
  u8 *vt = *(u8 **)r;
  u32 x = vcall<u32>(SYS_TABLE, 0x114, 0x6a66a8u, 0u, 0x6b82f4u, 0x22u, (u32)&flag);
  ((u32(THISCALL *)(u8 *, u32, u32)) * (u32 *)(vt + 0x130))(r, (u32)r, (u32)(u16)x);
  return flag;
}
PCREG(5f0ff0, fn5f0ff0);

// 0x5f5620: thiscall(a) ret 4: walk list at [this+0x96] (next +0x9c): find the node whose range [base,base+len) contains a; return [n+0x54]-[n+0x48]+a, else assert hook (int3 when null) and its eax
static u32 THISCALL fn5f5620(u8 *self, u32 a) {
  u8 *n = *(u8 **)(self + 0x96);
  while (n) {
    if (!(*(u32 *)(n + 0x48) > a)) {
      u32 len = ext_600810(n + 0x50);
      if (len + *(u32 *)(n + 0x48) > a) return *(u32 *)(n + 0x54) - *(u32 *)(n + 0x48) + a;
    }
    n = *(u8 **)(n + 0x9c);
  }
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(5f5620, fn5f5620);

// 0x64dcb0: thiscall: while [this+0x10089]: this->slot 0xc([[[this+0x1008d]+0xc]+0xc]); then [this+0x1005d]->slot 0x60(), slot 0x64() (vtable re-read), then number the entries: byte [entry+0x70]=i+1 for i < [this+0x10089]
static void THISCALL fn64dcb0(u8 *self) {
  while (*(u32 *)(self + 0x10089) != 0) {
    u8 *e = *(u8 **)(self + 0x1008d);
    u8 *x = *(u8 **)(e + 0xc);
    vcall<u32>(self, 0xc, *(u32 *)(x + 0xc));
  }
  vcall<u32>(*(u8 **)(self + 0x1005d), 0x60);
  vcall<u32>(*(u8 **)(self + 0x1005d), 0x64);
  if (*(u32 *)(self + 0x10089) == 0) return;
  u32 i = 0;
  u32 *p = (u32 *)(self + 0x1008d);
  do {
    u8 *e = (u8 *)*p;
    p++;
    i++;
    e[0x70] = (u8)i;
  } while (i != *(u32 *)(self + 0x10089));
}
PCREG(64dcb0, fn64dcb0);

// 0x421500: thiscall(a): VirtualQuery-like import[0x6760e8](a,&mbi,0x1c); committed region (state 0x1000) with allocation base: GetModuleFileName-like import[0x67607c](base,buf 0x6fd448,0x3e8), cdecl import[0x676258](buf,'\\'): p+1 or buf; else 0x677a4c
typedef u32 (STDCALL *impq_t)(u32, u32 *, u32);
typedef u32 (STDCALL *impf_t)(u32, u32, u32);
typedef u32 (__attribute__((cdecl)) *imps_t)(u32, u32);
static u32 THISCALL fn421500(u8 *self) {
  u32 mbi[7];
  (*(impq_t *)0x6760e8)((u32)self, mbi, 0x1c);
  if (mbi[4] != 0x1000 || mbi[1] == 0) return 0x677a4c;
  (*(impf_t *)0x67607c)(mbi[1], 0x6fd448, 0x3e8);
  u32 p = (*(imps_t *)0x676258)(0x6fd448, 0x5c);
  if (p) return p + 1;
  return 0x6fd448;
}
PCREG(421500, fn421500);
