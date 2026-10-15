import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,obj,pystub,sysobj

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 count=r.randrange(6);frame=rnd(c,0x600);entry=rnd(c,0x50);geom=rnd(c,0x60);model=rnd(c,0x70)
 owner=obj(c,0x20,{0x280:pystub(c,1,this=True)});e.w32(owner+8,model);e.w32(geom+0x54,owner);e.w32(entry+0x38,geom);e.w8(entry+0x3f,count);e.w32(entry+0x48,frame)
 bones=frame+0x90
 for i in range(count):
  for k in range(12):e.w32(bones+0x30*i+4*k,fb(r.uniform(-2,2)))
 hierarchy=rnd(c,0xc+0x30*max(count,1))
 for i in range(count):e.w32(hierarchy+0xc+0x30*i,r.randrange(i) if i else 0)
 provider=obj(c,16,{0xc4:pystub(c,1,this=True,ret=hierarchy)})
 cfg=rnd(c,0x20);e.w32(cfg+0x18,provider);so=sysobj(c);e.w32(so+0x1aa3,cfg)
 rec=rnd(c,36*8)
 def quat(e,k):
  src=e.reg('edx');dst=e.reg('ecx');e.wbytes(rec+36*min(k,7),e.rbytes(src,36));e.wbytes(dst,e.rbytes(src,16))
 hook_rec(c,0x4de1d0,0,this=True,side=quat)
 return [entry,r.choice([0,1,0x100,0x101,r.getrandbits(32)])]
S(0x63ce50,'GUESS build bone relative transform outputs','stdcall',None,ret=None,gen=gen)
