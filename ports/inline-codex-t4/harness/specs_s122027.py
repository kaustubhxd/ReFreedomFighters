from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec
from unicorn.x86_const import UC_X86_REG_XMM0,UC_X86_REG_XMM1
import struct,math

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 vals=[r.choice([0.,-0.,1.,-1.,float('nan'),r.uniform(-20,20)]) for _ in range(6)]
 hook_rec(c,0x4e5e80,0,this=True,st0=lambda em,k:vals[k])
 def pw(em,_):
  x=struct.unpack('<d',struct.pack('<Q',em.mu.reg_read(UC_X86_REG_XMM0)&((1<<64)-1)))[0]
  y=struct.unpack('<d',struct.pack('<Q',em.mu.reg_read(UC_X86_REG_XMM1)&((1<<64)-1)))[0]
  em.calllog.append(('pow',struct.pack('<d',x),struct.pack('<d',y)))
  try:z=math.pow(x,y)
  except (ValueError,OverflowError):z=float('nan')
  em.mu.reg_write(UC_X86_REG_XMM0,struct.unpack('<Q',struct.pack('<d',z))[0]);em.ret()
 e.stub_import('_libm_sse2_pow_precise',pw)
 return [rnd(c,0x80),rnd(c,0x20)]
S(0x4bbd00,'GUESS load clamped float parameters','thiscall',None,ret=None,gen=gen,nan_heap=True)
