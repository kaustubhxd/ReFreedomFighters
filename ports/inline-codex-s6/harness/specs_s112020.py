from pilot import S
from recruits_util import rnd,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 pointer=[0]
 def memset(em,k):em.wbytes(em.arg32(0),bytes(em.arg32(2)))
 hook_rec(c,0x634d10,3,pop=0,stackmark=(0,),side=memset,ret=lambda em,k:em.arg32(0))
 def format(em,k):
  p=em.arg32(0);pointer[0]=p;em.wbytes(p,('row%d:'%em.arg32(2)).encode()+b'\0')
 hook_rec(c,0x42ac56,3,pop=0,stackmark=(0,),side=format)
 def finish(em,k):
  p=pointer[0]
  if p:
   s=bytearray()
   while em.rbytes(p,1)!=b'\0':s+=em.rbytes(p,1);p+=1
   em.calllog.append(('final_text',bytes(s)))
 hook_rec(c,0x633654,0,side=finish)
 me=rnd(c,0x8500);count=r.randrange(0,5);e.w32(me+0x8065,count)
 for i in range(count):
  entry=me+0x807d+0x110*i;n=r.randrange(0,8);e.w32(entry-12,n)
  for j in range(n):e.w32(entry+8*j,r.choice([0,1,2,3,4,0xffffffff]))
 return [me]
S(0x549c50,'GUESS describe_entry_types','thiscall',None,ret=None,gen=gen,note='cookie hook observes final stack text; port explicitly retains cookie callee for observability')
