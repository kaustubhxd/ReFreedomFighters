import struct
from pilot import S,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def g505(c):
 clear_hooks(c);r=c.rng;e=c.emu
 cells=[rnd(c,8) for _ in range(5)];output=rnd(c,8)
 input=rnd(c,16);out=rnd(c,16);args=rnd(c,16);e.w32(args+4,input);e.w32(args+8,out)
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:output if em.reg('ecx')==out else cells[em.arg32(0)%5])
 def side(em,k):em.w32(em.reg('ecx'),em.arg32(0))
 hook_rec(c,0x5002f0,1,this=True,side=side)
 sys=sysobj(c);table=obj(c,0x80,{});e.w32(sys+0x9b,table)
 s=obj(c,32,{0x50:pystub(c,6,this=True,ret=r.getrandbits(32))})
 return [s,args]

def g486(c):
 clear_hooks(c);r=c.rng;e=c.emu
 target=obj(c,32,{0x1e0:pystub(c,1,this=True,ret=r.choice([0,1,0x100,0x101,r.getrandbits(32)]))})
 holder=obj(c,32,{0x2e8:pystub(c,0,this=True,ret=target)})
 action=rnd(c,32)
 actor=obj(c,32,{0x228:pystub(c,5,this=True,ret=action)})
 s=obj(c,32,{0xc:pystub(c,0,this=True,ret=r.getrandbits(32))})
 e.w32(s+8,holder);e.w32(s+0xc,actor)
 e.w32(s+0x14,r.choice([0,r.getrandbits(32)]));e.w32(s+0x18,r.choice([0,r.getrandbits(32)]))
 sysobj(c,slots={0x1c0:pystub(c,2,this=True,st0=r.uniform(-10,10))})
 hook_rec(c,0x461570,3,this=True)
 return [s]

def g468(c):
 clear_hooks(c);r=c.rng;e=c.emu
 actor=obj(c,32,{0x310:pystub(c,2,this=True)})
 sys=sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=actor)})
 component=obj(c,32,{0x20:pystub(c,1,this=True,ret=r.getrandbits(32))})
 s=obj(c,0x80,{0x84:pystub(c,1,this=True),0x88:pystub(c,1,this=True)})
 e.w32(s+0x44,component);a,b=r.randrange(65536),r.randrange(65536)
 e.wbytes(s+0x4a,struct.pack('<HH',a,b))
 put(e,s+0x57,r.choice(EDGE_F) if r.random()<0.2 else r.uniform(-100,100))
 value=r.getrandbits(32)
 def side(em,k):em.w32(em.arg32(1),value)
 arg=obj(c,32,{0x88:pystub(c,2,this=True,nullflag=(1,),side=side)})
 return [s,r.choice([a,b,r.randrange(65536)])|(r.getrandbits(16)<<16),arg]

def g504(c):
 clear_hooks(c);r=c.rng;e=c.emu
 input=rnd(c,16);cell=rnd(c,8);e.w32(cell,r.choice([0,0,r.getrandbits(32)]))
 args=rnd(c,16);e.w32(args+4,input)
 hook_rec(c,0x5003d0,1,this=True,ret=cell)
 sysobj(c,table_slots={0x54:pystub(c,1,this=True,ret=r.choice([0,1,r.getrandbits(32)]))})
 child=obj(c,32,{0x3c4:pystub(c,6,this=True),0x3c8:pystub(c,5,this=True)})
 s=rnd(c,32);e.w32(s+0x14,child)
 return [s,args]
S(0x505720,'GUESS dispatch five script cells','thiscall',None,ret=None,gen=g505,note='batch116003')
S(0x4864e0,'GUESS execute get item action','thiscall',None,ret='al',gen=g486,note='batch116003')
S(0x4684c0,'GUESS item state command','thiscall',None,ret='eax',gen=g468,note='batch116003')
S(0x504fc0,'GUESS script target selection','thiscall',None,ret=None,gen=g504,note='batch116003')
