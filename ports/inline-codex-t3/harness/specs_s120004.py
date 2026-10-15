from pilot import S,F
from recruits_util import rnd,clear_hooks,pystub,obj
import struct,math

def fv(r):
    b=r.choice([0,0x80000000,0x3f800000,0xbf800000,0x7f800000,0xff800000,0x7fc00000,r.getrandbits(32),struct.unpack('<I',struct.pack('<f',r.uniform(-50,50)))[0]])
    return struct.unpack('<f',struct.pack('<I',b))[0]

def inside(c):
    clear_hooks(c);e,r=c.emu,c.rng
    e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
    n=r.randint(0,5); nodes=[rnd(c,0x30) for _ in range(n)];table={}
    for i,node in enumerate(nodes):
        table[0x100+i]=node
        e.w32(node+8,0x101+i if i+1<n else 0)
        if r.random()<0.2:e.w32(node+0x24,0);continue
        cnt=r.randint(0,5);pl=rnd(c,4+cnt*16);table[0x1000+i]=pl
        e.w32(node+0x24,0x1000+i);e.w32(pl,cnt)
        for j in range(cnt*4):e.wf32(pl+4+4*j,fv(r))
    lookup=pystub(c,1,this=True,ret=lambda em,k:table[em.arg32(0)])
    self=obj(c,0x20,{0xc:lookup})
    p=rnd(c,12)
    for k in range(3):e.wf32(p+4*k,fv(r))
    return [self,0x100 if n else 0,p,F(fv(r))]
S(0x655fa0,'ZPrimControlBase::CheckPointInsidePrim','thiscall',None,ret='al',gen=inside)
