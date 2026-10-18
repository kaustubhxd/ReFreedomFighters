#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef void (*Fn0)(void);

extern "C" void THISCALL ext_4e11e0(void *ar, void *out, u32 flag);
extern "C" void THISCALL ext_4e12e0(void *ar, void *out, u32 flag);
extern "C" void THISCALL ext_4e12f0(void *ar, void *out, u32 flag);
extern "C" u32 THISCALL ext_4e1600(void *ar);
extern "C" void THISCALL ext_4e1b30(void *ar);
extern "C" void THISCALL ext_441890(void *obj, float v);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

static inline u32 cdecl2_ecx(u32 fn, u32 ecx_, u32 a, u32 b) {
  u32 r;
  __asm__ volatile("pushl %[b]; pushl %[a]; call *%%eax; addl $8,%%esp" : "=a"(r), "+c"(ecx_) : "0"(fn), [a] "r"(a), [b] "r"(b) : "edx", "memory", "cc");
  return r;
}

// 0x44bdb0: archive-reader for a record (self[0x18] = the record): an id (0..9, mapped to record[8] = id + 1), six dwords/floats, and in archive type 3 a flags group followed by
// the sign flip of record[0x4c]; in type 2 one more unaligned float at record+0xf9. Always ends by calling 0x4e1b30(archive). thiscall(archive*) ret 4; gated on the engine
// flag [[0x70039c]+0x1a9f] and slot 0x2c of the object table returning false.
extern "C" void THISCALL fn_44bdb0(u8 *self, u8 *ar) {
  u32 id;
  u32 tmp;
  float fl;
  u32 v12;
  u8 *eng = G(u8 *, 0x70039c);
  if (rd32u(eng + 0x1a9f) == 0) goto fin;
  {
    u8 *T = (u8 *)rd32u(eng + 0x9b);
    if ((u8)(*(V0 *)(vt(T) + 0x2c))(T)) goto fin;
  }
  if (rd32u(self + 0x18) == 0) goto fin;
  ext_4e11e0(ar, &id, 1);
  if (id > 9) {
    u8 *o = G(u8 *, 0x700390);
    u32 r = (*(u32(THISCALL **)(void *, u32, u32))(vt(o) + 0x20))(o, 0x67fe5c, 0x166);
    cdecl2_ecx(rd32u(vt((void *)r) + 0x2c), rd32u((u8 *)r), r, 0x67feec);
    Fn0 f = G(Fn0, 0x7003b0);
    if (f) f();
    else __asm__ volatile("int3");
  } else {
    wr32u((u8 *)rd32u(self + 0x18) + 8, id + 1);
  }
  ext_4e11e0(ar, (u8 *)rd32u(self + 0x18) + 0x7c, 1);
  ext_4e12f0(ar, (u8 *)rd32u(self + 0x18) + 0x44, 1);
  ext_4e12f0(ar, (u8 *)rd32u(self + 0x18) + 0x48, 1);
  ext_4e12f0(ar, (u8 *)rd32u(self + 0x18) + 0x4c, 1);
  ext_4e12f0(ar, (u8 *)rd32u(self + 0x18) + 0x50, 1);
  if ((u8)ext_4e1600(ar) == 3) ext_4e12e0(ar, &tmp, 1);
  if ((u8)ext_4e1600(ar) == 3) {
    tmp = 0;
    ext_4e11e0(ar, &tmp, 1);
    if (tmp != 0) {
      u8 *X = (u8 *)rd32u(self + 0x18);
      wr32u(X + 0x40, rd32u(X + 0x40) | 8);
    }
    ext_4e12f0(ar, (u8 *)rd32u(self + 0x18) + 0x88, 1);
    ext_4e12f0(ar, &fl, 1);
    ext_441890((void *)rd32u(self + 0x18), fl);
    ext_4e11e0(ar, &v12, 1);
    {
      u8 *X = (u8 *)rd32u(self + 0x18);
      wr32u(X + 0x40, rd32u(X + 0x40) | 0x80);
      wr32u(X + 0x2c, v12);
    }
    ext_4e11e0(ar, &tmp, 1);
    {
      u8 *X = (u8 *)rd32u(self + 0x18);
      if (tmp != 0) wr32u(X + 0x40, rd32u(X + 0x40) | 2);
      else wr32u(X + 0x40, rd32u(X + 0x40) & 0xfffffffd);
    }
  }
  {
    u8 *X = (u8 *)rd32u(self + 0x18);
    float f4c;
    __builtin_memcpy(&f4c, X + 0x4c, 4);
    if (f4c > 0.0f) wr32u(X + 0x4c, rd32u(X + 0x4c) ^ G(u32, 0x67af40));
  }
  {
    u8 al = (u8)ext_4e1600(ar);
    u8 *X = (u8 *)rd32u(self + 0x18);
    if (al == 2) {
      ext_4e12f0(ar, X + 0xf9, 1);
    } else {
      wr32u(X + 0xf9, 0);
    }
  }
fin:
  ext_4e1b30(ar);
}
PCREG(44bdb0, fn_44bdb0);
