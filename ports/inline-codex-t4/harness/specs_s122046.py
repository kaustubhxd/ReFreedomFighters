from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 s=rnd(c,0xa0);table=rnd(c,21*9);e.w32(s+0x98,table);n=r.randrange(2,8)
 for i in range(9):e.w16(table+21*i+16,0);e.w16(table+21*i+18,0)
 for i in range(1,n+1):
  e.w16(table+21*i+16,i+1 if i<n else 0);e.w16(table+21*i+18,i-1);e.wbytes(table+21*i+10,struct.pack('<f',float(i)))
 index=r.choice([8,r.randrange(2,n+1)]);e.wbytes(table+21*index+10,struct.pack('<f',r.choice([0.,1.,3.,10.,r.uniform(-2,10)])))
 return [s,1,index|(r.getrandbits(16)<<16)]
S(0x52d250,'GUESS insert or reposition priority entry','thiscall',None,ret=None,gen=gen)
