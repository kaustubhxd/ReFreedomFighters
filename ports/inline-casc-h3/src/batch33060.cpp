// batch33060.cpp - h3 () batch 33060: tier C wrappers
#include "ff.h"

extern "C" void THISCALL ext_45d5b0(u8 *self, u32 a);               // ret 4 (tail to slot 0x48)
extern "C" u32 THISCALL ext_4705a0(u8 *self, u32 a);                // ret 4
extern "C" void THISCALL ext_6352f0(u8 *self, u32 *out);            // ret 4
extern "C" u32 *THISCALL ext_5003d0(u8 *self, u32 a);               // ret 4
extern "C" u32 THISCALL ext_59e730(u8 *self, u32 a, u32 b);         // ret 8
extern "C" u32 THISCALL ext_4614d0(u8 *self, u32 a, u32 b, u32 c);  // ret 0xc

#define SYS (*(u8 **)0x70039c)
typedef u32 (*hook_t)();

// 0x462000: thiscall(a) ret 4: 0x45d5b0(this,a); if (u8)a->slot 0x1e0(0x200006) this->slot 0x2e4(a)
static void THISCALL fn462000(u8 *self, u8 *a) {
  ext_45d5b0(self, (u32)a);
  if ((u8)vcall<u32>(a, 0x1e0, 0x200006u)) vcall<u32>(self, 0x2e4, (u32)a);
}
PCREG(462000, fn462000);

// 0x46baa0: thiscall: [this+0x74]->slot 0x14() and [this+0x78]->slot 0x14() both zero -> slot 0x114(0x10); slot 0x31c(); tail slot 0x318()
static u32 THISCALL fn46baa0(u8 *self) {
  if (vcall<u32>(*(u8 **)(self + 0x74), 0x14) == 0) {
    if (vcall<u32>(*(u8 **)(self + 0x78), 0x14) == 0) vcall<u32>(self, 0x114, 0x10u);
  }
  vcall<u32>(self, 0x31c);
  return vcall<u32>(self, 0x318);
}
PCREG(46baa0, fn46baa0);

// 0x470610: thiscall(a) ret 4 bool: ok=0x4705a0(this,a); !(u8)ok -> return; a->slot 0x44([this+0x8e]); return 1
static u32 THISCALL fn470610(u8 *self, u8 *a) {
  u32 ok = ext_4705a0(self, (u32)a);
  if (!(u8)ok) return ok;
  u32 r = vcall<u32>(a, 0x44, *(u32 *)(self + 0x8e));
  return (r & 0xffffff00u) | 1;
}
PCREG(470610, fn470610);

// 0x4b5970: thiscall: local=0; 0x6352f0(&local); slot 0x98(&local); slot 0x68(0x10, 0)
static void THISCALL fn4b5970(u8 *self) {
  u32 local = 0;
  ext_6352f0(self, &local);
  vcall<u32>(self, 0x98, (u32)&local);
  vcall<u32>(self, 0x68, 0x10u, 0u);
}
PCREG(4b5970, fn4b5970);

// 0x558a50: thiscall(a) ret 4: v1=*0x5003d0([a+4],0) read before the second call; v2=*0x5003d0([a+4],1); 0x59e730([this+0x1c], v1, v2)
static u32 THISCALL fn558a50(u8 *self, u8 *a) {
  u32 v1 = *ext_5003d0(*(u8 **)(a + 4), 0);
  u32 *p2 = ext_5003d0(*(u8 **)(a + 4), 1);
  return ext_59e730(*(u8 **)(self + 0x1c), v1, *p2);
}
PCREG(558a50, fn558a50);

// 0x595210: thiscall(a) ret 4 bool: o=a->slot 0x350(); k=o->slot 0x330(); (k==7 && byte [[this+0x85a]+0xb45]) ? 0 : 1
static u32 THISCALL fn595210(u8 *self, u8 *a) {
  u8 *o = vcall<u8 *>(a, 0x350);
  u32 k = vcall<u32>(o, 0x330);
  if (k == 7 && (*(u8 **)(self + 0x85a))[0xb45]) return 0;
  return 1;
}
PCREG(595210, fn595210);

// 0x5e0200: thiscall: [this+0xc]->slot 0x10(); r=[this+8]->slot 0x228([this+0x10],1,0,10.0f,1.0f); 0x4614d0(r, 0.016f, 0x465710, 0); eax low byte 1
static u32 THISCALL fn5e0200(u8 *self) {
  vcall<u32>(*(u8 **)(self + 0xc), 0x10);
  u32 r = vcall<u32>(*(u8 **)(self + 8), 0x228, *(u32 *)(self + 0x10), 1u, 0u, 0x41200000u, 0x3f800000u);
  u32 x = ext_4614d0((u8 *)r, 0x3c83126f, 0x465710, 0);
  return (x & 0xffffff00u) | 1;
}
PCREG(5e0200, fn5e0200);

// 0x6566a0: stdcall(a) ret 4: s=[[sysobj+0x1aa3]+0x20]; if (!s) assert hook (int3 when null); return a + s
static u32 STDCALL fn6566a0(u32 a) {
  u32 s = *(u32 *)(*(u8 **)(SYS + 0x1aa3) + 0x20);
  if (!s) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  return a + s;
}
PCREG(6566a0, fn6566a0);
