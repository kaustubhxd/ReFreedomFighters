"""specs_s2618.py - wider batch 2618: nine unclaimed functions; callees and slots are recorders (arities from `ret` immediates)."""
import struct
import pe_emu
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger, reftab_vt


def rl(r, n, f):
    v = [f() for _ in range(n)]
    return lambda em, k: v[k % n]


def _w(e, a, v):
    e.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _is_stack(v):
    return pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= v < pe_emu.STACK_TOP


def g48b690(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, nargs=2, slot=0x2c)
    so = sysobj(c)
    tbl = e.r32(so + 0x9b)
    rr = obj(c, 0x20, {8: pystub(c, 0, this=True)})
    esi = obj(c, 0x20, {0x10c: pystub(c, 2, this=True, ret=rr)}) if r.random() < 0.8 else 0
    o = rnd(c, 0x80)
    e.w32(o + 0x54, esi)
    m = obj(c, 0x20, {8: pystub(c, 4, this=True, ret=o)})
    e.w32(tbl + 8, m)
    return []


def g48d0e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4db9a0, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100]))
    so = sysobj(c, table_size=0xb00)
    tbl = e.r32(so + 0x9b)
    elems = []
    for _ in range(r.choice([0, 1, 2, 4])):
        el = rnd(c, 0x80)
        e.w32(el + 0x54, obj(c, 0x20, {0x21c: pystub(c, 0, this=True)}))
        elems.append(el)
    nxt = list(elems[1:]) + [0]

    def adv(em, k):
        em.w32(em.arg32(0), nxt[k] if k < len(nxt) else 0)
    L = obj(c, 0x60, {0x50: pystub(c, 1, this=True, nullflag=(0,), side=adv)})
    e.w32(L + 8, elems[0] if elems else 0)
    e.w32(tbl + 0xadc, L)
    return []


def g48dea0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def cmp(em, rr):
        a, b = em.arg32(0), em.arg32(1)
        em.calllog.append(('cmp', a, b))
        em.ret(eax=0 if a == b else 1, argbytes=0)
    e.w32(0x676414, e.stub_fn('cmp', cmp))
    n = r.choice([0, 1, 2, 3, 5])
    nodes = [rnd(c, 0x40) for _ in range(n)]
    for i, nd in enumerate(nodes):
        e.w32(nd, r.choice([1, 2, 3]))
        e.w32(nd + 4, r.choice([0, 0, 1]))
        e.w32(nd + 8, r.getrandbits(32))
        e.w32(nd + 0xc, r.getrandbits(32))
        _w(e, nd + 0x2b, r.choice([0, 1, 2, 3]))
        e.w32(nd + 0x14, nodes[i + 1] if i + 1 < n else 0)
    e.w32(0x7003bc, nodes[0] if nodes else 0)
    return []


def g4908c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    keys = [r.getrandbits(32) for _ in range(3)]
    elems = []
    for _ in range(r.choice([0, 1, 2, 4])):
        el = rnd(c, 0x40)
        e.w32(el + 0x34, r.choice(keys))
        elems.append(el)
    me = rnd(c, 0xc00)
    e.w32(me + 0xb00, reftab_vt(c, elems))
    return [me, r.choice(keys + [r.getrandbits(32)])]


def _sized(alloc):
    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        if alloc:
            hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: em.alloc(0x40, 4))
        nval = r.choice([0, 0, 3, 8, 0x30])

        def side(em, k):
            p = em.arg32(0)
            if _is_stack(p):
                em.w32(p, nval)
                em.calllog.append(('size-read',))
            else:
                em.calllog.append(('data', p, em.arg32(1)))
        me = obj(c, 0x20, {0x18: pystub(c, 2, this=True, nullflag=(0,), side=side)})
        return [me, rnd(c, 0x40)]
    return g


def g49a510(c):
    clear_hooks(c)
    r = c.rng
    cnt = r.choice([0, 1, 2, 4])

    def side(em, k):
        em.w32(em.arg32(0), cnt if k == 0 else r.getrandbits(32))
    me = obj(c, 0x20, {0x14: pystub(c, 1, this=True, nullflag=(0,), side=side)})
    ob = obj(c, 0x20, {0xc: pystub(c, 0, this=True), 4: pystub(c, 1, this=True)})
    return [me, ob]


def g49c680(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x49cbb0, 3, this=True, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x49ccc0, 3, this=True, ret=lambda em, k: r.getrandbits(32))
    return [rnd(c, 0x20), r.getrandbits(32), r.getrandbits(32)]


def g4a37a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4e6330, 1, this=True)
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda em, k: r.getrandbits(32))

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    me = rnd(c, 0x100)
    vt = e.alloc(0x40, 4)
    e.w32(vt + 0x14, pystub(c, 0, this=True, ret=r.choice([0, 1, 5])))
    e.w32(me + 0x78, vt)
    return [me, rnd(c, 0x40)]


S(0x48b690, 'GUESS fetch named object, call slot 0x10c', 'cdecl', None, ret='eax', gen=g48b690, note='batch2618')
S(0x48d0e0, 'GUESS walk list, slot 0x21c on flagged', 'cdecl', None, ret=None, gen=g48d0e0, note='batch2618')
S(0x48dea0, 'GUESS link nodes by name', 'cdecl', None, ret=None, gen=g48dea0, note='batch2618')
S(0x4908c0, 'GUESS find element by key', 'thiscall', None, ret='eax', gen=g4908c0, note='batch2618')
S(0x499ac0, 'GUESS read sized string', 'thiscall', None, ret='eax', gen=_sized(False), note='batch2618')
S(0x499b00, 'GUESS read sized block', 'thiscall', None, ret='eax', gen=_sized(True), note='batch2618')
S(0x49a510, 'GUESS read counted items', 'thiscall', None, ret=None, gen=g49a510, note='batch2618')
S(0x49c680, 'GUESS two tests', 'thiscall', None, ret='al', gen=g49c680, note='batch2618')
S(0x4a37a0, 'GUESS read and check', 'thiscall', None, ret=None, gen=g4a37a0, note='batch2618')
