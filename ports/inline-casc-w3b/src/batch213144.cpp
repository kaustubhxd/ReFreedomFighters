#include "ff.h"

typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(*Atoi)(u32);

// 0x56f2d0: thiscall(): reads the engine value "key" 0x6a7584 (slot 0x5c); n = atoi(value) when found, else 0. Copies a 5-byte string from a table (n = 2..9 selects
// the row, anything else the default 0x6a7808) to this+0x1e9.
extern "C" void THISCALL fn_56f2d0(u8 *self) {
  u32 val;
  u32 n = 0;
  u8 *eng = G(u8 *, 0x70039c);
  if ((u8)(*(V2 *)(*(u8 **)eng + 0x5c))(eng, 0x6a7584, (u32)&val)) n = (*(Atoi *)0x6762d8)(val);
  static const u32 str[8] = {0x6a8540, 0x6a8548, 0x6a8550, 0x6a8558, 0x6a7810, 0x6a8560, 0x6a6e5c, 0x6a7818};
  u32 src = n - 2 > 7 ? 0x6a7808 : str[n - 2];
  __builtin_memcpy(self + 0x1e9, (const void *)src, 4);
  self[0x1ed] = *(const u8 *)(src + 4);
}
PCREG(56f2d0, fn_56f2d0);
