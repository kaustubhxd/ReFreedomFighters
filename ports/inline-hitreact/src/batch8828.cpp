// batch8828.cpp - wire-hit-parts run 9 (2026-10-16): ZBoneAnim::AddCallBackAlways 0x461570 (GC 8017fa94).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" void *ext_41e290(u32 size);                                     // operator new (cdecl; exe)
extern "C" u8 *THISCALL ext_4ccad0(void *self, u32 a, u32 b);              // LINKSORTREFTAB::LINKSORTREFTAB(a, b), returns this

typedef u8 *(THISCALL *vInsert)(void *self, u32 a, float key, u32 b);

// 0x461570 ZBoneAnim::AddCallBackAlways(float frame, callback fn, u32 data) (thiscall, ret 0xc). The exe's try frame around the allocation
// (fs:[0]) is not reproduced. With no callback table at +0x6c one is made: new(0x2c) -> LINKSORTREFTAB(0x20, 3) (0 when new fails). Then the
// table's slot 0x98(0, frame, 0) inserts an entry sorted by frame and returns its data pointer e: e[-4] = data, e[0] = 1, e[4] = fn.
static void THISCALL addCallBackAlways(u8 *self, float frame, u32 fn, u32 data) {
  if (*(u32 *)(self + 0x6c) == 0) {
    void *p = ext_41e290(0x2c);
    *(u8 **)(self + 0x6c) = p ? ext_4ccad0(p, 0x20, 3) : 0;
  }
  void *tab = *(void **)(self + 0x6c);
  u8 *e = ((vInsert)VT(tab, 0x98))(tab, 0, frame, 0);
  *(u32 *)(e - 4) = data;
  *(u32 *)e = 1;
  *(u32 *)(e + 4) = fn;
}
PCREG(461570, addCallBackAlways);
