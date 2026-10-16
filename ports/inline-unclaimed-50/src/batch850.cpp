// batch850.cpp - area 50 (residue-10 list): ZActionControlMap::GenerateGameActionsPC() [0x5b37e0, 258 instr, thiscall, no args].
// The object's mode word (+0x4d == 3) copies two flags into +0x1a8/+0x1a9. Then the first of ten queries (render-free
// manager +0x1907, vt +0x2c with (id, 0)) that answers true sets the byte at +0x189 to 0x7f, 0x17f, ... 0x97f (a word store);
// none gives 0. When +0x189 is set, a ten-slot table (copied from a 0x74-byte record filled by 0x596710) is scanned from the
// cursor at +0x18a: forwards when +0x17f is set (bh), backwards when only +0x180 is set (bl). The scan skips a zero slot,
// slot 4 when the record's word at +0x04 is zero, and slot 5 when the record's dword at +0x0c is nonzero. The first slot
// that stops the scan is compared with the value 0x591b20 returns for +0x5f; if they differ, 0x4f9680 is called with 1.
// Then vt +0x3dc (no args) and vt +0x4dc (slot value, 1) on the +0x5f object. The pushes of edi, ebx and esi are the
// callee-saved saves (the vt +0x90 call takes no argument).
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_596710(void *self, u8 *rec);     // record fill (not ported here; stood in by the harness)
extern "C" s32 THISCALL ext_591b20(void *self);                // item-type query (not ported here)
extern "C" void THISCALL ext_4f9680(void *self, u32 arg);      // sound play (not ported here)

// 0x5b37e0 ZActionControlMap::GenerateGameActionsPC().
static void THISCALL GenerateGameActionsPC(u8 *self) {
  if (U32(self, 0x4d) == 3) {
    U8(self, 0x1a8) = U8(self, 0x17f);
    U8(self, 0x1a9) = U8(self, 0x180);
  } else {
    U16(self, 0x1a8) = 0;
  }
  U8(self, 0x1b1) = U8(self, 0x175);
  u8 *obj = (u8 *)FP(self, 0x5f);
  if (U32(obj, 0x836) != 0 || U32(obj, 0x832) != 0 || U8(self, 0x1a3) != 0)
    return;

  // the first query that answers true picks the code word
  static const u32 codes[10] = {0x7f, 0x17f, 0x27f, 0x37f, 0x47f, 0x57f, 0x67f, 0x77f, 0x87f, 0x97f};
  const u32 ids[10] = {U32(self, 0xf3), U32(self, 0xf7), U32(self, 0xfb), U32(self, 0xff), U32(self, 0x103),
                       U32(self, 0x107), U32(self, 0x10b), U32(self, 0x10f), U32(self, 0x113), U32(self, 0x117)};
  bool found = false;
  for (int k = 0; k < 10 && !found; k++) {
    if (vcall<u8>(FP(G(u8 *, 0x70039c), 0x1907), 0x2c, ids[k], 0u)) {
      U16(self, 0x189) = (u16)codes[k];
      found = true;
    }
  }
  if (!found)
    U8(self, 0x189) = 0;

  bool bh = false, bl = false;
  if (U32(self, 0x4d) != 3) {
    if (U8(self, 0x17f) != 0) {
      bh = true;
      U8(self, 0x189) = 0x7f;
    } else if (U8(self, 0x180) != 0) {
      bl = true;
      U8(self, 0x189) = 0x7f;
    }
  }
  if (U8(self, 0x189) == 0)
    return;

  u8 *rb = (u8 *)FP(self, 0x5b);
  vcall<void>(rb, 0x90);
  u8 rec[0x74];
  ext_596710(FP(rb, 0x1d0f), rec);

  // the ten-slot table: slot 0 and slot 9 are zero, the others come from the record
  u32 slot[10];
  slot[0] = 0;
  slot[1] = *(u32 *)(rec + 0x35);
  slot[2] = *(u32 *)(rec + 0x39);
  slot[3] = *(u32 *)(rec + 0x3d);
  slot[4] = *(u32 *)(rec + 0x29);
  slot[5] = *(u32 *)(rec + 0x31);
  slot[6] = *(u32 *)(rec + 0x25);
  slot[7] = *(u32 *)(rec + 0x2d);
  slot[8] = *(u32 *)(rec + 0x41);
  slot[9] = 0;
  u32 flag4 = *(u32 *)(rec + 0x04);   // ebx: tested when the scan reaches slot 4
  u32 flag5 = *(u32 *)(rec + 0x0c);   // edi: tested when the scan reaches slot 5

  if (bh) {
    for (u32 n = 0; n < 10; n++) {
      u8 cur = U8(self, 0x18a) + 1;
      if (cur == 10)
        cur = 0;
      U8(self, 0x18a) = cur;
      if (slot[cur] != 0) {
        if (cur == 4 && flag4 == 0) {
          // skipped
        } else if (cur == 5 && flag5 == 0) {
          // skipped
        } else {
          break;
        }
      }
    }
  } else if (bl) {
    for (u32 n = 0; n < 10; n++) {
      u8 cur = U8(self, 0x18a) - 1;
      if (cur == 0xff)
        cur = 9;
      U8(self, 0x18a) = cur;
      if (slot[cur] != 0) {
        if (cur == 4 && flag4 == 0) {
          // skipped
        } else if (cur == 5 && flag5 == 0) {
          // skipped
        } else {
          break;
        }
      }
    }
  }

  u8 cur = U8(self, 0x18a);
  if (slot[cur] == 0)
    return;
  if (ext_591b20(obj) != (s32)cur)
    ext_4f9680((void *)0x700e24, 1);
  vcall<void>(obj, 0x3dc);
  vcall<void>(obj, 0x4dc, slot[cur], 1u);
}
PCREG(5b37e0, GenerateGameActionsPC);
