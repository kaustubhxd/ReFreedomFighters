#include "ff.h"
extern "C" void THISCALL ext_64ba70(void*,void*);
extern "C" void THISCALL ext_63e480(void*,void*);
static void THISCALL drain(u8*me,u32 delay,s32 limit){
 u32 w=*(u32*)(me+0x268),r=*(u32*)(me+0x26c);u32 count=w<r?0x2000-((s32)(r-w)>>2):((s32)(w-r)>>2);
 u32 local[5]={0x6c2784,0,0,0,0};
 u64 deadline=vcall<u64>(G(void*,0x70039c),0x1c8,(u32)0x6c265c,0x2db)+delay;
 for(;;){
 if(delay&&count<=0x800&&vcall<u64>(G(void*,0x70039c),0x1c8,(u32)0x6c265c,0x2dc)>=deadline)return;
 u8*res=*(u32*)(me+0x26c)==*(u32*)(me+0x268)?nullptr:**(u8***)(me+0x26c);
 if(res&&!(res[5]&1)&&*(s32*)res>limit)return;
 r=*(u32*)(me+0x26c);if(r==*(u32*)(me+0x268))return;
 r+=4;if(r==(u32)me+0x8270)r=(u32)me+0x270;*(u32*)(me+0x26c)=r;--count;
 if(!res)continue;*(u16*)(res+6)=0xffff;if(res[5]&1)continue;
 auto item=vcall<u8*>(local,0x2c,res);u8 type=item[1];
 if(type)ext_64ba70(*(void**)(me+0x68+4*type),res);else ext_63e480(me,res);
 }
}
PCREG(63cc50,drain);
