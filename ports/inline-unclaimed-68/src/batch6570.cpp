// batch6570.cpp - unclaimed-68 batch 57 (claim 58): 0x46b800, a Command(unsigned short, void*)-shaped method (GUESS name).
// thiscall, two stack arguments (ret 8). Returns 0. The cold path calls the exe helper 0x45d380 (thiscall, two arguments, ret 8).
#include "ff.h"

typedef u32(THISCALL *VRet0)(u8 *self);
typedef void(THISCALL *VVoid0)(u8 *self);
typedef u32(THISCALL *VRet1)(u8 *self, u32 a);
typedef void(THISCALL *VVoid1)(u8 *self, u32 a);
typedef u32(THISCALL *VRet2)(u8 *self, u32 a, u32 b);
typedef void(THISCALL *VVoid2)(u8 *self, u32 a, u32 b);

extern "C" void THISCALL ext_45d380(u8 *self, u32 cmd, u8 *obj);   // ret 8

static u8 *mgrObj() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 1 when the last call took the main path (the one whose exit pops ESI, EBX, EDI out of order); read by the naked wrapper.
extern "C" volatile u32 g_mainPath46b800 = 0;

extern "C" u32 THISCALL cmdBody46b800(u8 *self, u32 cmd, u8 *obj) {
  bool matches7c = (u16)cmd == *(u16 *)(self + 0x7c);
  bool matches7e = (u16)cmd == *(u16 *)(self + 0x7e);
  g_mainPath46b800 = 0;
  if (*(u32 *)(self + 0x60) == 0 || (!matches7c && !matches7e)) {
    ext_45d380(self, cmd, obj);
    return 0;
  }
  if (!matches7c) {
    u8 *mgr = mgrObj();
    u32 r = ((VRet1)*(u32 *)(*(u8 **)mgr + 0x58))(mgr, *(u32 *)(self + 0x60));
    if (r == 0) return 0;
    u32 e = ((VRet0)*(u32 *)(*(u8 **)r + 0x2ec))((u8 *)r);
    ((VRet2)*(u32 *)(*(u8 **)obj + 0x54))(obj, 0x688a38u, e != 0);
    return 0;
  }
  // cmd matches self+0x7c: the main path (all of its exits go through the out-of-order epilogue, see the wrapper)
  g_mainPath46b800 = 1;
  u8 *mgr = mgrObj();
  u32 v1 = ((VRet0)*(u32 *)(*(u8 **)mgr + 0x4c))(mgr);
  ((VRet2)*(u32 *)(*(u8 **)obj + 0x4c))(obj, 0x688a30u, v1);
  mgr = mgrObj();
  u32 first = ((VRet1)*(u32 *)(*(u8 **)mgr + 0x58))(mgr, *(u32 *)(self + 0x60));
  if (first == 0) return 0;
  if (!(u8)((VRet1)*(u32 *)(*(u8 **)first + 0x2e4))((u8 *)first, (u32)obj)) return 0;
  ((VRet2)*(u32 *)(*(u8 **)obj + 0x88))(obj, 0x68884cu, (u32)(self + 0x5c));
  u8 *X = *(u8 **)(self + 0x6c);
  if (X) {
    u32 l = 0;
    ((VVoid1)*(u32 *)(*(u8 **)X + 0x4c))(X, (u32)&l);
    u32 el = ((VRet1)*(u32 *)(*(u8 **)X + 0x64))(X, (u32)&l);
    while (el != 0) {
      mgr = mgrObj();
      u32 cur = ((VRet1)*(u32 *)(*(u8 **)mgr + 0x58))(mgr, *(u32 *)el);
      bool skipBlock = false;
      if (cur != 0) {
        u32 name = *(u32 *)(cur + 4);
        if (name == 0) name = 0x67c8e8u;
        u8 r2 = (u8)((VRet2)*(u32 *)(*(u8 **)first + 0x2f4))((u8 *)first, *(u32 *)(self + 0x5c), name);
        if (r2 != 0) {
          skipBlock = true;
        } else {
          u8 *s = *(u8 **)(cur + 0xc);
          if ((*(u32 *)(s + 0x23) & 0x400000u) && *(u32 *)(self + 0x5c) == 3) skipBlock = true;
        }
        if (!skipBlock) {
          u8 *o70 = *(u8 **)(self + 0x70);
          ((VVoid1)*(u32 *)(*(u8 **)o70 + 0x40))(o70, *(u32 *)el);
          ((VVoid1)*(u32 *)(*(u8 **)cur + 0x210))((u8 *)cur, 1u);
        }
      }
      if (cur == 0 || !skipBlock) {
        ((VVoid1)*(u32 *)(*(u8 **)X + 0x44))(X, (u32)&l);
      }
      el = ((VRet1)*(u32 *)(*(u8 **)X + 0x64))(X, (u32)&l);
    }
  }
  ((VVoid1)*(u32 *)(*(u8 **)first + 0x2e0))((u8 *)first, (u32)obj);
  ((VVoid0)*(u32 *)(*(u8 **)self + 0x318))(self);
  return 0;
}
// Naked wrapper. The exe saves EDI, then on the main path pushes EBX, ESI and EDI (= this), and its exit pops ESI, EBX, EDI in that
// order, so the caller gets ESI = this, EBX = the caller's ESI, EDI = the caller's EBX. Other paths restore all three.
extern "C" void opaque46b800(void);
__asm__(
    ".text\n"
    ".globl opaque46b800\n"
    "opaque46b800:\n"
    "  pushl %ebx\n"
    "  pushl %esi\n"
    "  pushl %edi\n"
    "  movl %ecx, %edi\n"
    "  pushl 20(%esp)\n"
    "  pushl 20(%esp)\n"
    "  movl %edi, %ecx\n"
    "  call cmdBody46b800\n"
    "  cmpl $0, g_mainPath46b800\n"
    "  je 1f\n"
    "  movl %edi, %esi\n"
    "  movl 4(%esp), %ebx\n"
    "  movl 8(%esp), %edi\n"
    "  addl $12, %esp\n"
    "  ret $8\n"
    "1:\n"
    "  popl %edi\n"
    "  popl %esi\n"
    "  popl %ebx\n"
    "  ret $8\n");
PCREG(46b800, opaque46b800);
