from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,reftab_vt

def g(c):
    clear_hooks(c)
    r,e=c.rng,c.emu
    def string(b):
        p=rnd(c,len(b)+1);e.wbytes(p,b+b'\0');return p
    def read(em,p,n=2048):
        b=bytearray()
        for i in range(n):
            v=em.rbytes(p+i,1)[0]
            if not v:break
            b.append(v)
        return bytes(b)
    def slot(n,ret=0,**kw):return pystub(c,n,this=True,ret=ret,**kw)
    me=rnd(c,0x100)
    names=[b'Alpha',b'Beta',b'Gamma',b'Delta'][:r.randrange(5)]
    counts=[r.choice([0,0,1,2,5,0xffffffff]) for _ in names]
    countmap={};entries=[]
    for name,count in zip(names,counts):
        rec=rnd(c,8);holder=rnd(c,0x20);countmap[holder]=count
        e.w32(rec,string(name));e.w32(rec+4,holder);entries.append(rec)
    e.w32(me+0xac,reftab_vt(c,entries,count=len(entries)))
    ignores=r.sample([b'#',b';',b'Ignore',b'Alpha'],r.randrange(4))
    e.w32(me+0xc8,reftab_vt(c,[string(x) for x in ignores]))
    extra=string(r.choice([b'\n',b'\r\n',b'!\n']))
    countmap[me+4]=extra
    hook_rec(c,0x4cc1d0,0,this=True,ret=lambda em,k:countmap[em.reg('ecx')])
    hook_rec(c,0x4cc5f0,0,this=True,ret=len(read(e,extra)))
    lines=[]
    for _ in range(r.randrange(8)):
        lines.append(r.choice([b'Alpha=old',b'aLpHa duplicate',b'Beta=2',b'Gamma',b'Delta 4',b'Unknown',b'# comment',b'Ignore blah',b';no',b''])+r.choice([b'\n',b'\r',b'\r\n']))
    data=b''.join(lines)+r.choice([b'',b'Unknown tail',b'Beta tail'])
    buf=rnd(c,len(data)+1)
    snap=rnd(c,(len(entries)+1)*8)
    hook_rec(c,0x41e290,1,pop=0,ret=lambda em,k:buf if k==0 else snap)
    hook_rec(c,0x634273,2,pop=0)
    def fill(em,k):em.wbytes(em.arg32(1),data)
    def wr(em,k):
        em.calllog.append(('write',em.arg32(0),em.rbytes(em.arg32(1),em.arg32(2))))
    fs=obj(c,0x20,{0x34:slot(2,r.choice([0,1,1,1,0x100])),0x30:slot(2,len(data)),
        0x60:slot(5,side=fill),0x14:slot(1,r.getrandbits(32)),0x38:slot(3,stackmark=(1,),side=wr),0x1c:slot(1)})
    e.w32(0x700394,fs)
    lg=obj(c,0x20,{0x2c:pystub(c,3,pop=0)})
    e.w32(0x700390,obj(c,0x20,{0x20:slot(2,lg)}))
    so=sysobj(c);e.wbytes(so+0x6b,bytes([r.choice([0,0,0,0,1])]))
    def strchr(em,k):
        p,ch=em.arg32(0),em.arg32(1)&255;b=read(em,p)
        ix=(b+b'\0').find(bytes([ch]));em.ret(p+ix if ix>=0 else 0,0)
    e.w32(0x676254,e.stub_fn('strchr',strchr))
    def sni(em,k):
        a,b,n=em.arg32(0),em.arg32(1),em.arg32(2)
        x,y=read(em,a)[:n].lower(),read(em,b)[:n].lower()
        em.ret((x>y)-(x<y),0)
    e.w32(0x67640c,e.stub_fn('strnicmp',sni))
    def fmt(em,k):
        dst,f,src=em.arg32(0),em.arg32(1),em.arg32(2)
        b=read(em,src)+b'='+str(em.arg32(3)).encode()+b'\n'
        em.wbytes(dst,b+b'\0')
        return len(b)
    hook_rec(c,0x42ac56,4,pop=0,stackmark=(0,),ret=fmt)
    hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
    return [me,string(b'config.ini')]
S(0x4338c0,'GUESS rewrite configuration file','thiscall',None,ret='al',gen=g,note='batch46010')
