import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec,sysobj,reftab

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 def put(a,v):e.wbytes(a,struct.pack('<'+'f'*len(v),*v))
 me=rnd(c,0x50);point=rnd(c,12);put(point,[r.uniform(-10,10) for _ in range(3)])
 put(me+0x18,[r.uniform(0,10) for _ in range(3)]);put(me+0x24,[r.uniform(-10,10) for _ in range(3)])
 ids=list(range(1,r.randrange(1,7)));targets={}
 for id in ids:
  target=obj(c,0x20,{0x18c:pystub(c,1,this=True,deref={0:3},st0=r.choice([0.,-1.,1.,10.,float('nan'),r.uniform(-20,20)]))})
  data=rnd(c,0x40);put(data,[r.uniform(-2,2) for _ in range(9)]);put(data+0x24,[r.uniform(-10,10) for _ in range(3)])
  e.w32(target+8,data);targets[id]=r.choice([0,target,target])
 e.w32(me+0x44,reftab(c,ids) if r.randrange(4) else 0)
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:targets.get(em.arg32(0),0))})
 def record(em,k):
  p=em.reg('ecx');d=em.reg('edx');em.calllog.append(('box',tuple(em.r32(p+4*i) for i in range(3)),tuple(em.r32(d+4*i) for i in range(3))))
 hook_rec(c,0x4e2120,0,pop=0,this='mark',side=record,st0=r.uniform(-20,20))
 return [me,point]
S(0x440b20,'GUESS minimum distance to child volumes','thiscall',None,ret='st0',gen=gen)
