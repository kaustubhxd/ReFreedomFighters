#include "ff.h"
extern "C" void THISCALL ext_5f2d60(void*,u32,u32);
static void THISCALL token(u8*me,void*out,u8**cursor,u8*end){
 ext_5f2d60(out,0x677b5a,0x677b5a);
 u8*p=*cursor;if(!*p)return;
 if(p[0]=='/'&&p[1]=='/')while(*cursor!=end&&**cursor!=13&&**cursor!=10)++*cursor;
 if(*cursor==end){vcall<void>(me,0x84,out,cursor,end);return;}
 u8 ch=**cursor;
 if(ch==32||ch==9){ext_5f2d60(out,0x679e6c,0x679e6d);while(*cursor!=end&&(**cursor==32||**cursor==9))++*cursor;return;}
 if(ch==13||ch==10){ext_5f2d60(out,0x676c04,0x676c05);while(*cursor!=end&&(**cursor==13||**cursor==10))++*cursor;return;}
 if(ch==0x24){ext_5f2d60(out,0x679e70,0x679e71);++*cursor;return;}
 vcall<void>(me,0x84,out,cursor,end);
}
PCREG(42ceb0,token);
