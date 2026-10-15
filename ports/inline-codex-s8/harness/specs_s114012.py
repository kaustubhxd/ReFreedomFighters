from pilot import S
from recruits_util import clear_hooks,rnd,obj,sysobj,_HOOKED

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng;s=rnd(c,0x1c0)
 def string(em,p):
  b=bytearray()
  for i in range(128):
   v=em.rbytes(p+i,1)[0]
   if not v:break
   b.append(v)
  return bytes(b)
 def format(em,_):
  owner,dst,fmt=[em.arg32(i) for i in range(3)];args=[em.arg32(3)] if fmt!=0x68dcfc else [em.arg32(3),em.arg32(4)]
  em.calllog.append(('format',owner,fmt,*args));data=('v'+str(r.getrandbits(32))).encode()+b'\0';em.wbytes(dst,data);em.ret(eax=r.getrandbits(32),argbytes=0)
 formatter=obj(c,16,{0x198:e.stub_fn('format',format)})
 def getformat(em,_):em.calllog.append(('formatter',));em.ret(eax=formatter,argbytes=0)
 strings=[rnd(c,32) for _ in range(8)]
 for p in strings:e.wbytes(p,b'label\0')
 def lookup(em,_):em.calllog.append(('lookup',em.arg32(0),em.arg32(1)));em.ret(eax=r.choice(strings),argbytes=8)
 lookupobj=obj(c,16,{0:e.stub_fn('lookup',lookup)})
 def query(em,_):
  em.calllog.append(('query',string(em,em.arg32(0)),em.rbytes(em.arg32(1),1)));em.w8(em.arg32(1),r.choice([0,1,2,255]));em.ret(eax=0,argbytes=8)
 q=obj(c,16,{0x90:e.stub_fn('query',query)})
 def getquery(em,_):em.calllog.append(('getquery',));em.ret(eax=q,argbytes=0)
 system=sysobj(c,slots={0x190:e.stub_fn('getformat',getformat)},table_slots={0x134:e.stub_fn('getquery',getquery)},table_size=0xb00);table=e.r32(system+0x9b);e.w32(table+0xae4,lookupobj)
 def apply(em,_):em.calllog.append(('apply',em.reg('ecx'),em.arg32(0),string(em,em.arg32(1))));em.ret(eax=0,argbytes=8)
 e.hook(0x5636c0,apply);_HOOKED.add(0x5636c0)
 return [s]
S(0x579d20,'GUESS update four localized toggle labels','thiscall',None,ret=None,gen=gen)
