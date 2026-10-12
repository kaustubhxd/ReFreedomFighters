// batch1013.cpp - unclaimed-07 batch 13 (docs/20-unclaimed-07.md, slice 6): ZInputAction::DependOnActionsNodes.
// Name from the GC name map (high). Body from the PC bytes.
#include "ff.h"

// 0x41e290: operator new (cdecl, one argument; original code, hooked in the spec).
extern "C" u8 *__attribute__((cdecl)) ext_41e290(u32 n);
// 0x634273: operator delete (cdecl, two arguments: pointer and size; hooked in the spec).
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);
// 0x4385e0: per-token helper (thiscall, the token and the flag; original code, hooked in the spec).
extern "C" void THISCALL ext_4385e0(u8 *self, u8 *tok, u32 flag);

// 0x4386a0, ZInputAction::DependOnActionsNodes(char*, bool) (high), thiscall, ret 8. Returns when the string is null.
// Copies the string into a new buffer, skips leading spaces, and for each token (up to a '+' or the end, spaces trimmed)
// calls ext_4385e0(this, token, flag). A first token that starts with '0' (or is empty) gives no calls. Frees the buffer.
static void THISCALL inputActionDependOnActionsNodes(u8 *self, u8 *s, u32 flag) {
  if (!s)
    return;
  u32 len = 0;
  while (s[len])
    len++;
  u8 *buf = ext_41e290(len + 1);
  for (u32 k = 0; k <= len; k++)
    buf[k] = s[k];
  u32 i = 0;
  while (buf[i] == ' ')
    i++;
  if (buf[i] != '0' && buf[i] != 0) {
    for (;;) {
      u32 esi = i;
      if (buf[i] != 0) {
        while (buf[esi] != 0 && buf[esi] != '+')
          esi++;
      }
      u8 bl = buf[esi];
      u8 *tok = buf + i;
      buf[esi] = 0;
      ext_4385e0(self, tok, flag);
      buf[esi] = bl;
      i = (bl == '+') ? esi + 1 : esi;
      while (buf[i] == ' ')
        i++;
      if (buf[i] == 0)
        break;
    }
  }
  ext_634273(buf, 1);
}
PCREG(4386a0, inputActionDependOnActionsNodes);
