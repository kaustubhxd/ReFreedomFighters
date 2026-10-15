from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    self = obj(c, 0xa4, {})
    table = obj(c, 0x20, {})
    entry = obj(c, 8, {})
    c.emu.w32(self + 0x97, table)
    c.emu.w32(self + 0x9f, c.rng.getrandbits(32))
    c.emu.w32(table + 0x10, c.rng.getrandbits(32))
    result = entry if c.rng.random() < 0.75 else 0
    c.emu.w32(entry + 4, c.rng.getrandbits(32))
    def observe_key(emu, k):
        emu.calllog.append(('key', emu.r32(emu.arg32(0))))

    fn = pystub(c, 5, pop=0, ret=result, stackmark=(0,), side=observe_key)
    c.emu.w32(0x676448, fn)
    return [self, c.rng.getrandbits(32), c.rng.getrandbits(32)]

S(0x4f6580, 'GUESS rotated key lookup', 'thiscall', None, ret='eax', gen=gen, note='batch62006')
