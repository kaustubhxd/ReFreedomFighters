// batch900.cpp - gap band slice: 0x41ede0 ZSysMem::IsMallocSimple(char*) and 0x420170 ZSysInterfaceGC::GetCharacter(int).
// IsMallocSimple: thiscall, one stack arg (a name), ret 4. For each non-null entry of the table at this+0x35 (count at this+0x45),
//   the helper 0x4d12e0 (thiscall: ECX = the entry, one argument, ret 4) is asked; the first entry that accepts gives index+1 (lea),
//   none gives 0.
// GetCharacter: thiscall, one stack arg (an index), ret 4, returns bool. The byte at this+5*idx+0xa0b keeps its top bit as the
//   test; bit 1 is cleared (stored as byte & 0x7f). If the engine float at +0x9c7 is equal (ordered) to the constant at 0x6785d0,
//   the result is false; else if the original byte is >= 0x80, the object's slot +0x1f8 (one argument, the index) decides.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(float *)((u8 *)(p) + (o)))

extern "C" bool THISCALL ext_4d12e0(void *obj, const char *name);   // helper (stood in); ret 4

// 0x41ede0 (name map: ZSysMem::IsMallocSimple(char*)).
static u32 THISCALL IsMallocSimple41ede0(u8 *self, const char *name) {
  u32 i = 0;
  if (U32(self, 0x45) == 0) return 0;
  u32 *tab = (u32 *)(self + 0x35);
  do {
    u32 obj = tab[i];
    if (obj != 0 && ext_4d12e0((void *)obj, name)) return i + 1;
    i++;
  } while (i != U32(self, 0x45));
  return 0;
}
PCREG(41ede0, IsMallocSimple41ede0);

// 0x420170 (name map: ZSysInterfaceGC::GetCharacter(int)).
static bool THISCALL GetCharacter420170(u8 *self, u32 idx) {
  u8 *addr = self + 5 * idx + 0xa0b;
  u8 bl = *addr;
  if (bl & 2) *addr = bl & 0x7f;
  float gf = F32(G(u8 *, 0x70039c), 0x9c7);
  float c = G(float, 0x6785d0);
  if (gf == c) return false;
  if (bl < 0x80) return false;
  return vcall<bool>(self, 0x1f8, idx);
}
PCREG(420170, GetCharacter420170);
