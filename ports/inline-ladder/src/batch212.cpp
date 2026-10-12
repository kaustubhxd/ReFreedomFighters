// batch212.cpp - base action set (inline-ladder thread, 2026-10-11): ZLNKWHANDS::CreateLnkAction.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void *ext_41e290(u32 size);   // __builtin_new, cdecl
extern "C" void *THISCALL ext_485ca0(void *o, u32 id, void *h, void *hand, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);   // ChamberItem
extern "C" void *THISCALL ext_485d00(void *o, u32 id, void *h, void *hand, u32 a);                     // DropItem
extern "C" void *THISCALL ext_485d30(void *o, u32 id, void *h, void *hand, u32 a, u32 b);             // GetItem
extern "C" void *THISCALL ext_485d70(void *o, u32 id, void *h, void *hand, u32 a);                     // PickupItem
extern "C" void *THISCALL ext_485db0(void *o, u32 id, void *h, void *hand, u32 a);                     // PushButton
extern "C" void *THISCALL ext_485df0(void *o, u32 id, void *h, void *hand, u32 a, u32 b);             // PutItem
extern "C" void *THISCALL ext_485e30(void *o, u32 id, void *h, void *hand, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f,
                                     u32 g);                                                          // ReloadItem
extern "C" void *THISCALL ext_485e90(void *o, u32 id, void *h, void *from, void *to, u32 a);          // SwapItems

// 0x4733d0, ZLNKWHANDS::CreateLnkAction(unsigned id) [GC 80188b1c, medium], vtable slot 0x3ec of ZLNKWHANDS, ZActor,
// ZPlayer and ZPlayerTest (and the default of ZFFHERO's own CreateLnkAction), thiscall, ret 4, returns the action or 0.
// Two hands: A at +0x2e7 and B at +0x34f (ZIKHAND members). Odd ids use hand A, even ids hand B (except 0xb, 0xc, 0xd,
// 0xf; see the table in docs/20-ladder.md). Animation fields are passed by value. Ids outside 1..0xf return 0.
static void *THISCALL lnkCreateLnkAction(u8 *self, u32 id) {
  u8 *A = self + 0x2e7, *B = self + 0x34f;
  void *p;
#define NEW(n)            \
  p = ext_41e290(n);      \
  if (!p) return 0;
  switch (id) {
  case 1: NEW(0x18) return ext_485db0(p, 1, self, A, U32(self, 0x21a));
  case 2: NEW(0x18) return ext_485db0(p, 2, self, B, U32(self, 0x21e));
  case 3: NEW(0x18) return ext_485d70(p, 3, self, A, U32(self, 0x212));
  case 4: NEW(0x18) return ext_485d70(p, 4, self, B, U32(self, 0x216));
  case 5: NEW(0x18) return ext_485df0(p, 5, self, A, U32(self, 0x1fa), U32(self, 0x202));
  case 6: NEW(0x18) return ext_485df0(p, 6, self, B, U32(self, 0x1fe), U32(self, 0x206));
  case 7: NEW(0x1c) return ext_485d30(p, 7, self, A, U32(self, 0x1ea), U32(self, 0x1fa));
  case 8: NEW(0x1c) return ext_485d30(p, 8, self, B, U32(self, 0x1ee), U32(self, 0x1f6));
  case 9: NEW(0x14) return ext_485d00(p, 9, self, A, U32(self, 0x20a));
  case 0xa: NEW(0x14) return ext_485d00(p, 0xa, self, B, U32(self, 0x20e));
  case 0xb: NEW(0x18) return ext_485e90(p, 0xb, self, B, A, U32(self, 0x222));
  case 0xc:
    NEW(0x40) return ext_485e30(p, 0xc, self, A, U32(self, 0x226), U32(self, 0x22e), U32(self, 0x236), U32(self, 0x232),
                                U32(self, 0x23a), U32(self, 0x25e), U32(self, 0x262));
  case 0xd:
    NEW(0x40) return ext_485e30(p, 0xd, self, B, U32(self, 0x22a), U32(self, 0x22e), U32(self, 0x236), U32(self, 0x232),
                                U32(self, 0x23a), U32(self, 0x25e), U32(self, 0x262));
  case 0xe:
    NEW(0x30) return ext_485ca0(p, 0xe, self, B, U32(self, 0x2bb), U32(self, 0x2bf), U32(self, 0x2c3), U32(self, 0x2c7),
                                U32(self, 0x2cb), U32(self, 0x2cf));
  case 0xf:
    NEW(0x30) return ext_485ca0(p, 0xf, self, A, U32(self, 0x2b7), U32(self, 0x2bf), U32(self, 0x2c3), U32(self, 0x2c7),
                                U32(self, 0x2cb), U32(self, 0x2cf));
  default:
    return 0;
  }
#undef NEW
}
PCREG(4733d0, lnkCreateLnkAction);
