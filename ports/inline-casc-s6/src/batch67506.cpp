// batch67506.cpp - cascade s6 batch 67506: 0x50b860.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 idx);   // ret 4
extern "C" u8 *THISCALL ext_5002f0(u8 *node, u32 v);     // ret 4
extern "C" void THISCALL ext_441730(u8 *g);              // plain ret
extern "C" void THISCALL ext_440530(u8 *g);              // plain ret
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd2_t)(void *, u32);
typedef void (*cd3_t)(void *, u32, u32);
typedef void (STDCALL *cmd_t)(void *, u32, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

static void *logger(u32 line, u32 file) {
  u8 *lg = *(u8 **)0x700390;
  return (void *)(*(v2_t **)lg)[0x20 / 4](lg, file, line);
}

// 0x50b860, stdcall(a) ret 4: script op "send command". The result node a+8 is first set to int 0. Argument 1 resolves to an object that must answer slot 0x1e0 (0x1007d1) (error
// 0x3c0 when missing, 0x3c5 with its name when not) and argument 0 to the target object (error 0x3cb when missing). Then, bracketed by the global helper calls 0x441730 / 0x440530
// on the object at 0x69d8f0, the command id registered under the name at 0x688dd8 (table slot 0x114) is sent to the target through its slot 0x130 with the first argument's value.
static void STDCALL fn50b860(u8 *a) {
  ext_5002f0(ext_5003d0(*(u32 *)(a + 8), 0), 0);
  u8 *esi = (u8 *)vcall<u32>(tabObj(), 0x58, D32(ext_5003d0(*(u32 *)(a + 4), 1), 0));
  if (!esi) {
    void *L = logger(0x3c0, 0x69d420);
    (*(cd2_t **)L)[0x2c / 4](L, 0x69d780);
    return;
  }
  if (!(u8)vcall<u32>(esi, 0x1e0, 0x1007d1u)) {
    void *L = logger(0x3c5, 0x69d420);
    (*(cd3_t **)L)[0x2c / 4](L, 0x69d5fc, D32(esi, 4));
    return;
  }
  u8 *ebx = (u8 *)vcall<u32>(tabObj(), 0x58, D32(ext_5003d0(*(u32 *)(a + 4), 0), 0));
  if (!ebx) {
    void *L = logger(0x3cb, 0x69d420);
    (*(cd2_t **)L)[0x2c / 4](L, 0x69d8a8);
    return;
  }
  ext_441730((u8 *)0x69d8f0);
  u32 id = (u16)vcall<u32>(tabObj(), 0x114, 0x688dd8u, 0u, 0x69d420u, 0x3ddu);
  u8 *n = ext_5003d0(*(u32 *)(a + 4), 1);
  (*(cmd_t *)(*(u8 **)ebx + 0x130))(ebx, id, D32(n, 0));
  ext_440530((u8 *)0x69d8f0);
}
PCREG(50b860, fn50b860);
