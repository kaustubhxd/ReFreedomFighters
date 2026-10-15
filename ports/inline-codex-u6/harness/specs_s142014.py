import struct
from pilot import S
from recruits_util import rnd,obj,pystub,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 def fp(n):return struct.pack('<'+'f'*n,*[r.uniform(-10,10) for _ in range(n)])
 me=rnd(c,0xc0);sys=rnd(c,0x80);e.w32(0x70039c,sys)
 owner=obj(c,16,{0x7c:pystub(c,2,this=True,deref={0:9,1:3})});e.w32(me+0x89,owner)
 record=e.alloc(1024,4);mat=[fp(9) for i in range(6)]
 def ctor(em,k):em.wbytes(record+64*k,em.rbytes(em.reg('edx'),12));em.w32(record+64*k+12,em.reg('ecx'));em.w32(record+64*k+16,em.arg32(0));em.wbytes(em.reg('ecx'),mat[k])
 hook_rec(c,0x4de040,1,side=ctor)
 def scale(em,k):em.wbytes(record+128+64*k,em.rbytes(em.reg('edx'),36));em.w32(record+128+64*k+36,em.arg32(0));em.wbytes(em.reg('ecx'),mat[2+k])
 hook_rec(c,0x4ddcb0,1,side=scale)
 def combine(em,k):em.wbytes(record+256+96*k,em.rbytes(em.reg('ecx'),36));em.wbytes(record+292+96*k,em.rbytes(em.reg('edx'),36));em.wbytes(em.reg('ecx'),mat[4+k])
 hook_rec(c,0x4de480,0,side=combine)
 for addr in [0x527f80,0x529760,0x527710,0x529660,0x528090]:hook_rec(c,addr,0,this=True)
 a=rnd(c,12);b=rnd(c,12);e.wbytes(a,fp(3));e.wbytes(b,fp(3));e.wbytes(me+0x30,fp(3))
 return [me,a,b]
S(0x528100,'GUESS tank undercarriage initial position direction','thiscall',None,ret=None,gen=gen)
