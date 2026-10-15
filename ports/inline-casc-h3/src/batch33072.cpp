// batch33072.cpp - h3 (Sonnet) batch 33072: tier C wrappers (stack-frame tricks, memcpy, big stack buffer)
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634d22(void *dst, const void *src, u32 n);   // memcpy through the IAT
extern "C" u32 *THISCALL ext_5003d0(u8 *self, u32 a);               // ret 4
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 a);                // ret 4
extern "C" u32 THISCALL ext_53a9e0(u8 *self);
extern "C" u32 THISCALL ext_4cc5f0(u8 *self);
extern "C" u32 THISCALL ext_4235b0(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e);   // ret 0x14
extern "C" u32 THISCALL ext_422ba0(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e);   // ret 0x14
extern "C" u32 THISCALL ext_4e5330(u8 *self);
extern "C" void THISCALL ext_5f2d60(u8 *self, u32 a, u32 b);        // ret 8

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))

// 0x4717f0: thiscall(a, mask) ret 8: for i<7 while mask: if (mask&1) { p=[this+0x70]->slot 4(i); *p = table->slot 0x4c(a) }; mask >>= 1 (arithmetic)
static void THISCALL fn4717f0(u8 *self, u32 a, s32 mask) {
  u32 i = 0;
  do {
    if (mask & 1) {
      u32 *p = vcall<u32 *>(*(u8 **)(self + 0x70), 4, i);
      u32 r = vcall<u32>(SYS_TABLE, 0x4c, a);
      *p = r;
    }
    mask >>= 1;
    if (mask == 0) break;
    i++;
  } while (i != 7);
}
PCREG(4717f0, fn4717f0);

// 0x4d2d90: thiscall(a, b) ret 8: e=this->slot 0xb0(a, 0); !e -> 0; flag bit1 of [[e+4]+0x10] clear -> global log slot 0x24(g,str,a); memcpy(b, e+[e]+0xc, [e+8]); returns [e+8]
typedef u32 (__attribute__((cdecl)) *log3_t)(u8 *, u32, u32);
static u32 THISCALL fn4d2d90(u8 *self, u32 a, u8 *b) {
  u8 *e = vcall<u8 *>(self, 0xb0, a, 0u);
  if (!e) return 0;
  u8 *x = *(u8 **)(e + 4);
  if (!(x[0x10] & 2)) {
    u8 *g = G(u8 *, 0x700390);
    (*(log3_t *)(*(u8 **)g + 0x24))(g, 0x696394, a);
  }
  ext_634d22(b, e + *(u32 *)e + 0xc, *(u32 *)(e + 8));
  return *(u32 *)(e + 8);
}
PCREG(4d2d90, fn4d2d90);

// 0x4f7fe0: thiscall: p=slot 0x2c4(); x=table->slot 0x58([this+0x60]); y=slot 0x368(x); table->slot 0x4c(this, &slot{y}, y); p->slot 0x2dc(0x10000)
static void THISCALL fn4f7fe0(u8 *self) {
  u8 *p = vcall<u8 *>(self, 0x2c4);
  u32 x = vcall<u32>(SYS_TABLE, 0x58, *(u32 *)(self + 0x60));
  u32 y = vcall<u32>(self, 0x368, x);
  u32 slot = y;
  vcall<u32>(SYS_TABLE, 0x4c, (u32)self, (u32)&slot, y);
  vcall<u32>(p, 0x2dc, 0x10000u);
}
PCREG(4f7fe0, fn4f7fe0);

// 0x5004a0: stdcall(a,b,c) ret 0xc: r=a->slot 0x18(b); !r -> 0; e=r->slot 0x4c(); 0x5002f0(0x5003d0(e,0), c[0]); 0x5002f0(0x5003d0(e,1), c[1]); returns r
static u8 *STDCALL fn5004a0(u8 *a, u32 b, u32 *c) {
  u8 *r = vcall<u8 *>(a, 0x18, b);
  if (!r) return 0;
  u8 *e = vcall<u8 *>(r, 0x4c);
  u32 *p0 = ext_5003d0(e, 0);
  ext_5002f0((u8 *)p0, c[0]);
  u32 *p1 = ext_5003d0(e, 1);
  ext_5002f0((u8 *)p1, c[1]);
  return r;
}
PCREG(5004a0, fn5004a0);

