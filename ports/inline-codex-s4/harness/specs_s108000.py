from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,reftab,reftab_vt

def base(c):
 clear_hooks(c)
 c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))
 # /GS check has no application-visible effect; preserve EAX as the real check does.
 c.emu.hook(0x633654,lambda e,r:e.ret(eax=e.reg('eax'),argbytes=0))

def g5770(c):
 base(c);e=c.emu;r=c.rng
 ids=[r.getrandbits(32) for _ in range(r.randrange(6))]
 items={}
 for ident in ids:
  pos=[r.getrandbits(32) for _ in range(3)]
  size=[r.getrandbits(32) for _ in range(3)]
  bounds=[r.getrandbits(32) for _ in range(9)]
  def out(em,k,sz=size,bo=bounds):
   for i,v in enumerate(bo):em.w32(em.arg32(0)+4*i,v)
   for i,v in enumerate(sz):em.w32(em.arg32(1)+4*i,v)
  item=obj(c,0x30,{0x80:pystub(c,2,this=True,stackmark=(0,1),side=out)})
  source=rnd(c,0x20)
  e.w32(item+8,source)
  items[ident]=(item,source,pos)
 def posout(em,k):
  p=next(v[2] for v in items.values() if v[1]==em.reg('ecx'))
  for i,v in enumerate(p):em.w32(em.arg32(0)+4*i,v)
 hook_rec(c,0x4db7c0,1,this=True,stackmark=(0,),side=posout)
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:items[em.arg32(0)][0])})
 sink=obj(c,0x30,{0x21c:pystub(c,3,this=True,deref={0:3,1:3},ret=r.getrandbits(32))})
 me=rnd(c,0x70)
 e.w32(me+0x48,0 if r.randrange(5)==0 else reftab(c,ids))
 e.w32(me+0x53,sink)
 return [me,r.choice([0,1,0xff,0x100,r.getrandbits(32)])]

def g24b0(c):
 base(c);e=c.emu;r=c.rng
 me=obj(c,0x150,{0x58:pystub(c,0,this=True,ret=r.getrandbits(32))})
 owner=rnd(c,0x30);e.w32(owner+0x18,rnd(c,0x20));e.w32(me+0x44,owner)
 for off in (0x54,0x100):
  ids=[r.getrandbits(32) for _ in range(r.randrange(6))]
  e.w32(me+off,reftab_vt(c,ids,count=r.choice([0,len(ids),1,0x80000000])))
 hook_rec(c,0x44b850,1,this=True,ret=r.getrandbits(32))
 hook_rec(c,0x44b880,1,this=True,ret=r.getrandbits(32))
 return [me]
S(0x4c5770,'GUESS set pathfinder link state for table boxes','thiscall',None,ret=None,gen=g5770)
S(0x4c24b0,'GUESS refresh two reference tables then notify','thiscall',None,ret='eax',gen=g24b0)
