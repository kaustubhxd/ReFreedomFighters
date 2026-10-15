from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def blocks(c):
 clear_hooks(c);e=c.emu;r=c.rng;s=rnd(c,0x30);tab=rnd(c,0x20);idx=r.randrange(8);e.w32(s+0x1d,tab)
 nodes=[]
 for i in range(r.randrange(4)):
  p=rnd(c,0x10);nodes.append(p)
  for j in range(3):e.w32(p+j*4,r.choice([0,r.getrandbits(32)]))
 for i,p in enumerate(nodes):e.w32(p+12,nodes[i+1] if i+1<len(nodes) else 0)
 e.w32(tab+idx*4,nodes[0] if nodes else 0)
 pool=[rnd(c,0x10) for _ in range(8)];fail=r.randrange(9)
 hook_rec(c,0x4e6bc0,0,this=True,ret=lambda em,k:pool[k] if k<fail else 0)
 n=r.randrange(16);src=rnd(c,max(4,4*n));return [s,idx,src,n]

def read_fields(c):
 clear_hooks(c);e=c.emu;r=c.rng;s=rnd(c,0xb0);p=rnd(c,0x20)
 hook_rec(c,0x44edd0,1,this=True);hook_rec(c,0x4e1b30,0,this=True)
 values=[r.getrandbits(32) for _ in range(14)]
 hook_rec(c,0x4e12e0,2,this=True,side=lambda em,k:em.w32(em.arg32(0),values[k]))
 hook_rec(c,0x4e1440,1,this=True,side=lambda em,k:em.w32(em.arg32(0),values[k+10]))
 hook_rec(c,0x4e1600,0,this=True,ret=r.choice([0,8,0x108,7,9]))
 return [s,p]
S(0x49c310,'GUESS append reversed words to block chain','thiscall',None,ret='eax',gen=blocks,note='batch130002')
S(0x4f5b70,'GUESS deserialize extended fields','thiscall',None,ret=None,gen=read_fields,note='batch130002')
