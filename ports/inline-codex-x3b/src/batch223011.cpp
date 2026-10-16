#include "ff.h"

static inline float read_f32(const u8 *p) {
  float v;
  __builtin_memcpy(&v, p, sizeof v);
  return v;
}

// 0x526fd0: thiscall(this), fld [ecx+4], plain ret, result in x87 ST0.
float THISCALL fn_526fd0(u8 *self) {
  return read_f32(self + 4); // m526fd0
}
PCREG(526fd0, fn_526fd0);

// 0x524390: thiscall(this), fld [ecx+0xc], plain ret, result in x87 ST0.
float THISCALL fn_524390(u8 *self) {
  return read_f32(self + 0xc); // m524390
}
PCREG(524390, fn_524390);

// 0x51c550: thiscall(this), though this is unused; returns the global float in ST0.
float THISCALL fn_51c550(u8 *self) {
  (void)self;
  return G(float, 0x69f9e8); // m51c550
}
PCREG(51c550, fn_51c550);

// 0x5162d0: thiscall(this), unaligned fld [ecx+0x55], plain ret.
float THISCALL fn_5162d0(u8 *self) {
  return read_f32(self + 0x55); // m5162d0
}
PCREG(5162d0, fn_5162d0);

// 0x486cb0: thiscall(this), fld [ecx+0x30], plain ret.
float THISCALL fn_486cb0(u8 *self) {
  return read_f32(self + 0x30); // m486cb0
}
PCREG(486cb0, fn_486cb0);

// 0x45efb0: stdcall(one unused stack argument), fld [0x67cd44], ret 4.
float STDCALL fn_45efb0(u32 unused) {
  (void)unused;
  return G(float, 0x67cd44); // m45efb0
}
PCREG(45efb0, fn_45efb0);

// 0x445fb0: thiscall(this), unaligned fld [ecx+0x181], plain ret.
float THISCALL fn_445fb0(u8 *self) {
  return read_f32(self + 0x181); // m445fb0
}
PCREG(445fb0, fn_445fb0);
