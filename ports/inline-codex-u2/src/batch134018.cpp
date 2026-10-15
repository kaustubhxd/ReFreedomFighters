#include "ff.h"
extern "C" void ext_4043a0(void*,u32,float,u32,u32,u32,float);
static void fn4042c0(u8* s,const u32* table,const float* scores,const float* limits,void* context,float bias){
 s32 n=G(s32,s);float delta=(float)((long double)G(float,G(u8*,s+4)+0x760)-(long double)bias);
 const s32* ids=G(s32*,s+0x18);
 for(s32 i=0;i<n;++i){
  s32 id=ids[i];float best=scores[i];
  while(i+1<n&&ids[i+1]==id){++i;if(!(best>=scores[i]))best=scores[i];}
  if((long double)best+(long double)G(float,0x6be088)>(long double)limits[i]){
   s32 bucket=id>>(G(u32,s+0x24)&31);if(bucket>=17)bucket=16;else if(bucket<0)bucket=0;
   ext_4043a0(context,table[bucket],best,(u32)ids[i]-G(u32,s+0x20),G(u32,s+0x2c),G(u32,s+0x28),delta);
  }
 }
}
PCREG(4042c0,fn4042c0);
