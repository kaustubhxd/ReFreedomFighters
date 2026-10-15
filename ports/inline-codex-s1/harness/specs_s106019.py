from pilot import S,SENTINELS
from pe_emu import STACK_TOP
from recruits_util import rnd,clear_hooks,hook_rec,stub_memmove,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 me=rnd(c,16);dst=rnd(c,80);src=rnd(c,80)
 cap=r.randrange(33);n=r.choice([0,cap,cap+1,r.randrange(65)])
 e.w32(me,dst);e.w32(me+4,dst+cap)
 frame=STACK_TOP-0x100;e.w32(frame-4,SENTINELS['ebx']);e.w32(frame,STACK_TOP-0x80);e.w32(frame+4,e.RET_ADDR);e.w32(frame+8,src);e.w32(frame+12,r.getrandbits(32))
 def copy(em,k):
  d,s,n=em.arg32(0),em.arg32(1),em.arg32(2);em.wbytes(d,em.rbytes(s,n))
 hook_rec(c,0x634d22,3,pop=0,side=copy)
 hook_rec(c,0x5f2c60,2,this=True)
 stub_memmove(c);e.w32(0x7003b0,pystub(c,0))
 return [me,src+n,src+r.randrange(65),frame,frame-4]
S(0x5f2d69,'partial-frame string assign',('regs',['ecx','eax','ebx','ebp','esp']),None,ret='eax',gen=gen)
