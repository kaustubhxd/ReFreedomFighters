// batch807.cpp - animation layer thread, batch 807: ZTARGET / ZIKHAND save-load and ZIKHAND::AttachItem.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

struct PMF { u32 w[4]; };

// ZTARGET::Save(ZSaveGame* s, const ZIKLNKOBJ* obj) [high, GC 8017bb08]. Save-stream vtable: +0x60 byte, +0x70 matrix,
// +0x68 vec3, +0x4c float, +0x3c dword. The callback is saved as an id: obj->vt[0x3bc](callback) (0 = none).
// Returns false (AL = 0).
static bool THISCALL ZTARGET_Save(u8 *t, void *s, void *obj) {
  vcall<void>(s, 0x60, (u32)F8(t, 0));
  vcall<void>(s, 0x70, t + 1);
  vcall<void>(s, 0x68, t + 0x25);
  vcall<void>(s, 0x4c, FF(t, 0x31));
  vcall<void>(s, 0x4c, FF(t, 0x35));
  vcall<void>(s, 0x3c, F32(t, 0x39));
  u32 id = 0;
  if (F32(t, 0x3d) != 0) id = vcall<u32>(obj, 0x3bc, *(PMF *)(t + 0x3d));
  vcall<void>(s, 0x3c, id);
  return false;
}
PCREG(467850, ZTARGET_Save);

// ZTARGET::Load(ZLoadGame* l, const ZIKLNKOBJ* obj) [high, GC 8017bbcc]. Load-stream vtable: +0x68 byte*, +0x74 matrix,
// +0x6c vec3, +0x50 float*, +0x40 dword*. The callback id is turned back into a member-function pointer by
// obj->vt[0x3c0] (returns the 16-byte struct through a hidden pointer). Returns false.
static bool THISCALL ZTARGET_Load(u8 *t, void *l, void *obj) {
  vcall<void>(l, 0x68, t);
  vcall<void>(l, 0x74, t + 1);
  vcall<void>(l, 0x6c, t + 0x25);
  vcall<void>(l, 0x50, t + 0x31);
  vcall<void>(l, 0x50, t + 0x35);
  vcall<void>(l, 0x40, t + 0x39);
  u32 id;
  vcall<void>(l, 0x40, &id);
  PMF tmp;
  PMF *p = vcall<PMF *>(obj, 0x3c0, &tmp, id);
  *(PMF *)(t + 0x3d) = *p;
  return false;
}
PCREG(466eb0, ZTARGET_Load);

// ZIKHAND::Save / Load [high, GC 80187914 / 80187988]: the target, then 5 bytes at +0x51 (item id + attached flag
// +0x55) and 12 bytes at +0x5a (item offset) through stream vt +0x10 (save) / +0x18 (load). Return true.
extern "C" bool THISCALL ext_467850(void *t, void *s, void *obj);
extern "C" bool THISCALL ext_466eb0(void *t, void *l, void *obj);
static bool THISCALL ZIKHAND_Save(u8 *self, void *s, void *obj) {
  ext_467850(self + 4, s, obj);
  vcall<void>(s, 0x10, self + 0x51, 5);
  vcall<void>(s, 0x10, self + 0x5a, 0xc);
  return true;
}
PCREG(475380, ZIKHAND_Save);
static bool THISCALL ZIKHAND_Load(u8 *self, void *l, void *obj) {
  ext_466eb0(self + 4, l, obj);
  vcall<void>(l, 0x18, self + 0x51, 5);
  vcall<void>(l, 0x18, self + 0x5a, 0xc);
  return true;
}
PCREG(474730, ZIKHAND_Load);

// ZIKHAND::AttachItem(ZIKLNKOBJ* obj, unsigned itemId) [medium, GC 80187c24; the string names it]. Returns the
// previous item id (+0x51). Same id again: logs "NOTIFY: ZIKHAND::AttachItem tried to attach same item twice!"
// (zlnkwhands.cpp line 0x4d) and changes nothing. Item lookup: [[0x70039c]+0x9b]->vt[0x58](id).
//   Attach (id resolves): flag +0x55 = 1; item->vt[0x2f0](scene->vt[0x4c](obj, scene+0xadc, 1)); obj->vt[0x290](
//   item geom, bone, 0, offset) where bone = dword +0x56 and the offset is (0, -4, 0) only for bone 0x11; the item
//   geom stops drawing itself (SetOwnerDraw(1): drawn with its owner).
//   Detach (0 or unknown id): if the old item resolves, obj->vt[0x294](geom, bone), SetOwnerDraw(0), PlaceItem
//   (leave it where the hand was), flag +0x55 = 0, new id 0.
//   Both end with obj->vt[0x128](word +0x66, id or 2, 0).
extern "C" void THISCALL ext_4dcbb0(void *geom, u32 on);           // ZBaseGeom::SetOwnerDraw
extern "C" void THISCALL ext_474eb0(void *self, void *obj, void *item);  // ZIKHAND::PlaceItem (batch 806)
static u32 THISCALL ZIKHAND_AttachItem(u8 *self, void *obj, u32 id) {
  if (id && id == F32(self, 0x51)) {
    void *sink = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x68961c, 0x4d);
    typedef void(__attribute__((cdecl)) * pf)(void *, const char *);
    (*(pf *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x689684);
    return F32(self, 0x51);
  }
  u32 a, newid;
  u8 *it = vcall<u8 *>(FP(G(u8 *, 0x70039c), 0x9b), 0x58, id);
  if (it) {
    F8(self, 0x55) = 1;
    u8 *ivt = *(u8 **)it;
    u8 *sc = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
    u32 x = vcall<u32>(sc, 0x4c, obj, F32(sc, 0xadc), 1);
    (*(void(THISCALL **)(void *, u32))(ivt + 0x2f0))(it, x);
    u32 bone = F32(self, 0x56);
    u8 *ovt = *(u8 **)obj;
    typedef void(THISCALL * att_t)(void *, void *, u32, u32, float *);
    if (bone == 0x11) {
      float off[3] = {0.0f, bitsf(0xc0800000), 0.0f};
      (*(att_t *)(ovt + 0x290))(obj, FP(it, 8), 0x11, 0, off);
    } else {
      (*(att_t *)(ovt + 0x290))(obj, FP(it, 8), bone, 0, 0);
    }
    ext_4dcbb0(FP(it, 8), 1);
    newid = id;
    a = id ? id : 2;
  } else {
    u8 *old = vcall<u8 *>(FP(G(u8 *, 0x70039c), 0x9b), 0x58, F32(self, 0x51));
    if (!old) return 0;
    vcall<void>(obj, 0x294, FP(old, 8), F32(self, 0x56));
    ext_4dcbb0(FP(old, 8), 0);
    ext_474eb0(self, obj, old);
    F8(self, 0x55) = 0;
    newid = 0;
    a = 2;
  }
  vcall<void>(obj, 0x128, (u32)F16(self, 0x66), a, 0);
  u32 prev = F32(self, 0x51);
  F32(self, 0x51) = newid;
  return prev;
}
PCREG(472280, ZIKHAND_AttachItem);
