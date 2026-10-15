from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 a=rnd(c,32)
 e.wbytes(a+12,bytes([r.choice([0,1,2,255])]))
 e.w32(0x7018d8,r.choice([0,1,33,34,35,48,49,50,51,0xffffffff,r.randrange(52)]))
 e.wbytes(0x7018e0,bytes(r.getrandbits(8) for _ in range(200)))
 # Both diagnostics and assertions may disable registration or alter the queue index.
 def diag(em,k):
  if k==0 and mode==1:em.wbytes(a+12,b'\0')
 def assertion(em,k):
  if mode==2:em.w32(0x7018d8,0)
 mode=r.randrange(4)
 s=obj(c,32,{0x44:pystub(c,1,this=True,side=diag)})
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32),side=assertion))
 hook_rec(c,0x519ea0,1,this=True,ret=r.getrandbits(32),deref={0:8})
 return [s,a]
S(0x51ed20,'GUESS ZHeliIf addMethodDefinitions','thiscall',None,ret='eax',gen=g,note='batch128000')
