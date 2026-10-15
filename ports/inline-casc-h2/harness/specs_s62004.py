from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    gate = pystub(c, 1, this=True, pop=4, ret=c.rng.choice([0, 1, 0x100, 0x80000002]))
    src = obj(c, 0x60, {0x1e0: gate})
    dst = obj(c, 0x60, {})
    c.emu.w32(src + 0x4c, c.rng.getrandbits(32))
    c.emu.w8(src + 0x50, c.rng.getrandbits(8))
    c.emu.w8(src + 0x51, c.rng.getrandbits(8))
    c.emu.w32(dst + 0x4c, c.rng.getrandbits(32))
    c.emu.w8(dst + 0x50, c.rng.getrandbits(8))
    c.emu.w8(dst + 0x51, c.rng.getrandbits(8))
    return [dst, src]

S(0x46ca60, 'GUESS conditionally copy three fields', 'thiscall', None, ret='eax', gen=gen, note='batch62004')
