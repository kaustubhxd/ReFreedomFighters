// batch36022.cpp - cascade s4 batch 36022: 0x5331f0, 0x536650, 0x537ed0, 0x57a5c0, 0x554bf0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v0u_t)(void *);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u32(THISCALL *v3u_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v6u_t)(void *, u32, u32, u32, u32, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
static inline u8 *tabOf() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 *logOpen(u32 file, u32 line) {
  u8 *db = G(u8 *, 0x700390);
  return (*(v2o_t **)db)[0x20 / 4](db, file, line);
}
// o->slot 0x2c cdecl(o, fmt) with ecx = o->vtbl, caller pops 8
static inline void logf2(u8 *o, u32 fmt) {
  void **vt2 = *(void ***)o;
  void *fn = *(void **)((u8 *)vt2 + 0x2c);
  __asm__ volatile("pushl %[f2]\n\tpushl %[o]\n\tcall *%[f]\n\taddl $8, %%esp"
                   : "+c"(vt2) : [f2] "r"(fmt), [o] "r"(o), [f] "r"(fn) : "eax", "edx", "memory", "cc");
}

// 0x5331f0, thiscall(no args) (this = E): n = E[0x546e]; zero returns. Logs (0x6a184c, 0x15f, 0x6a1888) and (0x160, 0x6a18a4); for i < n (signed): r = E->slot 0x248(i);
// logs (0x164, 0x6a18dc, r + 0x44, r[0xc4], (u8) r[0xc8]) with five stack args; finally logs (0x166, 0x6a18a4).
static void THISCALL fn5331f0(u8 *E) {
  if (rd(E + 0x546e) == 0) return;
  logf2(logOpen(0x6a184c, 0x15f), 0x6a1888);
  logf2(logOpen(0x6a184c, 0x160), 0x6a18a4);
  s32 i = 0;
  if ((s32)rd(E + 0x546e) > 0) {
    do {
      u8 *r = (*(v1o_t **)E)[0x248 / 4](E, (u32)i);
      u8 *o = logOpen(0x6a184c, 0x164);
      void **vt2 = *(void ***)o;
      void *fn = *(void **)((u8 *)vt2 + 0x2c);
      u32 b = r[0xc8];
      u32 c4 = rd(r + 0xc4);
      u32 p44 = (u32)(r + 0x44);
      ((void (*)(u8 *, u32, u32, u32, u32))fn)(o, 0x6a18dcu, p44, c4, b);  // cdecl varargs print (ecx = vtable in the exe is not read by it)
      (void)vt2;
      i++;
    } while (i < (s32)rd(E + 0x546e));
  }
  logf2(logOpen(0x6a184c, 0x166), 0x6a18a4);
}
PCREG(5331f0, fn5331f0);

// 0x536650, thiscall(a, b) ret 8 (this = E), returns eax: a == 0 or b == 0 or E[0x5302] == 0 -> 0; r = E[0x5302] + a: r[0] != 3 -> log (0x6a1e2c, 0x39e, 0x6a2058) through slot 0x30 and 0;
// else strlen(b) == 0: E->slot 0x1c0(r); otherwise E->slot 0x1c4(r, b, 2).
static u32 THISCALL fn536650(u8 *E, u32 a, const u8 *b) {
  if (!a) return 0;
  if (!b) return 0;
  u8 *base = *(u8 **)(E + 0x5302);
  if (!base) return 0;
  u8 *r = base + a;
  if (rd(r) != 3) {
    u8 *o = logOpen(0x6a1e2c, 0x39e);
    void **vt2 = *(void ***)o;
    void *fn = *(void **)((u8 *)vt2 + 0x30);
    __asm__ volatile("pushl $0x6a2058\n\tpushl %[o]\n\tcall *%[f]\n\taddl $8, %%esp"
                     : "+c"(vt2) : [o] "r"(o), [f] "r"(fn) : "eax", "edx", "memory", "cc");
    return 0;
  }
  if (b[0] == 0) return (*(v1u_t **)E)[0x1c0 / 4](E, (u32)r);
  return (*(v3u_t **)E)[0x1c4 / 4](E, (u32)r, (u32)b, 2);
}
PCREG(536650, fn536650);

extern "C" void THISCALL ext_53aae0(void *self, void *s);  // ret 4
extern "C" void THISCALL ext_534150(void *self);           // plain ret
extern "C" void THISCALL ext_534220(void *self, void *s);  // ret 4

