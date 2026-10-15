from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 me=rnd(c,32);pool=rnd(c,32*32);node=rnd(c,32);item=rnd(c,32);lo=rnd(c,12);hi=rnd(c,12)
 e.w32(me,rnd(c,32));e.w32(me+4,pool);e.w32(me+16,32)
 depth=r.randrange(8,16);cell=65536>>depth;e.wbytes(node+10,bytes([depth]));e.wbytes(node+8,r.randrange(8).to_bytes(2,'little'))
 for i in range(32):
  for j in range(4):e.wbytes(pool+i*32+j*2,r.choice([0,r.randrange(1,32)]).to_bytes(2,'little'))
 old=[r.randrange(1024,64000) for _ in range(3)]
 for i in range(3):e.wbytes(item+12+i*2,old[i].to_bytes(2,'little'));e.wbytes(item+18+i*2,(old[i]+r.randrange(1,50)).to_bytes(2,'little'))
 new=[v+r.choice([0,1,-1,cell,-cell,2*cell,1000]) for v in old];size=r.choice([1,max(1,cell//2),cell,cell+1,cell*3])
 if r.randrange(5)==0:new=r.choice([[-10,-5,-1],[65500,65500,65500],[-100,10,20]])
 for i in range(3):e.w32(lo+i*4,new[i]&0xffffffff);e.w32(hi+i*4,(new[i]+size-1)&0xffffffff)
 left=r.choice([0,rnd(c,32)]);right=r.choice([0,rnd(c,32)])
 e.w32(item,left);e.w32(item+4,right);e.w32(item+24,node)
 hook_rec(c,0x4e4960,1,this=True);hook_rec(c,0x4e4900,1,this=True);hook_rec(c,0x4e42a0,1,this=True)
 allocated=rnd(c,32);idx=r.randrange(1,32)
 def allocate(em,k):em.wbytes(em.arg32(0),idx.to_bytes(2,'little'))
 hook_rec(c,0x4e6b80,1,this=True,stackmark=(0,),ret=allocated,side=allocate)
 hook_rec(c,0x4e4a50,2,this=True);hook_rec(c,0x4e4890,1,this=True);hook_rec(c,0x4e4990,1,this=True,ret=r.getrandbits(32))
 hook_rec(c,0x4e3f60,1,this=True,deref={0:7})
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,item,lo,hi]
S(0x4e4bd0,'GUESS relocate spatial grid item','thiscall',None,ret=None,gen=g,note='batch128016')
