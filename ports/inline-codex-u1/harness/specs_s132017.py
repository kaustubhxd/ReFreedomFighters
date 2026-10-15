import math,struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,obj,pystub,sysobj
from unicorn.x86_const import UC_X86_REG_EDX

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 p=obj(c,0x1b50,{0x15c:pystub(c,0,this=True),0xd0:pystub(c,0,this=True)})
 db=obj(c,16,{0xa4:pystub(c,0,this=True),0xb0:pystub(c,0,this=True,ret=r.getrandbits(32)),0xa0:pystub(c,1,this=True),0x18c:pystub(c,1,this=True),0x9c:pystub(c,1,this=True)})
 e.w32(p+0x9b,db);e.w32(p+0x40,r.choice([0xffffffff,0,1]));e.w32(p+0x1b44,r.randrange(2))
 aux=obj(c,16,{0x54:pystub(c,0,this=True)});e.w32(p+0x1907,r.choice([aux,0]))
 e.w32(0x7003a0,r.choice([0,obj(c,16,{0x1c:pystub(c,0,this=True)})]))
 rate=r.choice([100.0,1000.0,10000.0]);e.w32(p+0x58,fb(rate))
 threshold=struct.unpack('<d',e.rbytes(0x6785f0,8))[0];step=max(1,math.ceil(rate*threshold/r.randrange(1,6)*1.1))
 start=r.choice([0,0xfffffff0,0x1fffffff0,0x7ffffffffffffff0]);values=[(start+step*k)&((1<<64)-1) for k in range(16)]
 def tickside(e,k):e.mu.reg_write(UC_X86_REG_EDX,values[min(k,15)]>>32)
 tick=pystub(c,2,this=True,ret=lambda e,k:values[min(k,15)]&0xffffffff,side=tickside)
 so=sysobj(c,slots={0x1c8:tick});e.w8(so+0x6d,r.randrange(2))
 mouse=obj(c,0x140,{0x230:pystub(c,3,this=True)});e.w32(so+0x190f,r.choice([mouse,mouse,0]))
 hook_rec(c,0x422ed0,2,this=True)
 x=r.randrange(-500,500);y=r.randrange(-500,500);dx=r.randrange(-50,50);dy=r.randrange(-50,50)
 def cursor(e,r):e.w32(e.arg32(0),x&0xffffffff);e.w32(e.arg32(0)+4,y&0xffffffff);e.ret(1,4)
 def client(e,r):
  point=e.arg32(1);e.w32(point,(e.r32(point)+dx)&0xffffffff);e.w32(point+4,(e.r32(point+4)+dy)&0xffffffff);e.ret(1,8)
 e.stub_import('GetCursorPos',cursor);e.stub_import('ScreenToClient',client)
 return [p,r.getrandbits(32)]
S(0x421d20,'GUESS frame input dispatch and timing wait','thiscall',None,ret=None,gen=gen)
