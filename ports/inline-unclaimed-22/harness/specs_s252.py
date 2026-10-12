"""specs_s252.py - area 22, batch252 (src/batch252.cpp): ZFFInventoryInfoList::GetInventoryInfo, ZFFInventoryBridge::GetAmmo
and ZFFInventoryBridge::GetWeapon. GetWeapon's REFTAB32 list lives on the stack and its constructor, iterator and destructor
run as original code on both sides; the owner's SendCommand (vt 0x130) fills it the way REFTAB::Add 0x4cd540 does for up
to 32 ids (the inline chunk at +0x1c), and logs owner and message, not the stack address."""
from pilot import S
from helpers22 import _rnd, _multi_vt, _pyvt, _log_world


def _r(c):
    return c.rng.getrandbits(32)


KINDS = [3, 4, 5, 6, 7, 8, 10, 11, 0, 1, 2, 9, 12]


def _kind(c):
    return c.rng.choice(KINDS + [_r(c)])


def _info_list(c, templates):
    n = len(templates)
    lst = c.emu.alloc(4 + 4 * n + 8, 4)
    c.emu.w32(lst, n)
    for i, t in enumerate(templates):
        rec = _rnd(c, 0x14)
        c.emu.w32(rec, t)
        c.emu.w32(rec + 0x10, _kind(c))
        c.emu.w32(lst + 4 + 4 * i, rec)
    return lst


def _g_5af0f0(c):
    ts = [_r(c) for _ in range(c.rng.choice([0, 1, 2, 4, 7]))]
    lst = _info_list(c, ts)
    t = c.rng.choice(ts + [_r(c)]) if ts else _r(c)
    return [lst, t]


def _spare(c):
    if c.rng.random() < 0.4:
        return 0
    x = _rnd(c, 0x10)
    c.emu.w32(x, _multi_vt(c, {0x320: (lambda em, a, v=_r(c) & 0xffff: (v, None), 0)}))
    return x


def _item(c, tmpl):
    g = _rnd(c, 0x10)
    c.emu.w32(g, _multi_vt(c, {0x2e8: (lambda em, a, t=tmpl: (t, None), 0),
                               0x35c: (lambda em, a, v=_r(c) & 0xffff: (v, None), 0)}))
    return g


def _g_5af300(c):
    o = _rnd(c, 0x10)
    sp = _spare(c)
    c.emu.w32(o, _multi_vt(c, {0x55c: (lambda em, a, v=sp: (v, None), 1)}))
    self_ = _rnd(c, 0x10)
    c.emu.w32(self_, o)
    return [self_, _item(c, _r(c))]


def _g_5af5b0(c):
    e = c.emu
    _log_world(c)
    tmpls = [_r(c) for _ in range(c.rng.choice([0, 1, 3, 5]))]
    info = _info_list(c, tmpls)
    n = c.rng.choice([0, 1, 2, 3, 5, 8])
    ids = [_r(c) for _ in range(n)]
    geoms = {}
    spares = {}
    for i in ids:
        t = c.rng.choice(tmpls + [_r(c)]) if tmpls else _r(c)
        g = _item(c, t)
        geoms[i] = g
        spares[g] = _spare(c)
    db = _rnd(c, 0x40)
    msg = _r(c)
    e.w32(db, _multi_vt(c, {0x58: (lambda em, a, m=geoms: (m.get(a[0], 0), None), 1),
                            0x114: (lambda em, a, v=msg: (v, None), 4)}))
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)

    def send(em, r):
        o, cmd, tab = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('owner.130', 0x130, em.reg('ecx'), (o, cmd)))
        if ids:
            ch = tab + 0x1c
            em.w32(ch, 0)
            em.w32(ch + 4, 0)
            em.w32(ch + 8, len(ids))
            for k, i in enumerate(ids):
                em.w32(ch + 0x10 + 4 * k, i)
            em.w32(tab + 4, ch)
            em.w32(tab + 8, ch)
            em.w32(tab + 0x14, len(ids))
        em.ret(eax=0, argbytes=12)

    def find_spare(em, r):
        g = em.arg32(0)
        em.calllog.append(('owner.55c', 0x55c, None, (g,)))
        em.ret(eax=spares.get(g, 0), argbytes=4)
    owner = _rnd(c, 0x10)
    e.w32(owner, _pyvt(c, {0x130: send, 0x55c: find_spare}))
    self_ = _rnd(c, 0x10)
    e.w32(self_, c.rng.choice([owner] * 6 + [0]))
    e.w32(self_ + 4, c.rng.choice([info] * 6 + [0]))
    e.w32(self_ + 8, c.rng.choice([_r(c) | 1] * 6 + [0]))
    out1 = _rnd(c, 4)
    out2 = _rnd(c, 4)
    e.mu.ctl_flush_tb()
    return [self_, out1, out2, (_r(c) & ~0xff) | c.rng.choice([0, 1, 0, 1, 0x80])]


S(0x5af0f0, 'ZFFInventoryInfoList::GetInventoryInfo', 'thiscall', None, ret='eax', gen=_g_5af0f0,
  note='batch252; linear search of the info records by template')
S(0x5af300, 'ZFFInventoryBridge::GetAmmo', 'thiscall', None, ret='eax', gen=_g_5af300,
  note='batch252; rounds in the gun plus the spare-ammo item')
S(0x5af5b0, 'ZFFInventoryBridge::GetWeapon', 'thiscall', None, ret=None, gen=_g_5af5b0,
  note='batch252; stack REFTAB32 runs as exe code; SEH frame and cookie not reproduced; void')
