from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 dst=obj(c,0x20,{0xc:pystub(c,1,this=True),0x3c:pystub(c,1,this=True),0x4c:pystub(c,1,this=True)})
 vals=[rnd(c,8) for _ in range(r.randrange(7))]
 def begin(em,k):em.wbytes(em.arg32(0),bytes(12))
 def nxt(em,k):return vals[k] if k<len(vals) else 0
 src=obj(c,0x20,{0x14:pystub(c,0,this=True,ret=r.getrandbits(32)),0x4c:pystub(c,1,this=True,stackmark=(0,),side=begin),0x64:pystub(c,1,this=True,deref={0:3},ret=nxt),0x9c:pystub(c,1,this=True,st0=r.uniform(-10000,10000))})
 return [dst,src]
S(0x499fb0,'GUESS copy keyed float table','thiscall',None,ret=None,gen=gen)
