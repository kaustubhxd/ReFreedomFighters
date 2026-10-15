from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 me=rnd(c,0x180)
 values=[r.getrandbits(32) for _ in range(61)]
 switches=[r.randrange(2) for _ in range(61)]
 managers=[]
 def side(em,k):
  em.calllog.append(('lookup',em.reg('ecx'),em.arg32(0)))
  em.w32(me+0x57,managers[switches[min(k,60)]])
 for j in range(2):
  managers.append(obj(c,32,{0x14:pystub(c,1,this=True,side=side,ret=lambda em,k:values[min(k,60)])}))
 e.w32(me+0x57,managers[r.randrange(2)])
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x5b5420,'GUESS load named action handles','thiscall',None,ret='eax',gen=g,note='batch128005')
