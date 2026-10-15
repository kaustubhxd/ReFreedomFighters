// batch1104.cpp - fresh-11 batch 4: slice-11 functions of 110 to 119 bytes. Names from the GC name map; GUESS otherwise.
// SEH frames and /GS cookies are not reproduced (stack and fs:[0] only, restored before return).
#include "ff.h"

extern "C" u32 ext_634273(void *p, u32 n);   // __builtin_delete (sized), cdecl
extern "C" void *ext_41e290(u32 n);          // __builtin_new, cdecl
static inline u8 *Eng9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x4fbab0 ZSortCameraList::AddCamera(unsigned int) [medium]: ([this+0x44]+0x18)->slot +4(id); node = new(0x15)
// {id, 0, prev = tail +0x4c, 0, list = this, byte 0}; link after the tail (or as head +0x48); tail = node.
static u8 *THISCALL SortCameraList_AddCamera(u8 *self, u32 id) {
  vcall<void>(*(void **)(*(u8 **)(self + 0x44) + 0x18), 4, id);
  u8 *n = (u8 *)ext_41e290(0x15);
  if (!n) return 0;
  n[0x14] = 0;
  *(u8 **)(n + 0x10) = self;
  *(u32 *)n = id;
  *(u32 *)(n + 4) = 0;
  u8 *tail = *(u8 **)(self + 0x4c);
  *(u8 **)(n + 8) = tail;
  *(u32 *)(n + 0xc) = 0;
  if (tail) *(u8 **)(tail + 0xc) = n;
  else *(u8 **)(self + 0x48) = n;
  *(u8 **)(self + 0x4c) = n;
  return n;
}
PCREG(4fbab0, SortCameraList_AddCamera);

// 0x5ec5f0 CSprite3D::SetPosition(float*, unsigned int) [low]: copy the 3 position dwords into entry idx (stride 0x28)
// of the array at [[this+0x3a]+4], or into every entry (count +0x3e) when idx == -1.
static void THISCALL Sprite3D_SetPosition(u8 *self, u32 *v, u32 idx) {
  if (idx == 0xffffffff) {
    for (u32 i = 0; i < *(u32 *)(self + 0x3e); i++) {
      u32 *e = (u32 *)(*(u8 **)(*(u8 **)(self + 0x3a) + 4) + 0x28 * i);
      e[0] = v[0];
      e[1] = v[1];
      e[2] = v[2];
    }
    return;
  }
  u32 *e = (u32 *)(*(u8 **)(*(u8 **)(self + 0x3a) + 4) + 0x28 * idx);
  e[0] = v[0];
  e[1] = v[1];
  e[2] = v[2];
}
PCREG(5ec5f0, Sprite3D_SetPosition);

// 0x650eb0 ZRender::SetFontSize(const float*) [high]: both sizes must be > 0 (NaN passes), else log (file 0x6c3180 line
// 0x506, msg 0x6c34a8); +0xb5/+0xb9 = sizes; free the cached buffer +0x74 (delete(p, 1)) and clear it.
typedef void *(THISCALL *logopen_t)(void *, u32, u32);
typedef u32 (*logmsg_t)(void *, u32);
static u32 THISCALL Render_SetFontSize(u8 *self, float *sz) {
  if (0.0f >= sz[0] || 0.0f >= sz[1]) {
    void *lg = G(void *, 0x700390);
    void *l2 = (*(logopen_t *)(*(u8 **)lg + 0x20))(lg, 0x6c3180, 0x506);
    return (*(logmsg_t *)(*(u8 **)l2 + 0x2c))(l2, 0x6c34a8);
  }
  *(u32 *)(self + 0xb5) = *(u32 *)&sz[0];
  *(u32 *)(self + 0xb9) = *(u32 *)&sz[1];
  void *p = *(void **)(self + 0x74);
  if (!p) return 0;
  u32 r = ext_634273(p, 1);
  *(u32 *)(self + 0x74) = 0;
  return r;
}
PCREG(650eb0, Render_SetFontSize);

// Shared by the decal constructor and End(): +0x36d0 = 0; word +0x2d0 + 0x68*i = i + 1 for i < 0x7f; last = 0xffff.
static inline void DecalResetFree(u8 *self) {
  u8 *e = self + 0x2d0;
  *(u32 *)(e + 0x3400) = 0;
  for (u32 i = 0; i != 0x7f; i++) {
    *(u16 *)e = (u16)(i + 1);
    e += 0x68;
  }
  *(u16 *)e = 0xffff;
}

// 0x65e0b0 ZGeometryDecal::ZGeometryDecal() [medium]: vtable 0x6c48f4; 16 elements of 12 bytes at +4 built by
// eh_vector_constructor_iterator (ctor 0x65e090, dtor 0x4690b0); +0xcc = 0; free list reset; +0xc8 = 0, +0xc4 = 0x80.
extern "C" void STDCALL ext_634123(void *p, u32 size, u32 n, u32 ctor, u32 dtor);
static u8 *THISCALL GeometryDecal_Ctor(u8 *self) {
  *(u32 *)self = 0x6c48f4;
  ext_634123(self + 4, 0xc, 0x10, 0x65e090, 0x4690b0);
  *(u32 *)(self + 0xcc) = 0;
  DecalResetFree(self);
  *(u32 *)(self + 0xc8) = 0;
  *(u32 *)(self + 0xc4) = 0x80;
  return self;
}
PCREG(65e0b0, GeometryDecal_Ctor);

