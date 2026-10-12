"""specs_s265.py - area 22, batch265 (src/batch265.cpp): ZItem::SetItemOwner. All objects are Python vtables whose slots
log their stack words (pointers to stack strings are not logged; names are logged as text by the printf stub). Names via
vt[0x1d8] write a self-pointing inline string read back by the exe's c_str/destructor (0x4cc1d0, 0x4cbec0 as original
code). 0x4dc440 SetAutoRoomAssign and 0x4dbe30 MakeDynamic are hooked by address (GUESS stubs, logged). The assert hook is
always set (with no hook the exe breaks on int3)."""
from pilot import S
from helpers22 import _rnd, _pyvt, _hk, _log_world


def _r(c):
    return c.rng.getrandbits(32)


def _slot(name, nargs, ret=0):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx'), tuple(em.arg32(i) for i in range(nargs))))
        em.ret(eax=ret(em) if callable(ret) else ret, argbytes=4 * nargs)
    return h


def _namer(text):
    def h(em, r):
        buf = em.arg32(0)
        em.calllog.append(('name.1d8', 0x1d8, em.reg('ecx'), (em.arg32(1),)))
        em.w32(buf, buf + 4)
        em.wbytes(buf + 4, text + b'\0')
        em.ret(eax=buf, argbytes=8)
    return h


def _cls(c, flags):
    k = _rnd(c, 0x40)
    c.emu.w32(k + 0x3c, flags)
    return k


def _flags(c):
    return _r(c) & c.rng.choice([0, 0x200000, 0x40000, 0x40000000, 0x40040000, 0x240000, 0xffffffff])


def _g_470c90(c):
    e = c.emu
    _log_world(c, deref=True)
    _hk(c, 0x4dc440, 'SetAutoRoomAssign', 1)
    _hk(c, 0x4dbe30, 'MakeDynamic', 1)
    ids = [_r(c) | 1 for _ in range(3)]
    old = c.rng.choice([0, ids[0], ids[0], ids[1]])
    owner = c.rng.choice([0, ids[1], ids[1], ids[2], old])
    gm = {}
    for i in ids:
        if c.rng.random() < 0.85:
            g = _rnd(c, 0x10)
            e.w32(g, _pyvt(c, {0x1d8: _namer(b'own%x' % (i & 0xff)), 0x128: _slot('send128', 3)}))
            gm[i] = g
        else:
            gm[i] = 0
    gm[0] = 0
    if c.rng.random() < 0.15:   # two ids for the same geom: a change of id with no change of owner object
        gm[ids[1]] = gm[ids[0]]
    h = _r(c)

    def grp(c):
        g = _rnd(c, 0x10)
        e.w32(g, _pyvt(c, {0x288: _slot('grp.288', 3)}))
        e.w32(g + 8, _cls(c, _flags(c)))
        return g
    roots = [c.rng.choice([grp(c), 0]), grp(c)]
    tm = _rnd(c, 0x10)
    e.w32(tm, _pyvt(c, {0x300: _slot('tmpl.300', 0, c.rng.choice([0, 1, _r(c)]))}))
    self_ = _rnd(c, 0x100)
    e.w32(self_, _pyvt(c, {0x20: _slot('item.20', 0, lambda em: roots.pop(0) if roots else 0x9999),
                           0x2f4: _slot('item.2f4', 0, c.rng.choice([0, 0, 1])),
                           0x2e8: _slot('item.2e8', 0, tm),
                           0x300: _slot('item.300', 1),
                           0x1d8: _namer(b'item')}))
    if c.rng.random() < 0.7:
        nm = e.alloc(16, 4)
        e.wbytes(nm, b'Pistol\0')
        e.w32(self_ + 4, nm)
    else:
        e.w32(self_ + 4, 0)
    e.w32(self_ + 8, _cls(c, _flags(c)))
    e.w32(self_ + 0x64, old)
    known = c.rng.random() < 0.9
    db = _rnd(c, 0x40)
    e.w32(db, _pyvt(c, {0x58: _slot('db.58', 1, lambda em: self_ if (em.arg32(0) == h and known) else gm.get(em.arg32(0), 0)),
                        0x4c: _slot('db.4c', 1, h),
                        0x114: _slot('db.114', 4, lambda em: _r(c))}))
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    e.mu.ctl_flush_tb()
    return [self_, owner, c.rng.choice([0, grp(c)]), (_r(c) & ~0xff) | c.rng.choice([0, 1, 1, 0x10])]


S(0x470c90, 'ZItem::SetItemOwner', 'thiscall', None, ret='eax', gen=_g_470c90,
  note='batch265; SEH frame and cookie not reproduced; 0x4dc440/0x4dbe30 GUESS stubs')
