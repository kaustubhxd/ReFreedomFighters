from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger

def base(c):
 clear_hooks(c)
 c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def gfe30(c):
 base(c);e=c.emu;r=c.rng
 logger(c,nargs=3)
 ref=r.getrandbits(32);first=rnd(c,0x10);arg=rnd(c,0x10);dest=rnd(c,0x10)
 referenced=obj(c,0x20,{0x34:pystub(c,0,this=True,ret=ref)})
 typ=r.choice([0,1,2,3,3,4,4,5,255]);e.w8(first+4,typ);e.w32(first,referenced if typ==4 else ref)
 e.w32(arg,r.choice([0,1,r.getrandbits(32)]))
 handle1=rnd(c,0x10);handle2=rnd(c,0x10)
 def get(em,k):
  if em.reg('ecx')==handle2:return dest
  return first if em.arg32(0)==0 else arg
 hook_rec(c,0x5003d0,1,this=True,ret=get)
 hook_rec(c,0x5002f0,1,this=True)
 found=r.choice([0,1,2,128,255])
 def out(em,k):em.w8(em.arg32(1),found)
 lookup0=obj(c,0x20,{0x90:pystub(c,2,this=True,deref={1:-1},side=out)})
 lookup1=obj(c,0x20,{0x68:pystub(c,3,this=True)})
 sysobj(c,table_slots={0x138:pystub(c,0,this=True,ret=lambda em,k:lookup0 if k==0 else lookup1)})
 inp=rnd(c,0x10);e.w32(inp+4,handle1);e.w32(inp+8,handle2)
 return [inp]

def g8850(c):
 base(c);e=c.emu;r=c.rng
 pos=rnd(c,0x50)
 def readout(em,k):
  for i in range(9):em.w32(em.arg32(0)+4*i,em.r32(em.arg32(0)+4*i)^0xabc123)
  for i in range(3):em.w32(em.arg32(1)+4*i,em.r32(em.arg32(1)+4*i)^0x987654)
 me=obj(c,0x1700,{0x80:pystub(c,2,this=True,deref={0:9,1:3},side=readout),0x7c:pystub(c,2,this=True,deref={0:9,1:3}),0x78:pystub(c,1,this=True,deref={0:3})})
 e.w32(me+0x5c,pos);active=r.choice([0,0,1,2,255]);e.w8(me+0x133,active)
 ident=r.choice([0,r.getrandbits(32)|1]);e.w32(me+0x123,ident)
 underlying=rnd(c,0x50);e.w32(underlying+0x3c,r.choice([0,0x1000,0x2000,0x1001,0xffffffff]))
 target=rnd(c,0x20);e.w32(target+8,underlying)
 # Active branch assumes a nonnull resolved object for a nonzero id.
 resolved=target if active and ident else r.choice([0,target,target])
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=resolved)})
 hook_rec(c,0x515c70,0,this=True)
 hook_rec(c,0x518bc0,0,this=True);hook_rec(c,0x519280,0,this=True);hook_rec(c,0x518960,0,this=True)
 def calculate(em,k):
  for i in range(9):em.w32(em.arg32(0)+4*i,em.r32(em.arg32(0)+4*i)^0x44444444)
  for i in range(3):em.w32(em.arg32(1)+4*i,em.r32(em.arg32(1)+4*i)^0x22222222)
 hook_rec(c,0x5251c0,8,this=True,deref={0:9,1:3,2:3,3:9},side=calculate)
 return [me]
S(0x50fe30,'GUESS toggle reference state and return previous byte result','stdcall',None,ret=None,gen=gfe30)
S(0x518850,'GUESS update car spline or fallback position','thiscall',None,ret=None,gen=g8850)
