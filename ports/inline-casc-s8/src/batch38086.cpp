// batch38086.cpp - cascade s8 batch 38086: 0x64c4b0 (collect the linked chains of every visible entry of a container into a list).
#include "ff.h"

extern "C" void THISCALL ext_64ea30(u8 *self, u32 v);                  // ret 4
extern "C" u32 THISCALL ext_658d30(u8 *obj);                           // plain ret
extern "C" u32 THISCALL ext_658e00(u8 *obj, u32 *arr, u32 n);          // ret 8
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u8(THISCALL *b2_t)(void *, u32, u32);
typedef u32 (*hook_t)();
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define SYS G(u8 *, 0x70039c)
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword
#define U(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void assert_hook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}
static void append(u32 *list, u32 v) {
  if (!(list[0] + 1 <= 0x2000)) assert_hook();
  list[1 + list[0]] = v;
  list[0]++;
}
static void chain(u32 *list, u8 *p) {
  while (p) {
    append(list, (u32)p);
    p = (u8 *)U(p, 0x1c);
  }
}
static u32 flags_of(u8 *n) { return n ? UN32(*(u8 **)(n + 0xc), 0x23) : 0x200002; }   // descriptor flags of a node (default without one)
// 0x43e920: register convention (ecx = out, edx = a, stack b, ret 4): out = a - b (3 floats)
static void vsub(u8 *out, u8 *a, u8 *b) {
  __asm__ volatile("pushl %[b]\n\tcall *%[f]" : : "c"(out), "d"(a), [b] "r"(b), [f] "r"(0x43e920) : "eax", "memory", "cc");
}
// 0x441a60: register convention (ecx = vector, edx = matrix): vector = vector * matrix
static void vmul(u8 *v, u8 *m) {
  __asm__ volatile("call *%[f]" : : "c"(v), "d"(m), [f] "r"(0x441a60) : "eax", "memory", "cc");
}

// Everything the original pushes for 0x658d30 (a plain-ret function) stays on its stack: every iteration that takes the "A slot 0x50" path leaks one dword (the value B), so the three final pops
// of the epilogue load ebx/edi/esi from the most recent leaks first, then the saved registers. out[0..2] receive the final ebx, edi, esi.
extern "C" u32 ff_inner_64c4b0(u8 *self, u32 *list, u32 ebx_s, u32 edi_s, u32 esi_s, u32 *out) {
  u8 *cont = self + 0x10199;
  u32 it[3];
  SLOT(cont, 0xc, v1_t)(cont, (u32)it);
  u32 last54 = 0;
  u32 L = 0, lk[3] = {0, 0, 0};
  bool pushed_ebx = it[0] != 0;
  while (it[0]) {
    u8 *ent = *(u8 **)it[0];
    if (!(ent[5] & 1)) {
      SLOT(cont, 0x10, v1_t)(cont, (u32)it);
      continue;
    }
    u8 type = ent[0x14];
    u8 *obj = (u8 *)U(ent, 8);
    u8 *F = *(u8 **)(*(u8 **)(obj + 0x38) + 0x54);
    u8 f71 = F[0x71];
    if (!(type > 1 && f71 == 0)) {
      u8 *A = (u8 *)SLOT(F, 0x24c, v0_t)(F);
      u32 g6c = U(*(u8 **)(F + 8), 0x6c);
      u8 *X = *(u8 **)(UN32(SYS, 0x1aa3) + 0x18);
      u32 B = SLOT(X, 0xc4, v1_t)(X, g6c);
      u32 p20 = U(ent, 0x20);
      if (last54 != p20) {
        last54 = p20;
        ext_64ea30(self, U(*(u8 **)(p20 + 0xc), 0xc));
      }
      u8 loc10[16];
      vsub(loc10, self + 0x1821d, obj + 0x2c);
      vmul(loc10, obj + 8);
      bool cont_on = true;
      if (f71 == 0) {
        u32 r = ext_658d30(obj);
        L++;
        lk[2] = lk[1];
        lk[1] = lk[0];
        lk[0] = B;
        u8 al = SLOT(A, 0x50, b2_t)(A, (u32)loc10, r);
        if (!al) cont_on = false;
      }
      if (cont_on) {
        chain(list, (u8 *)U(ent, 0x1c));
        u32 arr[8];
        u32 n = ext_658e00(obj, arr, 8);
        if (n != 0) {
          u32 k = 0;
          do {
            u8 *nb = *(u8 **)((u8 *)arr[k] + 0x54);
            if (flags_of(nb) & 0x100000) {
              u8 *q = (u8 *)U(nb, 8);
              if (q) {
                do {
                  u32 w = *(u16 *)(q + 0x5a);
                  if (w) {
                    if (flags_of(*(u8 **)(q + 0x54)) & 0x200000) {
                      u8 *e2 = ((u8 **)U(self, 0x10071))[w & 0xfff];
                      chain(list, (u8 *)U(e2, 0x1c));
                    }
                  }
                  SLOT(nb, 0x50, v1_t)(nb, (u32)&q);
                } while (q != 0);
              }
            }
            k++;
          } while (k != n);
        }
      }
    }
    // advance the segmented iterator
    u32 idx = ++it[1];
    u8 *node = (u8 *)it[2];
    if (idx == U(node, 0)) {
      node = (u8 *)U(node, 8);
      it[2] = (u32)node;
      if (!node) break;
      it[1] = 0;
      it[0] = (u32)(node + 0x10);
    } else {
      it[0] += 4;
    }
  }
  if (pushed_ebx) {
    u32 st[6], m = 0;
    for (u32 i = 0; i < L && i < 3; i++) st[m++] = lk[i];
    st[m++] = ebx_s;
    st[m++] = edi_s;
    st[m++] = esi_s;
    out[0] = st[0];
    out[1] = st[1];
    out[2] = st[2];
  } else {
    out[0] = ebx_s;
    out[1] = edi_s;
    out[2] = esi_s;
  }
  return 0;
}
// naked wrapper: thiscall(list) ret 4; reproduces the register state the original returns in (see above)
__attribute__((naked)) static void THISCALL fn64c4b0(u8 *self, u32 *list) {
  asm volatile(
      "push %ebp\n"
      "mov %esp, %ebp\n"
      "push %ebx\n"
      "push %esi\n"
      "push %edi\n"
      "sub $12, %esp\n"
      "lea -24(%ebp), %eax\n"
      "push %eax\n"
      "push -8(%ebp)\n"
      "push -12(%ebp)\n"
      "push -4(%ebp)\n"
      "push 8(%ebp)\n"
      "push %ecx\n"
      "call ff_inner_64c4b0\n"
      "add $24, %esp\n"
      "mov -24(%ebp), %ebx\n"
      "mov -20(%ebp), %edi\n"
      "mov -16(%ebp), %esi\n"
      "mov %ebp, %esp\n"
      "pop %ebp\n"
      "ret $4\n");
}
PCREG(64c4b0, fn64c4b0);
