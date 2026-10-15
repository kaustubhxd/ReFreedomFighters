from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger

def base(c):
 clear_hooks(c);e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))
 e.hook(0x633654,lambda em,rr:em.ret(eax=em.reg('eax'),argbytes=0))

def gdc60(c):
 base(c);e=c.emu;r=c.rng;logger(c,nargs=2)
 def actor():
  matrix=[r.getrandbits(32) for _ in range(9)];pos=[r.getrandbits(32) for _ in range(3)]
  def get(em,k):
   for i,v in enumerate(matrix):em.w32(em.arg32(0)+4*i,v)
   for i,v in enumerate(pos):em.w32(em.arg32(1)+4*i,v)
  def put(em,k):em.wbytes(em.reg('ecx')+8,em.rbytes(em.arg32(0),36)+em.rbytes(em.arg32(1),12))
  return obj(c,0x60,{0x80:pystub(c,2,this=True,stackmark=(0,1),side=get),0x7c:pystub(c,2,this=True,deref={0:9,1:3},side=put)})
 a,b=actor(),actor();ids=r.sample(range(1,10000000),2)
 values=[rnd(c,8),rnd(c,8)]
 for v,i in zip(values,ids):e.w32(v,i)
 mapping={ids[0]:r.choice([0,a,b]),ids[1]:r.choice([0,a,b])}
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:values[em.arg32(0)])
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:mapping[em.arg32(0)])})
 inp=rnd(c,0x10);e.w32(inp+4,rnd(c,8))
 return [inp]

def g8d90(c):
 base(c);e=c.emu;r=c.rng;logger(c,nargs=3)
 def point():
  values=[r.getrandbits(32)&0xfeffffff for _ in range(3)];mask=r.randrange(1,8)
  def out(em,k):
   for i,v in enumerate(values):
    if mask&(1<<i):em.w32(em.arg32(0)+4*i,v)
  return obj(c,0x30,{0x84:pystub(c,1,this=True,deref={0:3},side=out)})
 actor=point();target=point();resolved=r.choice([0,target,target])
 me=rnd(c,0x30);e.w32(me+0x1c,actor);e.w32(actor+4,r.choice([0,rnd(c,0x20)]))
 value=rnd(c,8);hook_rec(c,0x5003d0,1,this=True,ret=value)
 primary=pystub(c,3,this=True,deref={0:3,1:3})
 alternate=pystub(c,3,this=True,deref={0:3,1:3},ret=1)
 renderer=obj(c,0x20,{0x218:primary});second=obj(c,0x20,{0x218:pystub(c,3,this=True,deref={0:3,1:3},ret=2)})
 mode=r.randrange(4)
 def clock(em,k):
  if mode&1:em.w32(e.r32(system+0x9b)+0xadc,second)
  if mode&2:em.w32(em.r32(renderer)+0x218,alternate)
  return tick
 tick=r.choice([0,1,0xffffffff,0x80000000,r.getrandbits(32)])
 system=sysobj(c,slots={0x1bc:pystub(c,2,this=True,ret=clock)},table_slots={0x58:pystub(c,1,this=True,ret=resolved)},table_size=0xae0)
 e.w32(e.r32(system+0x9b)+0xadc,renderer)
 inp=rnd(c,0x10);e.w32(inp+4,rnd(c,8))
 return [me,inp]
S(0x50dc60,'GUESS copy object position and orientation','stdcall',None,ret=None,gen=gdc60)
S(0x558d90,'GUESS draw debug line to referenced actor','thiscall',None,ret=None,gen=g8d90)
