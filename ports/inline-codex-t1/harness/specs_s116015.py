import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def g4bc(c):
 clear_hooks(c);e=c.emu
 stream=obj(c,32,{0x44:pystub(c,1,this=True),0x4c:pystub(c,1,this=True),0x60:pystub(c,1,this=True)})
 return [rnd(c,0x90),stream]

def g441(c):
 clear_hooks(c);r=c.rng;e=c.emu
 def write_arg(index,n):
  vals=[r.uniform(-10,10) for _ in range(n)]
  def side(em,k):
   for i,v in enumerate(vals):put(em,em.arg32(index)+4*i,v)
  return side
 tree=rnd(c,32)
 s=obj(c,32,{0x314:pystub(c,0,this=True,ret=r.choice([0,tree,tree])),0x94:pystub(c,2,this=True,deref={0:9,1:3},side=write_arg(1,3))})
 hook_rec(c,0x4daf90,1,this=True,nullflag=(0,),side=write_arg(0,3))
 hook_rec(c,0x4db600,2,this=True,deref={0:9,1:3},side=write_arg(0,9))
 hook_rec(c,0x4db7c0,1,this=True,nullflag=(0,),side=write_arg(0,3))
 rec=rnd(c,48);vals=[r.uniform(-10,10) for _ in range(3)]
 def transform(em,k):
  em.wbytes(rec,em.rbytes(em.reg('ecx'),36)+em.rbytes(em.reg('edx'),12))
  for i,v in enumerate(vals):put(em,em.reg('edx')+4*i,v)
 hook_rec(c,0x4e2c60,0,this='mark',side=transform)
 hook_rec(c,0x4e41e0,3,this=True,deref={0:3,1:3})
 sysobj(c,table_slots={0x50:pystub(c,1,this=True,ret=r.getrandbits(32))})
 return [s,rnd(c,32)]
S(0x4bc150,'GUESS serialize float parameter block','thiscall',None,ret='al',gen=g4bc,note='batch116015')
S(0x441f40,'GUESS update geometry tree bounds','thiscall',None,ret=None,gen=g441,note='batch116015')
