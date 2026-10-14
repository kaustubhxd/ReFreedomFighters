// batch34056.cpp - cascade tier E, batch 34056: 0x462040 (read two strings from a stream and resolve them), 0x464460 (store a flag and, when clear, publish a table value), 0x476b50 (cycle to the next
// object, attach and configure it).
#include "ff.h"

extern "C" void THISCALL ext_610100(void *self, void *s);   // thiscall ret 4 (an empty stub in the exe: runs for real)
extern "C" void THISCALL ext_4e1070(void *s, char *buf);    // thiscall ret 4: reads a string from the stream
extern "C" u32 THISCALL ext_4e1b30(void *s);                // thiscall, plain ret
extern "C" void FASTCALL ext_633654(u32 cookie);            // /GS check

// 0x462040, thiscall(s) ret 4: 0x610100(this, s); 0x4e1070(s, buf1), 0x4e1070(s, buf2) (two 0x200-byte local strings); [this+0x5c] = this->slot0x2f4(buf1, this+0x64); [this+0x60] =
// this->slot0x2f4(buf2, this+0x68); 0x4e1b30(s) (its result stays in EAX); the /GS check.
static u32 THISCALL fn462040(u8 *self, u8 *s) {
  char buf1[0x200];
  char buf2[0x200];
  ext_610100(self, s);
  ext_4e1070(s, buf1);
  ext_4e1070(s, buf2);
  *(u32 *)(self + 0x5c) = vcall<u32>(self, 0x2f4, (u32)buf1, (u32)(self + 0x64));
  *(u32 *)(self + 0x60) = vcall<u32>(self, 0x2f4, (u32)buf2, (u32)(self + 0x68));
  u32 r = ext_4e1b30(s);
  ext_633654(0);
  return r;
}
PCREG(462040, fn462040);

// 0x464460, thiscall(f) ret 4: byte [this+0x70] = low byte of f; when it is zero: w = engine table slot 0x114(0x6859f4, 0, 0x685834, 0x671) (16-bit), t = engine table slot 0x138(), tmp = 0;
// t->slot0x88(0x685a0c, &tmp); v = engine table slot 0x4c(this); this->slot0x12c(tmp, w, v).
static void THISCALL fn464460(u8 *self, u32 f) {
  self[0x70] = (u8)f;
  if ((u8)f) return;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 w = vcall<u32>(tbl, 0x114, 0x6859f4u, 0u, 0x685834u, 0x671u) & 0xffff;
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *t = vcall<u8 *>(tbl, 0x138);
  u32 tmp = 0;
  vcall<void>(t, 0x88, 0x685a0cu, (u32)&tmp);
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 v = vcall<u32>(tbl, 0x4c, (u32)self);
  vcall<void>(self, 0x12c, tmp, w, v);
}
PCREG(464460, fn464460);

// 0x476b50, thiscall(a, b, c, + four unused) ret 0x1c, returns the object: [this+0x60]--; obj = engine table slot 0x58([this+0x68][[this+0x60]]); the counter reloads from [this+0x5c] at zero. When
// obj: a->slot0x288(obj, 0, 1), obj->slot0x74(b, c), obj->slot0x2c(), obj->slot0x138(word [this+0x70], 0, 0). Returns obj.
static u32 THISCALL fn476b50(u8 *self, u8 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
  (void)d; (void)e; (void)f; (void)g;
  *(u32 *)(self + 0x60) -= 1;
  u32 idx = *(u32 *)(self + 0x60);
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 *arr = *(u32 **)(self + 0x68);
  u8 *obj = vcall<u8 *>(tbl, 0x58, arr[idx]);
  if (*(u32 *)(self + 0x60) == 0) *(u32 *)(self + 0x60) = *(u32 *)(self + 0x5c);
  if (obj) {
    vcall<void>(a, 0x288, (u32)obj, 0u, 1u);
    vcall<void>(obj, 0x74, b, c);
    vcall<void>(obj, 0x2c);
    vcall<void>(obj, 0x138, (u32)(self[0x70] | self[0x71] << 8), 0u, 0u);
  }
  return (u32)obj;
}
PCREG(476b50, fn476b50);
