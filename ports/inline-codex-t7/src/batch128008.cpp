#include "ff.h"
extern "C" void THISCALL ext_4d0c70(void*,void*,u32);
extern "C" void THISCALL ext_4d0b10(void*);
extern "C" void THISCALL ext_4d0950(void*,void*);
extern "C" u8* THISCALL ext_4d0630(void*);
static inline u32 &w9(u8*p,u32 o=0){return *(u32*)(p+o);}
static void assert9(){((void(*)())G(u32,0x7003b0))();}
static void THISCALL release9(u8*self,u8*user){
 u8*block=user-16;--w9(self,0x20b);u32 size=0-w9(block,8);
 u32 base=w9(self,0x20f),offset=(u32)block-base;
 if(base!=0xffffffff && offset<(w9(self,0x8217)<<13)){
  u32 end=offset+size+16,limit=w9(self,0x8217)*0x1fff;
  if(end>limit)end=limit;
  u32 first=offset/w9(self,0x8217),last=end/w9(self,0x8217);
  for(u32 i=first+1;(s32)i<(s32)(last-1);++i){
   w9(self,0x217+i*4)-=w9(self,0x8217);if((u16)w9(self,0x217+i*4))assert9();
  }
  if(first!=last){w9(self,0x217+first*4)+=offset-w9(self,0x8217)*(first+1);w9(self,0x217+last*4)+=w9(self,0x8217)*last-end;}
  else w9(self,0x217+first*4)+=offset-end;
 }
 if((s32)size<0)assert9();
 if(w9(block,12)==0xffffffff){(*(void(**)(u32))0x6762ec)(w9(block,0xfffffffc));return;}
 w9(self)+=0xfffffff0-size;w9(block,8)=size;
 u32 before=w9(block,12);u32 magnitude=(s32)before<0?0-before:before;
 u8*prev=magnitude?block-magnitude-16:0;
 u8*next=block+size+16;
 if(w9(next,12)!=0-size)assert9();
 if(prev && w9(prev,8)!=w9(block,12)){
  void*log=vcall<void*>(G(void*,0x700390),0x20,0x695dc0u,0x34fu);
  ((void(*)(void*,u32))(*(u32*)(*(u8**)log+0x2c)))(log,0x695e78);assert9();
 }
 if((s32)w9(block,12)>0){
  if(!prev)assert9();if(w9(prev,8)!=w9(block,12))assert9();
  ext_4d0c70(self,prev,0);block=prev;size+=w9(prev,8)+16;w9(prev,8)=size;
 }
 u8*tail=next;u32 after=w9(next,8);w9(next,12)=size;
 if((s32)after>0){
  ext_4d0c70(self,next,0);size+=w9(next,8)+16;tail=block+size+16;w9(tail,12)=size;
 }
 w9(block,8)=size;
 u8*page=block-16;
 if(page!=(u8*)w9(self,0x20f) && !w9(block,12) && !w9(tail,8)){
  u8*left=*(u8**)page;u8*right=*(u8**)(page+4);
  if(left)w9(left,4)=(u32)right;else w9(self,0x8220)=(u32)right;
  if(right)w9(right)=(u32)left;
  --w9(self,0x8224);w9(self,4)+=0xffffffd0-w9(block,8);
  u32 cached=w9(self,0x1c8);
  if(cached==11){ext_4d0b10(page);ext_4d0950(self,page);--w9(self,0x207);}
  else {w9(self,8+cached*4)=(u32)page;++w9(self,0x1c8);}
  return;
 }
 void*tree=self+0x1cc;u8*node=vcall<u8*>(tree,8,size,0u);
 if(!node){node=ext_4d0630(self);w9(node,12)=size;w9(node,17)=0;vcall<void>(tree,0,node);}
 w9(block,16)=0;w9(block,20)=w9(node,17);w9(node,17)=(u32)block;
 if(w9(block,20))w9((u8*)w9(block,20),16)=(u32)block;
}
PCREG(4cfdb0,release9);
