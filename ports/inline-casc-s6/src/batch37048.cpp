// batch37048.cpp - cascade s6 batch 37048: 0x600280.
#include "ff.h"

extern "C" void THISCALL ext_600940(u8 *self, u32 a8, u32 key, u32 o0, u32 a18, u32 list, u32 o2c, u32 idx, u32 o30);   // ret 0x20
extern "C" u32 THISCALL ext_5ffb00(u8 *self, u32 v);                                                                       // ret 4
extern "C" void THISCALL ext_5fe880(u8 *self, u8 *dst, u32 v, u8 *list);                                                   // ret 0xc
extern "C" u32 THISCALL ext_5ffc10(u8 *self, u32 s);                                                                       // ret 4
typedef u32 (*hook_t)();
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void(*cdl_t)(void *, ...);
#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define W16(p, o) (*(u16 *)((u8 *)(p) + (o)))

static void assertHook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x600280, thiscall(a8, key, out, list, a18) ret 0x14, returns bool: looks the key up in the chain of tables starting at list (each table: lower bound +0xcc, count +0xd0, keys +0xe0,
// parent +0x9c); on a hit it calls 0x600940 and fills the out record {key, +4/+8 from table +0xec[idx], +0x1e resolved pointer (through the +0xa0/+0xa8/+0xac/+0xb0 index map, else
// the parent's 0x5ffb00; failures log error 0x137 and call the assert hook), +0x22 / +0x24 name length and text from +0xf4 / +0xfc, +0xc object via 0x5fe880 with its name via 0x5ffc10 at
// +0x28, +0x2c table, +0x30 index}.
static u32 THISCALL fn600280(u8 *self, u32 a8, u32 key, u8 *out, u8 *list, u32 a18) {
  u8 *t = list;
  u32 idx = 0;
  bool found = false;
  while (t) {
    if (key >= D32(t, 0xcc)) {
      u32 cnt = D32(t, 0xd0);
      if (cnt) {
        u32 *arr = (u32 *)D32(t, 0xe0);
        for (idx = 0; idx < cnt; idx++)
          if (arr[idx] == key) { found = true; break; }
        if (found) break;
      }
    }
    t = (u8 *)D32(t, 0x9c);
  }
  if (!found) return 0;
  ext_600940(self, a8, key, D32(out, 0), a18, (u32)t, D32(out, 0x2c), idx, W16(out, 0x30));
  D32(out, 0) = key;
  W16(out, 0x30) = (u16)idx;
  D32(out, 4) = ((u32 *)D32(t, 0xec))[idx * 2];
  D32(out, 8) = ((u32 *)D32(t, 0xec))[idx * 2 + 1];
  u32 v = W16(D32(t, 0xf0), idx * 2);
  u32 res;
  if (D32(t, 0xa8) != 0 && D32(t, 0xa0) <= v) {
    u32 cx = (u16)(v - (u16)D32(t, 0xa0));
    if (cx < D32(t, 0xa8)) {
      res = ((u32 *)D32(t, 0xac))[cx] + D32(t, 0xb0);
    } else {
      u8 *lg = *(u8 **)0x700390;
      void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6b9420, 0x137);
      (*(cdl_t **)L)[0x2c / 4](L, 0x69c6b0, 0x6b9474);
      assertHook();
      res = (u32)out;
    }
  } else {
    u8 *p = (u8 *)D32(t, 0x9c);
    if (p) {
      res = ext_5ffb00(p, v);
    } else {
      assertHook();
      res = (u32)out;
    }
  }
  D32(out, 0x1e) = res;
  u32 off = W16(D32(t, 0xf4), idx * 2);
  u8 *names = (u8 *)D32(t, 0xfc);
  u16 nl = W16(names, off);
  W16(out, 0x22) = nl;
  D32(out, 0x24) = nl ? (u32)(names + 2 + off) : 0;
  ext_5fe880(t, out + 0xc, ((u32 *)D32(t, 0xe4))[idx], t);
  D32(out, 0x28) = ext_5ffc10(out + 0xc, 0x6b9490);
  D32(out, 0x2c) = (u32)t;
  return 1;
}
PCREG(600280, fn600280);
