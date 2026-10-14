// batch34055.cpp - cascade tier E, batch 34055: 0x420ea0 (build the path of error.log next to the executable), 0x447bf0 (flag an entry and tell the observer), 0x454da0 (copy a child list when
// the source has a given kind).
#include "ff.h"

typedef u32(STDCALL *gmfn_t)(u32 mod, char *buf, u32 size);
typedef char *(*strrchr_t)(const char *s, int c);   // cdecl, VCRUNTIME140
extern "C" void THISCALL ext_4cbe80(void *self, const char *path);   // thiscall ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);                     // /GS check
extern "C" void THISCALL ext_45c680(void *self, u32 f);              // thiscall ret 4
extern "C" void THISCALL ext_4dc630(void *self, u32 a, u32 b);       // thiscall ret 8
extern "C" void THISCALL ext_4dbb00(void *self, u32 a);              // thiscall ret 4
extern "C" void THISCALL ext_43f8c0(void *self, void *a);            // thiscall (tail-jumps to a ret 4 body)

// 0x420ea0, cdecl(a), returns a: GetModuleFileNameA(0, buf, 0x400); a backslash found by strrchr(buf, '\\') gets a terminator right after it; then the 10 bytes at 0x677a60 ("error.log" and its
// terminator) are appended at the end of the string; 0x4cbe80(a, buf); the /GS check.
static u32 fn420ea0(u8 *a) {
  char buf[0x400];
  G(gmfn_t, 0x67607c)(0, buf, 0x400);
  char *p = G(strrchr_t, 0x676258)(buf, 0x5c);
  if (p) p[1] = 0;
  char *e = buf;
  while (*e) e++;
  const u8 *k = (const u8 *)0x677a60;
  for (int i = 0; i < 10; i++) e[i] = k[i];
  ext_4cbe80(a, buf);
  ext_633654(0);
  return (u32)a;
}
PCREG(420ea0, fn420ea0);

// 0x447bf0, thiscall(f) ret 4: 0x45c680(this, f); [this+0x18] |= 8; o = [this+0x8]; nothing more when [o+0x68] is zero. With f: 0x4dc630(o, 0x3000000, 0x400); the observer at the unaligned
// [[engine table]+0x5d35] (when set) gets slot 0x14(o). Without f: 0x4dc630(o, 0x1000400, 0); when the observer exists 0x4dbb00(o, 0) and observer slot 0x14(o).
static void THISCALL fn447bf0(u8 *self, u32 f) {
  ext_45c680(self, f);
  u8 *o = *(u8 **)(self + 8);
  *(u32 *)(self + 0x18) |= 8;
  if (*(u32 *)(o + 0x68) == 0) return;
  u8 *tbl = nullptr;
  if ((u8)f) {
    ext_4dc630(o, 0x3000000, 0x400);
    tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *obs = (u8 *)(tbl[0x5d35] | tbl[0x5d36] << 8 | tbl[0x5d37] << 16 | (u32)tbl[0x5d38] << 24);
    if (!obs) return;
    vcall<void>(obs, 0x14, (u32)*(u8 **)(self + 8));
    return;
  }
  ext_4dc630(o, 0x1000400, 0);
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *obs = (u8 *)(tbl[0x5d35] | tbl[0x5d36] << 8 | tbl[0x5d37] << 16 | (u32)tbl[0x5d38] << 24);
  if (!obs) return;
  ext_4dbb00(*(u8 **)(self + 8), 0);
  vcall<void>(obs, 0x14, (u32)*(u8 **)(self + 8));
}
PCREG(447bf0, fn447bf0);

// 0x454da0, thiscall(a) ret 4: [this+0x5c]->slot0xc(); when the dword at +0x23 of the record [a+0xc] equals 0x1000f0 and [a+0x5c] exists: walks it (slot 0x4c begin, slot 0x5c next with a stack
// iterator) calling [this+0x5c]->slot4(id) for every id; finally 0x43f8c0(this, a).
static void THISCALL fn454da0(u8 *self, u8 *a) {
  u32 it[3];
  vcall<void>(*(u8 **)(self + 0x5c), 0xc);
  u8 *rec = *(u8 **)(a + 0xc);
  u32 kind = rec[0x23] | rec[0x24] << 8 | rec[0x25] << 16 | (u32)rec[0x26] << 24;
  if (kind == 0x1000f0) {
    u8 *n = *(u8 **)(a + 0x5c);
    if (n) {
      vcall<void>(n, 0x4c, (u32)it);
      u32 id = vcall<u32>(*(u8 **)(a + 0x5c), 0x5c, (u32)it);
      if (it[0] != 0) {
        do {
          vcall<void>(*(u8 **)(self + 0x5c), 4, id);
          id = vcall<u32>(*(u8 **)(a + 0x5c), 0x5c, (u32)it);
        } while (it[0] != 0);
      }
    }
  }
  ext_43f8c0(self, a);
}
PCREG(454da0, fn454da0);
