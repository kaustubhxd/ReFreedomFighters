// batch0104.cpp - fresh-01 batch 4 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" void THISCALL ext_43fc30(u8 *self, u8 *geom, u32 flag);         // ZGROUP::DetachGeom
extern "C" void THISCALL ext_43de40(u8 *self, u32 info, u32 name, u32 parent);  // ZSTDOBJ::ZSTDOBJ
extern "C" void THISCALL ext_4dbb00(u32 geom, u32 flag);                    // ZBaseGeom::LightNotifyPotentialDetachment
extern "C" void THISCALL ext_45c3e0(u8 *self);                              // ZGEOM destructor body
extern "C" void FASTCALL ext_633654(u32 cookie);                            // __security_check_cookie
extern "C" u32 THISCALL ext_63b160(u8 *block);                              // ZArrayBlock take free entry
extern "C" u8 THISCALL ext_613c20(u8 *self);                                // ZDrawArray grow
extern "C" u8 *THISCALL ext_64d030(u32 view, u32 entry, u32 geom, u32 a, u32 b);  // ZViewBase::OnGeomNotify
extern "C" void FASTCALL ext_4de420(u32 dst, u32 src);                      // mcpy(float*, const float*)

typedef u32(STDCALL *comFn)(void *);
typedef void *(*memcpyFn)(void *, const void *, u32);
typedef void (*handlerFn)();

// 0x54b650 (unnamed, render device teardown): COM object at this+0xa278: slot 0x48 then Release (slot 8), cleared;
// COM object at this+0xa274: Release when set; cleared. COM calls are stdcall with the object as first argument.
static void THISCALL releaseDevice54b650(u8 *self) {
  u8 *o = *(u8 **)(self + 0xa278);
  if (o) {
    (*(comFn *)(*(u8 **)o + 0x48))(o);
    o = *(u8 **)(self + 0xa278);
    (*(comFn *)(*(u8 **)o + 8))(o);
    *(u32 *)(self + 0xa278) = 0;
  }
  o = *(u8 **)(self + 0xa274);
  if (o) (*(comFn *)(*(u8 **)o + 8))(o);
  *(u32 *)(self + 0xa274) = 0;
}
PCREG(54b650, releaseDevice54b650);

// 0x5fb550, ScriptEngine_t::checkValidProcess(Process_t*): true when the process is in the array at this+0x18 (count
// this+0x20). The vector index check before the first read calls the handler at [0x7003b0] (int3 when unset).
static u8 THISCALL scriptCheckValidProcess(u8 *self, u32 p) {
  u32 i = 0;
  if (*(u32 *)(self + 0x20) <= 0) return 0;
  if (!(i < *(u32 *)(self + 0x20))) {
    handlerFn h = G(handlerFn, 0x7003b0);
    if (!h) __builtin_debugtrap();
    else h();
  }
  do {
    if ((*(u32 **)(self + 0x18))[i] == p) return 1;
    i++;
  } while (i < *(u32 *)(self + 0x20));
  return 0;
}
PCREG(5fb550, scriptCheckValidProcess);

// 0x444450, ZROOM::DetachGeom(ZBaseGeom*, bool): ZGROUP::DetachGeom(geom, flag); then when geom+0x54 is set and its
// class (+0xc) has type id 0x200015 at +0x23: this slot 0x35c(render slot 0x50(geom)). The room's vtable is read
// before the render call.
static void THISCALL roomDetachGeom(u8 *self, u8 *geom, u32 flag) {
  ext_43fc30(self, geom, flag);
  u8 *a = *(u8 **)(geom + 0x54);
  if (!a) return;
  if (*(u32 *)(*(u8 **)(a + 0xc) + 0x23) != 0x200015) return;
  u8 *vt = *(u8 **)self;
  u32 r = vcall<u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x50, geom);
  typedef void(THISCALL * f)(void *, u32);
  (*(f *)(vt + 0x35c))(self, r);
}
PCREG(444450, roomDetachGeom);

// 0x573650 (unnamed ZSTDOBJ subclass constructor): ZSTDOBJ(info, name, parent), vtable 0x6a8d30, dwords +0x28, +0x18,
// +0x1c, +0x20, +0x24 = 0. Returns this.
static u8 *THISCALL stdObjSubCtor(u8 *self, u32 info, u32 name, u32 parent) {
  ext_43de40(self, info, name, parent);
  *(u32 *)self = 0x6a8d30;
  *(u32 *)(self + 0x28) = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x20) = 0;
  *(u32 *)(self + 0x24) = 0;
  return self;
}
PCREG(573650, stdObjSubCtor);

