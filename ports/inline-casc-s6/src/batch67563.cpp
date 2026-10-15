// batch67563.cpp - cascade s6 batch 67563: 0x466dc0.
#include "ff.h"

extern "C" u32 THISCALL ext_463620(u8 *self, u8 *st);                 // ret 4, bool in al
extern "C" void THISCALL ext_466eb0(u8 *sub, u8 *st, u8 *owner);      // ret 8
extern "C" void THISCALL ext_4946a0(u8 *list, u8 *item);              // ret 4

// 0x466dc0, thiscall(stream) ret 4, returns al: loads the object from a stream. After this slot 0x3d4 it asks 0x463620(stream) to validate (false returns 0). It then runs this slot 0x358 and reads
// the fields +0x169 (slot 0x40), +0x158 (0x68), +0x159 and +0x136 (0x48), +0x1ca (0x50), the sub-record at +0x16d (0x466eb0(stream, this)), a stream object (slot 0x6c into +0x1ba) whose slot 0x50 reads
// +0x1c6, and a handle through slot 0x40 into a local; a non-zero handle is resolved by this slot 0x3ec, loaded from the stream (slot 0x1c) and added to the list at this[0x1ce] (0x4946a0). Finally
// +0x14f is read (slot 0x48); returns 1.
extern "C" __attribute__((used, thiscall)) u32 body466dc0(u8 *self, u8 *st, u32 *hout) {
  *hout = 0;
  vcall<void>(self, 0x3d4);
  if (!(u8)ext_463620(self, st)) return 0;
  vcall<void>(self, 0x358);
  vcall<void>(st, 0x40, (u32)(self + 0x169));
  vcall<void>(st, 0x68, (u32)(self + 0x158));
  vcall<void>(st, 0x48, (u32)(self + 0x159));
  vcall<void>(st, 0x48, (u32)(self + 0x136));
  vcall<void>(st, 0x50, (u32)(self + 0x1ca));
  ext_466eb0(self + 0x16d, st, self);
  u8 *x = vcall<u8 *>(st, 0x6c, (u32)(self + 0x1ba));
  vcall<void>(x, 0x50, (u32)(self + 0x1c6));
  u32 h;
  vcall<void>(st, 0x40, (u32)&h);
  if (h) {
    *hout = h;
    u8 *y = vcall<u8 *>(self, 0x3ec, h, 0u);
    vcall<void>(y, 0x1c, (u32)st);
    ext_4946a0(*(u8 **)(self + 0x1ce), y);
  }
  vcall<void>(st, 0x48, (u32)(self + 0x14f));
  return 1;
}
// The original unbalances its stack when a handle was read (a `pop esi` without a push): it returns with ebx = handle, edi = caller's ebx and esi = caller's edi. The wrapper reproduces that.
extern "C" __attribute__((naked, used)) void wrap466dc0() {
  asm volatile(
      "movl 4(%esp), %edx\n"
      "pushl %edi\n"
      "pushl %ebx\n"
      "pushl $0\n"
      "leal (%esp), %eax\n"
      "pushl %eax\n"
      "pushl %edx\n"
      "call body466dc0\n"
      "movl (%esp), %ecx\n"
      "testl %ecx, %ecx\n"
      "jz 1f\n"
      "movl 8(%esp), %esi\n"
      "movl 4(%esp), %edi\n"
      "movl %ecx, %ebx\n"
      "addl $12, %esp\n"
      "ret $4\n"
      "1:\n"
      "addl $4, %esp\n"
      "popl %ebx\n"
      "popl %edi\n"
      "ret $4\n");
}
PCREG(466dc0, wrap466dc0);