// 0x65f0f0 ZGeometryDecal::End() [medium]: delete(+4 + 12i, 4) and clear +4/+8 of each of the +0xc8 entries; free list
// reset; +0xcc = +0xc8 = 0. EAX = 0xffff.
static u32 THISCALL GeometryDecal_End(u8 *self) {
  if (*(u32 *)(self + 0xc8)) {
    u32 i = 0;
    u8 *e = self + 4;
    do {
      ext_634273(*(void **)e, 4);
      *(u32 *)e = 0;
      *(u32 *)(e + 4) = 0;
      e += 0xc;
      i++;
    } while (i != *(u32 *)(self + 0xc8));
  }
  DecalResetFree(self);
  *(u32 *)(self + 0xcc) = 0;
  *(u32 *)(self + 0xc8) = 0;
  return 0xffff;
}
PCREG(65f0f0, GeometryDecal_End);

// 0x43ab30 GUESS clear flags of the geoms in the list at +0x19: iterate (slot +0x4c start, slot +0x5c next with a
// 16-byte iterator, stop when its first dword is 0); for each x with [x] == 0: base = x - 4; base+0x2d = 0 (unless it is
// the iterator's last dword), byte +0x32 &= 0x2f, byte +0x33 &= 1.
static void THISCALL ClearFlags43ab30(u8 *self) {
  void *l = *(void **)(self + 0x19);
  if (!l) return;
  u32 it[4];
  vcall<void>(l, 0x4c, it);
  u32 *x = vcall<u32 *>(*(void **)(self + 0x19), 0x5c, it);
  while (it[0]) {
    if (x && *x == 0) {
      u8 *base = (u8 *)x - 4;
      u32 *f = (u32 *)(base + 0x2d);
      if (f != &it[3]) *f = 0;
      base[0x32] &= 0x2f;
      base[0x33] &= 1;
    }
    x = vcall<u32 *>(*(void **)(self + 0x19), 0x5c, it);
  }
}
PCREG(43ab30, ClearFlags43ab30);

// 0x5515f0 Signature_ffi_EventTranslator_t::handleEventTranslation(ScriptEventFactory_t*, unsigned, void*) [low]
// (ECX unused, ret 0xc): ev = factory->slot +0x18(id); args = ev->slot +0x4c(); arg 0/1 = float data[0]/[1]
// (0x500360), arg 2 = dword data[2] (0x5002f0); returns ev.
extern "C" void *THISCALL ext_5003d0(void *arr, u32 i);
extern "C" void THISCALL ext_500360(void *v, u32 fbits);
extern "C" void THISCALL ext_5002f0(void *v, u32 x);
static void *STDCALL HandleEventTranslation(void *factory, u32 id, u32 *data) {
  void *ev = vcall<void *>(factory, 0x18, id);
  if (!ev) return 0;
  void *arr = vcall<void *>(ev, 0x4c);
  ext_500360(ext_5003d0(arr, 0), data[0]);
  ext_500360(ext_5003d0(arr, 1), data[1]);
  ext_5002f0(ext_5003d0(arr, 2), data[2]);
  return ev;
}
PCREG(5515f0, HandleEventTranslation);

// 0x453130 ZGATE::Close() [high]: when +0x5a is set: clear it, +0x21 = 1; for each id in the list at +0x52 (slot +0x4c
// start, +0x5c next, 12-byte iterator): g = eng9b->slot +0x58(id); g ? g->slot +0x228().
static void THISCALL GATE_Close(u8 *self) {
  if (!self[0x5a]) return;
  void *l = *(void **)(self + 0x52);
  self[0x5a] = 0;
  self[0x21] = 1;
  if (!l) return;
  u32 it[3];
  vcall<void>(l, 0x4c, it);
  u32 x = vcall<u32>(*(void **)(self + 0x52), 0x5c, it);
  while (it[0]) {
    void *g = vcall<void *>(Eng9b(), 0x58, x);
    if (g) vcall<void>(g, 0x228);
    x = vcall<u32>(*(void **)(self + 0x52), 0x5c, it);
  }
}
PCREG(453130, GATE_Close);

// 0x4b3170 / 0x4bebb0 / 0x4c6c70 / 0x57a130 GUESS factories: p = ([eng9b+8])->slot +0x44(ECX as passed); when p:
// base ctor 0x469870, flags +4 |= 0x20, +0x44 = 0, vtable; returns p.
extern "C" void THISCALL ext_469870(void *self);
template <u32 VT>
static u8 *THISCALL NewObj469870(u32 arg) {
  u8 *p = vcall<u8 *>(*(void **)(Eng9b() + 8), 0x44, arg);
  if (p) {
    ext_469870(p);
    *(u32 *)(p + 4) |= 0x20;
    *(u32 *)(p + 0x44) = 0;
    *(u32 *)p = VT;
  }
  return p;
}
PCREG(4b3170, NewObj469870<0x691b20>);
PCREG(4bebb0, NewObj469870<0x693564>);
PCREG(4c6c70, NewObj469870<0x6947d4>);
PCREG(57a130, NewObj469870<0x6a9b58>);

// 0x578d30 GUESS ask yes/no: s = [0x70039c]->slot +0x190(); s->slot +0x198 (cdecl)(s, buf, 0x6a9afc, +0x194) formats a
// 64-byte text; eng9b->slot +0x134()->slot +0x90(buf, &answer = 0); returns the answer byte (upper EAX from +0x90).
typedef void (*fmt_t)(void *, char *, u32, u32);
static u32 THISCALL Ask578d30(u8 *self) {
  void *eng = G(void *, 0x70039c);
  void *s = vcall<void *>(eng, 0x190);
  char buf[0x40];
  (*(fmt_t *)(*(u8 **)s + 0x198))(s, buf, 0x6a9afc, *(u32 *)(self + 0x194));
  void *o = vcall<void *>(Eng9b(), 0x134);
  u8 answer = 0;
  u32 r = vcall<u32>(o, 0x90, buf, &answer);
  return (r & 0xffffff00) | answer;
}
PCREG(578d30, Ask578d30);
