from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger

def base(c):
 clear_hooks(c)
 c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def gf6e0(c):
 base(c);e=c.emu;r=c.rng
 def out(n):
  values=[r.getrandbits(32) for _ in range(n)]
  def write(em,k):
   for i,v in enumerate(values):em.w32(em.arg32(0)+4*i,v^(k*17))
  return pystub(c,1,this=True,side=write)
 refs=[r.getrandbits(32) for _ in range(4)]
 def refout(em,k):em.w32(em.arg32(0),refs[k])
 reader=obj(c,0x20,{0x70:pystub(c,1,this=True),0x74:out(9),0x6c:out(3),0x50:out(1),0x40:pystub(c,1,this=True,stackmark=(0,),side=refout)})
 targets={ref:r.choice([0,rnd(c,0x20)]) for ref in refs}
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:targets[em.arg32(0)])})
 me=rnd(c,0x140)
 hook_rec(c,0x440e10,1,this=True,ret=r.getrandbits(32))
 return [me,reader]

def g0b30(c):
 base(c);e=c.emu;r=c.rng
 logger(c,nargs=4)
 n=r.randrange(6);nodes=[rnd(c,0x800) for _ in range(n)]
 for j,node in enumerate(nodes):
  e.w32(node+4,nodes[j+1] if j+1<n else 0)
  cursor=node+0x10
  for k in range(r.randrange(6)):
   if r.randrange(2):
    length=r.choice([4,8,12,32]);e.w32(cursor+8,length);cursor+=16+length
   else:
    gap=r.choice([32,48,64]);e.w32(cursor+8,(-gap)&0xffffffff)
    e.w32(cursor+4,r.choice([0xffffffff,0,1,r.getrandbits(32)]))
    after=cursor+gap
    length=r.choice([4,8,12,32]);e.w32(after+0x18,length)
    cursor=after+0x20+length
  e.w32(cursor+8,0)
 me=rnd(c,0x8230);e.w32(me+0x8220,nodes[0] if nodes else 0);e.w32(me+0x8224,n+r.randrange(3))
 temporary=rnd(c,4*(n+4))
 hook_rec(c,0x41e290,1,pop=0,ret=temporary);hook_rec(c,0x634273,2,pop=0)
 return [me]
S(0x46f6e0,'GUESS load weapon template fields and four references','thiscall',None,ret='al',gen=gf6e0)
S(0x4d0b30,'GUESS collect allocation blocks and log free records','thiscall',None,ret=None,gen=g0b30)
