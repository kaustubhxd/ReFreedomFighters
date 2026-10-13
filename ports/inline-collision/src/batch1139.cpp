// batch1139.cpp - collision thread, batch 1139 (hard-row lane, name GUESS): 0x4364e0, a constructor. SEH frame not reproduced:
// the exe installs an exception frame (fs:[0], handler 0x6658ff) and restores it on exit; the port makes the same calls without
// it. Sets the vtable 0x67a7a4 and fields, copies the string s into a new buffer (0x41e290, cdecl), counts the 0x1c-byte records
// of the list that B returns (slot 0 of B), allocates one record (0x41e290), constructs it (0x4ccbe0), then adds the count to
// [A+0x1348] and calls 0x437440 (flag zero) or logs through the logger (flag non-zero). Returns this.
#include "ff.h"

extern "C" void *ext_41e290(u32 size);                          // exe: cdecl allocator, stubbed by address in the spec
extern "C" u32 THISCALL ext_4ccbe0(void *self, u32 a, u32 b);   // exe: record constructor, ret 8, stubbed by address
extern "C" void THISCALL ext_437440(void *self, u32 a, u32 b);  // exe: ret 8, stubbed by address

// 0x4364e0 (name GUESS): thiscall (ECX = this), four stack arguments (A, B, s, flag), ret 0x10.
static u8 *THISCALL ctor4364e0(u8 *self, u8 *A, u8 *B, const char *s, u32 flag) {
  *(u32 *)(self + 4) = 3;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)self = 0x67a7a4;
  u8 al = vcall<u8>(B, 4);
  *(u32 *)(self + 0x15) = (u32)B;
  u32 edi = 0;
  self[0x21] = al;
  *(u32 *)(self + 0x11) = (u32)A;
  *(u32 *)(self + 0x1d) = 1;
  *(u32 *)(self + 8) = 0;
  self[0x22] = 0;
  self[0x10] = 1;
  if (s) {
    const char *e = s;
    while (*e) e++;
    u32 len = (u32)(e - s);
    char *buf = (char *)ext_41e290(len + 1);
    *(u32 *)(self + 8) = (u32)buf;
    for (u32 i = 0;; i++) {
      buf[i] = s[i];
      if (s[i] == 0) break;
    }
  }
  u8 *list = (u8 *)vcall<u32>(B, 0);
  if (*(u32 *)list != 0) {
    u8 *c = list;
    do {
      c += 0x1c;
      edi++;
    } while (*(u32 *)c != 0);
  }
  u8 *rec = (u8 *)ext_41e290(0x1c);
  u32 res = rec ? ext_4ccbe0(rec, 8u, 0u) : 0;
  *(u32 *)(self + 0x19) = res;
  if (edi) {
    *(u32 *)(A + 0x1348) += edi;
    if (flag == 0) {
      ext_437440(self, edi, (u32)list);
    } else {
      void *S = vcall<void *>(G(void *, 0x700390), 0x20, 0x67a850u, 0x995u);
      typedef void (*CdeclOne)(void *, u32);
      CdeclOne f = (CdeclOne)((*(void ***)S)[0x2c / 4]);
      f(S, 0x67a9d8u);
    }
  }
  return self;
}
PCREG(4364e0, ctor4364e0);
