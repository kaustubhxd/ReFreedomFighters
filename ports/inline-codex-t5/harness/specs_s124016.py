from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 objs=[]
 for _ in range(r.randrange(7)):
  data=rnd(c,0x20);e.w32(data,r.choice([0,1,2,3,0xffffffff]))
  item=obj(c,0x20,{0x84:pystub(c,0,this=True,ret=data)})
  objs.append(obj(c,0x20,{0x104:pystub(c,1,this=True,ret=r.choice([0,item,item]))}))
 def begin(em,k):
  for i in range(3):em.w32(em.arg32(0)+i*4,0)
 def advance(em,k):em.w32(em.arg32(0),1 if k<len(objs) else 0)
 listing=obj(c,16,{0x4c:pystub(c,1,this=True,stackmark=[0],side=begin),0x5c:pystub(c,1,this=True,stackmark=[0],side=advance,ret=lambda em,k:k+1)})
 table=obj(c,16,{0x58:pystub(c,1,this=True,ret=lambda em,k:objs[em.arg32(0)-1])})
 sys=rnd(c,0xb0);e.w32(0x70039c,sys);e.w32(sys+0x9b,table)
 me=obj(c,0x1d0,{0x94:pystub(c,2,this=True,deref={1:3})});e.w32(me+0xfc,e.r32(listing))
 return [me,r.getrandbits(32)]
S(0x4c2ab0,'GUESS send music category information','thiscall',None,ret=None,gen=g,note='batch124016')
