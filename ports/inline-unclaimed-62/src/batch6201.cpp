// batch6201.cpp - unclaimed-62 claim 1 (core-todo residue 02): ZInputActions::PrintActionDebugInfo(char *name) [map 0x439f60; thiscall,
// ret 4]. The object's slot 0x58 maps the name to an action (exe-side lookup). When that action exists and its first dword is zero, the
// debug reporter prints line 0x6b4 and then a line with the action's dword at +4 and two strings chosen by its bytes: the first string
// is 0x67a8d4 when byte +0x2e is below 0x80 (else 0x67a8cc); the second is 0x67a8cc when bit 0x10 of byte +0x2f is set (else 0x67a8d4).
#include "ff.h"

typedef void (*reportVarFn)(void *, const char *, ...);

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static void THISCALL printActionDebugInfo(u8 *self, const char *name) {
  u8 *a = vcall<u8 *>(self, 0x58, name);
  if (a && rd32u(a) == 0) {
    void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x67a850, 0x6b4);
    const char *s1 = (a[0x2e] < 0x80) ? (const char *)0x67a8d4 : (const char *)0x67a8cc;
    const char *s2 = (a[0x2f] & 0x10) ? (const char *)0x67a8cc : (const char *)0x67a8d4;
    (*(reportVarFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x67a8dc, rd32u(a + 4), s2, s1);
  }
}
PCREG(439f60, printActionDebugInfo);
