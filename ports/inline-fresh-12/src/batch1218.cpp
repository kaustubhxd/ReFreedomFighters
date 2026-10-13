// batch1218.cpp - fresh slice 12, batch 18. Exe callees run as ext_<hex>; the harness hooks and logs them.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 a);                     // ret 4
extern "C" u32 THISCALL ext_506040(u8 *self);                            // ret 0
extern "C" u32 __attribute__((fastcall)) ext_4f4e20(u32 a, u32 b, u32 c, u32 d);   // ret 8
extern "C" u8 *__attribute__((cdecl)) ext_45c4b0(u32 size);              // allocator, cdecl
extern "C" void THISCALL ext_4ee240(u8 *self, u32 a, u32 b, u32 c);     // base constructor, ret 0xc

// 0x555e80: looks up the object registered as name 0x6a5c48 (engine(+0x9b) slot 0x138() ->slot 0x88(name, &id),
// then engine slot 0x58(id)). When found: y = 0x506040(0x5003d0(a->+4, 0)), and the object's slot 0x128 gets
// (u16) engine slot 0x114(y, 0, 0x6a57fc, 0x439, 0, 0). stdcall, ret 4.
static void __attribute__((stdcall)) bind555e80(u8 *a) {
  u8 *eng = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *r = vcall<u8 *>(eng, 0x138);
  u32 id = 0;
  vcall<void>(r, 0x88, 0x6a5c48u, &id);
  u8 *o = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, id);
  if (!o) return;
  u32 y = ext_506040(ext_5003d0(*(u8 **)(a + 4), 0));
  u32 v = vcall<u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x114, y, 0u, 0x6a57fcu, 0x439u, 0u, 0u);
  vcall<void>(o, 0x128, (u32)(u16)v);
}
PCREG(555e80, bind555e80);

// 0x4f4f40: factory (SEH frame, registers restored), fastcall (a, b, c, d). d set -> 0x4f4e20(d, c, a, b). Else o =
// 0x45c4b0(0xc3); o -> base ctor 0x4ee240(o; c, a, b), vtable 0x699f78, +0xb7 = 8. Returns o (0 when the alloc
// failed). ret 8.
static u32 __attribute__((fastcall)) make4f4f40(u32 a, u32 b, u32 c, u32 d) {
  if (d) return ext_4f4e20(d, c, a, b);
  u8 *o = ext_45c4b0(0xc3);
  if (!o) return 0;
  ext_4ee240(o, c, a, b);
  *(u32 *)o = 0x699f78;
  *(u32 *)(o + 0xb7) = 8;
  return (u32)o;
}
PCREG(4f4f40, make4f4f40);
