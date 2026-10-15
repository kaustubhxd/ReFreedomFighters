from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 def print_(em,res):
  n=2 if em.arg32(1)==0x69d6dc else 3
  em.calllog.append(('log',tuple(em.arg32(i) for i in range(n))));em.ret(0,0)
 lo=obj(c,32,{0x2c:e.stub_fn('log',print_)});lg=obj(c,32,{0x20:pystub(c,2,this=True,ret=lo)});e.w32(0x700390,lg)
 out=rnd(c,8);inp=rnd(c,16)
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:out if em.reg('ecx')==output else inp)
 hook_rec(c,0x5002f0,1,this=True,side=lambda em,k:em.w32(em.reg('ecx'),em.arg32(0)))
 actor=obj(c,32,{0x1e0:pystub(c,1,this=True,ret=r.randrange(2)),0x2f4:pystub(c,0,this=True,ret=r.randrange(2)),0x2f0:pystub(c,3,this=True)})
 other=obj(c,32,{0x20:pystub(c,0,this=True,ret=r.getrandbits(32))})
 rets=[actor if r.randrange(4) else 0,other if r.randrange(2) else 0]
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:rets[min(k,1)])})
 args=rnd(c,16);output=rnd(c,16);e.w32(args+8,output)
 return [rnd(c,16),args]
S(0x50bbb0,'GUESS assign_actor_owner','thiscall',None,ret=None,gen=gen)
