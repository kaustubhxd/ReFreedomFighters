// batch258.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch258"): CMoveAlongPath::SetNextPath,
// the call that hands a path-following actor (soldiers, tanks on splines) its next path. Name from the GameCube name map.
#include "ff.h"

extern "C" const char *THISCALL ext_4cc1d0(u8 *str);   // original string c_str (returns [this])
extern "C" void THISCALL ext_4cbec0(u8 *str);          // original string destructor

typedef void(__attribute__((cdecl)) * logs_t)(void *, const char *, const char *);
typedef void (*assert_t)();

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

// 0x523b90 CMoveAlongPath::SetNextPath(unsigned path, float speed) ret 8. A zero handle does nothing. A geom that is not a
// path (vt[0x1e0](0x4000022) byte false) logs "WARNING: %s is not a spline. Vehicle cannot move!!!" (0x6a07f4) with the geom's name (vt[0x1d8]
// into a stack string, c_str, destructor; line 0xf6) and calls the assert hook [0x7003b0] (int3 when it is 0); either way the
// geom (db vt[0x58]) is stored at +0x4f and the float at +0x3d (bit copy, movss).
static void THISCALL setNextPath_523b90(u8 *self, u32 path, u32 speedBits) {
  if (!path) return;
  if (!(u8)vcall<u32>((u8 *)vcall<u32>(DB, 0x58, path), 0x1e0, 0x4000022u)) {
    u8 *g = (u8 *)vcall<u32>(DB, 0x58, path);
    void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x6a0778u, 0xf6u);
    u8 str[0x80];
    u8 *sp = (u8 *)vcall<u32>(g, 0x1d8, (u32)str, 1u);
    (*(logs_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6a07f4u, ext_4cc1d0(sp));
    ext_4cbec0(str);
    assert_t a = *(assert_t *)0x7003b0u;
    if (a) a();
    else __builtin_debugtrap();   // the exe jumps to an int3 when no hook is set
  }
  u32 g = vcall<u32>(DB, 0x58, path);
  *(u32 *)(self + 0x4f) = g;
  *(u32 *)(self + 0x3d) = speedBits;
}
#undef DB
PCREG(523b90, setNextPath_523b90);
