import struct
from pilot import S
from recruits_util import rnd,obj,pystub,clear_hooks,sysobj,reftab_vt,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 mat=[r.uniform(-10,10) for _ in range(9)];pos=[0.,0.,0.]
 for i in [2,4,6]:mat[i]=1.
 branch=r.randrange(10)
 if branch<3:mat[[2,4,6][branch]]=r.choice([0.,-1.,float('nan')])
 elif branch<6:pos[branch-3]=r.choice([1.,-1.,float('nan')])
 def transform(em,k):
  em.wbytes(em.arg32(0),struct.pack('<9f',*mat));em.wbytes(em.arg32(1),struct.pack('<3f',*pos))
 source=obj(c,0x40,{0x80:pystub(c,2,this=True,stackmark=(0,1),side=transform)})
 s=obj(c,0x80,{0x58:pystub(c,0,this=True)})
 e.w32(s+0x44,source)
 ids=list(range(r.randrange(6)));actors={};links={};valid={}
 for idx in ids:
  chain=[]
  for j in range(r.randrange(5)):
   target=obj(c,0x20,{0x34c:pystub(c,1,this=True)})
   node=rnd(c,0x60);e.w32(node+0x54,target);chain.append(node);valid[node]=r.randrange(2)
  for j,node in enumerate(chain):links[node]=chain[j+1] if j+1<len(chain) else 0
  def nxt(em,k):em.w32(em.arg32(0),links.get(em.r32(em.arg32(0)),0))
  actor=obj(c,0x40,{0x1e0:pystub(c,1,this=True,ret=r.randrange(2)),0x29c:pystub(c,1,this=True,deref={0:1},side=nxt)})
  e.w32(actor+8,chain[0] if chain else 0);actors[idx]=actor
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:actors[em.arg32(0)])})
 e.w32(s+0x48,reftab_vt(c,ids))
 hook_rec(c,0x4db9a0,1,this=True,ret=lambda em,k:valid.get(em.reg('ecx'),0))
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [s]
S(0x4c5a10,'GUESS propagateTransform','thiscall',None,ret=None,gen=gen)
