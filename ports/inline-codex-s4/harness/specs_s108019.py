from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,reftab

def base(c):
 clear_hooks(c);c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def g32a0(c):
 base(c);e=c.emu;r=c.rng
 state0=obj(c,0x20,{0x308:pystub(c,0,this=True,ret=r.choice([0,1,256,0x80000000]))})
 state1=obj(c,0x20,{0x300:pystub(c,0,this=True,ret=r.choice([0,1,2,2,3,0x10002]))})
 left=obj(c,0x20,{0x2e8:pystub(c,0,this=True,ret=lambda em,k:state0 if k==0 else state1)})
 left=r.choice([0,left,left]);spare=rnd(c,0x20);right=r.choice([0,left,spare])
 me=obj(c,0x20,{0x504:pystub(c,0,this=True,ret=left),0x500:pystub(c,0,this=True,ret=right),0x45c:pystub(c,2,this=True)})
 target=r.choice([0,left,right,spare]);sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=target)})
 return [me,r.choice([0,r.getrandbits(32)|1])]

def gfb50(c):
 base(c);e=c.emu;r=c.rng
 me=rnd(c,0x60)
 toggle=r.randrange(2)
 def dispatch(em,k):
  if toggle:em.w8(me+0x57,em.r8(me+0x57)^1)
 sender=obj(c,0x20,{0x12c:pystub(c,3,this=True,side=dispatch)})
 target=obj(c,0x30,{0x1e0:pystub(c,1,this=True,ret=r.choice([0,1,0x100,0x101,255]))})
 ids=[r.choice([0,r.getrandbits(32)]) for _ in range(r.randrange(7))]
 e.w32(target+0x18,r.choice([0,reftab(c,ids)]))
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=r.choice([0,target,target])),0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))})
 e.w32(me+0x44,sender);e.w8(me+0x56,r.choice([0,1,2,255]));e.w8(me+0x57,r.choice([0,1,2,255]))
 return [me,r.getrandbits(32)]
S(0x4732a0,'GUESS switch one weapon alone using control commands','thiscall',None,ret=None,gen=g32a0)
S(0x4afb50,'GUESS send single or grouped messages with sender selection','thiscall',None,ret=None,gen=gfb50)
