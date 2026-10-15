// batch121.cpp - ZMovementBaseMove::GetAnims (climb thread, batch 121). Names from the GC map (high). The body is
// generated from the disassembly of 0x488bc0 (1437 bytes, 31 name lookups, 31 register calls, 12 slot-8 calls, 8
// constant stores and 2 guarded 24-byte copies), keeping the exe's order. ebx = this+0x6d and esi = this+0x9d as in the exe.
#include "ff.h"

static void THISCALL movementBaseMoveGetAnims(u8 *self) {
  u8 *ebx_ = self + 0x6d;   // ebx = edi+0x6d at entry (never reassigned)
  u8 *esi_ = self + 0x9d;   // esi = edi+0x9d from the first use on
  *(u32 *)ebx_ = vcall<u32>(self, 0x58, (const char *)0x68d24c);  // "Run_Forward"
  *(u32 *)(self + 0x85) = vcall<u32>(self, 0x58, (const char *)0x68d258);  // "Run*Str*Left"
  *(u32 *)(self + 0x9d) = vcall<u32>(self, 0x58, (const char *)0x68d268);  // "Run*Str*Right"
  *(u32 *)(self + 0xb5) = vcall<u32>(self, 0x58, (const char *)0x68d278);  // "Run*Backward*"
  *(u32 *)(self + 0xcd) = vcall<u32>(self, 0x58, (const char *)0x68d288);  // "Run*Stair*Up*2*"
  *(u32 *)(self + 0xe5) = vcall<u32>(self, 0x58, (const char *)0x68d298);  // "Run*Stair*Down*"
  *(u32 *)(self + 0xfd) = vcall<u32>(self, 0x58, (const char *)0x68d2a8);  // "Run*Stop"
  *(u32 *)(self + 0x115) = vcall<u32>(self, 0x58, (const char *)0x68d2b4);  // "Walk_Forward"
  *(u32 *)(self + 0x12d) = vcall<u32>(self, 0x58, (const char *)0x68d2c4);  // "Walk_Backward"
  *(u32 *)(self + 0x145) = vcall<u32>(self, 0x58, (const char *)0x68d2d4);  // "Walk_Left*"
  *(u32 *)(self + 0x15d) = vcall<u32>(self, 0x58, (const char *)0x68d2e0);  // "Walk_Right*"
  *(u32 *)(self + 0x175) = vcall<u32>(self, 0x58, (const char *)0x68d288);  // "Run*Stair*Up*2*"
  *(u32 *)(self + 0x18d) = vcall<u32>(self, 0x58, (const char *)0x68d2ec);  // "Walk_Stair*Down"
  *(u32 *)(self + 0x1a5) = vcall<u32>(self, 0x58, (const char *)0x68d2fc);  // "Turn*L*"
  *(u32 *)(self + 0x1bd) = vcall<u32>(self, 0x58, (const char *)0x68d304);  // "Turn*R*"
  *(u32 *)(self + 0x1d5) = vcall<u32>(self, 0x58, (const char *)0x68d30c);  // "Lean*Forward"
  *(u32 *)(self + 0x1ed) = vcall<u32>(self, 0x58, (const char *)0x68d31c);  // "Lean*Backward"
  *(u32 *)(self + 0x205) = vcall<u32>(self, 0x58, (const char *)0x68d32c);  // "Lean_Out_Left"
  *(u32 *)(self + 0x21d) = vcall<u32>(self, 0x58, (const char *)0x68d33c);  // "Lean_Out_Right"
  *(u32 *)(self + 0x235) = vcall<u32>(self, 0x58, (const char *)0x68d34c);  // "LeanOut*L*Shoot"
  *(u32 *)(self + 0x24d) = vcall<u32>(self, 0x58, (const char *)0x68d35c);  // "LeanOut*R*Shoot"
  *(u32 *)(self + 0x27d) = vcall<u32>(self, 0x58, (const char *)0x68d36c);  // "Sneak_Forward*"
  *(u32 *)(self + 0x295) = vcall<u32>(self, 0x58, (const char *)0x68d37c);  // "Sneak_Backward*"
  *(u32 *)(self + 0x2ad) = vcall<u32>(self, 0x58, (const char *)0x68d38c);  // "Sneak_Left*"
  *(u32 *)(self + 0x2c5) = vcall<u32>(self, 0x58, (const char *)0x68d398);  // "Sneak_Right*"
  *(u32 *)(self + 0x2dd) = vcall<u32>(self, 0x58, (const char *)0x68d3a8);  // "Sneak_Turn_Left"
  *(u32 *)(self + 0x2f5) = vcall<u32>(self, 0x58, (const char *)0x68d3b8);  // "Sneak_Turn_Right"
  *(u32 *)(self + 0x30d) = vcall<u32>(self, 0x58, (const char *)0x68d3cc);  // "Drag_Forward*"
  *(u32 *)(self + 0x325) = vcall<u32>(self, 0x58, (const char *)0x68d3dc);  // "Drag_Backward*"
  *(u32 *)(self + 0x33d) = vcall<u32>(self, 0x58, (const char *)0x68d3ec);  // "Drag_Left*"
  *(u32 *)(self + 0x355) = vcall<u32>(self, 0x58, (const char *)0x68d3f8);  // "Drag_Right*"
  vcall<void>(self + 0x25, 8, (void *)(self + 0x115), (u32)1, 1.0f);
  vcall<void>(self + 0x25, 8, (void *)(self + 0x12d), (u32)2, 1.0f);
  vcall<void>(self + 0x25, 8, (void *)(self + 0x145), (u32)3, 1.0f);
  vcall<void>(self + 0x25, 8, (void *)(self + 0x15d), (u32)4, 1.0f);
  vcall<void>(self + 0x3d, 8, (void *)(self + 0x27d), (u32)1, 1.0f);
  vcall<void>(self + 0x3d, 8, (void *)(self + 0x295), (u32)2, 1.0f);
  vcall<void>(self + 0x3d, 8, (void *)(self + 0x2ad), (u32)3, 1.0f);
  vcall<void>(self + 0x3d, 8, (void *)(self + 0x2c5), (u32)4, 1.0f);
  vcall<void>(self + 0x55, 8, (void *)(self + 0x30d), (u32)1, 1.0f);
  vcall<void>(self + 0x55, 8, (void *)(self + 0x325), (u32)2, 1.0f);
  vcall<void>(self + 0x55, 8, (void *)(self + 0x33d), (u32)3, 1.0f);
  vcall<void>(self + 0x55, 8, (void *)(self + 0x355), (u32)4, 1.0f);
  vcall<void>(self, 0x54, (void *)ebx_);
  vcall<void>(self, 0x54, (void *)(self + 0x85));
  vcall<void>(self, 0x54, (void *)esi_);
  if (*(u32 *)(self + 0x85) == 0)
    for (int q = 0; q < 24; ++q)  // movups 16 + movq 8
      (self + 0x85)[q] = ebx_[q];
  if (*(u32 *)esi_ == 0)
    for (int q = 0; q < 24; ++q)  // movups 16 + movq 8
      esi_[q] = ebx_[q];
  vcall<void>(self, 0x54, (void *)(self + 0xb5));
  vcall<void>(self, 0x54, (void *)(self + 0xcd));
  vcall<void>(self, 0x54, (void *)(self + 0xe5));
  vcall<void>(self, 0x54, (void *)(self + 0xfd));
  vcall<void>(self, 0x54, (void *)(self + 0x115));
  vcall<void>(self, 0x54, (void *)(self + 0x12d));
  vcall<void>(self, 0x54, (void *)(self + 0x145));
  vcall<void>(self, 0x54, (void *)(self + 0x15d));
  vcall<void>(self, 0x54, (void *)(self + 0x175));
  vcall<void>(self, 0x54, (void *)(self + 0x18d));
  vcall<void>(self, 0x54, (void *)(self + 0x1a5));
  vcall<void>(self, 0x54, (void *)(self + 0x1bd));
  vcall<void>(self, 0x54, (void *)(self + 0x1d5));
  vcall<void>(self, 0x54, (void *)(self + 0x1ed));
  vcall<void>(self, 0x54, (void *)(self + 0x205));
  vcall<void>(self, 0x54, (void *)(self + 0x21d));
  vcall<void>(self, 0x54, (void *)(self + 0x235));
  vcall<void>(self, 0x54, (void *)(self + 0x24d));
  *(u32 *)(self + 0x241) = 0x428c0000;
  *(u32 *)(self + 0x245) = 0x0;
  *(u32 *)(self + 0x249) = 0x0;
  *(u32 *)(self + 0x239) = 0x40c00000;
  *(u32 *)(self + 0x259) = 0xc28c0000;
  *(u32 *)(self + 0x25d) = 0x0;
  *(u32 *)(self + 0x261) = 0x0;
  *(u32 *)(self + 0x251) = 0x40c00000;
  vcall<void>(self, 0x54, (void *)(self + 0x30d));
  vcall<void>(self, 0x54, (void *)(self + 0x325));
  vcall<void>(self, 0x54, (void *)(self + 0x33d));
  vcall<void>(self, 0x54, (void *)(self + 0x355));
  vcall<void>(self, 0x54, (void *)(self + 0x27d));
  vcall<void>(self, 0x54, (void *)(self + 0x295));
  vcall<void>(self, 0x54, (void *)(self + 0x2ad));
  vcall<void>(self, 0x54, (void *)(self + 0x2c5));
  vcall<void>(self, 0x54, (void *)(self + 0x2dd));
  vcall<void>(self, 0x54, (void *)(self + 0x2f5));
}
PCREG(488bc0, movementBaseMoveGetAnims);
