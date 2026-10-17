// batch388.cpp - area 76, residue 17 (out/functions.jsonl).
// 0x663250 (thiscall, one stack argument, ret 4; GUESS): builds a path on the stack (0x80-byte buffer, /GS cookie):
//   strcpy(buf, this+0x121b4); then the word at 0x67856c is stored at the string end (a one-character separator plus NUL);
//   then strcat(buf, arg). Calls [0x700394].vtbl[0x5c](buf) (thiscall, one word) and returns its eax.
#include "ff.h"

static u32 THISCALL f663250(u8 *selfp, const char *arg) {
    char buf[0x84];
    const char *s = (const char *)((u32)selfp + 0x121b4u);
    u32 n = 0u;
    do { buf[n] = s[n]; } while (s[n++] != 0);
    n = 0u;
    while (buf[n] != 0) n++;
    *(u16 *)(buf + n) = *(u16 *)0x67856cu;
    n = 0u;
    while (buf[n] != 0) n++;
    u32 k = 0u;
    do { buf[n + k] = arg[k]; } while (arg[k++] != 0);
    u32 g = *(u32 *)0x700394u;
    return ((u32(THISCALL *)(u32, char *))(*(u32 *)(*(u32 *)g + 0x5cu)))(g, buf);
}
PCREG(663250, f663250);
