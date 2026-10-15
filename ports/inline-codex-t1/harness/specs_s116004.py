import struct,math
from unicorn.x86_const import UC_X86_REG_EIP
from pilot import S,F,EDGE_F
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def g404(c):
 clear_hooks(c);r=c.rng;e=c.emu
 cell=e.alloc(16,8);tramp=e.alloc(16,4);e.wbytes(tramp,b'\xdd\x05'+struct.pack('<I',cell)+b'\xc3');e.mu.ctl_flush_tb()
 def floor(em,k):
  raw=em.rbytes(em.reg('esp')+4,8);x=struct.unpack('<d',raw)[0]
  em.calllog.append(('floor',raw.hex()))
  y=float(math.floor(x)) if math.isfinite(x) else x
  if y==0:y=math.copysign(0.,x)
  em.wbytes(cell,struct.pack('<d',y));em.mu.reg_write(UC_X86_REG_EIP,tramp)
 e.stub_import('floor',floor)
 vals=[r.choice(EDGE_F) if r.random()<0.1 else r.uniform(-100,100) for _ in range(7)]
 if r.random()<0.2:vals[6]=0.
 if r.random()<0.15:vals[1]=r.choice([vals[0],-vals[0]])
 return [F(x) for x in vals]+[rnd(c,4),rnd(c,4)]

def g51e(c):
 clear_hooks(c);r=c.rng;e=c.emu
 cells=[rnd(c,8),rnd(c,8)]
 # Change values on every access so reordered reads are observable.
 def value(em,k):
  i=em.arg32(0)&1;em.w32(cells[i],r.getrandbits(32));return cells[i]
 hook_rec(c,0x5003d0,1,this=True,ret=value)
 component=rnd(c,0x400)
 for off in [0x2c3,0x2ec,0x315]:
  vt=e.alloc(4,4);e.w32(vt,pystub(c,3,this=True));e.w32(component+off,vt)
 s=rnd(c,32);e.w32(s+0x18,component);args=rnd(c,16);e.w32(args+4,rnd(c,16))
 return [s,args]

def g656(c):
 clear_hooks(c);r=c.rng;e=c.emu
 source=rnd(c,0x40);out=source if r.random()<0.2 else rnd(c,0x40)
 for off in [0x18,0x1c,0x24,0x28]:put(e,source+off,r.choice(EDGE_F) if r.random()<0.15 else r.uniform(-10,10))
 if r.random()<0.25:e.w32(source+0x28,e.r32(source+0x24))
 return [out,source]
S(0x404fd0,'GUESS x87 quantized scale','cdecl',None,ret=None,gen=g404,note='batch116004',nan_heap=True)
S(0x51e940,'GUESS set three embedded vectors','thiscall',None,ret=None,gen=g51e,note='batch116004')
S(0x656c60,'GUESS spot light cone setup','stdcall',None,ret=None,gen=g656,note='batch116004',nan_heap=True)
