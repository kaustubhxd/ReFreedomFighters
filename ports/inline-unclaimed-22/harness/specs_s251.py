"""specs_s251.py - area 22, batch251 (src/batch251.cpp): CInventory::GetItemOfType. The embedded item list (+0x11a) is a
Python vtable (start, next, remove) whose iterator is a stack local, so only values are logged; each id maps to a geom, null,
or a geom without a template; names come from vt[0x1d8] writing a self-pointing inline string, read back by the exe's own
c_str/destructor (0x4cc1d0, 0x4cbec0 run as original code); the logger logs the %s text, not the stack address."""
from pilot import S
from helpers22 import _rnd, _multi_vt, _pyvt, _log_world


def _r(c):
    return c.rng.getrandbits(32)


def _namer(c, text):
    def h(em, r):
        buf = em.arg32(0)
        em.calllog.append(('name.1d8', 0x1d8, None, (em.arg32(1),)))
        em.w32(buf, buf + 4)
        em.wbytes(buf + 4, text + b'\0')
        em.ret(eax=buf, argbytes=8)
    return h


def _g_4ac820(c):
    e = c.emu
    _log_world(c, deref=True)
    self_ = _rnd(c, 0x200)
    owner = _rnd(c, 0x10)
    e.w32(owner, _pyvt(c, {0x1d8: _namer(c, b'owner%d' % c.rng.randint(0, 99))}))
    e.w32(self_ + 0x44, owner)
    n = c.rng.choice([0, 1, 2, 3, 5])
    ids = [_r(c) for _ in range(n)]
    geoms = {}
    for k, i in enumerate(ids):
        kind = c.rng.choice(['ok', 'ok', 'ok', 'null', 'notemplate'])
        if kind == 'null':
            geoms[i] = 0
            continue
        g = _rnd(c, 0x10)
        if kind == 'notemplate':
            tmpl = 0
        else:
            tmpl = _rnd(c, 0x10)
            v = (c.rng.getrandbits(24) << 8) | c.rng.choice([0, 0, 1, c.rng.getrandbits(8)])
            e.w32(tmpl, _multi_vt(c, {0x1e0: (lambda em, a, v=v: (v, None), 1)}))
        vt = _pyvt(c, {0x1d8: _namer(c, b'item%d' % k),
                       0x2e8: lambda em, r, t=tmpl: (em.calllog.append(('geom.2e8', 0x2e8, None, ())), em.ret(eax=t))})
        e.w32(g, vt)
        geoms[i] = g
    db = _rnd(c, 0x40)
    e.w32(db, _multi_vt(c, {0x58: (lambda em, a, m=geoms: (m.get(a[0], 0), None), 1)}))
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    st = {'k': 0}

    def start(em, r):
        em.calllog.append(('list.4c', 0x4c, None, ()))
        st['k'] = 0
        em.w32(em.arg32(0), 0x66000000)
        em.ret(eax=0x2468ace0, argbytes=4)

    def nxt(em, r):
        k = st['k']
        em.calllog.append(('list.5c', 0x5c, None, (em.r32(em.arg32(0)),)))
        if k < len(ids):
            em.w32(em.arg32(0), 0x66000001 + k)
            v = ids[k]
        else:
            em.w32(em.arg32(0), 0)
            v = 0x7777aaaa
        st['k'] = k + 1
        em.ret(eax=v, argbytes=4)

    def rem(em, r):
        em.calllog.append(('list.44', 0x44, None, (em.r32(em.arg32(0)),)))
        em.ret(eax=0, argbytes=4)
    e.w32(self_ + 0x11a, _pyvt(c, {0x4c: start, 0x5c: nxt, 0x44: rem}))
    e.mu.ctl_flush_tb()
    return [self_, _r(c)]


S(0x4ac820, 'CInventory::GetItemOfType', 'thiscall', None, ret='eax', gen=_g_4ac820,
  note='batch251; SEH frame and cookie not reproduced; list walk with removal and two warnings')
