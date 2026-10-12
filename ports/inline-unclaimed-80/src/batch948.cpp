#include "ff.h"
// batch948.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x437670 (high). Thiscall, one stack argument (src), ret 4.
// s = *src (the exe calls the getter 0x4cc1d0, which is `mov eax,[ecx]; ret`, read directly here). len = strlen(s); p = alloc(len+1)
// (cdecl 0x41e290, one argument); copy s through its NUL into p; then vslot +4 of the object at this+0xd is called with p (thiscall,
// one argument, callee-cleaned: nothing is popped after it in the exe).

extern "C" u8 *ext_41e290(u32 n);

typedef u32(THISCALL *tc1)(u8 *, u32);

static void THISCALL zgroupCopyString(u8 *self, u8 *src) {
  u8 *s = *(u8 **)src;
  u32 len = 0;
  while (s[len]) len++;
  u8 *p = ext_41e290(len + 1);
  s = *(u8 **)src;
  for (u32 i = 0;; i++) {
    u8 ch = s[i];
    p[i] = ch;
    if (ch == 0) break;
  }
  u8 *obj = *(u8 **)(self + 0xd);
  ((tc1)(*(u32 *)(*(u32 *)obj + 4)))(obj, (u32)p);
}
PCREG(437670, zgroupCopyString);
