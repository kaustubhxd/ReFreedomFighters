from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub,obj

def load(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 self=obj(c,0x90,{0x330:pystub(c,0,this=True)})
 blob=rnd(c,0x800);cursor=blob
 for i in range(5):
  size=r.choice([0,0,1,15,16,17,31,32,63,80]);e.w32(cursor,size)
  cursor+=16 if not size else 32+((size+15)&~15)
 blocks=[rnd(c,24) for _ in range(5)]
 vt=e.alloc(0x18,4);e.w32(vt+0x14,pystub(c,1,this=True))
 hook_rec(c,0x41e290,1,pop=0,ret=lambda em,k:blocks[k])
 def setup(em,k):em.w32(em.reg('ecx'),vt)
 hook_rec(c,0x4e3d60,1,this=True,side=setup)
 def vec(em,k):em.wbytes(em.reg('ecx')+4,em.rbytes(em.arg32(0),12))
 hook_rec(c,0x4e3360,1,this=True,deref={0:3},side=vec)
 return [self,blob]
S(0x443570,'GUESS_load_five_serialized_entries','thiscall',None,ret='eax',gen=load)
