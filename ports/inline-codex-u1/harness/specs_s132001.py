import math,struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 p=rnd(c,12);out=rnd(c,8);selfp=rnd(c,4)
 cases=[[0,0,0],[1,0,0],[-1,0,0],[0,1,0],[0,-1,0],[0,0,1],[0,0,-1],[0.0001,1,0],[0.0002,1,0],[1,1,1],[-1,-1,-1]]
 vals=r.choice(cases) if r.random()<0.45 else [r.uniform(-1000,1000) for _ in range(3)]
 for k,x in enumerate(vals):e.w32(p+4*k,fb(x))
 # Exercise the real CRT imports via deterministic host implementations on both sides.
 from unicorn.x86_const import UC_X86_REG_XMM0
 def mathstub(fun):
  def h(e,r):
   x=struct.unpack('<d',struct.pack('<Q',e.mu.reg_read(UC_X86_REG_XMM0)&((1<<64)-1)))[0]
   try:z=fun(x)
   except ValueError:z=math.nan
   e.mu.reg_write(UC_X86_REG_XMM0,struct.unpack('<Q',struct.pack('<d',z))[0]);e.ret()
  return h
 e.stub_import('_libm_sse2_atan_precise',mathstub(math.atan));e.stub_import('_libm_sse2_sqrt_precise',mathstub(math.sqrt))
 return [selfp,out,out+4,p]
S(0x5cf820,'GUESS polar angles','thiscall',None,ret=None,gen=gen,nan_heap=True)
