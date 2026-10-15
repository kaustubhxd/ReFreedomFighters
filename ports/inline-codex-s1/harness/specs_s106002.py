from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 value=r.choice([0,1,r.getrandbits(32)])
 def out(em,k):em.w32(em.arg32(1),value)
 config=obj(c,0x20,{0x88:pystub(c,2,this=True,nullflag=(1,),side=out)})
 sys=sysobj(c,table_slots={0x138:pystub(c,0,this=True,ret=config)})
 e.w32(sys+0x1b5d,r.choice([0,1,1,2,0xffffffff]))
 me=rnd(c,0xa00);child=rnd(c,0x10);e.w32(me+0x54,child);e.w32(child+4,r.choice([0,3,3,4]))
 for addr,n in [(0x5aee60,1),(0x5afed0,2),(0x5af8f0,2),(0x5af990,4)]:hook_rec(c,addr,n,this=True)
 e.w32(0x7003b0,e.stub_fn('assert',lambda em,k:em.ret(eax=0)))
 return [me]
S(0x595100,'configure multiplayer bindings','thiscall',None,ret=None,gen=gen)
