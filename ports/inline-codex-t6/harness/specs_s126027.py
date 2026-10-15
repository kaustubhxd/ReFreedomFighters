from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0x200);root=rnd(c,0x30);nested=rnd(c,0x90);e.w32(me+0x44,root);e.w32(root+0x18,nested)
 def config(em,k):em.w32(em.arg32(1),0x100+k)
 cfg=obj(c,0x20,{0x88:pystub(c,2,this=True,nullflag=(1,),side=config)})
 target=obj(c,0x20,{0x130:pystub(c,3,deref={2:3})});ret1=r.choice([0,target,target]);ret2=r.getrandbits(32)
 so=sysobj(c,table_size=0xb00,table_slots={0x138:pystub(c,0,this=True,ret=cfg),0x58:pystub(c,1,this=True,ret=lambda em,k:ret1 if k==0 else ret2),0x114:pystub(c,4,this=True,ret=r.getrandbits(32))})
 text=rnd(c,0x20);e.w32(e.r32(so+0x9b)+0xae4,r.choice([0,text,text]));handle=rnd(c,0x20)
 hook_rec(c,0x49df60,2,this=True,nullflag=(1,),ret=r.choice([0,handle,handle]));hook_rec(c,0x49df30,0,this=True);hook_rec(c,0x49e0d0,0,this=True,ret=r.getrandbits(32))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x4c2f00,'GUESS resolve text and register UI event','thiscall',None,ret=None,gen=gen)
