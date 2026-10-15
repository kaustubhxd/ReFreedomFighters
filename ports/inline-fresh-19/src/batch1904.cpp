// batch1904.cpp - fresh slice 19, batch 1904 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);                 // sized operator delete (cdecl; hooked)
extern "C" void THISCALL ext_4cbec0(u8 *s);                    // MYSTR::~MYSTR (hooked)
extern "C" void THISCALL ext_42bae0(u8 *self);                 // base destructor (hooked)
extern "C" void THISCALL ext_4ef210(u8 *self, u8 *g);          // ZWINOBJ::CopyData (hooked)
extern "C" bool THISCALL ext_63b2c0(u8 *self);                 // ZDrawArray block grow (hooked)
extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 i);            // parameter array element (hooked)
extern "C" void THISCALL ext_500360(u8 *p, float v);           // set float parameter (hooked)
extern "C" void THISCALL ext_5002f0(u8 *p, u32 v);             // set int parameter (hooked)
extern "C" void THISCALL ext_561020(u8 *self);                 // CBaseWindow::CBaseWindow (hooked)
extern "C" void THISCALL ext_4dc600(u8 *g, float *v);          // ZBaseGeom::SetCen (hooked)
extern "C" void THISCALL ext_4dd060(u8 *g, float *v);          // (no GC name; hooked)
extern "C" double VECTORCALL ext_634d7c(double x);             // sqrt thunk (jmp [0x676330]), runs as exe code
extern "C" void THISCALL ext_4dce50(u8 *g, float r);           // ZBaseGeom::SetRadius (hooked)
extern "C" void *ext_41e290(u32 n);                            // operator new (cdecl; hooked)
extern "C" void THISCALL ext_5577d0(u8 *self);                 // (no GC name; hooked)
extern "C" void THISCALL ext_4a90b0(u8 *self, u8 *g);          // ZSIGTE::InitPointer (verified in batch1903; runs as exe code)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

// 0x42a7b0 (no GC name) scalar deleting destructor (flags) ret 4: six MYSTR members (+0x1e0b down to +0x1b71), the base
// destructor 0x42bae0, flag 1 frees 0x1e8b bytes; returns this.
static u8 *THISCALL sdtor_42a7b0(u8 *self, u32 f) {
  ext_4cbec0(self + 0x1e0b);
  ext_4cbec0(self + 0x1d71);
  ext_4cbec0(self + 0x1cf1);
  ext_4cbec0(self + 0x1c71);
  ext_4cbec0(self + 0x1bf1);
  ext_4cbec0(self + 0x1b71);
  ext_42bae0(self);
  if (f & 1) ext_634273(self, 0x1e8b);
  return self;
}
PCREG(42a7b0, sdtor_42a7b0);

// 0x4f50f0 ZFRAME::CopyData(const ZGEOM *g) ret 4: ZWINOBJ::CopyData(g); when g->vt[0x1e0](0x200045) (is a frame) copies
// +0x93..+0xb7, +0xbb and +0xbf (+0xb7 is not copied).
static void THISCALL copyData_4f50f0(u8 *self, u8 *g) {
  ext_4ef210(self, g);
  if (!vcall<bool>(g, 0x1e0, 0x200045u)) return;
  for (u32 o = 0x93; o < 0xb7; o += 4) *(u32 *)(self + o) = *(u32 *)(g + o);
  *(u32 *)(self + 0xbb) = *(u32 *)(g + 0xbb);
  *(u32 *)(self + 0xbf) = *(u32 *)(g + 0xbf);
}
PCREG(4f50f0, copyData_4f50f0);

