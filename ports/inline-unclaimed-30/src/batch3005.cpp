// batch3005.cpp - unclaimed-30: batch 5 (docs/20-unclaimed-30.md, claim 1). CMsgForwardToActors::Init(arg, DBREAD&) [map
// 0x49f010; thiscall, ret 8]. If this+4 has bit 2 set: the three fields (word +0x48, word +0x4a, float +0x4c) and the object
// at +0x50 are zeroed. Otherwise the DBREAD gives two words (operator unsigned short, 0x4e5e40) and a float (0x4e5e80), and the
// message table's collision object is asked for the object named 0x685f44 (slot 0x25c, arg 0); when none comes back, the
// reporter prints the error at line 0x1aa.
#include "ff.h"

extern "C" u16 THISCALL ext_4e5e40(u8 *dbread);     // DBREAD::operator unsigned short (patched in the harness)
extern "C" float THISCALL ext_4e5e80(u8 *dbread);   // DBREAD float read (patched in the harness; ST0)

static void THISCALL msgForwardInit(u8 *self, u32 arg, u8 *dbread) {
  (void)arg;
  if (self[4] & 2) {
    *(u32 *)(self + 0x48) = 0;
    *(u32 *)(self + 0x4c) = 0;
    *(u32 *)(self + 0x50) = 0;
    return;
  }
  u16 w1 = ext_4e5e40(dbread);
  *(u16 *)(self + 0x48) = w1;
  u16 w2 = ext_4e5e40(dbread);
  *(u16 *)(self + 0x4a) = w2;
  float f = ext_4e5e80(dbread);
  *(float *)(self + 0x4c) = f;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *msg = *(u8 **)(eng + 0x9b);
  u8 *coll = *(u8 **)(msg + 0xadc);
  u8 *o = (u8 *)vcall<u32>(coll, 0x25c, (u32)0x685f44, (u32)0);
  *(u8 **)(self + 0x50) = o;
  if (!o) {
    void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x68f6b4, 0x1aa);
    typedef void (*reportFn)(void *, const char *);
    (*(reportFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x68f6e0);
  }
}
PCREG(49f010, msgForwardInit);
