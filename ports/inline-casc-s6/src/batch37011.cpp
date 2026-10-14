// batch37011.cpp - cascade s6 batch 37011: 0x421b40.
#include "ff.h"

extern "C" void THISCALL ext_533b80(u8 *c);
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(STDCALL *imp7_t)(u32, u32, u32, u32, u32, u32, u32);
typedef u32(STDCALL *imp4_t)(u32, u32, u32, u32);
typedef u32(STDCALL *imp2_t)(u32, u32);
typedef u32(STDCALL *imp1_t)(u32);
#define ENG (*(u8 **)0x70039c)

// 0x421b40, stdcall(hwnd, msg, wparam, lparam) ret 0x10: the window procedure. A message equal to the one slot 0x10 of the object at 0x700390 reports is
// handed to its slot 0x1c; WM_ACTIVATE (6), WM_SETFOCUS (7), WM_KILLFOCUS (8), WM_DESTROY (2) and the SC_xxx system commands are handled here;
// everything else goes to slot 0x200 of the object at [engine+0x190f] or DefWindowProc (IAT 0x676200).
static u32 STDCALL fn421b40(u32 hwnd, u32 msg, u32 wp, u32 lp) {
  void *lg = *(void **)0x700390;
  if (!lg) return 0;
  if (msg == (*(v0_t **)lg)[0x10 / 4](lg)) {
    lg = *(void **)0x700390;
    return (*(v3_t **)lg)[0x1c / 4](lg, msg, wp, lp);
  }
  if (msg == 6) {
    if ((u16)wp) {
      void *e = ENG;
      (*(v0_t **)e)[0x16c / 4](e);
      *(u32 *)(ENG + 0x1b44) = 1;
      if (*(u8 *)(ENG + 0x63)) {
        G(imp7_t, 0x67619c)(hwnd, 0xffffffff, 0, 0, 0, 0, 3);
        G(imp2_t, 0x676198)(hwnd, 9);
      }
    } else {
      u8 *c = *(u8 **)(ENG + 0x1a9f);
      if (c) ext_533b80(c);
      if (*(u8 *)(ENG + 0x1b48)) *(u32 *)(ENG + 0x1b44) = 0;
      if (*(u8 *)(ENG + 0x63)) G(imp7_t, 0x67619c)(hwnd, 1, 0, 0, 0, 0, 3);
    }
  } else if (msg == 2) {
    G(imp1_t, 0x6761c8)(0);
    return 0;
  } else if (msg == 7) {
    void *e = ENG;
    (*(v0_t **)e)[0x16c / 4](e);
    *(u32 *)(ENG + 0x1b44) = 1;
    void *o = *(void **)0x7003a0;
    if (o) (*(v0_t **)o)[0x54 / 4](o);
  } else if (msg == 8) {
    if (*(u8 *)(ENG + 0x1b48)) *(u32 *)(ENG + 0x1b44) = 0;
    void *o = *(void **)0x7003a0;
    if (o) (*(v0_t **)o)[0x58 / 4](o);
  } else if (msg == 0x112) {
    if (wp == 0x1000) G(imp4_t, 0x6761bc)(0, 0x678498, 0x677b5a, 0);
    else if (wp == 0xf120) return 0;
  }
  void *h = *(void **)(ENG + 0x190f);
  if (!h) return G(imp4_t, 0x676200)(hwnd, msg, wp, lp);
  return (*(v3_t **)h)[0x200 / 4](h, msg, wp, lp);
}
PCREG(421b40, fn421b40);