// 0x63ad70 ZDrawArray<ZDrawResource, ZDrawResource, ZArrayBlock>::Add(): finds a block with a free entry (word +2 not
// 0xffff), walking the ring from the current block (+8, advanced as it goes) until it wraps or hits 0; none: grow
// (0x63b2c0) and use the new current block, or return 0. Counts +0xc, pops the free entry (8 bytes at block + 16 +
// 8 * index; its word 0 is the next free index), clears it (dword 0 = 0, byte 5 = 0x12, word 6 = 0xffff), counts byte 0
// of the block and returns the entry. An index of 0xffff after the count returns 0.
static u8 *THISCALL add_63ad70(u8 *self) {
  u8 *start = *(u8 **)(self + 8);
  u8 *b = 0;
  if (start) {
    for (;;) {
      u8 *c = *(u8 **)(self + 8);
      if (*(u16 *)(c + 2) != 0xffff) {
        b = c;
        break;
      }
      c = *(u8 **)(c + 8);
      *(u8 **)(self + 8) = c;
      if (start == c || !c) break;
    }
  }
  if (!b) {
    if (!ext_63b2c0(self)) return 0;
    b = *(u8 **)(self + 8);
  }
  (*(u32 *)(self + 0xc))++;
  u32 i = *(u16 *)(b + 2);
  if (i == 0xffff) return 0;
  u8 *e = b + (i + 2) * 8;
  *(u16 *)(b + 2) = *(u16 *)e;
  *(u32 *)e = 0;
  e[5] = 0x12;
  *(u16 *)(e + 6) = 0xffff;
  b[0]++;
  return e;
}
PCREG(63ad70, add_63ad70);

// 0x4f3f70 ZWINDOW::OnWindowClose(unsigned, bool) ret 8: w = vt[0x2c4]()->vt[0x2f0]() (the focus window); when this
// window is w or one of its parents (vt[0x20] walks up), vt[0x2c4]()->vt[0x2f4](w, 0). Always vt[0xbc](1); returns 0.
static bool THISCALL onWindowClose_4f3f70(u8 *self, u32, u32) {
  u8 *w = vcall<u8 *>(vcall<u8 *>(self, 0x2c4), 0x2f0);
  if (w) {
    u8 *x = w;
    while (x != self) {
      x = vcall<u8 *>(x, 0x20);
      if (!x) {
        vcall<void>(self, 0xbc, 1u);
        return false;
      }
    }
    vcall<void>(vcall<u8 *>(self, 0x2c4), 0x2f4, (u32)w, 0u);
  }
  vcall<void>(self, 0xbc, 1u);
  return false;
}
PCREG(4f3f70, onWindowClose_4f3f70);

// 0x551670 Signature_fii_EventTranslator_t::handleEventTranslation(factory, id, data) ret 0xc: ev = factory->vt[0x18](id);
// with an event, its parameter array (vt[0x4c]) gets float data[0] and ints data[1], data[2]; returns ev.
static u8 *THISCALL handleEvent_551670(u8 *self, u8 *factory, u32 id, u32 *data) {
  u8 *ev = vcall<u8 *>(factory, 0x18, id);
  if (!ev) return 0;
  u8 *arr = vcall<u8 *>(ev, 0x4c);
  ext_500360(ext_5003d0(arr, 0), *(float *)data);
  ext_5002f0(ext_5003d0(arr, 1), data[1]);
  ext_5002f0(ext_5003d0(arr, 2), data[2]);
  return ev;
}
PCREG(551670, handleEvent_551670);

// 0x57be70 (no GC name) window factory (no stack args): o = (engine db +8)->vt[0x44](ecx as one stack word: GUESS, the
// exe pushes its incoming ecx and the callee pops it); with o: CBaseWindow ctor, vptr 0x6aa4f4. Returns o. The exe's
// SEH frame and cookie are not ported.
static u8 *THISCALL make_57be70(u8 *self) {
  u8 *o = vcall<u8 *>(*(u8 **)(DB + 8), 0x44, (u32)self);
  if (o) {
    ext_561020(o);
    *(u32 *)o = 0x6aa4f4;
  }
  return o;
}
PCREG(57be70, make_57be70);

