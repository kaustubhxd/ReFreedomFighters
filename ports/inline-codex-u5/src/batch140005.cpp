#include "ff.h"
struct HeapValue {u8 bytes[56];};
extern "C" void FASTCALL ext_4ae160(u8*,s32,s32,HeapValue);
static void copy53(u8* dst,const u8* src){for(int j=0;j<53;++j)dst[j]=src[j];}
extern "C" void FASTCALL heap_build(u8* begin,u8* end,u32 unused1,u32 unused2){
 s32 len=(s32)(end-begin);if(len<106)return;
 s32 n=len/53;
 for(s32 top=(n-2)/2;;--top){
  HeapValue value={};copy53(value.bytes,begin+top*53);
  s32 hole=top,child=top*2+2;
  while(child<n){
   if(*(float*)(begin+(child-1)*53)>*(float*)(begin+child*53))--child;
   copy53(begin+hole*53,begin+child*53);hole=child;child=child*2+2;
  }
  if(child==n){copy53(begin+hole*53,begin+(child-1)*53);hole=child-1;}
  ext_4ae160(begin,hole,top,value);
  if(top==0)break;
 }
}
PCREG(4adf60,heap_build);
