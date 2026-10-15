from pilot import S
from recruits_util import rnd,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));hook_rec(c,0x65c730,0,this=True)
 me=rnd(c,0x10060);counter=rnd(c,0x60);e.w32(me+0x10051,counter)
 base=rnd(c,0x2000);manager=rnd(c,0x30);e.w32(manager+0x20,base);so=sysobj(c);e.w32(so+0x1aa3,manager)
 n=r.randrange(0,8);e.w32(me+0x20,n)
 for i in range(n):
  a=rnd(c,32);b=rnd(c,32);cc=rnd(c,32);meta=rnd(c,0x80);e.w32(a+8,b);e.w32(b+0x10,cc);e.w32(cc+8,meta)
  e.w32(meta+12,r.choice([0,1,3,4,5]));e.w32(meta+0x78,r.randrange(20));offset=i*0x200;e.w32(meta+0x3c,offset)
  count=r.randrange(0,5);e.wbytes(base+offset,count.to_bytes(2,'little'));p=base+offset+2
  for j in range(count):
   length=r.randrange(0,10);e.wbytes(p,length.to_bytes(2,'little'));p+=2*(length+1)
  data=rnd(c,0x30);e.w32(data,r.getrandbits(32));e.w32(data+0x1c,r.getrandbits(32));e.w32(a+0x1c,data)
  e.w32(me+0x28+8*i,r.choice([0,1,2,3,15,0x10,0x21]));e.w32(me+0x2c+8*i,a)
 return [me]
S(0x65c840,'GUESS accumulate_render_statistics','thiscall',None,ret=None,gen=gen)
