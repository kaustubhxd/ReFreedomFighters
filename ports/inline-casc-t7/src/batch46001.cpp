// batch46001.cpp - cascade t7 (Sonnet), tier G: 0x5a04f0 (loads a table of ~44 named resource handles into a 0x98-byte record).
#include "ff.h"

extern "C" u8 *ext_41e290(u32 size);                          // cdecl alloc
extern "C" void *ext_634d10(void *p, u32 v, u32 n);           // cdecl memset
typedef void (*cdecl2_t)(void *, u32);

struct NameOff { u32 name; u8 off; };
static const NameOff kNames1[] = {
  {0x6aeb5c, 0x00}, {0x6aeb68, 0x04}, {0x6aeb70, 0x08}, {0x6aeb78, 0x0c}, {0x6aeb80, 0x10}, {0x6aeb8c, 0x14},
  {0x6aeb98, 0x30}, {0x6aeba0, 0x20}, {0x6aebac, 0x24},
};
static const NameOff kNames2[] = {
  {0x6aebb8, 0x18}, {0x6aebc4, 0x40}, {0x6aebcc, 0x48}, {0x6aebd8, 0x68}, {0x6aebe0, 0x70}, {0x6aebe8, 0x54}, {0x6aebe0, 0x74},
};
static const NameOff kNames3[] = {
  {0x6aebfc, 0x28}, {0x6aec0c, 0x2c}, {0x6aec18, 0x34}, {0x6aec20, 0x38}, {0x6aec28, 0x3c}, {0x6aec30, 0x44}, {0x6aec3c, 0x4c},
  {0x6aec48, 0x6c}, {0x6aec54, 0x1c}, {0x6aec60, 0x64}, {0x6aec6c, 0x60}, {0x6aeba0, 0x58}, {0x6aec78, 0x5c}, {0x6aec84, 0x78},
  {0x6aec8c, 0x7c}, {0x6aec98, 0x80}, {0x6aec30, 0x84}, {0x6aeca4, 0x88}, {0x6aecac, 0x8c}, {0x6aecb4, 0x90}, {0x6aecc0, 0x94},
};

static inline u8 *lookupObj() { return *(u8 **)(*(u8 **)0x70039c + 0x1a9f); }
static inline u32 look(u8 *edi, u32 name) { return vcall<u32>(lookupObj(), 0x60, (u32)edi, name); }
static inline u8 *rec(u8 *self) { return *(u8 **)(self + 0x936); }

static void THISCALL fn5a04f0(u8 *self) {
  u8 *edi = vcall<u8 *>(self, 0x680);
  u8 *p = ext_41e290(0x98);
  *(u8 **)(self + 0x936) = p;
  ext_634d10(p, 0, 0x98);
  u8 *L = lookupObj();
  if (L) {
    vcall<void>(L, 0x80, (u32)self);
    if (edi) {
      u8 *w = *(u8 **)(self + 0x54);
      self[0x143] = (u8)((*(u32 *)(w + 4) == 0) + 2);
      for (const NameOff &n : kNames1) *(u32 *)(rec(self) + n.off) = look(edi, n.name);
      *(u32 *)(rec(self) + 0x50) = 0;
      for (const NameOff &n : kNames2) *(u32 *)(rec(self) + n.off) = look(edi, n.name);
      if (look(edi, 0x6aebf0)) {
        u32 r = look(edi, 0x6aebf0);
        *(u32 *)(rec(self) + 0x74) = r;
      }
      for (const NameOff &n : kNames3) *(u32 *)(rec(self) + n.off) = look(edi, n.name);
    }
  }
  u8 *t = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  u8 *q = vcall<u8 *>(t, 0x138);
  u32 local = 0;
  vcall<void>(q, 0x88, (u32)0x6aecc8, (u32)&local);
  if (local) {
    u8 *t2 = *(u8 **)(*(u8 **)0x70039c + 0x9b);
    u8 *o = vcall<u8 *>(t2, 0x58, local);
    *(u32 *)(self + 0x93a) = vcall<u32>(o, 0x100, (u32)0x6aece0);
  } else {
    u8 *g = *(u8 **)0x700390;
    u8 *r = vcall<u8 *>(g, 0x20, (u32)0x6ae6a0, (u32)0x9b0);
    (*(cdecl2_t **)r)[0x2c / 4](r, 0x6aecf4);
  }
  *(u16 *)(self + 0x93e) = 0x100;
  *(u32 *)(self + 0x945) = 0;
  *(u32 *)(self + 0x941) = 0;
}
PCREG(5a04f0, fn5a04f0);
