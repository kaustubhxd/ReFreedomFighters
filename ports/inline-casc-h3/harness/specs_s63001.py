from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def word(c): return c.rng.getrandbits(32)
def lookup(c):
 clear_hooks(c); e=c.emu; r=c.rng
 s=rnd(c,0xc0); e.w32(s+0xad,r.choice([0,word(c)]))
 p=rnd(c,8); p=r.choice([0,p]); out=word(c)
 so=sysobj(c,table_slots={0x58:pystub(c,1,this=True),0x160:pystub(c,1,this=True,ret=out)})
 sub=rnd(c,0x30); e.w32(so+0x1aa3,sub)
 e.w32(sub+0x1c,obj(c,0x20,{0x74:pystub(c,1,this=True,deref={0:2},ret=word(c))}))
 e.w32(sub+0x18,obj(c,0x20,{0xf8:pystub(c,1,this=True,ret=p)}))
 return [s]
def fields(c):
 clear_hooks(c); e=c.emu
 s=rnd(c,0x80)
 def side(em,k): em.wbytes(em.arg32(0),bytes([k+23])*2)
 slots={off:pystub(c,1,this=True,side=side) for off in [0x44,0x40,0x50]}
 e.w32(0x7003b0,pystub(c,0))
 hook_rec(c,0x4c0b00,1,this=True)
 return [s,obj(c,0x80,slots)]
def query(c):
 clear_hooks(c); e=c.emu; value=c.rng.randrange(256); write=c.rng.randrange(2); text=bytes(c.rng.randrange(1,256) for _ in range(63))+b'\0'
 def fmt(em,k): em.wbytes(em.arg32(1),text)
 service=obj(c,0x20,{0x198:pystub(c,4,pop=0,stackmark=(1,),side=fmt)})
 def result(em,k):
  if write: em.wbytes(em.arg32(1),bytes([value]))
 q=obj(c,0x20,{0x90:pystub(c,2,this=True,deref={0:-64,1:-1},side=result)})
 sysobj(c,slots={0x190:pystub(c,0,this=True,ret=service)},table_slots={0x134:pystub(c,0,this=True,ret=q)})
 return [rnd(c,0x200)]
def states(c):
 clear_hooks(c); e=c.emu; r=c.rng; idx=r.randrange(8); args=[word(c) for _ in range(3)]
 for j in range(3): e.w32(0x7248c8+idx*4+j*32,r.choice([args[j],word(c)]))
 e.w32(0x724a00,obj(c,0x20,{0xfc:pystub(c,4)}))
 return [idx]+args

def config(c):
 clear_hooks(c); e=c.emu; r=c.rng
 hook_rec(c,0x432650,0,this=True)
 vals=[word(c),word(c)]; enabled=[r.randrange(2),r.randrange(2)]
 def side(em,k): em.w32(em.arg32(1),vals[k])
 sysobj(c,slots={0x5c:pystub(c,2,this=True,stackmark=(1,),side=side,ret=lambda em,k:enabled[k])})
 def parse(em,res):
  arg=em.arg32(0); em.calllog.append(('parse',arg)); em.ret(eax=arg^0x101,argbytes=0)
 e.stub_import('atoi',parse)
 return [rnd(c,0x120)]
def match(c):
 clear_hooks(c); e=c.emu; r=c.rng; s=rnd(c,0x20)
 prefix=e.alloc(16); e.wbytes(prefix,r.choice([b'abc\0',b'\0',b'xy\0']))
 arr=e.alloc(32); words=[]
 for i in range(8):
  p=e.alloc(16); e.wbytes(p,r.choice([b'abcdef\0',b'abc\0',b'xyz\0',b'123\0'])); words.append(p); e.w32(arr+i*4,p)
 e.w32(s+4,arr); e.w32(s+8,r.randrange(1,9)); e.w32(s+0xc,r.choice([prefix,prefix,0])); e.w32(s+0x10,r.choice([0xffffffff,0,1,6,7]))
 # Hook the imported comparator, record all input bytes and implement its prefix comparison.
 def cmp(em,res):
  a,b,n=[em.arg32(j) for j in range(3)]; aa=em.rbytes(a,n).lower(); bb=em.rbytes(b,n).lower()
  em.calllog.append(('cmp',aa,bb,n)); em.ret(eax=(aa>bb)-(aa<bb),argbytes=0)
 e.stub_import('_strnicmp',cmp)
 return [s]
S(0x516250,'GUESS lookup referenced entity','thiscall',None,ret='eax',gen=lookup,note='batch63001')
S(0x4c2170,'GUESS read fields and refresh','thiscall',None,ret='al',gen=fields,note='batch63001')
S(0x578d30,'GUESS formatted boolean query','thiscall',None,ret='al',gen=query,note='batch63001')
S(0x60feb0,'GUESS set three cached device states','fastcall',None,ret=None,gen=states,note='batch63001')
S(0x433dc0,'GUESS load configuration defaults','thiscall',None,ret=None,gen=config,note='batch63001')
S(0x4d4540,'GUESS next matching prefix','thiscall',None,ret='eax',gen=match,note='batch63001')
