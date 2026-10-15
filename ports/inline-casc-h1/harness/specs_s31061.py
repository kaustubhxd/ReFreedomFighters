"""specs_s31061.py - Sonnet h1 batch 31061: tail-jump thunks and small field functions."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _stub(c, n=2):
    return pystub(c, n, ret=c.rng.getrandbits(32), this=True)


def g4616b0(c):
    clear_hooks(c)
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x6c, obj(c, 0x40, {0x1c: _stub(c)}))
    return [me, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def g601a60(c):
    clear_hooks(c)
    sysobj(c, table_slots={0x118: _stub(c)})
    return [rnd(c, 0x20), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def g4f4d00(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4690b0, 2, ret=r.getrandbits(32), pop=0, this=True)
    me = rnd(c, 0xa0)
    c.emu.w32(me + 0x8f, r.choice([1, 0, r.getrandbits(32)]))
    c.emu.w32(me + 0x70, r.choice([0x20, 2, 0, 3, r.getrandbits(32)]))
    return [me, r.getrandbits(32), r.getrandbits(32)]


def g4dc420(c):
    clear_hooks(c)
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x54, 0 if c.rng.random() < 0.4 else obj(c, 0x40, {0xc: _stub(c, 1)}))
    return [me, c.rng.getrandbits(32)]


def g4d4940(c):
    me = rnd(c, 0x20)
    return [me, c.rng.choice([0x10, 0x10, 0, 0x11, c.rng.getrandbits(32)]), c.rng.getrandbits(32)]


def g4cfd90(c):
    return [rnd(c, 0x40), rnd(c, 0x40)]


def g4d0ee0(c):
    me = rnd(c, 0x8230)
    r = c.rng
    c.emu.wbytes(me + 0x821b, bytes([r.choice([0, 1, r.getrandbits(8)])]))
    return [me, r.choice([r.getrandbits(32), -r.getrandbits(8) & 0xffffffff, 0, 0x80000000, 5])]


S(0x4616b0, 'GUESS this->[0x6c] vtable tail thunk slot 0x1c', 'thiscall', None, ret='eax', gen=g4616b0, note='batch31061')
S(0x601a60, 'GUESS sysobj->[0x9b] vtable tail thunk slot 0x118', 'thiscall', None, ret='eax', gen=g601a60, note='batch31061')
S(0x4f4d00, 'GUESS state check else tail call 0x4690b0', 'thiscall', None, ret='eax', gen=g4f4d00, note='batch31061')
S(0x4dc420, 'GUESS null-checked this->[0x54] vtable tail slot 0xc', 'thiscall', None, ret='eax', gen=g4dc420, note='batch31061')
S(0x4d4940, 'GUESS clear byte +5 if arg==0x10', 'thiscall', None, ret=None, gen=g4d4940, note='batch31061')
S(0x4cfd90, 'GUESS copy unaligned dword +0x11', 'stdcall', None, ret=None, gen=g4cfd90, note='batch31061')
S(0x4d0ee0, 'GUESS take-and-set flag +0x821b', 'thiscall', None, ret='eax', gen=g4d0ee0, note='batch31061')
