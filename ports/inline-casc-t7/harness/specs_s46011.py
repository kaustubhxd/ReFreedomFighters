from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def g(c):
    clear_hooks(c)
    r,e=c.rng,c.emu
    s=rnd(c,0x16c0);out=rnd(c,0x2000)
    e.w32(s+8,out);e.w32(s+0x14,r.randrange(9));e.w32(s+0x16b4,r.randrange(17))
    for i in range(19):
        e.wbytes(s+0xa74+i*4,r.getrandbits(16).to_bytes(2,'little'))
        e.wbytes(s+0xa76+i*4,r.randrange(1,16).to_bytes(2,'little'))
    n=r.choice([-1,0,1,2,3,5,6,7,10,11,137,138,139,280,r.randrange(300)])
    vals=[]
    while len(vals)<max(n+1,1):
        vals.extend([r.choice([0,0,0,1,2,7,15])]*r.choice([1,2,3,4,5,6,7,8,10,11,12,137,138,139]))
    vals=vals[:max(n+1,1)]+[0xffff]
    tree=rnd(c,len(vals)*4)
    for i,v in enumerate(vals):e.wbytes(tree+i*4+2,v.to_bytes(2,'little'))
    hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
    return [s,tree,n]
S(0x631100,'GUESS zlib send_tree','cdecl',None,ret=None,gen=g,note='batch46011')
