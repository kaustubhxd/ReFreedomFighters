import struct
from pilot import S,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def g5df(c):
 clear_hooks(c);r=c.rng;e=c.emu;vec=rnd(c,12)
 vals=[r.choice(EDGE_F) if r.random()<0.15 else r.uniform(-1,1) for _ in range(3)]
 if r.random()<0.2:vals[0]=vals[2]=0.
 for i,v in enumerate(vals):put(e,vec+4*i,v)
 return [rnd(c,4),vec]

def g502(c):
 clear_hooks(c);r=c.rng;e=c.emu
 report=obj(c,32,{0x2c:pystub(c,3,pop=0)});debug=obj(c,32,{0x20:pystub(c,2,this=True,ret=report)});e.w32(0x700390,debug);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 cells=[rnd(c,8) for _ in range(5)];k=r.choice([3,4,0,1,255]);e.wbytes(cells[1]+4,bytes([k]))
 if k==4:e.w32(cells[1],obj(c,32,{0x34:pystub(c,0,this=True,ret=r.getrandbits(32))}))
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:cells[em.arg32(0)%5])
 sysobj(c,table_slots={0x114:pystub(c,4,this=True,ret=r.getrandbits(32))})
 child=obj(c,32,{0x12c:pystub(c,3,this=True,deref={2:3})});s=rnd(c,32);e.w32(s+0xc,child);args=rnd(c,16);e.w32(args+4,rnd(c,16));return [s,args]

def g515(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=obj(c,0x300,{0x130:pystub(c,3,this=True,deref={2:7})})
 sysobj(c,table_slots={0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))})
 for i in range(3):put(e,s+0x227+4*i,r.choice([1.,5.,10.,-1.,r.uniform(0,10)]))
 for i in range(9):put(e,s+0x237+4*i,1. if i%4==0 else 0.)
 if r.random()<0.4:
  for i in range(9):put(e,s+0x237+4*i,r.uniform(-2,2))
 for i in range(3):
  v=r.uniform(-10,10);put(e,s+0x25b+4*i,v);put(e,s+0x2b3+4*i,v+r.uniform(-5,5))
 return [s]
S(0x5df4d0,'GUESS encode direction angles','fastcall',None,ret=None,gen=g5df,note='batch116014')
S(0x502490,'GUESS typed handle vector dispatch','thiscall',None,ret=None,gen=g502,note='batch116014')
S(0x515270,'GUESS vehicle local bounds event','thiscall',None,ret=None,gen=g515,note='batch116014')
