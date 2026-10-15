#include "ff.h"
extern "C" void FASTCALL ext_4de420(void*,void*);
extern "C" void FASTCALL ext_446ee0(void*,void*,void*);
extern "C" long double THISCALL ext_44c840(void*);
static u8 THISCALL basis(u8* me,void* object,u32 unused){
 float* dest=vcall<float*>(object,0x38);float* source=vcall<float*>(object,0x40);
 if(G(u8,me+0x18)){ext_4de420(dest,source);return 1;}
 float* other=vcall<float*>(object,0x3c);float dot=other[1]*source[1];dot=dot+other[0]*source[0];dot=dot+other[2]*source[2];
 double absolute=__builtin_bit_cast(double,__builtin_bit_cast(u64,(double)dot)&0x7fffffffffffffffULL);
 if(absolute>G(double,0x680148)){ext_4de420(dest,source);return 1;}
 dest[0]=source[0];dest[1]=source[1];dest[2]=source[2];ext_446ee0(dest+6,other+3,dest);(void)ext_44c840(dest+6);ext_446ee0(dest+3,dest,dest+6);return 1;
}
PCREG(44c660,basis);
