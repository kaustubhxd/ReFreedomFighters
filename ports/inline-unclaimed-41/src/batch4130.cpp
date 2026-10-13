// batch4130.cpp - unclaimed-41 batch 30 (slice 13): 0x4edc50 ZCollisionBase::InstallInsideBuffer(char*, int) (thiscall, two stack
// arguments s and n, ret 8). The allocator 0x41e290 is cdecl (the caller pops 4). The /GS cookie check is not reproduced.
#include "ff.h"

extern "C" u8 *__attribute__((cdecl)) ext_41e290(u32 size);      // exe allocator, one stack argument, caller pops (stub, GUESS)
extern "C" void THISCALL ext_4e3d60(u8 *self, u8 *s);            // octree constructor, one stack argument, callee pops (stub, GUESS)

// 0x4edc50: when n is not -1, a 0x18-byte object is allocated (zeroed; its first dword is the vtable 0x67d138) and stored at this+0x1a1;
// a null allocation stores null. Then the octree constructor is called with ecx = the object and s.
static void THISCALL fn4edc50(u8 *self, u8 *s, u32 n) {
  if (n != 0xffffffffu) {
    u8 *obj = ext_41e290(0x18u);
    if (obj != 0) {
      for (u32 k = 0; k < 0x18; k += 4)
        *(u32 *)(obj + k) = 0;
      *(u32 *)obj = 0x67d138u;
    }
    *(u32 *)(self + 0x1a1) = (u32)obj;
    ext_4e3d60(obj, s);
  }
}
PCREG(4edc50, fn4edc50);
