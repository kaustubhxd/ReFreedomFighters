import struct
from pilot import S, EDGE_F
from recruits_util import rnd, clear_hooks, hook_rec

def fb(f): return struct.unpack('<I',struct.pack('<f',f))[0]
def gen(c):
 clear_hooks(c); e=c.emu; r=c.rng
 vec=[r.choice([0.,1.,-1.,r.uniform(-10,10)]) for _ in range(3)]
 if r.random()<.2: vec=[0.,0.,0.]
 if r.random()<.15: vec[r.randrange(3)]=r.choice(EDGE_F)
 def sub(em,k):
  em.calllog.append(('sub-edx',em.reg('edx')))
  em.wbytes(em.reg('ecx'),struct.pack('<fff',*vec))
 hook_rec(c,0x43e920,1,this='mark',side=sub)
 def angle(em,k):
  em.calllog.append(('angle',em.reg('xmm0') & ((1<<64)-1)))
 hook_rec(c,0x634dbe,0,side=angle)
 e.w32(0x7003b0,e.stub_fn('assert',lambda em,k:em.ret(eax=0)))
 a=rnd(c,12); b=rnd(c,12); axis=rnd(c,12)
 for i in range(3):e.w32(axis+4*i,fb(r.choice([0.,1.,-1.,r.uniform(-2,2)])))
 return [a,b,axis,fb(r.choice([0.,1.,-1.,r.uniform(-3,3)]))]
S(0x5d6960,'direction angle comparison','stdcall',None,ret='al',gen=gen)
