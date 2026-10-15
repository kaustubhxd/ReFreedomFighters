import struct
from pilot import S,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def g525(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0x1800)
 for off in [0x8c,0x90]:e.w32(s+off,r.choice([0,1,2,3,0xffffffff]))
 def side(em,k):
  for i in range(3):em.w32(em.arg32(0)+4*i,r.getrandbits(32))
 transform=obj(c,32,{0x84:pystub(c,1,this=True,deref={0:3},side=side)})
 e.w32(s+0x88,transform)
 hook_rec(c,0x516360,1,this=True,deref={0:3})
 return [s]

def g593(c):
 clear_hooks(c);r=c.rng;e=c.emu
 s=obj(c,0x900,{0x5bc:pystub(c,3,this=True,deref={0:3,1:3})})
 event=rnd(c,0x90)
 put(e,event+5,r.choice([0.,1.,10.,100.,1e6,float('nan'),r.uniform(0,10000)]))
 for off in [0x39,0x3d,0x41,0x69,0x6d,0x71]:put(e,event+off,r.uniform(-100,100))
 sys=sysobj(c,table_slots={0x4c:pystub(c,1,this=True,ret=rnd(c,32))})
 put(e,sys+0x48,r.choice([0.,0.001,0.1,1.,10.]))
 hook_rec(c,0x4e0870,0,this=True,st0=r.choice([0.,0.01,1.,10.,100.,r.uniform(0,100)]))
 # Also compare EDX for this fastcall helper through a side record.
 rec=rnd(c,4)
 def side_distance(em,k):em.w32(rec,em.reg('edx'))
 hook_rec(c,0x4e0870,0,this=True,st0=r.choice([0.,0.01,1.,10.,100.,r.uniform(0,100)]),side=side_distance)
 hp=r.choice([-1.,0.,0.5,1.,100.,float('nan')]);put(e,s+0x7ff,hp)
 def side_hp(em,k):put(em,s+0x7ff,hp)
 hook_rec(c,0x58b9c0,3,this=True,st0=0.,side=side_hp)
 return [s,event]
S(0x5254c0,'GUESS initialize global damper positions','thiscall',None,ret=None,gen=g525,note='batch116009')
S(0x5935a0,'GUESS large object move damage','thiscall',None,ret=None,gen=g593,note='batch116009',nan_heap=True)
