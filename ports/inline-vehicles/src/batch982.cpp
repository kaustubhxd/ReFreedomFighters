// batch982.cpp - residue-10 (core todo), batch 982: ZFFSimpleTrain2::CopyEventDataBlock(DBREAD&), 0x5b86a0, thiscall, ret 4.
// (SEH frame not reproduced.) Reads (DBREAD readers 0x4e5e60 dword, 0x4e5e80 float, 0x4e5ea0 string pointer; all stood in): [this+0x48]
// = dword; allocation 0x41e290(0x1c, stood in) and, when it succeeds, the constructor 0x4ccbe0(obj, 1, 0) (stood in); [this+0x4c] = that;
// 0x4e6330(obj) (stood in); [this+0x50], [this+0x54] dwords; f1 float; [this+0x5c] = f2 float; [this+0xde] dword; b1 dword; the string
// at 0x4e5ea0 copied to [this+0x60]; [this+0xe2] = render vslot 0x58(b1) when b1 != 0; [this+0xe6] = render vslot 0x58([this+0xde])
// when that is non-zero; [this+0x7e] = render vslot 0x58([this+0x48]) (returned); [this+0x58] = f1 * 0x68af2c / 0x6a87fc.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(void *d);                            // DBREAD dword (stood in)
extern "C" float THISCALL ext_4e5e80(void *d);                          // DBREAD float (stood in)
extern "C" const char *THISCALL ext_4e5ea0(void *d);                    // DBREAD string (stood in)
extern "C" void THISCALL ext_4e6330(void *d, u32 obj);                  // stood in
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 size);           // allocator (stood in)
extern "C" u32 THISCALL ext_4ccbe0(void *self, u32 a, u32 b);           // constructor (stood in)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x5b86a0 ZFFSimpleTrain2::CopyEventDataBlock(DBREAD&).
static u32 THISCALL simpleTrain2Copy(u8 *t, u8 *d) {
  D(t, 0x48) = ext_4e5e60(d);
  void *buf = ext_41e290(0x1c);
  u32 obj = 0;
  if (buf)
    obj = ext_4ccbe0(buf, 1u, 0u);
  D(t, 0x4c) = obj;
  ext_4e6330(d, obj);
  D(t, 0x50) = ext_4e5e60(d);
  D(t, 0x54) = ext_4e5e60(d);
  float f1 = ext_4e5e80(d);
  F(t, 0x5c) = ext_4e5e80(d);
  D(t, 0xde) = ext_4e5e60(d);
  u32 b1 = ext_4e5e60(d);
  const char *s = ext_4e5ea0(d);
  for (u32 k = 0;; k++) {
    char ch = s[k];
    t[0x60 + k] = (u8)ch;
    if (ch == 0)
      break;
  }
  u8 *rm = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  if (b1)
    D(t, 0xe2) = vcall<u32>(rm, 0x58, b1);
  u32 b2 = D(t, 0xde);
  if (b2)
    D(t, 0xe6) = vcall<u32>(rm, 0x58, b2);
  u32 r = vcall<u32>(rm, 0x58, D(t, 0x48));
  D(t, 0x7e) = r;
  F(t, 0x58) = (f1 * *(float *)0x68af2c) / *(float *)0x6a87fc;
  return r;
}
PCREG(5b86a0, simpleTrain2Copy);
