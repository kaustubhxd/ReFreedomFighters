"""specs_s34018.py - cascade tier E, batch 34018. 0x5518e0 (stdcall; a has slot 0x18 returning an object or 0, that object slot 0x4c returns the setter holder; hooked 0x5003d0 /
0x5002f0 are thiscall recorders, 0x5003d0 returns a token); 0x56b980 (five member objects with slot 0xbc recorders, hooked 0x564a40, flag low byte zero in a third of the cases);
0x5c90b0 (engine table slot 0x58 returns an object or 0, its slot 0x1e0 returns 0/1, +0x54 pointer null or with [+4] zero/non-zero); 0x5d4b80 (id zero in a fifth; the assert hook is set;
engine table slots 0x58 / 0x4c, s slot 0x2c4, x slot 0x2c are recorders)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g5518e0(c):
    clear_hooks(c)
    r = c.rng
    token = rnd(c, 0x20)
    hook_rec(c, 0x5003d0, 1, ret=token, this=True)
    hook_rec(c, 0x5002f0, 1, this=True)
    holder = obj(c, 0x40, {0x4c: pystub(c, 0, ret=rnd(c, 0x20), this=True)}, nslots=0x40)
    res = 0 if r.random() < 0.25 else holder
    a = obj(c, 0x40, {0x18: pystub(c, 1, ret=res, this=True)}, nslots=0x20)
    cc = rnd(c, 0x10)
    return [a, r.getrandbits(32), cc]


def _g56b980(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x564a40, 1, this=True)
    mem = lambda: obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0x50)
    o = obj(c, 0x20, {0x2ec: pystub(c, 1, this=True)}, nslots=0xc0)
    me = obj(c, 0xd40, {0x84: pystub(c, 0, ret=o, this=True)}, nslots=0x50)
    for off in (0xcda, 0xcde, 0xcc2, 0xcd2, 0xcd6):
        c.emu.wbytes(me + off, mem().to_bytes(4, 'little'))
    flag = (r.getrandbits(32) & ~0xff) if r.random() < 0.33 else r.getrandbits(32)
    return [me, flag]


def _g5c90b0(c):
    clear_hooks(c)
    r = c.rng
    p = 0 if r.random() < 0.3 else rnd(c, 0x10)
    if p:
        c.emu.w32(p + 4, 0 if r.random() < 0.5 else r.getrandbits(32) | 1)
    o = 0 if r.random() < 0.2 else obj(c, 0x80, {0x1e0: pystub(c, 1, ret=r.choice([0, 1]) | (r.getrandbits(24) << 8), this=True)}, nslots=0x1f0)
    if o:
        c.emu.w32(o + 0x54, p)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=o, this=True)})
    return [rnd(c, 0x100), r.getrandbits(32)]


def _g5d4b80(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    x = obj(c, 0x20, {0x2c: pystub(c, 0, this=True)}, nslots=0x20)
    s = obj(c, 0x20, {0x2c4: pystub(c, 2, ret=x, this=True)}, nslots=0x2d0)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=s, this=True), 0x4c: pystub(c, 1, ret=r.getrandbits(32), this=True)}, table_size=0xb00)
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x58, 0 if r.random() < 0.2 else r.getrandbits(32) | 1)
    return [me]


S(0x5518e0, 'GUESS lookup and set three values', 'stdcall', None, ret='eax', gen=_g5518e0, note='batch34018')
S(0x56b980, 'GUESS broadcast flag to five members', 'thiscall', None, ret=None, gen=_g56b980, note='batch34018')
S(0x5c90b0, 'GUESS record id and weight', 'thiscall', None, ret=None, gen=_g5c90b0, note='batch34018')
S(0x5d4b80, 'GUESS resolve name through engine tables', 'thiscall', None, ret=None, gen=_g5d4b80, note='batch34018')
