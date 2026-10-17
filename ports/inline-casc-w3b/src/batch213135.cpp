#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef int (*StrCmp)(u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" u32 THISCALL ext_5003d0(void *tab, u32 zero);
extern "C" u32 ext_5fa630();
extern "C" void ext_634273(void *p, u32 one);
extern "C" void *ext_41e290(u32 n);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline u32 slen(const char *s) { u32 n = 0; while (s[n]) n++; return n; }

static inline u32 cdecl4_ecx(u32 fn, u32 ecx_, u32 a, u32 b, u32 c, u32 d) {
  u32 r;
  __asm__ volatile("pushl %[d]; pushl %[c]; pushl %[b]; pushl %[a]; call *%%eax; addl $16,%%esp"
                   : "=a"(r), "+c"(ecx_) : "0"(fn), [a] "r"(a), [b] "r"(b), [c] "r"(c), [d] "r"(d) : "edx", "memory", "cc");
  return r;
}
static inline u32 cdecl3_ecx(u32 fn, u32 ecx_, u32 a, u32 b, u32 c) {
  u32 r;
  __asm__ volatile("pushl %[c]; pushl %[b]; pushl %[a]; call *%%eax; addl $12,%%esp"
                   : "=a"(r), "+c"(ecx_) : "0"(fn), [a] "r"(a), [b] "r"(b), [c] "r"(c) : "edx", "memory", "cc");
  return r;
}
static inline u32 fmt_d(u32 fn, u32 ecx_, u32 P, u32 buf, u32 fmt, double d) {
  u32 r;
  __asm__ volatile("subl $8,%%esp; movsd %[d],(%%esp); pushl %[fmt]; pushl %[buf]; pushl %[P]; call *%%eax; addl $20,%%esp"
                   : "=a"(r), "+c"(ecx_) : "0"(fn), [d] "x"(d), [fmt] "r"(fmt), [buf] "r"(buf), [P] "r"(P) : "edx", "memory", "cc");
  return r;
}

// 0x604a60: thiscall(args) ret 4 on a script string-builder object (string pointer this[0xc], capacity u16 this[0x10]). args[0] is a command name: when it equals the image
// string 0x6b9c20 the text is chosen from two image strings by the value of args[1]'s entry, otherwise it is formatted by the type byte of that entry (1: int, 2: float as double,
// 4: copy of another string object, else logged assert); the formatted text is stored into this's buffer (reallocating when it does not fit), then args[2]'s entry is
// released (type 4 -> slot 0x28) and replaced by this slot 0x24()'s result with type 4.
extern "C" void THISCALL fn_604a60(u8 *self, u32 *args) {
  char buf[0x68];
  buf[0] = 1;
  u8 *P;
  u8 *Vv;
  u8 *S;
  if (G(StrCmp, 0x676414)(0x6b9c20, args[0]) == 0) {
    P = (u8 *)ext_5fa630();
    Vv = (u8 *)ext_5003d0((void *)args[1], 0);
    u32 str = (rd32u(Vv) == 0) ? 0x6b9c30 : 0x6b9c28;
    cdecl4_ecx(rd32u(vt(P) + 0x14), str, (u32)P, (u32)buf, 0x677368, str);
  } else {
    Vv = (u8 *)ext_5003d0((void *)args[1], 0);
    u32 type = Vv[4];
    if (type == 1) {
      P = (u8 *)ext_5fa630();
      Vv = (u8 *)ext_5003d0((void *)args[1], 0);
      cdecl4_ecx(rd32u(vt(P) + 0x14), rd32u(P), (u32)P, (u32)buf, 0x69d384, rd32u(Vv));
    } else if (type == 2) {
      P = (u8 *)ext_5fa630();
      Vv = (u8 *)ext_5003d0((void *)args[1], 0);
      float fv;
      __builtin_memcpy(&fv, Vv, 4);
      fmt_d(rd32u(vt(P) + 0x14), rd32u(P), (u32)P, (u32)buf, 0x6792bc, (double)fv);
    } else if (type == 4) {
      Vv = (u8 *)ext_5003d0((void *)args[1], 0);
      S = (u8 *)rd32u(Vv);
      const char *src = (const char *)rd32u(S + 0xc);
      u32 len = slen(src);
      u32 cap = *(u16 *)(self + 0x10);
      if (len > cap - 1) {
        ext_634273((void *)rd32u(self + 0xc), 1);
        void *nb = ext_41e290(*(u16 *)(S + 0x10));
        *(void **)(self + 0xc) = nb;
        *(u16 *)(self + 0x10) = *(u16 *)(S + 0x10);
      }
      const char *s2 = (const char *)rd32u(S + 0xc);
      char *d2 = (char *)rd32u(self + 0xc);
      char c;
      do {
        c = *s2++;
        *d2++ = c;
      } while (c != 0);
      buf[0] = c;
      goto after;
    } else {
      u8 *Eo = G(u8 *, 0x700390);
      u32 o = (*(V2 *)(vt(Eo) + 0x20))(Eo, 0x6b9c38, 0x5d);
      cdecl3_ecx(rd32u(vt((void *)o) + 0x2c), rd32u((u8 *)o), o, 0x69c6b0, 0x6b9c6c);
      typedef void (*Fn0)(void);
      Fn0 f = G(Fn0, 0x7003b0);
      if (f) f();
      else __asm__ volatile("int3");
    }
  }
  if (buf[0] != 0) {
    u32 len = slen(buf);
    u32 cap = *(u16 *)(self + 0x10);
    if (len >= cap) {
      ext_634273((void *)rd32u(self + 0xc), 1);
      u32 l2 = slen(buf);
      *(u16 *)(self + 0x10) = (u16)(l2 + 1);
      void *nb = ext_41e290(*(u16 *)(self + 0x10));
      *(void **)(self + 0xc) = nb;
    }
    char *d2 = (char *)rd32u(self + 0xc);
    const char *s2 = buf;
    char c;
    do {
      c = *s2++;
      *d2++ = c;
    } while (c != 0);
  }
after:
  u8 *V2r = (u8 *)ext_5003d0((void *)args[2], 0);
  u8 t = V2r[4];
  if (t != 0) {
    if (t != 4) goto done;
    u8 *obj = (u8 *)rd32u(V2r);
    (*(V0 *)(vt(obj) + 0x28))(obj);
  }
  {
    u32 nv = (*(V0 *)(vt(self) + 0x24))(self);
    *(u32 *)V2r = nv;
    V2r[4] = 4;
  }
done:
  ext_633654(G(u32, 0x6f5630));
}
PCREG(604a60, fn_604a60);
