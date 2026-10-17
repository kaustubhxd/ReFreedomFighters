// batch244021.cpp - Sonnet-w4c: hand port of a mesh/ray test (GUESS name; the lifter rejects its ebp operands).
#include "ff.h"

extern "C" void FASTCALL ext_4e0d40(u8 *out, u8 *src, float f);                                  // ecx = out vector, edx = source, float on the stack
extern "C" u32 FASTCALL ext_4dddf0(u32 a2, float *vecs, u8 *v1, u8 *v2, u8 *v3);                  // ecx = a2, edx = vecs, 3 stack args, ret 0xc

// 0x6619d0: stdcall(node offset, mask byte, a2, vecsrc, scale3) ret 0x14, returns al. Builds three vectors from vecsrc (+0x18, +0xc, +0) scaled by 1.0f / scale[k]
// (0x4e0d40), then walks the node chain (offsets relative to the region base [[engine+0x1aa3]+0x20]; next at +8): nodes whose word at +0x2c has a bit of `mask`
// hold a vertex block (+0x14, 36-byte vertices) and an index list (+0x3c: group count, then per group a count n and n word indices forming a strip of n-2 triangles);
// each triangle is tested with 0x4dddf0(a2, vecs, v1, v2, v3); the first hit returns true.
static u32 STDCALL fn6619d0(u32 node, u32 mask, u32 a2, u8 *vecsrc, float *scale) {
  float L[9];                                   // local28, local1c, local10 (contiguous like the original frame)
  float one = G(float, 0x678858);
  ext_4e0d40((u8 *)&L[6], vecsrc + 0x18, one / scale[0]);
  ext_4e0d40((u8 *)&L[3], vecsrc + 0xc, one / scale[1]);
  ext_4e0d40((u8 *)&L[0], vecsrc, one / scale[2]);
  u8 *base = *(u8 **)(*(u8 **)(*(u8 **)0x70039c + 0x1aa3) + 0x20);
  u32 flag = mask & 0xff;
  u32 ebx = node;
  while (ebx) {
    u8 *nd = (u8 *)((u32)base + ebx);
    u32 nxt = *(u32 *)(nd + 8);
    if (*(u32 *)(nd + 0x2c) & flag) {
      u8 *vb = (u8 *)(*(u32 *)(nd + 0x14) + (u32)base);
      u8 *ecx = (u8 *)(*(u32 *)(nd + 0x3c) + (u32)base);
      u32 cnt = *(u16 *)ecx;
      ecx += 2;
      u32 g = 0;
      if (cnt) {
        do {
          u32 n = *(u16 *)ecx;
          ecx += 2;
          u32 last = n - 2;
          if (last != 0) {
            u32 s = 0;
            do {
              u8 *edi = ecx + 2;
              u8 *v3 = vb + (u32)*(u16 *)(ecx + 4) * 36;
              u8 *v2 = vb + (u32)*(u16 *)edi * 36;
              u8 *v1 = vb + (u32)*(u16 *)ecx * 36;
              if ((u8)ext_4dddf0(a2, &L[0], v1, v2, v3)) return 1;
              s++;
              ecx = edi;
            } while (s < last);
          }
          g++;
          ecx += 4;
        } while (g < cnt);
      }
    }
    ebx = nxt;
  }
  return 0;
}
PCREG(6619d0, fn6619d0);

// ---- 0x661000 hand port (SEH, 64-bit sbb/adc, rep movsd zero fill). GUESS name.
#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)
extern "C" u32 ext_41e290_c1(...) __asm__("ext_41e290");
extern "C" u32 THISCALL ext_4cca60(u32 self, u32 a, u32 b) __asm__("ext_4cca60");   // thiscall ret 8
typedef u32(THISCALL *w4c_t1)(void *, u32);
typedef u32(THISCALL *w4c_t2)(void *, u32, u32);
typedef u64(THISCALL *w4c_t64)(void *, u32, u32);

