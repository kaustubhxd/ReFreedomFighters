from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;width=r.randrange(1,7);blocks=r.randrange(8);me=rnd(c,32);table=rnd(c,width*8*4);out=rnd(c,max(width*blocks,1)*4);input=rnd(c,32)
 e.w32(me,width);e.w32(me+12,table)
 for p,n in [(table,width*8),(out,max(width*blocks,1))]:e.wbytes(p,struct.pack('<'+'f'*n,*[r.uniform(-1000,1000) for _ in range(n)]))
 seq=[r.choice([-1,r.randrange(8),r.randrange(8),r.randrange(8)]) for _ in range(max(blocks,1))]
 def ret(em,k):return seq[k%len(seq)]
 def side(em,k):em.w32(input+4*(k%8),em.r32(input+4*(k%8))^0x12345678)
 hook_rec(c,0x405f20,2,pop=0,ret=ret,side=side);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,out,input,blocks*width+r.randrange(width)]
S(0x405fa0,'GUESS decode and accumulate transposed blocks','cdecl',None,ret='eax',gen=gen)
