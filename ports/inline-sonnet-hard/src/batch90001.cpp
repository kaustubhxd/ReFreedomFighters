// batch 90001: 0x5af350 ZFFInventoryBridge::GetNoOf(EFFItemType) -- jump table on (type - 0xc): 0xc,0xd -> branch A (0x5af3a0), 0xe..0x10 -> branch B (0x5af430), else 0.
// thiscall(this, type) ret 4. this[0] = player-ish object, this[1] = list (count at +0, entries at +4..), this[2] = object with slot 0x98.
#include "ff.h"

extern "C" u32 *THISCALL ext_5af130(void *list, u32 type);   // find entry by type (entry+0x10), ret 4
extern "C" u32 THISCALL ext_5af300(void *self, void *obj);   // ret 4
extern "C" void THISCALL ext_4ccba0(void *list);              // list constructor, plain ret
extern "C" void THISCALL ext_4ccf60(void *list);              // list destructor body (SEH frame), plain ret

struct VO { void **vt; };
#define VCALL(T, o, off) ((T)((VO *)(o))->vt[(off) / 4])

static void log_fail(u32 line, const char *fmt) {
  VO *lg = *(VO **)0x700390;
  VO *lo = VCALL(VO *(THISCALL *)(VO *, u32, u32), lg, 0x20)(lg, 0x6b0f44, line);
  VCALL(void(__cdecl *)(VO *, const char *), lo, 0x2c)(lo, fmt);
}

static VO *table() { return *(VO **)(*(u32 *)0x70039c + 0x9b); }

static u32 getnoof_5af350(u32 *self, u32 type) {
  u32 idx = type - 0xc;
  if (idx > 4) return 0;
  if (idx < 2) {
    if (!self[0] || !self[1] || !self[2]) {
      log_fail(0x20, (const char *)0x6b0fd0);
      return 0;
    }
    u32 *p = ext_5af130((void *)self[1], type);
    if (!p || !*p) return 0;
    VO *o2 = (VO *)self[2];
    u32 r = VCALL(u32(THISCALL *)(VO *, u32, u32), o2, 0x98)(o2, *p, 0);
    VO *t = table();
    VO *e = VCALL(VO *(THISCALL *)(VO *, u32), t, 0x58)(t, r);
    if (!e) return 0;
    return ext_5af300(self, e);
  }
  if (!self[0] || !self[1] || !self[2]) {
    log_fail(0x35, (const char *)0x6b1020);
    return 0;
  }
  u32 *p = ext_5af130((void *)self[1], type);
  if (!p || !*p) return 0;
  u8 L[0xc0];
  ext_4ccba0(L);
  VO *a = (VO *)self[0];
  VO *tb = table();
  u32 ax = VCALL(u32(THISCALL *)(VO *, u32, u32, u32, u32, void *), tb, 0x114)(tb, 0x690a30, 0, 0x6b0f44, 0x3d, L);
  VCALL(void(THISCALL *)(VO *, VO *, u32), a, 0x130)(a, a, ax & 0xffff);
  u32 it[2];
  u32 cnt = 0;
  VO *lv = (VO *)L;
  VCALL(void(THISCALL *)(VO *, u32 *), lv, 0x4c)(lv, it);
  u32 el = VCALL(u32(THISCALL *)(VO *, u32 *), lv, 0x5c)(lv, it);
  while (it[0] != 0) {
    VO *t = table();
    VO *o = VCALL(VO *(THISCALL *)(VO *, u32), t, 0x58)(t, el);
    if (VCALL(u32(THISCALL *)(VO *), o, 0x2e8)(o) == *p) cnt++;
    el = VCALL(u32(THISCALL *)(VO *, u32 *), lv, 0x5c)(lv, it);
  }
  ext_4ccf60(L);
  return cnt;
}

static u32 THISCALL entry_5af350(u32 *self, u32 type) { return getnoof_5af350(self, type); }
PCREG(5af350, entry_5af350);
