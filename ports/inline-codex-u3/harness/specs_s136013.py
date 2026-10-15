import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 result=[r.choice([0.,r.uniform(-3,3)]) for _ in range(3)]
 def solve(em,k):
  e.wbytes(em.arg32(4),struct.pack('<3f',*result));e.wbytes(em.arg32(5),bytes(12));e.wbytes(em.arg32(6),bytes(36))
 s=obj(c,0x40,{0x220:pystub(c,7,this=True,deref={3:3},stackmark=(4,5,6),side=solve)})
 geo=rnd(c,0x60);e.w32(s+8,geo);e.wbytes(s+0x21,bytes([r.choice([0,1,0x80])]))
 for p,n in [(geo+0x24,3),(geo+0x30,3)]:e.wbytes(p,struct.pack('<3f',*(r.uniform(-2,2) for _ in range(n))))
 e.wbytes(geo+0x40,struct.pack('<3f',*(r.choice([0.,1.,5.,-1.]) for _ in range(3))))
 hit=rnd(c,0x20);thing=rnd(c,0x20);e.w32(hit+0x10,thing);e.wbytes(hit+0xc,struct.pack('<f',r.choice([-5.,0.,5.])))
 if r.randrange(4)==0:
  result[:]=[0.,0.,0.];e.wbytes(geo+0x30,struct.pack('<3f',0.,0.,0.));e.wbytes(geo+0x40,struct.pack('<3f',5.,5.,5.));e.wbytes(hit+0xc,struct.pack('<f',0.5))
 point=rnd(c,12);e.wbytes(point,struct.pack('<3f',*(r.uniform(-10,10) for _ in range(3))))
 entry=rnd(c,0x20);manager=obj(c,0x20,{0x20:pystub(c,1,this=True,ret=entry)})
 sys=sysobj(c,table_slots={0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))});e.w32(sys+0x190f,manager)
 hook_rec(c,0x63db70,0,this=True,ret=r.getrandbits(32));hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [s,hit,point,r.getrandbits(32)]
S(0x4f0270,'GUESS update closer bounding plane hit','thiscall',None,ret=None,gen=gen)
