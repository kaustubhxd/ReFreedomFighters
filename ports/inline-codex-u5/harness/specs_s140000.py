from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 # Six paths: success, recoverable create failure, second create failure,
 # format failure, play failure, and failures after recovery.
 path=r.randrange(8)
 bad=r.choice([1,0x80004005,0x88780032,0xffffffff])
 buf=obj(c,0x20,{
  0x38:pystub(c,2,ret=bad if path in (3,6) else 0,deref={1:-18}),
  0x30:pystub(c,4,ret=bad if path in (4,7) else 0)})
 def create(em,k): em.w32(em.arg32(2),buf)
 dev=obj(c,0x20,{0xc:pystub(c,4,ret=lambda em,k:bad if (path in (1,2,5,6,7) and k==0) or path==2 else 0,deref={1:9},side=create)})
 # out pointer is an observable object field; recording it checks identity.
 me=rnd(c,0xa280);e.w32(me+0xa274,dev);e.w32(me+0xa278,buf)
 logger=obj(c,0x10,{0x2c:pystub(c,2,pop=0)})
 system=obj(c,0x10,{0x20:pystub(c,2,this=True,ret=logger)})
 e.w32(0x700390,system)
 hook_rec(c,0x54f2b0,0,pop=0,this=True,side=lambda em,k:em.calllog.append(('error',em.reg('edx'))))
 return [me]
S(0x54b4d0,'GUESS initialize sound buffer','thiscall',None,ret='al',gen=gen)
