from pilot import S
from recruits_util import clear_hooks,rnd,obj,sysobj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 table=0
 def setslot(slot):
  def h(em,_):em.calllog.append(('set',slot,em.arg32(0)));em.ret(eax=r.getrandbits(32),argbytes=4)
  return e.stub_fn('set',h)
 width=r.choice([-3,0,1,2,7,32]);height=r.choice([-2,0,1,3,16]);levels=r.randrange(5)
 def getter(slot,value):return e.stub_fn('get',lambda em,_:(em.calllog.append(('get',slot)),em.ret(eax=value&0xffffffff,argbytes=0)))
 def upload(em,_):
  args=[em.arg32(i) for i in range(6)];em.calllog.append(('upload',*args,em.rbytes(args[0],args[1])));em.ret(eax=0,argbytes=24)
 slots={slot:setslot(slot) for slot in [0x74,0x78,0x5c,0x4c,0x2c,0x24]};slots.update({0x1c:getter(0x1c,width),0x20:getter(0x20,height),0x34:getter(0x34,levels),0x58:e.stub_fn('upload',upload)})
 s=obj(c,64,slots);system=sysobj(c,table_size=0x6300);table=e.r32(system+0x9b);swap=r.randrange(2);e.w32(table+0x62e7,3 if swap else 0)
 if r.randrange(5)==0:e.w32(system+0x9b,0);swap=0
 p=rnd(c,512);identifier=r.getrandbits(32);e.w32(s+4,r.choice([identifier,identifier,identifier^1]))
 def write(off,v):e.wbytes(p+off,v.to_bytes(4,'big' if swap else 'little'))
 write(0,identifier)
 for i in range(1,7):write(i*4,r.getrandbits(32))
 name=bytes(r.randrange(65,91) for _ in range(r.randrange(16)))+b'\0';e.wbytes(p+28,name);at=28+len(name)
 for i in range(levels):
  size=r.randrange(32);write(at,size);at+=size+4
 e.w32(0x7003b0,e.stub_fn('assert',lambda em,_:(em.calllog.append(('assert',)),em.ret(eax=r.getrandbits(32),argbytes=0))))
 return [s,p]
S(0x638f20,'GUESS load endian aware resource levels','thiscall',None,ret='eax',gen=gen)
