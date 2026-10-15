#include "ff.h"
extern "C" void* ext_401820(void*,u32);
static u32** transform(void*allocator,u8*ctx,u32**columns,s32 channels,u32(*fn)(u32*,u32,void*,u32,u32)){
 auto d=*(u32**)ctx;s32 stride=d[2],rows=(s32)(d[1]-d[0])/stride;u32 tag=d[3];auto output=(u32**)ext_401820(allocator,channels*4);
 for(s32 c=0;c<channels;++c){output[c]=(u32*)ext_401820(allocator,rows*4);for(s32 i=0;i<rows;++i)output[c][i]=0;}
 for(s32 row=0;row<rows;++row)for(s32 c=0;c<channels;++c)output[c][row]=fn(columns[c]+d[0]+row*stride,stride,ctx,tag,row);
 ++*(u32*)(ctx+0x2c);return output;
}
PCREG(409400,transform);
