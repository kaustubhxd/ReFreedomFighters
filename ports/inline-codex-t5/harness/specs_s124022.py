from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 hook_rec(c,0x633654,0,pop=0,ret=lambda em,k:em.reg("eax"))
 def put(em,k):em.calllog.append(('put',em.reg('ecx'),em.arg32(0)))
 hook_rec(c,0x5f01c0,1,this=True,side=put)
 for addr in [0x5af1d0,0x5af230,0x5aefc0]:
  tab={i:r.getrandbits(32) for i in range(32)}
  hook_rec(c,addr,1,this=True,ret=lambda em,k,t=tab:t[em.arg32(0)])
 me=rnd(c,0x60);buf=rnd(c,16);e.wbytes(buf+12,bytes([r.choice([0,1,2])]))
 return [me,buf]
S(0x5b06b0,'GUESS serialize player inventory','thiscall',None,ret='al',gen=g,note='batch124022',tries=2)
