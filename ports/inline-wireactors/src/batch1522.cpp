#include "ff.h"

// batch1522.cpp - recruits thread, batch 1522: CFormationControl::Save(ZSaveGame*), thiscall, ret 4, returns AL = 1.
// The saver is used through its slot 0x10 (write block: ptr, size) for every field. Layout of the calls (from the
// disassembly, 5b7100..5b7346):
//   count of formations (table +0x48, slot 0x14) as 4 bytes; then per formation f (table iteration, slots 0x4c/0x64):
//     f[0..4), f[0x3c..+4), f[0x64..+0x24), f[0x4c..+0xc), f[0x58..+0xc), f[0x40..+0xc), f[0x0c..+0x30),
//     f[0x88..+4), f[0x8c..+4), f[0x90..+1);
//     member count (f+4, slot 0x14) as 4 bytes; each member e (iteration of f+4): e[0..4), e[4..+4), e[8..+4),
//     e[0xc..+4), e[0x10..+1), e[0x11..+4), e[0x15..+0xc);
//     second count (f+8, slot 0x14) as 4 bytes; each entry e2 of f+8: e2[0..4), e2[4..+0xc), e2[0x10..+0xc),
//     e2[0x20..+4), e2[0x1c..+4).
// The flag 0x40 at +4 is cleared first. A null table returns 1 without writing.

struct RefIter {
  u32 cur, a, b;
};

static void formWrite(void *w, const void *p, u32 n) {
  typedef void(THISCALL * fWrite)(void *, const void *, u32);
  ((fWrite)(*(void ***)w)[0x10 / 4])(w, p, n);
}

static u8 THISCALL formSave(u8 *self, void *w) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  if (!*(void **)(self + 0x48))
    return 1;
  u32 count = vcall<u32>(*(void **)(self + 0x48), 0x14);
  formWrite(w, &count, 4);
  RefIter it;
  vcall<void>(*(void **)(self + 0x48), 0x4c, &it);
  for (u8 *f = vcall<u8 *>(*(void **)(self + 0x48), 0x64, &it); f;
       f = vcall<u8 *>(*(void **)(self + 0x48), 0x64, &it)) {
    formWrite(w, f, 4);
    formWrite(w, f + 0x3c, 4);
    formWrite(w, f + 0x64, 0x24);
    formWrite(w, f + 0x4c, 0xc);
    formWrite(w, f + 0x58, 0xc);
    formWrite(w, f + 0x40, 0xc);
    formWrite(w, f + 0x0c, 0x30);
    formWrite(w, f + 0x88, 4);
    formWrite(w, f + 0x8c, 4);
    formWrite(w, f + 0x90, 1);
    void *mt = *(void **)(f + 4);
    u32 mc = vcall<u32>(mt, 0x14);
    formWrite(w, &mc, 4);
    if (*(void **)(f + 4)) {
      RefIter it2;
      vcall<void>(mt, 0x4c, &it2);
      for (u8 *e = vcall<u8 *>(mt, 0x64, &it2); e; e = vcall<u8 *>(mt, 0x64, &it2)) {
        formWrite(w, e, 4);
        formWrite(w, e + 4, 4);
        formWrite(w, e + 8, 4);
        formWrite(w, e + 0xc, 4);
        formWrite(w, e + 0x10, 1);
        formWrite(w, e + 0x11, 4);
        formWrite(w, e + 0x15, 0xc);
      }
    }
    void *t2 = *(void **)(f + 8);
    u32 c2 = vcall<u32>(t2, 0x14);
    formWrite(w, &c2, 4);
    if (*(void **)(f + 8)) {
      RefIter it3;
      vcall<void>(t2, 0x4c, &it3);
      for (u8 *e = vcall<u8 *>(t2, 0x64, &it3); e; e = vcall<u8 *>(t2, 0x64, &it3)) {
        formWrite(w, e, 4);
        formWrite(w, e + 4, 0xc);
        formWrite(w, e + 0x10, 0xc);
        formWrite(w, e + 0x20, 4);
        formWrite(w, e + 0x1c, 4);
      }
    }
  }
  return 1;
}
PCREG(5b7100, formSave);
