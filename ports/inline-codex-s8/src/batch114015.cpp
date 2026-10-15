#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
extern "C" s32 ext_405ee0(void *,s32,void *);extern "C" u32 ext_410f10(void *);
typedef u32 (*Decode409)(void *,void *,u32,u32,u32);
static u32 decode4096e0(u8 *s,u8 *a,u32 *outputs,s32 channels,s32 mode,u32 **classes,Decode409 decode,u32 *positions) {
 u8 *config=(u8 *)U(U(U(s,64),4),28),*header=(u8 *)U(a,0),*book=(u8 *)U(a,20);
 s32 stride=U(header,8),dimension=U(book,0),num=((s32)(U(header,4)-U(header,0)))/stride;
 s32 layer=mode?(s32)U(config,0xfe4+mode*4):0,end=U(config,0xfe8+mode*4);
 for(;layer<end;layer++) {
  s32 pos=0;u32 stamp=0;u32 *times=positions?positions+layer*16:0;
  while(pos<num) {
   if(!layer)for(s32 c=0;c<channels;c++) {
    s32 value=classes[c][pos];for(s32 j=1;j<dimension;j++){value*=U(header,12);if(pos+j<num)value+=classes[c][pos+j];}
    if(value<(s32)U(book,4))U(a,40)+=ext_405ee0(book,value,s+4);
   }
   for(s32 j=0;j<dimension && pos<num;j++,pos++) {
    u32 offset=pos*stride+U(header,0);
    if(times)while(pos>=(s32)U(a,48+stamp*4)){times[stamp]=ext_410f10(s+4);stamp++;}
    for(s32 c=0;c<channels;c++) {
     u32 type=classes[c][pos];
     if((U(header,20+type*4)&(1u<<(layer&31)))) {
      u32 data=U(U(U(a,24),type*4),layer*4);
      if(data)U(a,36)+=decode(s+4,(void *)(outputs[c]+offset*4),stride,data,0);
     }
    }
   }
   if(times)while(pos>=(s32)U(a,48+stamp*4)){times[stamp]=ext_410f10(s+4);stamp++;}
  }
 }
 return 0;
}
PCREG(4096e0,decode4096e0);
