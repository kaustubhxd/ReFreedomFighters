from pilot import S
from recruits_util import clear_hooks,rnd,obj,hook_rec

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 stamp=r.getrandbits(32);system=rnd(c,0x80);e.w32(system+0x3c,stamp);e.w32(0x70039c,system)
 def finish(em,_):em.calllog.append(('finish',em.reg('ecx')));em.ret(eax=0,argbytes=0)
 s=obj(c,0x18200,{0x24:e.stub_fn('finish',finish)})
 # Randomize the large object while preserving its vtable.
 e.wbytes(s+4,bytes(r.getrandbits(8) for _ in range(0x181fc)))
 map=rnd(c,256);dd=rnd(c,32);e.w32(dd+16,map);e.w32(s+0x10051,dd)
 ring=rnd(c,0x8300);e.w32(s+0x1005d,ring);e.w32(ring+0x268,ring+0x268+8+4*r.choice([0,1,8190,8191]))
 heads=rnd(c,32);e.w32(s+0x10071,heads)
 for i in range(8):e.w32(heads+i*4,rnd(c,32))
 def advance(em,ip):
  ptr,idx,node=em.r32(ip),em.r32(ip+4),em.r32(ip+8);idx+=1
  if idx==em.r32(node):
   node=em.r32(node+8);ptr=node+16 if node else 0
   if node:idx=0
  else:ptr+=4
  em.w32(ip,ptr);em.w32(ip+4,idx);em.w32(ip+8,node)
 def remove(em,_):
  ip=em.arg32(0);em.calllog.append(('remove',em.reg('ecx'),em.r32(em.r32(ip))));advance(em,ip);em.ret(eax=0,argbytes=4)
 for off,kind in [(0x10171,0),(0x10185,1),(0x101ad,2)]:
  nodes=[]
  for _ in range(r.randrange(3)):
   n=r.randrange(1,4);node=rnd(c,16+4*n);e.w32(node,n);nodes.append(node)
   for j in range(n):
    p=rnd(c,48);data=rnd(c,80);e.w32(p+8,data);e.w32(p+16,r.choice([stamp,stamp^1]));e.w32(node+16+j*4,p)
    if kind==1:e.w16(data+0x3e,r.choice([0,0,1]));e.w8(data+0x3c,r.choice([0,1,2,255]))
    if kind==2:
     e.w8(p+4,r.choice([0,5,6,6]));link=rnd(c,32);leaf=rnd(c,16);e.w32(data+16,link);e.w32(link+8,leaf);e.w16(leaf+6,r.randrange(8))
  for i,node in enumerate(nodes):e.w32(node+8,nodes[i+1] if i+1<len(nodes) else 0)
  first=nodes[0] if nodes else 0
  def begin(em,_,first=first,off=off):
   ip=em.arg32(0);em.w32(ip,first+16 if first else 0);em.w32(ip+4,0);em.w32(ip+8,first);em.calllog.append(('begin',off));em.ret(eax=0,argbytes=4)
  vt=rnd(c,24);e.w32(vt+12,e.stub_fn('begin',begin));e.w32(vt+16,e.stub_fn('remove',remove));e.w32(s+off,vt)
 for addr,nargs in [(0x64c2d0,0),(0x64c240,1),(0x6491b0,1),(0x63f030,1),(0x64b3c0,1)]:hook_rec(c,addr,nargs=nargs,ret=0)
 return [s]
S(0x64de70,'GUESS cleanup active resource collections','thiscall',None,ret=None,gen=gen)
