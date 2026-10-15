from pilot import S
from recruits_util import rnd,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 addrs=[0x50b620,0x50d880,0x510f30,0x5117d0,0x5045c0,0x5060f0,0x509630,0x50a4a0]
 for a in addrs:hook_rec(c,a,0,this=True,ret=r.getrandbits(32))
 def string(em,p):
  s=bytearray()
  while em.rbytes(p,1)!=b'\0':s+=em.rbytes(p,1);p+=1
  return bytes(s)
 def compare(em,res):
  a,b=em.arg32(0),em.arg32(1);x,y=string(em,a),string(em,b);em.calllog.append(('compare',a,b));em.ret(((x>y)-(x<y))&0xffffffff,0)
 e.w32(0x676414,e.stub_fn('compare',compare))
 names=[0x69c770,0x69c77c,0x69c784,0x69c790,0x685230,0x69c754,0x69c75c,0x69c768];p=rnd(c,64);s=string(e,r.choice(names));e.wbytes(p,(s if r.randrange(4) else b'UNKNOWN')+b'\0')
 return [rnd(c,16),p,rnd(c,32)]
S(0x4fff00,'GUESS dispatch_interface_factory','thiscall',None,ret='eax',gen=gen)
