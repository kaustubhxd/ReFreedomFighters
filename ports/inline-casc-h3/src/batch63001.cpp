#include "ff.h"
extern "C" void THISCALL ext_4c0b00(u8*,u32);
extern "C" void THISCALL ext_432650(u8*);
static u32 THISCALL lookup(u8* s){
 if(!G(u32,s+0xad)) return 0;
 u8* sys=G(u8*,0x70039c); vcall<u32>(G(u8*,sys+0x9b),0x58,G(u32,s+0xad));
 sys=G(u8*,0x70039c); u8* sub=G(u8*,sys+0x1aa3);
 u32 id=vcall<u32>(G(u8*,sub+0x1c),0x74,s+0xa5);
 sub=G(u8*,G(u8*,0x70039c)+0x1aa3);
 u8* p=vcall<u8*>(G(u8*,sub+0x18),0xf8,id);
 if(!p) return 0;
 return vcall<u32>(G(u8*,G(u8*,0x70039c)+0x9b),0x160,(u32)p[2]);
}
PCREG(516250,lookup);
static u8 THISCALL readfields(u8* s,u8* stream){
 G(u32,s+4)&=0xffffffbf;
 vcall<u32>(stream,0x44,s+0x48); vcall<u32>(stream,0x40,s+0x4a);
 vcall<u32>(stream,0x40,s+0x52); vcall<u32>(stream,0x50,s+0x56);
 typedef void(*hook)(); hook assert_hook=G(hook,0x7003b0); assert_hook(); ext_4c0b00(s,0); return 1;
}
PCREG(4c2170,readfields);
static u8 THISCALL query(u8* s){
 u8* service=vcall<u8*>(G(u8*,0x70039c),0x190); u8 text[64]; u8 result=0;
 typedef u32(*fmt)(u8*,u8*,u32,u32);
 G(fmt,G(u8*,service)+0x198)(service,text,0x6a9afc,G(u32,s+0x194));
 u8* q=vcall<u8*>(G(u8*,G(u8*,0x70039c)+0x9b),0x134);
 vcall<u32>(q,0x90,text,&result); return result;
}
PCREG(578d30,query);
static void FASTCALL setstates(u32 idx,u32 a,u32 b,u32 c){
 u32 values[3]={a,b,c};
 for(u32 j=0;j<3;j++){
 u32* p=(u32*)(0x7248c8+idx*4+j*0x20);
 if(*p!=values[j]){*p=values[j]; u8* dev=G(u8*,0x724a00);
 typedef u32(STDCALL *set)(u8*,u32,u32,u32);
 G(set,G(u8*,dev)+0xfc)(dev,idx,4+j,values[j]);}
 }
}
PCREG(60feb0,setstates);
static void THISCALL config(u8* s){
 ext_432650(s); G(u32,s+0x102)=0x10; s[0x106]=1; u32 out;
 if(vcall<u8>(G(u8*,0x70039c),0x5c,0x67a394u,&out)){
 typedef u32(*parse)(u32); s[0x106]=G(parse,0x6762d8)(out)!=0;
 }
 if(vcall<u8>(G(u8*,0x70039c),0x5c,0x67a39cu,&out)){
 typedef u32(*parse)(u32); G(u32,s+0x102)=G(parse,0x6762d8)(out);
 }
}
PCREG(433dc0,config);
static u8* THISCALL nextmatch(u8* s){
 u8* prefix=G(u8*,s+0xc); if(!prefix) return 0;
 u32 i=++G(u32,s+0x10);
 if(i<G(u32,s+8)){
 u8* word=G(u8**,s+4)[i]; u32 n=0; while(prefix[n]) ++n;
 typedef s32(*cmp)(u8*,u8*,u32);
 if(G(cmp,0x676408)(prefix,word,n)==0) return word;
 }
 --G(u32,s+0x10); return 0;
}
PCREG(4d4540,nextmatch);
