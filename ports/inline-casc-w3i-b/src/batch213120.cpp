#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef double(THISCALL *VD0)(void *);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" u8 *ext_5fa630();                  // returns [0x724270]
extern "C" u32 THISCALL ext_5f49e0(void *item);  // P.slot 0x1c(item[0x24])

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// cdecl virtual call fn(a[0], ..., a[8]) with ecx = ecxv, caller cleans 36 bytes
static inline void cvcall9(u32 fn, u32 ecxv, const u32 *a) {
  asm volatile(
      "movl $9, %%edx\n\t"
      "1: pushl -4(%[arr],%%edx,4)\n\t"
      "decl %%edx\n\t"
      "jnz 1b\n\t"
      "call *%%eax\n\t"
      "addl $36, %%esp"
      : "+a"(fn), "+c"(ecxv)
      : [arr] "r"(a)
      : "edx", "memory", "cc");
}
// same with 6 dwords (the last two are a double), caller cleans 24 bytes
static inline void cvcall6(u32 fn, u32 ecxv, const u32 *a) {
  asm volatile(
      "movl $6, %%edx\n\t"
      "1: pushl -4(%[arr],%%edx,4)\n\t"
      "decl %%edx\n\t"
      "jnz 1b\n\t"
      "call *%%eax\n\t"
      "addl $24, %%esp"
      : "+a"(fn), "+c"(ecxv)
      : [arr] "r"(a)
      : "edx", "memory", "cc");
}

// 0x5fc030: thiscall(a, outp) ret 8, /GS protected; returns the text buffer 0x724280 (0 when a - 2 is out of range). Rows of a text list: a = 0 and a = 1 format a header line
// (P = [0x724270] slot 0x14 as a cdecl sprintf: P, buffer, [0x6efbfc], 0, 0, 0x6b931c, 0x6b9324, 0x6b9394, 0x6b932c) with *outp = 0, a = 1 replacing every character of the
// result by '-'. a >= 2 picks item = this[0x18][a - 2] (count this[0x20], unsigned compare) and formats its row: kind = item[0xac] & 0xf, name = kind == 4 ? item[0x16] : 0x677b5a,
// label = table [0x6efbe4 + kind * 4] (for kind 2 the label is "%.1f"-style text of (item_f[0xa] - this[0x24] slot 4()) built in a stack buffer); the row is P slot 0x14(buffer,
// item[0x20] ? [0x6efc00] : [0x6efbfc], item[0xac2], item slot 0x28(), 0x5f49e0(item), label, name, item slot 0x24()).
extern "C" u32 THISCALL fn_5fc030(u8 *self, u32 a, u32 *outp) {
  u8 *buf = (u8 *)0x724280;
  if (a == 0 || a == 1) {
    *outp = 0;
    u8 *P = ext_5fa630();
    u32 args[9] = {(u32)P, 0x724280, G(u32, 0x6efbfc), 0, 0, 0x6b931c, 0x6b9324, 0x6b9394, 0x6b932c};
    cvcall9(*(u32 *)(vt(P) + 0x14), *(u32 *)P, args);
    if (a == 1) {
      u32 len = 0;
      while (buf[len]) len++;
      if (len != 0) {
        u32 k = len;
        do {
          k--;
          buf[k] = 0x2d;
        } while (k != 0);
      }
    }
    ext_633654(G(u32, 0x6f5630));
    return 0x724280;
  }
  u32 idx = a - 2;
  if (idx >= rd32u(self + 0x20)) {
    ext_633654(G(u32, 0x6f5630));
    return 0;
  }
  u8 *item = (u8 *)rd32u((u8 *)rd32u(self + 0x18) + idx * 4);
  *outp = (u32)item;
  u8 dl = item[0xac] & 0xf;
  u32 name = (dl == 4) ? rd32u(item + 0x16) : 0x677b5a;
  u32 kind = (u32)(*(u16 *)(item + 0xac)) & 0xf;
  u32 label = rd32u((u8 *)0x6efbe4 + kind * 4);
  u8 lbuf[0x20];
  if (dl == 2) {
    float f = rdf(item + 0xa);
    u8 *Q = (u8 *)rd32u(self + 0x24);
    double r = (*(VD0 *)(vt(Q) + 4))(Q);
    f = (float)((double)f - r);
    u8 *P = ext_5fa630();
    double d = (double)f;
    u32 lohi[2];
    __builtin_memcpy(lohi, &d, 8);
    u32 args[6] = {(u32)P, (u32)lbuf, 0x6b93a4, 0x6b939c, lohi[0], lohi[1]};
    cvcall6(*(u32 *)(vt(P) + 0x14), *(u32 *)P, args);
    label = (u32)lbuf;
  }
  u32 fmt = (rd32u(item + 0x20) != 0) ? G(u32, 0x6efc00) : G(u32, 0x6efbfc);
  u8 *P = ext_5fa630();
  u32 A = (*(V0 *)(vt(item) + 0x24))(item);
  u32 D = ext_5f49e0(item);
  u32 E = (*(V0 *)(vt(item) + 0x28))(item);
  u32 args9[9] = {(u32)P, 0x724280, fmt, rd32u(item + 0xac2), E, D, label, name, A};
  cvcall9(*(u32 *)(vt(P) + 0x14), (u32)item, args9);
  ext_633654(G(u32, 0x6f5630));
  return 0x724280;
}
PCREG(5fc030, fn_5fc030);
