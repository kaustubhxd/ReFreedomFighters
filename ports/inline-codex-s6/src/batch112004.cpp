#include "ff.h"
extern "C" void* ext_634d22(void*,const void*,u32);
static u32 insert(u8*ctx,u8*parent,u32 key,u8*text,u8**list){
 typedef u8*(*Alloc)(u32);typedef u8*(*Realloc)(u8*,u32);typedef void(*Free)(u8*);typedef void(*Notify)(u32,u32,u8*);
 u32 len=0;while(text[len])++len;if(ctx[0x268])++len;
 u8*node=*(u8**)(ctx+0x210);
 if(node){
 if((s32)len>*(s32*)(node+0x18)){auto p=(*(Realloc*)(ctx+0x10))(*(u8**)(node+0x10),len+0x18);*(u8**)(node+0x10)=p;if(!p)return 0;*(u32*)(node+0x18)=len+0x18;}
 *(u8**)(ctx+0x210)=*(u8**)(node+4);
 }else{
 node=(*(Alloc*)(ctx+0xc))(0x1c);if(!node)return 0;
 auto p=(*(Alloc*)(ctx+0xc))(len+0x18);*(u8**)(node+0x10)=p;if(!p){(*(Free*)(ctx+0x14))(node);return 0;}*(u32*)(node+0x18)=len+0x18;
 }
 *(u32*)(node+0x14)=len;ext_634d22(*(u8**)(node+0x10),text,len);
 if(ctx[0x268])(*(u8**)(node+0x10))[len-1]=ctx[0x268];
 *(u8**)node=parent;*(u32*)(node+0xc)=key;*(u32*)(node+8)=*(u32*)(parent+4);
 if(!text[0]&&parent==ctx+0x1dc)*(u32*)(parent+4)=0;else *(u8**)(parent+4)=node;
 *(u8**)(node+4)=*list;*list=node;
 if(*(u32*)(ctx+0x64))(*(Notify*)(ctx+0x64))(*(u32*)(ctx+4),*(u32*)parent,*(u32*)(parent+4)?text:nullptr);
 return 1;
}
PCREG(61c660,insert);
