from pilot import S
from recruits_util import clear_hooks,rnd,_HOOKED

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng;s=rnd(c,0x4040);out=rnd(c,256);st=rnd(c,0x80)
 e.w32(st+0x47,r.randrange(1,64));e.w32(s+0x4024,r.choice([0,st]))
 e.w32(s,r.choice([-32768,-32760,0,32760,32767])&0xffffffff);e.w32(s+4,r.randrange(89))
 block=r.choice([0,1,2]);e.w32(s+8,block);e.w32(s+16,r.choice([0,2,4,6,8]));e.w32(s+24,r.randrange(8))
 e.w32(s+20,s+32);e.w32(s+0x4020,r.choice([0,4,8,12,16,64]))
 # Headers at every dword remain valid step indices whenever interpreted as headers.
 for i in range(0,256,4):e.w32(s+32+i,r.getrandbits(16)|(r.randrange(89)<<16))
 state={'n':0}
 def refill(em,_):
  state['n']+=1;buf,sizep=em.arg32(0),em.arg32(2);size=r.choice([0,4,8,16]) if state['n']<8 else 0
  data=b''.join((r.getrandbits(16)|(r.randrange(89)<<16)).to_bytes(4,'little') for _ in range(size//4))
  em.wbytes(buf,data);em.w32(sizep,size);em.calllog.append(('refill',em.reg('ecx'),buf,em.arg32(1),em.arg32(3),data));em.ret(eax=0,argbytes=16)
 def zero(em,_):
  p,val,n=[em.arg32(i) for i in range(3)];em.wbytes(p,bytes([val&255])*n);em.calllog.append(('zero',p,val,n));em.ret(eax=p,argbytes=0)
 for addr,h in [(0x54e1f0,refill),(0x634d10,zero)]:e.hook(addr,h);_HOOKED.add(addr)
 return [s,out,r.getrandbits(32),r.randrange(2),r.getrandbits(32),r.randrange(1,4),r.randrange(1,40),r.randrange(0,40)]
S(0x54d470,'GUESS decode ADPCM samples','fastcall',None,ret='eax',gen=gen)
