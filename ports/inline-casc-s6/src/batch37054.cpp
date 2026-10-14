// batch37054.cpp - cascade s6 batch 37054: 0x64b170.
#include "ff.h"

extern "C" void THISCALL ext_64d490(u8 *self, u8 *rec);   // ret 4
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
#define F32(o) (*(u32 *)(self + (o)))

static inline void *obj32(u8 *self, u32 off) { return *(void **)(self + off); }
#define PTR(o, off) (*(void **)((u8 *)(o) + (off)))
#define FREE(pool, p) ((*(v1_t **)(pool))[0xc / 4]((pool), (u32)(p)))
#define ALLOC(pool) ((u8 *)(*(v0_t **)(pool))[2]((pool)))

// 0x64b170, thiscall(prio, flag) ret 8, returns the new record or 0: creates a handle record. Takes a handle (ebx) from the pool at [this+0x1005d]+0x224 and a record (edi) from
// the pool at this+0x1015d; the record's +0xc comes from the pool at [this+0x1005d]+0x234. The owner at this+0x1005d accepts the handle through slot 0xa8(handle, prio + the engine's
// offset [[engine+0x1aa3]+0x20], [this+0x1007d]+8); on failure everything is returned to its pools (slot 0xac for the handle). On success the record gets +0x14 = [this+0x1007d],
// bit 4 of +5 when flag is set, +8 = handle; this slot 0x54(rec) must accept it (else slot 0x58, return all and 0), then 0x64d490 and slot 2 of the object embedded at
// this+0x101ad get the record.
static u8 *THISCALL fn64b170(u8 *self, u32 prio, u32 flagw) {
  u8 flag = (u8)flagw;
  prio += *(u32 *)(*(u8 **)(*(u8 **)0x70039c + 0x1aa3) + 0x20);
  void *a = PTR(obj32(self, 0x1005d), 0x224);
  u8 *h = ALLOC(a);
  if (!h) return 0;
  void *q = obj32(self, 0x1015d);
  u8 *rec = ALLOC(q);
  if (rec) {
    void *b = PTR(obj32(self, 0x1005d), 0x234);
    u32 x = (u32)ALLOC(b);
    *(u32 *)(rec + 0xc) = x;
    if (!x) {
      FREE(obj32(self, 0x1015d), rec);
      void *a2 = PTR(obj32(self, 0x1005d), 0x224);
      FREE(a2, h);
      return 0;
    }
    void *own = obj32(self, 0x1005d);
    u8 *r = *(u8 **)(self + 0x1007d);
    if (!(u8)(*(v3_t **)own)[0xa8 / 4](own, (u32)h, prio, *(u32 *)(r + 8))) {
      void *b2 = PTR(obj32(self, 0x1005d), 0x234);
      FREE(b2, *(u32 *)(rec + 0xc));
      FREE(obj32(self, 0x1015d), rec);
      void *own2 = obj32(self, 0x1005d);
      (*(v1_t **)own2)[0xac / 4](own2, (u32)h);
      void *a3 = PTR(obj32(self, 0x1005d), 0x224);
      FREE(a3, h);
      return 0;
    }
    *(u32 *)(rec + 0x14) = F32(0x1007d);
    if (flag) rec[5] |= 4;
    *(u32 *)(rec + 8) = (u32)h;
    if (!(u8)(*(v1_t **)self)[0x54 / 4](self, (u32)rec)) {
      (*(v1_t **)self)[0x58 / 4](self, (u32)rec);
      FREE(obj32(self, 0x1015d), rec);
      void *own3 = obj32(self, 0x1005d);
      (*(v1_t **)own3)[0xac / 4](own3, (u32)h);
      void *a4 = PTR(obj32(self, 0x1005d), 0x224);
      FREE(a4, h);
      return 0;
    }
    ext_64d490(self, rec);
    void *emb = self + 0x101ad;
    u32 var = (u32)rec;
    (*(v1_t **)emb)[2]((emb), (u32)&var);
    return rec;
  }
  void *a5 = PTR(obj32(self, 0x1005d), 0x224);
  FREE(a5, h);
  return 0;
}
PCREG(64b170, fn64b170);
