// batch38048.cpp - cascade s8 batch 38048: 0x46f020 (show a caption for the object on its text target).
#include "ff.h"

typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v8_t)(void *, u32, u32, u32, u32, u32, u32, u32, u32);
typedef u32(*fmt4_t)(void *, char *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)

// 0x46f020, thiscall, no args, plain ret. With this[0x60] set: builds a caption string in a 0x100-byte stack buffer (the text object at engine table +0xae4 looks up two format strings, the engine's text
// formatter slot 0x198 formats them with the name of this object, slot 0x2e8, default string 0x67c8e8) and shows it on a target found with slot 0x2f8(0) / 0x2f8(0x10) (an already existing target
// gets slot 0x88(buf, buf), otherwise the target made by slot 0x10c is initialised and slot 0xb0 gets the buffer, a row offset 0xc8 / 0xcd (flag tests 0x1007d2 / 0x1007d8, minus 0xd7 - slot
// 0x330 for the first) corrected by the partner kind slots 0x300 / 0x308), then slot 0xb8. A freshly made target with bit 0 of byte +4 set takes the original's null-pointer path (faults).
static void THISCALL fn46f020(u8 *self) {
  char buf[0x100];
  if (*(u32 *)(self + 0x60) == 0) return;
  u8 *rec = (u8 *)SLOT(self, 0x2e8, v0_t)(self);
  u32 s = 0x67c8e8;
  if (*(u32 *)(rec + 4)) s = *(u32 *)(rec + 4);
  u8 *t = *(u8 **)(ENG + 0x9b);
  u8 *o = *(u8 **)(t + 0xae4);
  u32 fmt1 = SLOT(o, 0, v2_t)(o, 0x68899c, s);
  u8 *a = (u8 *)SLOT(ENG, 0x190, v0_t)(ENG);
  t = *(u8 **)(ENG + 0x9b);
  o = *(u8 **)(t + 0xae4);
  u32 fmt2 = SLOT(o, 0, v2_t)(o, 0x6889b8, 0x6889b0);
  (*(fmt4_t **)a)[0x198 / 4](a, buf, fmt2, fmt1);
  u8 *edi = (u8 *)SLOT(self, 0x2f8, v1_t)(self, 0);
  if (edi) {
    SLOT(edi, 0x88, v2_t)(edi, (u32)buf, (u32)buf);
  } else {
    edi = (u8 *)SLOT(self, 0x2f8, v1_t)(self, 0x10);
    if (!edi) {
      edi = (u8 *)SLOT(self, 0x10c, v2_t)(self, 0x6889cc, 0);
      if (!(edi[4] & 1)) {
        SLOT(edi, 8, v0_t)(edi);
        edi[4] |= 4;
        edi[4] |= 0;
      }
      if (!(edi[4] & 1)) {
        SLOT(edi, 0xc, v0_t)(edi);
        *(u32 *)(edi + 4) |= 8;
      }
      if (edi[4] & 1) {
        SLOT(edi, 0x4c, v0_t)(edi);
        SLOT(edi, 0x54, v1_t)(edi, *(u32 *)(edi + 0x30));
        *(u32 *)(edi + 4) |= 0x100;
        edi = 0;
        (void)*(volatile u8 *)(edi + 4);   // the original dereferences the cleared pointer here
        return;
      }
    }
    u32 base = 0xc8;
    u32 v;
    if ((u8)SLOT(self, 0x1e0, v1_t)(self, 0x1007d2)) {
      u8 *r2 = (u8 *)SLOT(self, 0x2e8, v0_t)(self);
      v = 0xd7 - SLOT(r2, 0x330, v0_t)(r2);
    } else {
      if ((u8)SLOT(self, 0x1e0, v1_t)(self, 0x1007d8)) base = 0xcd;
      u8 *r3 = (u8 *)SLOT(self, 0x2e8, v0_t)(self);
      bool k2 = SLOT(r3, 0x300, v0_t)(r3) == 2;
      bool k1 = SLOT(r3, 0x308, v0_t)(r3) == 1;
      v = k2 ? base - 5 : base;
      if (k1) v -= 5;
    }
    SLOT(edi, 0xb0, v8_t)(edi, (u32)buf, (u32)buf, 0, 0, 0, v, 0, 0);
  }
  SLOT(edi, 0xb8, v0_t)(edi);
}
PCREG(46f020, fn46f020);
