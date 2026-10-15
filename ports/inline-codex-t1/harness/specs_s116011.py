import struct
from pilot import S,F,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def g43d(c):
 clear_hooks(c);r=c.rng;e=c.emu
 values=[r.getrandbits(32) for _ in range(18)]
 def side(em,k):
  for i,v in enumerate(values):em.w32(em.arg32(0)+4*i,v)
 collider=obj(c,32,{0x64:pystub(c,6,this=True,deref={0:1,2:3,3:3},ret=r.choice([0,1,0x100,0x101]),side=side)})
 manager=rnd(c,32);e.w32(manager+0x1c,collider)
 sys=sysobj(c,table_slots={0x50:pystub(c,1,this=True,ret=r.getrandbits(32))});e.w32(sys+0x1aa3,manager)
 return [rnd(c,32),rnd(c,0x80),r.getrandbits(32)]

def g529(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0x2000)
 for off in [0x8d,0x91]:e.w32(s+off,r.choice([0,1,2,3,0xffffffff]))
 for i in range(12):put(e,s+4*i,r.uniform(-10,10))
 def side(em,k):
  for i in range(3):put(em,em.arg32(0)+4*i,r.uniform(-10,10))
 hook_rec(c,0x516230,1,this=True,nullflag=(0,),side=side)
 hook_rec(c,0x52a270,1,this=True)
 return [s]

def g467(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0x1c0);sys=sysobj(c)
 e.wbytes(s+0x158,bytes([r.choice([0,0,0,1])]))
 e.w32(s+0x136,r.choice([0,0x200000,r.getrandbits(32)]))
 oldid=r.getrandbits(32);e.w32(s+0x1a6,oldid)
 for off in [0x1a2,0x19e]:put(e,s+off,r.choice([-2.,-1.,-0.,0.,0.01,1.,10.,float('nan'),float('inf'),r.uniform(-10,10)]))
 e.w32(sys+0x40,r.choice([0,1,1024,10000,0x7fffffff,0x80000000,0xffffffff,r.getrandbits(32)]))
 return [s,r.choice([oldid,r.getrandbits(32)]),F(r.choice(EDGE_F) if r.random()<0.15 else r.uniform(-10,10))]+[r.getrandbits(32) for _ in range(4)]
S(0x43dff0,'GUESS collision query result copy','thiscall',None,ret='al',gen=g43d,note='batch116011')
S(0x529660,'GUESS update tank wheel heights','thiscall',None,ret=None,gen=g529,note='batch116011')
S(0x4678f0,'GUESS set facing target blend','thiscall',None,ret=None,gen=g467,note='batch116011',nan_heap=False)
