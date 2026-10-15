from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,ret=r.getrandbits(32),pop=0)
 s=rnd(c,0x60)
 slots={}
 for off,size in [(0x68,1),(0x74,36),(0x6c,12),(0x50,4),(0x40,4)]:
  data=bytes(r.getrandbits(8) for _ in range(size))
  def put(em,k,data=data):em.wbytes(em.arg32(0),data)
  slots[off]=pystub(c,1,this=True,stackmark=(0,),side=put)
 stream=obj(c,0x20,slots)
 data=rnd(c,16)
 ctx=obj(c,0x20,{0x3c0:pystub(c,2,this=True,stackmark=(0,),ret=data)})
 return [s,stream,ctx]
S(0x466eb0,'GUESS deserialize record','thiscall',None,ret='al',gen=gen)
