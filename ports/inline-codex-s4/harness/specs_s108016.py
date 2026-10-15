from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def base(c):
 clear_hooks(c);e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))
 e.hook(0x633654,lambda em,rr:em.ret(eax=em.reg('eax'),argbytes=0))

def gee30(c):
 base(c);e=c.emu;r=c.rng
 value=rnd(c,8);hook_rec(c,0x5003d0,1,this=True,ret=value)
 matrix=[r.getrandbits(32)&0xfeffffff for _ in range(9)];pos=[r.getrandbits(32)&0xfeffffff for _ in range(3)]
 def out(em,k):
  for i,v in enumerate(matrix):em.w32(em.arg32(0)+4*i,v)
  for i,v in enumerate(pos):em.w32(em.arg32(1)+4*i,v)
 target=obj(c,0x20,{0x80:pystub(c,2,this=True,stackmark=(0,1),side=out),0x1e0:pystub(c,1,this=True,ret=r.choice([0,1,0x100,0x101,255]))})
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=r.choice([0,target,target]))})
 def adjust(em,k):
  for arg,n in ((1,9),(2,3)):
   p=em.arg32(arg)
   for i in range(n):em.w32(p+4*i,em.r32(p+4*i)^0x1234567)
 hook_rec(c,0x55f900,3,this=True,deref={1:9,2:3},side=adjust)
 record=rnd(c,0x20)
 hero=obj(c,0x20,{0x370:pystub(c,2,this=True,deref={0:9,1:3}),0x20:pystub(c,0,this=True,ret=record)})
 me=rnd(c,0x30);e.w32(me+0x18,hero)
 log=obj(c,0x20,{0x30:pystub(c,3,pop=0)})
 channel=obj(c,0x20,{0x20:pystub(c,2,ret=log,this=True)});e.w32(0x700390,channel)
 inp=rnd(c,0x10);e.w32(inp+4,rnd(c,8))
 return [me,inp]

def geeb0(c):
 base(c);e=c.emu;r=c.rng
 slots={}
 for slot,size,stack in ((0x40,4,True),(0x48,4,True),(0x50,4,False),(0x68,1,False),(0x6c,12,False),(0x18,24,False)):
  data=[bytes(r.getrandbits(8) for _ in range(size)) for _ in range(4)]
  def write(em,k,data=data):em.wbytes(em.arg32(0),data[k%4])
  slots[slot]=pystub(c,2 if slot==0x18 else 1,this=True,stackmark=(0,) if stack else (),side=write)
 reader=obj(c,0x20,slots)
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=r.choice([0,rnd(c,0x20)]))})
 return [rnd(c,0x40),reader]
S(0x55ee30,'GUESS beam hero to reference transform','thiscall',None,ret=None,gen=gee30)
S(0x5beeb0,'GUESS load packed formation element with resolved reference','thiscall',None,ret='al',gen=geeb0)