// 0x451b30 ZCubeGrid::CalcCenSize(): geom +8: SetCen(+0x24), 0x4dd060(+0x18), then SetRadius(sqrt(x*x + y*y + z*z) +
// [0x678858] (1.0)) from the geom's +0x40/+0x44/+0x48 (float sum, sqrt in double through the CRT).
static void THISCALL calcCenSize_451b30(u8 *self) {
  ext_4dc600(*(u8 **)(self + 8), (float *)(self + 0x24));
  ext_4dd060(*(u8 **)(self + 8), (float *)(self + 0x18));
  u8 *g = *(u8 **)(self + 8);
  float x = *(float *)(g + 0x40), y = *(float *)(g + 0x44), z = *(float *)(g + 0x48);
  float s = x * x + y * y;
  s = s + z * z;
  float r = (float)ext_634d7c((double)s);
  ext_4dce50(g, r + G(float, 0x678858));
}
PCREG(451b30, calcCenSize_451b30);

// 0x509ff0 (no GC name) (unused) ret 4: with a list at (+0xc)->+0x18: it->vt[0x4c](&iter); each id from vt[0x5c](&iter)
// while iter.first != 0: the geom db vt[0x58](id), when found, gets vt[0xbc](0). The list pointer is re-read per call.
static void THISCALL fn_509ff0(u8 *self, u32) {
  u32 it[3];
  u8 *l = *(u8 **)(*(u8 **)(self + 0xc) + 0x18);
  if (!l) return;
  vcall<void>(l, 0x4c, (u32)it);
  u32 id = vcall<u32>(*(u8 **)(*(u8 **)(self + 0xc) + 0x18), 0x5c, (u32)it);
  while (it[0]) {
    u8 *g = vcall<u8 *>(DB, 0x58, id);
    if (g) vcall<void>(g, 0xbc, 0u);
    id = vcall<u32>(*(u8 **)(*(u8 **)(self + 0xc) + 0x18), 0x5c, (u32)it);
  }
}
PCREG(509ff0, fn_509ff0);

// 0x557930 (no GC name) singleton getter: an existing [0x713f04] returns its vt[0x24](); otherwise new(0x28) {vptr 0x6a57a4,
// +4 = 1, +8..+0x14 = 0}, stored at 0x713f04, init 0x5577d0, returns the global.
static u32 THISCALL get_557930(u8 *) {
  u8 *g = G(u8 *, 0x713f04);
  if (g) return vcall<u32>(g, 0x24);
  u8 *o = (u8 *)ext_41e290(0x28);
  if (o) {
    *(u32 *)(o + 4) = 1;
    *(u32 *)(o + 8) = 0;
    *(u32 *)o = 0x6a57a4;
    *(u32 *)(o + 0x14) = 0;
    *(u32 *)(o + 0xc) = 0;
    *(u32 *)(o + 0x10) = 0;
    *(u32 *)(o + 0x14) = 0;
  }
  G(u8 *, 0x713f04) = o;
  ext_5577d0(o);
  return G(u32, 0x713f04);
}
PCREG(557930, get_557930);

// 0x4a9330 ZSIGTE::SetPointer(unsigned id) ret 4: a new id releases the old geom (vt[0xbc](1)), stores the id at +0xbb and
// shows the new geom (vt[0xbc](0)) and InitPointer on it.
static void THISCALL setPointer_4a9330(u8 *self, u32 id) {
  u32 old = *(u32 *)(self + 0xbb);
  if (id == old) return;
  if (old) {
    u8 *g = vcall<u8 *>(DB, 0x58, old);
    if (g) vcall<void>(g, 0xbc, 1u);
  }
  *(u32 *)(self + 0xbb) = id;
  if (!id) return;
  u8 *g = vcall<u8 *>(DB, 0x58, id);
  if (!g) return;
  vcall<void>(g, 0xbc, 0u);
  ext_4a90b0(self, g);
}
PCREG(4a9330, setPointer_4a9330);
