from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    calls = []
    def mk(tag):
        return pystub(c, 1, this=True, pop=4,
                      side=lambda emu, k: calls.append((tag, emu.reg('ecx'), emu.arg32(0))))
    target = obj(c, 0x70, {0x3c: mk('count'), 0x64: mk('item')}, nslots=0x65 // 4)
    count = r.randrange(0, 9)
    items = rnd(c, 4 * (count + 1))
    e.w32(items, count)
    for i in range(count):
        e.w32(items + 4 * (i + 1), r.getrandbits(32))
    return [target, items]


S(0x511c20, 'GUESS dispatch a counted item list', 'fastcall', None,
  ret='eax', gen=gen, note='batch62062')
