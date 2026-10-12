// batch324.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): three scalar deleting destructors (thiscall, ret 4, GUESS).
// Each calls its base destructor (exe, thiscall, no arguments); if the flag word has bit 0 set, the CRT free wrapper 0x634273 (cdecl, two
// arguments) runs with (this, size), then returns this. 0x601440: base 0x601020, size 0x19. 0x6081f0: base 0x608080, size 0x14f6.
// 0x613950: base 0x63ab30, size 0xb9b4.
#include "ff.h"

extern "C" void THISCALL ext_601020(u8 *self);
extern "C" void THISCALL ext_608080(u8 *self);
extern "C" void THISCALL ext_63ab30(u8 *self);
extern "C" void __attribute__((cdecl)) ext_634273(u8 *p, u32 size);

static u32 THISCALL sdtor_601440(u8 *self, u32 flags) {
    ext_601020(self);
    if (flags & 1u) ext_634273(self, 0x19u);
    return (u32)self;
}
PCREG(601440, sdtor_601440);

static u32 THISCALL sdtor_6081f0(u8 *self, u32 flags) {
    ext_608080(self);
    if (flags & 1u) ext_634273(self, 0x14f6u);
    return (u32)self;
}
PCREG(6081f0, sdtor_6081f0);

static u32 THISCALL sdtor_613950(u8 *self, u32 flags) {
    ext_63ab30(self);
    if (flags & 1u) ext_634273(self, 0xb9b4u);
    return (u32)self;
}
PCREG(613950, sdtor_613950);
