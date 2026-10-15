import zlib
from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,reftab

def base(c):
 clear_hooks(c)
 c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))
 c.emu.hook(0x633654,lambda e,r:e.ret(eax=e.reg('eax'),argbytes=0))

def gfb50(c):
 base(c);e=c.emu;r=c.rng
 new=rnd(c,0x188)
 hook_rec(c,0x41e290,1,pop=0,ret=new)
 hook_rec(c,0x634273,2,pop=0)
 def fill(em,k):em.wbytes(em.arg32(0),bytes([em.arg32(1)&255])*em.arg32(2))
 hook_rec(c,0x634d10,3,pop=0,side=fill,ret=lambda em,k:em.arg32(0))
 def fmt(em,k):
  form=em.arg32(1);num=em.arg32(2)
  text=(('*_0%d*' if form==0x6aed14 else '*_%d*')%num).encode()+b'\0'
  em.wbytes(em.arg32(0),text)
 hook_rec(c,0x42ac56,3,pop=0,stackmark=(0,),side=fmt)
 def find(em,k):
  text=em.rbytes(em.arg32(1),16).split(b'\0')[0]
  em.calllog.append(('find_sound',em.reg('ecx'),em.arg32(0),text))
  return zlib.crc32(text)^em.arg32(0)
 sound=obj(c,0x20,{0x60:pystub(c,2,this=True,stackmark=(1,),ret=find)})
 system=sysobj(c);e.w32(system+0x1a9f,r.choice([0,sound,sound]))
 me=obj(c,0x960,{0x680:pystub(c,0,this=True,ret=r.choice([0,r.getrandbits(32)]))})
 e.w8(me+0x93e,r.choice([0,0,0,1,2,255]))
 e.w32(me+0x936,rnd(c,0x188))
 return [me]

def g7350(c):
 base(c);e=c.emu;r=c.rng
 ids=[r.getrandbits(32) for _ in range(r.randrange(6))]
 entries=[];actors={}
 for ident in ids:
  entry=rnd(c,0x10);e.w32(entry,ident);entries.append(entry)
  actors[ident]=obj(c,0x20,{0x128:pystub(c,3,this=True)})
 key=r.getrandbits(32)|1
 members=reftab(c,entries,find={key:r.choice(entries)} if entries else {})
 group=rnd(c,0x10);e.w32(group+4,0 if r.randrange(4)==0 else members)
 formation=r.getrandbits(32)
 groups=obj(c,0x20,{0x2c:pystub(c,1,this=True,ret=r.choice([0,group,group]))})
 me=rnd(c,0x60);e.w32(me+0x48,groups)
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:actors[em.arg32(0)])})
 # A nonzero member requires a valid member table; zero may exercise the null table guard.
 member=r.choice([0,0,key,key^2])
 if member:e.w32(group+4,members)
 return [me,formation,member,r.getrandbits(32),rnd(c,0x20)]
S(0x59fb50,'GUESS expand actor soundset once','thiscall',None,ret=None,gen=gfb50)
S(0x5b7350,'GUESS send formation event to one member or all','thiscall',None,ret=None,gen=g7350)
