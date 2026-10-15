// batch67557.cpp - cascade s6 batch 67557: 0x506960.
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u32 self, u32 idx);        // value node by index, ret 4
extern "C" void THISCALL ext_5094c0(u8 *self, u8 *obj, u32 *m, u32 *v);   // ret 0xc
extern "C" void THISCALL ext_4daf90(u8 *e, u32 *v);            // ret 4
extern "C" void FASTCALL ext_4419f0(u32 *v, u32 *m);           // plain ret
extern "C" void FASTCALL ext_441940(u32 *v, u32 *w);           // plain ret

typedef void (__cdecl *log67557_t)(u8 *, ...);

// 0x506960, thiscall(req) ret 4, no return value: pushes an object's transform to the owner's slot 0x370. The object comes from the request's first value node (object table sys[0x9b] slot 0x58); its
// slot 0x80 fills a 12-dword matrix and a 3-dword vector. Objects accepted by slot 0x1e0(0x2000e1) are handled by 0x5094c0; others that fail slot 0x1e0(0x200006) get the vector rebuilt from the
// object's +8 child (0x4daf90 -> 0x4419f0 with the matrix -> 0x441940 into the vector). The result is handed to this[0x18] slot 0x370(matrix, vector). A missing object logs (0x20b) with this[0x18]'s name.
static void THISCALL fn506960(u8 *self, u8 *req) {
  u32 m[12], v[3];
  u32 *w = &m[9];   // the original's 3-dword temporary sits on the matrix's last three dwords
  u32 *n = ext_5003d0(*(u32 *)(req + 4), 0);
  u8 *obj = vcall<u8 *>(*(u8 **)(*(u8 **)0x70039c + 0x9b), 0x58, n[0]);
  if (!obj) {
    u8 *lg = *(u8 **)0x700390;
    u8 *x = vcall<u8 *>(lg, 0x20, 0x69cff0u, 0x20bu);
    u8 *y = vcall<u8 *>(*(u8 **)(self + 0x18), 0x20);
    (*(log67557_t *)(*(u8 **)x + 0x30))(x, 0x69d10cu, *(u32 *)(y + 4));
    return;
  }
  vcall<void>(obj, 0x80, (u32)m, (u32)v);
  if ((u8)vcall<u32>(obj, 0x1e0, 0x2000e1u)) {
    ext_5094c0(self, obj, m, v);
  } else if (!(u8)vcall<u32>(obj, 0x1e0, 0x200006u)) {
    ext_4daf90(*(u8 **)(obj + 8), w);
    ext_4419f0(w, m);
    ext_441940(v, w);
  }
  vcall<void>(*(u8 **)(self + 0x18), 0x370, (u32)m, (u32)v);
}
PCREG(506960, fn506960);
