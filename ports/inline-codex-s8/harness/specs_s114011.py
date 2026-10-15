from pilot import S
from recruits_util import clear_hooks,rnd,hook_rec,_HOOKED
from unicorn.x86_const import UC_X86_REG_EDX

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng;s=rnd(c,0x160);page=rnd(c,32);hdr=rnd(c,64)
 n=r.randrange(9);e.w8(hdr+26,n);lengths=[r.choice([0,1,3,7,255]) for _ in range(n)]
 for i,v in enumerate(lengths):e.w8(hdr+27+i,v)
 data=rnd(c,max(16,sum(lengths)));e.w32(page,hdr);e.w32(page+8,data);e.w32(page+12,sum(lengths))
 dst=rnd(c,8192);lacing=rnd(c,256);granules=rnd(c,512);e.w32(s,dst);e.w32(s+16,lacing);e.w32(s+20,granules)
 count=r.randrange(9);consumed=r.randrange(count+1);start=r.randrange(consumed,count+1)
 e.w32(s+28,count);e.w32(s+32,start);e.w32(s+36,consumed)
 for i in range(count):e.w32(lacing+i*4,r.randrange(8))
 e.w32(s+8,128);e.w32(s+12,r.randrange(16));serial=r.getrandbits(32);e.w32(s+0x150,serial)
 number=r.randrange(5);e.w32(s+0x154,r.choice([number,number,0xffffffff,number+1]))
 values={0x410100:r.choice([0,0,0,1,0xffffffff]),0x410110:r.randrange(2),0x410120:r.randrange(2),0x410130:r.randrange(2),0x410220:r.choice([serial,serial,serial^1]),0x410250:number}
 for addr,v in values.items():hook_rec(c,addr,nargs=1,pop=0,ret=v)
 lo=r.getrandbits(32);hi=r.getrandbits(32)
 def gran(em,_):em.calllog.append(('granule',em.arg32(0)));em.mu.reg_write(UC_X86_REG_EDX,hi);em.ret(eax=lo,argbytes=0)
 def move(em,_):
  dst,src,size=[em.arg32(i) for i in range(3)];data=em.rbytes(src,size);em.wbytes(dst,data);em.calllog.append(('move',dst,src,size));em.ret(eax=dst,argbytes=0)
 for addr,fn in [(0x410140,gran),(0x634d28,move)]:e.hook(addr,fn);_HOOKED.add(addr)
 for addr in [0x410420,0x4103f0]:hook_rec(c,addr,nargs=2,pop=0,ret=0)
 return [s,page]
S(0x4106f0,'GUESS ingest paged packet data','cdecl',None,ret='eax',gen=gen)
