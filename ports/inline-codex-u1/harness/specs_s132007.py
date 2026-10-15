import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,obj,pystub

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 nodes=r.randrange(4);mapping={}
 for i in range(1,nodes+1):
  node=rnd(c,0x28);mapping[i]=node;e.w32(node+8,i+1 if i<nodes else 0)
  if r.random()<0.2:e.w32(node+0x24,0);continue
  block=rnd(c,4+16*4);mapping[100+i]=block;e.w32(node+0x24,100+i);count=r.randrange(5);e.w32(block,count)
  for j in range(count):
   vals=[r.uniform(-1,1) for _ in range(3)]+[r.uniform(-3,3)]
   for k,x in enumerate(vals):e.w32(block+4+j*16+4*k,fb(x))
 selfp=obj(c,16,{0xc:pystub(c,1,this=True,ret=lambda e,k:mapping[e.arg32(0)])})
 mat=rnd(c,36);center=rnd(c,12);rad=rnd(c,12)
 vals=r.choice([[1,0,0,0,1,0,0,0,1],[0]*9,[r.uniform(-1,1) for _ in range(9)]])
 for k,x in enumerate(vals):e.w32(mat+4*k,fb(x))
 for k in range(3):e.w32(center+4*k,fb(r.uniform(-3,3)));e.w32(rad+4*k,fb(r.uniform(0.05,3)))
 return [selfp,1 if nodes else 0,mat,center,rad]
S(0x655dd0,'GUESS test oriented extents against linked planes','thiscall',None,ret='al',gen=gen)
