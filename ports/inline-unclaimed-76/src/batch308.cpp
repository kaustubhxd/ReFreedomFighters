// batch308.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): five scalar-deleting destructors. Each sets its vtable,
// then (if the flag byte's bit 0 is set) frees the object with the exe's cdecl free 0x634273(this, size), and returns this.
#include "ff.h"

// Exe free (cdecl: pointer, size). Recorded by a GUESS stub in the spec.
extern "C" void ext_634273(u32 self, u32 size);

// 0x616b40 (ret 4): vtable 0x6bdc38; if flag bit 0: free(this, 8).
static u32 THISCALL sdtor_616b40(u8 *self, u32 flags) {
    *(u32 *)self = 0x6bdc38u;
    if ((u8)flags & 1u) ext_634273((u32)self, 8u);
    return (u32)self;
}
PCREG(616b40, sdtor_616b40);

// 0x616d30 (ret 4): vtable 0x6bdc40; if flag bit 0: free(this, 0xc).
static u32 THISCALL sdtor_616d30(u8 *self, u32 flags) {
    *(u32 *)self = 0x6bdc40u;
    if ((u8)flags & 1u) ext_634273((u32)self, 0xcu);
    return (u32)self;
}
PCREG(616d30, sdtor_616d30);

// 0x616dd0 (ret 4): vtable 0x6bdc40; if flag bit 0: free(this, 8).
static u32 THISCALL sdtor_616dd0(u8 *self, u32 flags) {
    *(u32 *)self = 0x6bdc40u;
    if ((u8)flags & 1u) ext_634273((u32)self, 8u);
    return (u32)self;
}
PCREG(616dd0, sdtor_616dd0);

// 0x608300 (ret 4): vtable 0x6bc884; if flag bit 0: free(this, 0x14).
static u32 THISCALL sdtor_608300(u8 *self, u32 flags) {
    *(u32 *)self = 0x6bc884u;
    if ((u8)flags & 1u) ext_634273((u32)self, 0x14u);
    return (u32)self;
}
PCREG(608300, sdtor_608300);

// 0x612580 (ret 4): vtable 0x6bd594; if flag bit 0: free(this, 4).
static u32 THISCALL sdtor_612580(u8 *self, u32 flags) {
    *(u32 *)self = 0x6bd594u;
    if ((u8)flags & 1u) ext_634273((u32)self, 4u);
    return (u32)self;
}
PCREG(612580, sdtor_612580);
