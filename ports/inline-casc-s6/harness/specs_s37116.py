"""specs_s37116.py - cascade s6 batch 37116 (0x5a8550, thiscall(idA, idB, count) ret 0xc). The allocator 0x41e290 hands out spec blocks, 0x4de7a0 / 0x4dc630 are recording hooks, the
table object (slot 0x58 -> the two factory objects, field +0xadc) and the factories' slot 0x1bc (7 arguments; stack pointers as markers, every call logged) returns fresh objects
with a member at +8 and a release slot 0x28."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g5a8550(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    pool = [e.alloc(0x60, 4) for _ in range(2)]
    for p in pool:
        e.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x60)))
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: pool[k % 2])
    hook_rec(c, 0x4de7a0, 0, this='mark')
    hook_rec(c, 0x4dc630, 2, this=True)

    def mkinst():
        o = obj(c, 0x20, {0x28: pystub(c, 0, this=True)})
        _w(c, o + 8, rnd(c, 0x20))
        return o
    insts = [mkinst() for _ in range(12)]

    def mk(tag):
        def f(em, res_):
            k = em.calllog.count(('f', tag))
            em.calllog.append(('f', tag))
            em.calllog.append(('1bc', tag, tuple((x if not 0x57000000 <= x else 1) for x in (em.arg32(0),)), tuple(em.arg32(i) for i in range(3, 7))))
            em.ret(eax=insts[(len(em.calllog) // 2) % 12], argbytes=28)
        return f
    fa = obj(c, 0x20, {0x1bc: e.stub_fn('fa', mk('a'))})
    fb = obj(c, 0x20, {0x1bc: e.stub_fn('fb', mk('b'))})
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: fa if k == 0 else fb)}, table_size=0xb00)
    tab = int.from_bytes(e.rbytes(so + 0x9b, 4), 'little')
    _w(c, tab + 0xadc, r.getrandbits(32))
    t = rnd(c, 0x20)
    return [t, r.getrandbits(32), r.getrandbits(32), r.choice([0, 1, 2, 3, 5])]


S(0x5a8550, 'GUESS make_instances', 'thiscall', None, ret=None, gen=_g5a8550, note='batch37116')
