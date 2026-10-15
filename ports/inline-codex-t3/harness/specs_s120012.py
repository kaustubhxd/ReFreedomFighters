from pilot import S
from recruits_util import rnd,clear_hooks,pystub,obj,hook_rec

def reset(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 self=e.alloc(0x18200,4);e.wbytes(self,r.randbytes(0x18200))
 vt=e.alloc(0x34,4)
 for off,n in ((0x2c,1),(0x30,0)):e.w32(vt+off,pystub(c,n,this=True))
 e.w32(self,vt)
 blocks=[]
 for i in range(r.randint(0,3)):
  n=r.randint(1,4);b=rnd(c,16+4*n);e.w32(b,n);blocks.append(b)
  for j in range(n):e.w32(b+16+4*j,rnd(c,0x30))
 for i,b in enumerate(blocks):e.w32(b+8,blocks[i+1] if i+1<len(blocks) else 0)
 def begin(em,k):
  p=em.arg32(0);b=blocks[0] if blocks else 0
  for i,v in enumerate((b+16 if b else 0,0,b)):em.w32(p+4*i,v)
 getter=pystub(c,1,this=True,stackmark=(0,),side=begin,ret=lambda em,k:em.arg32(0))
 ivt=e.alloc(16,4);e.w32(ivt+12,getter);e.w32(self+12,ivt)
 e.w32(self+0x10165,obj(c,0x20,{0x14:pystub(c,0,this=True)}))
 count=r.randint(0,6);e.w32(self+0x10089,count)
 for i in range(count):
  ctl=obj(c,0x20,{0x258:pystub(c,0,this=True,ret=(r.getrandbits(24)<<8)|r.choice([0,1,255]))})
  mid=rnd(c,0x20);e.w32(mid+12,r.choice([0,ctl]));entry=rnd(c,0x20);e.w32(entry+12,mid)
  e.w32(self+0x1008d+4*i,entry)
 hook_rec(c,0x64e150,1,this=True)
 return [self]
S(0x64c800,'GUESS_reset_render_entries_and_rebuild','thiscall',None,ret=None,gen=reset)
