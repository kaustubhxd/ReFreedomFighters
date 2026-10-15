from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct,math

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0x180);point=rnd(c,12)
 loc=[r.uniform(-100,100) for _ in range(3)];pos=[v+r.uniform(-100,100) for v in loc]
 if r.random()<0.3:pos=loc[:]
 e.wbytes(point,struct.pack('<3f',*pos))
 def side(em,k):em.wbytes(em.arg32(0),struct.pack('<3f',*loc))
 link=obj(c,0x20,{0x84:pystub(c,1,this=True,nullflag=(0,),side=side)})
 e.w32(me+0x44,link);e.w32(me+0xcf,rnd(c,0x40))
 # Use actual subtraction and sqrt routines; provide the CRT sqrt import.
 def sqrt(em,res):
  from unicorn.x86_const import UC_X86_REG_XMM0
  raw=em.mu.reg_read(UC_X86_REG_XMM0);x=struct.unpack('<d',(raw&((1<<64)-1)).to_bytes(8,'little'))[0]
  em.mu.reg_write(UC_X86_REG_XMM0,int.from_bytes(struct.pack('<d',math.sqrt(x)),'little'));em.ret()
 e.stub_import('_libm_sse2_sqrt_precise',sqrt)
 hook_rec(c,0x543810,2,this=True,deref={0:3});hook_rec(c,0x634e90,1,this=True)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,point]
S(0x53eeb0,'GUESS proximity activation state','thiscall',None,ret=None,gen=gen)