// 0x534da0: thiscall(a,b,c,d,e,f) ret 0x18 bool: c && o=[this+0x52fa] (unaligned): s=0x53a9e0(o); fills s from c, table->slot 0x4c(a), e, f and the 3 dwords at b; returns 1
static u32 THISCALL fn534da0(u8 *self, u32 a, u32 *b, u32 c, u32 d, u32 e, u32 f) {
  if (c == 0) return 1;
  u8 *o = *(u8 **)(self + 0x52fa);
  if (!o) return 1;
  u8 *s = (u8 *)ext_53a9e0(o);
  *(u32 *)s = c;
  u32 r = vcall<u32>(SYS_TABLE, 0x4c, a);
  *(u32 *)(s + 0x18) = r;
  *(u32 *)(s + 4) = e;
  *(u32 *)(s + 8) = f;
  *(u32 *)(s + 0xc) = b[0];
  *(u32 *)(s + 0x10) = b[1];
  *(u32 *)(s + 0x14) = b[2];
  return 1;
}
PCREG(534da0, fn534da0);

// 0x5f2f10: thiscall(a) ret 4 (stack cookie, 0x2714-byte buffer): [this+0x15]->slot 0x64(buf); 0x5f2d60(a, buf, buf+strlen(buf))
static void THISCALL fn5f2f10(u8 *self, u8 *a) {
  u8 buf[0x2714];
  vcall<u32>(*(u8 **)(self + 0x15), 0x64, (u32)buf);
  u32 n = 0;
  while (buf[n]) n++;
  ext_5f2d60(a, (u32)buf, (u32)buf + n);
}
PCREG(5f2f10, fn5f2f10);

// 0x422e60: thiscall(a..e) ret 0x14: 0x4cc5f0(this+0x255b) ? tail 0x4235b0 : 0x4cc5f0(this+0x23db) ? tail 0x422ba0 : 0
static u32 THISCALL fn422e60(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e) {
  if (ext_4cc5f0(self + 0x255b)) return ext_4235b0(self, a, b, c, d, e);
  if (ext_4cc5f0(self + 0x23db)) return ext_422ba0(self, a, b, c, d, e);
  return 0;
}
PCREG(422e60, fn422e60);

// 0x461fa0: thiscall(a) ret 4: [this+0x5c]=[this+0x60]=0; for each of [a+0x5c] / [a+0x60] set: x=0x4e5330(that); [this+0x5c/0x60] = old vtable[0x2f4](x, this+0x64/0x68)
static void THISCALL fn461fa0(u8 *self, u8 *a) {
  *(u32 *)(self + 0x5c) = 0;
  *(u32 *)(self + 0x60) = 0;
  u8 *c1 = *(u8 **)(a + 0x5c);
  if (c1) {
    u8 *vt = *(u8 **)self;
    u32 x = ext_4e5330(c1);
    u32 r = ((u32(THISCALL *)(u8 *, u32, u32)) * (u32 *)(vt + 0x2f4))(self, x, (u32)(self + 0x64));
    *(u32 *)(self + 0x5c) = r;
  }
  u8 *c2 = *(u8 **)(a + 0x60);
  if (c2) {
    u8 *vt = *(u8 **)self;
    u32 x = ext_4e5330(c2);
    u32 r = ((u32(THISCALL *)(u8 *, u32, u32)) * (u32 *)(vt + 0x2f4))(self, x, (u32)(self + 0x68));
    *(u32 *)(self + 0x60) = r;
  }
}
PCREG(461fa0, fn461fa0);
