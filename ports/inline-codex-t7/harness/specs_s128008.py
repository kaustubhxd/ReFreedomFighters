from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 me=rnd(c,0x8230);arena=rnd(c,4096);size=r.choice([16,32,64,128,256]);ps=r.choice([16,32,64]);ns=r.choice([16,32,64])
 prev=arena+256;block=prev+ps+16;next=block+size+16;tail=next+ns+16
 before=r.choice([0,ps,(-ps)&0xffffffff]);after=r.choice([0,ns,(-ns)&0xffffffff]);isolated=r.randrange(12)==0
 if isolated:before=0xffffffff
 for p in [prev,block,next,tail]:
  e.w32(p+8,0);e.w32(p+12,0)
 e.w32(prev+8,before);e.w32(block+8,(-size)&0xffffffff);e.w32(block+12,before)
 e.w32(next+8,after);e.w32(next+12,(-size)&0xffffffff);e.w32(tail+8,0)
 # Page list links may point to valid neighboring pages.
 left=r.choice([0,rnd(c,32)]);right=r.choice([0,rnd(c,32)])
 page=block-16
 if before==ps:page=prev-16
 e.w32(page,left);e.w32(page+4,right)
 e.w32(me+0x20f,r.choice([0xffffffff,block-16,arena,arena+2000]))
 e.w32(me+0x8217,r.choice([16,32,64,128,256]))
 e.w32(me+0x1c8,r.choice([0,1,10,11]))
 existing=rnd(c,32);new=rnd(c,32);oldhead=r.choice([0,rnd(c,32)])
 e.w32(existing+17,oldhead)
 tree=obj(c,32,{8:pystub(c,2,this=True,ret=r.choice([0,existing])),0:pystub(c,1,this=True)})
 e.w32(me+0x1cc,e.r32(tree))
 hook_rec(c,0x4d0c70,2,this=True)
 hook_rec(c,0x4d0b10,0,this=True)
 hook_rec(c,0x4d0950,1,this=True)
 hook_rec(c,0x4d0630,0,this=True,ret=new)
 e.w32(0x6762ec,pystub(c,1,pop=0))
 lg=obj(c,32,{0x2c:pystub(c,2,pop=0)})
 e.w32(0x700390,obj(c,32,{0x20:pystub(c,2,this=True,ret=lg)}))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,block+16]
S(0x4cfdb0,'GUESS pool release and coalesce','thiscall',None,ret=None,gen=g,note='batch128008')
