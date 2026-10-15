import struct,math
from pilot import S,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def g411(c):
 clear_hooks(c);r=c.rng;e=c.emu
 inp=rnd(c,16);out=inp if r.random()<0.3 else rnd(c,16)
 mode=r.randrange(5)
 if mode==0:values=[0.,0.,0.]
 elif mode==1:values=[r.choice([-1.,1.])*(1+r.choice([-5e-6,0.,5e-6,1e-5,-1e-5])),0.,0.]
 elif mode==2:values=[r.uniform(-1e-5,1e-5) for _ in range(3)]
 else:values=[r.choice(EDGE_F) if r.random()<0.15 else r.uniform(-100,100) for _ in range(3)]
 for i,v in enumerate(values):put(e,inp+4*i,v)
 return [out,inp]

def g51c(c):
 clear_hooks(c);r=c.rng;e=c.emu
 guns=[rnd(c,32) for _ in range(5)]
 for g in guns:e.w32(g+8,rnd(c,32))
 vals=[r.uniform(-10,10) for _ in range(3)]
 def point(em,k):
  p=em.arg32(0)
  for i,v in enumerate(vals):
   old=struct.unpack('<f',em.rbytes(p+4*i,4))[0];put(em,p+4*i,old+v)
 s=obj(c,0x500,{0x328:pystub(c,3,this=True,ret=lambda em,k:guns[k%5]),0x8c:pystub(c,1,this=True,deref={0:3},side=point)})
 hook_rec(c,0x4db670,1,this=True,deref={0:3},side=point)
 # Real mreset runs; consume its 9 initialized floats by content.
 hook_rec(c,0x4dcb50,2,this=True,deref={0:9,1:3})
 return [s,rnd(c,20),rnd(c,32)]

def g5cd(c):
 clear_hooks(c);r=c.rng;e=c.emu;sys=sysobj(c);s=rnd(c,0xe40)
 for off in [0xab6,0xb45]:e.wbytes(s+off,bytes([r.choice([0,0,0,1])]))
 for off in [0xad4,0xb19]:e.wbytes(s+off,bytes([r.choice([0,1,1,255])]))
 e.w32(s+0xe1c,r.choice([0,1,3]))
 for off in [0xaed,0xa5c,0xb05]:put(e,s+off,r.choice([-2.,-1.,-0.5,0.,0.1,1.,float('nan'),float('inf'),r.uniform(-3,3)]))
 put(e,sys+0x48,r.choice([0.,0.01,0.5,1.,2.,r.uniform(0,5)]))
 hook_rec(c,0x662b70,1,this=True);hook_rec(c,0x662b00,1,this=True)
 def side(em,k):put(em,em.arg32(0),r.uniform(-1,1))
 hook_rec(c,0x6627c0,1,this=True,deref={0:1},side=side)
 return [s]
S(0x4110c2,'GUESS guarded x87 normalization','stdcall',None,ret='eax',gen=g411,note='batch116007',nan_heap=True)
S(0x51c2e0,'GUESS helicopter wing guns','thiscall',None,ret=None,gen=g51c,note='batch116007')
S(0x5cd890,'GUESS camera idle pitch easing','thiscall',None,ret=None,gen=g5cd,note='batch116007')
