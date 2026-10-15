import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c); e=c.emu; r=c.rng
 me=rnd(c,0xc0); a=rnd(c,12); b=rnd(c,12)
 for i in range(3):
  lo=r.uniform(-200,200); hi=lo+r.choice([0.125,1,32,100])+r.random()
  e.wbytes(me+6+4*i,struct.pack('<f',lo)); e.wbytes(me+0x12+4*i,struct.pack('<f',hi))
  e.w32(me+0x3c+4*i,r.choice([1,2,16,255,1024]))
  e.wbytes(a+4*i,struct.pack('<f',r.uniform(-500,500)))
  e.wbytes(b+4*i,struct.pack('<f',r.uniform(-500,500)))
 ca=[r.randrange(65536) for _ in range(4)]; cb=[r.randrange(65536) for _ in range(4)]
 def first(em,k): em.wbytes(em.arg32(0),struct.pack('<4H',*ca))
 def second(em,k):
  em.wbytes(em.arg32(0),struct.pack('<4H',*cb)); em.wbytes(em.arg32(2),b'\x01')
 hook_rec(c,0x530e80,5,this=True,ret=r.choice([0,1,2]),deref={1:-6},stackmark=(0,),side=first)
 hook_rec(c,0x530bf0,3,this='mark',ret=r.choice([0,1,2]),stackmark=(0,2),side=second)
 hook_rec(c,0x52dfc0,2,this=True,ret=r.getrandbits(32),deref={0:-6,1:-6})
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 return [me,a,b,r.choice([0,1,2,256,257])]
S(0x52e0a0,'GUESS world line check and height snap','thiscall',None,ret='al',gen=gen)
