from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger

def base(c):
 clear_hooks(c);c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def gd9e0(c):
 base(c);e=c.emu;r=c.rng;logger(c,nargs=3)
 source=rnd(c,8);delta=rnd(c,8);dest=rnd(c,8)
 ref=r.getrandbits(32);typ=r.choice([0,1,2,3,3,4,4,5])
 refobj=obj(c,0x20,{0x34:pystub(c,0,this=True,ret=ref)})
 e.w8(source+4,typ);e.w32(source,refobj if typ==4 else ref)
 e.w32(delta,r.choice([0,1,0xffffffff,0x80000000,r.getrandbits(32)]))
 handles=[rnd(c,8),rnd(c,8)]
 def get(em,k):return dest if em.reg('ecx')==handles[1] else (delta if em.arg32(0) else source)
 hook_rec(c,0x5003d0,1,this=True,ret=get)
 hook_rec(c,0x5002f0,1,this=True,side=lambda em,k:em.w32(em.reg('ecx'),em.arg32(0)))
 prior=r.choice([0,1,0xffffffff,0x80000000,r.getrandbits(32)])
 query=obj(c,0x20,{0x88:pystub(c,2,this=True,deref={1:1},side=lambda em,k:em.w32(em.arg32(1),prior))})
 update=obj(c,0x20,{0x5c:pystub(c,3,this=True)})
 sysobj(c,table_slots={0x138:pystub(c,0,this=True,ret=lambda em,k:query if k==0 else update)})
 inp=rnd(c,0x10);e.w32(inp+4,handles[0]);e.w32(inp+8,handles[1])
 return [inp]

def gf4d0(c):
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
 sysobj(c,table_slots={0x138:pystub(c,0,this=True,ret=service)})
 inp=rnd(c,0x10);e.w32(inp+4,handles[0]);e.w32(inp+8,handles[1]);e.w32(inp+12,factory)
 return [inp]

S(0x50d9e0,'GUESS add to integer property and return old value','stdcall',None,ret=None,gen=gd9e0)
S(0x50f4d0,'GUESS assign refcounted script state-manager result','stdcall',None,ret=None,gen=gf4d0)
