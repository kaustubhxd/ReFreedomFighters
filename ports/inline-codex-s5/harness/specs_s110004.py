from pilot import S
from recruits_util import rnd,obj,pystub,hook_rec,clear_hooks

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 mat=[r.uniform(-50,50) for _ in range(9)];pos=[r.uniform(-50,50) for _ in range(3)]
 def fill(em,n):
  for j,v in enumerate(mat):em.wf32(em.arg32(0)+4*j,v)
  for j,v in enumerate(pos):em.wf32(em.arg32(1)+4*j,v)
 handle=rnd(c,0x40)
 t=obj(c,0x160,{0x3b8:pystub(c,2,this=True,nullflag=(0,1),side=fill,ret=123),0x3b4:pystub(c,2,this=True,nullflag=(0,1),side=fill,ret=456),0x390:pystub(c,1,this=True),0x20:pystub(c,6,this=True,deref={0:9,1:3},ret=handle)})
 root=rnd(c,0x30)
 for i,v in enumerate(mat+pos):e.wf32(root+4*i,v)
 e.w32(t+8,root)
 for off in (0x144,0x146):e.w8(t+off,r.randrange(2))
 for off in (0x147,0x14b,0x14f):e.w32(t+off,r.choice([0,r.getrandbits(32)]))
 returns=r.choice([[0,0],[0,111],[222,333]])
 dll=obj(c,0x20,{0x58:pystub(c,2,this=True,ret=lambda em,n:returns[min(n,1)]),0x5c:pystub(c,1,this=True,ret=r.getrandbits(32))})
 db=obj(c,0x20,{0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))})
 sys=rnd(c,0x1ac0);e.w32(sys+0x9b,db);e.w32(sys+0x1a9f,r.choice([0,dll,dll,dll]));e.w32(0x70039c,sys)
 hook_rec(c,0x43ec00,0,this=True,ret=r.getrandbits(32))
 return [t,r.choice([0,1,256,257,r.getrandbits(32)])]
S(0x4670b0,'ZIKLNKOBJ PlaySoundFootStep','thiscall',None,ret='eax',gen=gen)
