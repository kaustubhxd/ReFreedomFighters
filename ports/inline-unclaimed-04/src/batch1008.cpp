// batch1008.cpp - unclaimed-04 batch 8 (docs/20-unclaimed-04.md): ZInputAction::AddNodes (0x4379f0, high name).
// thiscall, two stack arguments (ret 8). The copy is from 0x41e290 (cdecl operator new, length + 1) and is freed through
// 0x634273 (cdecl, pointer and size 1); both are original code here, and the spec hooks them with logging stubs (GUESS).
#include "ff.h"

typedef void(THISCALL *slot0_t)(void *self, char *token, u32 flag);

extern "C" void *ext_41e290(u32 size);          // cdecl operator new, original code
extern "C" void ext_634273(void *p, u32 size);  // cdecl delete, original code

// 0x4379f0. s = '+'-separated tokens; a leading run of spaces is skipped; a first character of '0' or an empty string
// adds nothing. Each token (up to the next '+' or the end) goes to vtable slot 0 with the flag.
static void THISCALL inputActionAddNodes(u8 *self, char *s, u32 flag) {
  if (!s) return;

  u32 len = 0;
  while (s[len]) len++;
  char *buf = (char *)ext_41e290(len + 1);
  for (u32 k = 0; k <= len; k++) buf[k] = s[k];  // includes the terminator

  u32 p = 0;
  while (buf[p] == ' ') p++;
  char first = buf[p];
  if (first != '0' && first != 0) {
    u32 idx = p;
    for (;;) {
      // the token runs to the first '+' or the terminator; an empty start gives an empty token
      u32 e = idx;
      while (buf[e] != '+' && buf[e] != 0) e++;
      char saved = buf[e];
      buf[e] = 0;
      slot0_t fn = *(slot0_t *)(*(u32 *)self + 0);
      fn(self, buf + idx, flag);
      buf[e] = saved;

      idx = e + (saved == '+' ? 1 : 0);
      while (buf[idx] == ' ') idx++;
      if (buf[idx] == 0) break;
    }
  }
  ext_634273(buf, 1);
}
PCREG(4379f0, inputActionAddNodes);
