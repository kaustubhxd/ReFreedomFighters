// batch249.cpp - ZFFHERO::CalcObjectsMatPos(CAction *a, float *mat, float *pos) (inline-ladder thread, 2026-10-11).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_4de7a0(void *mat);   // mreset (identity matrix), ECX = matrix

static inline bool isItem(u32 obj) { return (u8)vcall<u32>((void *)obj, 0x1e0, 0x1007d1u) != 0; }

// 0x58c150 ZFFHERO::CalcObjectsMatPos(CAction *a, float *mat, float *pos) [, high], thiscall, ret 0xc, returns AL.
// obj = a+0x44. An item-class object: obj slot 0x2e0(mat, pos) and slot 0x98(mat, pos); true.
// Else o = obj slot 0x20: if o and isItem(o) (o = obj slot 0x20 again): o2 = obj slot 0x20; o2 slot 0x2e0 and 0x98 with
// (mat, pos); return o2 != 0.
// Else the global G2 slot 0xcc(a+0x106): zero means the error line "ERROR: ZFFHERO::CalcObjectsMatPos" (logger), false.
// Nonzero: pos = 0, mreset(mat); when obj has class flag 0x200074, obj slot 0x390(obj slot 0x3a8(mat, pos)); then
// obj slot 0x98(mat, pos); return G2 slot 0xcc(a+0x106) != 0.
static bool THISCALL heroCalcObjectsMatPos(u8 *self, u8 *a, float *mat, float *pos) {
  (void)self;
  u32 obj = U32(a, 0x44);
  if (isItem(obj)) {
    vcall<void>((void *)obj, 0x2e0, mat, pos);
    vcall<void>((void *)obj, 0x98, mat, pos);
    return true;
  }
  if (vcall<u32>((void *)obj, 0x20)) {
    u32 y = vcall<u32>((void *)obj, 0x20);
    if (isItem(y)) {
      u32 o2 = vcall<u32>((void *)obj, 0x20);
      vcall<void>((void *)o2, 0x2e0, mat, pos);
      vcall<void>((void *)o2, 0x98, mat, pos);
      return o2 != 0;
    }
  }
  u8 *g2 = (u8 *)G(u32, 0x70038c);
  u32 r = vcall<u32>(g2, 0xcc, U32(a, 0x106));
  if (!r) {
    void *logger = (void *)G(u32, 0x700390);
    void *printer = vcall<void *>(logger, 0x20, (const char *)0x6ac6d0, 0x377u);
    typedef void (*printT)(void *, const char *);
    u8 *pvt = *(u8 **)printer;
    ((printT)U32(pvt, 0x2c))(printer, (const char *)0x6ac9a8);   // "ERROR: ZFFHERO::CalcObjectsMatPos"
    return false;
  }
  pos[0] = 0.0f;
  pos[1] = 0.0f;
  pos[2] = 0.0f;
  ext_4de7a0(mat);
  if (vcall<u32>((void *)obj, 0x1e0, 0x200074u) & 0xff) {
    u32 v = vcall<u32>((void *)obj, 0x3a8, mat, pos);
    vcall<void>((void *)obj, 0x390, v);
  }
  vcall<void>((void *)obj, 0x98, mat, pos);
  g2 = (u8 *)G(u32, 0x70038c);
  u32 r2 = vcall<u32>(g2, 0xcc, U32(a, 0x106));
  return r2 != 0;
}
PCREG(58c150, heroCalcObjectsMatPos);
