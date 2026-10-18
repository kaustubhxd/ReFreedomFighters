#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V5)(void *, u32, u32, u32, float, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" u32 THISCALL ext_5743c0(void *self, u32 a, u32 flag);
extern "C" u32 THISCALL ext_573af0(void *self, u32 a);
extern "C" u32 THISCALL ext_574680(void *self, u32 a0, u32 a1, float f, float *out, float k);
extern "C" u32 THISCALL ext_575bd0(void *self);
extern "C" u32 THISCALL ext_575d00(void *self);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline void show(u32 obj, u32 arg) { void *o = (void *)obj; (*(V1 *)(vt(o) + 0xbc))(o, arg); }

// 0x5759e0: thiscall(a, flag) ret 8, returns 0 in AL (/GS protected): refreshes a panel after selecting entry a. 0x5743c0(this, a, flag); a set flag sets this[0x21b]; 0x573af0(this, this[0x1b8]);
// the engine object's slot 0xbc()->slot 0xdc() picks the float constant [0x6a913c] (true) or [0x67da0c] for 0x574680(this[0x1b8], this[0x1c8], f, &out, 1.7f); 0x575bd0(this);
// widgets this[0x1e0], [0x1e8]..: slot 0xbc(1 / 0 / 0), [0x188] (1), [0x20e] (0). With the flag: the first of the 5 entries at this+0x224 (stride 0x24) whose name ([entry + 4], or the
// string at 0x67c8e8) equals the string at this[0x94] + 0x48 is selected through this slot 0x84()->slot 0x2ec(entry); without it this[0x206] is reselected the same way, or created with
// slot 0x2f0() when zero, then 0x575d00(this). Finally this slot 0x84()->slot 0x34c(2, 0, this[0x44], 10.0f, 0).
extern "C" u32 THISCALL fn_5759e0(u8 *self, u32 a, u32 flag) {
  float out[3];
  ext_5743c0(self, a, flag);
  u8 fl = (u8)flag;
  if (fl) self[0x21b] = 1;
  ext_573af0(self, rd32u(self + 0x1b8));
  void *g = G(void *, 0x70039c);
  void *x = (void *)(*(V0 *)(vt(g) + 0xbc))(g);
  float f;
  if ((u8)(*(V0 *)(vt(x) + 0xdc))(x)) f = G(float, 0x6a913c);
  else f = G(float, 0x67da0c);
  ext_574680(self, rd32u(self + 0x1b8), rd32u(self + 0x1c8), f, out, bitsf(0x3fd9999a));
  ext_575bd0(self);
  show(rd32u(self + 0x1e0), 1);
  show(rd32u(self + 0x1e4), 0);
  show(rd32u(self + 0x1e8), 0);
  show(rd32u(self + 0x188), 1);
  show(rd32u(self + 0x20e), 0);
  if (fl) {
    for (u32 i = 0; i < 5; i++) {
      u8 *ent = (u8 *)rd32u(self + 0x224 + i * 0x24);
      if (!ent) continue;
      const char *s = (const char *)rd32u(ent + 4);
      if (!s) s = (const char *)0x67c8e8;
      const char *t = (const char *)rd32u(self + 0x94) + 0x48;
      for (;;) {
        if (*s != *t) goto next;
        if (!*s) break;
        s++;
        t++;
      }
      {
        void *y = (void *)(*(V0 *)(vt(self) + 0x84))(self);
        (*(V1 *)(vt(y) + 0x2ec))(y, (u32)ent);
        goto done;
      }
    next:;
    }
  } else {
    void *y = (void *)(*(V0 *)(vt(self) + 0x84))(self);
    if (rd32u(self + 0x206)) {
      (*(V1 *)(vt(y) + 0x2ec))(y, rd32u(self + 0x206));
    } else {
      u32 r = (*(V0 *)(vt(y) + 0x2f0))(y);
      wr32u(self + 0x206, r);
    }
    ext_575d00(self);
  }
done:
  {
    void *y = (void *)(*(V0 *)(vt(self) + 0x84))(self);
    (*(V5 *)(vt(y) + 0x34c))(y, 2, 0, rd32u(self + 0x44), bitsf(0x41200000), 0);
  }
  ext_633654(G(u32, 0x6f5630));
  return 0;
}
PCREG(5759e0, fn_5759e0);
