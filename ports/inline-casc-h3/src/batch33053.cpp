// batch33053.cpp - h3 () batch 33053: tiny tier C wrappers
#include "ff.h"

extern "C" u32 THISCALL ext_562d90(u8 *self, u32 a);                  // ret 4
extern "C" void THISCALL ext_593f40(u8 *self, u32 a);                 // ret 4
extern "C" u32 THISCALL ext_594040(u8 *self, u32 a, u32 b);           // ret 8
extern "C" void THISCALL ext_596d70(u8 *self, u32 a, u32 b);          // ret 8
extern "C" u32 THISCALL ext_467060(u8 *self, u32 a, u32 b, u32 c);    // ret 0xc
extern "C" void THISCALL ext_5f0380(u8 *self);
extern "C" void THISCALL ext_46cee0(u8 *self, u32 a);                 // ret 4
extern "C" void THISCALL ext_4e0fd0(u8 *self, u32 a);                 // ret 4
extern "C" void THISCALL ext_4e1b30(u8 *self);
extern "C" void THISCALL ext_471680(u8 *self);
extern "C" void THISCALL ext_4705a0(u8 *self, u32 a);                 // ret 4

// 0x574250: thiscall(a) ret 4: a == 0x105 ? (slot 0x84()->slot 0x300(), eax low byte cleared) : tail 0x562d90(a)
static u32 THISCALL fn574250(u8 *self, u32 a) {
  if (a == 0x105) {
    u8 *r = vcall<u8 *>(self, 0x84);
    return vcall<u32>(r, 0x300) & 0xffffff00u;
  }
  return ext_562d90(self, a);
}
PCREG(574250, fn574250);

// 0x597640: thiscall: o=[this+0x1d0b] re-read each time; 0x593f40(o,1); [this+0xdd]=0x594040(o,0xd,1); 0x596d70(this,0,0)
static void THISCALL fn597640(u8 *self) {
  ext_593f40(*(u8 **)(self + 0x1d0b), 1);
  u32 r = ext_594040(*(u8 **)(self + 0x1d0b), 0xd, 1);
  *(u32 *)(self + 0xdd) = r;
  ext_596d70(self, 0, 0);
}
PCREG(597640, fn597640);

// 0x5a1c20: thiscall(a) ret 4: r = slot 0x684(); 0x467060([[this+0x936]+(u8)a*4], r, 0)
static u32 THISCALL fn5a1c20(u8 *self, u32 a) {
  u32 r = vcall<u32>(self, 0x684);
  u32 elem = *(u32 *)(*(u8 **)(self + 0x936) + (u8)a * 4);
  return ext_467060(self, elem, r, 0);
}
PCREG(5a1c20, fn5a1c20);

// 0x5f0420: thiscall: g=[sysobj+0x1907]; if (u8)g->slot 0x2c([this+0xc], 0) tail 0x5f0380(this)
static void THISCALL fn5f0420(u8 *self) {
  u8 *g = *(u8 **)(*(u8 **)0x70039c + 0x1907);
  if ((u8)vcall<u32>(g, 0x2c, *(u32 *)(self + 0xc), 0u)) ext_5f0380(self);
}
PCREG(5f0420, fn5f0420);

// 0x46d040: thiscall(a) ret 4: 0x46cee0(this,a); 0x4e0fd0(a,[this+0x7c]); 0x4e1b30(a)
static void THISCALL fn46d040(u8 *self, u8 *a) {
  ext_46cee0(self, (u32)a);
  ext_4e0fd0(a, *(u32 *)(self + 0x7c));
  ext_4e1b30(a);
}
PCREG(46d040, fn46d040);

// 0x46eff0: thiscall: c=[this+0x44]->slot 0xbc(1); [this+0x44] re-read ->slot 0x300(0); if byte [this+0x51] tail 0x471680
static void THISCALL fn46eff0(u8 *self) {
  vcall<u32>(*(u8 **)(self + 0x44), 0xbc, 1u);
  vcall<u32>(*(u8 **)(self + 0x44), 0x300, 0u);
  if (self[0x51]) ext_471680(self);
}
PCREG(46eff0, fn46eff0);

// 0x470640: thiscall(a) ret 4 bool: 0x4705a0(this,a); a->slot 0x6c([this+0x94]); return 1
static u32 THISCALL fn470640(u8 *self, u8 *a) {
  ext_4705a0(self, (u32)a);
  vcall<u32>(a, 0x6c, *(u32 *)(self + 0x94));
  return 1;
}
PCREG(470640, fn470640);

// 0x48aad0: thiscall: o=[this]; local=0; o->slot 0x88([this+4], &local); return local
static u32 THISCALL fn48aad0(u8 *self) {
  u32 local = 0;
  vcall<u32>(*(u8 **)self, 0x88, *(u32 *)(self + 4), (u32)&local);
  return local;
}
PCREG(48aad0, fn48aad0);
