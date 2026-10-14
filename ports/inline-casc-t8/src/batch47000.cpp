// batch47000.cpp - cascade t8 batch 47000: 0x5f3eb0, 0x57bfe0 (tier F rows).
#include "ff.h"

typedef u32(THISCALL *v0r_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef void (*hook_t)();

extern "C" void THISCALL ext_5f9db0(void *self, void *elem);   // ret 4 (thunk: ecx = [ecx+4], tail jump)
extern "C" void THISCALL ext_562af0(void *self, u32 code);     // ret 4
extern "C" u32 THISCALL ext_562c20(void *self, u32 code);      // ret 4, bool in al

static inline void assert_idx(u32 i, u32 cnt) {
  if (i >= cnt) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
}

// 0x5f3eb0, stdcall(arr, out) ret 8. arr = {+0 data (8-byte entries: elem ptr, type byte at +4), +8 count}. For each entry (bounds assert on every index):
// type 3: out->slot 0(elem); type 4: id = elem->slot 0x38(); out->slot 0(id) (vtable read before the call); elem->slot 0x3c(out); 0x5f9db0(out, elem).
static void STDCALL fn5f3eb0(u8 *arr, u8 *out) {
  u32 i = 0;
  if (!*(u32 *)(arr + 8)) return;
  do {
    assert_idx(i, *(u32 *)(arr + 8));
    u8 *data = *(u8 **)arr;
    u32 t = data[i * 8 + 4];
    if (t == 3) {
      assert_idx(i, *(u32 *)(arr + 8));
      u8 *e = *(u8 **)(*(u8 **)arr + i * 8);
      (**(v1_t **)out)(out, (u32)e);
    } else if (t == 4) {
      assert_idx(i, *(u32 *)(arr + 8));
      u8 *e = *(u8 **)(*(u8 **)arr + i * 8);
      v1_t *vt = *(v1_t **)out;
      u32 id = (*(v0r_t **)e)[0x38 / 4](e);
      vt[0](out, id);
      assert_idx(i, *(u32 *)(arr + 8));
      e = *(u8 **)(*(u8 **)arr + i * 8);
      (*(v1_t **)e)[0x3c / 4](e, (u32)out);
      assert_idx(i, *(u32 *)(arr + 8));
      ext_5f9db0(out, *(u8 **)(*(u8 **)arr + i * 8));
    }
    i++;
  } while (i < *(u32 *)(arr + 8));
}
PCREG(5f3eb0, fn5f3eb0);

// 0x57bfe0, thiscall(code) ret 4, bool. 0x562c20(this, code) nonzero: return 1. Else tbl = engine[0x9b]:
// code 0x61: o = tbl->slot 0x138(); local = 0; o->slot 0x88(0x6aa604, &local); this->slot 0xd0(local); return 1.
// else: o = tbl->slot 0x134(); o->slot 0x68(0x6a75b0, 0, 0); code 0x15 / 0x47 / 0x5b: o = tbl->slot 0x134() again, o->slot 0x68(str, 1, 0)
// (0x6a757c / 0x6a776c / 0x6aa5ec), then 0x562af0(this, code); return 0. Other codes: logger 0x700390 slot 0x20(0x6aa610, 0x58) -> lo, lo->slot 0x2c(0x6aa638, code) (cdecl), return 0.
static u32 THISCALL fn57bfe0(u8 *self, u32 code) {
  if ((u8)ext_562c20(self, code)) return 1;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  void **vt = *(void ***)tbl;
  if (code == 0x61) {
    u8 *o = ((v0o_t)vt[0x138 / 4])(tbl);
    u32 local = 0;
    ((v2_t)(*(void ***)o)[0x88 / 4])(o, 0x6aa604, (u32)&local);
    ((v1_t)(*(void ***)self)[0xd0 / 4])(self, local);
    return 1;
  }
  u8 *o = ((v0o_t)vt[0x134 / 4])(tbl);
  ((v3_t)(*(void ***)o)[0x68 / 4])(o, 0x6a75b0, 0, 0);
  u32 str;
  if (code == 0x15) str = 0x6a757c;
  else if (code == 0x47) str = 0x6a776c;
  else if (code == 0x5b) str = 0x6aa5ec;
  else {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x6aa610, 0x58);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32, u32))fn)(lo, 0x6aa638, code);
    return 0;
  }
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  o = ((v0o_t)(*(void ***)tbl)[0x134 / 4])(tbl);
  ((v3_t)(*(void ***)o)[0x68 / 4])(o, str, 1, 0);
  ext_562af0(self, code);
  return 0;
}
PCREG(57bfe0, fn57bfe0);
