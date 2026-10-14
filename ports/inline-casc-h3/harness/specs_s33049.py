"""specs_s33049.py - h3 () batch 33049."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _gsys(off, argc=1):
    def g(c):
        clear_hooks(c)
        r = c.rng
        stub = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
        sysobj(c, table_slots={0x58: stub})
        me = rnd(c, 0x100)
        c.emu.w32(me + off, r.choice([0, _w(c), _w(c)]))
        return [me] + [_w(c)] * (argc - 1 if False else 0) + ([_w(c)] if argc == 2 else [])
    return g


def _g4cbe20(c):
    clear_hooks(c)
    e = c.emu
    r = c.rng

    def h(em, rr):
        em.calllog.append(('fp', 0, None, (em.reg('ecx'), em.reg('edx'), em.arg32(0), em.arg32(1))))
        em.ret(eax=_w(c), argbytes=8)
    fp = e.stub_fn('fnptr', h)
    me = rnd(c, 0x80)
    e.w32(me + 0x1f, fp)
    return [me, _w(c), _w(c), _w(c)]


def _g59fd00(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x478b70, 2, this=True, ret=lambda em, k: _w(c))
    stub = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    me = obj(c, 0x800, {0x21c: stub})
    c.emu.wbytes(me + 0x7a6, bytes([r.choice([0, 1, 3, 2, r.getrandbits(8)])]))
    return [me, _w(c), _w(c)]


def _g6515a0(c):
    clear_hooks(c)
    e = c.emu
    me = rnd(c, 0x100)
    o3 = rnd(c, 0x40)
    st = {}
    stub2 = pystub(c, 1, this=True, side=lambda em, k: e.w32(me + 0xbd, o3), ret=lambda em, k: _w(c))
    o2 = obj(c, 0x40, {0: stub2})
    o1 = rnd(c, 0x40)
    hook_rec(c, 0x4690b0, 0, this=True, side=lambda em, k: e.w32(me + 0xbd, o2))
    hook_rec(c, 0x63d910, 0, this=True, ret=lambda em, k: _w(c))
    e.w32(me + 0xbd, o1)
    return [me]


def _g4632d0(c):
    clear_hooks(c)
    e = c.emu

    def side(em, k):
        d = em.reg('edx')
        em.calllog.append(('edx', 0, None, tuple(em.r32(d + 4 * i) for i in range(9))))
    hook_rec(c, 0x4de420, 0, this=True, side=side)
    stub = pystub(c, 1, this=True, ret=lambda em, k: rnd(c, 0x30))
    child = obj(c, 0x40, {0x58: stub})
    me = rnd(c, 0x100)
    e.w32(me + 0x6c, child)
    return [me, rnd(c, 0x30)]


def _gA(off, argc):
    def g(c):
        clear_hooks(c)
        stub = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
        a = obj(c, 0x80, {off: stub})
        return [rnd(c, 0x80), a]
    return g


S(0x46e8c0, 'GUESS sys table lookup by id', 'thiscall', None, ret='eax', gen=_gsys(0x68), note='batch33049')
S(0x4cbe20, 'GUESS call field fn ptr fastcall', 'thiscall', None, ret='eax', gen=_g4cbe20, note='batch33049')
S(0x59fd00, 'GUESS flag vcall or tail', 'thiscall', None, ret='eax', gen=_g59fd00, note='batch33049')
S(0x6515a0, 'GUESS child call chain re-read', 'thiscall', None, ret='eax', gen=_g6515a0, note='batch33049')
S(0x4632d0, 'GUESS child vcall 0x58 then copy', 'thiscall', None, ret=None, gen=_g4632d0, note='batch33049')
S(0x46ef70, 'GUESS sys table lookup by id 2', 'thiscall', None, ret='eax', gen=_gsys(0xe1, 2), note='batch33049')
S(0x4c5750, 'GUESS clear flag vcall 0x60', 'thiscall', None, ret='al', gen=_gA(0x60, 1), note='batch33049')
S(0x4cbdd0, 'GUESS clear flag vcall 0x50', 'thiscall', None, ret='al', gen=_gA(0x50, 1), note='batch33049')
