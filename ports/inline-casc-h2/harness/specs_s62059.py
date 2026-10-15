from pilot import S
from recruits_util import rnd, sysobj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    stored_key = r.getrandbits(16)
    match = r.choice([True, False])
    key = stored_key if match else ((stored_key + r.randrange(1, 0x10000)) & 0xffff)
    found = r.getrandbits(32)
    lookup = pystub(c, 1, this=True, pop=4, ret=found,
                    side=lambda emu, k: emu.calllog.append(('lookup', emu.reg('ecx'), emu.arg32(0))))
    sysobj(c, table_slots={0x4c: lookup}, table_size=0x50 // 4)
    def dispatch(emu, k):
        emu.calllog.append(('dispatch', emu.reg('ecx'), *(emu.arg32(i) for i in range(3))))
    slot = pystub(c, 3, this=True, pop=12, side=dispatch)
    child = rnd(c, 0x20)
    vt = e.alloc(0x130, 4)
    e.w32(child, vt)
    e.w32(vt + 0x12c, slot)
    self = rnd(c, 0x60)
    e.w32(self + 0x44, child)
    e.w16(self + 0x48, stored_key)
    e.w16(self + 0x4a, r.getrandbits(16))
    e.w32(self + 0x4c, r.getrandbits(32))
    value = r.getrandbits(32)
    return [self, key, value]


S(0x4b14a0, 'GUESS dispatch matching indexed value update', 'thiscall', None,
  ret='eax', gen=gen, note='batch62059')
