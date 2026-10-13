// batch799.cpp - unclaimed-77 batch 799, claims 44 to 48 (docs/20-unclaimed-77.md), residue 4 rows.
// 5 functions: 0x41f680, 0x41f7c0, 0x41fa40, 0x427d80, 0x43f5c0
#include "ff.h"

// 0x41f680, ZSysMemGC::FlushCache(): ecx = dword[self+0x31] (unaligned), then jmp 0x4d0690, which is `lea eax,[ecx+0x217]; ret`.
static u32 THISCALL zsysMemFlushCache(u8 *self) {
  return *(u32 *)(self + 0x31) + 0x217;
}
PCREG(41f680, zsysMemFlushCache);

extern "C" u32 THISCALL ext_41ee20(void *self, u32 a);  // stubbed (GUESS): thiscall, one stack arg, returns a value

// 0x41f7c0, ZSysMem::ExgRefs(x) (the real signature is one stack argument, ret 4): vtbl[0xec](this); r = 0x41ee20(this, x);
// vtbl[0xe8](this); return r.
static u32 THISCALL zsysMemExgRefs(u8 *self, u32 x) {
  void **vt = *(void ***)self;
  ((void (THISCALL *)(void *))(*(void **)((u8 *)vt + 0xec)))(self);
  u32 r = ext_41ee20(self, x);
  vt = *(void ***)self;
  ((void (THISCALL *)(void *))(*(void **)((u8 *)vt + 0xe8)))(self);
  return r;
}
PCREG(41f7c0, zsysMemExgRefs);

extern "C" void THISCALL ext_41f190(void *self, void *p);  // stubbed (GUESS): thiscall, one stack arg (ret 4)

// 0x41fa40, ZSysMemGC::SubLink(p) (ret 4, returns bool in al):
//   if (E = [0x70038c]; E->vtbl[0x20](E, p)) return false;
//   lim = dword[dword[g_pSysInterface + 0x9b] + 0x1c5d] (when the first is nonzero); if (p >= lim && lim && p < lim + (dword[lim-8] & 0x1fffffff))
//     call the hook [0x7003b0] (zero would hit an int3 in the exe: excluded, spec keeps it nonzero).
//   --dword[p-0xc]; 0x41f190(this, p); r = dword[p-0xc]; if (r == 0) return true;
//   if (r < 0) with ecx = db->vtbl (as the exe does): db->vtbl[0x34](db, 0x677524) cdecl, db = [0x700390]; return false.
static bool THISCALL zsysMemSubLink(u8 *self, u8 *p) {
  u8 *e = G(u8 *, 0x70038c);
  void **evt = *(void ***)e;
  if (((u32(THISCALL *)(void *, u8 *))(*(void **)((u8 *)evt + 0x20)))(e, p)) return false;
  u8 *rec = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  if (rec) {
    u8 *lim = *(u8 **)(rec + 0x1c5d);
    if (p >= lim && lim && p < lim + (*(u32 *)(lim - 8) & 0x1fffffffu)) {
      ((void (*)())G(void *, 0x7003b0))();
    }
  }
  (*(int *)(p - 0xc))--;
  ext_41f190(self, p);
  int r = *(int *)(p - 0xc);
  if (r == 0) return true;
  if (r < 0) {
    u8 *db = G(u8 *, 0x700390);
    void **vt = *(void ***)db;
    void *fn = *(void **)((u8 *)vt + 0x34);
    __asm__ volatile("pushl %[s]\n\tpushl %[o]\n\tcall *%[f]\n\taddl $8, %%esp"
                     : "+c"(vt)
                     : [s] "i"(0x677524), [o] "r"(db), [f] "r"(fn)
                     : "eax", "edx", "memory", "cc");
  }
  return false;
}
PCREG(41fa40, zsysMemSubLink);

// 0x427d80, ZMovementAnimation::WantControl(3 pointers): `xor al,al; ret 0xc`: always false.
static bool THISCALL moveAnimWantControl(u8 *self, const float *a1, const float *a2, const float *a3) {
  (void)self; (void)a1; (void)a2; (void)a3;
  return false;
}
PCREG(427d80, moveAnimWantControl);

extern "C" void THISCALL ext_4da1d0(void *node, u32 a);  // stubbed (GUESS): thiscall, one stack arg (ret 4)

// 0x43f5c0, ZGROUP::CalcCenSizeRecur(): for each node n of the list at this+0x50 (next at n+0x60): o = dword[n+0x54];
// flags = o ? dword[dword[o+0xc]+0x23] : 0x200002; if flags & 0x100000 then o->vtbl[0x2b8](o) else 0x4da1d0(n, 0).
// Then tail-jumps to this->vtbl[0](this) (result returned).
static u32 THISCALL zgroupCalcCenSizeRecur(u8 *self) {
  for (u8 *n = *(u8 **)(self + 0x50); n; n = *(u8 **)(n + 0x60)) {
    u8 *o = *(u8 **)(n + 0x54);
    u32 fl = o ? *(u32 *)(*(u8 **)(o + 0xc) + 0x23) : 0x200002u;
    if (fl & 0x100000u) {
      void **vt = *(void ***)o;
      ((void (THISCALL *)(void *))(*(void **)((u8 *)vt + 0x2b8)))(o);
    } else {
      ext_4da1d0(n, 0);
    }
  }
  void **vt = *(void ***)self;
  return ((u32 (THISCALL *)(void *))(vt[0]))(self);
}
PCREG(43f5c0, zgroupCalcCenSizeRecur);
