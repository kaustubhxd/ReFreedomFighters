from pilot import S
from recruits_util import rnd,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 stride=r.randrange(1,9);channels=r.randrange(0,7);rows=r.randrange(0,8);start=r.randrange(6);desc=rnd(c,16);e.w32(desc,start);e.w32(desc+4,start+rows*stride);e.w32(desc+8,stride);ctx=rnd(c,0x40);e.w32(ctx,desc)
 table=rnd(c,4*max(channels,1))
 for i in range(channels):e.w32(table+4*i,rnd(c,512))
 allocs=[rnd(c,4*max(channels,1))]+[rnd(c,4*max(rows,1)) for _ in range(channels)];hook_rec(c,0x401820,2,pop=0,ret=lambda em,k:allocs[k])
 fn=pystub(c,5,pop=0,deref={0:stride},ret=lambda em,k:sum(em.r32(em.arg32(0)+4*j) for j in range(stride))&0xffffffff)
 return [rnd(c,32),ctx,table,channels,fn]
S(0x409400,'GUESS transform_interleaved_rows','cdecl',None,ret='eax',gen=gen)
