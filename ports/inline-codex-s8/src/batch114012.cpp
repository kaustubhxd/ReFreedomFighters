#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
extern "C" void THISCALL ext_5636c0(void *,u32,const char *);
typedef void (*Fmt4)(void *,char *,u32,u32);typedef void (*Fmt5)(void *,char *,u32,u32,u32);
static void *system579(){return G(void *,0x70039c);}static void *table579(){return (void *)U(system579(),0x9b);}static void *formatter579(){return vcall<void *>(system579(),0x190);}
static u32 lookup579(u32 a,u32 b){return vcall<u32>((void *)U(table579(),0xae4),0,a,b);}
static void THISCALL labels579d20(u8 *s) {
 char key[64],text[1024];u8 flag;
 const u32 keys[]={0x6a9af0,0x6a9ac8,0x6a9adc,0x6a9afc};
 const u32 names[]={0x6a9aa4,0x6a9a7c,0x6a9a84,0x6a9abc};const u32 fields[]={0x188,0x180,0x184,0x190};
 for(u32 i=0;i<4;i++) {
  void *fmt=formatter579();((Fmt4)U(U(fmt,0),0x198))(fmt,key,keys[i],U(s,0x194));
  void *query=vcall<void *>(table579(),0x134);flag=0;vcall<void>(query,0x90,key,&flag);
  u32 status=lookup579(0x6a67e8,flag?(i?0x6a7c24:0x6a9a9c):(i?0x6a7c28:0x6a9aa0));
  u32 name;
  if(!i){name=lookup579(0x6a9aac,names[i]);fmt=formatter579();}
  else {fmt=formatter579();name=lookup579(0x6a9aac,names[i]);}
  ((Fmt5)U(U(fmt,0),0x198))(fmt,text,0x68dcfc,name,status);
  ext_5636c0(s,U(s,fields[i]),text);
 }
}
PCREG(579d20,labels579d20);
