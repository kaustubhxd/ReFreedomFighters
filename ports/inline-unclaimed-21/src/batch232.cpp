// batch232.cpp - gap band 0x641000-0x661000 (docs/20-unclaimed-72.md method; no claim found for 0x646f30 in docs/20 or
// doc-only). 0x646f30, stdcall(A, B, idx, C, out) (ret 0x14): row = A + idx*48; out[0..2] = row[0x24..0x2c];
// 0x4dfd10(local, row) (fastcall struct copy, exe code); 0x4de480(local, B + idx*36) (fastcall, stubbed);
// 0x4dfd10(C, local). Name GUESS. The local is a 0x28-byte stack block.
#include "ff.h"

extern "C" void FASTCALL ext_4dfd10(u8 *dst, u8 *src);   // original struct copy (exe code, not stubbed)
extern "C" void FASTCALL ext_4de480(u8 *dst, u8 *src);   // original (stubbed in the harness: stores its edx)

static void STDCALL rowCopy_646f30(u8 *A, u8 *B, u32 idx, u8 *C, u32 *out) {
  u8 local[0x28];
  u8 *row = A + idx * 48;
  out[0] = *(u32 *)(row + 0x24);
  out[1] = *(u32 *)(row + 0x28);
  out[2] = *(u32 *)(row + 0x2c);
  ext_4dfd10(local, row);
  ext_4de480(local, B + idx * 36);
  ext_4dfd10(C, local);
}
PCREG(646f30, rowCopy_646f30);
