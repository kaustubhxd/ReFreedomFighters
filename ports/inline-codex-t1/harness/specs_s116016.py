import struct
from pilot import S,F,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def g527(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0x2000)
 for off in [0x8d,0x91]:e.w32(s+off,r.choice([0,1,2,3,0xffffffff]))
 for i in range(12):put(e,s+4*i,r.uniform(-10,10))
 for base,src in [(0x95,0xe91),(0x785,0x1829)]:
  for i in range(3):
   for off in [0x41,0x55]:put(e,s+base+0xde*i+off,r.choice([-1.,0.,1.,float('nan'),r.uniform(-10,10)]))
   for j in range(3):put(e,s+src+0x133*i+4*j,r.uniform(-10,10))
 hook_rec(c,0x5162e0,1,this=True,deref={0:3});return [s]

def g523(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0x60);path=obj(c,0x40,{0x88:pystub(c,1,this=True,deref={0:3})})
 e.w32(s+0x4b,r.choice([0,path,path]));put(e,s+0x53,r.choice([0.,1.,-1.,100.]));put(e,s+0x20,r.uniform(-10,10))
 def side(em,k):
  for a in [0,1]:
   for i in range(3):put(e,em.arg32(a)+4*i,r.uniform(-10,10))
 hook_rec(c,0x460af0,3,this=True,nullflag=(0,1),side=side)
 record=rnd(c,24)
 def dist(em,k):em.wbytes(record,em.rbytes(em.reg('ecx'),12)+em.rbytes(em.reg('edx'),12))
 hook_rec(c,0x4e0830,0,this='mark',st0=r.choice([0.,0.001,1.,100.,float('nan')]),side=dist)
 return [s,rnd(c,12),F(r.uniform(-1,2)),F(r.uniform(-10,10))]

def g54c(c):
 clear_hooks(c);r=c.rng;e=c.emu
 def exception(em,k):
  em.calllog.append(('CRT_except1',tuple(em.arg32(i) for i in range(7))))
  # The CRT helper immediately discards the returned ST0; its integer sentinel follows.
  em.ret(st0=0.)
 e.stub_import('_except1',exception)
 device=obj(c,32,{0x40:pystub(c,2,ret=r.choice([0,1,0xffffffff,0x80000000]))})
 effect=obj(c,32,{0x30:pystub(c,3,deref={1:16})})
 s=obj(c,0x6400,{0x7c:pystub(c,1,this=True,ret=r.choice([0,1,-1,-10001,10001,0x7fffffff,0x80000000]))});e.w32(s+0x63ec,device);e.w32(s+0x63f0,r.choice([0,effect,effect]))
 event=rnd(c,0xc0);e.w32(event+0x24,r.choice([0,1,1,10,10,255]))
 for off in [0xb4,0xb8,0xbc]:put(e,event+off,r.choice([-1.,0.,1.,3e9,float('nan'),r.uniform(-100,100)]))
 rec=rnd(c,4)
 def error(em,k):em.w32(rec,em.reg('edx'))
 hook_rec(c,0x54f2b0,0,this=True,side=error)
 return [s,event]
S(0x5279f0,'GUESS correct reversed tank dampers','thiscall',None,ret=None,gen=g527,note='batch116016')
S(0x523520,'GUESS path direction around parameter','thiscall',None,ret=None,gen=g523,note='batch116016')
S(0x54c7a0,'GUESS force feedback event','thiscall',None,ret=None,gen=g54c,note='batch116016')
