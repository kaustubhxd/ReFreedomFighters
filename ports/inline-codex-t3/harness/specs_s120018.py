from pilot import S
from recruits_util import rnd,clear_hooks,pystub

def sewer(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 names=[]
 for text in [b'',b'sewer',b'sewerX',b'Sewer',b'sew',b'other']:
  a=e.alloc(len(text)+1,1);e.wbytes(a,text+b'\0');names.append(a)
 self=rnd(c,0x170)
 for i in range(19):e.w32(self+8+18*i,r.choice(names))
 d=rnd(c,36)
 for off in (24,32):e.wf32(d+off,r.choice([0.0,-0.0,1.0,-1.0,float('nan'),float('inf'),float('-inf'),r.uniform(-100,100)]))
 return [self,r.choice(names),r.getrandbits(32),rnd(c,12),d]
S(0x5b1760,'ZSewerControl::SetSewerInfo','thiscall',None,ret=None,gen=sewer)
