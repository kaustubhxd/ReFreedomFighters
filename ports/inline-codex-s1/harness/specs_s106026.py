import struct,math
from unicorn.x86_const import UC_X86_REG_XMM0
from pilot import S,EDGE_F
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 values=[r.choice(EDGE_F+[r.uniform(-10,10)]) for _ in range(6)]
 hook_rec(c,0x4e5e80,0,this=True,st0=lambda em,k:values[k%6])
 def power(em,k):
  a=em.reg('xmm0')&((1<<64)-1);b=em.reg('xmm1')&((1<<64)-1);em.calllog.append(('pow',a,b))
  x=struct.unpack('<d',struct.pack('<Q',a))[0];y=struct.unpack('<d',struct.pack('<Q',b))[0]
  try:z=math.pow(x,y)
  except OverflowError:z=math.inf
  except ValueError:z=math.nan
  em.mu.reg_write(UC_X86_REG_XMM0,struct.unpack('<Q',struct.pack('<d',z))[0])
 hook_rec(c,0x634db2,0,side=power)
 e.w32(0x7003b0,pystub(c,0))
 return [rnd(c,0x80),rnd(c,16)]
S(0x4bbd00,'read clamped response parameters','thiscall',None,ret=None,gen=gen,nan_heap=True)
