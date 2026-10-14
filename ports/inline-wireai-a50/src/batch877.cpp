// batch877.cpp - area 50 (residue-09 file row): 0x49f010 CMsgForwardToActors::Init(ZGEOM*, DBREAD&) [48 instr, thiscall, two stack
// args (ret 8)]. When the flag byte at this+4 has bit 1 set, the three result words (+0x48, +0x4c, +0x50) are cleared. Otherwise two
// words (DBREAD operator unsigned short, 0x4e5e40) go to +0x48 and +0x4a, a float (DBREAD operator float, 0x4e5e80) to +0x4c, and the
// render manager's object (eng+0x9b, +0xadc) gives +0x50 through vt +0x25c(0x685f44, 0). A zero +0x50 prints a line (logger 0x700390,
// file 0x68f6b4, line 0x1aa, format 0x68f6e0) and returns. The DBREAD readers are recorded stubs in the harness (the reads are the
// exe's own sequence, the values come from a generation-time list).
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" u16 THISCALL ext_4e5e40(void *db);     // DBREAD::operator unsigned short() (stood in)
extern "C" float THISCALL ext_4e5e80(void *db);   // DBREAD::operator float() (stood in; st0)

// 0x49f010 (name from the residue file).
static void THISCALL Init49f010(u8 *self, void *geom, void *db) {
  (void)geom;
  if (U8(self, 4) & 2) {
    U32(self, 0x48) = 0;
    U32(self, 0x4c) = 0;
    U32(self, 0x50) = 0;
    return;
  }
  U16(self, 0x48) = ext_4e5e40(db);
  U16(self, 0x4a) = ext_4e5e40(db);
  F32(self, 0x4c) = ext_4e5e80(db);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *mgr = (u8 *)FP(eng, 0x9b);
  U32(self, 0x50) = vcall<u32>(FP(mgr, 0xadc), 0x25c, (u32)0x685f44, 0u);
  if (U32(self, 0x50) == 0) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *sink = vcall<u8 *>(lg, 0x20, (u32)0x68f6b4, 0x1aau);
    typedef void (*printf_t)(void *, const char *);
    (*(printf_t *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x68f6e0);
  }
}
PCREG(49f010, Init49f010);
