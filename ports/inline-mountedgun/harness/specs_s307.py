"""specs_s307.py - mounted gun batch 307: CFFTools_if natives CalcMachineGunStandPosition, IsMachineGunFree,
GetMachineGunInfo. Parameter accessors 0x5003d0/0x5002f0 run as exe code on real parameter blocks."""
from pilot import S
from mg_helpers import _rnd, _stub, _obj, flush, dispatch, new_log, log_stub, cmd_stub, make_block

NAMES = {0x6a585c: 0, 0x6a5830: 1, 0x6a583c: 2, 0x6a5884: 3}   # GetCenter, GetOwner, GetReservedBy, MakeReservation


def _world(c, owner=0, by=0):
    """db with slot 0x114 = name -> id dispatcher, slot 0x58 = ref dispatcher; one nest and its center geom."""
    r = c.rng
    log = new_log(c)
    ids = r.sample(range(1, 0x10000), 4)
    idmap = {k: ids[v] | (r.getrandbits(16) << 16) for k, v in NAMES.items()}
    refs = r.sample(range(1, 1 << 30), 3)
    center = _obj(c, 0x40, {0x80: _stub(c, 2, fills=((0, _put(c, 9, -1, 1), 9), (1, _put(c, 3, -500, 500), 3)),
                                         skip=(0, 1))})
    nest = _obj(c, 0x40, {0x128: cmd_stub(c, {ids[0]: refs[1], ids[1]: owner, ids[2]: by},
                                          log_stub(c, log, 0x128, 3))})
    eng = _rnd(c, 0x200)
    db = _obj(c, 0x200, {0x114: log_stub(c, log, 0x114, 4, args=(0, 3), chain=dispatch(c, idmap, argbytes=16)), 0x58: dispatch(c, {refs[0]: nest, refs[1]: center})})
    c.emu.w32(eng + 0x9b, db)
    c.emu.w32(0x70039c, eng)
    lg_pr = _obj(c, 8, {0x2c: _stub(c, 3, pop=0, this=True)})
    lg = _obj(c, 8, {0x20: _stub(c, 2, ret=lg_pr, this=True)})
    c.emu.w32(0x700390, lg)
    c.emu.w32(0x7003b0, log_stub(c, log, 0xa55e, 0))
    return refs[0], log


def _put(c, n, lo, hi):
    a = c.emu.alloc(4 * (n + 8), 4)
    for i in range(n + 8):
        c.emu.wf32(a + 4 * i, c.fv(lo, hi))
    return a


def _stand(c):
    nest, log = _world(c)
    out = c.emu.alloc(4 * 11, 4)
    flush(c)
    return [_rnd(c, 0x10), nest, c.rng.getrandbits(32), out]


def _free(c):
    r = c.rng
    me = r.getrandbits(32) | 1
    owner = r.choice([0, 0, me, r.getrandbits(32) | 1])
    by = r.choice([0, me, r.getrandbits(32) | 1])
    nest, log = _world(c, owner, by)
    inb, _ = make_block(c, [(nest, r.choice([0, 1])), (me, 1)], first=r.randint(0, 2))
    outb, _ = make_block(c, [(r.getrandbits(32), r.choice([0, 1, 1, 1]))], first=r.randint(0, 2))
    par = _rnd(c, 0x10)
    c.emu.w32(par + 4, inb)
    c.emu.w32(par + 8, outb)
    flush(c)
    return [_rnd(c, 0x10), par]


def _info(c):
    r = c.rng
    me = r.getrandbits(32) | 1
    nest, log = _world(c)
    t = lambda ok: r.choice(ok) if r.random() < 0.93 else r.choice([2, 3, 4])
    s4 = _obj(c, 0x10, {0x24: log_stub(c, log, 0x24, 0, ret=r.getrandbits(32)), 0x28: log_stub(c, log, 0x28, 0)})
    v0t = t([0, 1])
    inb, _ = make_block(c, [(s4 if v0t == 4 else nest, v0t), (me, t([0, 1]))], first=r.randint(0, 2))
    d4 = _obj(c, 0x10, {0x28: log_stub(c, log, 0x29, 0), 0x24: log_stub(c, log, 0x25, 0)})
    o0t = r.choice([0, 1, 4])
    outb, _ = make_block(c, [(d4 if o0t == 4 else r.getrandbits(32), o0t)] +
                         [(r.getrandbits(32), t([0, 2])) for _ in range(3)], first=r.randint(0, 2))
    par = _rnd(c, 0x10)
    c.emu.w32(par + 4, inb)
    c.emu.w32(par + 8, inb if r.random() < 0.05 else outb)
    flush(c)
    return [_rnd(c, 0x10), par]


S(0x5520c0, 'CFFTools_if::CalcMachineGunStandPosition', 'thiscall', None, gen=_stand, note='batch307')
S(0x555a40, 'CFFTools_if::IsMachineGunFree', 'thiscall', None, gen=_free, note='batch307')
S(0x5544f0, 'CFFTools_if::GetMachineGunInfo', 'thiscall', None, gen=_info, note='batch307')
