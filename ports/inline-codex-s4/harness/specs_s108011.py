from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,reftab,reftab_vt

def base(c):
 clear_hooks(c);c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def gcac0(c):
 base(c);e=c.emu;r=c.rng
 state=rnd(c,0x10);e.w32(state+0xc,r.choice([0,0,1,r.getrandbits(32)]))
 match=rnd(c,0x30);hit=r.randrange(10)
 e.w32(match+0x1c,pystub(c,4,pop=0,ret=lambda em,k:0 if k!=hit else rvalue))
 rvalue=r.getrandbits(32)|1
 for i in range(8):e.w32(0x6f4458+4*i,r.getrandbits(32))
 return [state,r.choice([15,18,18,18,23,28,28,0,19,0xffffffff]),r.getrandbits(32),r.getrandbits(32),match]

def ge9e0(c):
 base(c);e=c.emu;r=c.rng
 names=[b'',b'alpha',b'ALPHA',b'beta',b'BETA',b'gamma']
 entries=[];mapping={}
 n=r.randrange(8)
 for i in range(n):
  ident=r.getrandbits(32);entry=rnd(c,8);e.w32(entry,ident);entries.append(entry)
  text=r.choice(names);p=rnd(c,0x20);e.wbytes(p,text+b'\0')
  geom=rnd(c,0x20);e.w32(geom+4,r.choice([p,p,0]));mapping[ident]=r.choice([0,geom,geom])
 table=reftab(c,entries)
 # Use a destructive iterator whose erase adjusts iteration position.
 def nextptr(em,rr):
  it=em.arg32(0);index=em.r32(it+4);em.w32(it+4,index+1)
  em.ret(eax=entries[index] if index<len(entries) else 0,argbytes=4)
 def remove(em,rr):
  it=em.arg32(0);index=em.r32(it+4)-1
  em.calllog.append(('erase_mark',em.r32(entries[index])))
  entries.pop(index);em.w32(it+4,index)
  em.ret(eax=0,argbytes=4)
 vt=e.r32(table);e.w32(vt+0x64,e.stub_fn('nextptr',nextptr));e.w32(vt+0x44,e.stub_fn('eraseptr',remove))
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:mapping[em.arg32(0)])})
 def cstr(em,p):
  result=bytearray()
  while em.r8(p):result.append(em.r8(p));p+=1
  return bytes(result)
 def cmp(em,rr):
  a=cstr(em,em.arg32(0));b=cstr(em,em.arg32(1));em.calllog.append(('stricmp',a,b))
  em.ret(eax=0 if a.lower()==b.lower() else (-1 if a.lower()<b.lower() else 1),argbytes=0)
 e.stub_import('_stricmp',cmp)
 me=rnd(c,0x80);e.w32(me+0x70,r.choice([0,table,table,table]))
 e.w32(me+0x6c,obj(c,0x20,{0x40:pystub(c,1,this=True)}));e.w32(me+0x74,obj(c,0x20,{0x40:pystub(c,1,this=True)}))
 query=rnd(c,0x20);e.wbytes(query,r.choice(names)+b'\0')
 return [me,query]
S(0x62cac0,'GUESS keyword matcher state dispatch','cdecl',None,ret='eax',gen=gcac0)
S(0x46e9e0,'GUESS take first marked geometry matching name','thiscall',None,ret='eax',gen=ge9e0)
