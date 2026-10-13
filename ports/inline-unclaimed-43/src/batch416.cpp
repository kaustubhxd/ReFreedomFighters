// batch416.cpp - residue 2 rows 0x4b58e0 and 0x4cb6e0.
// 0x4b58e0 (thiscall, no arguments): L = 0; call 0x6352f0(&L) (stdcall, one argument; GUESS, hooked); then vtable slot 0x84 of this
// with the argument &L (thiscall, one argument; ECX = this).
// 0x4cb6e0 (thiscall, one stack argument obj, ret 4): first = 0x4e5e40 with ECX = obj (word result); second = 0x4e5e40 with
// ECX = obj again; [this+0x50] = first (word), [this+0x52] = second (word), dword [this+0x54] = 0. (0x4e5e40 GUESS, hooked.)
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void STDCALL ext_6352f0(u32 *out);
extern "C" u16 THISCALL ext_4e5e40(void *obj);

static void THISCALL slot84WithLocal(u8 *self) {
  u32 local = 0;
  ext_6352f0(&local);
  vcall<void>((void *)self, 0x84, (u32)(unsigned long)&local);
}

static void THISCALL storeTwoWords(u8 *self, u32 obj) {
  u16 first = ext_4e5e40((void *)(unsigned long)obj);
  u16 second = ext_4e5e40((void *)(unsigned long)obj);
  *(u16 *)(self + 0x50) = first;
  *(u16 *)(self + 0x52) = second;
  U32(self, 0x54) = 0;
}

PCREG(4b58e0, slot84WithLocal);
PCREG(4cb6e0, storeTwoWords);
