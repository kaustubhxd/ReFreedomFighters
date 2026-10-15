import struct
from pilot import S,EDGE_F
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 me=rnd(c,0x60)
 child=obj(c,16,{4:pystub(c,3,this=True)})
 e.w32(me+0x28,e.r32(child))
 def process(em,k):
  em.calllog.append(('process',em.reg('edx'),em.rbytes(em.reg('ecx'),12).hex()))
  for i in range(3):em.w32(em.reg('ecx')+4*i,em.r32(em.reg('edx')+4*i))
 hook_rec(c,0x441940,0,this=True,side=process)
 def dot(em,k):em.calllog.append(('dot',em.reg('edx'),em.rbytes(em.reg('ecx'),12).hex(),em.rbytes(em.reg('edx'),12).hex()))
 hook_rec(c,0x4e0030,0,this=True,side=dot,st0=r.choice(EDGE_F+[r.uniform(-100,100)]))
 e.w32(0x7003b0,e.stub_fn('assert',lambda em,k:em.ret(eax=0)))
 # Include overlapping input buffers, preserving sequential copy semantics.
 a=r.choice([rnd(c,12),me+8]);b=r.choice([rnd(c,12),me+4])
 return [me,a,b]
S(0x527420,'set vector pair and angle','thiscall',None,ret=None,gen=gen,nan_heap=True)
