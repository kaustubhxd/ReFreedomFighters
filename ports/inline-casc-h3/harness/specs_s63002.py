from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def read6(c):
 clear_hooks(c)
 def side(em,k): em.w32(em.arg32(0),0x12340000+k)
 return [rnd(c,24),obj(c,0x20,{0x50:pystub(c,1,this=True,side=side)})]
def broadcast(c):
 clear_hooks(c); e=c.emu; r=c.rng
 root=obj(c,0x60,{0x1e0:pystub(c,1,this=True,ret=r.randrange(2))}); nodes=[rnd(c,0x64) for _ in range(r.randrange(5))]
 e.w32(root+0x50,nodes[0] if nodes else 0)
 for i,node in enumerate(nodes):
  item=obj(c,0x20,{0x1e0:pystub(c,1,this=True,ret=r.randrange(2)),0x284:pystub(c,1,this=True)})
  e.w32(node+0x54,item); e.w32(node+0x60,nodes[i+1] if i+1<len(nodes) else 0)
 return [rnd(c,0x20),r.choice([root,root,0]),r.getrandbits(32)]
def readstate(c):
 clear_hooks(c); r=c.rng; vals=[r.choice([0,1,2,0xffffffff]) for _ in range(2)]
 hook_rec(c,0x610100,1,this=True)
 def side(em,k): em.w32(em.arg32(0),vals[k])
 hook_rec(c,0x4e12e0,2,this=True,stackmark=(0,),side=side)
 hook_rec(c,0x4e1b30,0,this=True)
 return [rnd(c,0x30),rnd(c,0x20)]
def check(c):
 clear_hooks(c); e=c.emu; r=c.rng; s=rnd(c,0xa0); ctx=rnd(c,0x30)
 hook_rec(c,0x602d30,0,pop=0,ret=ctx)
 hook_rec(c,0x602c50,1,this=True,ret=r.randrange(2))
 def side(em,k):
  if em.arg32(1)==0x6b95b4: em.calllog.append(('value',em.arg32(2)))
 log=obj(c,0x20,{0xc:pystub(c,2,pop=0,side=side)})
 hook_rec(c,0x5fa630,0,pop=0,ret=log)
 return [s]
S(0x524780,'GUESS read six dwords','thiscall',None,ret='al',gen=read6,note='batch63002')
S(0x563650,'GUESS broadcast to typed children','thiscall',None,ret=None,gen=broadcast,note='batch63002')
S(0x5a65f0,'GUESS read two flag state','thiscall',None,ret=None,gen=readstate,note='batch63002')
S(0x5fe4e0,'GUESS check identifier and log failure','thiscall',None,ret='al',gen=check,note='batch63002')
