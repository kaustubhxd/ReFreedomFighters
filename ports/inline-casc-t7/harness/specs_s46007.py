from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    me = rnd(c, 0x300)
    key, pending = r.randrange(1, 20), r.choice([0, 21, 22])
    records = [rnd(c, 0x24) for _ in range(5)]
    for p in records:
        e.w32(p, r.choice([0, key, pending, r.randrange(1, 30)]))
        e.w32(p+4, r.choice([0, 1, 5, 20, 0xffffffff, r.getrandbits(32)]))
        e.w32(p+0x10, r.choice([0xb, 0xb, 3, 8]))
        e.wbytes(p+0x14, bytes([r.randrange(2)]))
        e.w32(p+0x15, r.choice([0, 0, r.getrandbits(32)]))
        e.w32(p+0x19, r.choice([0, 1, 1, 2]))
    primary = records[0]
    pendrec = records[1]
    # The table returns stable records but can miss pending keys on either list.
    in_pending = r.choice([True, False])
    in_source = r.choice([True, True, False])
    def find(em, k):
        li, ky = em.reg('ecx'), em.arg32(0)
        if li == me+0x180:
            return primary if ky == key else (pendrec if in_source else 0)
        return pendrec if in_pending else 0
    hook_rec(c, 0x5af130, 1, this=True, ret=find)
    amount = r.choice([0, 1, 7, 0xffffffff, r.getrandbits(32)])
    def out(em, k):
        em.w32(em.arg32(0), pending)
        em.w32(em.arg32(1), amount)
    hook_rec(c, 0x5af5b0, 3, this=True, stackmark=(0,1), side=out)
    for addr, n in [(0x5aedf0,1),(0x5af260,1),(0x5aef10,0),(0x5aee20,2),(0x5b0290,0),(0x569260,0),(0x59a580,3)]:
        hook_rec(c, addr, n, this=True)
    count = r.choice([0, 1, 3, 5, 0xffffffff])
    hook_rec(c, 0x4cc1d0, 0, this=True, ret=count)
    hook_rec(c, 0x5af0d0, 1, this=True, ret=lambda em,k: records[em.arg32(0)%5])
    def slot(n, ret=0, **kw):
        return pystub(c, n, this=True, ret=ret, **kw)
    child = obj(c, 0x20, {0x324:slot(1), 0x2f0:slot(1)})
    base = obj(c, 0x20, {0x2c4:slot(1, child)})
    text = rnd(c, 0x10)
    e.w32(text+4, r.choice([0, rnd(c, 0x20)]))
    limit = r.choice([0, 1, 5, 20, 0xffffffff])
    sound = obj(c, 0x20, {0x1e0:slot(1, r.choice([0,1,1,0x100])),
        0x2e8:slot(0, text), 0x328:slot(0, r.choice([base,base,0])),
        0x360:slot(1), 0x364:slot(0,limit)})
    active = obj(c, 0x20, {0x2e8:slot(0, r.choice([e.r32(pendrec),0,55]))})
    y = obj(c, 0x20, {0x1e0:slot(1,r.choice([0,1,1,0x100])),0x320:slot(0)})
    widget = obj(c, 0x1000, {0x3dc:slot(0),0x4dc:slot(2),0x55c:slot(1,r.choice([0,child])),
        0x3f4:slot(1),0x20:slot(1,r.getrandbits(32))})
    manager = obj(c, 0x20, {0x98:slot(2,r.getrandbits(32)),0x44:slot(2)})
    hook_rec(c, 0x591f00, 0, this=True, ret=r.choice([0,active,active]))
    hook_rec(c, 0x591080, 0, this=True, ret=y)
    lookup = obj(c, 0x20, {0:slot(2,r.getrandbits(32))})
    # Variadic slot 0x4c: one key argument or three args for widget construction.
    table_ret = r.getrandbits(32)
    def t4c(em,k):
        n = 3 if em.arg32(0) == widget else 1
        em.calllog.append(('table4c',em.reg('ecx'),tuple(em.arg32(i) for i in range(n))))
        em.ret(eax=table_ret,argbytes=4*n)
    so = sysobj(c,table_size=0xb00,table_slots={0x114:slot(4,r.getrandbits(32)),
        0x58:slot(1,r.choice([0,sound,sound,sound])),
        0x4c:e.stub_fn('table4c',t4c)})
    e.w32(e.r32(so+0x9b)+0xae4,lookup)
    e.w32(me+0x90,widget)
    e.w32(me+0x94,rnd(c,0xf00))
    e.w32(me+0x288,manager)
    e.w32(me+0x28c,rnd(c,0x40))
    e.w32(me+0x291,r.choice([0,key,key,key,key]))
    hook_rec(c,0x7003b0,2,ret=r.getrandbits(32))
    return [me]

S(0x568dc0,'GUESS refresh pending UI list','thiscall',None,ret=None,gen=g,note='batch46007')
