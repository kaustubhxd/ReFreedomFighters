// fb1010.cpp - fresh slice 17, batch 10.
#include "ff.h"

extern "C" u32 THISCALL ext_48c4b0(void *db, char *out, const char *name);    // ZEngineDataBase::CalcCacheFileName
extern "C" const char *THISCALL ext_4cc1d0(char *str);                        // MYSTR c_str (mov eax, [ecx])
extern "C" u32 THISCALL ext_4cbec0(char *str);                                // MYSTR::~MYSTR
extern "C" u32 THISCALL ext_5ec090(void *spr, u32 w, u32 h);                  // CSprite3D::Resize
extern "C" u32 THISCALL ext_5ed1e0(void *spr, u32 ex, u32 ey, s32 x, s32 y, u32 c); // CSprite2D::SetPositionScreen
extern "C" void *ext_45c4f0(u32 size, u32 pool);
extern "C" void *ext_45c4b0(u32 size);
extern "C" u32 THISCALL ext_44c930(void *self, u32 a, u32 b, u32 c);
extern "C" u32 THISCALL ext_5f4940(void *proc, u32 name);                     // Process_t::getCodeAddrOffset
extern "C" u32 THISCALL ext_5fa220(void *buf, u32 obj);                       // OpaqueObjectSerialBuffer_t::getOpaqueObjectIndex
extern "C" u32 THISCALL ext_469870(void *self);
extern "C" u32 THISCALL ext_4dd8d0(void *geom);                               // ZBaseGeom::WantCameraMsg
extern "C" const char *FASTCALL ext_4cc5a0(s32 n);                            // InsertSpace(int)
extern "C" void *THISCALL ext_6014a0(void *self, u32 size);                   // CHostInterface::alloc
extern "C" u32 THISCALL ext_54f870(void *self, void *p, u32 size);

typedef void (*logfn)(void *, const char *, ...);
typedef void (*voidfn)();
#define g_pAssertHook G(voidfn, 0x7003b0)

// 0x490a90 ZEngineDataBase::GetRoomColiTreeData(void* buf, unsigned size): name = CalcCacheFileName(".." 0x68d830) into a
// local MYSTR, then the file system (0x700394) slot +0x60(name, buf, size, 0, 0); the MYSTR is destroyed. The return
// value is whatever ~MYSTR left in eax, so the port returns nothing. SEH frame and /GS cookie not reproduced.
static void THISCALL getRoomColiTreeData490a90(void *self, u32 buf, u32 size) {
  char s[0x80];
  ext_48c4b0(self, s, (const char *)0x68d830);
  void *fs = G(void *, 0x700394);
  u8 *vt = *(u8 **)fs;
  const char *name = ext_4cc1d0(s);
  typedef u32(THISCALL * rd)(void *, const char *, u32, u32, u32, u32);
  (*(rd *)(vt + 0x60))(G(void *, 0x700394), name, buf, size, 0, 0);
  ext_4cbec0(s);
}
PCREG(490a90, getRoomColiTreeData490a90);

// 0x4267d0 ZSysFileGC::Create(const char* name): CreateFileA(name, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, NORMAL, 0); on
// failure the system message for GetLastError() is formatted into a 0x100 buffer and logged (0x6789ac line 0xc6, text
// 0x678b18, name, message), returns 0. /GS cookie not reproduced.
typedef u32(STDCALL *createfile_t)(const char *, u32, u32, void *, u32, u32, u32);
typedef u32(STDCALL *getlasterror_t)();
typedef u32(STDCALL *formatmessage_t)(u32, void *, u32, u32, char *, u32, void *);
static u32 THISCALL create4267d0(void *, const char *name) {
  u32 h = (*(createfile_t *)0x676068)(name, 0x40000000u, 0, 0, 2, 0x80, 0);
  if (h != 0xffffffffu)
    return h;
  char msg[0x100];
  u32 err = (*(getlasterror_t *)0x67609c)();
  (*(formatmessage_t *)0x6760ec)(0x1000, 0, err, 0, msg, 0x100, 0);
  void *log = (void *)vcall<u32>(G(void *, 0x700390), 0x20, 0x6789acu, 0xc6u);
  (*(logfn *)(*(u8 **)log + 0x2c))(log, (const char *)0x678b18, name, msg);
  return 0;
}
PCREG(4267d0, create4267d0);

