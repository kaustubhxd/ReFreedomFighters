// batch35201.cpp - cascade s5 batch 35201 (tier H): 0x5b6b70 (GUESS per-frame update of a list of effects: update the live ones, destroy the finished ones).
#include "ff.h"

extern "C" u8 THISCALL ext_5b5d60(u8 *self, u8 *e);          // al, ret 4
extern "C" void THISCALL ext_5b6110(u8 *self, u8 *e);        // ret 4
extern "C" void THISCALL ext_5b7420(u8 *self);               // plain ret
typedef u64(THISCALL *ts_t)(void *, u32, u32);
typedef void(THISCALL *lg_t)(void *, u32, u32, u32);
typedef void(THISCALL *it_t)(void *, u32 *);
typedef u8 *(THISCALL *nx_t)(void *, u32 *);
typedef void(THISCALL *d1_t)(void *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// Debug log (only when the floats at [engine+0x9c7] and [engine+0x9c3] are both non-zero): ts = engine slot 0x1c8(0x67a7f8, line) (64-bit in EDX:EAX); engine slot `slot`(lo, hi, 0x6b2128).
static void dbgLog(u32 line, u32 slot) {
  u8 *eng = G(u8 *, 0x70039c);
  if (bitsf(rd32u(eng + 0x9c7)) != 0.0f && bitsf(rd32u(eng + 0x9c3)) != 0.0f) {
    u64 ts = (*(ts_t **)eng)[0x1c8 / 4](eng, 0x67a7f8, line);
    u8 *e2 = G(u8 *, 0x70039c);
    (*(lg_t **)e2)[slot / 4](e2, (u32)ts, (u32)(ts >> 32), 0x6b2128);
  }
}

// 0x5b6b70, thiscall, no args, no return value. Debug log 0x259 (slot 0x178). C = [this+0x48]; when set: C slot 0x4c(it); e = C slot 0x64(it); for each e (C re-read each time): 0x5b5d60(this, e) true: 0x5b6110(this, e); otherwise the sub-collection [e+4], when set, is emptied
// (slot 0x4c, then slot 0x64 and slot 0x44 until slot 0x64 returns 0), then [e+4] slot 0(1) (when set), [e+8] slot 0(1) (when set) and C slot 0x44(it) removes the entry; then e = C slot 0x64(it). After the loop 0x5b7420(this); debug log 0x260 (slot 0x17c).
static void THISCALL fn5b6b70(u8 *self) {
  dbgLog(0x259, 0x178);
  u8 *C = *(u8 **)(self + 0x48);
  if (C) {
    u32 it[3], it2[3];
    (*(it_t **)C)[0x4c / 4](C, it);
    C = *(u8 **)(self + 0x48);
    u8 *e = (*(nx_t **)C)[0x64 / 4](C, it);
    while (e) {
      if (ext_5b5d60(self, e)) {
        ext_5b6110(self, e);
      } else {
        u8 *c2 = *(u8 **)(e + 4);
        if (c2) {
          (*(it_t **)c2)[0x4c / 4](c2, it2);
          c2 = *(u8 **)(e + 4);
          u8 *r = (*(nx_t **)c2)[0x64 / 4](c2, it2);
          if (r) {
            do {
              c2 = *(u8 **)(e + 4);
              (*(it_t **)c2)[0x44 / 4](c2, it2);
              c2 = *(u8 **)(e + 4);
              r = (*(nx_t **)c2)[0x64 / 4](c2, it2);
            } while (r);
          }
        }
        c2 = *(u8 **)(e + 4);
        if (c2) (*(d1_t **)c2)[0](c2, 1);
        u8 *c3 = *(u8 **)(e + 8);
        if (c3) (*(d1_t **)c3)[0](c3, 1);
        C = *(u8 **)(self + 0x48);
        (*(it_t **)C)[0x44 / 4](C, it);
      }
      C = *(u8 **)(self + 0x48);
      e = (*(nx_t **)C)[0x64 / 4](C, it);
    }
  }
  ext_5b7420(self);
  dbgLog(0x260, 0x17c);
}
PCREG(5b6b70, fn5b6b70);
