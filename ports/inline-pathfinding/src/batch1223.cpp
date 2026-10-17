// batch1223.cpp - pathfinding tree: ZPFOctree_packed::SerializeData(char* blob, int mode, bool) [map high; GameCube reference;
// zpfoctreepacked.cpp lines 0x9ac..0x9ae]. thiscall (octree), ret 0xc, returns the number of blob bytes used.
//
// Blob layout (after the 4-byte format word that goes to +0x48): u16 A (+0x2a) and u16 B (+0x52); B entries of 0x16
// bytes (component table, +0x54); u16 C (+0x58), C of 12 bytes (area table, +0x5a); u16 D (+0x70), then D*A u32
// (+0x72); u16 E (+0x5e), E u32 (+0x60); u16 F (+0x64), F of 10 bytes (+0x66); u16 G (+0x86), G of 12 bytes (+0x88);
// if +4: G u32 (+0x8c), and if +5: G of 24 bytes (+0x90); u16 H (+0x6a), H u32 (+0x6c); u16 I (+0x76), I of 10 bytes
// (+0x78) and I bytes (+0x7c); u16 J (+0x80), J bytes (+0x82); then a 0x44-byte record copied into the fields
// +0x2c..+0x4c. Mode 1 allocates each array first (load); mode 2 copies into the arrays already there.
#include "pf.h"

extern "C" void *ext_634d22(void *dst, const void *src, u32 n);   // memcpy (cdecl)

#define OCT_FILE ((const char *)0x6a1438)

static u32 THISCALL octreeSerializeData(u8 *self, u8 *blob, u32 mode, u32 flag) {
  (void)flag;   // the bool argument (ret 0xc); not read by this function
  u8 *edi = blob + 4;
  *(u32 *)(self + 0x48) = *(u32 *)blob;
  *(u16 *)(self + 0x2a) = *(u16 *)edi;
  *(u16 *)(self + 0x52) = *(u16 *)(edi + 2);
  edi += 4;
  u32 A = *(u16 *)(self + 0x2a), B = *(u16 *)(self + 0x52);
  if (mode == 1) *(void **)(self + 0x54) = ext_41e290(B * 0x16);
  ext_634d22(*(void **)(self + 0x54), edi, B * 0x16);
  edi += B * 0x16;
  *(u16 *)(self + 0x58) = *(u16 *)edi;
  edi += 2;
  u32 C = *(u16 *)(self + 0x58);
  if (mode == 1) *(void **)(self + 0x5a) = ext_41e290(C * 12);
  ext_634d22(*(void **)(self + 0x5a), edi, C * 12);
  edi += C * 12;
  u32 D = *(u16 *)edi;
  edi += 2;
  *(u16 *)(self + 0x70) = (u16)D;
  if (mode == 1) *(void **)(self + 0x72) = ext_41e290(D * A * 4);
  ext_634d22(*(void **)(self + 0x72), edi, D * A * 4);
  edi += D * A * 4;
  u32 E = *(u16 *)edi;
  edi += 2;
  *(u16 *)(self + 0x5e) = (u16)E;
  if (mode == 1) *(void **)(self + 0x60) = ext_41e290(E * 4);
  ext_634d22(*(void **)(self + 0x60), edi, E * 4);
  edi += E * 4;
  u32 F = *(u16 *)edi;
  edi += 2;
  *(u16 *)(self + 0x64) = (u16)F;
  if (mode == 1) *(void **)(self + 0x66) = ext_41e290(F * 10);
  ext_634d22(*(void **)(self + 0x66), edi, F * 10);
  edi += F * 10;
  u32 G = *(u16 *)edi;
  edi += 2;
  *(u16 *)(self + 0x86) = (u16)G;
  if (mode == 1) *(void **)(self + 0x88) = ext_41e290(G * 12);
  ext_634d22(*(void **)(self + 0x88), edi, G * 12);
  edi += G * 12;
  if (self[4]) {
    if (mode == 1) *(void **)(self + 0x8c) = ext_41e290(G * 4);
    ext_634d22(*(void **)(self + 0x8c), edi, G * 4);
    edi += G * 4;
    if (self[5]) {
      if (mode == 1) *(void **)(self + 0x90) = ext_41e290(G * 24);
      ext_634d22(*(void **)(self + 0x90), edi, G * 24);
      edi += G * 24;
    }
  }
  u32 H = *(u16 *)edi;
  edi += 2;
  *(u16 *)(self + 0x6a) = (u16)H;
  if (mode == 1) *(void **)(self + 0x6c) = ext_41e290(H * 4);
  ext_634d22(*(void **)(self + 0x6c), edi, H * 4);
  edi += H * 4;
  u32 I = *(u16 *)edi;
  edi += 2;
  *(u16 *)(self + 0x76) = (u16)I;
  if (mode == 1) {
    *(void **)(self + 0x78) = ext_41e290(I * 10);
    *(void **)(self + 0x7c) = ext_41e290(I);
  }
  ext_634d22(*(void **)(self + 0x78), edi, I * 10);
  edi += I * 10;
  ext_634d22(*(void **)(self + 0x7c), edi, I);
  edi += I;
  u32 J = *(u16 *)edi;
  edi += 2;
  *(u16 *)(self + 0x80) = (u16)J;
  if (mode == 1) *(void **)(self + 0x82) = ext_41e290(J);
  ext_634d22(*(void **)(self + 0x82), edi, J);
  edi += J;
  // the fixed record
  __builtin_memcpy(self + 0x2c, edi, 8);
  *(u32 *)(self + 0x34) = *(u32 *)(edi + 8);
  __builtin_memcpy(self + 0x3c, edi + 0xc, 8);
  *(u32 *)(self + 0x44) = *(u32 *)(edi + 0x14);
  __builtin_memcpy(self + 6, edi + 0x18, 8);
  *(u32 *)(self + 0xe) = *(u32 *)(edi + 0x20);
  __builtin_memcpy(self + 0x12, edi + 0x24, 8);
  *(u32 *)(self + 0x1a) = *(u32 *)(edi + 0x2c);
  __builtin_memcpy(self + 0x1e, edi + 0x30, 8);
  *(u32 *)(self + 0x26) = *(u32 *)(edi + 0x38);
  *(u32 *)(self + 0x38) = *(u32 *)(edi + 0x3c);
  *(u32 *)(self + 0x4c) = *(u32 *)(edi + 0x40);
  edi += 0x44;
  if (G(u8, 0x701b5d)) {
    void *r = vcall<void *>(G(void *, 0x700390), 0x20, OCT_FILE, 0x9ac);
    typedef void (*fn3)(void *, const char *, double, double, double);
    double a = *(float *)(self + 6), b = *(float *)(self + 0xa), c = *(float *)(self + 0xe);
    (*(fn3 *)(*(u8 **)r + 0x2c))(r, (const char *)0x6a1508, a, b, c);
    r = vcall<void *>(G(void *, 0x700390), 0x20, OCT_FILE, 0x9ad);
    a = *(float *)(self + 0x12); b = *(float *)(self + 0x16); c = *(float *)(self + 0x1a);
    (*(fn3 *)(*(u8 **)r + 0x2c))(r, (const char *)0x6a1520, a, b, c);
    r = vcall<void *>(G(void *, 0x700390), 0x20, OCT_FILE, 0x9ae);
    typedef void (*fn1)(void *, const char *, u32);
    (*(fn1 *)(*(u8 **)r + 0x2c))(r, (const char *)0x6a1538, *(u32 *)(self + 0x38));
  }
  return (u32)(edi - blob);
}
PCREG(531270, octreeSerializeData);
