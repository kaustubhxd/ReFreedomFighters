from pilot import S
from recruits_util import rnd,clear_hooks,pystub,obj,sysobj

def deactivate(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 entries=[rnd(c,8) for _ in range(r.randint(0,6))]
 holders={};dues={}
 now=r.randint(-1000000,1000000)
 for i,p in enumerate(entries):
  e.w32(p,i+1)
  holder=obj(c,0x20,{0x210:pystub(c,1,this=True)})
  holders[i+1]=r.choice([0,holder,holder]);dues[p]=r.choice([now/1024.0-1,now/1024.0,now/1024.0+1,float('nan'),r.uniform(-2000,2000)])
 sys=sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:holders[em.arg32(0)])});e.w32(sys+0x40,now&0xffffffff)
 def begin(em,k):em.wbytes(em.arg32(0),bytes(12))
 def nxt(em,k):
  p=em.arg32(0);i=em.r32(p);em.w32(p,i+1)
  return entries[i] if i<len(entries) else 0
 ctl=obj(c,0x20,{0x4c:pystub(c,1,this=True,stackmark=(0,),side=begin),0x64:pystub(c,1,this=True,deref={0:1},ret=nxt),0x44:pystub(c,1,this=True,deref={0:1}),0x9c:pystub(c,1,this=True,st0=lambda em,k:dues[em.arg32(0)])})
 self=rnd(c,0x90);e.w32(self+0x74,r.choice([0,ctl,ctl,ctl]))
 for off in (0x70,0x6c):e.w32(self+off,obj(c,0x20,{0x40:pystub(c,1,this=True)}))
 return [self]
S(0x471930,'ZItem::UpdateDeactivate','thiscall',None,ret=None,gen=deactivate)
