"""specs_s276.py - area 22, batch276 (src/batch276.cpp): the input action system. Lists are Python objects whose vt 0x4c
starts an iteration and vt 0x5c returns the next member and writes the iterator's first word (1 while valid, 0 at the
end); nothing logs a stack address. ZInputActionBase::IsActive 0x439670 and ZInputAction::CheckAction 0x437d60 are not
verified anywhere and are hooked (GUESS stubs, per-call results); 0x438c30 (inline-unclaimed-76) runs as exe code;
GetActiveActions' spec hooks 0x438150 (verified in this batch) to keep its world small. memset is a Python import stub."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt, _hk, _log_world


def _r(c):
    return c.rng.getrandbits(32)


def _slot(name, nargs, ret=0):
    def h(em, r):
        em.calllog.append((name, 0, None, tuple(em.arg32(i) for i in range(nargs))))
        em.ret(eax=ret(em) if callable(ret) else ret, argbytes=4 * nargs)
    return h


def _list(c, name, items):
    st = {'i': 0}
    marks = [c.rng.choice([1, 2, 0x80000000, _r(c) | 1]) for _ in items]

    def start(em, r):
        em.calllog.append((name + '.4c', 0, None, ()))
        st['i'] = 0
        em.w32(em.arg32(0), _r(c) | 1)
        em.ret(eax=0, argbytes=4)

    def nxt(em, r):
        it = em.arg32(0)
        if st['i'] < len(items):
            v = items[st['i']]
            st['i'] += 1
            em.w32(it, marks[st['i'] - 1])
        else:
            v = 0x5eed
            em.w32(it, 0)
        em.calllog.append((name + '.5c', 0, None, ()))
        em.ret(eax=v, argbytes=4)
    o = _rnd(c, 0x10)
    c.emu.w32(o, _pyvt(c, {0x4c: start, 0x5c: nxt}))
    return o


def _seq(c, n, choices):
    return [c.rng.choice(choices) for _ in range(n)]


def _hk_seq(c, addr, name, vals):
    q = list(vals)
    _hk(c, addr, name, 0, eax=lambda em: q.pop(0) if q else 0)


def _g_437ed0(c):
    e = c.emu
    _hk_seq(c, 0x439670, 'isactive.439670', _seq(c, 2, [0, 1, 1, 0x101, 0x100]))
    blk = _rnd(c, 0x40)
    a = blk + 4
    e.w32(a, c.rng.choice([0, 0, 0, 1, 2, 3, _r(c)]))
    e.w8(a + 0x2e, c.rng.choice([0, 0, 4, 0xfb]))
    e.w8(a + 0xc, c.rng.choice([0, 1, 1, 0x80]))
    e.w32(a + 8, _rnd(c, 0x10))
    e.w8(a + 0x15, c.rng.choice([0, 1, 0x7f]))
    self_ = _rnd(c, 0x40)
    e.w32(self_, _pyvt(c, {0x30: _slot('s.30', 2, _r(c)), 0x34: _slot('s.34', 2, _r(c))}))
    e.mu.ctl_flush_tb()
    return [self_, c.rng.choice([a, a, a, a, 0]), c.rng.choice([0, 0, _r(c)])]


def _group(c, n):
    """A ZInputActionGroup (at the returned address) with n members, its owning set and member table."""
    e = c.emu
    g = _rnd(c, 0x40)
    ids = [_r(c) for _ in range(n)]
    ents = {}
    for i in ids:
        eb = _rnd(c, 0x20)
        e.w32(eb + 4, c.rng.choice([0, 0, 0, 1, 2]))
        ents[i] = eb + 4
    tab = _rnd(c, 0x10)
    e.w32(tab, _pyvt(c, {0x58: _slot('tab.58', 1, lambda em: ents.get(em.arg32(0), ents[ids[0]] if ids else 0))}))
    p = _rnd(c, 0x40)
    e.w32(p, 3)
    e.w32(p + 0xd, tab)          # set = p - 4, set + 0x11 = p + 0xd
    e.w32(g + 8, p)
    e.w32(g + 0xd, _list(c, 'grp', ids))
    return g


def _g_438150(c):
    e = c.emu
    _log_world(c, pslot=0x2c)
    im = _rnd(c, 0x10)
    e.w32(im, _pyvt(c, {0x34: _slot('im.34', 2, lambda em: c.rng.choice([0, 1, 0x100]))}))
    rm = _rnd(c, 0x1a00)
    e.w32(rm + 0x1907, im)
    e.w32(0x70039c, rm)
    g = _group(c, c.rng.choice([0, 1, 2, 3, 5]))
    if c.rng.random() < 0.1:
        e.w32(g + 0xd, 0)
    e.mu.ctl_flush_tb()
    return [g]


def _g_438f50(c):
    e = c.emu
    _hk_seq(c, 0x437d60, 'act.437d60', _seq(c, 20, [0, 1, 0x100, 0x101]))
    _hk_seq(c, 0x438150, 'grp.438150', _seq(c, 20, [0, 1, 0x100]))
    groups = []
    for _ in range(c.rng.choice([0, 1, 2, 3])):
        g = _rnd(c, 0x30)
        acts = []
        for _ in range(c.rng.choice([0, 1, 2, 4])):
            ab = _rnd(c, 0x20)
            e.w32(ab + 4, c.rng.choice([0, 0, 1, 1, 2, 3]))
            acts.append(ab + 4)
        e.w32(g + 0x19, c.rng.choice([_list(c, 'acts', acts)] * 4 + [0]))
        groups.append(g)
    out = _rnd(c, 0x10)
    e.w32(out, _pyvt(c, {4: _slot('out.4', 1)}))
    self_ = _rnd(c, 0x1220)
    e.w32(self_ + 0x1214, c.rng.choice([_list(c, 'groups', groups)] * 5 + [0]))
    e.mu.ctl_flush_tb()
    return [self_, out]


def _memset(em, r):
    d, v, n = em.arg32(0), em.arg32(1), em.arg32(2)
    em.wbytes(d, bytes([v & 0xff]) * n)
    em.ret(eax=d, argbytes=0)


def _g_439690(c):
    e = c.emu
    e.stub_import('memset', _memset)
    recs = []
    for _ in range(c.rng.choice([0, 1, 2, 4])):
        k = c.rng.choice([1, 1, 2, 3, _r(c) | 1])
        nm = bytes(c.rng.choice(b'abcdefgh') for _ in range(c.rng.randrange(1, 12)))
        key = bytes(c.rng.choice(b'XYZ012') for _ in range(c.rng.randrange(0, 8)))
        recs.append((k, nm, key, _r(c)))
    q = list(recs)

    def rd(em, r):
        b, n = em.arg32(0), em.arg32(1)
        em.calllog.append(('s.18', 0, None, (n,)))
        if q:
            k, nm, key, w = q.pop(0)
            em.w32(b, k)
            em.wbytes(b + 4, nm + b'\0')
            em.wbytes(b + 0x80, key + b'\0')
            em.w32(b + 0xfc, w)
        else:
            em.w32(b, 0)
        em.ret(eax=0, argbytes=8)
    s = _rnd(c, 0x10)
    e.w32(s, _pyvt(c, {0x18: rd}))
    rb = _rnd(c, 0x60)
    o = _rnd(c, 0x10)
    e.w32(o, _pyvt(c, {0x1c: _slot('o.1c', 0),
                       0x10: (lambda em, r: (em.calllog.append(('o.10', 0, None, (em.rbytes(em.arg32(0), 16).split(b'\0')[0],))),
                                             em.ret(eax=rb + 4, argbytes=4)))}))
    self_ = _rnd(c, 0x40)
    pick = [c.rng.choice([o, o, 0]) for _ in range(5)]
    pq = list(pick)
    e.w32(self_, _pyvt(c, {0x60: (lambda em, r: (em.calllog.append(('a.60', 0, None, (em.rbytes(em.arg32(0), 16).split(b'\0')[0],))),
                                                 em.ret(eax=pq.pop(0) if pq else 0, argbytes=4)))}))
    e.mu.ctl_flush_tb()
    return [self_, s]


S(0x437ed0, 'ZInputActions::CheckAction', 'thiscall', None, ret='al', gen=_g_437ed0,
  note='batch276; IsActive 0x439670 hooked (GUESS); ctx 0 = caller return address')
S(0x438150, 'ZInputActionGroup::CheckGroup', 'thiscall', None, ret='al', gen=_g_438150,
  note='batch276; 0x438c30 as exe code')
S(0x438f50, 'ZInputActions::GetActiveActions', 'thiscall', None, ret=None, gen=_g_438f50,
  note='batch276; 0x437d60 hooked (GUESS), 0x438150 hooked (verified in this batch)')
S(0x439690, 'ZInputActions::Save', 'thiscall', None, ret='al', gen=_g_439690,
  note='batch276; memset import stubbed; SEH cookie not reproduced')
