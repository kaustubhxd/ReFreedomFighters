from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec
import struct

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,ret=r.getrandbits(32),pop=0)
 s=rnd(c,0x120);tab=rnd(c,0x4000);entry=rnd(c,0x60)
 idx=r.randrange(4096);ident=(r.getrandbits(20)<<12)|idx
 e.w32(s+0x68,tab);e.w32(tab+4*idx,entry)
 n=r.randrange(6);e.w32(s+0xec,n)
 for i in range(n):
  owner=rnd(c,0x10080);t=rnd(c,0x4000);other=rnd(c,0x40);data=rnd(c,0x90)
  e.w32(s+0xf0+4*i,owner);e.w32(owner+0x10071,t)
  e.w32(t+4*idx,other if r.randrange(3) else 0);e.w32(other+0x20,data)
 # Hook lookup to observe id and preserve the real mapping.
 hook_rec(c,0x64c7e0,1,this=True,ret=lambda em,k:em.r32(em.r32(em.reg('ecx')+0x10071)+4*(em.arg32(0)&4095)))
 vals=[r.choice([0.,0.25,1.,100.,1.e8,r.uniform(0.,1.e12)]) for _ in range(8)]
 rec=e.alloc(4*8,4)
 hook_rec(c,0x4e0830,0,this=True,side=lambda em,k:em.w32(rec+4*k,em.reg('edx')),st0=lambda em,k:vals[k])
 return [s,ident]
S(0x63eb90,'GUESS nearest owner distance','thiscall',None,ret='st0',gen=gen)
