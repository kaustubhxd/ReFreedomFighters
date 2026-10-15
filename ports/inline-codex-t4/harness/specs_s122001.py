from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,ret=r.getrandbits(32),pop=0)
 # Observe all 53 by-value bytes (the final 3 ABI padding bytes are unspecified).
 rec=e.alloc(8*64+4,4)
 def side(em,k):
  em.w32(rec+64*k,em.reg('edx'))
  em.wbytes(rec+64*k+4,em.rbytes(em.reg('esp')+8,53))
 hook_rec(c,0x4adc70,1,this=True,pop=60,side=side)
 count=r.randrange(0,9)
 p=rnd(c,53*10)
 return [p,p+53*count]
S(0x4ae460,'GUESS pop heap record range','fastcall',None,ret=None,gen=gen)
