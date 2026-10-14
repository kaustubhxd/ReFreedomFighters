// batch38030.cpp - cascade s8 batch 38030: 0x601810 (look a named entry up in a node table and hand it to a callback).
#include "ff.h"

extern "C" u32 STDCALL ext_602d30(u32 key);          // stdcall (ret 4)
extern "C" u8 *THISCALL ext_602ff0(u32 p);          // thiscall, no stack args
typedef int (*stricmp_t)(const char *, const char *);
typedef u32 (*hook_t)();
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define imp_stricmp G(stricmp_t, 0x676414)

static void fail_hook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x601810, thiscall(name, keyref, sink) ret 0xc. this is a vector (+4 data, +0xc size) of entries; entry -> node, node[0] == 3 marks a named node (name at node[0xc]). The first node whose
// name equals `name` (_stricmp) calls sink slot 0 with (node[8][0], node[4]); otherwise the last node named like the default string 0x685220 is the fallback: when the helper chain
// 0x602d30(*keyref) / 0x602ff0 yields an object whose +0x10 is 5 the sink gets (*keyref, table handle of node[4] through the engine table slot 0x58), else (*keyref, 0). No named match and
// no fallback (or an empty vector) calls the assert hook. (The original's per-element bounds asserts can never fire and are left out.)
static void THISCALL fn601810(u8 *self, const char *name, u32 *keyref, u8 *sink) {
  u32 size = *(u32 *)(self + 0xc);
  if (size == 0) {
    fail_hook();
    return;
  }
  u32 fallback = 0xffffffff;
  u32 **data = *(u32 ***)(self + 4);
  for (u32 i = 0; i < *(u32 *)(self + 0xc); i++) {
    u32 *n = *(u32 **)data[i];
    if (n[0] != 3) continue;
    const char *nm = *(const char **)((u8 *)n + 0xc);
    if (imp_stricmp(nm, name) == 0) {
      u32 *p = *(u32 **)((u8 *)n + 8);
      SLOT(sink, 0, v2_t)(sink, p[0], n[1]);
      return;
    }
    if (imp_stricmp(nm, (const char *)0x685220) == 0) fallback = i;
  }
  if (fallback == 0xffffffff) {
    fail_hook();
    return;
  }
  u32 key = *keyref;
  u32 r = ext_602d30(key);
  u8 *r2 = ext_602ff0(r);
  if (r2 && *(u32 *)(r2 + 0x10) == 5) {
    u32 *n = *(u32 **)data[fallback];
    u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 h = SLOT(t, 0x58, v1_t)(t, n[1]);
    SLOT(sink, 0, v2_t)(sink, key, h);
  } else {
    SLOT(sink, 0, v2_t)(sink, key, 0);
  }
}
PCREG(601810, fn601810);
