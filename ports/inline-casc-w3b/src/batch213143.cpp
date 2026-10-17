#include "ff.h"

typedef u32(THISCALL *V5)(void *, u32, u32, u32, u32, u32);

extern "C" u8 *STDCALL ext_4d2c00(const char *name);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static u32 slen(const char *s) {
  u32 n = 0;
  while (s[n]) n++;
  return n;
}
// cdecl vcall slot 0x24 of the log object [0x700390] with ecx = the object
static void log3(u32 fmt, u32 a) {
  void *L = G(void *, 0x700390);
  u32 fn = *(u32 *)(*(u8 **)L + 0x24), rc = (u32)L, ra = fn;
  asm volatile("pushl %[a]\n\tpushl %[f]\n\tpushl %[m]\n\tcall *%%eax\n\taddl $12, %%esp"
               : "+a"(ra), "+c"(rc)
               : [a] "r"(a), [f] "r"(fmt), [m] "r"(L)
               : "edx", "memory", "cc");
}
static void log2(u32 fmt) {
  void *L = G(void *, 0x700390);
  u32 fn = *(u32 *)(*(u8 **)L + 0x24), rc = *(u32 *)L, ra = fn;  // this slot is called with ecx = the vtable pointer
  asm volatile("pushl %[f]\n\tpushl %[m]\n\tcall *%%eax\n\taddl $8, %%esp"
               : "+a"(ra), "+c"(rc)
               : [f] "r"(fmt), [m] "r"(L)
               : "edx", "memory", "cc");
}

// 0x4d24e0: thiscall(name, mask, v, cnt) ret 0x10: looks the type record of `name` up (0x4d2c00); logs when its flags [+0x10] lack `mask`; v is passed by address
// when the record kind ([+8]) is 5, otherwise by value; the byte count is cnt, else the record's [+0xc], else derived from the kind (12/14 -> strlen(v)+1, 15/17 -> *(u32*)v,
// others log); then slot 0xac of this gets (name, strlen(name)+1, the kind's row in the 18-entry table at 0x6e7a30 or 0, count, v).
extern "C" u32 THISCALL fn_4d24e0(u8 *self, const char *name, u32 mask, u32 v, u32 cnt);
u32 THISCALL fn_4d24e0(u8 *self, const char *name, u32 mask, u32 v, u32 cnt) {
  u8 *rec = ext_4d2c00(name);
  if ((rd32u(rec + 0x10) & mask) == 0) log3(0x6963cc, (u32)name);
  u32 kind = rd32u(rec + 8);
  u32 p = kind == 5 ? (u32)&v : v;
  u32 len = slen(name) + 1;
  u32 count = cnt;
  if (count == 0) {
    count = rd32u(rec + 0xc);
    if (count == 0) {
      u32 k = kind - 0xc;
      if (k == 0 || k == 2) count = slen((const char *)p) + 1;
      else if (k == 3 || k == 5) count = rd32u((const u8 *)p);
      else if (k > 5 || k == 1 || k == 4) log2(0x696404);
    }
  }
  kind = rd32u(rec + 8);
  u32 row = 0;
  for (u32 i = 0; i < 18; i++)
    if (G(u32, 0x6e7a38 + 0x14 * i) == kind) { row = 0x6e7a30 + 0x14 * i; break; }
  return (*(V5 *)(*(u8 **)self + 0xac))(self, (u32)name, len, row, count, p);
}
PCREG(4d24e0, fn_4d24e0);
