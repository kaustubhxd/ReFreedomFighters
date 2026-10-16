#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V5)(void *, u32, u32, u32, u32, u32);
typedef u32(THISCALL *V8)(void *, u32, u32, u32, u32, u32, u32, u32, u32);
typedef u32(THISCALL *V10)(void *, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void THISCALL ext_4dae60(void *self);
extern "C" void THISCALL ext_4de7a0(void *obj);
extern "C" void THISCALL ext_4db600(void *self, void *m, void *o);
extern "C" void THISCALL ext_4d9970(void *self, void *a, void *b, u32 count);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x4d9f90: thiscall(), void, /GS protected, large frame (arrays of 0x200 / 0x200 / 0x1000 / 0x1000 bytes, __chkstk by the original). When this[0x3c] has none of the bits 0x200c00
// it asks the table-object chain R = ([[0x70039c]+0x9b]+8) slot 0x5c(u16 this[0x5c]) for a preferred id esi (= R[0x18], or R[0] when R[0x18] == 0 and byte R[0x1c] != 0) and edi = R[0x18]; M = a
// matrix built by 0x4de7a0 and 0x4db600(this, &M, &O) with O = this_f[0x30..0x38] and the direction D = this_f[0x40..0x48]. With edi != 0 the hit list arr240 = {edi}, count 1; otherwise
// H = [[0x70039c]+0x1aa3]->[0x1c] slot 0x24(arr240, M, M, O, D) returns the count. The preferred id esi is swapped to the front of the list (once, when found at a nonzero index); H slot 0x28
// (&flag, arr240, M, count, arr2440, arr1440, arr1440, M, O, D) refines it (count c2) and the preferred id is swapped to the front again (arr1440 is swapped with it); H slot 0x2c
// (arr440, arr240, M, c2, arr2440, arr1440, arr1440, O) and 0x4d9970(this, arr440, arr240, c2) finish.
extern "C" void THISCALL fn_4d9f90(u8 *self) {
  u32 arr240[128], arr440[128], arr1440[1024], arr2440[1024];
  u8 flag;
  u8 Mbuf[0x24];
  float O[3], D[3];
  if (rd32u(self + 0x3c) & 0x200c00) {
    ext_4dae60(self);
    ext_633654(G(u32, 0x6f5630));
    return;
  }
  u32 dx = *(u16 *)(self + 0x5c);
  u32 esi = 0, edi = 0;
  if (dx != 0) {
    u8 *Tn = (u8 *)rd32u((u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b) + 8);
    u8 *Rr = (u8 *)(*(V1 *)(vt(Tn) + 0x5c))(Tn, dx);
    if (Rr != nullptr) {
      edi = rd32u(Rr + 0x18);
      esi = edi;
      if (edi == 0 && Rr[0x1c] != 0) esi = rd32u(Rr);
    }
  }
  ext_4de7a0(Mbuf);
  O[0] = rdf(self + 0x30);
  O[1] = rdf(self + 0x34);
  O[2] = rdf(self + 0x38);
  D[0] = rdf(self + 0x40);
  D[1] = rdf(self + 0x44);
  D[2] = rdf(self + 0x48);
  ext_4db600(self, Mbuf, O);
  u32 cnt;
  if (edi != 0) {
    arr240[0] = edi;
    cnt = 1;
  } else {
    u8 *H = (u8 *)rd32u((u8 *)rd32u(G(u8 *, 0x70039c) + 0x1aa3) + 0x1c);
    cnt = (*(V5 *)(vt(H) + 0x24))(H, (u32)arr240, (u32)Mbuf, (u32)Mbuf, (u32)O, (u32)D);
    edi = arr240[0];
  }
  if (esi != 0 && cnt != 0) {
    u32 k = 0;
    do {
      if (arr240[k] == esi) {
        if (k != 0) {
          arr240[k] = edi;
          arr240[0] = esi;
          esi = 0;
        }
        break;
      }
      k++;
    } while (k != cnt);
  }
  flag = 0;
  u8 *H2 = (u8 *)rd32u((u8 *)rd32u(G(u8 *, 0x70039c) + 0x1aa3) + 0x1c);
  u32 c2 = (*(V10 *)(vt(H2) + 0x28))(H2, (u32)&flag, (u32)arr240, (u32)Mbuf, cnt, (u32)arr2440, (u32)arr1440, (u32)arr1440, (u32)Mbuf, (u32)O, (u32)D);
  if (esi != 0 && c2 != 0) {
    u32 k = 0;
    do {
      if (arr240[k] == esi) {
        if (k != 0) {
          u32 a = arr240[0];
          u32 b = arr1440[k];
          arr240[k] = a;
          u32 a2 = arr1440[0];
          arr1440[k] = a2;
          arr240[0] = esi;
          arr1440[0] = b;
        }
        break;
      }
      k++;
    } while (k != c2);
  }
  u8 *H3 = (u8 *)rd32u((u8 *)rd32u(G(u8 *, 0x70039c) + 0x1aa3) + 0x1c);
  (*(V8 *)(vt(H3) + 0x2c))(H3, (u32)arr440, (u32)arr240, (u32)Mbuf, c2, (u32)arr2440, (u32)arr1440, (u32)arr1440, (u32)O);
  ext_4d9970(self, arr440, arr240, c2);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(4d9f90, fn_4d9f90);
