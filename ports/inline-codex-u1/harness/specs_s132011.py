import math,struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec
from unicorn.x86_const import UC_X86_REG_XMM0

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 p=rnd(c,0x80);obj=rnd(c,0x80);e.w32(p+8,obj);e.w8(p+0x14,r.randrange(256))
 e.w32(p+0x5c,fb(r.choice([0,0.25,1,2,3.1,r.uniform(-3,3)])))
 e.w32(p+0x60,fb(r.choice([-100,0,1,10,100,1000,r.uniform(-500,500)])))
 def mathstub(fun):
  def h(e,r):
   x=struct.unpack('<d',struct.pack('<Q',e.mu.reg_read(UC_X86_REG_XMM0)&((1<<64)-1)))[0]
   e.mu.reg_write(UC_X86_REG_XMM0,struct.unpack('<Q',struct.pack('<d',fun(x)))[0]);e.ret()
  return h
 e.stub_import('_libm_sse2_tan_precise',mathstub(math.tan));e.stub_import('_libm_sse2_sqrt_precise',mathstub(math.sqrt))
 return [p]
S(0x445580,'GUESS camera center and size','thiscall',None,ret=None,gen=gen)
