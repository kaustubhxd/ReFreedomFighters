"""specs_s36028.py - cascade s4 batch 36028: 0x5307c0 (build a 22-dword stack record and call the renderer), 0x468320 (check a flag and notify), 0x468a30 (look up a name and update), 0x46d760 (notify the sink for ready entries), 0x473000 (state switch by owner)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _w32(c, a, v):
    c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _g5307c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ret = r.getrandbits(32)

    def h(em, rr):
        ec = em.reg('ecx')
        a = [em.arg32(i) for i in range(9)]
        s = a[0]
        sv = [em.r32(s + 4 * i) for i in range(13)]
        t0 = [em.r32(sv[1] + 4 * i) for i in range(3)]
        t1 = [em.r32(sv[2] + 4 * i) for i in range(3)]
        t2 = [em.r32(sv[3] + 4 * i) for i in range(3)]
        blk = [em.r32(sv[0] + 4 * i) for i in range(7)]
        em.calllog.append(('52d750', ec, tuple(a[1:]), (sv[4] & 0xff, sv[5]) + tuple(sv[6:]), tuple(blk), tuple(t0), tuple(t1), tuple(t2)))
        em.ret(eax=ret, argbytes=36)
    e.hook(0x52d750, h)
    E = rnd(c, 0x60)
    p = rnd(c, 0x10)
    return [E, r.getrandbits(32), p, r.getrandbits(32)]


def _g468320(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)
    X = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100])), 0x2dc: pystub(c, 2, this=True)})
    cc = obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=X)})
    blk = rnd(c, 0x60)
    e.w32(cc + 8, blk)
    e.w32(cc + 4, 0 if r.random() < 0.4 else rnd(c, 0x10))
    E = obj(c, 0x100, {0x58: pystub(c, 0, this=True)})
    e.w32(E + 0x44, cc)
    return [E]


def _g468a30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    res = [r.choice([0, 1, 5]) for _ in range(2)]

    def m(em, rr):
        em.calllog.append(('4cc850', em.reg('ecx'), em.reg('edx')))
        em.ret(eax=res[0], argbytes=0)
    e.hook(0x4cc850, m)
    hook_rec(c, 0x41e680, 1, this=True, ret=r.getrandbits(32))

    def s88(em, rr):
        v = 0 if r.random() < 0.4 else r.getrandbits(32)
        em.w32(em.arg32(1), v)
        em.calllog.append(('s88', em.reg('ecx'), em.arg32(0)))
        em.ret(eax=0, argbytes=8)
    x = obj(c, 0x20, {0x88: e.stub_fn('s88', s88)})
    o = obj(c, 0x20, {0x128: pystub(c, 2, this=True)})
    so = sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=x), 0x58: pystub(c, 1, this=True, ret=o),
                                0x114: pystub(c, 4, this=True, ret=r.getrandbits(32))})
    cobj = obj(c, 0x20, {0xac: pystub(c, 2, this=True)})
    e.wbytes(so + 0x190f, cobj.to_bytes(4, 'little'))
    a = rnd(c, 0x10)
    e.w32(a + 4, 0 if r.random() < 0.4 else rnd(c, 0x10))
    return [a]


def _g46d760(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3])
    elems = []
    for i in range(n):
        el = rnd(c, 0x10)
        e.w32(el + 4, r.getrandbits(32) | 1)
        elems.append(el)
    objs = []
    for i in range(n):
        if r.random() < 0.2:
            objs.append(0)
        else:
            q = 0 if r.random() < 0.25 else obj(c, 0x20, {0x90: pystub(c, 0, this=True, ret=r.choice([0, 1, 0x100]))})
            objs.append(obj(c, 0x20, {0x100: pystub(c, 1, this=True, ret=q)}))
    seq = elems + [0]
    cobj = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, stackmark=(0,)), 0x44: pystub(c, 1, this=True, stackmark=(0,)),
                         0x64: pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: seq[min(k, len(seq) - 1)])})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: objs[min(k, len(objs) - 1)] if objs else 0)})
    sink = obj(c, 0x20, {4: pystub(c, 1, this=True)})
    E = rnd(c, 0x80)
    e.w32(E + 0x70, 0 if r.random() < 0.1 else cobj)
    return [E, sink]


def _g473000(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2)
    a = 0 if r.random() < 0.2 else r.getrandbits(32) | 1
    sv = a if r.random() < 0.4 else r.getrandbits(32)
    tv = a if r.random() < 0.5 else r.getrandbits(32)
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    E = obj(c, 0x40, {0x500: pystub(c, 0, this=True, ret=sv), 0x504: pystub(c, 0, this=True, ret=tv),
                      0x3f0: pystub(c, 0, this=True, ret=r.choice([9, 0xa, 0, 5])), 0x45c: pystub(c, 2, this=True)})
    return [E, a]


S(0x5307c0, 'GUESS build stack record and call the renderer', 'thiscall', None, ret='eax', gen=_g5307c0, note='batch36028')
S(0x468320, 'GUESS flag check and notify', 'thiscall', None, ret=None, gen=_g468320, note='batch36028')
S(0x468a30, 'GUESS name lookup and update', 'stdcall', None, ret=None, gen=_g468a30, note='batch36028')
S(0x46d760, 'GUESS notify sink for ready entries', 'thiscall', None, ret=None, gen=_g46d760, note='batch36028')
S(0x473000, 'GUESS state switch by owner', 'thiscall', None, ret=None, gen=_g473000, note='batch36028')
