import struct,math
from pilot import S
from recruits_util import rnd,obj,sysobj,pystub,clear_hooks

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 id=r.getrandbits(32);sysobj(c,table_slots={0x50:pystub(c,1,this=True,ret=id)})
 matrix=rnd(c,36);out=rnd(c,12);ob=rnd(c,16);data=rnd(c,0x60);e.w32(ob+8,data);e.wbytes(data+0x5a,struct.pack('<H',r.choice([0,0,1,65535])))
 def side(em,k):
  em.wbytes(em.arg32(0),bytes([0x35])*36);em.wbytes(em.arg32(1),bytes([0x54])*12)
 me=obj(c,0x280,{0xc:pystub(c,4,this=True,side=side)})
 n=r.randrange(0,7);e.w32(me+0x69,n);match=r.randrange(n+2)
 for i in range(n):e.w32(me+0x6d+0x38*i,id if i==match else (id+i+1)&0xffffffff);e.w32(me+0x71+0x38*i,r.choice([0x15,0x15,0x14,0]))
 e.wbytes(me+0x251,struct.pack('<f',r.choice([0.,-0.,1.,-1.,math.nan,2.])))
 for i in range(3):e.wbytes(me+0x259+4*i,struct.pack('<f',r.uniform(-100,100)))
 return [me,matrix,out,r.getrandbits(32),ob]
S(0x646060,'GUESS resolve keyed camera pose','thiscall',None,ret='al',gen=gen,nan_heap=True)
