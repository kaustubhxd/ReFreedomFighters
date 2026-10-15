import struct
from pilot import S,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def debug(c):
 e=c.emu
 report=obj(c,32,{0x2c:pystub(c,4,pop=0)})
 d=obj(c,32,{0x20:pystub(c,2,this=True,ret=report)})
 e.w32(0x700390,d)
 # The error reporter in 502100 has three dwords, unlike the size logger.
 return report

def g650(c):
 clear_hooks(c);r=c.rng;e=c.emu;debug(c)
 stream=obj(c,32,{8:pystub(c,1,this=True),0x3c:pystub(c,1,this=True),0x10:pystub(c,2,this=True)})
 service=obj(c,32,{0x1a8:pystub(c,1,this=True)})
 sys=sysobj(c);e.w32(sys+0x190f,service)
 s=rnd(c,0x40);base=rnd(c,0x100);offset=r.randrange(8,64);e.w32(base+4,offset)
 size=r.choice([0,0,1,16,256,0x80000000,0xffffffff,r.getrandbits(32)])
 e.w32(s+0x20,base);e.w32(s+0x28,(base+offset+size)&0xffffffff);e.w32(s+0x38,rnd(c,32))
 hook_rec(c,0x644e70,1,this=True)
 return [s,stream]

def g44b(c):
 clear_hooks(c);r=c.rng;e=c.emu
 ids=r.sample(range(65536),3)
 for a,v in zip([0x6ff96c,0x6ff970,0x6ff974],ids):e.wbytes(a,struct.pack('<H',v))
 state=rnd(c,0x100);e.w32(state+4,r.choice([1,8,0,12,r.getrandbits(32)]))
 put(e,state+0x88,r.choice(EDGE_F) if r.random()<0.2 else r.uniform(-100,100))
 s=obj(c,32,{0x24:pystub(c,1,this=True)});e.w32(s+0x18,state)
 service=obj(c,32,{0x50:pystub(c,1,this=True)});sys=sysobj(c);e.w32(sys+0x1a9f,r.choice([0,service,service]))
 hook_rec(c,0x45d380,2,this=True)
 return [s,r.choice(ids+[r.randrange(65536)])|(r.getrandbits(16)<<16),r.getrandbits(32)]

def g551(c):
 clear_hooks(c);r=c.rng;e=c.emu
 cells=[rnd(c,8) for _ in range(6)]
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:cells[em.arg32(0)%6])
 def side(em,k):em.w32(em.reg('ecx'),em.arg32(0))
 hook_rec(c,0x500360,1,this=True,side=side);hook_rec(c,0x5002f0,1,this=True,side=side)
 ptr=rnd(c,16);o=obj(c,32,{0x4c:pystub(c,0,this=True,ret=ptr)})
 a=obj(c,32,{0x18:pystub(c,1,this=True,ret=r.choice([0,o,o,o]))})
 return [a,r.getrandbits(32),rnd(c,24)]

def g502(c):
 clear_hooks(c);r=c.rng;e=c.emu
 report=obj(c,32,{0x2c:pystub(c,3,pop=0)});dbg=obj(c,32,{0x20:pystub(c,2,this=True,ret=report)});e.w32(0x700390,dbg)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 cells=[rnd(c,8) for _ in range(3)];kind=r.choice([3,4,0,1,255]);e.wbytes(cells[1]+4,bytes([kind]))
 if kind==4:e.w32(cells[1],obj(c,32,{0x34:pystub(c,0,this=True,ret=r.getrandbits(32))}))
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:cells[em.arg32(0)%3])
 sysobj(c,table_slots={0x114:pystub(c,4,this=True,ret=r.getrandbits(32))})
 child=obj(c,32,{0x12c:pystub(c,3,this=True,deref={2:1})});s=rnd(c,32);e.w32(s+0xc,child)
 args=rnd(c,16);e.w32(args+4,rnd(c,16));return [s,args]
S(0x650d00,'GUESS serialize payload and child','thiscall',None,ret='al',gen=g650,note='batch116006')
S(0x44ba90,'GUESS timed state command','thiscall',None,ret='eax',gen=g44b,note='batch116006',nan_heap=True)
S(0x551430,'GUESS set four floats two integers','stdcall',None,ret='eax',gen=g551,note='batch116006')
S(0x502100,'GUESS dispatch typed script handle','thiscall',None,ret=None,gen=g502,note='batch116006')
