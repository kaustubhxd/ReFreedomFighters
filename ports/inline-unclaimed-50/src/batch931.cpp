// batch931.cpp - 0x4386a0 [thiscall (ECX = this), two stack args (s, a2), ret 8, void]. Body read in full (2026-10-12). A tokenizer: copies s
// into a block from 0x41e290 (cdecl, size strlen+1), skips spaces, and for each '+'-separated token (ended by '+' or NUL, trailing spaces
// skipped) calls 0x4385e0 (thiscall: this, token, a2; ret 8; stood in). A string that starts with NUL or '0' (after the spaces) gives no
// token. At the end 0x634273 (cdecl: block, 1; stood in) is called. Null s returns at once.
#include "ff.h"

extern "C" void *ext_41e290(u32 size);                              // stood in (cdecl)
extern "C" void THISCALL ext_4385e0(void *self, u8 *token, u32 a2); // stood in (thiscall; ret 8)
extern "C" void ext_634273(void *obj, u32 n);                       // stood in (cdecl)

// 0x4386a0 (no name in the map).
static void THISCALL Tokenize4386a0(u8 *self, const u8 *s, u32 a2) {
  if (!s) return;
  u32 len = 0;
  while (s[len]) len++;
  u8 *blk = (u8 *)ext_41e290(len + 1);
  for (u32 k = 0; k <= len; k++) blk[k] = s[k];
  u32 i = 0;
  while (blk[i] == ' ') i++;
  u8 c = blk[i];
  if (c != '0' && c != 0) {
    for (;;) {
      u32 j = i;
      if (blk[i] != 0) {
        while (blk[j] != '+') {
          j++;
          if (blk[j] == 0) break;
        }
      }
      u8 bl = blk[j];
      blk[j] = 0;
      ext_4385e0(self, blk + i, a2);
      blk[j] = bl;
      i = (bl == '+') ? j + 1 : j;
      while (blk[i] == ' ') i++;
      if (blk[i] == 0) break;
    }
  }
  ext_634273(blk, 1u);
}
PCREG(4386a0, Tokenize4386a0);
