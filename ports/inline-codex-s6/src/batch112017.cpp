#include "ff.h"
extern "C" void ext_620cb0(void*,void*,u32,u32);
extern "C" u32 ext_620180(void*,void*,u32,u32);
extern "C" u32 ext_6206e0(void*);
extern "C" void ext_6200d0(void*);
extern "C" void ext_6204a0(void*);
static u32 parse(u8*ctx,u8*encoding,u32 start,u32 finish){
 if(!*(u32*)(ctx+0x40)){if(*(u32*)(ctx+0x50))ext_620cb0(ctx,encoding,start,finish);return 1;}
 typedef u32(*Convert)(void*,u32);u32 n=*(u32*)(encoding+0x44)*2;start+=n;u32 end=(*(Convert*)(encoding+0x20))(encoding,start)+start;u8*scratch=ctx+0x22c;
 if(!ext_620180(scratch,encoding,start,end))return 0;
 if(*(u32*)(scratch+12)==*(u32*)(scratch+8)&&!ext_6206e0(scratch))return 0;
 **(u8**)(scratch+12)=0;++*(u32*)(scratch+12);auto first=*(void**)(scratch+16);if(!first)return 0;
 *(u32*)(ctx+0x23c)=*(u32*)(ctx+0x238);finish-=n;start=(*(Convert*)(encoding+0x24))(encoding,end);
 if(!ext_620180(scratch,encoding,start,finish))return 0;
 if(*(u32*)(scratch+12)==*(u32*)(scratch+8)&&!ext_6206e0(scratch))return 0;
 **(u8**)(scratch+12)=0;++*(u32*)(scratch+12);auto second=*(void**)(scratch+16);if(!second)return 0;
 ext_6200d0(second);typedef void(*Notify)(u32,void*,void*);(*(Notify*)(ctx+0x40))(*(u32*)(ctx+4),first,second);ext_6204a0(scratch);return 1;
}
PCREG(620d50,parse);
