// batch611.cpp - band 0x421000-0x441000, batch 611: three ZSysInterface string accessors (each copies a member string into
// a hidden return object; the copy is the exe's MYSTR assign at 0x4cbe50, not ported here: its callee is the existing
// ext_4cc630 port in docs/18-level1-haiku-trial.md (w15)).
//   0x42ee20 ZSysInterface::ProjectPath() const: copy the string at this+0x123 into the hidden dest; returns dest
//   0x42fc30 ZSysInterface::StreamFile() const: copy the string at this+0x8a3
//   0x42fc60 ZSysInterface::StreamIdxFile() const: copy the string at this+0x7a3
// All three are thiscall with the hidden return pointer as the one stack argument, ret 4.
#include "ff.h"

extern "C" u8 *THISCALL ext_4cbe50(void *dst, void *srcField);  // MYSTR assign (thiscall, ret 4): srcField holds a char *

static u8 *THISCALL projectPath(u8 *self, u8 *dest) {
  ext_4cbe50(dest, self + 0x123);
  return dest;
}
PCREG(42ee20, projectPath);

static u8 *THISCALL streamFile(u8 *self, u8 *dest) {
  ext_4cbe50(dest, self + 0x8a3);
  return dest;
}
PCREG(42fc30, streamFile);

static u8 *THISCALL streamIdxFile(u8 *self, u8 *dest) {
  ext_4cbe50(dest, self + 0x7a3);
  return dest;
}
PCREG(42fc60, streamIdxFile);
