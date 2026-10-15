from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def g(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 # Initialize all stack outputs in hooks; record vector inputs by value.
 values=[r.getrandbits(32) for _ in range(6)]
 def mul(em,k):
  em.calllog.append(('mul-input',tuple(em.r32(em.reg('edx')+i*4) for i in range(3))))
  for i in range(3):em.w32(em.reg('ecx')+i*4,values[(k*3+i)%6])
 hook_rec(c,0x446ee0,1,this='mark',deref={0:3},side=mul)
 hook_rec(c,0x44c840,0,this='mark',st0=r.uniform(-10,10),side=lambda em,k:em.calllog.append(('norm',tuple(em.r32(em.reg('ecx')+4*i) for i in range(3)))))
 def init(em,k):
  for i in range(6):em.w32(em.reg('ecx')+4*i,values[i])
 hook_rec(c,0x4de7a0,0,this='mark',side=init)
 hook_rec(c,0x633654,0,pop=0)
 b=obj(c,0x20,{0x30:pystub(c,4,this=True,deref={1:6},ret=r.getrandbits(32))})
 me=obj(c,0x20,{0xe0:pystub(c,4,this=True,ret=r.getrandbits(32))})
 backing=rnd(c,0x80);e.w32(backing+0x6c,r.choice([0,1,2,0xffffffff]));e.w32(me+8,backing);e.wbytes(me+0x18,bytes([r.choice([0,0,1])]))
 vec=rnd(c,0x20)
 e.wbytes(vec+0x14,struct.pack('<f',r.choice([-2.,-1.,0.,1.,2.,float('nan'),float('inf'),r.uniform(-1,1)])))
 return [me,b,r.getrandbits(32),vec,r.getrandbits(32)]
S(0x44c580,'GUESS conditional orientation dispatch','thiscall',None,ret=None,gen=g,nan_heap=True,note='batch124000')
