import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,obj,pystub

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 selfp=rnd(c,0x500);state=rnd(c,0x48);info=rnd(c,0x60);frame=rnd(c,36);pos=rnd(c,12)
 e.w32(selfp+8,info);e.w8(state+0x40,r.choice([0,0,0,1]))
 for p,n in [(pos,3),(state+12,3),(frame,9),(state+24,9)]:
  for k in range(n):e.w32(p+4*k,fb(r.uniform(-50,50)))
 hook_rec(c,0x44d250,2,ret=r.choice([state,state,state,0]),this=True)
 # Record both register arguments through an explicit heap record.
 distance=r.choice([0.0,0.1,1.0,2.0,5.0,10.0,30.0,100.0])
 rec=rnd(c,8)
 def dist(e,k):e.w32(rec,e.reg('ecx'));e.w32(rec+4,e.reg('edx'))
 hook_rec(c,0x4e0870,0,this=True,side=dist,st0=distance)
 def interp(e,k):
  dst=e.reg('ecx');src=e.reg('edx');other=e.arg32(0);t=struct.unpack('<f',struct.pack('<I',e.arg32(1)))[0]
  e.w32(rec,src)
  for j in range(9):
   a=struct.unpack('<f',struct.pack('<I',e.r32(src+4*j)))[0];b=struct.unpack('<f',struct.pack('<I',e.r32(other+4*j)))[0]
   e.w32(dst+4*j,fb(a+(b-a)*t))
 hook_rec(c,0x4de520,2,this='mark',side=interp)
 def copy(e,k):e.wbytes(e.reg('ecx'),e.rbytes(e.reg('edx'),36))
 hook_rec(c,0x4de420,0,this=True,side=copy)
 target=obj(c,0x20,{0x50:pystub(c,5,this=True,deref={1:9,2:3,3:7})})
 return [selfp,r.getrandbits(32),r.getrandbits(32),target,r.choice([0,1,1,1]),frame,pos,r.getrandbits(32)]
S(0x44d360,'GUESS sample interpolated frame callbacks','thiscall',None,ret=None,gen=gen)
