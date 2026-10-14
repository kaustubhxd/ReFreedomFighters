"""specs_s313.py - mounted gun batch 314: ZHeliIf::Fire, ZHeliIf::SetTarget."""
from pilot import S
from mg_helpers import _rnd, _obj, flush, new_log, log_stub, make_block


def _gen(slot, nargs=1):
    def g(c):
        r = c.rng
        log = new_log(c)
        tank = _obj(c, 0x40, {slot: log_stub(c, log, slot, nargs)})
        s = _rnd(c, 0x40)
        c.emu.w32(s + 0x18, tank)
        inb, _ = make_block(c, [(r.choice([0, 1, r.getrandbits(32)]), r.choice([0, 1]))], first=r.randint(0, 2))
        par = _rnd(c, 0x10)
        c.emu.w32(par + 4, inb)
        flush(c)
        return [s, par]
    return g


S(0x51e840, 'ZHeliIf::Fire', 'thiscall', None, gen=_gen(0x39c), note='batch314')
S(0x51eb50, 'ZHeliIf::SetTarget', 'thiscall', None, gen=_gen(0x398), note='batch314')
