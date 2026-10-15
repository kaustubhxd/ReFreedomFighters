import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 def floats(n):return struct.pack('<'+'f'*n,*[r.uniform(-10,10) for _ in range(n)])
 def output(i,bs):return lambda em,k:em.wbytes(em.arg32(i),bs)
 p=floats(3);q=floats(3);mat=floats(9)
 owner=obj(c,16,{0x84:pystub(c,1,this=True,stackmark=(0,),side=output(0,p))})
 ob=obj(c,16,{0x80:pystub(c,2,this=True,stackmark=(0,1),side=lambda em,k:(em.wbytes(em.arg32(0),mat),em.wbytes(em.arg32(1),q)))})
 od=rnd(c,0x60);e.w32(ob+8,od);e.wbytes(od+0x40,floats(3))
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=ob)})
 def collision(em,k):
  ptr=em.arg32(2)
  # Defined bytes only: prefix, two constructor outputs, explicit vectors, final scalar.
  for off,n in [(0,21),(21,36),(57,12),(69,36),(105,16)]:
   em.wbytes(record+off,em.rbytes(ptr+off,n))
 record=e.alloc(0x79,4)
 me=obj(c,0x1660,{0x8c:pystub(c,1,this=True,deref={0:3}),0x94:pystub(c,2,this=True,deref={0:9,1:3}),0x130:pystub(c,3,this=True,stackmark=(2,),side=collision)})
 data=rnd(c,0x60);e.w32(me+8,data);e.wbytes(data+0x30,floats(3));e.wbytes(data+0x4c,struct.pack('<f',r.uniform(-20,20)))
 e.w32(me+0x164a,r.choice([0,owner,owner,owner]));e.w32(me+0x123,r.getrandbits(32));e.wbytes(me+0x2ce,struct.pack('<H',r.randrange(65536)))
 # Register ABI callees have explicit recorded input bytes and deterministic outputs.
 rec=e.alloc(3*4+3*4+9*4+3*4+2*3*4+8,4); dist=r.uniform(-20,20); transformed=floats(3)
 def distance(em,k):
  em.wbytes(rec,em.rbytes(em.reg('ecx'),12));em.wbytes(rec+12,em.rbytes(em.reg('edx'),12))
 hook_rec(c,0x4e0870,0,side=distance,st0=dist)
 def transform(em,k):
  em.wbytes(rec+24,em.rbytes(em.reg('ecx'),36));em.wbytes(rec+60,em.rbytes(em.reg('edx'),12));em.wbytes(em.reg('edx'),transformed)
 hook_rec(c,0x4e2c60,0,side=transform)
 def ctor(em,k):
  em.wbytes(rec+72+12*k,em.rbytes(em.reg('edx'),12));em.w32(rec+96+4*k,em.arg32(0));em.wbytes(em.reg('ecx'),mat)
 hook_rec(c,0x4de040,1,side=ctor)
 args=[]
 for i in range(4):
  a=rnd(c,12);e.wbytes(a,floats(3));args.append(a)
 return [me]+args
S(0x5172e0,'GUESS vehicle player collision packet','thiscall',None,ret=None,gen=gen)
