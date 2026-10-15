#include "ff.h"
extern "C" s32 ext_405f20(u8*,void*);
static s32 fn405fa0(u8* s,float* out,void* input,s32 count){
 s32 width=G(s32,s);s32 blocks=count/width;
 float** rows=(float**)__builtin_alloca((u32)blocks*4);
 for(s32 i=0;i<blocks;++i){s32 index=ext_405f20(s,input);if(index==-1)return -1;rows[i]=G(float*,s+12)+(u32)width*(u32)index;}
 for(s32 j=0;j<G(s32,s);++j){for(s32 i=0;i<blocks;++i){u32 off=(u32)j*(u32)blocks+(u32)i;out[off]=(float)((long double)rows[i][j]+(long double)out[off]);}}
 return 0;
}
PCREG(405fa0,fn405fa0);
