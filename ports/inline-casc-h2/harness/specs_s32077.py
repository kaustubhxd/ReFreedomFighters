"""specs_s32077.py - h2 (Sonnet) batch 32077: import call + five vtable thunks. Slots are recorder stubs returning a random eax."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def g425240(c):
    clear_hooks(c)
    r = c.rng
    v = r.choice([0, 1, r.getrandbits(32), 0x80000000])
    c.emu.w32(0x67606c, pystub(c, 0, ret=v))
    return []


def _thunk(slot):
    def g(c):
        clear_hooks(c)
        return [obj(c, 0x40, {slot: pystub(c, 1, ret=c.rng.getrandbits(32), this=True)}, nslots=slot // 4 + 2)]
    return g


def g4cbdc0(c):
    clear_hooks(c)
    inner = obj(c, 0x20, {0x3c: pystub(c, 1, ret=c.rng.getrandbits(32), this=True)})
    me = rnd(c, 0x60)
    c.emu.w32(me + 0x44, inner)
    return [me]


S(0x425240, 'GUESS import returns nonzero', 'cdecl', None, ret='al', gen=g425240, note='batch32077')
S(0x466f40, 'GUESS slot 0x2b4(0x16)', 'thiscall', None, ret='eax', gen=_thunk(0x2b4), note='batch32077')
S(0x467400, 'GUESS slot 0x2b4(0xa)', 'thiscall', None, ret='eax', gen=_thunk(0x2b4), note='batch32077')
S(0x4ce510, 'GUESS slot 8(0)', 'thiscall', None, ret='eax', gen=_thunk(8), note='batch32077')
S(0x566e30, 'GUESS slot 0xd0(0)', 'thiscall', None, ret='eax', gen=_thunk(0xd0), note='batch32077')
S(0x4cbdc0, 'GUESS [this+0x44] slot 0x3c(1)', 'thiscall', None, ret='eax', gen=g4cbdc0, note='batch32077')
