from pilot import S
from recruits_util import rnd,obj,pystub,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);r=c.rng
 def record(em,k):em.calllog.append(('serialized_word',em.arg32(0)))
 writer=obj(c,0x20,{off:pystub(c,1,this=True,side=record,ret=r.getrandbits(32)) for off in [0x44,0x4c]})
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [rnd(c,0xa0),writer]
S(0x4bd7f0,'GUESS serializeMaterial','thiscall',None,ret='al',gen=gen)
