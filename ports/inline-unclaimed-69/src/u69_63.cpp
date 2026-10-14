// u69_63.cpp - area 69, group 63 (slice 8). Writes a value into an array of 40-byte entries (CSprite3D::SetColor). No callees.
#include "ff.h"

// 0x5ec340, CSprite3D::SetColor(unsigned int, unsigned int) (GC map high). thiscall two stack args (color, idx; ret 8), void.
// The array is the list at self+0x3a: its base pointer is the dword at list+4. idx == -1 writes color at offset 0x24 of every entry (count = the dword at self+0x3e);
// otherwise only entry idx (at 40 * idx + 0x24) is written.
static void THISCALL setColor5ec340(u8 *self, u32 color, u32 idx) {
  if (idx == 0xffffffffu) {
    u32 n = *(u32 *)(self + 0x3e);
    for (u32 k = 0; k < n; ++k) {
      u8 *base = *(u8 **)(*(u8 **)(self + 0x3a) + 4);
      *(u32 *)(base + 0x28 * k + 0x24) = color;
    }
    return;
  }
  u8 *base = *(u8 **)(*(u8 **)(self + 0x3a) + 4);
  *(u32 *)(base + idx * 40 + 0x24) = color;
}
PCREG(5ec340, setColor5ec340);
