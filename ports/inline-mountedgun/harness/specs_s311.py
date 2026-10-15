"""specs_s311.py - mounted gun batch 311: CFFTools_if::FireMachineGun, MGCanFireAt."""
from pilot import S
from mg_helpers import _rnd, _stub, _obj, flush, dispatch, new_log, log_stub, cmd_stub, make_block


def _world(c, nest_writes):
    r = c.rng
    log = new_log(c)
    ids = r.sample(range(1, 0x10000), 2)
    idmap = {0x6a584c: ids[0] | (r.getrandbits(16) << 16), 0x6a5874: ids[1] | (r.getrandbits(16) << 16)}
    gun = _obj(c, 0x40, {0x2d0: log_stub(c, log, 0x2d0, 2), 0x360: log_stub(c, log, 0x360, 1),
                         0x358: log_stub(c, log, 0x358, 1)})
    nref, gref = r.sample(range(1, 1 << 30), 2)
    nest = _obj(c, 0x40, {0x128: cmd_stub(c, nest_writes(ids, gref), log_stub(c, log, 0x128, 3))})
    eng = _rnd(c, 0x200)
    db = _obj(c, 0x200, {0x114: log_stub(c, log, 0x114, 4, args=(0, 3), chain=dispatch(c, idmap, argbytes=16)), 0x58: dispatch(c, {nref: nest, gref: gun})})
    c.emu.w32(eng + 0x9b, db)
    c.emu.w32(0x70039c, eng)
    pr = _obj(c, 8, {0x2c: _stub(c, 3, pop=0, this=True)})
    lg = _obj(c, 8, {0x20: _stub(c, 2, ret=pr, this=True)})
    c.emu.w32(0x700390, lg)
    c.emu.w32(0x7003b0, log_stub(c, log, 0xa55e, 0))
    return nref


def _par(c, ins, outs):
    r = c.rng
    inb, _ = make_block(c, ins, first=r.randint(0, 2))
    outb, _ = make_block(c, outs, first=r.randint(0, 2))
    par = _rnd(c, 0x10)
    c.emu.w32(par + 4, inb)
    c.emu.w32(par + 8, outb)
    return par


def _fire(c):
    r = c.rng
    nref = _world(c, lambda ids, gref: {ids[0]: gref})
    shots = r.choice([0, 1, 5, 30, -1, 0x80000000, r.getrandbits(32)])
    par = _par(c, [(shots, r.choice([0, 1, 1, 1]) if r.random() < 0.95 else 2), (nref, 1)], [(0, 0)])
    flush(c)
    return [_rnd(c, 0x10), par]


def _can(c):
    r = c.rng
    tgt = r.getrandbits(30) | 1
    nref = _world(c, lambda ids, gref: {ids[1]: r.choice([0, tgt])})
    par = _par(c, [(nref, 1), (r.choice([0, tgt]), 1)], [(r.getrandbits(32), r.choice([0, 1]))])
    flush(c)
    return [_rnd(c, 0x10), par]


S(0x553690, 'CFFTools_if::FireMachineGun', 'thiscall', None, gen=_fire, note='batch311')
S(0x555f20, 'CFFTools_if::MGCanFireAt', 'thiscall', None, gen=_can, note='batch311')
