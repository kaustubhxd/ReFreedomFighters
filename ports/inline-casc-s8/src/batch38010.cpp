// batch38010.cpp - cascade s8 batch 38010: 0x579590 (look up four named settings and apply them).
#include "ff.h"

extern "C" void THISCALL ext_5626c0(u8 *self);
extern "C" void THISCALL ext_563510(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_563610(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_579a60(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_579bd0(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_579b20(u8 *self, u32 a);   // ret 4
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(*c4_t)(void *, void *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)
#define TABLE (*(u8 **)(ENG + 0x9b))

// name = lookup string of the property; fills buf with the stored text (engine slot 0x190 object, slot 0x198, cdecl) for this+0x194.
static void fetch(u8 *self, void *buf, u32 name) {
  u8 *a = (u8 *)SLOT(ENG, 0x190, v0_t)(ENG);
  (*(c4_t **)a)[0x198 / 4](a, buf, name, *(u32 *)(self + 0x194));
}
// parses buf with the table's helper (slot 0x134 object, slot 0x90 (buf, &flag)).
static void parse(void *buf, u8 *flag) {
  u8 *t = TABLE;
  u8 *x = (u8 *)SLOT(t, 0x134, v0_t)(t);
  SLOT(x, 0x90, v2_t)(x, (u32)buf, (u32)flag);
}

// 0x579590, thiscall, no args, plain ret: base setup (0x5626c0, 0x563510, 0x563610), then four named-setting lookups: the first three parse a flag and pass it to
// 0x579a60 / 0x579bd0 / 0x579b20; the fourth parses a flag, fetches a second text and hands both to slot 0x68; finally the table's slot 0x4c of this+0x44 is stored
// at [this->+0x94 + 0x132af].
static void THISCALL fn579590(u8 *self) {
  u8 buf44[0x40], buf84[0x40];
  u8 flag = 0;
  ext_5626c0(self);
  ext_563510(self, 0x6a6f98);
  ext_563610(self, 0x6a9b08);
  fetch(self, buf44, 0x6a9afc);
  flag = 0;
  parse(buf44, &flag);
  ext_579a60(self, flag);
  fetch(self, buf44, 0x6a9ac8);
  flag = 0;
  parse(buf44, &flag);
  ext_579bd0(self, flag);
  fetch(self, buf44, 0x6a9adc);
  flag = 0;
  parse(buf44, &flag);
  ext_579b20(self, flag);
  fetch(self, buf44, 0x6a9af0);
  u8 flag2 = 0;
  parse(buf44, &flag2);
  flag = flag2;
  fetch(self, buf84, 0x6a9af0);
  u8 *t = TABLE;
  u8 *x = (u8 *)SLOT(t, 0x134, v0_t)(t);
  SLOT(x, 0x68, v3_t)(x, (u32)buf84, flag, 0);
  u8 *dst = *(u8 **)(self + 0x94);
  u32 v = *(u32 *)(self + 0x44);
  t = TABLE;
  u32 r = SLOT(t, 0x4c, v1_t)(t, v);
  *(u32 *)(dst + 0x132af) = r;
}
PCREG(579590, fn579590);