// 0x661000: profiler record lookup/insert. Already reported ([this+0x20]) returns. Lazily creates the list object [this+0x18] (0x28 bytes, ctor 0x4cca60(8, 0x7a)). Iterates the list (slot 0x4c(&it), slot 0x64(&it))
// for a record with [rec+0x1cc] == [this+0x10] and the name (strncmp(rec+0x1b8, name, 0x13)) equal; otherwise a new record (slot 0x94/0x8c with the parent, or slot 4(0)) is cleared (0x1b8 bytes)
// and named (strncpy). Then stores (lo, hi) at rec+0x10/+0x14, links it as current ([this+0x10] = rec, [this+0x1c]++, byte 0x1d4 = 1 when the parent changed) and adds
// engine time (slot 0x1c8(0x6c4928, 0x64)) minus (lo, hi) as a 64-bit value to rec+0x18.
static void THISCALL fn661000(u8 *self, u32 lo, u32 hi, const char *name) {
  SEH_ENTER(0x66ee5f);
  if (self[0x20]) { SEH_LEAVE(); return; }
  if (*(u32 *)(self + 0x18) == 0) {
    u32 obj = ext_41e290_c1(0x28);
    reg.state = 0;
    if (obj) obj = ext_4cca60(obj, 8, 0x7a);
    reg.state = -1;
    *(u32 *)(self + 0x18) = obj;
  }
  u8 *rec = 0;
  bool found = false;
  void *lst = *(void **)(self + 0x18);
  if (lst) {
    u32 it[3];
    (*(w4c_t1 **)lst)[0x4c / 4](lst, (u32)it);
    lst = *(void **)(self + 0x18);
    u8 *p = (u8 *)(*(w4c_t1 **)lst)[0x64 / 4](lst, (u32)it);
    while (p) {
      rec = p + 8;
      if (*(u32 *)(rec + 0x1cc) != *(u32 *)(self + 0x10) ||
          ((u32(*)(const char *, const char *, u32))G(u32, 0x676410))((const char *)(rec + 0x1b8), name, 0x13) != 0) {
        lst = *(void **)(self + 0x18);
        p = (u8 *)(*(w4c_t1 **)lst)[0x64 / 4](lst, (u32)it);
        continue;
      }
      found = true;
      break;
    }
  }
  if (!found) {
    u32 parent = *(u32 *)(self + 0x10);
    u32 b = 0;
    bool have = false;
    if (parent) {
      void *l2 = *(void **)(self + 0x18);
      u32 q = (*(w4c_t1 **)l2)[0x94 / 4](l2, parent - 8);
      if (q) {
        void *l3 = *(void **)(self + 0x18);
        b = (*(w4c_t2 **)l3)[0x8c / 4](l3, q, 0) + 4;
        have = (b != 0);
      }
    }
    if (!have) {
      void *l4 = *(void **)(self + 0x18);
      b = (*(w4c_t1 **)l4)[4 / 4](l4, 0) + 4;
    }
    rec = (u8 *)b;
    *(u32 *)(rec) = 0;
    *(u32 *)(rec + 4) = 0;
    *(u32 *)(rec + 8) = 0;
    *(u32 *)(rec + 0xc) = 0;
    *(u32 *)(rec + 0x18) = 0;
    *(u32 *)(rec + 0x1c) = 0;
    *(u32 *)(rec + 0x20) = 0;
    *(u32 *)(rec + 0x24) = 0;
    for (u32 o = 0x28; o < 0x1b8; o += 4) *(u32 *)(rec + o) = 0;
    *(u32 *)(rec + 0x1d0) = *(u32 *)(self + 0x1c);
    *(u32 *)(rec + 0x1cc) = *(u32 *)(self + 0x10);
    rec[0x1d4] = 0;
    *(u32 *)(rec + 0x1d5) = 0;
    *(u32 *)(rec + 0x1d9) = 0;
    ((u32(*)(u8 *, const char *, u32))G(u32, 0x67642c))(rec + 0x1b8, name, 0x13);
    rec[0x1cb] = 0;
  }
  *(u32 *)(rec + 0x14) = hi;
  *(u32 *)(rec + 0x10) = lo;
  if (*(u32 *)(rec + 0x1cc) != *(u32 *)(self + 0x10)) {
    rec[0x1d4] = 1;
    *(u32 *)(rec + 0x1cc) = *(u32 *)(self + 0x10);
  }
  (*(u32 *)(self + 0x1c))++;
  *(u32 *)(self + 0x10) = (u32)rec;
  u8 *eng = *(u8 **)0x70039c;
  u64 now = (*(w4c_t64 **)eng)[0x1c8 / 4](eng, 0x6c4928, 0x64);
  u64 d = now - (((u64)hi << 32) | lo);
  *(u64 *)(rec + 0x18) += d;
  SEH_LEAVE();
}
PCREG(661000, fn661000);
