import struct
from pilot import S,F,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def g4bf(c):
 clear_hooks(c);r=c.rng;e=c.emu
 sysobj(c,rand=r.choice([-1.,0.,0.5,1.,10.,float('nan')]))
 s=obj(c,0x80,{0x64:pystub(c,1,this=True),0x68:pystub(c,2,this=True)})
 a,b=r.randrange(65536),r.randrange(65536)
 e.wbytes(s+0x48,struct.pack('<HH',a,b))
 put(e,s+0x66,r.choice([-1.,0.,0.5,1.,10.,float('nan')]))
 data=rnd(c,12)
 for i in range(2):e.w32(data+4*i,r.choice([0,1,0xffffffff,0x7fffffff,0x80000000,r.getrandbits(32)]))
 return [s,r.choice([a,b,r.randrange(65536)])|(r.getrandbits(16)<<16),r.choice([0,data,data])]

def g528(c):
 clear_hooks(c);r=c.rng;e=c.emu
 outputs=[rnd(c,32) for _ in range(2)]
 returns=[r.choice([outputs[0],outputs[0],0]),r.choice([outputs[1],outputs[1],0])]
 table=obj(c,0x20,{0x60:pystub(c,2,this=True,ret=lambda em,k:0x100+em.arg32(1)),0xe4:pystub(c,2,this=True,ret=lambda em,k:em.arg32(0)+0x200)})
 manager=obj(c,0x30,{0x80:pystub(c,1,this=True,ret=lambda em,k:returns[k%2])})
 e.w32(manager+0x18,table);sys=sysobj(c);e.w32(sys+0x1aa3,manager)
 s=rnd(c,0x20);body=rnd(c,0x80);e.w32(s+8,body)
 return [s,F(r.choice(EDGE_F) if r.random()<0.3 else r.uniform(-1000,1000))]

def g657(c):
 clear_hooks(c);r=c.rng;e=c.emu
 records=[rnd(c,0x60) for _ in range(r.randrange(7))];out=rnd(c,0x60)
 for i,p in enumerate(records):
  e.wbytes(p+2,struct.pack('<H',r.choice([0,0,1,65535])))
  e.w32(p+8,i+2 if i+1<len(records) else 0)
  put(e,p+0x54,r.choice([-0.,0.,1.,100.,float('nan'),float('inf'),r.uniform(-1000,1000)]))
  put(e,p+0x58,r.choice([-0.,0.,1.,100.,float('nan'),float('inf'),r.uniform(-1000,1000)]))
 e.wbytes(out+2,struct.pack('<H',r.choice([0,0,1,65535])))
 def lookup(em,k):
  i=em.arg32(0);return out if i==100 else records[i-1]
 s=obj(c,32,{0xc:pystub(c,1,this=True,ret=lookup)})
 return [s,1 if records else 0,100]
S(0x4bf200,'GUESS timer event dispatch','thiscall',None,ret='eax',gen=g4bf,note='batch116001')
S(0x528f50,'GUESS set track UV offset','stdcall',None,ret=None,gen=g528,note='batch116001',nan_heap=True)
S(0x657cc0,'GUESS aggregate linked record range','thiscall',None,ret=None,gen=g657,note='batch116001',nan_heap=True)
