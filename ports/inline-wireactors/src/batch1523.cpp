// batch1523.cpp - recruits thread, batch 1523: CFormationControl::Load(ZLoadGame*), thiscall, ret 4, AL = 1.
// Mirror of Save (batch 1522): the reader's slot 0x18 (read block: ptr, size). The key read before each record is the
// formation (or member, or second-table entry) id; the record it selects is the table's slot-4 result, which is the
// save-side address + 4 (the reads use record + offsets that are 4 more than the save's offsets, consistently).
#include "ff.h"

extern "C" void THISCALL ext_5b6d00(u8 *self);               // CFormationControl::InitWrapper (batch 1513)
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 size); // operator new
extern "C" u32 *THISCALL ext_4ccbe0(void *t, s32 a, s32 b);   // REFTAB::REFTAB(int, int)

struct RefIter2 {
  u32 cur, a, b;
};

static void formRead(void *lg, void *p, u32 n) {
  typedef void(THISCALL * fRead)(void *, void *, u32);
  ((fRead)(*(void ***)lg)[0x18 / 4])(lg, p, n);
}

static u8 THISCALL formLoad(u8 *self, void *lg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ext_5b6d00(self);
  u32 nf;
  formRead(lg, &nf, 4);
  for (u32 i = 0; i < nf; ++i) {
    u32 key;
    formRead(lg, &key, 4);
    u8 *f = vcall<u8 *>(*(void **)(self + 0x48), 4, key);   // table slot 4: the record for the key
    void *t1 = ext_41e290(0x1c);
    *(u32 **)f = t1 ? ext_4ccbe0(t1, 0xc, 0x1d) : 0;
    void *t2 = ext_41e290(0x1c);
    *(u32 **)(f + 4) = t2 ? ext_4ccbe0(t2, 0xc, 0x20) : 0;
    formRead(lg, f + 0x38, 4);
    formRead(lg, f + 0x60, 0x24);
    formRead(lg, f + 0x48, 0xc);
    formRead(lg, f + 0x54, 0xc);
    formRead(lg, f + 0x3c, 0xc);
    formRead(lg, f + 8, 0x30);
    formRead(lg, f + 0x84, 4);
    formRead(lg, f + 0x88, 4);
    formRead(lg, f + 0x8c, 1);
    u32 m;
    formRead(lg, &m, 4);
    for (u32 j = 0; j < m; ++j) {
      u32 ekey;
      formRead(lg, &ekey, 4);
      u8 *e = vcall<u8 *>(*(void **)f, 4, ekey);
      formRead(lg, e, 4);
      formRead(lg, e + 4, 4);
      formRead(lg, e + 8, 4);
      formRead(lg, e + 0xc, 1);
      formRead(lg, e + 0xd, 4);
      formRead(lg, e + 0x11, 0xc);
    }
    u32 m2;
    formRead(lg, &m2, 4);
    for (u32 j = 0; j < m2; ++j) {
      u32 ekey;
      formRead(lg, &ekey, 4);
      u8 *e = vcall<u8 *>(*(void **)(f + 4), 4, ekey);
      formRead(lg, e, 0xc);
      formRead(lg, e + 0xc, 0xc);
      formRead(lg, e + 0x1c, 4);
      formRead(lg, e + 0x18, 4);
    }
  }
  return 1;
}
PCREG(5b6e20, formLoad);
