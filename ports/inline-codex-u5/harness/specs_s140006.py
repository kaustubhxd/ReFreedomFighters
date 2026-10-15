import struct
from pilot import S,F
from recruits_util import rnd,obj,clear_hooks,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 def put(a,v):e.wbytes(a,struct.pack('<'+'f'*len(v),*v))
 def mat():return [r.uniform(-1,1) for _ in range(9)]
 m=mat();p=[r.uniform(-10,10) for _ in range(3)]
 def transform(em,k):put(em.arg32(0),m);put(em.arg32(1),p)
 me=obj(c,0x140,{0x80:pystub(c,2,this=True,nullflag=[0,1],side=transform)})
 state=rnd(c,0x20);timeline=rnd(c,0x20);put(timeline+4,[r.uniform(-10,10)])
 e.w32(state+0x14,timeline);e.w32(state+4,r.getrandbits(32));e.w32(me+0x1c,state)
 q=[r.uniform(-1,1) for _ in range(4)];v=[r.uniform(-10,10) for _ in range(3)]
 def sample(em,k):put(em.arg32(2),v);put(em.arg32(3),q)
 animator=obj(c,0x20,{0xc:pystub(c,5,this=True,nullflag=[2,3],side=sample)})
 e.w32(me+0x5c,animator)
 rotation=rnd(c,36);put(rotation,mat());position=rnd(c,12);put(position,[r.uniform(-10,10) for _ in range(3)])
 return [me,rotation,position,F(r.choice([0.,1.,-1.,r.uniform(-10,10)]))]
S(0x464270,'GUESS initialize motion blend','thiscall',None,ret='al',gen=gen)
