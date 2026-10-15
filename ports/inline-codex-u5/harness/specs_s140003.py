import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec,sysobj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 def transform(pos):
  matrix=[r.uniform(-3,3) for _ in range(9)]
  def side(em,k):
   em.wbytes(em.arg32(0),struct.pack('<9f',*matrix));em.wbytes(em.arg32(1),struct.pack('<3f',*pos))
  return pystub(c,2,this=True,nullflag=[0,1],side=side)
 actor=obj(c,0x100,{0x80:transform([0.,0.,0.])})
 count=r.randrange(0,7);me=rnd(c,0x80);entries=[];ids={};ranks={}
 for i in range(count):
  pos=r.choice([[0.,0.,0.],[1.,0.,0.],[-1.,0.,0.],[100.,200.,-30.],[r.uniform(-10,10) for _ in range(3)]])
  target=obj(c,0x100,{0x80:transform(pos)})
  entry=rnd(c,0x10);e.w32(entry,target);entries.append(entry);ids[target]=i+1;ranks[i+1]=r.choice([0,0,1,2,255])
  e.w32(me+0x3c+4*i,entry)
 e.w32(me+0x38,count)
 # Pruning may change the count. The port must re-read the current extent.
 keep=r.randrange(count+1)
 def prune(em,k):em.w32(me+0x38,keep)
 hook_rec(c,0x58a320,0,this=True,side=prune)
 sysobj(c,table_slots={0x4c:pystub(c,1,this=True,ret=lambda em,k:ids[em.arg32(0)])})
 hook_rec(c,0x59e050,1,this=True,ret=lambda em,k:ranks[em.arg32(0)])
 out=rnd(c,4);flag=rnd(c,4)
 return [me,actor,r.getrandbits(32),out,flag]
S(0x589a10,'GUESS choose nearest ranked candidate','thiscall',None,ret=None,gen=gen)
