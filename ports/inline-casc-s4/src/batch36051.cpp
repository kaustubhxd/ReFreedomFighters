// batch36051.cpp - cascade s4 batch 36051: 0x6402b0, 0x464d00 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_65f2f0(void *self);                    // plain ret
extern "C" void THISCALL ext_640590(void *self);                    // plain ret
extern "C" void THISCALL ext_63d4a0(void *self, u32 *arr, u32 n);   // ret 8

// 0x6402b0, thiscall(a) ret 4 (this = s): s[5] == 0 -> return. s[6] = 1; s[7] = (a[0xfd] != 0); collect up to s[0xec] entries c of the table at s + 0xf0 whose c[0x10051] == a; each c->slot 0(); 0x65f2f0(s + 0x8270); each c->slot 4();
// s->slot 0xcc(); 0x640590(s); s->slot 0xb8(); 0x63d4a0(s, list, count); s[6] = 0.
static void THISCALL fn6402b0(u8 *s, u8 *a) {
  u32 list[33];
  if (s[5] == 0) return;
  u32 n = rd(s + 0xec);
  s[6] = 1;
  s[7] = (rd(a + 0xfd) != 0);
  u32 cnt = 0;
  if (n) {
    u8 *p = s + 0xf0;
    do {
      u8 *c = *(u8 **)p;
      if (rd(c + 0x10051) == (u32)a) list[cnt++] = (u32)c;
      p += 4;
      n--;
    } while (n);
  }
  for (u32 i = 0; cnt && i != cnt; i++) {
    u8 *c = (u8 *)list[i];
    (*(v0_t **)c)[0](c);
  }
  ext_65f2f0(s + 0x8270);
  for (u32 i = 0; cnt && i != cnt; i++) {
    u8 *c = (u8 *)list[i];
    (*(v0_t **)c)[4 / 4](c);
  }
  (*(v0_t **)s)[0xcc / 4](s);
  ext_640590(s);
  (*(v0_t **)s)[0xb8 / 4](s);
  ext_63d4a0(s, list, cnt);
  s[6] = 0;
}
PCREG(6402b0, fn6402b0);

extern "C" void THISCALL ext_462510(void *self, u32 a);   // ret 4

// 0x464d00, thiscall(flag) ret 4 (this = s): s[0x18] == 0 -> return. s->slot 0x274(). For i < s[0x20] (entries of 0x18 bytes at s[0x1c]): entry[4] & 1: x = entry[0x14]; (u8)flag and (x[0x70][0x7c] & 0x30) -> skip; else entry[0] = x[4]; s->slot 0x340(i, 0).
// Then iterate s[0x18] (slot 0x4c, e = slot 0x64 until 0): ecx = e + 4; (u8)flag and (ecx[0x70][0x7c] & 0x30) -> skip; else 0x462510(ecx, 1) and s[0x18]->slot 0x44(&it) (remove).
static void THISCALL fn464d00(u8 *s, u32 flag) {
  if (rd(s + 0x18) == 0) return;
  (*(v0_t **)s)[0x274 / 4](s);
  u32 n = rd(s + 0x20);
  if (n != 0) {
    u32 i = 0;
    u32 off = 0;
    do {
      u8 *arr = *(u8 **)(s + 0x1c);
      if (arr[off + 4] & 1) {
        u8 *x = *(u8 **)(arr + off + 0x14);
        bool skip = false;
        if ((u8)flag) {
          u8 *q = *(u8 **)(x + 0x70);
          if (q[0x7c] & 0x30) skip = true;
        }
        if (!skip) {
          wr(arr + off, rd(x + 4));
          (*(v2_t **)s)[0x340 / 4](s, i, 0);
        }
      }
      i++;
      off += 0x18;
    } while (i != rd(s + 0x20));
  }
  u8 *l = *(u8 **)(s + 0x18);
  if (!l) return;
  u32 it[3];
  (*(v1_t **)l)[0x4c / 4](l, (u32)it);
  l = *(u8 **)(s + 0x18);
  u8 *e = (*(v1o_t **)l)[0x64 / 4](l, (u32)it);
  while (e) {
    u8 *c = e + 4;
    bool skip = false;
    if ((u8)flag) {
      u8 *q = *(u8 **)(c + 0x70);
      if (q[0x7c] & 0x30) skip = true;
    }
    if (!skip) {
      ext_462510(c, 1);
      l = *(u8 **)(s + 0x18);
      (*(v1_t **)l)[0x44 / 4](l, (u32)it);
    }
    l = *(u8 **)(s + 0x18);
    e = (*(v1o_t **)l)[0x64 / 4](l, (u32)it);
  }
}
PCREG(464d00, fn464d00);
