from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 def string(b):
  p=rnd(c,len(b)+1);e.wbytes(p,b+b'\0');return p
 names={}
 base=rnd(c,128);base+=8;e.w32(base-8,r.choice([0x80,0xa0000080]))
 origin=r.getrandbits(32)
 table_ref=string(b'reference')
 def slot(n,ret=0,**kw):return pystub(c,n,this=True,ret=ret,**kw)
 def streamwrite(em,k):em.calllog.append(('bytes',em.rbytes(em.arg32(0),em.arg32(1))))
 stream=obj(c,32,{8:slot(1),0x28:slot(1),0x10:slot(2,stackmark=(0,),side=streamwrite)})
 arg=rnd(c,16);e.w32(arg,stream);e.w32(arg+4,rnd(c,8));e.w32(arg+8,rnd(c,8))
 arr=rnd(c,16*112);holder=rnd(c,16);e.w32(holder+4,arr)
 me=rnd(c,0x80);e.w32(me+0x14,holder);e.w32(me+0x28,0);e.w32(me+0x5d,rnd(c,16*4))
 nodes=[arr+i*112 for i in range(1,5)]
 for i,p in enumerate(nodes):
  e.w32(p+0x3c,r.choice([0,0,0x8000000]))
  desc=rnd(c,0x58);typ=rnd(c,0x30);ref=rnd(c,16)
  e.w32(typ+0x23,0x100000 if i==0 else r.getrandbits(32)&~0x100000)
  e.w32(desc+12,typ);e.w32(desc+16,r.choice([0,ref]));e.w32(ref+12,r.choice([0,table_ref]))
  e.w32(desc+0x50,nodes[1] if i==0 and r.randrange(2) else 0)
  e.w32(p+0x54,r.choice([0,desc]) if i else desc)
  e.w32(p+0x60,nodes[i+1] if 1<=i<3 else 0)
  if r.randrange(3)==0:
   off=r.randrange(48);name=base+off;e.wbytes(name,b'pool\0')
  else:name=string(r.choice([b'',b'geom',b'Longer name',b'<NONAME>',b'<noname>']))
  names[p]=name
 hook_rec(c,0x4dc2b0,1,this=True)
 hook_rec(c,0x4dc110,0,this=True,ret=lambda em,k:names[em.reg('ecx')])
 hook_rec(c,0x499670,2,this=True)
 hook_rec(c,0x41e650,1,this=True,ret=r.choice([0,1,0x100,255]))
 so=sysobj(c,table_slots={0x17c:slot(0,origin)},table_size=0x1c70)
 e.w32(e.r32(so+0x9b)+0x1c5d,r.choice([0,base,base]))
 def read(em,p):
  b=bytearray()
  while True:
   x=em.rbytes(p+len(b),1)[0]
   if not x:return bytes(b)
   b.append(x)
 def ci(em,k):
  a,b=read(em,em.arg32(0)).lower(),read(em,em.arg32(1)).lower();em.calllog.append(('stricmp',a,b));em.ret((a>b)-(a<b),0)
 e.w32(0x676414,e.stub_fn('stricmp',ci))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,arg,nodes[0]]
S(0x499360,'GUESS serialize geometry tree','thiscall',None,ret=None,gen=g,note='batch128011')
