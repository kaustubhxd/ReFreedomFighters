// batch1510.cpp - recruits thread, batch 1510: CFormationControl::FrameUpdate and SendUpdates.
#include "ff.h"

static inline void *objTable() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
#define SYS G(u8 *, 0x70039c)

typedef u64(THISCALL *fStamp)(void *, const char *, u32);
typedef void(THISCALL *fMark)(void *, u32, u32, const char *);
static void prof(u32 slot, u32 line, u32 name) {
  if (!(*(float *)(SYS + 0x9c7) != 0.0f && *(float *)(SYS + 0x9c3) != 0.0f))
    return;
  u8 *s = SYS;
  u64 t = ((fStamp)(*(void ***)s)[0x1c8 / 4])(s, (const char *)0x67a7f8, line);
  u8 *s2 = SYS;
  ((fMark)(*(void ***)s2)[slot / 4])(s2, (u32)t, (u32)(t >> 32), (const char *)name);
}

struct RefIter {
  u32 cur, a, b;
};

// 0x5b7420 CFormationControl::SendUpdates(), thiscall, plain ret. Each formation (at most 1,000,000 per call) with a
// pending event queue (+8) sends its oldest event: the queue entry is {member id, event data...}; the member gets
// event +0x4c with the entry's data (+4), and the entry is removed. Profiling marker "SendUpdates" (0x6b22d0).
static void THISCALL formSendUpdates(u8 *self) {
  s32 budget = 1000000;
  prof(0x178, 0x259, 0x6b22d0);
  if (*(void **)(self + 0x48)) {
    RefIter it;
    vcall<void>(*(void **)(self + 0x48), 0x4c, &it);
    for (u8 *f = vcall<u8 *>(*(void **)(self + 0x48), 0x64, &it); f; f = vcall<u8 *>(*(void **)(self + 0x48), 0x64, &it)) {
      if (*(void **)(f + 8)) {
        RefIter q;
        vcall<void>(*(void **)(f + 8), 0x4c, &q);
        u32 *ev = vcall<u32 *>(*(void **)(f + 8), 0x64, &q);
        if (ev) {
          void *o = vcall<void *>(objTable(), 0x58, ev[0]);
          vcall<void>(o, 0x128, (u32) * (u16 *)(self + 0x4c), ev + 1, 0u);
          vcall<void>(*(void **)(f + 8), 0x44, &q);
        }
      }
      if (--budget == 0)
        break;
    }
  }
  prof(0x17c, 0x260, 0x6b22d0);
}
PCREG(5b7420, formSendUpdates);

