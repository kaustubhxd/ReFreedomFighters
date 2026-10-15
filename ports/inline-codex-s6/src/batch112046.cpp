#include "ff.h"
extern "C" void* ext_401820(void*,u32);
static u32* transform(void*allocator,u8*ctx,u32**columns,s32 channels,u32(*fn)(u32*,u32,void*,u32,u32)){
 auto d=*(u32**)ctx;s32 span=d[1]-d[0],stride=d[2],rows=span/stride;u32 tag=d[3];auto out=(u32*)ext_401820(allocator,4);u32 bytes=((s32)((u32)span*(u32)channels)/stride)*4;auto values=(u32*)ext_401820(allocator,bytes);*out=(u32)values;for(u32 i=0;i<bytes;++i)((u8*)values)[i]=0;
 u32 scratch[stride];u32 item=d[0];s32 channel=0;for(s32 row=0;row<rows;++row){for(s32 j=0;j<stride;++j){scratch[j]=columns[channel][item];++channel;if(channel>=channels){channel=0;++item;}}values[row]=fn(scratch,stride,ctx,tag,row);}
 ++*(u32*)(ctx+0x2c);return out;
}
PCREG(409fc0,transform);
