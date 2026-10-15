from pilot import S
from recruits_util import rnd, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    assert_ret = r.getrandbits(32)
    e.w32(0x7003b0, pystub(c, 0, ret=assert_ret))
    count = r.randrange(0, 7)
    items = rnd(c, max(0x10, count * 0x10))
    input_key = r.choice([0, 1, 0xfffffffe, 0xffffffff, r.getrandbits(32)])
    wanted = (input_key + 1) & 0xffffffff
    found = bool(count and r.choice([0, 1]))
    for i in range(count):
        e.w32(items + i * 0x10, wanted if found and i == count - 1 else (wanted ^ (i + 0x100)) & 0xffffffff)
        e.wbytes(items + i * 0x10 + 4, bytes(r.getrandbits(8) for _ in range(12)))
    self = rnd(c, 0x20)
    e.w32(self + 8, count)
    e.w32(self + 0xc, r.getrandbits(32))
    e.w32(self + 0x10, items if count else r.choice([0, items]))
    return [self, input_key]


S(0x49b2e0, 'GUESS find keyed sixteen-byte record', 'thiscall', None,
  ret='eax', gen=gen, note='batch62090')
