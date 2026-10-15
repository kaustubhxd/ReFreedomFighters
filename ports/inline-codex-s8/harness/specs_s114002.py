from pilot import S
from recruits_util import clear_hooks,rnd,obj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 s=rnd(c,0x2d00)
 pool=[rnd(c,16)+4 for _ in range(8)]
 for p in pool:e.w32(p-4,r.choice([0,r.getrandbits(32)]))
 def out(slot):
  def h(em,_):em.calllog.append(('write',slot,em.arg32(0)));em.ret(eax=r.getrandbits(32),argbytes=4)
  return e.stub_fn('write',h)
 st=obj(c,32,{slot:out(slot) for slot in [0x3c,0x60,0x64]})
 def check(em,_):em.calllog.append(('check',em.arg32(0)));em.ret(eax=r.choice([0,0,1]),argbytes=4)
 def assign(em,_):
  p=em.arg32(0);em.w32(p-4,r.getrandbits(32));em.calllog.append(('assign',p));em.ret(eax=r.getrandbits(32),argbytes=4)
 def resolve(em,_):em.calllog.append(('resolve',em.reg('ecx')));em.ret(eax=r.getrandbits(32),argbytes=0)
 m=obj(c,32,{0x20:e.stub_fn('check',check),0xac:e.stub_fn('assign',assign)})
 e.w32(m+8,e.stub_fn('resolve',resolve) if r.randrange(2) else 0)
 lo=r.choice(pool);hi=r.choice(pool+[pool[-1]+16]);e.w32(m+12,lo);e.w32(m+16,hi);e.w32(0x70038c,m)
 for count,base,stride in [(0xbe5,0xbe9,4),(0xc69,0xc6d,9)]:
  n=r.randrange(5);e.w32(s+count,n)
  for i in range(n):e.w32(s+base+i*stride,r.choice(pool+[0]))
 n=r.randrange(4);e.w32(s+0xd8d,n)
 for i in range(n):
  p=s+0xd91+i*0xf4;e.w32(p,r.randrange(8));nn=r.randrange(8);e.w32(p+0x38,nn)
  for j in range(nn):e.w32(p+0x3c+j*4,r.choice(pool+[0]))
 e.w32(s+0x2c55,r.randrange(8))
 return [s,st]
S(0x58a3b0,'GUESS serialize event collections','thiscall',None,ret=None,gen=gen)
