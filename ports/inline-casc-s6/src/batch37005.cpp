// batch37005.cpp - cascade s6 batch 37005: 0x50dfa0.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 zero);          // ret 4
extern "C" void THISCALL ext_50d7b0(u8 *self, u32 *p);           // ret 4
typedef int(*stricmp_t)(const char *, const char *);
#define imp_stricmp G(stricmp_t, 0x676414)
typedef u32(*hook_t)();
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void(*cd3_t)(void *, u32, u32);

static void logfail(u32 line, u32 msg) {
  u8 *lg = *(u8 **)0x700390;
  void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x69c8e0, line);
  (*(cd3_t **)L)[0x2c / 4](L, 0x69c6b0, msg);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x50dfa0, stdcall(a) ret 4: looks up a name from the node at a[1] (type 3: the dword itself, type 4: slot 0x34 of the object; other
// types log an error and use 0), scans the list at [lookup(0x685f44,0)+0x18] for an entry whose table object name equals it (_stricmp);
// found: calls 0x50d7b0 on the node at a[2] with the entry id; not found: node a[2] must be type 0 or 1, else logs; it is then reset (type 1, value 0).
static void STDCALL fn50dfa0(u8 *a) {
  u8 *x = ext_5003d0(*(u32 *)(a + 4), 0);
  u32 name;
  u8 ty = x[4];
  if (ty == 3) {
    name = *(u32 *)x;
  } else if (ty == 4) {
    void *o = *(void **)x;
    name = (*(v0_t **)o)[0x34 / 4](o);
  } else {
    logfail(0x111, 0x69c9b0);
    name = 0;
  }
  u8 *tab = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  void *M = *(void **)(tab + 0xadc);
  u8 *ent = (u8 *)(*(v2_t **)M)[0x25c / 4](M, 0x685f44, 0);
  if (ent) {
    void *lst = *(void **)(ent + 0x18);
    if (lst) {
      u32 var10;
      (*(v1_t **)lst)[0x4c / 4](lst, (u32)&var10);
      lst = *(void **)(ent + 0x18);
      u32 id = (*(v1_t **)lst)[0x5c / 4](lst, (u32)&var10);
      while (var10 != 0) {
        void *t2 = *(void **)(*(u8 **)0x70039c + 0x9b);
        void *t = (void *)(*(v1_t **)t2)[0x58 / 4](t2, id);
        if (t) {
          u8 *r = (u8 *)(*(v0_t **)t)[0x20 / 4](t);
          const char *s = *(const char **)(r + 4);
          if (!s) s = (const char *)0x67c8e8;
          if (imp_stricmp(s, (const char *)name) == 0) {
            u32 found = id;
            u8 *n2 = ext_5003d0(*(u32 *)(a + 8), 0);
            ext_50d7b0(n2, &found);
            return;
          }
        }
        lst = *(void **)(ent + 0x18);
        id = (*(v1_t **)lst)[0x5c / 4](lst, (u32)&var10);
      }
    }
  }
  u8 *n = ext_5003d0(*(u32 *)(a + 8), 0);
  if (n[4] > 1) logfail(0x104, 0x69c938);
  n[4] = 1;
  *(u32 *)n = 0;
}
PCREG(50dfa0, fn50dfa0);
