// batch36075.cpp - cascade s4 batch 36075: 0x551d70, 0x555a40, 0x56c950 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32(THISCALL *v4r_t)(void *, u32, u32, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *src2_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4
extern "C" void THISCALL ext_5002f0(void *self, u32 a);  // ret 4
extern "C" u8 *THISCALL ext_553d00(void *self);          // plain ret

// 0x551d70, thiscall(p) ret 4 (this = s): rec = {*0x5003d0(p[4], 0), *(.., 1), *(.., 2), 0, 0, 0}; x = s[0xc]; x == 0: 0x553d00(s); x = s[0xc]; still 0: logger(0x6a57fc, 0x265) prints (cdecl) 0x6a5894; 0x5002f0(0x5003d0(p[8], 0), 0); return.
// Else x->slot 0x21 (0x84)(&rec); 0x5002f0(0x5003d0(p[8], 0), rec[0]).
static void THISCALL fn551d70(u8 *s, u8 *p) {
  u32 rec[6];
  rec[0] = rd(ext_5003d0(*(u8 **)(p + 4), 0));
  rec[1] = rd(ext_5003d0(*(u8 **)(p + 4), 1));
  rec[2] = rd(ext_5003d0(*(u8 **)(p + 4), 2));
  rec[3] = rec[4] = rec[5] = 0;
  u8 *x = *(u8 **)(s + 0xc);
  if (!x) {
    ext_553d00(s);
    x = *(u8 **)(s + 0xc);
    if (!x) {
      u8 *db = G(u8 *, 0x700390);
      u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x6a57fcu, 0x265u);
      void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
      ((void (*)(u8 *, u32))fn)(lo, 0x6a5894u);
      u8 *y = ext_5003d0(*(u8 **)(p + 8), 0);
      ext_5002f0(y, 0);
      return;
    }
  }
  (*(v1_t **)x)[0x84 / 4](x, (u32)rec);
  u8 *y = ext_5003d0(*(u8 **)(p + 8), 0);
  ext_5002f0(y, rec[0]);
}
PCREG(551d70, fn551d70);

// 0x555a40, stdcall(p) ret 4: id = *0x5003d0(p[4], 0); v = *0x5003d0(p[4], 1); o = tab->slot 0x58(id); ax = (u16)tab->slot 0x114(0x6a5830, 0, 0x6a57fc, 0xdc); o->slot 0x4a (0x128)(ax, &l, 0).
// l == v -> flag 1; l != 0 -> flag 0; l == 0: ax2 = (u16)tab->slot 0x114(0x6a583c, 0, 0x6a57fc, 0xed); o->slot 0x4a(ax2, &l2, 0): l2 == 0 or l2 == v -> flag 1, else flag 0. 0x5002f0(0x5003d0(p[8], 0), flag).
static void STDCALL fn555a40(u8 *p) {
  u32 id = rd(ext_5003d0(*(u8 **)(p + 4), 0));
  u32 v = rd(ext_5003d0(*(u8 **)(p + 4), 1));
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, id);
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 ax = (u16)(*(v4r_t **)tab)[0x114 / 4](tab, 0x6a5830u, 0, 0x6a57fcu, 0xdcu);
  void **vt = *(void ***)o;
  u32 l = 0;
  ((v3_t)vt[0x128 / 4])(o, ax, (u32)&l, 0);
  u32 flag;
  if (l == v) {
    flag = 1;
  } else if (l != 0) {
    flag = 0;
  } else {
    tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 l2 = 0;
    u32 ax2 = (u16)(*(v4r_t **)tab)[0x114 / 4](tab, 0x6a583cu, 0, 0x6a57fcu, 0xedu);
    ((v3_t)vt[0x128 / 4])(o, ax2, (u32)&l2, 0);
    if (l2 == 0) flag = 1;
    else if (l2 == v) flag = 1;
    else flag = 0;
  }
  u8 *y = ext_5003d0(*(u8 **)(p + 8), 0);
  ext_5002f0(y, flag);
}
PCREG(555a40, fn555a40);

static void append_text(u8 *dest, u32 name) {
  u8 *end = dest;
  while (*end) end++;
  end[0] = ((u8 *)0x679e6c)[0];
  end[1] = ((u8 *)0x679e6c)[1];
  u8 *obj = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xae4);
  u8 *src = (*(src2_t *)(*(void ***)obj))(obj, 0x6a67e8u, name);
  u32 n = 0;
  while (src[n++]) {}
  u8 *d = dest;
  while (*d) d++;
  for (u32 i = 0; i < n; i++) d[i] = src[i];
}

// 0x56c950, stdcall(dest) ret 4: twice: append the 2 bytes at 0x679e6c to dest, then append the text sys[0x9b][0xae4]->slot 0(0x6a67e8, name) (names 0x6a8184, then 0x6a8198), stdcall with 2 arguments.
static void STDCALL fn56c950(u8 *dest) {
  append_text(dest, 0x6a8184u);
  append_text(dest, 0x6a8198u);
}
PCREG(56c950, fn56c950);
