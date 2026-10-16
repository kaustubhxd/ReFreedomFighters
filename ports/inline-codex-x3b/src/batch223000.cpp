#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" u32 THISCALL ext_45f3c0(void *self, u32 reader);
extern "C" u32 THISCALL ext_4de7a0(void *self);
extern "C" u32 THISCALL ext_5a6980(void *self);
extern "C" u32 THISCALL ext_5aa190(void *self, u32 reader);

static inline u32 call1(void *self, u32 slot, u32 a) {
  return (*(V1 *)(*(u8 **)self + slot))(self, a);
}

static inline u32 call2(void *self, u32 slot, u32 a, u32 b) {
  return (*(V2 *)(*(u8 **)self + slot))(self, a, b);
}

static inline u32 call0(void *self, u32 slot) {
  return (*(V0 *)(*(u8 **)self + slot))(self);
}

static inline float cvt_i32_f32(u32 v) {
  return _mm_cvtss_f32(_mm_cvtsi32_ss(_mm_setzero_ps(), (s32)v));
}

// 0x5aa250: thiscall(this, reader) ret 4. Reads serialized fields, resolves
// identifier lists through the engine table, initializes runtime collections,
// and lets each pending child consume the reader.
u32 THISCALL fn_5aa250(u8 *self, u8 *reader) {
  u8 *const reader_reg = reader;
  u32 gate = ext_45f3c0(self, (u32)reader_reg);
  if ((gate & 0xffu) == 0) return gate; // m4

  *(u32 *)(self + 0x681) = 0; // m0
  call1(reader_reg, 0x40, (u32)(self + 0x69d));
  call1(reader_reg, 0x50, (u32)(self + 0x2fc));

  // The reader owns an in/out pointer to the caller's argument slot. EBX in
  // the original preserves the old reader for all calls that follow it.
  volatile u8 *reader_arg = reader;
  call1(reader_reg, 0x40, (u32)&reader_arg);
  *(u32 *)(self + 0x354) = (u32)reader_arg;

  call1(reader_reg, 0x50, (u32)(self + 0x358));
  call1(reader_reg, 0x50, (u32)(self + 0x35c));
  call1(reader_reg, 0x50, (u32)(self + 0x42c));
  call1(reader_reg, 0x40, (u32)(self + 0x3d4));
  call1(reader_reg, 0x40, (u32)(self + 0x3d8));
  call1(reader_reg, 0x40, (u32)(self + 0x3dc));
  call1(reader_reg, 0x40, (u32)(self + 0x3e0));
  call1(reader_reg, 0x40, (u32)(self + 0x3e4));
  call1(reader_reg, 0x40, (u32)(self + 0x3e8));
  call1(reader_reg, 0x40, (u32)(self + 0x3ec));
  call1(reader_reg, 0x40, (u32)(self + 0x3f0));
  call1(reader_reg, 0x40, (u32)(self + 0x3f4));
  call1(reader_reg, 0x40, (u32)(self + 0x3f8));
  call1(reader_reg, 0x40, (u32)(self + 0x3fc));
  call1(reader_reg, 0x40, (u32)(self + 0x400));
  call1(reader_reg, 0x40, (u32)(self + 0x404));
  call1(reader_reg, 0x40, (u32)(self + 0x408));
  call1(reader_reg, 0x40, (u32)(self + 0x40c));
  call1(reader_reg, 0x40, (u32)(self + 0x410));
  call1(reader_reg, 0x40, (u32)(self + 0x414));
  call1(reader_reg, 0x40, (u32)(self + 0x418));

  call1(reader_reg, 0x40, (u32)&reader_arg);
  *(u32 *)(self + 0x3c2) = (u32)reader_arg;
  call1(reader_reg, 0x68, (u32)(self + 0x3c6));
  call1(reader_reg, 0x68, (u32)(self + 0x3c7));
  call1(reader_reg, 0x50, (u32)(self + 0x3c8));
  call1(reader_reg, 0x40, (u32)&reader_arg);
  *(u32 *)(self + 0x3cc) = (u32)reader_arg;
  call1(reader_reg, 0x50, (u32)(self + 0x3d0));
  call1(reader_reg, 0x50, (u32)(self + 0x374));
  call1(reader_reg, 0x40, (u32)(self + 0x378));
  call1(reader_reg, 0x40, (u32)(self + 0x370));

  u32 id = 0;
  call1(reader_reg, 0x40, (u32)&id);
  u8 *sys = G(u8 *, 0x70039c);
  void *table = *(void **)(sys + 0x9b);
  *(u32 *)(self + 0x364) = call1(table, 0x58, id);
  call1(reader_reg, 0x48, (u32)(self + 0x360));
  call1(reader_reg, 0x40, (u32)(self + 0x348));
  call1(reader_reg, 0x40, (u32)(self + 0x34c));

  call1(reader_reg, 0x40, (u32)&reader_arg);
  *(u32 *)(self + 0x300) = (u32)reader_arg;
  call1(reader_reg, 0x40, (u32)&id);
  *(u32 *)(self + 0x89e) = call1(table, 0x58, id);
  call1(reader_reg, 0x40, (u32)&id);
  *(u32 *)(self + 0x89a) = call1(table, 0x58, id);

  u32 mode = 0;
  call1(reader_reg, 0x68, (u32)&mode);
  void *clock = *(void **)(sys + 0x190f);
  call1(clock, 0x0c, mode);
  call2(reader_reg, 0x18, (u32)(self + 0x18), 0x2b8); // m1
  call2(reader_reg, 0x18, (u32)(self + 0x37d), 0x45);
  *(float *)(self + 0x2f4) = cvt_i32_f32(call0(clock, 0xd8)); // m2
  u32 height = call0(clock, 0xdc);
  *(u32 *)(self + 0x368) = 0;
  *(u32 *)(self + 0x685) = 0;
  *(u32 *)(self + 0x68d) = 0;
  *(float *)(self + 0x2f8) = cvt_i32_f32(height);
  *(u32 *)(self + 0x36c) = 0;

  ext_4de7a0(self + 0x2d0);
  ext_5a6980(self);

  for (u8 *p = *(u8 **)(self + 0x659), *end = *(u8 **)(self + 0x65d); p != end; p += 4)
    call1(*(void **)p, 0x0c, (u32)reader_reg);
  for (u8 *p = *(u8 **)(self + 0x665), *end = *(u8 **)(self + 0x669); p != end; p += 4)
    call1(*(void **)p, 0x0c, (u32)reader_reg);
  for (u8 *p = *(u8 **)(self + 0x671), *end = *(u8 **)(self + 0x675); p != end; p += 4)
    call1(*(void **)p, 0x0c, (u32)reader_reg);

  *(u32 *)(self + 0x304) = 0x0fffffffu; // m5
  ext_5aa190(self + 0x53c, (u32)reader_reg);
  u32 tail = ext_5aa190(self + 0x54a, (u32)reader_reg);
  return (tail & 0xffffff00u) | 1u; // m3
}
PCREG(5aa250, fn_5aa250);
