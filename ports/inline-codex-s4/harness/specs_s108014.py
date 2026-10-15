from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger

def base(c):
 clear_hooks(c);c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def ga860(c):
 base(c);e=c.emu;r=c.rng
 logger(c,nargs=3)
 acquired=rnd(c,0x20);copy=rnd(c,0x20)
 def setref(em,k):em.w32(em.reg('ecx')+8,em.arg32(0))
 wrapper=obj(c,0x20,{0x30:pystub(c,1,this=True,side=setref),0x24:pystub(c,0,this=True,ret=copy),0x28:pystub(c,0,this=True)})
 factory=obj(c,0x20,{0:pystub(c,2,this=True,ret=wrapper)})
 ref=r.getrandbits(32);sourceobj=obj(c,0x20,{0x34:pystub(c,0,this=True,ret=ref)})
 old=obj(c,0x20,{0x28:pystub(c,0,this=True)})
 source=rnd(c,8);typ=r.choice([0,1,2,3,3,4,4,5]);e.w8(source+4,typ);e.w32(source,sourceobj if typ==4 else ref)
 dest=rnd(c,8);typ=r.choice([0,0,1,3,4,4,255]);e.w8(dest+4,typ);e.w32(dest,old if typ==4 else r.getrandbits(32))
 handles=[rnd(c,8),rnd(c,8)]
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:source if em.reg('ecx')==handles[0] else dest)
 service=obj(c,0x20,{0x9c:pystub(c,2,this=True,ret=acquired)})
 sysobj(c,table_slots={0x134:pystub(c,0,this=True,ret=service)})
 inp=rnd(c,0x10);e.w32(inp+4,handles[0]);e.w32(inp+8,handles[1]);e.w32(inp+12,factory)
 return [inp]

def gc450(c):
 base(c);e=c.emu;r=c.rng
 source=rnd(c,8);dest=rnd(c,8);handles=[rnd(c,8),rnd(c,8)]
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:source if em.reg('ecx')==handles[0] else dest)
 def init(em,k):em.w32(em.reg('ecx'),em.arg32(0));em.w8(em.reg('ecx')+4,1)
 hook_rec(c,0x5002f0,1,this=True,side=init)
 hook_rec(c,0x50d7b0,1,this=True,deref={0:1},side=lambda em,k:em.w32(em.reg('ecx'),em.r32(em.arg32(0))))
 owner=rnd(c,0x20);ownerid=r.getrandbits(32)
 second=obj(c,0x20,{0x4c:pystub(c,1,this=True,ret=ownerid^1)})
 system=sysobj(c)
 alternate=pystub(c,1,this=True,ret=ownerid^2)
 change=r.randrange(4)
 def ownerfn(em,k):
  if change&1:em.w32(system+0x9b,second)
  if change&2:em.w32(em.r32(first)+0x4c,alternate)
  return owner
 item=obj(c,0x20,{0x1e0:pystub(c,1,this=True,ret=r.choice([0,1,0x100,0x101,255])),0x2f4:pystub(c,0,this=True,ret=ownerfn)})
 resolved=r.choice([0,item,item,item]);logger(c,nargs=2 if not resolved else 3)
 first=obj(c,0x20,{0x58:pystub(c,1,this=True,ret=resolved),0x4c:pystub(c,1,this=True,ret=ownerid)})
 e.w32(system+0x9b,first)
 inp=rnd(c,0x10);e.w32(inp+4,handles[0]);e.w32(inp+8,handles[1])
 return [inp]
S(0x50a860,'GUESS assign refcounted script object result','stdcall',None,ret=None,gen=ga860)
S(0x50c450,'GUESS return item owner id with cached lookup slot','stdcall',None,ret=None,gen=gc450)
