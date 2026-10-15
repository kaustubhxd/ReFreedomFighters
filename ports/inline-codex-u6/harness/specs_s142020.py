import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 me=rnd(c,0x1800)
 def fp(n):return struct.pack('<'+'f'*n,*[r.uniform(-100,100) for _ in range(n)])
 e.wbytes(me,fp(12));e.w32(me+0x8c,r.choice([-1,0,1,2,3])&0xffffffff);e.w32(me+0x90,r.choice([-1,0,1,2,3])&0xffffffff)
 values=[fp(3) for _ in range(6)]
 hook_rec(c,0x516230,1,this=True,stackmark=(0,),side=lambda em,k:em.wbytes(em.arg32(0),values[k]))
 hook_rec(c,0x52a220,1,this=True);hook_rec(c,0x52a270,1,this=True)
 return [me]
S(0x526cf0,'GUESS car wheel vertical position refresh','thiscall',None,ret=None,gen=gen)
