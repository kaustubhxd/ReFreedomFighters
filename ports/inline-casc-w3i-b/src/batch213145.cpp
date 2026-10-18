#include "ff.h"

typedef void (*Hook)();

extern "C" u32 THISCALL ext_48aad0(void *pair);
extern "C" u8 *THISCALL ext_566fa0(void *ent);
extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

// cdecl vcall of slot `off` of O's vtable with ecx = the vtable pointer (not the object)
static void vt_cdecl4(void *O, u32 off, u32 a, u32 b, u32 c) {
  u32 vtp = *(u32 *)O, fn = *(u32 *)(vtp + off), rc = vtp, ra = fn;
  asm volatile("pushl %[c]\n\tpushl %[b]\n\tpushl %[a]\n\tpushl %[o]\n\tcall *%%eax\n\taddl $16, %%esp"
               : "+a"(ra), "+c"(rc)
               : [a] "r"(a), [b] "r"(b), [c] "r"(c), [o] "r"(O)
               : "edx", "memory", "cc");
}
static void vt_cdecl2(void *O, u32 off, u32 a) {
  u32 vtp = *(u32 *)O, fn = *(u32 *)(vtp + off), rc = vtp, ra = fn;
  asm volatile("pushl %[a]\n\tpushl %[o]\n\tcall *%%eax\n\taddl $8, %%esp"
               : "+a"(ra), "+c"(rc)
               : [a] "r"(a), [o] "r"(O)
               : "edx", "memory", "cc");
}

// 0x5672c0: thiscall(a) ret 4, /GS. Unless the engine's slot 0xbc() object says (slot 0xb0) it is busy: formats this[0x188] into a 0x84-byte buffer through slot 0x198 of
// the object returned by engine slot 0x190, hands (buffer, a, 2) to table slot 0x134()->0x5c, then by this[0x188] (0..3) names an entity through the table
// ([engine+0x9b] slot 0x138 plus a string pair, resolved by 0x48aad0, then table slot 0x58) and, when found, stores 1 / 0 / 2 into [0x566fa0(entity)+0xe1c] for a = 0 / 1 / 2
// (any other a logs through [0x700390] slots 0x20 and 0x2c); this[0x188] > 3 calls the assert hook [0x7003b0] (int3 when null).
extern "C" void THISCALL fn_5672c0(u8 *self, u32 a);
static void THISCALL body_5672c0(u8 *self, u32 a) {
  u8 buf[0x84];
  u8 *E = G(u8 *, 0x70039c);
  void *X = vcall<void *>(E, 0xbc);
  if ((u8)vcall<u32>(X, 0xb0)) return;
  void *Y = vcall<void *>(E, 0x190);
  vt_cdecl4(Y, 0x198, (u32)buf, 0x6a7058, rd32u(self + 0x188));
  void *T = (void *)rd32u(E + 0x9b);
  void *Q = vcall<void *>(T, 0x134);
  vcall<void>(Q, 0x5c, (u32)buf, a, 2);
  u32 k = rd32u(self + 0x188);
  if (k > 3) {
    Hook h = G(Hook, 0x7003b0);
    if (!h) __builtin_trap();
    h();
    return;
  }
  static const u32 strs[4] = {0x681320, 0x68fcbc, 0x68fccc, 0x68fcdc};
  T = (void *)rd32u(E + 0x9b);
  u32 pair[2];
  pair[0] = vcall<u32>(T, 0x138);
  pair[1] = strs[k];
  u32 id = ext_48aad0(pair);
  T = (void *)rd32u(E + 0x9b);
  u8 *ent = vcall<u8 *>(T, 0x58, id);
  if (!ent) return;
  if (a == 0) {
    *(u32 *)(ext_566fa0(ent) + 0xe1c) = 1;
  } else if (a == 1) {
    *(u32 *)(ext_566fa0(ent) + 0xe1c) = 0;
  } else if (a == 2) {
    *(u32 *)(ext_566fa0(ent) + 0xe1c) = 2;
  } else {
    void *L = G(void *, 0x700390);
    void *M = vcall<void *>(L, 0x20, 0x6a6fd0, 0x12f);
    vt_cdecl2(M, 0x2c, 0x6a706c);
  }
}
extern "C" void THISCALL fn_5672c0(u8 *self, u32 a) {
  body_5672c0(self, a);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(5672c0, fn_5672c0);
