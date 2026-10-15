// batch67550.cpp - cascade s6 batch 67550: 0x401220.
#include "ff.h"

extern "C" void ext_410bc0(u32 *b, u8 *buf, int bytes);          // oggpack_readinit, cdecl
extern "C" int ext_410de0(u32 *b, int bits);                     // oggpack_read, cdecl
extern "C" void ext_401320(u32 *b, u8 *buf, int n);              // read n bytes, cdecl
extern "C" int ext_401350(u8 *vi, u32 *b);                       // unpack info, cdecl
extern "C" int ext_401430(u8 *vc, u32 *b);                       // unpack comment, cdecl
extern "C" int ext_401510(u8 *vi, u32 *b);                       // unpack books, cdecl

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x401220, cdecl(vi, vc, op) returns eax: vorbis_synthesis_headerin. Reads the 8-bit packet type and the six "vorbis" bytes from the packet (op[0] data, op[4] bytes) through the bit reader;
// a mismatch returns -132 (0xffffff7c). Type 1 (needs op[8], vi[8] == 0) unpacks the info header, type 3 (vi[8] != 0) the comments into vc, type 5 (vi[8] and vc[0xc] non-zero) the codebooks;
// anything else, or a failed precondition, or a missing packet, returns -133 (0xffffff7b).
static int fn401220(u8 *vi, u8 *vc, u8 *op) {
  u32 opb[5];
  u8 buffer[6];
  if (op) {
    ext_410bc0(opb, *(u8 **)op, (int)D32(op, 4));
    int type = ext_410de0(opb, 8);
    for (int i = 0; i < 6; i++) buffer[i] = 0;
    ext_401320(opb, buffer, 6);
    const u8 *v = (const u8 *)0x6efd38;
    bool eq = true;
    for (int i = 0; i < 6; i++) if (buffer[i] != v[i]) { eq = false; break; }
    if (!eq) return -132;
    if (type == 1) {
      if (D32(op, 8) && D32(vi, 8) == 0) return ext_401350(vi, opb);
    } else if (type == 3) {
      if (D32(vi, 8)) return ext_401430(vc, opb);
    } else if (type == 5) {
      if (D32(vi, 8) && D32(vc, 0xc)) return ext_401510(vi, opb);
    }
  }
  return -133;
}
PCREG(401220, fn401220);
