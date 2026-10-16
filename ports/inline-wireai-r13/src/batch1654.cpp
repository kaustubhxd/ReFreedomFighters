// batch1654.cpp - jump thunk 0x480010 (residue 13 gap band, 2026-10-12): `jmp 0x4805a0` (ZLightOverlay::InitSprites,
// [high]; the target takes no stack arguments, ret with no immediate). The port calls the target with the same this
// and returns its eax unchanged. The target is hooked by address in the checker.
#include "ff.h"

extern "C" char ext_4805a0[];
typedef u32(THISCALL *Thunk0)(void *self);

u32 THISCALL ZLightOverlay_InitSprites_thunk(void *self) { return ((Thunk0)(void *)ext_4805a0)(self); }
PCREG(480010, ZLightOverlay_InitSprites_thunk);
