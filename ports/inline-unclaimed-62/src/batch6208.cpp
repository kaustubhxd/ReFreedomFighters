// batch6208.cpp - unclaimed-62 claim 4 (slice 1): ZGeomIf::GetAngleToObject(OpaqueCallParameters_t &p) [map 0x501050; thiscall, ret 4].
// res = 0. The element 0 of the array at p+4 (exe 0x5003d0): if its dword is non-zero, res = this+0xc's slot 0x194 (that dword), a float in ST0.
// Then the element 0 of the array at p+8: its tag byte other than 0 and 2 reports line 0x104 (format 0x69c6b0, text 0x69c938) and calls the
// assert hook (int3 when none). Last: the float res goes to the second element (b) and its byte +4 becomes 2.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 index);   // exe: element pointer (ret 4)

typedef void (*reportStrFn)(void *, const char *, const char *);

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wrf(u8 *p, float f) { __builtin_memcpy(p, &f, 4); }

static void THISCALL geomIfGetAngleToObject(u8 *self, u8 *p) {
  float res = 0.0f;
  u8 *a = ext_5003d0(rdp(p + 4), 0);
  u32 edx = rd32u(a);
  if (edx != 0) {
    u8 *obj = rdp(self + 0xc);
    res = vcall<float>(obj, 0x194, edx);
  }
  u8 *b = ext_5003d0(rdp(p + 8), 0);
  u8 tag = b[4];
  if (tag != 0 && tag != 2) {
    void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x69c8e0, 0x104);
    (*(reportStrFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x69c6b0, (const char *)0x69c938);
    typedef void (*hookfn)();
    hookfn h = G(hookfn, 0x7003b0);
    if (h) h();
    else __builtin_debugtrap();
  }
  // the exe stores through esi, which now holds the second element (b), not p
  wrf(b, res);
  b[4] = 2;
}
PCREG(501050, geomIfGetAngleToObject);
