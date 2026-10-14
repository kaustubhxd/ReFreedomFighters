// batch38017.cpp - cascade s8 batch 38017: 0x5a0be0 (load an object's fields from a stream).
#include "ff.h"

extern "C" void THISCALL ext_479190(u8 *self, u8 *s);   // ret 4
extern "C" void THISCALL ext_5a0b80(u8 *self, u8 *s);   // ret 4
extern "C" void THISCALL ext_59d3a0(u8 *self, u8 *s);   // ret 4
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define RD(s, off, dst) SLOT(s, off, v1_t)(s, (u32)(dst))   /* stream read of one field into dst */
#define ENG G(u8 *, 0x70039c)

// 0x5a0be0, thiscall(stream) ret 4, returns true: reads the object's saved fields from the stream by its typed read slots (0x40 = 4-byte, 0x68 / 0x48 / 0x4c / 0x50 / 0x6c = other
// widths), runs the sub-loaders 0x479190, 0x5a0b80 and 0x59d3a0, and rebases two timestamps by the engine table's +0x44 clock.
static bool THISCALL fn5a0be0(u8 *self, u8 *s) {
  u32 l;
  ext_479190(self, s);
  RD(s, 0x50, self + 0x94d);
  RD(s, 0x40, &l);
  *(u32 *)(self + 0x77f) = l;
  RD(s, 0x68, self + 0x783);
  RD(s, 0x40, self + 0x784);
  RD(s, 0x40, self + 0x792);
  RD(s, 0x40, self + 0x796);
  RD(s, 0x40, self + 0x78a);
  RD(s, 0x40, self + 0x78e);
  RD(s, 0x48, self + 0x79a);
  RD(s, 0x4c, self + 0x7a0);
  RD(s, 0x4c, self + 0x7a2);
  RD(s, 0x4c, self + 0x7a4);
  RD(s, 0x6c, self + 0x8fb);
  RD(s, 0x40, self + 0x907);
  RD(s, 0x48, self + 0x90f);
  ext_5a0b80(self + 0x7ce, s);
  SLOT(s, 0x18, v2_t)(s, (u32)(self + 0x8d2), 0x10);
  RD(s, 0x68, self + 0x920);
  RD(s, 0x68, self + 0x929);
  RD(s, 0x4c, self + 0x788);
  u32 t;
  RD(s, 0x40, &t);
  *(u32 *)(self + 0x7b2) = *(u32 *)(*(u8 **)(ENG + 0x9b) + 0x44) + t;
  RD(s, 0x40, &t);
  *(u32 *)(self + 0x7ae) = *(u32 *)(*(u8 **)(ENG + 0x9b) + 0x44) + t;
  ext_59d3a0(*(u8 **)(self + 0x54), s);
  RD(s, 0x40, self + 0x8f2);
  RD(s, 0x68, self + 0x8fa);
  RD(s, 0x68, self + 0x917);
  RD(s, 0x48, self + 0x925);
  return true;
}
PCREG(5a0be0, fn5a0be0);
