import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,sysobj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 def floats(a,values):e.wbytes(a,struct.pack('<'+'f'*len(values),*values))
 owner=rnd(c,0xb0);floats(owner+0x9b,[r.choice([0.,1.,-2.,10.,640.,2048.])])
 nodes=[]
 for i in range(r.randrange(1,5)):
  xyz=[r.uniform(-1000,1000) for _ in range(3)]
  def fill(em,k,xyz=xyz):em.wbytes(em.arg32(0),struct.pack('<fff',*xyz))
  node=obj(c,0xb0,{
   0x1e0:pystub(c,1,this=True,ret=r.choice([0,1,1,1])),
   0x1a8:pystub(c,1,this=True,nullflag=[0],side=fill),
   0x20:pystub(c,0,this=True,ret=nodes[-1] if nodes else 0),
   0x2c4:pystub(c,0,this=True,ret=owner),
   0x358:pystub(c,1,this=True)})
  data=rnd(c,0x40);floats(data+0x24,[r.uniform(-500,500) for _ in range(3)])
  e.w32(node+8,data);nodes.append(node)
 me=nodes[-1]
 floats(me+0x9b,[r.choice([0.,-1.,1.,0.5,100.,2000.]),r.choice([0.,-2.,1.,0.25,200.,1500.])])
 target=obj(c,0x70,{0x23c:pystub(c,1,this=True,deref={0:4}),0x27c:pystub(c,1,this=True),0x250:pystub(c,0,this=True)})
 system=sysobj(c,table_slots={0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))})
 e.w32(system+0x6f,r.choice([320,640,1920,1]));e.w32(system+0x73,r.choice([240,480,1080,1]))
 return [me,0 if r.randrange(8)==0 else target]
S(0x4f7730,'GUESS bind normalized viewport','thiscall',None,ret=None,gen=gen)