// 0x537ed0, thiscall(s) ret 4, returns 1 (this = E): s->slot 0xc(0x14); sub = E + 0x53b2; s->slot 0x70(sub); E[0x52fa] non-null: 0x53aae0(E[0x52fa], s); 0x534150(E + 0x109f); 0x534220(E + 0x8b, s);
// sub->slot 0x4c(&loc); r = sub->slot 0x5c(&loc); while loc != 0: t = tab->slot 0x60(r); t && t[4] == 1: t[4] = 5; r = sub->slot 0x5c(&loc).
static u8 THISCALL fn537ed0(u8 *E, u8 *s) {
  u32 loc[3];
  (*(v1_t **)s)[0xc / 4](s, 0x14);
  u8 *sub = E + 0x53b2;
  (*(v1_t **)s)[0x70 / 4](s, (u32)sub);
  u8 *x = *(u8 **)(E + 0x52fa);
  if (x) ext_53aae0(x, s);
  ext_534150(E + 0x109f);
  ext_534220(E + 0x8b, s);
  (*(v1_t **)sub)[0x4c / 4](sub, (u32)loc);
  u32 r = (*(v1u_t **)sub)[0x5c / 4](sub, (u32)loc);
  if (loc[0] == 0) return 1;
  do {
    u8 *t = tabOf();
    u8 *e = (*(v1o_t **)t)[0x60 / 4](t, r);
    if (e && rd(e + 4) == 1) wr(e + 4, 5);
    r = (*(v1u_t **)sub)[0x5c / 4](sub, (u32)loc);
  } while (loc[0] != 0);
  return 1;
}
PCREG(537ed0, fn537ed0);

extern "C" u32 THISCALL ext_561cb0(void *self, u32 code, u32 *p);  // ret 8
extern "C" void THISCALL ext_563500(void *self);                    // plain ret

// 0x57a5c0, thiscall(code, p) ret 8 (this = E), returns eax: (u16)code != (u16)tab->slot 0x114(0x6a6684, 0, 0x6a9ecc, 0x8a): 0x561cb0(E, code, p).
// Else: a = E[0x94], a && a[0x103f]: i = *p; E[i + 0x193] == 0 -> 0; clear it; any of E[0x194..0x197] non-zero: 0x57aaf0(E), return 0; (all zero) falls to the notify step.
// a null or a[0x103f] == 0: 0x563500(E); E[0x184] = [0x7003a0][0x6c]; E[0x194] = 0. Notify: E->slot 0x84()->slot 0x300(); return 0.
extern "C" void THISCALL ext_57aaf0(void *self);
typedef u32(THISCALL *v4u_t)(void *, u32, u32, u32, u32);
static u32 THISCALL fn57a5c0(u8 *E, u32 code, u32 *p) {
  u8 *t = tabOf();
  u32 ax = (*(v4u_t **)t)[0x114 / 4](t, 0x6a6684u, 0, 0x6a9ecc, 0x8a);
  if ((u16)code != (u16)ax) return ext_561cb0(E, code, p);
  u8 *a = *(u8 **)(E + 0x94);
  if (a && a[0x103f]) {
    u32 i = *p;
    if (E[i + 0x193] == 0) return 0;
    E[i + 0x193] = 0;
    bool allzero = E[0x197] == 0 && E[0x196] == 0 && E[0x195] == 0 && E[0x194] == 0;
    if (!allzero) {
      ext_57aaf0(E);
      return 0;
    }
  } else {
    ext_563500(E);
    wr(E + 0x184, rd(*(u8 **)0x7003a0 + 0x6c));
    E[0x194] = 0;
  }
  u8 *x = (*(v0o_t **)E)[0x84 / 4](E);
  (*(v0_t **)x)[0x300 / 4](x);
  return 0;
}
PCREG(57a5c0, fn57a5c0);

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 a);   // ret 4
extern "C" void THISCALL ext_5002f0(void *self, u32 a);  // ret 4
extern "C" u32 THISCALL ext_506040(void *self);          // plain ret

// 0x554bf0, stdcall(a) ret 4: 0x5002f0(0x5003d0(a[8], 0), 0); x = tab->slot 0x138(); local = 0; x->slot 0x88(0x6a5c48, &local); obj = tab->slot 0x58(local), null returns.
// 0x506040(0x5003d0(a[4], 0)); id = tab->slot 0x114(0x6a5c68, 0, 0x6a57fc, 0x451, &out, 0); obj->slot 0x128((u16)id); 0x5002f0(0x5003d0(a[8], 0), out).
typedef u32(THISCALL *v6b_t)(void *, u32, u32, u32, u32, u32, u32);
static void STDCALL fn554bf0(u8 *a) {
  u32 local = 0;
  u32 out;
  u8 *r0 = ext_5003d0(*(u8 **)(a + 8), 0);
  ext_5002f0(r0, 0);
  u8 *t = tabOf();
  u8 *x = (*(v0o_t **)t)[0x138 / 4](t);
  (*(v2_t **)x)[0x88 / 4](x, 0x6a5c48, (u32)&local);
  t = tabOf();
  u8 *obj = (*(v1o_t **)t)[0x58 / 4](t, local);
  if (!obj) return;
  u8 *r1 = ext_5003d0(*(u8 **)(a + 4), 0);
  (void)ext_506040(r1);
  void **ovt = *(void ***)obj;
  t = tabOf();
  u32 id = (*(v6b_t **)t)[0x114 / 4](t, 0x6a5c68, 0, 0x6a57fc, 0x451, (u32)&out, 0);
  ((v1_t)ovt[0x128 / 4])(obj, (u16)id);
  u8 *r2 = ext_5003d0(*(u8 **)(a + 8), 0);
  ext_5002f0(r2, out);
}
PCREG(554bf0, fn554bf0);
