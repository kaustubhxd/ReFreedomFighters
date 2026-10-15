#include "ff.h"
static u8 *FASTCALL partition53(u8 *lo,u8 *hi,u32 p0,u32 p1,u32 p2,u32 p3,u32 p4,u32 p5,u32 p6,u32 p7,u32 p8,u32 p9,u32 p10,u32 p11,u32 p12,u32 p13) {
  float pivot=bitsf(p0);
  for (;;) {
    while (pivot>*(float *)lo) lo+=53;
    do {hi-=53;} while (*(float *)hi>pivot);
    if (lo>=hi) return lo;
    for (u32 k=0;k<53;++k) {u8 t=lo[k];lo[k]=hi[k];hi[k]=t;}
    lo+=53;
  }
}
PCREG(4ae320,partition53);
