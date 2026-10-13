// batch2510.cpp - decomp area 24, batch 2510. Two previously blocked rows, conventions now settled.
// 0x54ab40: SetEvent(*0x713d28) through the IAT slot 0x67613c (stdcall, one argument; same slot area 04 verified in 0x54ab30), cdecl, no args.
// 0x5a5c50: thiscall, no args, plain ret: this = [this+0x62c]; 0x5ef050(this, 0) (thiscall, one stack argument; 0x5ef050 ends in a
// tail jump to 0x5acac0 which pops that argument, so the chain pops 4; the caller does no cleanup).
#include "ff.h"

typedef u32(STDCALL *event_t)(u32 handle);
#define CRT_SET_EVENT (*(event_t *)0x67613c)

extern "C" u32 THISCALL ext_5ef050(void *self, u32 v);

static u32 __attribute__((cdecl)) setEvent713d28() { return CRT_SET_EVENT(*(u32 *)0x713d28); }
PCREG(54ab40, setEvent713d28);

static u32 THISCALL forward5a5c50(u8 *self) { return ext_5ef050(*(void **)(self + 0x62c), 0); }
PCREG(5a5c50, forward5a5c50);
