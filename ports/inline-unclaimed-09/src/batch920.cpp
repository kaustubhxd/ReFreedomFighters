// batch920.cpp - unclaimed-09 batch 12: 0x4a1300 (docs/20-unclaimed-09.md, claim 12). The GC name says CAction::SafeDelete,
// but the body is an eight-argument field initialiser (GUESS on the name). thiscall, ret 0x20. Virtual calls are
// unverified callees, stubbed in the spec.
#include "ff.h"

typedef void(THISCALL *Init88)(u8 *self, u32 a, u32 b);   // vt+0x88
typedef void(THISCALL *Init1)(u8 *self, u32 a);           // vt+0xa8

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x4a1300, CAction::SafeDelete() (low; the body is an initialiser): vt+0x88(a1, a2); this+0x48 = a3; this+0x4c = the
// low word of a4; this+0x4e = a5 (dword); vt+0xa8(a6); this+0x56 = a7; this+0x106 = a8; ret 0x20.
static void THISCALL actionInit(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8) {
  ((Init88)slot(self, 0x88))(self, a1, a2);
  *(u32 *)(self + 0x48) = a3;
  *(u16 *)(self + 0x4c) = (u16)a4;
  *(u32 *)(self + 0x4e) = a5;
  ((Init1)slot(self, 0xa8))(self, a6);
  *(u32 *)(self + 0x56) = a7;
  *(u32 *)(self + 0x106) = a8;
}
PCREG(4a1300, actionInit);
