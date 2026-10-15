// batch122.cpp - ZFFHeroMovementBaseMove::GetAnims (climb thread, batch 122). Names from the GC map (high). The body is
// generated from the disassembly of 0x5e3e90 (1259 bytes) by tools/gen_basemove_getanims.py: 23 name lookups (slot 0x58),
// 23 register calls (slot 0x54), 20 slot-8 calls on embedded sub-objects (3 args: address, index, float 1.0), 2 guarded
// 24-byte copies, and the call to the base ZMovementBaseMove::GetAnims at the start (bound to the original code).
#include "ff.h"

extern "C" void THISCALL ext_488bc0(void *self);  // ZMovementBaseMove::GetAnims (original code; batch 121 is the port)

static void THISCALL baseMoveGetAnims(u8 *self) {
  ext_488bc0(self);  // ZMovementBaseMove::GetAnims (batch 121 port exists; original code bound here)
  *(u32 *)(self + 0x403) = vcall<u32>(self, 0x58, (const char *)0x68acf8);  // "Stand"
  *(u32 *)(self + 0x41b) = vcall<u32>(self, 0x58, (const char *)0x6b7a38);  // "Sneak_Stand"
  *(u32 *)(self + 0x433) = vcall<u32>(self, 0x58, (const char *)0x6b7a50);  // "Swim_Stand"
  vcall<void>(self, 0x54, (void *)(self + 0x403));
  vcall<void>(self, 0x54, (void *)(self + 0x41b));
  vcall<void>(self, 0x54, (void *)(self + 0x433));
  *(u32 *)(self + 0x6d) = vcall<u32>(self, 0x58, (const char *)0x68d24c);  // "Run_Forward"
  vcall<void>(self, 0x54, (void *)(self + 0x6d));
  *(u32 *)(self + 0xb5) = vcall<u32>(self, 0x58, (const char *)0x6b7a94);  // "Run_Backwards"
  vcall<void>(self, 0x54, (void *)(self + 0xb5));
  *(u32 *)(self + 0x85) = vcall<u32>(self, 0x58, (const char *)0x6b7aa4);  // "Run_Left"
  *(u32 *)(self + 0x9d) = vcall<u32>(self, 0x58, (const char *)0x6b7ab0);  // "Run_Right"
  vcall<void>(self, 0x54, (void *)(self + 0x85));
  vcall<void>(self, 0x54, (void *)(self + 0x9d));
  if (*(u32 *)(self + 0x85) == 0)
    for (int q = 0; q < 24; ++q)  // movups 16 + movq 8
      (self + 0x85)[q] = (self + 0x6d)[q];
  if (*(u32 *)(self + 0x9d) == 0)
    for (int q = 0; q < 24; ++q)  // movups 16 + movq 8
      (self + 0x9d)[q] = (self + 0x6d)[q];
  vcall<void>(self + 0x3d3, 8, (void *)(self + 0x6d), (u32)1, 1.0f);
  vcall<void>(self + 0x3d3, 8, (void *)(self + 0xb5), (u32)2, 1.0f);
  vcall<void>(self + 0x3d3, 8, (void *)(self + 0x85), (u32)3, 1.0f);
  vcall<void>(self + 0x3d3, 8, (void *)(self + 0x9d), (u32)4, 1.0f);
  *(u32 *)(self + 0x27d) = vcall<u32>(self, 0x58, (const char *)0x6b7abc);  // "Sneak_Walk_Forward*"
  *(u32 *)(self + 0x295) = vcall<u32>(self, 0x58, (const char *)0x6b7ad0);  // "Sneak_Walk_Backward*"
  *(u32 *)(self + 0x2ad) = vcall<u32>(self, 0x58, (const char *)0x6b7ae8);  // "Sneak_Walk_Left*"
  *(u32 *)(self + 0x2c5) = vcall<u32>(self, 0x58, (const char *)0x6b7afc);  // "Sneak_Walk_Right*"
  vcall<void>(self, 0x54, (void *)(self + 0x27d));
  vcall<void>(self, 0x54, (void *)(self + 0x295));
  vcall<void>(self, 0x54, (void *)(self + 0x2ad));
  vcall<void>(self, 0x54, (void *)(self + 0x2c5));
  vcall<void>(self + 0x3d, 8, (void *)(self + 0x27d), (u32)1, 1.0f);
  vcall<void>(self + 0x3d, 8, (void *)(self + 0x295), (u32)2, 1.0f);
  vcall<void>(self + 0x3d, 8, (void *)(self + 0x2ad), (u32)3, 1.0f);
  vcall<void>(self + 0x3d, 8, (void *)(self + 0x2c5), (u32)4, 1.0f);
  *(u32 *)(self + 0x373) = vcall<u32>(self, 0x58, (const char *)0x6b7b10);  // "Sneak_Run_Forward*"
  *(u32 *)(self + 0x38b) = vcall<u32>(self, 0x58, (const char *)0x6b7b24);  // "Sneak_Run_Backward*"
  *(u32 *)(self + 0x3a3) = vcall<u32>(self, 0x58, (const char *)0x6b7b38);  // "Sneak_Run_Left*"
  *(u32 *)(self + 0x3bb) = vcall<u32>(self, 0x58, (const char *)0x6b7b48);  // "Sneak_Run_Right*"
  vcall<void>(self, 0x54, (void *)(self + 0x373));
  vcall<void>(self, 0x54, (void *)(self + 0x38b));
  vcall<void>(self, 0x54, (void *)(self + 0x3a3));
  vcall<void>(self, 0x54, (void *)(self + 0x3bb));
  vcall<void>(self + 0x3eb, 8, (void *)(self + 0x373), (u32)1, 1.0f);
  vcall<void>(self + 0x3eb, 8, (void *)(self + 0x38b), (u32)2, 1.0f);
  vcall<void>(self + 0x3eb, 8, (void *)(self + 0x3a3), (u32)3, 1.0f);
  vcall<void>(self + 0x3eb, 8, (void *)(self + 0x3bb), (u32)4, 1.0f);
  *(u32 *)(self + 0x44b) = vcall<u32>(self, 0x58, (const char *)0x6b7b5c);  // "Swim_Forward*"
  *(u32 *)(self + 0x463) = vcall<u32>(self, 0x58, (const char *)0x6b7b6c);  // "Swim_Run_Backward*"
  *(u32 *)(self + 0x47b) = vcall<u32>(self, 0x58, (const char *)0x6b7b80);  // "Swim_Run_Left*"
  *(u32 *)(self + 0x493) = vcall<u32>(self, 0x58, (const char *)0x6b7b90);  // "Swim_Run_Right*"
  vcall<void>(self, 0x54, (void *)(self + 0x44b));
  vcall<void>(self, 0x54, (void *)(self + 0x463));
  vcall<void>(self, 0x54, (void *)(self + 0x47b));
  vcall<void>(self, 0x54, (void *)(self + 0x493));
  vcall<void>(self + 0x4ab, 8, (void *)(self + 0x44b), (u32)1, 1.0f);
  vcall<void>(self + 0x4ab, 8, (void *)(self + 0x463), (u32)2, 1.0f);
  vcall<void>(self + 0x4ab, 8, (void *)(self + 0x47b), (u32)3, 1.0f);
  vcall<void>(self + 0x4ab, 8, (void *)(self + 0x493), (u32)4, 1.0f);
  *(u32 *)(self + 0x4c3) = vcall<u32>(self, 0x58, (const char *)0x6b7ba0);  // "CC_Walk_Forward"
  *(u32 *)(self + 0x4db) = vcall<u32>(self, 0x58, (const char *)0x6b7bb0);  // "CC_Walk_Backwards"
  *(u32 *)(self + 0x4f3) = vcall<u32>(self, 0x58, (const char *)0x6b7bc4);  // "CC_Walk_Left"
  *(u32 *)(self + 0x50b) = vcall<u32>(self, 0x58, (const char *)0x6b7bd4);  // "CC_Walk_Right"
  vcall<void>(self, 0x54, (void *)(self + 0x4c3));
  vcall<void>(self, 0x54, (void *)(self + 0x4db));
  vcall<void>(self, 0x54, (void *)(self + 0x4f3));
  vcall<void>(self, 0x54, (void *)(self + 0x50b));
  vcall<void>(self + 0x523, 8, (void *)(self + 0x4c3), (u32)1, 1.0f);
  vcall<void>(self + 0x523, 8, (void *)(self + 0x4db), (u32)2, 1.0f);
  vcall<void>(self + 0x523, 8, (void *)(self + 0x4f3), (u32)3, 1.0f);
  vcall<void>(self + 0x523, 8, (void *)(self + 0x50b), (u32)4, 1.0f);
}
PCREG(5e3e90, baseMoveGetAnims);
