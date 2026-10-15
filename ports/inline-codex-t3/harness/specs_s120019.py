from pilot import S,F
from recruits_util import rnd,clear_hooks,pystub,hook_rec
import struct

def sf(x):return struct.unpack('<f',struct.pack('<f',x))[0]
def visit(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 self=rnd(c,0xb0);it=rnd(c,0x40);arr=rnd(c,32*21);e.w32(self+0x98,arr)
 frm=r.randrange(32);idx=r.choice([0,frm,r.randrange(1,32)]);direc=r.choice([0,1,2,3,4,5,10,11])
 for i in range(32):e.wf32(arr+21*i+10,r.choice([0.0,10.0,10000.0,float('nan'),r.uniform(-100,100)]))
 f=sf(e.rf32(arr+21*frm+10)+e.rf32(0x6a1584))
 if r.random()<0.4:e.wf32(arr+21*idx+10,sf(f+e.rf32(0x67a284)))
 e.w8(it+0x20,r.choice([0,1,2,3,255]));e.w16(it+0x16,r.choice([0,1,r.getrandbits(16)]))
 move=(r.getrandbits(16)<<16)|r.choice([0,1,r.getrandbits(16)]);rec=r.randbytes(8)
 def moved(em,k):em.wbytes(em.reg('ecx')+0x16,rec)
 for a in (0x52e320,0x531070):hook_rec(c,a,1,this=True,side=moved,ret=move)
 hook_rec(c,0x530a40,0,this=True,ret=(r.getrandbits(16)<<16)|idx)
 hook_rec(c,0x532420,2,this=True,ret=r.getrandbits(32))
 hook_rec(c,0x52d250,2,this=True)
 return [self,(r.getrandbits(16)<<16)|frm,it,direc,F(r.uniform(-100,100)),rnd(c,6)]
S(0x531b40,'ZPFOctree_packed::VisitNeighbor','thiscall',None,ret='eax',gen=visit)
