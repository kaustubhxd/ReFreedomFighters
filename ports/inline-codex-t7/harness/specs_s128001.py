from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 a=rnd(c,32);e.wbytes(a+12,bytes([r.choice([0,1,255])]))
 stop=r.choice([-1,-1,0,1,6,7,8,25,51,52,r.randrange(53)])
 def side(em,k):
  em.calllog.append(('method',em.reg('ecx'),em.arg32(0)))
  if k==stop:em.wbytes(a+12,b'\0')
 s=obj(c,32,{0x48:pystub(c,1,this=True,side=side),0x44:pystub(c,1,this=True)})
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [s,a]
S(0x557350,'GUESS CFFTools_if addMethodDefinitions','thiscall',None,ret=None,gen=g,note='batch128001')