// 0x4270d0, ZSysFileGC::GameSize(unsigned int, unsigned int): own slot 0x144(buf, a, b) formats into a 0x400-byte local
// buffer; the buffer goes to [0x700394] slot 0x30(buf, 0). /GS cookie checked on exit (always passes here).
static void THISCALL sysFileGameSize(u8 *self, u32 a, u32 b) {
  char buf[0x400];
  vcall<void>(self, 0x144, (char *)buf, a, b);
  vcall<void>(G(u8 *, 0x700394), 0x30, (char *)buf, 0u);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(4270d0, sysFileGameSize);

// 0x4478d0 (unnamed ZGEOM subclass destructor): vtable 0x67dc30; LightNotifyPotentialDetachment(false) on the geom at
// this+8; ZGEOM destructor body.
static void THISCALL geomSubDtor(u8 *self) {
  *(u32 *)self = 0x67dc30;
  ext_4dbb00(*(u32 *)(self + 8), 0);
  ext_45c3e0(self);
}
PCREG(4478d0, geomSubDtor);

// 0x48d010 (unnamed): walks the list of render([0x70039c]+0x9b)+0xadc (first entry at +8): clears bit 0x100000 of each
// entry's +0x3c; the list's slot 0x50(&cur) advances cur. The list pointer is re-read every step.
static void clearFlag48d010() {
  u8 *cur = *(u8 **)(*(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc) + 8);
  while (cur) {
    *(u32 *)(cur + 0x3c) &= 0xffefffffu;
    vcall<void>(*(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc), 0x50, &cur);
  }
}
PCREG(48d010, clearFlag48d010);

// 0x4d5310, IOFSMemoryAccess_t::nativeRead(void*, unsigned int, ImpNativeFd_t*): the fd must be this+4 (else the handler
// at [0x7003b0], int3 when unset, and its EAX is returned). Copies min(n, end - pos) bytes from data+pos, advances pos.
// Layout at this+4: data, pos, end.
static u32 THISCALL memAccessNativeRead(u8 *self, void *dst, u32 n, u8 *fd) {
  u8 *f = self + 4;
  if (fd != f) {
    typedef u32 (*hFn)();
    hFn h = G(hFn, 0x7003b0);
    if (h) return h();
    __builtin_debugtrap();
  }
  u32 pos = *(u32 *)(f + 4);
  u32 take = *(u32 *)(f + 8) - pos;
  if (n < take) take = n;
  if (take) {
    (*(memcpyFn *)0x67626c)(dst, *(u8 **)f + pos, take);
    *(u32 *)(f + 4) += take;
  }
  return take;
}
PCREG(4d5310, memAccessNativeRead);

// 0x63aed0, ZDrawArray<ZPrimInstDrawEntry, ...>::Add(): looks from the current block (this+8) along the block ring (+8)
// for one whose free index (+2 word) is not 0xffff, moving this+8 as it goes (stops at the start block or null).
// When none has room, grows with 0x613c20 (returns 0 when that fails). Then count (this+0xc)++ and returns the block's
// new entry (0x63b160).
static u32 THISCALL drawArrayAdd(u8 *self) {
  u8 *start = *(u8 **)(self + 8);
  if (start) {
    u8 *b;
    do {
      b = *(u8 **)(self + 8);
      if (*(u16 *)(b + 2) != 0xffff) {
        ++*(u32 *)(self + 0xc);
        return ext_63b160(b);
      }
      b = *(u8 **)(b + 8);
      *(u8 **)(self + 8) = b;
    } while (start != b && b);
  }
  if (!ext_613c20(self)) return 0;
  ++*(u32 *)(self + 0xc);
  return ext_63b160(*(u8 **)(self + 8));
}
PCREG(63aed0, drawArrayAdd);

// 0x65f410, ZDrawBuffer::DrawBaseGeom(ZBaseGeom*, const float* mat, const float* pos, unsigned char): e =
// ZViewBase::OnGeomNotify(view this+0xc, entry this+4, geom, true, false); when e+0xc is set its +0x24..+0x2c = pos[0..2]
// and mcpy(e+0xc, mat); then e+0x16 = the byte unless it is 0xff.
static void THISCALL drawBufferDrawBaseGeom(u8 *self, u32 geom, u32 mat, const u32 *pos, u32 flag) {
  u8 *e = ext_64d030(*(u32 *)(self + 0xc), *(u32 *)(self + 4), geom, 1, 0);
  u8 *d = *(u8 **)(e + 0xc);
  if (d) {
    *(u32 *)(d + 0x24) = pos[0];
    *(u32 *)(d + 0x28) = pos[1];
    *(u32 *)(d + 0x2c) = pos[2];
    ext_4de420(*(u32 *)(e + 0xc), mat);
  }
  u8 b = (u8)flag;
  if (b != 0xff) e[0x16] = b;
}
PCREG(65f410, drawBufferDrawBaseGeom);
