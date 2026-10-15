#include "ff.h"
static void stamp(u8*me,u32 index,u32 amount){auto cell=(u32*)(me+0x217+index*4);*cell+=amount;*(u16*)((u8*)cell+2)=0;*cell|=*(u32*)(me+0x213)<<16;}
static void THISCALL mark(u8*me,u32 address,u32 size){
 u32 base=*(u32*)(me+0x20f);if(base==0xffffffff)return;u32 offset=address-base,gran=*(u32*)(me+0x8217);u32 finish=size+16+offset;if(offset>=gran*0x2000)return;u32 max=gran*0x1fff;if(finish>max)finish=max;u32 first=offset/gran,last=finish/gran;
 for(u32 i=first+1;(s32)i<(s32)(last-1);++i){auto cell=(u32*)(me+0x217+4*i);*cell+=gran;if((u16)*cell!=*(u32*)(me+0x8217)){typedef void(*A)();auto a=G(A,0x7003b0);if(a)a();else asm volatile("int3");}*(u16*)((u8*)cell+2)=0;*cell|=*(u32*)(me+0x213)<<16;}
 if(first!=last){stamp(me,first,gran*(first+1)-offset);stamp(me,last,finish-gran*last);}else stamp(me,first,finish-offset);
}
PCREG(4d09b0,mark);
