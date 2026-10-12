// batch273.cpp - unclaimed area 67, gap band 0x5e1000-0x601000: tail-call forwarders through [this+0x15].
#include "ff.h"

typedef u32 (THISCALL *F0)(u8 *self);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// Each: obj = [this+0x15]; return obj->vslot[k](obj) (ECX = obj, no arguments; the callee's eax is the result).
static u32 THISCALL fwdSlot68(u8 *selfP) { u32 o = rdw((u32)(unsigned long)selfP, 0x15); return ((F0)rdw(rdw(o, 0), 0x68))((u8 *)(unsigned long)o); }
static u32 THISCALL fwdSlot60(u8 *selfP) { u32 o = rdw((u32)(unsigned long)selfP, 0x15); return ((F0)rdw(rdw(o, 0), 0x60))((u8 *)(unsigned long)o); }
static u32 THISCALL fwdSlot48(u8 *selfP) { u32 o = rdw((u32)(unsigned long)selfP, 0x15); return ((F0)rdw(rdw(o, 0), 0x48))((u8 *)(unsigned long)o); }
static u32 THISCALL fwdSlot18(u8 *selfP) { u32 o = rdw((u32)(unsigned long)selfP, 0x15); return ((F0)rdw(rdw(o, 0), 0x18))((u8 *)(unsigned long)o); }
static u32 THISCALL fwdSlot5c(u8 *selfP) { u32 o = rdw((u32)(unsigned long)selfP, 0x15); return ((F0)rdw(rdw(o, 0), 0x5c))((u8 *)(unsigned long)o); }
static u32 THISCALL fwdSlot10(u8 *selfP) { u32 o = rdw((u32)(unsigned long)selfP, 0x15); return ((F0)rdw(rdw(o, 0), 0x10))((u8 *)(unsigned long)o); }
PCREG(5f2e00, fwdSlot68);
PCREG(5f2e50, fwdSlot60);
PCREG(5f2f00, fwdSlot48);
PCREG(5f3000, fwdSlot18);
PCREG(5f31b0, fwdSlot5c);
PCREG(5f3360, fwdSlot10);
