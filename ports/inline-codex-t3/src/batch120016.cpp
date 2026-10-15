#include "ff.h"
struct CGameStats {u32 w[8];};
extern "C" u8 *THISCALL ext_589c20(u8 *,s8);
extern "C" u32 THISCALL ext_59b6d0(u8 *);
extern "C" void THISCALL ext_59cc60(u8 *);
extern "C" void THISCALL ext_59ce70(u8 *);
extern "C" void THISCALL ext_59cbc0(u8 *);
extern "C" void THISCALL ext_5ae020(u8 *);
extern "C" void THISCALL ext_59ce00(u8 *);
extern "C" void THISCALL ext_597fc0(u8 *,u32,u32);
extern "C" void THISCALL ext_59b120(u8 *,u32);
extern "C" void THISCALL ext_5ab020(u8 *,CGameStats);
static inline u8 *sysi() {return G(u8 *,0x70039c);}
static inline u8 *mgr() {return *(u8 **)(sysi()+0x9b);}
static inline bool comiss_ge(float a,float b) {return a>=b;}
extern "C" void ext_633910();
static inline u32 crt_ftoll_lo(float f) {
  u32 lo;
  asm volatile("call ext_633910"
               : "=a"(lo), "+Yz"(f)
               :
               : "ecx", "edx", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  return lo;
}

static void THISCALL lcFrameUpdate(u8 *lc) {
  if (lc[0x103b]) {
    if (lc[0x103c]) {
      ext_59cc60(lc);
    } else if (!lc[0x103f]) {
      ext_5ae020(lc + 0x57);
      if (!lc[0x103e]) {
        u8 *osd = ext_589c20(G(u8 *, 0x7003b8), 0);
        u32 sz = ext_59b6d0(lc);
        CGameStats s = *(CGameStats *)(lc + 0x46f + sz * 32);
        ext_5ab020(*(u8 **)(osd + 0x1d0f), s);
      }
    }
    if (lc[0x103e])
      ext_59ce00(lc);
    if (lc[0x4a] == '2' && lc[0x4b] == 'R') {
      u8 *osd = ext_589c20(G(u8 *, 0x7003b8), 0);
      if (osd)
        ext_597fc0(osd, 0x25, 0);
    }
    lc[0x103b] = 0;
  }
  if (lc[0x103c] && *(u32 *)(lc + 0x132c7)) {
    u8 *in = *(u8 **)(sysi() + 0x1907);
    if (vcall<u8, u32, u32>(in, 0x2c, *(u32 *)(lc + 0x132bb), 0))
      ext_59ce70(lc);
  }
  ext_59cbc0(lc);
  vcall<void>(mgr(), 0xb8);
  float f = *(float *)(lc + 0x1060);
  if (comiss_ge(f, 0.0f)) {
    ext_59b120(lc, crt_ftoll_lo(f));
    *(u32 *)(lc + 0x1060) = 0xbf800000u;
  }
}
PCREG(59b1c0, lcFrameUpdate);
