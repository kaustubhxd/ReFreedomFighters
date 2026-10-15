import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec

def g5519(c):
 clear_hooks(c);r=c.rng;e=c.emu
 cells=[rnd(c,16) for _ in range(5)]
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:cells[em.arg32(0)%5])
 hook_rec(c,0x5002f0,1,this=True)
 hook_rec(c,0x500360,1,this=True)
 p=rnd(c,32)
 o=obj(c,32,{0x4c:pystub(c,0,this=True,ret=p)})
 a=obj(c,32,{0x18:pystub(c,1,this=True,ret=r.choice([o,o,o,0]))})
 return [a,r.getrandbits(32),rnd(c,20)]

def g493b(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0xa20)
 count=r.randint(1,32);nodes=[s+4+20*i for i in range(count)]
 order=nodes[:];r.shuffle(order)
 for i,n in enumerate(order):
  e.w32(n+12,order[i-1] if i else 0)
  e.w32(n+16,order[i+1] if i+1<count else 0)
 e.w32(s+0xa04,order[0]);e.w32(s+0xa0c,count)
 return [s,r.choice(nodes)]

def g5216(c):
 clear_hooks(c);r=c.rng;e=c.emu
 def put(p,v):e.wbytes(p,struct.pack('<f',v))
 vals=[r.uniform(-10,10) for _ in range(3)]
 def side(em,k):
  for i,v in enumerate(vals):em.wbytes(em.arg32(0)+4*i,struct.pack('<f',v))
 target=obj(c,32,{0x84:pystub(c,1,this=True,nullflag=(0,),side=side)})
 s=obj(c,0x2800,{0x90:pystub(c,1,this=True,deref={0:3})})
 motion=rnd(c,0x40);e.w32(s+0x5c,motion)
 put(motion+0x24,r.choice([-10.,0.,1.,10.,float('nan')]))
 e.wbytes(s+0x260b,bytes([r.choice([0,1,255])]))
 e.w32(s+0x2610,r.choice([0,0,1,0xffffffff]))
 e.w32(s+0x25d1,r.choice([target,target,0]))
 for off in [0x6c,0x70,0x74,0x78,0x7c,0x80,0x25fd,0x2601,0x2605]:put(s+off,r.uniform(-10,10))
 return [s]
S(0x5519d0,'GUESS set five typed cells','stdcall',None,ret='eax',gen=g5519,note='batch116000')
S(0x493b80,'GUESS unlink packed list node','thiscall',None,ret=None,gen=g493b,note='batch116000')
S(0x5216a0,'GUESS wanted turret direction','thiscall',None,ret=None,gen=g5216,note='batch116000')
