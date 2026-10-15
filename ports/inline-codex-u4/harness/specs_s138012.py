from pilot import S
from recruits_util import rnd,obj,pystub,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 values=rnd(c,44);elements=[rnd(c,8) for _ in range(11)];table=rnd(c,0x20)
 object=obj(c,0x20,{0x4c:pystub(c,0,this=True,ret=table)})
 factory=obj(c,0x20,{0x18:pystub(c,1,this=True,ret=r.choice([0,object,object,object]))})
 # Getter mutates the source after each original load; this catches reordered loads.
 def touch(em,k):em.w32(values+4*em.arg32(0),rvalues[em.arg32(0)])
 rvalues=[r.getrandbits(32) for _ in range(11)]
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:elements[em.arg32(0)],side=touch)
 def store(em,k):em.w32(em.reg('ecx'),em.arg32(0))
 hook_rec(c,0x500360,1,this=True,side=store)
 hook_rec(c,0x5002f0,1,this=True,side=store)
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [rnd(c,4),factory,r.getrandbits(32),values]
S(0x500630,'GUESS populateValues','thiscall',None,ret='eax',gen=gen)
