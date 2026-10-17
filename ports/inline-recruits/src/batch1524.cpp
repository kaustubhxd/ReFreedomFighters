// batch1524.cpp - recruits thread, batch 1524: ZFollowShape::FrameUpdate (0x4c5df0).
// Reconstructed from the disassembly (every branch below is one block of it; the x87/SSE steps are written with the
// same operation order). Helpers: BasicShape::GetSplinePos (0x460aa0, ported in batch 1520), mreset (0x4de7a0).
#include "ff.h"

extern "C" void THISCALL ext_460aa0(u8 *basic, float *out, float t);  // BasicShape::GetSplinePos (batch 1520)
extern "C" void THISCALL ext_4de7a0(float *m);                        // mreset (identity 3x4)

static inline void *objTable() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }

static inline float bitsToF(u32 b) { return __builtin_bit_cast(float, b); }
static inline u32 fToBits(float f) { return __builtin_bit_cast(u32, f); }

// 0x4c5df0 ZFollowShape::FrameUpdate(), thiscall, plain ret.
static void THISCALL shapeFrameUpdate(u8 *self) {
  void *T = vcall<void *>(objTable(), 0x58, *(u32 *)(self + 0x54));
  if (!T) {
    vcall<void>(self, 0x58);
    return;
  }
  // H = int(f50 * 1024) (cvttss2si); it is later replaced by a float's bits in every branch.
  u32 hb = (u32)_mm_cvttss_si32(_mm_set_ss(*(float *)(self + 0x50) * 1024.0f));
  u32 now = *(u32 *)(G(u8 *, 0x70039c) + 0x40);
  u32 off = *(u32 *)(self + 0x4c);
  if ((s32)(now - off) < (s32)hb)
    return;   // not yet due (the original's first exit)
  u8 mode = 0;
  const float one = 1.0f;
  u32 kind = *(u32 *)(self + 0x62);
  float radius = *(float *)(self + 0x48);

  // The three "next" steps. MID: the spline step. AFTER: the tail. EXIT: return.
  enum { MID, AFTER, EXIT } nxt = MID;

  // helper blocks (as code, the names say what the block does)
  // The original's edi here is still sys+0x40 (the engine time pointer from the entry code), not T: the copied value
  // is the current time, and the test is against that pointer (never equal to this+0x4c).
  auto offFromT = [&]() {
    u8 *timePtr = G(u8 *, 0x70039c) + 0x40;
    if ((u8 *)(self + 0x4c) != timePtr)
      *(u32 *)(self + 0x4c) = *(u32 *)timePtr;
  };
  auto tailZero = [&](float x0, float x1) {   // 4c5ed3 and 4c607a
    if (x0 <= x1) {
      nxt = MID;
      return;
    }
    if (self[0x59])
      vcall<void>(T, 0x210, 1u);
    nxt = AFTER;
  };
  auto tailB66 = [&](float x0, float x1) {   // 4c6059
    if (x0 <= x1) {
      nxt = MID;
      return;
    }
    offFromT();
    *(u32 *)(self + 0x50) = 0;
    mode = 1;
    nxt = MID;
  };
  auto tailB66b = [&](float x0, float x1) {   // 4c5ff1 (kind 1, flag 67 != 1)
    if (x0 <= x1) {
      nxt = MID;
      return;
    }
    offFromT();
    *(u32 *)(self + 0x67) = 1;
    *(u32 *)(self + 0x50) = 0;
    mode = 1;
    nxt = MID;
  };

  // D = now - H - off (32-bit), A = int(1024 / radius), P = A * D (64-bit), Q = low32(P >> 10).
  auto quotient = [&]() -> u32 {
    float r = one / radius;
    s32 A = _mm_cvttss_si32(_mm_set_ss(r * 1024.0f));
    s32 D = (s32)(now - hb - off);
    long long P = (long long)A * (long long)D;
    return (u32)((u64)P >> 10);
  };

  if (kind == 0) {
    // B0 (4c6019)
    u32 Q = quotient();
    float phase2 = (float)(s32)Q * 0.0009765625f;
    hb = fToBits(phase2);
    if (self[0x66] == 0)
      tailZero(phase2, one);
    else
      tailB66(phase2, one);
  } else if (kind == 1) {
    // B1 (4c5f64)
    u32 Q = quotient();
    if (*(u32 *)(self + 0x67) == 1) {
      float x = (float)(s32)Q * 0.0009765625f;
      hb = fToBits(x);
      if (!(x > one)) {
        nxt = MID;
      } else {
        offFromT();
        *(u32 *)(self + 0x50) = 0;
        *(u32 *)(self + 0x67) = 0;
        nxt = MID;
      }
    } else {
      u32 ecx = 0x400u - Q;
      float x1 = (float)(s32)ecx * 0.0009765625f;
      hb = fToBits(x1);
      if (self[0x66] == 0)
        tailZero(0.0f, x1);
      else
        tailB66b(0.0f, x1);
    }
  } else if (kind == 2) {
    // B2 (4c5e88)
    u32 Q = quotient();
    u32 ecx = 0x400u - Q;
    float x1 = (float)(s32)ecx * 0.0009765625f;
    hb = fToBits(x1);
    if (self[0x66] == 0)
      tailZero(0.0f, x1);
    else
      tailB66(0.0f, x1);
  } else {
    // default (4c5eee): H becomes the bit pattern of the object pointer (as the original does)
    hb = (u32)(u64)(u32)T;
    nxt = MID;
  }

  if (nxt == AFTER) {
    if (self[0x58]) {
      u8 *owner = *(u8 **)(self + 0x44);
      if (owner)
        vcall<void>(owner, 0x210, 1u);
    }
    vcall<void>(self, 0x68, 0x10u, 0u);
    return;
  }
  if (nxt == MID) {
    // (4c5ef8) identity matrix, then the spline point, then the owner's matrix
    float frame[12] = {0};
    ext_4de7a0(frame);
    float *pos = frame + 9;   // the original's two buffers overlap (see batch 1516)
    ext_460aa0(T ? (u8 *)T + 0x1c : (u8 *)0, pos, bitsToF(hb));
    vcall<void>(T, 0x84, pos);
    u8 *owner = *(u8 **)(self + 0x44);
    vcall<void>(owner, 0x7c, frame, pos);
    if (mode) {
      s32 c = *(s32 *)(self + 0x5a);
      if (c > 1) {
        --c;
        *(s32 *)(self + 0x5a) = c;
        if (c == 1)
          self[0x66] = 0;
      }
    }
  }
}
PCREG(4c5df0, shapeFrameUpdate);
