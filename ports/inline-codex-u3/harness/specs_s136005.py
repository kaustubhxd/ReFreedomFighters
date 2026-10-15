from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 def text(em,k):
  p=em.arg32(0);b=bytearray()
  while em.rbytes(p+len(b),1)!=b'\0':b.extend(em.rbytes(p+len(b),1))
  em.calllog.append(('text',bytes(b)))
 widgets=[]
 for i in range(2):
  w=obj(c,0xb0,{0x284:pystub(c,1,this=True,stackmark=(0,),side=text)})
  b=r.choice([b'',b'\n\n Hello  world\n',b'  a   b  ',bytes(r.choice(b'ab  \n\tXYZ') for _ in range(r.randrange(1,190)))])+b'\0'
  p=rnd(c,len(b));e.wbytes(p,b);e.w32(w+0x97,p);widgets.append(r.choice([w,w,w,0]))
 def lookup(em,k):return widgets[0 if em.arg32(0)==0x6a78e8 else 1]
 parent=obj(c,0x40,{0x25c:pystub(c,2,this=True,ret=lookup)})
 so=sysobj(c,slots={0xc:pystub(c,4,this=True)},table_slots={0xa4:pystub(c,0,this=True),0xa0:pystub(c,1,this=True)})
 s=rnd(c,0x80);e.w32(s+0x44,parent);e.w32(s+0x48,r.choice([0,1,2,3,0xfffffffe,0xffffffff]));e.wbytes(s+0x50,bytes([r.randrange(2)]))
 hook_rec(c,0x634273,2,pop=0)
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [s]
S(0x56aea0,'GUESS normalize widget text and retire resource','thiscall',None,ret=None,gen=gen)
