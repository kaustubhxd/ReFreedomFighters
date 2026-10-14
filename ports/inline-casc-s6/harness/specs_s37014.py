"""specs_s37014.py - cascade s6 batch 37014: 0x4b0620. this slots 0x90 (3 args) / 0x94 (2 args) return the resolved object; table slots 0x54 (id -> object) and 0x60
(handle -> record); hooked 0x44b610, 0x44b740 (cdecl), 0x43ec00 (returns the new handle); logger at 0x700390 (slot 0x20 -> line object with cdecl slot 0x2c, recorded
by its 4 arguments); the pure helpers 0x4cc5f0/0x4cc1d0/0x4dc110/0x4dc130 run as original code on spec memory."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _cs(c, text):
    p = c.emu.alloc(len(text) + 1, 1)
    c.emu.wbytes(p, text + b'\0')
    return p


def _g4b0620(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x44b610, 0, this=True)
    hook_rec(c, 0x44b740, 1, pop=0)
    hook_rec(c, 0x43ec00, 6, this=True, ret=lambda em, k: r.choice([0, 0x11, 0x22, r.getrandbits(32)]))

    def lg(em, res_):
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(4))))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    names = [_cs(c, b'alpha'), _cs(c, b''), _cs(c, b'Bob')]

    def mkobj():
        O = rnd(c, 0x70)
        if r.random() < 0.8:
            X = rnd(c, 0x10)
            e.w32(X + 4, r.choice(names + [0]))
            e.w32(O + 0x54, X)
        else:
            e.w32(O + 0x54, 0)
        if r.random() < 0.6:
            P = rnd(c, 0x60)
            e.w32(P + 0x54, rnd(c, 0x10))
            e.w32(O + 0x50, P)
        else:
            e.w32(O + 0x50, 0)
        return O
    ident = r.choice([0, 0, 0x31, 0x32])
    byid = {0: mkobj() if r.random() < 0.5 else 0, 0x31: mkobj() if r.random() < 0.7 else 0, 0x32: mkobj() if r.random() < 0.7 else 0}
    recs = {h: rnd(c, 0x10) for h in (0, 0x11, 0x22, 0x44)}
    so = sysobj(c, table_slots={0x54: pystub(c, 1, this=True, ret=lambda em, k: byid.get(em.arg32(0), 0) if r.random() < 0.7 else 0),
                                0x60: pystub(c, 1, this=True, ret=lambda em, k: recs.get(em.arg32(0), 0) if r.random() < 0.8 else 0)}, table_size=0x20)
    resolved = mkobj()
    me = obj(c, 0x100, {0x90: pystub(c, 3, this=True, ret=lambda em, k: resolved if r.random() < 0.6 else 0),
                        0x94: pystub(c, 2, this=True, ret=lambda em, k: resolved if r.random() < 0.5 else 0)})
    e.w32(me + 0x58, ident)
    e.w32(me + 0x5c, r.choice(names))
    e.w32(me + 0xde, r.choice([0, 0x11, 0x22, 0x44]))
    e.w32(me + 0x50, r.choice([0, 0, 0x1234]))
    e.w32(me + 0x54, r.choice([0, 0, 0x5678]))
    Q = rnd(c, 0x10)
    e.w32(Q + 4, r.choice(names + [0]))
    e.w32(me + 0x44, Q)
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x4b0620, 'GUESS resolve entry and refresh handle', 'thiscall', None, ret=None, gen=_g4b0620, note='batch37014')
