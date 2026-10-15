import struct
from pilot import S
from recruits_util import rnd,obj,pystub,clear_hooks,sysobj,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 s=rnd(c,0x1c0)
 for off in [0xc,0x1b1]:e.w8(s+off,0 if r.randrange(6)==0 else 1)
 gate=obj(c,0x20,{0xc:pystub(c,0,this=True,ret=r.choice([0,0,0,1]))})
 sys=sysobj(c,slots={0x1b0:pystub(c,0,this=True,ret=r.choice([0,gate]))})
 clock=r.choice([r.randrange(0,100000),0x7fffffff,0x80000000,0xffffffff]);e.w32(sys+0x40,clock)
 for key in range(256):
  stamp=(clock-r.choice([0,1,100,255,256,257,1000]))/1024.0 if clock<100001 and r.randrange(2) else r.uniform(-100,100)
  e.wbytes(sys+0xf07+key*5,struct.pack('<f',stamp))
 count=r.randrange(6); data=bytearray()
 for i in range(count):data+=struct.pack('<IIIII',r.randrange(256),r.choice([0,0x80,0xff]),r.getrandbits(32),r.getrandbits(32),r.getrandbits(32))
 if r.randrange(5)==0:
  count=2;data=bytearray(struct.pack('<IIIII',0x1d,0x80,1,2,3)+struct.pack('<IIIII',0xb8,r.choice([0,0x80]),4,5,6))
 def read(em,k):em.w32(em.arg32(3),count);em.wbytes(em.arg32(2),data)
 code=pystub(c,5,pop=20,ret=r.choice([0,0,0,0x8007001e,0x8007000c,0x80004005]),deref={3:1},side=read)
 errors=[r.choice([0x8007001e,0x8007000c]) for _ in range(r.randrange(4))]+[0]
 device=obj(c,0x20,{0x28:code,0x1c:pystub(c,1,ret=lambda em,k:errors[min(k,len(errors)-1)])})
 e.w32(s+0xd,device)
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [s]
S(0x42a180,'GUESS pollInput','thiscall',None,ret=None,gen=gen)
