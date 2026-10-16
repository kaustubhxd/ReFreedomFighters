#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V6)(void *, u32, u32, u32, u32, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" double VECTORCALL ext_634d70(double x);  // cos
extern "C" void THISCALL ext_4e09b0(void *b);
extern "C" float FASTCALL ext_4e0830(void *a, void *b);
extern "C" void FASTCALL ext_43e920(void *out, void *b, void *c);
extern "C" long double THISCALL ext_44c840(void *v);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline u8 *eng() { return G(u8 *, 0x70039c); }
static inline void *table() { return (void *)rd32u(eng() + 0x9b); }

// 0x5dfaa0: thiscall() returning 0 in AL, /GS protected: picks the actor in front of this->[8] and sends a request for it. S = [[[0x70039c]+0x9b]+0xadc] slot 0x25c(0x685f44, 0); A / B =
// this[8] slot 0x80(B, A) (B then 0x4e09b0), k = float(cos(double [0x6b7518])). S's list S[0x18] is walked with slot 0x4c(&cnt) once and slot 0x5c(&cnt) per item while cnt != 0: an item is
// resolved through the table slot 0x58; objects other than this[8] whose slot 0x1e0(0x200074) is set and whose point C (their slot 0x84) lies within [0x6aef84] of A (0x4e0830) give D =
// normalize(C - A) (0x43e920, 0x44c840) and are taken when k <= B.D (dot). With a taken item (or when the list is empty / missing, where S itself is used) a request record
// {this[8]'s 0x4c id, 0, C, C.y + [0x68c74c], D, 40.0f} goes through table slot 0x114(0x69eaac, 0, 0x6b74a4, 0x268, &rec, 0) and its u16 result to the item's slot 0x128.
extern "C" u32 THISCALL fn_5dfaa0(u8 *self) {
  float A[3], B[3], C[3], D[3];
  u32 F[11];
  u32 cnt;
  u8 *T0 = (u8 *)table();
  void *K = (void *)rd32u(T0 + 0xadc);
  u8 *S = (u8 *)(*(V2 *)(vt(K) + 0x25c))(K, 0x685f44, 0);
  void *O = (void *)rd32u(self + 8);
  (*(V2 *)(vt(O) + 0x80))(O, (u32)B, (u32)A);
  ext_4e09b0(B);
  float k = (float)ext_634d70(G(double, 0x6b7518));
  u8 *item;
  u8 *Y;
  u8 *L = (u8 *)rd32u(S + 0x18);
  if (!L) {
    item = S;
    Y = S;
  } else {
    (*(V1 *)(vt(L) + 0x4c))(L, (u32)&cnt);
    item = (u8 *)(*(V1 *)(vt(L) + 0x5c))(L, (u32)&cnt);
    if (cnt == 0) {
      Y = S;
    } else {
      for (;;) {
        Y = (u8 *)(*(V1 *)(vt(table()) + 0x58))(table(), (u32)item);
        if ((u8)(*(V1 *)(vt(Y) + 0x1e0))(Y, 0x200074) && (u32)Y != rd32u(self + 8)) {
          C[0] = C[1] = C[2] = 0.0f;
          (*(V1 *)(vt(Y) + 0x84))(Y, (u32)C);
          float d = ext_4e0830(A, C);
          if (!(d > G(float, 0x6aef84))) {
            ext_43e920(D, C, A);
            ext_44c840(D);
            float p1 = B[1] * D[1];
            float p0 = B[0] * D[0];
            p0 = p0 + p1;
            float p2 = B[2] * D[2];
            p0 = p0 + p2;
            if (!(k > p0)) break;
          }
        }
        L = (u8 *)rd32u(S + 0x18);
        item = (u8 *)(*(V1 *)(vt(L) + 0x5c))(L, (u32)&cnt);
        if (cnt == 0) break;
      }
    }
  }
  if (item) {
    u32 r = (*(V1 *)(vt(table()) + 0x4c))(table(), rd32u(self + 8));
    u8 *evt = vt(Y);
    F[1] = 0;
    F[10] = 0x42200000;
    __builtin_memcpy(&F[4], &C[0], 4);
    __builtin_memcpy(&F[6], &C[2], 4);
    __builtin_memcpy(&F[7], &D[0], 4);
    __builtin_memcpy(&F[8], &D[1], 4);
    __builtin_memcpy(&F[9], &D[2], 4);
    float cy = C[1] + G(float, 0x68c74c);
    __builtin_memcpy(&F[5], &cy, 4);
    F[0] = r;
    u32 res = (*(V6 *)(vt(table()) + 0x114))(table(), 0x69eaac, 0, 0x6b74a4, 0x268, (u32)F, 0);
    (*(V1 *)(evt + 0x128))(Y, (u16)res);
  }
  ext_633654(G(u32, 0x6f5630));
  return 0;
}
PCREG(5dfaa0, fn_5dfaa0);
