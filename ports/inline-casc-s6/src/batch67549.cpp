// batch67549.cpp - cascade s6 batch 67549: 0x48dcb0.
#include "ff.h"

extern "C" u32 THISCALL ext_4db9a0(u8 *self, u32 key);   // ret 4, bool in al

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define SYS (*(u8 **)0x70039c)
#define TABLE (*(u8 **)(SYS + 0x9b))

// 0x48dcb0, thiscall() plain ret (eax unused): applies the pending list this[0xaec] to the renderer. With the list present it sets the colour 0x8080ff through the device at [0x70038c] (slot 0x48, which
// returns the old one), calls slot 0x300(1) on the current object of the object table (table[0xadc]) when the list head is non-empty, then walks the table object's children (table[0xadc][8], next via slot
// 0x50 with an iterator pointer) letting every typed child that 0x4db9a0(0x100020) and slot 0x308 accept advance the cursor (its slot 0x32c(cursor)). The cursor is then moved to the list end (slot 0x50 of
// sys[0x1aa3][0x1c] until the entry is -1) and the remaining span is passed to that object's slot 0x40; finally the old colour is restored.
static void THISCALL fn48dcb0(u8 *self) {
  if (!D32(self, 0xaec)) return;
  u8 *dev = *(u8 **)0x70038c;
  u32 old = vcall<u32>(dev, 0x48, 0x8080ffu);
  u32 *esi = *(u32 **)(self + 0xaec);
  if (esi[0] != 0) vcall<void>(*(u8 **)(TABLE + 0xadc), 0x300, 1u);
  esi = (u32 *)((u8 *)esi + 0x10);
  u8 *cur = *(u8 **)(*(u8 **)(TABLE + 0xadc) + 8);
  if (cur) {
    do {
      u8 *sub = *(u8 **)(cur + 0x54);
      u32 t = sub ? D32(*(u8 **)(sub + 0xc), 0x23) : 0x200002u;
      if (t & 0x100000) {
        if ((u8)ext_4db9a0(cur, 0x100020u)) {
          if ((u8)vcall<u32>(sub, 0x308)) esi = (u32 *)vcall<u8 *>(sub, 0x32c, (u32)esi);
        }
      }
      vcall<void>(*(u8 **)(TABLE + 0xadc), 0x50, (u32)&cur);
    } while (cur != 0);
  }
  if (esi[0] != 0xffffffffu) {
    do {
      esi = (u32 *)vcall<u8 *>(*(u8 **)(*(u8 **)(SYS + 0x1aa3) + 0x1c), 0x50, (u32)esi);
    } while (esi[0] != 0xffffffffu);
  }
  esi = (u32 *)((u8 *)esi + 4);
  u8 *l = *(u8 **)(*(u8 **)(SYS + 0x1aa3) + 0x1c);
  u32 span = D32(self, 0xae8) - (u32)esi + D32(self, 0xaec);
  vcall<void>(l, 0x40, (u32)esi, span);
  vcall<void>(*(u8 **)0x70038c, 0x48, old);
}
PCREG(48dcb0, fn48dcb0);
