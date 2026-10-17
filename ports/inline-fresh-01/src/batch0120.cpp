// batch0120.cpp - fresh-01 batch 20 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u32 arr, u32 i);                 // array element pointer (checked)
extern "C" void *ext_634d10(void *d, s32 v, u32 n);                  // memset thunk
extern "C" void FASTCALL ext_4e09b0(float *v);                       // vneg
extern "C" void FASTCALL ext_633654(u32 cookie);                     // __security_check_cookie
extern "C" float THISCALL ext_4e5e80(void *db);                      // DBREAD::operator float (st0)
extern "C" u32 THISCALL ext_4e5e60(void *db);                        // DBREAD::operator unsigned int
extern "C" void *ext_41e290(u32 size);                               // operator new
extern "C" u32 THISCALL ext_4ccbe0(void *p, u32 a, u32 b);           // REFTAB::REFTAB(int, int)

typedef void (*handlerFn)();
typedef void (*log3Fn)(void *, u32, u32);
typedef void(STDCALL *com3Fn)(void *, u32, void *);
typedef void(STDCALL *com3iFn)(void *, u32, u32);

static u8 *render() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x509b10 (script native, unnamed): v = {element 0 (type 3 value, type 4 value slot 0x34(), else log 0x69c8e0:0x111
// and the handler / int3, 0), element 1 value}; for every item of the +0xc object's +0x18 list (slot 0x4c(&it) starts
// the walk, slot 0x5c(&it) returns the next one while it.word0 != 0) the +0xc object gets SendCommand (slot 0x12c:
// item, RegisterZMsg(0x694c6c, 0, 0x69d214, 0xd0) as u16, &v).
static void THISCALL native509b10(u8 *self, u8 *p) {
  u32 v[2];
  u32 *e = ext_5003d0(*(u32 *)(p + 4), 0);
  u8 ty = *((u8 *)e + 4);
  if (ty == 3) {
    v[0] = *e;
  } else if (ty == 4) {
    v[0] = vcall<u32>(*(u8 **)e, 0x34);
  } else {
    u8 *lg = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x69c8e0u, 0x111u);
    (*(log3Fn *)(*(u8 **)lg + 0x2c))(lg, 0x69c6b0, 0x69c9b0);
    handlerFn h = G(handlerFn, 0x7003b0);
    if (!h) __builtin_debugtrap();
    h();
    v[0] = 0;
  }
  v[1] = *ext_5003d0(*(u32 *)(p + 4), 1);
  u8 *lst = *(u8 **)(*(u8 **)(self + 0xc) + 0x18);
  if (!lst) return;
  u32 it[3];
  vcall<void>(lst, 0x4c, it);
  u32 x = vcall<u32>(*(u8 **)(*(u8 **)(self + 0xc) + 0x18), 0x5c, it);
  while (it[0]) {
    u8 *o = *(u8 **)(self + 0xc);
    u8 *vt = *(u8 **)o;
    u16 id = vcall<u16>(render(), 0x114, 0x694c6cu, 0u, 0x69d214u, 0xd0u);
    (*(void(THISCALL **)(void *, u32, u32, u32 *))(vt + 0x12c))(*(u8 **)(self + 0xc), x, id, v);
    x = vcall<u32>(*(u8 **)(*(u8 **)(self + 0xc) + 0x18), 0x5c, it);
  }
}
PCREG(509b10, native509b10);

// 0x611710 (stdcall, unnamed): sets the three directional lights of the D3D device at [0x724a00] from the 3 x 32-byte
// records (direction +0, colour +0x10): a record with a black colour (all of +0x10..+0x18 == 0) is disabled (slot
// 0xb8(i, 0)) unless it is light 2; others get a D3DLIGHT9 (type 3, diffuse = colour, light 2 also ambient = +0x60,
// direction = -dir) via slot 0xb0 and slot 0xb8(i, 1). Light 3 is disabled. The light struct is cleared once and
// reused. /GS cookie.
static void STDCALL setLights611710(u8 *rec) {
  u32 L[0x1a];
  ext_634d10(L, 0, 0x68);
  L[0] = 3;
  u32 i = 0;
  for (; i < 3; i++) {
    u8 *r = rec + i * 32;
    if (*(float *)(r + 0x10) == 0.0f && *(float *)(r + 0x14) == 0.0f && *(float *)(r + 0x18) == 0.0f && i != 2) {
      u8 *dev = G(u8 *, 0x724a00);
      (*(com3iFn *)(*(u8 **)dev + 0xb8))(dev, i, 0);
      continue;
    }
    __builtin_memcpy(&L[1], r + 0x10, 16);
    if (i == 2) __builtin_memcpy(&L[9], rec + 0x60, 16);
    L[0x10] = *(u32 *)(r + 0);
    L[0x11] = *(u32 *)(r + 4);
    L[0x12] = *(u32 *)(r + 8);
    ext_4e09b0((float *)&L[0x10]);
    u8 *dev = G(u8 *, 0x724a00);
    (*(com3Fn *)(*(u8 **)dev + 0xb0))(dev, i, L);
    dev = G(u8 *, 0x724a00);
    (*(com3iFn *)(*(u8 **)dev + 0xb8))(dev, i, 1);
  }
  for (; i < 4; i++) {
    u8 *dev = G(u8 *, 0x724a00);
    (*(com3iFn *)(*(u8 **)dev + 0xb8))(dev, i, 0);
  }
  ext_633654(G(u32, 0x6f5630));
}
PCREG(611710, setLights611710);

// 0x4bb050, CWaves::Init(ZGEOM*, DBREAD&): reads 9 floats (a, +0x50, b, +0x58..+0x6c) and a uint (+0x70); +0x54 =
// 2pi / b, +0x4c = 2pi / (a * 100); +0x48 = new REFTAB(8, 8) (0 when new fails); then own slot 0x94(+0x44). The
// geom argument is unused. SEH frame without cleanups.
static void THISCALL wavesInit(u8 *self, u32, void *db) {
  float a = ext_4e5e80(db);
  *(float *)(self + 0x50) = ext_4e5e80(db);
  float b = ext_4e5e80(db);
  *(float *)(self + 0x58) = ext_4e5e80(db);
  *(float *)(self + 0x5c) = ext_4e5e80(db);
  *(float *)(self + 0x60) = ext_4e5e80(db);
  *(float *)(self + 0x64) = ext_4e5e80(db);
  *(float *)(self + 0x68) = ext_4e5e80(db);
  *(float *)(self + 0x6c) = ext_4e5e80(db);
  *(u32 *)(self + 0x70) = ext_4e5e60(db);
  const float twoPi = G(float, 0x68aef8);
  *(float *)(self + 0x54) = twoPi / b;
  *(float *)(self + 0x4c) = twoPi / (a * G(float, 0x67cd40));
  void *p = ext_41e290(0x1c);
  *(u32 *)(self + 0x48) = p ? ext_4ccbe0(p, 8, 8) : 0;
  vcall<void>(self, 0x94, *(u32 *)(self + 0x44));
}
PCREG(4bb050, wavesInit);
