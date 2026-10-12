// batch313.cpp - own slice (residue 15): 0x5c53f0, CTargetObtained::Command(unsigned short, void*) (thiscall, ret 8; GUESS).
// Vtable offsets are bytes. The data argument is never read. The exe's stack cookie check (0x633654) is not reproduced.
// Block 1: when cmd == word [this+0x148] and 0x5c5620(this) == 0: dat = eng.[0x9b]; o = dat.vtbl[0x138](); o.vtbl[0x88](0x6a5c48, &t);
//          e = dat.vtbl[0x58](t); if e != 0: w = dat.vtbl[0x114](0x6a5c58, 0, 0x6b4204, 0x94, this+0x48, 0); e.vtbl[0x128](w).
//          s = (dat.[0xae4]).vtbl[0](this+0xc8, 0x677b5a); if stricmp(s, 0x677b5a) == 0 then s = this+0xc8;
//          x = 0x589c20 (ECX = [0x7003b8]) (0); 0x59a580(x, s, -1, 0); 0x5c5810(this).
//          If byte [this+0x152] != 0: o = dat.vtbl[0x138](); o.vtbl[0x88](0x681320, &t); e = dat.vtbl[0x58](t);
//          if e.[0x852] != 0: 0x596940 (ECX = e.[0x852]) (3, &u, 1, -1) with u = 0.
#include "ff.h"

typedef int(__attribute__((cdecl)) * stricmp_t)(const char *a, const char *b);
#define CRT_STRICMP_313 (*(stricmp_t *)0x676414)

extern "C" u32 THISCALL ext_5c5620(u8 *self);
extern "C" void THISCALL ext_5c5810(u8 *self);
extern "C" u32 THISCALL ext_589c20(u32 ecx, u32 a);       // exe reads ECX = [0x7003b8] before the call
extern "C" void THISCALL ext_59a580(u8 *self, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_596940(u32 ecx, u32 a, u32 *p, u32 b, u32 c);  // ECX = e.[0x852]

static void THISCALL command_5c53f0(u8 *self, u16 cmd, u32 data) {
    (void)data;
    if (cmd != *(u16 *)(self + 0x148u)) return;
    if (ext_5c5620(self) != 0u) return;
    {
        u32 dat = *(u32 *)(G(u32, 0x70039cu) + 0x9bu);
        u32 t = 0u;
        u32 o = vcall<u32>((void *)dat, 0x138u);
        vcall<void>((void *)o, 0x88u, 0x6a5c48u, (u32)&t);
        u32 e = vcall<u32>((void *)dat, 0x58u, t);
        if (e != 0u) {
            u16 w = (u16)vcall<u32>((void *)dat, 0x114u, 0x6a5c58u, 0u, 0x6b4204u, 0x94u, (u32)(self + 0x48u), 0u);
            vcall<void>((void *)e, 0x128u, (u32)w);
        }
    }
    u32 dat2 = *(u32 *)(G(u32, 0x70039cu) + 0x9bu);
    u32 obj = *(u32 *)(dat2 + 0xae4u);
    u32 s = vcall<u32>((void *)obj, 0u, (u32)(self + 0xc8u), 0x677b5au);
    if (CRT_STRICMP_313((const char *)s, (const char *)0x677b5au) == 0) s = (u32)(self + 0xc8u);
    u32 x = ext_589c20(G(u32, 0x7003b8u), 0u);
    ext_59a580((u8 *)x, s, 0xffffffffu, 0u);
    ext_5c5810(self);
    if (*(u8 *)(self + 0x152u) == 0) return;
    {
        u32 dat = *(u32 *)(G(u32, 0x70039cu) + 0x9bu);
        u32 t = 0u;
        u32 o = vcall<u32>((void *)dat, 0x138u);
        vcall<void>((void *)o, 0x88u, 0x681320u, (u32)&t);
        u32 e = vcall<u32>((void *)dat, 0x58u, t);
        if (*(u32 *)(e + 0x852u) != 0u) {
            u32 u = 0u;
            ext_596940(*(u32 *)(e + 0x852u), 3u, &u, 1u, 0xffffffffu);
        }
    }
}
PCREG(5c53f0, command_5c53f0);
