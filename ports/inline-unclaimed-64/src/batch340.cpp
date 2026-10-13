// batch340.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe helpers, run as original code (thiscall). 0x524780 and 0x524410: ecx = sub-object, one stack word = stream, ret 4.
// 0x524760: ecx = sub-object, two stack words, ret 8; it stores them at +0x18 and +0x1c.
extern "C" void THISCALL ext_524780(u8 *sub, u8 *stream);
extern "C" void THISCALL ext_524410(u8 *sub, u8 *stream);
extern "C" void THISCALL ext_524760(u8 *sub, u32 first, u32 second);

// Virtual calls on the stream object: slot 0x6c, 0x50 and 0x68 (one word each), 0x18 (two words).
typedef void(__attribute__((thiscall)) * Slot1Fn)(u8 *, u32);
typedef void(__attribute__((thiscall)) * Slot2Fn)(u8 *, u32, u32);

// 0x516470: thiscall (ecx = self, one stack pointer stream, ret 4), returns true (al = 1). Order of the exe calls:
// stream.vtbl[0x6c](self); stream.vtbl[0x50](self+0xc); stream.vtbl[0x68](self+0x10); stream.vtbl[0x50](self+0x11);
// stream.vtbl[0x50](self+0x15); stream.vtbl[0x50](self+0x19); stream.vtbl[0x50](self+0x1d); 524780(self+0x21, stream);
// 524410(self+0x41, stream); 524410(self+0x55, stream); stream.vtbl[0x18](self+0x69, 0x6d); 524760(self+0x21, self+0x41,
// self+0x55). The exe's esi is self+0x55 by the last call, so the last helper gets that value as its second word.
// GUESS: a serialiser that writes header fields and then two sub-blocks to a stream.
static u8 THISCALL serialise_516470(u8 *self, u8 *stream) {
    void **vt = *(void ***)stream;
    ((Slot1Fn)vt[0x6c / 4])(stream, (u32)self);
    vt = *(void ***)stream;
    ((Slot1Fn)vt[0x50 / 4])(stream, (u32)(self + 0xc));
    vt = *(void ***)stream;
    ((Slot1Fn)vt[0x68 / 4])(stream, (u32)(self + 0x10));
    vt = *(void ***)stream;
    ((Slot1Fn)vt[0x50 / 4])(stream, (u32)(self + 0x11));
    vt = *(void ***)stream;
    ((Slot1Fn)vt[0x50 / 4])(stream, (u32)(self + 0x15));
    vt = *(void ***)stream;
    ((Slot1Fn)vt[0x50 / 4])(stream, (u32)(self + 0x19));
    vt = *(void ***)stream;
    ((Slot1Fn)vt[0x50 / 4])(stream, (u32)(self + 0x1d));
    ext_524780(self + 0x21, stream);
    ext_524410(self + 0x41, stream);
    ext_524410(self + 0x55, stream);
    vt = *(void ***)stream;
    ((Slot2Fn)vt[0x18 / 4])(stream, (u32)(self + 0x69), 0x6du);
    ext_524760(self + 0x21, (u32)(self + 0x41), (u32)(self + 0x55));
    return 1;
}
PCREG(516470, serialise_516470);
