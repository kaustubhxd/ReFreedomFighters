// batch37059.cpp - cascade s6 batch 37059: 0x464f50.
#include "ff.h"

extern "C" void THISCALL ext_4db2c0(u8 *self, u32 *a, u32 *b);        // ret 8
extern "C" void FASTCALL ext_441970(u32 *dst, u8 *m, u32 *src);       // ecx / edx + 1 stack arg, ret 4
extern "C" void FASTCALL ext_4de480(u32 *a, u8 *m);                   // ecx / edx, plain ret
extern "C" void FASTCALL ext_441940(u32 *a, u32 *b);                  // ecx / edx, plain ret
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define F32(o) (*(u32 *)(self + (o)))

static void refresh(u8 *self, u32 off) {
  u32 id = F32(off);
  if (!id) return;
  void *t = *(void **)(*(u8 **)0x70039c + 0x9b);
  u8 *o = (u8 *)(*(v1_t **)t)[0x58 / 4](t, id);
  if (!o) return;
  u8 *a = (u8 *)(*(v0_t **)self)[0x20 / 4](self);
  u32 v34[9], v10[3], v40[3];
  ext_4db2c0(*(u8 **)(a + 8), v34, v10);
  ext_441970(v40, self + 0x48, v34);
  ext_4de480(v34, self + 0x24);
  ext_441940(v10, v40);
  (*(v2_t **)o)[0x7c / 4](o, (u32)v34, (u32)v10);
}

// 0x464f50, thiscall, no args: for each of the three object ids at this+0x12a / +0x12e / +0x132 (when the table knows the object) recomputes its transform: asks slot 0x20 of this for
// the owner, takes its frame (0x4db2c0 into a 36-byte and a 12-byte record), combines it with this+0x48 (0x441970) and this+0x24 (0x4de480), derives the 12-byte part (0x441940)
// and passes both records to slot 0x7c of the object.
static void THISCALL fn464f50(u8 *self) {
  refresh(self, 0x12a);
  refresh(self, 0x12e);
  refresh(self, 0x132);
}
PCREG(464f50, fn464f50);