// 0x434f10 ZSysFile::PrintBigFiles(): walks the big-file list at this+4 (slot +0x4c(iter) starts, slot +0x64(iter) returns
// the next entry pointer or 0). For each entry e = *node: e->slot +0x14(0x67a58c) picks the log line (0x67a4ec line 0x213,
// text 0x67a594, or line 0x215, text 0x67a5ac) printed with e+0xd.
static void THISCALL printBigFiles434f10(u8 *self) {
  u32 it[3];
  void *lst = *(void **)(self + 4);
  if (!lst)
    return;
  vcall<u32>(lst, 0x4c, it);
  u8 **node = vcall<u8 **>(*(void **)(self + 4), 0x64, it);
  while (node) {
    u8 *e = *node;
    u8 hit = vcall<u8>(e, 0x14, 0x67a58cu);
    void *log;
    if (hit) {
      log = (void *)vcall<u32>(G(void *, 0x700390), 0x20, 0x67a4ecu, 0x213u);
      (*(logfn *)(*(u8 **)log + 0x2c))(log, (const char *)0x67a594, *(u32 *)(e + 0xd));
    } else {
      log = (void *)vcall<u32>(G(void *, 0x700390), 0x20, 0x67a4ecu, 0x215u);
      (*(logfn *)(*(u8 **)log + 0x2c))(log, (const char *)0x67a5ac, *(u32 *)(e + 0xd));
    }
    node = vcall<u8 **>(*(void **)(self + 4), 0x64, it);
  }
}
PCREG(434f10, printBigFiles434f10);

