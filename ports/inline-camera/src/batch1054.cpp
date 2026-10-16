// batch1054.cpp - ZFFCamera1::ZFFCamera1 (0x5ca720). Camera thread, 2026-10-11.
// The field initialisers are generated from the disassembly in asm order (constants written to +0x4b2..+0x7b9).
#include "cam.h"

#define CDECL __attribute__((cdecl))

extern "C" THISCALL void ext_5c9530(void *self);                                // base constructor
extern "C" CDECL void *ext_41e290(u32 size);                                    // operator new (size 0x108 here)
extern "C" THISCALL void *ext_4d83b0(void *self, u32 a1, u32 a2, u8 *a3);      // sub-object constructor, returns self

// 0x5ca720 ZFFCamera1::ZFFCamera1(void) (thiscall): base constructor, vtable 0x6b4be8, the constant fields, the
// manager call (slot 0x114, result word at +0x59a), a 0x108-byte sub-object at +0x7b0 owned at +0x5a8 (registered
// with the sys object's slot 0x1a4). Returns self.
static THISCALL u8 *ZFFCamera1_Ctor(u8 *self) {
  ext_5c9530(self);
  at<u32>(self, 0) = 0x6b4be8;
  at<u32>(self, 0x4b6) = 0;
  at<u32>(self, 0x4e4) = 0x0;
  at<u32>(self, 0x4e8) = 0x0;
  at<u32>(self, 0x4ec) = 0x0;
  at<u32>(self, 0x4f0) = 0x0;
  at<u8>(self, 0x4f4) = 0x1;
  at<u32>(self, 0x4f5) = 0x0;
  at<u32>(self, 0x4f9) = 0x0;
  at<u32>(self, 0x4fd) = 0x3f800000;
  at<u32>(self, 0x501) = 0x0;
  at<u32>(self, 0x505) = 0x0;
  at<u32>(self, 0x509) = 0x0;
  at<u32>(self, 0x50d) = 0x3ba3d70a;
  at<u32>(self, 0x511) = 0x0;
  at<u32>(self, 0x515) = 0x0;
  at<u32>(self, 0x519) = 0x0;
  at<u32>(self, 0x51d) = 0x0;
  at<u8>(self, 0x521) = 0x1;
  at<u32>(self, 0x522) = 0x0;
  at<u32>(self, 0x526) = 0x0;
  at<u32>(self, 0x52a) = 0x3f800000;
  at<u32>(self, 0x52e) = 0x0;
  at<u32>(self, 0x532) = 0x0;
  at<u32>(self, 0x536) = 0x0;
  at<u32>(self, 0x53a) = 0x3ba3d70a;
  at<u32>(self, 0x53e) = 0x0;
  at<u32>(self, 0x542) = 0x0;
  at<u32>(self, 0x546) = 0x0;
  at<u32>(self, 0x54a) = 0x0;
  at<u8>(self, 0x54e) = 0x1;
  at<u32>(self, 0x54f) = 0x0;
  at<u32>(self, 0x553) = 0x0;
  at<u32>(self, 0x557) = 0x3f800000;
  at<u32>(self, 0x55b) = 0x0;
  at<u32>(self, 0x55f) = 0x0;
  at<u32>(self, 0x563) = 0x0;
  at<u32>(self, 0x567) = 0x3ba3d70a;
  at<u32>(self, 0x56b) = 0x0;
  at<u32>(self, 0x56f) = 0x0;
  at<u32>(self, 0x573) = 0x0;
  at<u32>(self, 0x577) = 0x0;
  at<u8>(self, 0x57b) = 0x1;
  at<u32>(self, 0x57c) = 0x0;
  at<u32>(self, 0x580) = 0x0;
  at<u32>(self, 0x584) = 0x3f800000;
  at<u32>(self, 0x588) = 0x0;
  at<u32>(self, 0x58c) = 0x0;
  at<u32>(self, 0x590) = 0x0;
  at<u32>(self, 0x594) = 0x3ba3d70a;
  at<u32>(self, 0x5ac) = 0x0;
  at<u32>(self, 0x471) = 0x0;
  at<u8>(self, 0x4ca) = 0x0;
  at<u16>(self, 0x598) = 0x0;
  at<u32>(self, 0x2fa) = 0x40a00000;
  at<u8>(self, 0x30a) = 0x0;
  at<u32>(self, 0x68) = 0x0;
  at<u32>(self, 0x64) = 0xffffffff;
  at<u32>(self, 0x4be) = 0x0;
  at<u32>(self, 0x4ba) = 0x0;
  at<u32>(self, 0x4c2) = 0x0;
  at<u32>(self, 0x4c6) = 0x0;
  at<u32>(self, 0x451) = 0x0;
  at<u32>(self, 0x455) = 0x0;
  at<u32>(self, 0x459) = 0x80000000;
  at<u32>(self, 0x45d) = 0x0;
  at<u32>(self, 0x461) = 0x0;
  at<u32>(self, 0x465) = 0x80000000;
  at<u32>(self, 0x4b2) = 0x3e800000;
  at<u32>(self, 0x4b6) = 0;
  at<u32>(self, 0x4d8) = 0x0;
  at<u32>(self, 0x485) = 0x42480000;
  at<u32>(self, 0x479) = 0x43fa0000;
  at<u32>(self, 0x47d) = 0x43fa0000;
  at<u32>(self, 0x489) = 0x43fa0000;
  at<u32>(self, 0x4cb) = 0x0;
  at<u32>(self, 0x4cf) = 0x0;
  at<u32>(self, 0x4d3) = 0x0;
  at<u32>(self, 0x4dc) = 0x0;
  at<u32>(self, 0x4e0) = 0x0;
  at<u32>(self, 0x4ae) = 0xfe967699;
  at<u8>(self, 0xd8) = 0x1;
  at<u32>(self, 0xd9) = 0x44bb8000;
  at<u8>(self, 0x15a) = 0x1;
  at<u32>(self, 0x15b) = 0x44bb8000;
  at<u8>(self, 0x1dc) = 0x1;
  at<u32>(self, 0x1dd) = 0x44bb8000;
  at<u8>(self, 0x25e) = 0x1;
  at<u32>(self, 0x25f) = 0x44bb8000;
  at<u8>(self, 0x2e0) = 0x1;
  at<u32>(self, 0x2e1) = 0x44bb8000;
  u16 mgr_ret = (u16)vcall<u32>(SYS9B, 0x114, (u32)0x6b4ce4, (u32)0, (u32)0x6b4cb4, (u32)0xa5);
  at<u16>(self, 0x59a) = mgr_ret;
  u8 *edi = self + 0x7b0;
  at<u8>(self, 0x7b0) = 0;
  at<u32>(self, 0x7b1) = 0x0;
  at<u32>(self, 0x7b5) = 0x0;
  at<u8>(self, 0x7b9) = 0x0;
  at<u8>(self, 0x4d7) = 0x0;
  at<u32>(self, 0x46d) = 0x3fb4f4ab;
  at<u32>(self, 0x50d) = 0x3ba3d70a;
  at<u32>(self, 0x53a) = 0x3ba3d70a;
  at<u32>(self, 0x567) = 0x3ba3d70a;
  at<u32>(self, 0x594) = 0x3ba3d70a;
  at<u32>(self, 0x475) = 0x0;
  u8 *p = (u8 *)ext_41e290(0x108);
  u8 *owner = 0;
  if (p) owner = (u8 *)ext_4d83b0(p, 0x6b4d14, 0x6b4cf4, edi);
  at<u32>(self, 0x5a8) = (u32)owner;
  vcall<void>(G(u8 *, 0x70039c), 0x1a4, owner);
  return self;
}
PCREG(5ca720, ZFFCamera1_Ctor);
