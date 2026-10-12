// batch332.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): four factories (thiscall, ret 8, GUESS). Each allocates 8 bytes
// with the exe allocator 0x41e290 (cdecl, one argument); if the result is nonzero, [obj+4] = this and [obj] = the vtable of its class.
// The result (the object or 0) is returned. 0x617050: vtable 0x6bdd74; 0x617090: 0x6bdd34; 0x6170d0: 0x6bddf4; 0x617110: 0x6bddb4.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_41e290(u32 size);

static u32 factory8(u8 *self, u32 vt) {
    u32 obj = ext_41e290(8u);
    if (obj != 0u) {
        *(u32 *)(obj + 4u) = (u32)self;
        *(u32 *)obj = vt;
    }
    return obj;
}

static u32 THISCALL f617050(u8 *self, u32 a, u32 b) { (void)a; (void)b; return factory8(self, 0x6bdd74u); }
PCREG(617050, f617050);
static u32 THISCALL f617090(u8 *self, u32 a, u32 b) { (void)a; (void)b; return factory8(self, 0x6bdd34u); }
PCREG(617090, f617090);
static u32 THISCALL f6170d0(u8 *self, u32 a, u32 b) { (void)a; (void)b; return factory8(self, 0x6bddf4u); }
PCREG(6170d0, f6170d0);
static u32 THISCALL f617110(u8 *self, u32 a, u32 b) { (void)a; (void)b; return factory8(self, 0x6bddb4u); }
PCREG(617110, f617110);
