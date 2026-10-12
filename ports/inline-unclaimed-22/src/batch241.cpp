// batch241.cpp - area 59, docs/20-unclaimed-59.md (coordinator loop). Tokenizer: copies obj->[+0x10] (a string) into a
// stack buffer, then for each token (split on '+', stopping at the terminator or at a '0' token start) copies the token into
// a block from 0x41e290 (cdecl) and calls vtable slot 4 of this->[+0xd] with the block (thiscall, one argument). The
// oversize path (string over 0x80 bytes, an assertion in the original) is not ported. Name GUESS.
#include "ff.h"

extern "C" u8 *__attribute__((cdecl)) ext_41e290(u32 size);

typedef void(THISCALL *SlotPtr)(u8 *, u32);

static u32 strLen_4376c0(const u8 *s) {
  u32 n = 0;
  while (s[n]) n++;
  return n;
}

// 0x4376c0, thiscall(obj) ret 4.
static void THISCALL tokenize_4376c0(u8 *self, u8 *obj) {
  u8 buf[0x84];
  u8 *src = *(u8 **)(obj + 0x10);
  u32 n = strLen_4376c0(src);
  for (u32 i = 0; i <= n; i++) buf[i] = src[i];
  u8 *esi = buf;
  for (;;) {
    u8 *edi = esi;
    u8 al = *esi;
    if (al == 0 || al == 0x30) break;
    for (;;) {
      if (al == 0x2b) {
        *esi = 0;
        esi++;
        break;
      }
      al = esi[1];
      esi++;
      if (al == 0) break;
    }
    u32 len = strLen_4376c0(edi);
    u8 *blk = ext_41e290(len + 1);
    for (u32 i = 0; i <= len; i++) blk[i] = edi[i];
    u8 *sub = *(u8 **)(self + 0xd);
    SlotPtr fn = (SlotPtr)(*(u32 *)(*(u32 *)sub + 4));
    fn(sub, (u32)blk);
  }
}
PCREG(4376c0, tokenize_4376c0);
