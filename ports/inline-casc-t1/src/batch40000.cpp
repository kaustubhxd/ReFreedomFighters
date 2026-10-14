// batch40000.cpp - cascade t1 (), tier H: 0x479090, 0x4d6150, 0x45aff0, 0x421810.
#include "ff.h"

extern "C" void ext_634dc4();                                    // x87 CRT routine (st0 = 1.0, st1 = x on entry; result in st0)
extern "C" double VECTORCALL ext_634d7c(double);                 // CRT sqrt, argument/result in XMM0
extern "C" u8 *ext_41e290(u32 n);                                // cdecl allocator (n bytes)
extern "C" void THISCALL ext_4d9350(u8 *self, u32 a, u8 *blk);   // thiscall ret 8
extern "C" void THISCALL ext_4dd060(u8 *self, u8 *p);            // thiscall ret 4
extern "C" void THISCALL ext_4dce50(u8 *self, float f);          // thiscall ret 4
extern "C" void THISCALL ext_42d730(u8 *self, u8 *p);            // thiscall ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr64(u8 *p, double d) { u64 u = __builtin_bit_cast(u64, d); for (int i = 0; i < 8; i++) p[i] = u >> (8 * i); }

// 0x479090, thiscall() returns the low byte: q = unaligned float [this+0x755] as double; r = float(fmod-style x87 routine 0x634dc4 (q, 1.0));
// false when K1(0x67a288) <= r <= K2(0x684ce4) (ordered), else true (also for NaN).
static u32 THISCALL fn479090(u8 *self) {
  double qd = (double)__builtin_bit_cast(float, rd32(self + 0x755));
  float r;
  __asm__ volatile("fldl %1\n\tfld1\n\tcall ext_634dc4\n\tfstps %0" : "=m"(r) : "m"(qd) : "eax", "ecx", "edx", "memory", "cc", "st", "st(1)", "st(2)", "st(3)");
  return !(r >= G(float, 0x67a288) && G(float, 0x684ce4) >= r);
}
PCREG(479090, fn479090);

// 0x4d6150, thiscall(a, p, c) ret 0xc: blk = ext_41e290(0x1e); blk[0..0x1a) = p[0..0x1a); unaligned [blk+0x1a] = c; ext_4d9350(this+4, a, blk);
// then slot 4 of the object at this+0xa (vtable = unaligned dword at this+0xa) is called with blk.
static void THISCALL fn4d6150(u8 *self, u32 a, u8 *p, u32 c) {
  u8 *blk = ext_41e290(0x1e);
  for (int i = 0; i < 0x1a; i++) blk[i] = p[i];
  blk[0x1a] = c; blk[0x1b] = c >> 8; blk[0x1c] = c >> 16; blk[0x1d] = c >> 24;
  ext_4d9350(self + 4, a, blk);
  u8 *o = self + 0xa;
  u8 *vt = (u8 *)rd32(o);
  ((void(THISCALL *)(u8 *, u8 *))rd32(vt + 4))(o, blk);
}
PCREG(4d6150, fn4d6150);

// 0x45aff0, thiscall(): o = [this+8]; ext_4dd060(o, this+0x18); then with o = [this+8] again: f = (float)sqrt((double)(x*x + y*y + z*z)) + K(0x678858)
// where x, y, z = floats [o+0x40], [o+0x44], [o+0x48]; ext_4dce50(o, f).
static void THISCALL fn45aff0(u8 *self) {
  ext_4dd060(*(u8 **)(self + 8), self + 0x18);
  u8 *o = *(u8 **)(self + 8);
  float x = *(float *)(o + 0x40), y = *(float *)(o + 0x44), z = *(float *)(o + 0x48);
  float s = x * x + y * y;
  s = s + z * z;
  float f = (float)ext_634d7c((double)s) + G(float, 0x678858);
  ext_4dce50(o, f);
}
PCREG(45aff0, fn45aff0);

// 0x421810, thiscall(p) ret 4: ext_42d730(this, p); p->slot0x54(this+0x23c6); p->slot0x5c(this+0x23ce); t = clock() (CRT import 0x676434, signed);
// unaligned double [this+0xc] = (double)(float)((double)t * K(0x6785e8)); this->slot0x170().
static void THISCALL fn421810(u8 *self, u8 *p) {
  ext_42d730(self, p);
  vcall<void>(p, 0x54, self + 0x23c6);
  vcall<void>(p, 0x5c, self + 0x23ce);
  s32 t = (*(s32(**)())0x676434)();
  float f = (float)((double)t * G(double, 0x6785e8));
  wr64(self + 0xc, (double)f);
  vcall<void>(self, 0x170);
}
PCREG(421810, fn421810);
