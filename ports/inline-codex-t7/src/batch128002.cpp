#include "ff.h"
extern "C" u8 *ext_41e290(u32);
extern "C" u32 ext_42ac56(u8*,u32,...);
extern "C" u8 *THISCALL ext_4cc1d0(u8*);
extern "C" void ext_634273(void*,u32);
static inline u8 *fs2(){return G(u8*,0x700394);}
static inline u32 w2(u8*p,u32 o){return *(u32*)(p+o);}
static inline u32 len2(u8*p){u32 n=0;while(p[n])++n;return n;}
static inline u8 *find2(u8*p,u32 ch){return (*(u8* (**)(u8*,u32))0x676254)(p,ch);}
static inline int cmp2(u8*p,u8*q,u32 n){return (*(int (**)(u8*,u8*,u32))0x67640c)(p,q,n);}
static inline void wr2(u32 f,u8*p,u32 n){vcall<void>(fs2(),0x38,f,p,n);}
static u8 THISCALL rewriteSettings(u8*self){
 if(self[0x6b])return 1;
 u8*path=ext_4cc1d0(self+0x1997);
 if(*path!=0x40)return 0;
 ++path;
 if(!vcall<u8>(fs2(),0x34,path,0u))return 0;
 u32 size=vcall<u32>(fs2(),0x30,path,0u);
 u8*data=ext_41e290(size+1);
 vcall<void>(fs2(),0x60,path,data,size,0u,0u);data[size]=0;
 u8*log=vcall<u8*>(G(void*,0x700390),0x20,0x677fb4u,0xa4bu);
 ((void(*)(u8*,u32,u8*))(*(u32*)(*(u8**)log+0x2c)))(log,0x6784cc,path);
 u32 file=vcall<u32>(fs2(),0x14,path);
 u32 out1=0,out2=0;void*sub=*(void**)(self+0x190f);
 vcall<void>(sub,0x1cc,&out1);vcall<void>(sub,0x1d4,7u,&out2);
 u8 local[64];for(u32 i=0;i<64;++i)local[i]=0xcc;
 u8 *b4=local,*b0=local+12,*b3=local+28,*b2=local+40,*b1=local+52;
 u8 window=self[0x63];
 ext_42ac56(b0,0x6784ec,w2(self,0x6f),w2(self,0x73));
 ext_42ac56(b1,0x6784f4,w2(self,0x7f));
 ext_42ac56(b2,0x6784f4,w2(self,0x8f));
 ext_42ac56(b3,0x6784f4,w2(self,0x93));
 ext_42ac56(b4,0x6784f4,w2(self,0x97));
 u32 names[]={0x678400,0x678308,0x67820c,0x6781c0,0x678358,0x678398};
 u8*values[]={0,b0,*(u8**)(*(u8**)(self+0x1aa3)+4),b1,b2,b3};
 u8 flags[]={window,0,0,0,0,0};
 u8*cur=data;
 while(cur && *cur){
  u8*next=find2(cur,10);if(!next)next=find2(cur,13);if(next)++next;else next=cur+len2(cur);
  bool matched=false;
  for(u32 i=0;i<6;++i){if(!cmp2(cur,(u8*)names[i],len2((u8*)names[i]))){
   matched=true;
   if(!flags[i]){
    flags[i]=1;u8 buf[256];u32 n;
    if(values[i])n=ext_42ac56(buf,0x6784f8,names[i],values[i]);else n=ext_42ac56(buf,0x678500,names[i]);
    wr2(file,buf,n);break;
   }
  }}
  if(!matched)wr2(file,cur,(u32)(next-cur));
  cur=next;
 }
 for(u32 i=0;i<6;++i)if(!flags[i]){
  flags[i]=1;u8 buf[256];u32 n;
  if(values[i])n=ext_42ac56(buf,0x6784f8,names[i],values[i]);else n=ext_42ac56(buf,0x678500,names[i]);
  wr2(file,buf,n);
 }
 vcall<void>(fs2(),0x1c,file);ext_634273(data,1);return 1;
}
PCREG(4239c0,rewriteSettings);