// 0x5aab10 (GUESS HUD gauge SetScale(float)): stores the value at +0x42c, marks both sprites (+0x474, +0x478) dirty (+0x35),
// n = ftoui(v * 120) (0x633910, SSE float -> unsigned), sprite 0x478 Resize(n, 8) and SetPositionScreen(3, 2,
// (int)((120 - (float)n) * -0.5), 0x63, -1).
static u32 ftoui633910(float f) {
  u32 r;
  asm volatile("movss %1, %%xmm0\n\tcall *%2" : "=a"(r) : "m"(f), "r"(0x633910u)
               : "ecx", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  return r;
}
static void THISCALL setScale5aab10(u8 *self, float v) {
  *(float *)(self + 0x42c) = v;
  (*(u8 **)(self + 0x474))[0x35] = 1;
  (*(u8 **)(self + 0x478))[0x35] = 1;
  u32 n = ftoui633910(*(volatile float *)(self + 0x42c) * G(float, 0x68c74c));
  ext_5ec090(*(void **)(self + 0x478), n, 8);
  float d = (float)(double)n;
  float x = (G(float, 0x68c74c) - d) * G(float, 0x67a6b0);
  ext_5ed1e0(*(void **)(self + 0x478), 3, 2, (s32)x, 0x63, 0xffffffffu);
}
PCREG(5aab10, setScale5aab10);

// 0x64da90 ZDrawArray<ZPrimInstViewEntry,...>::Remove(entry): count (+0xc) - 1; blk = slot +0x2c(entry); clears entry flag
// 0x02 (+5), pushes the entry's slot on the block free list (entry word = blk+2, blk+2 = slot index (entry-blk-0x10)>>5) and
// drops the block use count (byte 0). An empty block is unlinked from the ring (+8 next, +0xc prev; this+8 moves on or
// becomes 0) and released with slot +0x34(blk); otherwise a block that is not already the ring head moves to the head.
static void THISCALL remove64da90(u8 *self, u8 *ent) {
  *(u32 *)(self + 0xc) -= 1;
  u8 *blk = vcall<u8 *>(self, 0x2c, ent);
  ent[5] &= 0xfd;
  blk[0] -= 1;
  *(u16 *)ent = *(u16 *)(blk + 2);
  *(u16 *)(blk + 2) = (u16)((s32)(ent - blk - 0x10) >> 5);
  if (blk[0] == 0) {
    if (*(u8 **)(self + 8) == blk) {
      u8 *n = *(u8 **)(blk + 8);
      *(u8 **)(self + 8) = n == blk ? 0 : n;
    }
    *(u32 *)(*(u8 **)(blk + 8) + 0xc) = *(u32 *)(blk + 0xc);
    *(u32 *)(*(u8 **)(blk + 0xc) + 8) = *(u32 *)(blk + 8);
    vcall<u32>(self, 0x34, blk);
    return;
  }
  if (blk == *(u8 **)(self + 8))
    return;
  *(u32 *)(*(u8 **)(blk + 8) + 0xc) = *(u32 *)(blk + 0xc);
  *(u32 *)(*(u8 **)(blk + 0xc) + 8) = *(u32 *)(blk + 8);
  u8 *h = *(u8 **)(self + 8);
  *(u8 **)(blk + 8) = h;
  u8 *t = *(u8 **)(h + 0xc);
  *(u8 **)(blk + 0xc) = t;
  *(u8 **)(t + 8) = blk;
  *(u8 **)(h + 0xc) = blk;
  *(u8 **)(self + 8) = blk;
}
PCREG(64da90, remove64da90);

// 0x44cc50 (GUESS factory, fastcall (a, b) + stack (c, pool)): 0x1348 bytes from 0x45c4f0(0x1348, pool) or, without a pool,
// 0x45c4b0(0x1348); null -> 0; else 0x44c930(p, c, a, b). SEH frame not reproduced.
static u32 FASTCALL create44cc50(u32 a, u32 b, u32 c, u32 pool) {
  void *p = pool ? ext_45c4f0(0x1348, pool) : ext_45c4b0(0x1348);
  if (!p)
    return 0;
  return ext_44c930(p, c, a, b);
}
PCREG(44cc50, create44cc50);

// 0x605a10 StackData_t::toSerial(SerialInfo_t& out, OpaqueObjectSerialBuffer_t& opq, Process_t* proc): writes the type byte
// (+4) with out.slot +0x2c, then the value (+0): 1 -> slot +0x30(int), 2 -> slot +0x38(float), 3 -> slot
// +0x2c(proc->getCodeAddrOffset(value)) (no process -> assert hook, int3 when none), 4 -> slot
// +0x2c(opq.getOpaqueObjectIndex(value)).
static void THISCALL toSerial605a10(u8 *self, void *out, void *opq, void *proc) {
  vcall<u32>(out, 0x2c, (u32)self[4]);
  switch (self[4]) {
  case 1:
    vcall<u32>(out, 0x30, *(u32 *)self);
    return;
  case 2:
    vcall<u32>(out, 0x38, *(float *)self);
    return;
  case 3:
    if (!proc) {
      if (!g_pAssertHook)
        __builtin_debugtrap();
      g_pAssertHook();
      return;
    }
    vcall<u32>(out, 0x2c, ext_5f4940(proc, *(u32 *)self));
    return;
  case 4:
    vcall<u32>(out, 0x2c, ext_5fa220(opq, *(u32 *)self));
    return;
  }
}
PCREG(605a10, toSerial605a10);

// 0x5bc1d0 ZFFCareTaker_C03B::ZFFCareTaker_C03B(): (null this -> 0) base ctor 0x469870, flags (+4) |= 0x20, +0x44 = 0,
// vtable 0x6b2e08, event id (+0x48, word) = engine db RegisterZMsg(0x6b2ec4, 0, 0x6b2e8c, 0x13). SEH frame not reproduced.
static u8 *THISCALL ctorC03B5bc1d0(u8 *self) {
  if (!self)
    return 0;
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b2e08;
  void *db = *(void **)(G(u8 *, 0x70039c) + 0x9b);
  *(u16 *)(self + 0x48) = (u16)vcall<u32>(db, 0x114, 0x6b2ec4u, 0u, 0x6b2e8cu, 0x13u);
  return self;
}
PCREG(5bc1d0, ctorC03B5bc1d0);

// 0x63ef90 ZDrawBase::LightEnter(ZLightDrawEntry* l): a slot index (+6, word) other than 0xffff clears this+0x270[idx]
// and resets to 0xffff; flag 0x01 (+5) set; l[0] = engine +0x3c; l added to the list at +0x204 (slot +8(&l)). Its geometry
// (+0x38): when WantCameraMsg and geom+0x54 is set, geom+0x54 slot +0x130(itself, 0x401, 0). Lights with geom flags
// 0x40040000 (+0x3c) or geom+0x54 byte +0x18 bit 0x10 also go to the list at +0x1b4.
static void THISCALL lightEnter63ef90(u8 *self, u8 *l) {
  u16 idx = *(u16 *)(l + 6);
  if (idx != 0xffff) {
    *(u16 *)(l + 6) = 0xffff;
    *(u32 *)(self + idx * 4 + 0x270) = 0;
  }
  l[5] |= 1;
  *(u32 *)l = *(u32 *)(G(u8 *, 0x70039c) + 0x3c);
  vcall<u32>(self + 0x204, 8, &l);
  u8 *g = *(u8 **)(l + 0x38);
  if (ext_4dd8d0(g) & 0xff) {
    void *m = *(void **)(g + 0x54);
    if (m)
      vcall<u32>(m, 0x130, m, 0x401u, 0u);
  }
  if ((*(u32 *)(g + 0x3c) & 0x40040000u) || ((*(u8 **)(g + 0x54))[0x18] & 0x10)) {
    u8 *p = l;
    vcall<u32>(self + 0x1b4, 8, &p);
  }
}
PCREG(63ef90, lightEnter63ef90);

// 0x4f0ad0 ZWINOBJ::PrintStatus(int indent, int) const: state text from the window flags (+8 -> +0x3c & 0xc00: 0x400
// 0x68dd0c, 0x800 0x69850c, 0xc00 0x698518, else 0x677b5a), logged (0x697b1c line 0x686, text 0x69852c) with
// InsertSpace(indent), **(this+0xc), the name (+4, or 0x67c8e8 when none), window +0x24 and the state text.
static void THISCALL printStatus4f0ad0(u8 *self, s32 indent, u32) {
  const char *st = (const char *)0x677b5a;
  switch (*(u32 *)(*(u8 **)(self + 8) + 0x3c) & 0xc00) {
  case 0x400:
    st = (const char *)0x68dd0c;
    break;
  case 0x800:
    st = (const char *)0x69850c;
    break;
  case 0xc00:
    st = (const char *)0x698518;
    break;
  }
  void *log = (void *)vcall<u32>(G(void *, 0x700390), 0x20, 0x697b1cu, 0x686u);
  u8 *w = *(u8 **)(self + 8) + 0x24;
  const char *name = *(const char **)(self + 4) ? *(const char **)(self + 4) : (const char *)0x67c8e8;
  u32 v = **(u32 **)(self + 0xc);
  logfn f = *(logfn *)(*(u8 **)log + 0x2c);
  (*f)(log, (const char *)0x69852c, ext_4cc5a0(indent), v, name, w, st);
}
PCREG(4f0ad0, printStatus4f0ad0);

// 0x607310 (GUESS vector<4-byte>::reserve(n)): begin +0, end +4, capacity end +8. When capacity < n: new block
// (CHostInterface::alloc(n*4), none when n == 0), elements copied, old block freed with 0x54f870(old, cap*4) when the
// capacity was non-zero, pointers rebuilt.
static void THISCALL reserve607310(u32 *self, u32 n) {
  u32 b = self[0];
  if ((u32)((s32)(self[2] - b) >> 2) >= n)
    return;
  u32 e = self[1];
  s32 cnt = (s32)(e - b) >> 2;
  u32 *p = n ? (u32 *)ext_6014a0(self, n * 4) : 0;
  for (s32 i = 0; i < cnt; i++)
    p[i] = ((u32 *)b)[i];
  u32 cap = (u32)((s32)(self[2] - self[0]) >> 2);
  if (cap)
    ext_54f870(self, (void *)self[0], cap * 4);
  self[0] = (u32)p;
  self[1] = (u32)(p + cnt);
  self[2] = (u32)(p + n);
}
PCREG(607310, reserve607310);
