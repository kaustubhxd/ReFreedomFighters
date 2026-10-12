// batch261.cpp - unclaimed area 67, slice floor(addr/16) mod 20 == 6 (FUN_ names; bodies from the PC bytes).
#include "ff.h"

typedef u32 (THISCALL *F0)(u8 *self);

// 0x59aa20, no this use: returns the dword at 0x6ed024.
static u32 THISCALL readGlobal6ed024(u8 *self) { (void)self; return *(u32 *)0x6ed024; }
PCREG(59aa20, readGlobal6ed024);

// 0x432520, thiscall: returns this+0xac.
static u32 THISCALL addrAC(u8 *self) { return (u32)(unsigned long)(self + 0xac); }
PCREG(432520, addrAC);

// 0x49a4e0, thiscall: returns the dword at [[this+0xc]+8].
static u32 THISCALL readNested(u8 *self) { return *(u32 *)(unsigned long)(*(u32 *)(self + 0xc) + 8); }
PCREG(49a4e0, readNested);

// 0x4d4d20, thiscall: stores 0x696634 at the first dword of this.
static void THISCALL setVtableWord(u8 *self) { *(u32 *)self = 0x696634u; }
PCREG(4d4d20, setVtableWord);

// 0x606220, thiscall: zeroes the 16 bytes at this.
static void THISCALL zero16(u8 *self) { for (int i = 0; i < 16; i++) self[i] = 0; }
PCREG(606220, zero16);

// 0x513160, thiscall: tail call to slot 0xc of the object at this+0x5c, with that object as this.
static u32 THISCALL tailSlot0c(u8 *self) {
  u32 obj = *(u32 *)(self + 0x5c);
  u32 fn = *(u32 *)(unsigned long)(*(u32 *)(unsigned long)obj + 0xc);
  return ((F0)fn)((u8 *)(unsigned long)obj);
}
PCREG(513160, tailSlot0c);
