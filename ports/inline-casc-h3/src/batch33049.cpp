// batch33049.cpp - h3 (Sonnet) batch 33049: tiny tier C wrappers (sysobj table lookups, pointer calls, tail-calls)
#include "ff.h"

extern "C" u32 THISCALL ext_478b70(u8 *self, u32 a, u32 b);            // ret 8
extern "C" void THISCALL ext_4690b0(u8 *self);                          // ret 0
extern "C" u32 THISCALL ext_63d910(u8 *self);                           // ret 0
extern "C" void __attribute__((fastcall)) ext_4de420(u8 *dst, u8 *src); // ecx=dst, edx=src

#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))

// 0x46e8c0: thiscall: id=[this+0x68]; id ? table->slot 0x58(id) : 0
static u32 THISCALL fn46e8c0(u8 *self) {
  u32 id = *(u32 *)(self + 0x68);
  if (!id) return 0;
  return vcall<u32>(SYS_TABLE, 0x58, id);
}
PCREG(46e8c0, fn46e8c0);

// 0x4cbe20: thiscall(a,b,c) ret 0xc: call fn ptr [this+0x1f] with ecx=a, edx=b, stack (this, c), callee pops
typedef u32 (__attribute__((fastcall)) *fc_t)(u32, u32, u8 *, u32);
static u32 THISCALL fn4cbe20(u8 *self, u32 a, u32 b, u32 c) {
  fc_t f = *(fc_t *)(self + 0x1f);
  return f(a, b, self, c);
}
PCREG(4cbe20, fn4cbe20);

// 0x59fd00: thiscall(a,b) ret 8: if byte [this+0x7a6]&1 slot 0x21c(0x6accdc) else tail-call 0x478b70(a,b)
static u32 THISCALL fn59fd00(u8 *self, u32 a, u32 b) {
  if (self[0x7a6] & 1) return vcall<u32>(self, 0x21c, 0x6accdcu);
  return ext_478b70(self, a, b);
}
PCREG(59fd00, fn59fd00);

// 0x6515a0: thiscall: o=[this+0xbd] re-read each step: 0x4690b0(o); o->slot 0(this); tail-call 0x63d910(o)
static u32 THISCALL fn6515a0(u8 *self) {
  ext_4690b0(*(u8 **)(self + 0xbd));
  vcall<u32>(*(u8 **)(self + 0xbd), 0, (u32)self);
  return ext_63d910(*(u8 **)(self + 0xbd));
}
PCREG(6515a0, fn6515a0);

// 0x4632d0: thiscall(a) ret 4: r = [this+0x6c]->slot 0x58(this); 0x4de420(a, r)
static void THISCALL fn4632d0(u8 *self, u8 *a) {
  u8 *r = vcall<u8 *>(*(u8 **)(self + 0x6c), 0x58, (u32)self);
  ext_4de420(a, r);
}
PCREG(4632d0, fn4632d0);

// 0x46ef70: thiscall(a) ret 4: id=[this+0xe1]; id ? table->slot 0x58(id) : 0
static u32 THISCALL fn46ef70(u8 *self, u32 a) {
  u32 id = *(u32 *)(self + 0xe1);
  if (!id) return 0;
  return vcall<u32>(SYS_TABLE, 0x58, id);
}
PCREG(46ef70, fn46ef70);

// 0x4c5750: thiscall(a) ret 4 bool: [this+4]&=~0x40; a->slot 0x60(byte [this+0x52]); return 1
static u32 THISCALL fn4c5750(u8 *self, u8 *a) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<u32>(a, 0x60, (u32)self[0x52]);
  return 1;
}
PCREG(4c5750, fn4c5750);

// 0x4cbdd0: thiscall(a) ret 4 bool: [this+4]&=~0x40; a->slot 0x50(this+0x4c); return 1
static u32 THISCALL fn4cbdd0(u8 *self, u8 *a) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<u32>(a, 0x50, (u32)(self + 0x4c));
  return 1;
}
PCREG(4cbdd0, fn4cbdd0);
