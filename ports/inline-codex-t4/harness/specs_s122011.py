from pilot import S,F
import math,struct
from unicorn.x86_const import UC_X86_REG_XMM0,UC_X86_REG_XMM1
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 def pw(em,_):
  x=struct.unpack('<d',struct.pack('<Q',em.mu.reg_read(UC_X86_REG_XMM0)&((1<<64)-1)))[0]
  y=struct.unpack('<d',struct.pack('<Q',em.mu.reg_read(UC_X86_REG_XMM1)&((1<<64)-1)))[0]
  em.calllog.append(('pow',struct.pack('<d',x),struct.pack('<d',y)))
  try:z=math.pow(x,y)
  except (ValueError,OverflowError):z=float('nan')
  em.mu.reg_write(UC_X86_REG_XMM0,struct.unpack('<Q',struct.pack('<d',z))[0]);em.ret()
 e.stub_import('_libm_sse2_pow_precise',pw)
 dev=obj(c,0x20,{0x48:pystub(c,3,deref={2:384})})
 s=rnd(c,0x1380);e.w32(s+0x1377,dev)
 sys=rnd(c,0x1b00);cfg=rnd(c,0x100);e.w32(0x70039c,sys);e.w32(sys+0x1aa3,cfg)
 return [s,F(r.choice([0.,1.,2.,0.5,-1.,-2.,0.1,10.,r.uniform(-3,3)]))]
S(0x610350,'GUESS set gamma ramp','thiscall',None,ret=None,gen=gen)
