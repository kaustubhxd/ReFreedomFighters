// batch6351.cpp - unclaimed-63 gap-band batch 51: 0x4d3b30 (C-set; no GC name), thiscall, three stack arguments s, o, c, ret 0xc.
//   n = o->vtbl[+0x14]() (thiscall, no arguments). buf = alloca(16n + 16); buf[0] = 4n + 4.
//   o->vtbl[+0x4c](&L); item = o->vtbl[+0x5c](&L); while L != 0: buf[k++] = item; item = o->vtbl[+0x5c](&L). (k starts at 1.)
//   rec = the 20-byte record of the table at 0x6e7a30 (18 records, type dword at +8) whose type equals c (0 if none).
//   If (rec[+0x10] & 4) == 0: logger 0x700390 slot +0x24 (cdecl): (log, 0x6963cc, s).
//   chosen = rec[+8] != 5 ? buf : &saved (the stack slot holding buf). L1 = strlen(s) + 1.
//   val = rec[+0xc]; if val == 0: switch (rec[+8] - 0xc): 0 and 2 -> strlen(chosen) + 1; 3 and 5 -> *(u32 *)chosen;
//     1, 4 and the default -> logger slot +0x24 (cdecl): (log, 0x696404).
//   rec2 = the record whose type equals rec[+8] (the same search); this->vtbl[+0xac](s, L1, rec2, val, chosen) (caller cleans 20).
//   The 0x633654 stack cookie check at the end of the original is not reproduced (tagged).
#include "ff.h"

typedef u32(THISCALL * q0_fn)(void *);
typedef u32(THISCALL * q1_fn)(void *, u32 *);
typedef u32(*cdecl_log3_fn)(u32, u32, u32);
typedef u32(*cdecl_log2_fn)(u32, u32);

static u32 search_type(u32 value) {
  for (u32 k = 0; k < 18; k++) {
    u32 rec = 0x6e7a30u + 20u * k;
    if (*(u32 *)(rec + 8) == value)
      return rec;
  }
  return 0;
}

// 0x4d3b30 (C-set).
static void THISCALL unnamed4d3b30(u8 *self, u32 s, u8 *o, u32 c) {
  u32 n = ((q0_fn)(*(u32 *)(*(u32 *)o + 0x14)))((void *)o);
  u32 size = 16u * n + 16u;
  u32 *buf = (u32 *)__builtin_alloca(size);
  buf[0] = 4u * n + 4u;
  u32 L = 0;
  ((q1_fn)(*(u32 *)(*(u32 *)o + 0x4c)))((void *)o, &L);
  u32 item = ((q1_fn)(*(u32 *)(*(u32 *)o + 0x5c)))((void *)o, &L);
  u32 k = 1;
  while (L != 0) {
    buf[k++] = item;
    item = ((q1_fn)(*(u32 *)(*(u32 *)o + 0x5c)))((void *)o, &L);
  }
  u32 rec = search_type(c);
  u32 lg = G(u32, 0x700390);
  if ((*(u8 *)(rec + 0x10) & 4u) == 0)
    ((cdecl_log3_fn)(*(u32 *)(*(u32 *)lg + 0x24)))(lg, 0x6963ccu, s);
  u32 saved = (u32)buf;
  u32 chosen = (*(u32 *)(rec + 8) != 5u) ? (u32)buf : (u32)&saved;
  u32 L1 = 0;
  {
    const u8 *p = (const u8 *)s;
    u32 len = 0;
    while (p[len] != 0)
      len++;
    L1 = len + 1;
  }
  u32 val = *(u32 *)(rec + 0xc);
  if (val == 0) {
    u32 ix = *(u32 *)(rec + 8) - 0xcu;
    if (ix <= 5u && (ix == 0 || ix == 2)) {
      const u8 *p = (const u8 *)chosen;
      u32 len = 0;
      while (p[len] != 0)
        len++;
      val = len + 1;
    } else if (ix <= 5u && (ix == 3 || ix == 5)) {
      val = *(u32 *)chosen;
    } else {
      ((cdecl_log2_fn)(*(u32 *)(*(u32 *)lg + 0x24)))(lg, 0x696404u);
    }
  }
  u32 rec2 = search_type(*(u32 *)(rec + 8));
  u32 fn = *(u32 *)(*(u32 *)self + 0xac);
  asm volatile("push %[a4]\n\tpush %[a3]\n\tpush %[a2]\n\tpush %[a1]\n\tpush %[a0]\n\tcall *%[fn]\n\tadd $20, %%esp"
               : "+c"(self)
               : [a4] "rm"(chosen), [a3] "rm"(val), [a2] "rm"(rec2), [a1] "rm"(L1), [a0] "rm"(s), [fn] "rm"(fn)
               : "eax", "edx", "memory", "cc");
}
PCREG(4d3b30, unnamed4d3b30);
